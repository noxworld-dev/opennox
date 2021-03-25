package main

import (
	"errors"
	"path/filepath"
	"strings"

	"github.com/spf13/cobra"

	"nox/common/strman"
)

func init() {
	cmd := &cobra.Command{
		Use:     "strings command",
		Short:   "Tools for working with Nox string files (*.csf, *.str)",
		Aliases: []string{"str"},
	}
	Root.AddCommand(cmd)

	cmdJSON := &cobra.Command{
		Use:     "csf2json input output",
		Short:   "Converts Nox string files (*.csf) to JSON",
		Aliases: []string{"c2j"},
	}
	cmd.AddCommand(cmdJSON)
	fPretty := cmdJSON.Flags().BoolP("pretty", "p", true, "pretty-print the output")
	cmdJSON.RunE = func(cmd *cobra.Command, args []string) error {
		var (
			in  string
			out string
		)
		if len(args) == 1 {
			in = args[0]
			ext := filepath.Ext(in)
			base := strings.TrimSuffix(filepath.Base(in), ext)
			out = filepath.Join(filepath.Dir(in), base+".json")
		} else if len(args) == 2 {
			in = args[0]
			out = args[1]
		} else {
			return errors.New("expected one or two arguments")
		}
		sm := strman.New()
		err := sm.ReadCSF(in)
		if err != nil {
			return err
		}
		return sm.WriteJSON(out, *fPretty)
	}
}
