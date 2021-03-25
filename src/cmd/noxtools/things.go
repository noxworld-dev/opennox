package main

import (
	"errors"
	"path/filepath"
	"strings"

	"github.com/spf13/cobra"

	"nox/common/things"
)

func init() {
	cmd := &cobra.Command{
		Use:     "things command",
		Short:   "Tools related to Nox thing.bin file",
		Aliases: []string{"th"},
	}
	Root.AddCommand(cmd)

	cmdJSON := &cobra.Command{
		Use:     "thing2json input output",
		Short:   "Converts Nox thing.bin file to JSON",
		Aliases: []string{"t2j"},
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
		f, err := things.Open(in)
		if err != nil {
			return err
		}
		defer f.Close()
		data, err := f.ReadAll()
		if err != nil {
			return err
		}
		return writeJSON(out, data, *fPretty)
	}
}
