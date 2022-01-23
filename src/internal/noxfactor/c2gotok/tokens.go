package c2gotok

import (
	"bytes"
	"go/scanner"
	"go/token"
	"strings"
)

func Tokenize(data []byte) []Token {
	fs := token.NewFileSet()
	f := fs.AddFile("input", -1, len(data))
	var sc scanner.Scanner
	sc.Init(f, data, func(pos token.Position, msg string) {}, scanner.ScanComments)
	var (
		out []Token
		cur = f.Pos(0)
	)
	for {
		pos, tok, lit := sc.Scan()
		if tok == token.EOF {
			break
		}
		if sz := pos - cur; sz > 0 {
			off := f.Offset(cur)
			space := data[off : off+int(sz)]
			out = append(out, Token{Pos: off, Lit: string(space)})
		}
		t := Token{Pos: f.Offset(pos), Tok: tok, Lit: lit}
		added := false
		if n := len(out); n != 0 {
			prev := &out[n-1]
			if tok == token.COMMENT && prev.Tok == token.SEMICOLON && prev.Lit == "\n" && prev.Pos == f.Offset(pos) {
				*prev = t
				added = true
			}
		}
		if !added {
			out = append(out, t)
		}
		cur = pos
		if tok.IsLiteral() || tok.IsKeyword() || tok == token.ILLEGAL || tok == token.COMMENT {
			cur += token.Pos(len(lit))
		} else if tok.IsOperator() {
			cur += token.Pos(len(tok.String()))
		} else {
			cur++
		}
	}
	if sz := f.Pos(len(data)) - cur; sz > 0 {
		off := f.Offset(cur)
		space := data[off : off+int(sz)]
		out = append(out, Token{Pos: off, Lit: string(space)})
	}
	return out
}

type Token struct {
	Pos int
	Tok token.Token
	Lit string
}

func (t Token) String() string {
	switch t.Tok {
	case token.ILLEGAL, token.COMMENT:
		return t.Lit
	case token.SEMICOLON:
		return t.Lit // will be empty for fake semi
	default:
		if t.Tok.IsOperator() {
			return t.Tok.String()
		} else if t.Tok.IsKeyword() || t.Tok.IsLiteral() {
			return t.Lit
		}
		panic(t.Tok.String())
	}
}

func (t Token) IsSpace() bool {
	return t.Tok == token.ILLEGAL && strings.TrimSpace(t.Lit) == ""
}

func Print(buf *bytes.Buffer, toks []Token) {
	for _, t := range toks {
		buf.WriteString(t.String())
	}
}
