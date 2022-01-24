package c2gotok

import (
	"go/token"
	"strings"
)

var (
	c2goIdents = map[string]string{
		"uint64_t": "uint64",
		"uint32_t": "uint32",
		"uint16_t": "uint16",
		"uint8_t":  "uint8",
		"char":     "byte",
		"float":    "float32",
		"double":   "float64",
	}
	c2goKnowTypes = []string{
		"int", "char", "byte", "float", "double",
		"uint64_t", "uint32_t", "uint16_t", "uint8_t",
		"uint64", "uint32", "uint16", "uint8",
	}
)

func C2Go(toks []Token) []Token {
	c := new(c2goConv)
	return c.Convert(toks)
}

type c2goConv struct {
	toks []Token
	prev Token
}

func (c *c2goConv) Convert(toks []Token) []Token {
	c.toks = toks
	out := make([]Token, 0, len(toks))
	for {
		res, ok := c.convertNext()
		if !ok {
			break
		}
		out = append(out, res...)
	}
	return out
}

type checkFunc func() ([]Token, bool)

func (c *c2goConv) convertNext() ([]Token, bool) {
	if len(c.toks) == 0 {
		return nil, false
	}
	if i, ok := c.spaces(); ok {
		space := c.toks[:i]
		c.skip(i)
		return space, true
	}
	for _, check := range []checkFunc{
		c.checkTwoWordTypes,
		c.checkConvToPtrOrder,
		c.checkConvTo,
		c.checkConvToPtrIdent,
		c.checkConvToPtrIdentAddr,
		//c.checkAssignConv,
		c.checkIfParen,
		c.checkForParen,
		c.checkWhile1,
		c.checkWhile,
		c.checkDoWhile,
	} {
		if toks, ok := check(); ok {
			return toks, true
		}
	}
	t := c.toks[0]
	switch t.Tok {
	case token.IDENT:
		if v, ok := c2goIdents[t.Lit]; ok && c.prev.Tok != token.PERIOD {
			t.Lit = v
		}
	}
	c.skip(1)
	return []Token{t}, true
}

func (c *c2goConv) skip(n int) {
	if n == 0 {
		return
	}
	c.prev = c.toks[n-1]
	c.toks = c.toks[n:]
}

func (c *c2goConv) replace(n int, replace ...Token) {
	if n >= len(replace) {
		c.skip(n - len(replace))
		copy(c.toks, replace)
		return
	}
	c.skip(n)
	out := make([]Token, len(replace)+len(c.toks))
	i := copy(out, replace)
	copy(out[i:], c.toks)
	c.toks = out
}

func (c *c2goConv) spaces() (int, bool) {
	if len(c.toks) == 0 {
		return 0, false
	}
	for i, t := range c.toks {
		if t.Tok != token.ILLEGAL || strings.TrimSpace(t.Lit) != "" {
			return i, i != 0
		}
	}
	return len(c.toks), true
}

func (c *c2goConv) skipSpaces() {
	if i, ok := c.spaces(); ok {
		c.toks = c.toks[i:]
	}
}

func (c *c2goConv) tokens(exact bool, tokens ...interface{}) (int, []Token, bool) {
	if len(c.toks) < len(tokens) {
		return 0, nil, false
	}
	conds := make([]matchOp, 0, 2*len(tokens)-1)
	for i, v := range tokens {
		if i != 0 && !exact {
			conds = append(conds, matchSpaces())
		}
		conds = append(conds, asMatchOp(v))
	}
	j := 0
	last := 0
	var out []Token
	for i := 0; i < len(c.toks); i++ {
		if j >= len(conds) {
			last = i
			break
		}
		t := c.toks[i]
		ok := conds[j].Matches(t)
		page, res := conds[j].Result()
		if res == matchFail {
			return 0, nil, false
		}
		if !ok {
			i--
		}
		switch res {
		case matchDone:
			out = append(out, page...)
			j++
		case matchMore:
			// nop
		default:
			panic(res)
		}
	}
	return last, out, true
}

