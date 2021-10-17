package main

import (
	"flag"
	"fmt"
	"os"

	"nox/v1"
)

func main() {
	if err := nox.RunArgs(os.Args); err != nil && err != flag.ErrHelp {
		if code, ok := err.(nox.ErrExit); ok {
			os.Exit(int(code))
		} else {
			fmt.Fprintln(os.Stderr, err)
			os.Exit(1)
		}
	}
}
