package main

import (
	"bytes"
	"fmt"
	"regexp"
	"strconv"
	"strings"
)

var reBlobCall = regexp.MustCompile(`(getMem[^\s(]*)\s*\(`)

type BlobCall struct {
	Name    string // identifier of the called function
	Base    uint   // blob base address
	Pos     [2]int // start and the end index of the call
	Off     [2]int // start and the end index of the index expression (in a call)
	Expr    []byte // whole blob call expression
	OffExpr []byte // blob index expression
}

func (b *BlobCall) ParseOffs() (BlobOffSum, bool) {
	return parseOffSum(b.OffExpr)
}

func nextBlobCall(data []byte) (BlobCall, bool) {
	orig := data
	ind := reBlobCall.FindSubmatchIndex(data)
	if len(ind) == 0 {
		return BlobCall{}, false
	}
	start := ind[0]
	sbrace := ind[1]
	i := indexToken(data[sbrace:], '(', ')')
	if i < 0 {
		return BlobCall{}, false
	}
	call := BlobCall{
		Pos:  [2]int{start, sbrace + i + 1},
		Name: string(data[ind[2]:ind[3]]),
	}
	call.Expr = orig[call.Pos[0]:call.Pos[1]:call.Pos[1]]
	data = data[sbrace : call.Pos[1]-1]

	i = indexTokenAll(data, ',')
	if i < 0 {
		return BlobCall{}, false
	}
	base, err := parseUint(data[:i])
	if err != nil {
		return BlobCall{}, false
	}
	call.Base = base
	call.Off = [2]int{sbrace + i + 1, call.Pos[1] - 1}
	call.OffExpr = orig[call.Off[0]:call.Off[1]:call.Off[1]]
	return call, true
}

func BlobCalls(data []byte) []BlobCall {
	var calls []BlobCall
	for {
		b, ok := nextBlobCall(data)
		if !ok {
			return calls
		}
		calls = append(calls, b)
		next := b.Off[0] // continue from the expression - it may contain other calls
		data = data[next:]
	}
}

func parseUint(s []byte) (uint, error) {
	s = bytes.TrimSpace(s)
	v, err := strconv.ParseUint(string(s), 0, 64)
	if err != nil {
		return 0, err
	}
	return uint(v), nil
}

func parseOffSum(data []byte) (BlobOffSum, bool) {
	sub := splitToken(data, '+')
	if len(sub) == 0 {
		return BlobOffSum{}, false
	}
	var (
		res BlobOffSum
		out [][]byte
	)
	for _, s := range sub {
		s = bytes.TrimSpace(s)
		v, err := parseUint(s)
		if err == nil {
			res.Static += v
			continue
		}
		m, ok := parseOffMult(s)
		if !ok {
			out = append(out, s)
			continue
		}
		if m.Sum.Zero() {
			res.Static += m.Static
			continue
		} else if m.Sum.StaticOnly() {
			res.Static += m.Static * m.Sum.Static
			continue
		}
		res.AddMult(m)
	}
	if len(out) == len(sub) {
		return BlobOffSum{}, false
	}
	for _, p := range out {
		res.Raw = append(res.Raw, string(p))
	}
	return res, true
}

func parseOffMult(data []byte) (BlobOffMult, bool) {
	if len(data) == 0 {
		return BlobOffMult{}, false
	}
	sub := splitToken(data, '*')
	if len(sub) == 0 {
		return BlobOffMult{}, false
	}
	var (
		first = true
		res   BlobOffMult
		out   [][]byte
	)
	for _, s := range sub {
		s = bytes.TrimSpace(s)
		v, err := parseUint(s)
		if err == nil {
			if first {
				first = false
				res.Static = v
			} else {
				res.Static *= v
			}
			continue
		}
		out = append(out, unbrace(s))
	}
	if len(out) == len(sub) || len(out) > 1 {
		return BlobOffMult{}, false
	}
	if len(out) == 0 {
		return res, true
	}
	sum, ok := parseOffSum(out[0])
	if !ok {
		str := string(out[0])
		if strings.Contains(str, "+") {
			str = "(" + str + ")"
		}
		res.Sum.Raw = append(res.Sum.Raw, str)
	} else {
		res.Sum.Merge(sum)
		if res.Sum.StaticOnly() {
			res.Static *= res.Sum.Static
			res.Sum = BlobOffSum{}
		}
	}
	return res, true
}

type BlobOffMult struct {
	Static uint
	Sum    BlobOffSum
}

func (o BlobOffMult) String() string {
	if o.Sum.Zero() {
		o.Sum.Static = 1
	}
	if o.Sum.StaticOnly() {
		return fmt.Sprintf("%d*%d", o.Static, o.Sum.Static)
	}
	if o.Sum.Parts() < 2 {
		return fmt.Sprintf("%d*%s", o.Static, o.Sum.String())
	}
	return fmt.Sprintf("%d*(%s)", o.Static, o.Sum.String())
}

func (o BlobOffMult) Replace(fnc func(string) string) {
	o.Sum.Replace(fnc)
}

type BlobOffSum struct {
	Static uint
	Mult   []BlobOffMult
	Raw    []string
}

func (o BlobOffSum) Zero() bool {
	return o.Static == 0 && len(o.Mult) == 0 && len(o.Raw) == 0
}

func (o BlobOffSum) StaticOnly() bool {
	return len(o.Mult) == 0 && len(o.Raw) == 0
}

func (o BlobOffSum) Replace(fnc func(string) string) {
	for i := range o.Mult {
		o.Mult[i].Replace(fnc)
	}
	for i, s := range o.Raw {
		o.Raw[i] = fnc(s)
	}
}

func (o *BlobOffSum) Merge(o2 BlobOffSum) {
	o.Static += o2.Static
	for _, m := range o2.Mult {
		o.AddMult(m)
	}
	o.Raw = append(o.Raw, o2.Raw...)
}

func (o BlobOffSum) FindMult(elem uint) (*BlobOffMult, []BlobOffMult) {
	var (
		cur  BlobOffMult
		rest []BlobOffMult
	)
	for _, m := range o.Mult {
		if m.Static == elem {
			cur.Static = m.Static
			cur.Sum.Merge(m.Sum)
		} else {
			rest = append(rest, m)
		}
	}
	if cur.Static == 0 {
		return nil, o.Mult
	}
	return &cur, rest
}

func (o BlobOffSum) Parts() int {
	parts := 0
	if o.Static != 0 {
		parts++
	}
	parts += len(o.Mult)
	parts += len(o.Raw)
	return parts
}

func (o BlobOffSum) String() string {
	var parts []string
	if o.Static != 0 {
		parts = append(parts, strconv.FormatUint(uint64(o.Static), 10))
	}
	for _, m := range o.Mult {
		parts = append(parts, m.String())
	}
	parts = append(parts, o.Raw...)
	return strings.Join(parts, " + ")
}
