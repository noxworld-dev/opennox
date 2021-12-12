package main

import (
	"bytes"
	"errors"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"path/filepath"
	"strconv"
	"strings"

	"github.com/spf13/cobra"
)

const (
	memmapName  = "memmap.c"
	varDefsName = "vardefs.c"
	dataName    = "GAME_data.c"
	initName    = "GAME_data_init.c"
)

func main() {
	cmd := &cobra.Command{
		Use:   "offalign",
		Short: "given an array parameters and the blob offset, rewrites static offsets to appear as array access",
	}
	fBlob := cmd.Flags().Uint("blob", 0, "blob to rewrite")
	fBase := cmd.Flags().Uint("base", 0, "base offset of the array/structure in the blob")
	fElem := cmd.Flags().Uint("elem", 0, "size of the element or structure in the array")
	fCnt := cmd.Flags().Uint("cnt", 1, "number of elements in the array")
	fPrint := cmd.Flags().Bool("print", false, "print base offsets of each element")
	fPath := cmd.Flags().String("path", ".", "path to sources and other files")
	cmd.RunE = func(cmd *cobra.Command, args []string) error {
		cmd.SilenceUsage = true
		base := *fBase
		elem := *fElem
		cnt := *fCnt
		if *fPrint {
			for i := uint(0); i < cnt; i++ {
				log.Printf("elem %d: %d", i, base+elem*i)
			}
		}
		_, err := offsetAlignDir(*fPath, *fBlob, base, elem, cnt)
		return err
	}
	if err := cmd.Execute(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func offsetAlignDir(path string, blob, base, elem, cnt uint) (int, error) {
	if blob == 0 {
		return 0, errors.New("blob address must be specified")
	}
	if base == 0 {
		return 0, errors.New("base offset in the blob must be specified")
	}
	if elem == 0 {
		return 0, errors.New("element size must be specified")
	}
	paths, err := readFileListC(path, []string{
		memmapName,
		dataName,
	})
	if err != nil {
		return 0, err
	}
	num := 0
	for _, fname := range paths {
		ok, err := offsetAlignFile(fname, blob, base, elem, cnt)
		if err != nil {
			return num, err
		}
		if ok {
			num++
		}
	}
	return num, nil
}

type AlignedOffset struct {
	Base  uint
	Elem  BlobOffMult
	Field uint
	Raw   []string
}

func (o AlignedOffset) String() string {
	var parts []string
	if o.Base != 0 {
		parts = append(parts, strconv.FormatUint(uint64(o.Base), 10))
	}
	if o.Elem.Static != 0 {
		parts = append(parts, o.Elem.String())
	}
	if o.Field != 0 {
		parts = append(parts, strconv.FormatUint(uint64(o.Field), 10))
	}
	parts = append(parts, o.Raw...)
	return strings.Join(parts, " + ")
}

func (o AlignedOffset) Replace(fnc func(string) string) {
	o.Elem.Replace(fnc)
	for i, s := range o.Raw {
		o.Raw[i] = fnc(s)
	}
}

func (o *BlobOffSum) AddMult(m BlobOffMult) {
	for i, m2 := range o.Mult {
		if m.Static == m2.Static {
			o.Mult[i].Sum.Merge(m.Sum)
			return
		}
	}
	o.Mult = append(o.Mult, m)
}

func (o BlobOffSum) Align(base, elem, cnt uint) (AlignedOffset, bool) {
	size := elem * cnt
	if o.Static < base || (size != 0 && o.Static >= base+size) {
		return AlignedOffset{}, false
	}
	out := AlignedOffset{
		Base:  base,
		Field: o.Static - base,
	}
	if out.Field >= elem {
		o.Mult = append([]BlobOffMult{}, o.Mult...)
		n := out.Field / elem
		out.Field %= elem
		o.AddMult(BlobOffMult{Static: elem, Sum: BlobOffSum{Static: n}})
	}
	el, mrest := o.FindMult(elem)
	if el != nil {
		out.Elem = *el
	}
	for _, m := range mrest {
		out.Raw = append(out.Raw, m.String())
	}
	out.Raw = append(out.Raw, o.Raw...)
	return out, true
}

func offsetAlignFile(path string, blob, base, elem, cnt uint) (bool, error) {
	data, err := ioutil.ReadFile(path)
	if err != nil {
		return false, err
	}
	out := offsetAlign(data, blob, base, elem, cnt)
	if out == nil || bytes.Equal(data, out) {
		return false, nil // skip
	}
	err = ioutil.WriteFile(path, out, 0644)
	return true, err
}

func offsetAlign(data []byte, blob, base, elem, cnt uint) []byte {
	if cnt <= 0 {
		cnt = 1
	}
	var (
		buf      bytes.Buffer
		replaced = 0
	)
	for {
		b, ok := nextBlobCall(data)
		if !ok {
			if buf.Len() == 0 {
				return nil // skip
			}
			buf.Write(data)
			break
		}
		if buf.Len() == 0 {
			buf.Grow(len(data))
		}
		next := b.Off[0] // continue from the expression - it may contain other calls
		if b.Base != blob {
			buf.Write(data[:next])
			data = data[next:]
			continue // skip
		}
		exp := bytes.TrimSpace(data[b.Off[0]:b.Off[1]])
		offs, ok := parseOffSum(exp)
		if !ok {
			buf.Write(data[:next])
			data = data[next:]
			continue // skip
		}
		aoff, ok := offs.Align(base, elem, cnt)
		if !ok {
			buf.Write(data[:next])
			data = data[next:]
			continue // skip
		}
		buf.Write(data[:b.Pos[0]])
		fmt.Fprintf(&buf, "%s(0x%X, ", b.Name, b.Base)
		aoff.Replace(func(s string) string {
			nout := offsetAlign([]byte(s), blob, base, elem, cnt)
			if len(nout) == 0 {
				return s
			}
			return string(nout)
		})
		buf.WriteString(aoff.String())
		buf.WriteString(")")
		data = data[b.Pos[1]:]
		replaced++
	}
	if replaced == 0 {
		return nil
	}
	return buf.Bytes()
}

func readFileListC(path string, ignore []string) ([]string, error) {
	var out []string
	err := filepath.Walk(path, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		} else if info.IsDir() {
			return nil // descend
		}
		if !strings.HasSuffix(path, ".c") {
			return nil // ignore
		}
		for _, name := range ignore {
			if strings.HasSuffix(path, name) {
				return nil // ignore
			}
		}
		out = append(out, path)
		return nil
	})
	return out, err
}
