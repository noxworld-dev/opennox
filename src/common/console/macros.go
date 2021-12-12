package console

import (
	"context"
	"sort"
	"strings"

	"nox/v1/common/keybind"
	"nox/v1/common/strman"
)

type macro struct {
	Key   keybind.Key
	Alias string
	Cmd   string
}

func (cn *Console) initMacros() {
	cn.macros.byKey = make(map[keybind.Key]*macro)

	cn.Register(&Command{
		Token:  "macros",
		HelpID: "macroshelp",
		Flags:  ClientServer,
		Sub: []*Command{
			{Token: "on", HelpID: "macrosonhelp", Flags: Server, Func: func(ctx context.Context, c *Console, tokens []string) bool {
				if len(tokens) != 0 {
					return false
				}
				c.SetMacros(true)
				c.Printf(ColorRed, "%s\n", c.Strings().GetStringInFile("macroson", "parsecmd.c"))
				return true
			}},
			{Token: "off", HelpID: "macrosoffhelp", Flags: Server, Func: func(ctx context.Context, c *Console, tokens []string) bool {
				if len(tokens) != 0 {
					return false
				}
				c.SetMacros(false)
				c.Printf(ColorRed, "%s\n", c.Strings().GetStringInFile("macrosoff", "parsecmd.c"))
				return true
			}},
		},
	})
	cn.Register(&Command{
		Token:  "bind",
		HelpID: "bindHelp",
		Flags:  ClientServer,
		Func: func(ctx context.Context, c *Console, tokens []string) bool {
			if len(tokens) < 2 {
				return false
			}
			return c.BindKeyByName(tokens[0], strings.Join(tokens[1:], " "))
		},
	})
	cn.Register(&Command{
		Token:  "unbind",
		HelpID: "unbindHelp",
		Flags:  ClientServer,
		Func: func(ctx context.Context, c *Console, tokens []string) bool {
			if len(tokens) != 1 {
				return false
			}
			return c.UnBindKeyByName(tokens[0])
		},
	})
	cn.Register(&Command{
		Token:  "bindings",
		HelpID: "showbindingshelp",
		Flags:  ClientServer,
		Func: func(ctx context.Context, c *Console, tokens []string) bool {
			if len(tokens) != 0 {
				return false
			}
			var binds []*macro
			for _, b := range c.macros.byKey {
				if b.Cmd != "" {
					binds = append(binds, b)
				}
			}
			sort.Slice(binds, func(i, j int) bool {
				return binds[i].Key < binds[j].Key
			})
			for _, b := range binds {
				name := b.Key.String()
				if b.Alias == "" || b.Alias == name {
					c.Printf(ColorWhite, "%s - %s\n", name, b.Cmd)
				} else {
					c.Printf(ColorWhite, "%s (%s) - %s\n", name, b.Alias, b.Cmd)
				}
			}
			var sid strman.ID = "macrosOn"
			if c.macros.disabled {
				sid = "macrosOff"
			}
			c.Printf(ColorWhite, "%s\n", c.sm.GetStringInFile(sid, "parsecmd.c"))
			return true
		},
	})
}

func (cn *Console) localizeMacros() {
	for _, b := range cn.macros.byKey {
		b.Alias = cn.sm.GetStringInFile(b.Key.TitleID(), "parsecmd.c")
		cn.tokAlias[b.Alias] = b.Key.String()
	}
}

type ExecFunc func(ctx context.Context, cmd string) bool

// SetExec sets a custom exec function for macros.
func (cn *Console) SetExec(exec ExecFunc) {
	cn.macros.exec = exec
}

// SetMacros enables or disables macros on this console.
func (cn *Console) SetMacros(enabled bool) {
	cn.macros.disabled = !enabled
}

// Macros indicates if macros are enabled on this console.
func (cn *Console) Macros() bool {
	return !cn.macros.disabled
}

// ExecMacros runs a macros associated with a given key. It returns false if the key is not bound to anything.
func (cn *Console) ExecMacros(ctx context.Context, k keybind.Key) bool {
	if cn.macros.disabled {
		return false
	}
	b := cn.macros.byKey[k]
	if b == nil || b.Cmd == "" {
		return false
	}
	cmd := b.Cmd
	cn.Printf(ColorWhite, "> %s\n", cmd)
	if cn.macros.exec != nil {
		return cn.macros.exec(ctx, cmd)
	}
	return cn.Exec(ctx, cmd)
}

// BindKey binds command to a given key.
func (cn *Console) BindKey(k keybind.Key, cmd string) bool {
	b := cn.macros.byKey[k]
	if b == nil {
		b = &macro{Key: k}
		if cn.sm != nil {
			b.Alias = cn.sm.GetStringInFile(k.TitleID(), "parsecmd.c")
			cn.tokAlias[b.Alias] = b.Key.String()
		}
		cn.macros.byKey[k] = b
	}
	b.Cmd = cmd
	return true
}

// UnBindKey unbinds command from a key.
func (cn *Console) UnBindKey(k keybind.Key) bool {
	b := cn.macros.byKey[k]
	if b == nil {
		return false
	}
	b.Cmd = ""
	return true
}

// BindKeyByName binds command to a key with a given alias.
func (cn *Console) BindKeyByName(name string, cmd string) bool {
	k := keybind.KeyByName(name)
	if k == 0 {
		return false
	}
	return cn.BindKey(k, cmd)
}

// UnBindKeyByName unbinds command from a key with a given alias.
func (cn *Console) UnBindKeyByName(name string) bool {
	k := keybind.KeyByName(name)
	if k == 0 {
		return false
	}
	return cn.UnBindKey(k)
}
