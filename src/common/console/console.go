package console

import (
	"context"
	"fmt"
	"strings"
	"sync"

	"nox/v1/common/keybind"
	"nox/v1/common/log"
	"nox/v1/common/strman"
)

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
	Print(cl Color, str string)
	Printf(cl Color, format string, args ...interface{})
}

// LogPrinter returns a printer that writes to a given logger.
func LogPrinter(l *log.Logger) Printer {
	return logPrinter{l: l}
}

type logPrinter struct {
	l *log.Logger
}

func (p logPrinter) Print(cl Color, str string) {
	// TODO: colorize?
	p.l.Print(str)
}
func (p logPrinter) Printf(cl Color, format string, args ...interface{}) {
	// TODO: colorize?
	p.l.Printf(format, args...)
}

// NewMultiPrinter prints into multiple printers at once.
func NewMultiPrinter(list ...Printer) *MultiPrinter {
	return &MultiPrinter{list: list}
}

type MultiPrinter struct {
	mu   sync.Mutex
	list []Printer
}

func (p *MultiPrinter) Add(p2 Printer) {
	p.mu.Lock()
	p.list = append(p.list, p2)
	p.mu.Unlock()
}

func (p *MultiPrinter) Print(cl Color, str string) {
	p.mu.Lock()
	defer p.mu.Unlock()
	for _, s := range p.list {
		s.Print(cl, str)
	}
}

func (p *MultiPrinter) Printf(cl Color, format string, args ...interface{}) {
	str := fmt.Sprintf(format, args...)
	p.Print(cl, str)
}

// LocalizedPrinter is an interface used for command output.
type LocalizedPrinter interface {
	Strings() *strman.StringManager
	Printer
}

type isClientKey struct{}
type isDedicatedKey struct{}
type isCheatsKey struct{}
type curCmdKey struct{}

// AsClient marks the commands as executed client-side.
func AsClient(ctx context.Context) context.Context {
	return context.WithValue(ctx, isClientKey{}, true)
}

// AsServer marks the commands as executed server-side.
func AsServer(ctx context.Context) context.Context {
	return context.WithValue(ctx, isClientKey{}, false)
}

// AsDedicated marks the commands as executed in a dedicated server context.
func AsDedicated(ctx context.Context) context.Context {
	return context.WithValue(ctx, isDedicatedKey{}, false)
}

// WithCheats forces a cheats-enabled flag for this context.
func WithCheats(ctx context.Context) context.Context {
	return context.WithValue(ctx, isCheatsKey{}, true)
}

// IsClient checks if it's a client-side command context.
func IsClient(ctx context.Context) bool {
	v, ok := ctx.Value(isClientKey{}).(bool)
	if !ok {
		return false
	}
	return v
}

// IsServer checks if it's a server-side command context.
func IsServer(ctx context.Context) bool {
	v, ok := ctx.Value(isClientKey{}).(bool)
	if !ok {
		return false
	}
	return !v
}

// IsDedicated checks if it's a dedicated server command context.
func IsDedicated(ctx context.Context) bool {
	v, ok := ctx.Value(isDedicatedKey{}).(bool)
	if !ok {
		return false
	}
	return v
}

// IsCheats checks if this context allows cheat execution.
func IsCheats(ctx context.Context) bool {
	v, ok := ctx.Value(isCheatsKey{}).(bool)
	if !ok {
		return false
	}
	return v
}

// withCommand sets current command string that is being executed.
func withCommand(ctx context.Context, cmd string) context.Context {
	return context.WithValue(ctx, curCmdKey{}, cmd)
}

// CurCommand gets current command string that is being executed.
func CurCommand(ctx context.Context) string {
	v, _ := ctx.Value(curCmdKey{}).(string)
	return v
}

var _ Printer = (*Console)(nil)

// New creates a new console handler.
// A custom exec function can be provided. The function is used for macros only.
// in case it is nil, Exec will be used.
func New(p Printer) *Console {
	cn := &Console{
		p: p,
	}
	cn.registerBuiltin()
	cn.initMacros()
	return cn
}

// Console handles console commands.
type Console struct {
	p        Printer
	sm       *strman.StringManager
	tokAlias map[string]string
	cmds     []*Command
	cheats   bool
	macros   struct {
		disabled bool
		exec     ExecFunc
		byKey    map[keybind.Key]*macro
	}
}

