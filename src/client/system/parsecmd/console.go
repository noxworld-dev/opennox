package parsecmd

import "nox/v1/common/strman"

// Color of console text messages.
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

// Printer is an interface used for command output.
type Printer interface {
	Printf(cl Color, format string, args ...interface{})
}

// NewConsole creates a new console handler.
func NewConsole(p Printer, sm *strman.StringManager) *Console {
	cn := &Console{
		p:  p,
		sm: sm,
	}
	cn.registerBuiltin()
	return cn
}

// Console handles console commands.
type Console struct {
	p          Printer
	sm         *strman.StringManager
	cmds       []*Command
	cheats     bool
	isClient   bool
	isHeadless bool
}

// Printf exposes underlying Printer.
func (cn *Console) Printf(cl Color, format string, args ...interface{}) {
	if cn.p != nil {
		cn.p.Printf(cl, format, args...)
	}
}

// Strings exposes the underlying string manager.
func (cn *Console) Strings() *strman.StringManager {
	return cn.sm
}

// IsClient checks if it's a client-side console.
func (cn *Console) IsClient() bool {
	return cn.isClient
}

// SetIsClient switches the console to either server or client mode.
func (cn *Console) SetIsClient(v bool) {
	cn.isClient = v
}

// IsHeadless checks if it's a dedicated server console.
func (cn *Console) IsHeadless() bool {
	return cn.isHeadless
}

// SetIsHeadless switches the console to a dedicated server mode or back.
func (cn *Console) SetIsHeadless(v bool) {
	cn.isHeadless = v
}

func (cn *Console) registerBuiltin() {
	cn.Register(&Command{
		Token:  "racoiaws",
		HelpID: "noHelp",
		Flags:  Secret | ClientServer | NoHelp,
		Func: func(c *Console, _ []string) bool {
			c.SetCheats(true)
			return true
		},
	})
	cn.Register(&Command{Token: "help", HelpID: "helphelp", Flags: ClientServer, LegacyFunc: (*Console).help})
	cn.Register(&Command{Token: "ques", HelpID: "helphelp", Flags: ClientServer, LegacyFunc: (*Console).help})
}

func (cn *Console) HelpString(cmd *Command) string {
	if cmd.HelpID != "" {
		if help, ok := cn.sm.GetVariantInFile(cmd.HelpID, "parsecmd.c"); ok {
			return help.Str
		}
	}
	return cmd.Help
}

func (cn *Console) help(_ int, tokens []string) bool {
	if len(tokens) != 1 {
		return cn.helpOne(1, tokens, cn.cmds)
	}
	cn.helpList(cn.cmds)
	return true
}

func (cn *Console) helpOne(ind int, tokens []string, cmds []*Command) bool {
	if ind >= len(tokens) || len(cmds) == 0 {
		return false
	}
	var cmd *Command
	for i, cur := range cmds {
		if tokens[ind] == cur.Token {
			if !cur.Flags.Has(NoHelp) && (cn.Cheats() || !cur.Flags.Has(Cheat)) {
				cmd = cmds[i]
				break
			}
		}
	}
	if cmd == nil {
		return false
	}
	if len(cmd.Sub) == 0 {
		cn.p.Printf(ColorRed, cn.HelpString(cmd))
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

func (cn *Console) helpList(cmds []*Command) {
	for _, cmd := range cmds {
		if !cmd.Flags.Has(NoHelp) && (cn.Cheats() || !cmd.Flags.Has(Cheat)) {
			cn.p.Printf(ColorRed, "\t%s -\t%s", cmd.Token2, cn.HelpString(cmd))
		}
	}
}

// SetCheats enables or disables cheats on this console.
func (cn *Console) SetCheats(enabled bool) {
	cn.cheats = enabled
}

// Cheats indicates if cheats are enabled on this console.
func (cn *Console) Cheats() bool {
	return cn.cheats
}

// Register a command handler for this console.
func (cn *Console) Register(c *Command) {
	if c.Flags.Has(Secret) {
		c.Token = EncodeSecret(c.Token)
	}
	cn.cmds = append(cn.cmds, c)
}

// Commands lists already registered console commands.
func (cn *Console) Commands() []*Command {
	return cn.cmds
}

// ParseToken matches the first token against a list of commands.
func (cn *Console) ParseToken(tokInd int, tokens []string, cmds []*Command) bool {
	if tokInd >= len(tokens) || len(cmds) == 0 {
		return false
	}

	var cmd *Command
	for i, cur := range cmds {
		tok := tokens[tokInd]
		if cur.Flags.Has(Secret) {
			tok = EncodeSecret(tok)
		}
		if tok == cur.Token {
			cmd = cmds[i]
			break
		}
	}
	if cmd == nil {
		return false
	}
	if !cn.IsHeadless() && !cn.Cheats() && cmd.Flags.Has(Cheat) {
		return false
	}
	if !cn.IsClient() {
		if !cmd.Flags.Has(Server) {
			s := cn.Strings().GetString("parsecmd.c:clientonly")
			cn.Printf(ColorRed, s)
			return true
		}
	} else {
		if !cmd.Flags.Has(Client) {
			s := cn.Strings().GetString("parsecmd.c:serveronly")
			cn.Printf(ColorRed, s)
			return true
		}
	}
	if cmd.Flags.Has(FlagDedicated) && !cn.IsHeadless() {
		return true
	}
	var res bool
	if len(cmd.Sub) != 0 { // have sub-commands
		if tokInd+1 >= len(tokens) {
			// not enough tokens - print help
			cn.Printf(ColorRed, cn.HelpString(cmd))
			return true
		}
		// continue parsing the sub command
		res = cn.ParseToken(tokInd+1, tokens, cmd.Sub)
	} else {
		// call console command handler, let it parse the rest
		if cmd.Func != nil {
			res = cmd.Func(cn, tokens[tokInd+1:])
		} else {
			res = cmd.LegacyFunc(cn, tokInd+1, tokens)
		}
	}
	if !res {
		// command failed - print help
		cn.Printf(ColorRed, cn.HelpString(cmd))
		return true
	}
	return res
}