func (c *c2goConv) checkTwoWordTypes() ([]Token, bool) {
	if i, _, ok := c.tokens(false, "unsigned", "int"); ok {
		c.skip(i)
		return []Token{{Tok: token.IDENT, Lit: "uint32"}}, true
	}
	if i, _, ok := c.tokens(false, "unsigned", "short"); ok {
		c.skip(i)
		return []Token{{Tok: token.IDENT, Lit: "uint16"}}, true
	}
	if i, _, ok := c.tokens(false, "unsigned", "char"); ok {
		c.skip(i)
		return []Token{{Tok: token.IDENT, Lit: "byte"}}, true
	}
	if i, _, ok := c.tokens(false, "const", "char"); ok {
		c.skip(i)
		return []Token{{Tok: token.IDENT, Lit: "byte"}}, true
	}
	return nil, false
}

func (c *c2goConv) checkConvToPtrOrder() ([]Token, bool) {
	id := asMatchOp(token.IDENT)
	ptr := matchOneOrMore(token.MUL)
	li, _, ok := c.tokens(false, token.LPAREN, id, ptr, token.RPAREN)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.LPAREN},
	}...)
	page, _ := ptr.Result()
	toks = append(toks, page...)
	page, _ = id.Result()
	toks = append(toks, page...)
	toks = append(toks, []Token{
		{Tok: token.RPAREN},
	}...)
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkConvTo() ([]Token, bool) {
	for _, typ := range c2goKnowTypes {
		if toks, ok := c.checkConvToType(typ); ok {
			return toks, true
		}
	}
	return nil, false
}

func (c *c2goConv) checkConvToType(typ string) ([]Token, bool) {
	id := asMatchOp(token.IDENT)
	last := asMatchOp(func(t Token) bool {
		return t.Tok != token.LPAREN && t.Tok != token.LBRACK
	})
	li, _, ok := c.tokens(false, token.LPAREN, typ, token.RPAREN, id, last)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.LPAREN},
		{Tok: token.IDENT, Lit: typ},
		{Tok: token.RPAREN},
		{Tok: token.LPAREN},
	}...)
	page, _ := id.Result()
	toks = append(toks, page...)
	toks = append(toks, []Token{
		{Tok: token.RPAREN},
	}...)
	page, _ = last.Result()
	toks = append(toks, page...)
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkConvToPtrIdent() ([]Token, bool) {
	for _, typ := range c2goKnowTypes {
		if toks, ok := c.checkConvToPtrIdentType(typ); ok {
			return toks, true
		}
	}
	return nil, false
}

func (c *c2goConv) checkConvToPtrIdentType(typ string) ([]Token, bool) {
	ptrs := matchOneOrMore(token.MUL)
	id := asMatchOp(token.IDENT)
	last := asMatchOp(func(t Token) bool {
		return t.Tok != token.LPAREN && t.Tok != token.LBRACK
	})
	li, _, ok := c.tokens(false, token.LPAREN, ptrs, typ, token.RPAREN, id, last)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.LPAREN},
	}...)
	page, _ := ptrs.Result()
	toks = append(toks, page...)
	toks = append(toks, []Token{
		{Tok: token.IDENT, Lit: typ},
		{Tok: token.RPAREN},
		{Tok: token.LPAREN},
	}...)
	page, _ = id.Result()
	toks = append(toks, page...)
	toks = append(toks, []Token{
		{Tok: token.RPAREN},
	}...)
	page, _ = last.Result()
	toks = append(toks, page...)
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkConvToPtrIdentAddr() ([]Token, bool) {
	for _, typ := range c2goKnowTypes {
		if toks, ok := c.checkConvToPtrIdentAddrType(typ); ok {
			return toks, true
		}
	}
	return nil, false
}

