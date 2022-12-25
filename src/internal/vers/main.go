package main

import (
	"errors"
	"flag"
	"fmt"
	"os"

	"github.com/noxworld-dev/opennox/v1/internal/vers/git"
)

var (
	fNoNewLine = flag.Bool("n", false, "do not add newline")
	fOut       = flag.String("o", "", "output file")
)

func main() {
	flag.Parse()
	if err := run(flag.Args()); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run(args []string) error {
	if len(args) < 1 {
		return errors.New("at least one argument expected")
	}
	var res string
	switch args[0] {
	default:
		return fmt.Errorf("unsupported command: %q", args[0])
	case "commit", "sha":
		res = git.ShortSHA()
	case "version", "vers":
		vers, _ := git.Version()
		res = vers
	case "full":
		res = git.FullVersion()
	}
	if out := *fOut; out != "" && out != "-" {
		return os.WriteFile(out, []byte(res), 0644)
	}
	if *fNoNewLine {
		fmt.Print(res)
	} else {
		fmt.Println(res)
	}
	return nil
}
