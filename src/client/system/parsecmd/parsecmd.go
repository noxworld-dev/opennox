package parsecmd

import "nox/common/strman"

var secretChars = `0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`

func EncodeSecret(s string) string {
	if s == "" {
		return ""
	}
	var out []byte
	for i, c := range s {
		j := (i * int(c-1)) % len(secretChars)
		out = append(out, secretChars[j])
	}
	return string(out)
}

type Flags uint

func (f Flags) Has(v Flags) bool {
	return f&v != 0
}

const (
	Server   = Flags(1 << 0)
	Client   = Flags(1 << 2)
	NoHelp   = Flags(1 << 3)
	Flag0x8  = Flags(1 << 4)
	Cheat    = Flags(1 << 5)
	Flag0x20 = Flags(1 << 6)
	Secret   = Flags(1 << 7)
)

const (
	ClientServer = Server | Client
)

type CommandFunc func(tokInd int, tokens []string) bool

type Command struct {
	Token  string
	Token2 string
	HelpID strman.ID
	Flags  Flags
	Sub    []Command
	Func   CommandFunc
}