func (c *c2goConv) checkConvToPtrIdentAddrType(typ string) ([]Token, bool) {
	ptrs := matchOneOrMore(token.MUL)
	id := asMatchOp(token.IDENT)
	last := asMatchOp(func(t Token) bool {
		return t.Tok != token.LPAREN && t.Tok != token.LBRACK
	})
	li, _, ok := c.tokens(false, token.LPAREN, ptrs, typ, token.RPAREN, token.AND, id, last)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.LPAREN},
	}...)
	page, _ := ptrs.Result()
	toks = append(toks, page...)
	toks = append(toks, []Token{
		{Tok: token.IDENT, Lit: typ},
		{Tok: token.RPAREN},
		{Tok: token.LPAREN},
		{Tok: token.AND},
	}...)
	page, _ = id.Result()
	toks = append(toks, page...)
	toks = append(toks, []Token{
		{Tok: token.RPAREN},
	}...)
	page, _ = last.Result()
	toks = append(toks, page...)
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkAssignConv() ([]Token, bool) {
	for _, typ := range c2goKnowTypes {
		if toks, ok := c.checkAssignConvType(typ); ok {
			return toks, true
		}
	}
	return nil, false
}

func (c *c2goConv) checkAssignConvType(typ string) ([]Token, bool) {
	ptrs := matchZeroOrMore(token.MUL)
	li, _, ok := c.tokens(false, token.ASSIGN, token.LPAREN, ptrs, typ, token.RPAREN)
	if !ok {
		return nil, false
	}
	toks := []Token{
		{Tok: token.ASSIGN},
	}
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkIfParen() ([]Token, bool) {
	cond := matchClosing(token.LPAREN, token.RPAREN)
	li, _, ok := c.tokens(false, token.IF, token.LPAREN, cond, token.LBRACE)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.IF, Lit: "if"}, {Lit: " "},
	}...)
	page, _ := cond.Result()
	toks = append(toks, page[:len(page)-1]...)
	toks = append(toks, []Token{
		{Lit: " "}, {Tok: token.LBRACE},
	}...)
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkForParen() ([]Token, bool) {
	cond := matchClosing(token.LPAREN, token.RPAREN)
	li, _, ok := c.tokens(false, token.FOR, token.LPAREN, cond, token.LBRACE)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.FOR, Lit: "for"}, {Lit: " "},
	}...)
	page, _ := cond.Result()
	toks = append(toks, page[:len(page)-1]...)
	toks = append(toks, []Token{
		{Lit: " "}, {Tok: token.LBRACE},
	}...)
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkWhile1() ([]Token, bool) {
	li, _, ok := c.tokens(false, "while", token.LPAREN, "1", token.RPAREN, token.LBRACE)
	if !ok {
		return nil, false
	}
	c.replace(li, []Token{
		{Tok: token.FOR, Lit: "for"},
		{Lit: " "},
		{Tok: token.LBRACE},
	}...)
	return nil, true
}

func (c *c2goConv) checkWhile() ([]Token, bool) {
	cond := matchClosing(token.LPAREN, token.RPAREN)
	li, _, ok := c.tokens(false, "while", token.LPAREN, cond, token.LBRACE)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.FOR, Lit: "for"},
		{Lit: " "},
	}...)
	page, _ := cond.Result()
	toks = append(toks, page[:len(page)-1]...)
	toks = append(toks, []Token{
		{Tok: token.LBRACE},
	}...)
	c.replace(li, toks...)
	return nil, true
}

func (c *c2goConv) checkDoWhile() ([]Token, bool) {
	if c.toks[0].Lit != "do" {
		return nil, false
	}
	body := matchClosing(token.LBRACE, token.RBRACE)
	cond := matchClosing(token.LPAREN, token.RPAREN)
	li, _, ok := c.tokens(false, "do", token.LBRACE, body, "while", token.LPAREN, cond, token.SEMICOLON)
	if !ok {
		return nil, false
	}
	var toks []Token
	toks = append(toks, []Token{
		{Tok: token.FOR, Lit: "for"}, {Lit: " "},
		{Tok: token.LBRACE}, {Lit: "\n\t\t"},
	}...)
	page, _ := body.Result()
	toks = append(toks, page[:len(page)-1]...)
	toks = append(toks, []Token{
		{Lit: "\t"}, {Tok: token.IF, Lit: "if"}, {Lit: " "},
		{Tok: token.NOT},
		{Tok: token.LPAREN},
	}...)
	page, _ = cond.Result()
	toks = append(toks, page...)
	toks = append(toks, []Token{
		{Lit: " "}, {Tok: token.LBRACE}, {Lit: "\n\t\t\t"},
		{Tok: token.BREAK, Lit: "break"}, {Lit: "\n\t\t"},
		{Tok: token.RBRACE}, {Lit: "\n\t"},
		{Tok: token.RBRACE},
	}...)
	c.replace(li, toks...)
	return nil, true
}

