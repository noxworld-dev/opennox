package desktop

import (
	"bytes"
	_ "embed"
	"text/template"

	"github.com/noxworld-dev/opennox/v1/internal/vers/git"
)

//go:embed opennox.desktop
var desktopTemplate string

//go:embed opennox-hd.desktop
var desktopTemplateHD string

type Options struct {
	HD       bool
	IconPref string
	ExecPref string
}

func Generate(opts Options) string {
	src := desktopTemplate
	if opts.HD {
		src = desktopTemplateHD
	}
	tpl := template.New("desktop")
	_, err := tpl.Parse(src)
	if err != nil {
		panic(err)
	}
	var buf bytes.Buffer
	err = tpl.Execute(&buf, struct {
		Version  string
		IconPref string
		ExecPref string
	}{
		Version:  git.FullVersion(),
		IconPref: opts.IconPref,
		ExecPref: opts.ExecPref,
	})
	if err != nil {
		panic(err)
	}
	return buf.String()
}
