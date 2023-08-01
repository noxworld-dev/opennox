package main

import (
	"os"
	"path/filepath"
	"strings"
	"testing"

	"github.com/stretchr/testify/require"
)

var cases = []struct {
	name string
	file string
	exp  string
	skip bool
}{
	{
		name: "not changed",
		file: `func foo() {}`,
	},
	{
		name: "unsafe add",
		skip: true,
		file: `
func foo() {
	var p unsafe.Pointer
	v := p + 1
	w := p - 1
}`,
		exp: `
func foo() {
	var p *A
	v := unsafe.Add(p, 1)
	w := unsafe.Add(p, -1)
}`,
	},
	{
		name: "unsafe field",
		file: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := *(*uint32)(unsafe.Add(unsafe.Pointer(p), 4))
}`,
		exp: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := p.Y
}`,
	},
	{
		name: "unsafe field zero",
		file: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := *(*uint32)(unsafe.Add(unsafe.Pointer(p), 0))
}`,
		exp: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := p.X
}`,
	},
	{
		name: "unsafe field zero deref",
		skip: true,
		file: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := *(*uint32)(unsafe.Pointer(p))
}`,
		exp: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := p.X
}`,
	},
	{
		name: "unsafe field addr",
		file: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := (*uint32)(unsafe.Add(unsafe.Pointer(p), 4))
}`,
		exp: `
type A struct {
	X, Y int32
}

func foo() {
	var p *A
	v := &p.Y
}`,
	},
}

func TestFixLegacy(t *testing.T) {
	for _, c := range cases {
		c := c
		t.Run(c.name, func(t *testing.T) {
			dir, err := os.MkdirTemp("", "fixlegacy_")
			require.NoError(t, err)
			t.Cleanup(func() {
				_ = os.RemoveAll(dir)
			})
			err = os.WriteFile(filepath.Join(dir, "go.mod"), []byte("module legacy\ngo 1.19\n"), 0644)
			require.NoError(t, err)
			before := []byte("package legacy\n" + strings.TrimSpace(c.file))
			err = os.WriteFile(filepath.Join(dir, "file.go"), before, 0644)
			require.NoError(t, err)

			changed, err := runOnce(dir, ".")
			require.NoError(t, err)
			if c.skip {
				if !changed {
					t.SkipNow()
				}
				t.Fatal("test marked as skipped, but passes")
			}
			if c.exp == "" {
				require.False(t, changed)
				got, err := os.ReadFile(filepath.Join(dir, "file.go"))
				require.NoError(t, err)
				require.Equal(t, string(before), string(got))
			} else {
				require.True(t, changed)
				got, err := os.ReadFile(filepath.Join(dir, "file.go"))
				require.NoError(t, err)
				require.Equal(t, "package legacy\n\n"+strings.TrimSpace(c.exp)+"\n", string(got))
			}
		})
	}
}