func asMatchOp(v interface{}) matchOp {
	switch v := v.(type) {
	case matchOp:
		return v
	case matchFunc:
		return &matchTok{fnc: v}
	case func(t Token) bool:
		return &matchTok{fnc: v}
	case string:
		return &matchTok{fnc: func(t Token) bool {
			return v == t.Lit
		}}
	case token.Token:
		return &matchTok{fnc: func(t Token) bool {
			return v == t.Tok
		}}
	default:
		panic(v)
	}
}

type matchRes int

const (
	matchNone = matchRes(iota)
	matchFail
	matchDone
	matchMore
)

func mustMatchSpace() matchOp {
	return &multiMatch{op: &matchTok{fnc: func(t Token) bool {
		return t.IsSpace()
	}}}
}

func matchSpaces() matchOp {
	return &multiMatch{zero: true, op: &matchTok{fnc: func(t Token) bool {
		return t.IsSpace()
	}}}
}

type matchFunc func(t Token) bool

type matchTok struct {
	fnc matchFunc
	res matchRes
	t   Token
}

func (m *matchTok) Matches(t Token) bool {
	if !m.fnc(t) {
		m.res = matchFail
		return false
	}
	m.res = matchDone
	m.t = t
	return true
}

func (m *matchTok) Result() ([]Token, matchRes) {
	if m.res == matchFail {
		return nil, m.res
	}
	return []Token{m.t}, m.res
}

type multiMatch struct {
	op        matchOp
	res       matchRes
	toks      []Token
	zero      bool
	skipSpace bool
}

func (m *multiMatch) Matches(t Token) bool {
	if m.op.Matches(t) {
		m.toks = append(m.toks, t)
		m.res = matchMore
		return true
	}
	if m.skipSpace && len(m.toks) != 0 && t.IsSpace() {
		m.res = matchMore
		return true
	}
	if len(m.toks) == 0 && !m.zero {
		m.res = matchFail
	} else {
		m.res = matchDone
	}
	return false
}

func (m *multiMatch) Result() ([]Token, matchRes) {
	if m.res == matchDone {
		return m.toks, m.res
	}
	return nil, m.res
}

func matchOneOrMore(v interface{}) matchOp {
	return &multiMatch{op: asMatchOp(v), skipSpace: true}
}

func matchZeroOrMore(v interface{}) matchOp {
	return &multiMatch{op: asMatchOp(v), skipSpace: true, zero: true}
}

type matchBraces struct {
	lb, rb token.Token
	lvl    int
	toks   []Token
	res    matchRes
}

func (m *matchBraces) Matches(t Token) bool {
	if m.lvl == 0 {
		m.toks = append(m.toks, t)
		switch t.Tok {
		case m.rb:
			m.res = matchDone
			return true
		case m.lb:
			m.lvl++
		}
		m.res = matchMore
		return true
	}
	m.res = matchMore
	m.toks = append(m.toks, t)
	switch t.Tok {
	case m.lb:
		m.lvl++
	case m.rb:
		m.lvl--
		if m.lvl < 0 {
			m.res = matchFail
			return false
		}
	}
	return true
}

func (m *matchBraces) Result() ([]Token, matchRes) {
	if m.res == matchDone {
		return m.toks, m.res
	}
	return nil, m.res
}

func matchClosing(lb, rb token.Token) matchOp {
	return &matchBraces{lb: lb, rb: rb}
}

type matchOp interface {
	Matches(t Token) bool
	Result() ([]Token, matchRes)
}
