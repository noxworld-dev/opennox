package main

import (
	"flag"
	"fmt"
	"nox/v1/tainted"
	"os"
)

func main() {
	if err := tainted.RunNox(os.Args); err != nil && err != flag.ErrHelp {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}