// Print exposes underlying Printer.
func (cn *Console) Print(cl Color, str string) {
	if cn.p != nil {
		cn.p.Print(cl, str)
	}
}

// Printf exposes underlying Printer.
func (cn *Console) Printf(cl Color, format string, args ...interface{}) {
	if cn.p != nil {
		cn.p.Printf(cl, format, args...)
	}
}

// PrintOrError prints given text or prints a generic error if the text is empty.
func (cn *Console) PrintOrError(cl Color, str string) {
	if cn.p == nil {
		return
	}
	if str != "" {
		cn.Print(cl, str)
		return
	}
	str = cn.Strings().GetStringInFile("InternalError", "guicon.c")
	if str != "" {
		cn.Print(cl, str)
	}
}

// Strings exposes the underlying string manager.
func (cn *Console) Strings() *strman.StringManager {
	if cn.sm == nil {
		panic("call Localize first")
	}
	return cn.sm
}

// Localize all command tokens. Additional tokens can be passed as well.
func (cn *Console) Localize(sm *strman.StringManager, tokens ...string) {
	cn.sm = sm
	cn.tokAlias = make(map[string]string)
	cn.localizeCmds(cn.Commands())
	cn.localizeMacros()
	for _, tok := range tokens {
		sid := strman.ID(fmt.Sprintf("cmd_token:%s", tok))
		alias := cn.sm.GetStringInFile(sid, "parsecmd.c")
		cn.tokAlias[alias] = tok
	}
}

func (cn *Console) localizeCmds(cmds []*Command) {
	for i := range cmds {
		c := cmds[i]
		if v, ok := cn.sm.GetVariant(strman.ID("cmd_token:" + c.Token)); ok {
			c.Alias = v.Str
		} else {
			c.Alias = c.Token
		}
		cn.tokAlias[c.Alias] = c.Token
		cn.localizeCmds(c.Sub)
	}
}

func (cn *Console) registerBuiltin() {
	cn.Register(&Command{
		Token:  "racoiaws",
		HelpID: "noHelp",
		Flags:  Secret | ClientServer | NoHelp,
		Func: func(ctx context.Context, c *Console, _ []string) bool {
			c.SetCheats(true)
			return true
		},
	})
	cn.Register(&Command{Token: "help", HelpID: "helphelp", Flags: ClientServer, LegacyFunc: helpCmd})
	cn.Register(&Command{Token: "ques", HelpID: "helphelp", Flags: ClientServer, LegacyFunc: helpCmd})
	cn.Register(&Command{
		Token:  "colors",
		Help:   "test console colors",
		HelpID: "helpcolors",
		Flags:  ClientServer,
		Func: func(ctx context.Context, c *Console, tokens []string) bool {
			c.Print(ColorBlack, " 1: Black")
			c.Print(ColorDarkGrey, " 2: DarkGrey")
			c.Print(ColorLightGrey, " 3: LightGrey")
			c.Print(ColorWhite, " 4: White")
			c.Print(ColorDarkRed, " 5: DarkRed")
			c.Print(ColorRed, " 6: Red")
			c.Print(ColorLightRed, " 7: LightRed")
			c.Print(ColorDarkGreen, " 8: DarkGreen")
			c.Print(ColorGreen, " 9: Green")
			c.Print(ColorLightGreen, "10: LightGreen")
			c.Print(ColorDarkBlue, "11: DarkBlue")
			c.Print(ColorBlue, "12: Blue")
			c.Print(ColorLightBlue, "13: LightBlue")
			c.Print(ColorDarkYellow, "14: DarkYellow")
			c.Print(ColorYellow, "15: Yellow")
			c.Print(ColorLightYellow, "16: LightYellow")
			return true
		},
	})
}

func (cn *Console) HelpString(cmd *Command) string {
	if cmd.HelpID != "" {
		if help, ok := cn.sm.GetVariantInFile(cmd.HelpID, "parsecmd.c"); ok {
			return help.Str
		}
	}
	return cmd.Help
}

func helpCmd(ctx context.Context, c *Console, _ int, tokens []string) bool {
	if len(tokens) != 1 {
		return c.helpOne(ctx, 1, tokens, c.cmds)
	}
	c.helpList(ctx, c.cmds)
	return true
}

