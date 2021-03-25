package main

import (
	"encoding/json"
	"fmt"
	"os"

	"github.com/spf13/cobra"
)

var Root = &cobra.Command{
	Use:   "noxtools",
	Short: "A collection of Nox tools",
}

func main() {
	if err := Root.Execute(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func writeJSON(path string, data interface{}, pretty bool) error {
	f, err := os.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	enc := json.NewEncoder(f)
	if pretty {
		enc.SetIndent("", "\t")
	}
	if err = enc.Encode(data); err != nil {
		return err
	}
	return f.Close()
}
