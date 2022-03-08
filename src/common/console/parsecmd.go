// Package console implements console command parsing for Nox.
package console

import (
	"context"

	"nox/v1/common/strman"
)

var secretChars = `0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`

// EncodeSecret encodes a command token so it's kept secret. See Secret.
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

// Flags represents console command flags.
type Flags uint

func (f Flags) Has(v Flags) bool {
	return f&v != 0
}

const (
	// Server flag allows using this command on the server.
	Server = Flags(1 << 0)
	// Client flag allows using this command on the client.
	Client = Flags(1 << 2)
	// NoHelp hides the command from the commands list printed by help.
	NoHelp  = Flags(1 << 3)
	Flag0x8 = Flags(1 << 4)
	// Cheat marks a command as a cheat, thus requiring enabling cheats first.
	Cheat         = Flags(1 << 5)
	FlagDedicated = Flags(1 << 6)
	// Secret flag is used when the command token should be encrypted.
	Secret = Flags(1 << 7)
)

const (
	// ClientServer flag allows using this command on both the server and the client.
	ClientServer = Server | Client
)

// CommandFunc accepts a set of string arguments (tokens) and executes some action.
// The function should return true if the parsing was successful and false otherwise.
type CommandFunc func(ctx context.Context, c *Console, tokens []string) bool

// CommandLegacyFunc is the same as CommandFunc, but accepts the full array of tokens
// and a index of the first token that is the first argument for the command.
// This functions is a Nox legacy and isn't designed well, e.g. changing parent of the sub-command
// requires changes to the code, since the number of tokens may change.
// The function should return true if the parsing was successful and false otherwise.
type CommandLegacyFunc func(ctx context.Context, c *Console, tokInd int, tokens []string) bool

// Command describes a console command.
type Command struct {
	// Token is the first token (keyword) of the command.
	Token string
	Alias string
	// HelpID is a string ID used to fetch the help text.
	HelpID strman.ID
	// Help is a text string used when a help text cannot be found by HelpID.
	Help string
	// Flags for this command.
	Flags Flags
	// Sub is a list of sub-commands.
	Sub []*Command
	// Func is a function that will be executed.
	Func CommandFunc
	// LegacyFunc is a legacy function that will be executed.
	//
	// Deprecated: use Func instead.
	LegacyFunc CommandLegacyFunc
}

// Register a sub command handler.
func (c *Command) Register(sub *Command) {
	if sub.Flags.Has(Secret) {
		sub.Token = EncodeSecret(sub.Token)
	}
	for _, s := range c.Sub {
		if s.Token == sub.Token {
			panic("already registered: " + sub.Token)
		}
	}
	c.Sub = append(c.Sub, sub)
}
