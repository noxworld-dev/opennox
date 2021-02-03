package parsecmd

import "nox/common/strman"

type Color int

const (
	ColorBlack       = Color(1)
	ColorDarkGrey    = Color(2)
	ColorLightGrey   = Color(3)
	ColorWhite       = Color(4)
	ColorDarkRed     = Color(5)
	ColorRed         = Color(6)
	ColorLightRed    = Color(7)
	ColorDarkGreen   = Color(8)
	ColorGreen       = Color(9)
	ColorLightGreen  = Color(10)
	ColorDarkBlue    = Color(11)
	ColorBlue        = Color(12)
	ColorLightBlue   = Color(13)
	ColorDarkYellow  = Color(14)
	ColorYellow      = Color(15)
	ColorLightYellow = Color(16)
)

type Printer interface {
	Printf(cl Color, format string, args ...interface{})
}

func NewConsole(p Printer, sm *strman.StringManager) *Console {
	cn := &Console{
		p:  p,
		sm: sm,
	}
	cn.registerBuiltin()
	return cn
}

type Console struct {
	p      Printer
	sm     *strman.StringManager
	cmds   []Command
	cheats bool
}

func (cn *Console) registerBuiltin() {
	cn.Register(Command{
		Token:  "racoiaws",
		HelpID: "noHelp",
		Flags:  Secret | ClientServer | Flag0x4,
		Func: func(_ int, _ []string) bool {
			cn.SetCheats(true)
			return true
		},
	})
	cn.Register(Command{Token: "help", HelpID: "helphelp", Flags: ClientServer, Func: cn.help})
	cn.Register(Command{Token: "ques", HelpID: "helphelp", Flags: ClientServer, Func: cn.help})
}

func (cn *Console) help(_ int, tokens []string) bool {
	if len(tokens) != 1 {
		return cn.helpOne(1, tokens, cn.cmds)
	}
	cn.helpList(cn.cmds)
	return true
}

func (cn *Console) helpOne(ind int, tokens []string, cmds []Command) bool {
	if ind >= len(tokens) || len(cmds) == 0 {
		return false
	}
	var cmd *Command
	for i, cur := range cmds {
		if tokens[ind] == cur.Token {
			if !cur.Flags.Has(Flag0x4) && (cn.Cheats() || !cur.Flags.Has(Cheat)) {
				cmd = &cmds[i]
				break
			}
		}
	}
	if cmd == nil {
		return false
	}
	if len(cmd.Sub) == 0 {
		help := cn.sm.GetStringInFile(cmd.HelpID, "parsecmd.c")
		cn.p.Printf(ColorRed, help)
		return true
	}
	if ind+1 >= len(tokens) {
		cn.helpList(cmd.Sub)
		return true
	}
	if !cn.helpOne(ind+1, tokens, cmd.Sub) {
		cn.helpList(cmd.Sub)
	}
	return true
}

func (cn *Console) helpList(cmds []Command) {
	for _, cmd := range cmds {
		if !cmd.Flags.Has(Flag0x4) && (cn.Cheats() || !cmd.Flags.Has(Cheat)) {
			help := cn.sm.GetStringInFile(cmd.HelpID, "parsecmd.c")
			cn.p.Printf(ColorRed, "\t%s -\t%s", cmd.Token2, help)
		}
	}
}

func (cn *Console) SetCheats(enabled bool) {
	cn.cheats = enabled
}

func (cn *Console) Cheats() bool {
	return cn.cheats
}

func (cn *Console) Register(c Command) {
	if c.Flags.Has(Secret) {
		c.Token = EncodeSecret(c.Token)
	}
	cn.cmds = append(cn.cmds, c)
}

func (cn *Console) Commands() []Command {
	return cn.cmds
}