func (cn *Console) helpOne(ctx context.Context, ind int, tokens []string, cmds []*Command) bool {
	if ind >= len(tokens) || len(cmds) == 0 {
		return false
	}
	var cmd *Command
	for i, cur := range cmds {
		if tokens[ind] == cur.Token {
			if !cur.Flags.Has(NoHelp) && (cn.Cheats() || IsCheats(ctx) || !cur.Flags.Has(Cheat)) {
				cmd = cmds[i]
				break
			}
		}
	}
	if cmd == nil {
		return false
	}
	if len(cmd.Sub) == 0 {
		cn.p.Print(ColorRed, cn.HelpString(cmd))
		return true
	}
	if ind+1 >= len(tokens) {
		cn.helpList(ctx, cmd.Sub)
		return true
	}
	if !cn.helpOne(ctx, ind+1, tokens, cmd.Sub) {
		cn.helpList(ctx, cmd.Sub)
	}
	return true
}

func (cn *Console) helpList(ctx context.Context, cmds []*Command) {
	for _, cmd := range cmds {
		if !cmd.Flags.Has(NoHelp) && (cn.Cheats() || IsCheats(ctx) || !cmd.Flags.Has(Cheat)) {
			cn.p.Printf(ColorRed, "\t%s -\t%s", cmd.Alias, cn.HelpString(cmd))
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
func (cn *Console) ParseToken(ctx context.Context, tokInd int, tokens []string, cmds []*Command) bool {
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
	if cmd.Flags.Has(Cheat) && !IsDedicated(ctx) && !cn.Cheats() && !IsCheats(ctx) {
		return false
	}
	if !IsClient(ctx) {
		if !cmd.Flags.Has(Server) {
			s := cn.Strings().GetString("parsecmd.c:clientonly")
			cn.Print(ColorRed, s)
			return true
		}
	} else {
		if !cmd.Flags.Has(Client) {
			s := cn.Strings().GetString("parsecmd.c:serveronly")
			cn.Print(ColorRed, s)
			return true
		}
	}
	if cmd.Flags.Has(FlagDedicated) && !IsDedicated(ctx) {
		return true
	}
	var res bool
	if len(cmd.Sub) != 0 { // have sub-commands
		if tokInd+1 >= len(tokens) {
			// not enough tokens - print help
			cn.Print(ColorRed, cn.HelpString(cmd))
			return true
		}
		// continue parsing the sub command
		res = cn.ParseToken(ctx, tokInd+1, tokens, cmd.Sub)
	} else {
		// call console command handler, let it parse the rest
		if cmd.Func != nil {
			res = cmd.Func(ctx, cn, tokens[tokInd+1:])
		} else {
			res = cmd.LegacyFunc(ctx, cn, tokInd+1, tokens)
		}
	}
	if !res {
		// command failed - print help
		cn.Print(ColorRed, cn.HelpString(cmd))
		return true
	}
	return res
}

// Exec a given console command.
func (cn *Console) Exec(ctx context.Context, cmd string) bool {
	ctx = withCommand(ctx, cmd)
	var (
		tokens []string
	)
	for len(cmd) > 0 {
		var token string
		if cmd[0] == '"' {
			if i := strings.IndexAny(cmd[1:], "\"\n\r"); i >= 0 {
				i++
				token = cmd[1:i]
				cmd = cmd[i+1:]
			} else {
				token = cmd[1:]
				cmd = ""
			}
			tokens = append(tokens, token)
			continue
		}
		if i := strings.IndexByte(cmd, ' '); i >= 0 {
			token = cmd[:i]
			cmd = cmd[i+1:]
		} else {
			token = cmd
			cmd = ""
		}
		if toknew, ok := cn.tokAlias[token]; ok {
			token = toknew
		}
		if token != "" {
			tokens = append(tokens, token)
		}
	}
	if len(tokens) == 0 {
		return false
	}
	ok := cn.ParseToken(ctx, 0, tokens, cn.Commands())
	if !ok {
		help := cn.sm.GetStringInFile("typehelp", "parsecmd.c")
		cn.p.Print(ColorRed, help)
	}
	return ok
}
