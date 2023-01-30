package main

import (
	"flag"
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"os"
	"path/filepath"
	"strings"
)

var (
	fDir  = flag.String("dir", ".", "source directory")
	fMode = flag.String("mode", "", "processing mode (export)")
)

func main() {
	flag.Parse()
	if err := run(); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run() error {
	var fnc func(path, epath string) error
	switch *fMode {
	default:
		return fmt.Errorf("unsupported mode: %q", *fMode)
	case "export":
		fnc = exportProcessFile
	case "ccall":
		return runCCall()
	}
	return eachSrcFile(fnc)
}

func eachSrcFile(fnc func(path, epath string) error) error {
	names, err := os.ReadDir(*fDir)
	if err != nil {
		return err
	}
	for _, d := range names {
		if !strings.HasSuffix(d.Name(), ".go") {
			continue
		}
		path := filepath.Join(*fDir, d.Name())
		epath := filepath.Join(filepath.Dir(path), "legacy", filepath.Base(path))
		if err := fnc(path, epath); err != nil {
			return err
		}
	}
	return nil
}

func eachDstFile(fnc func(epath string) error) error {
	names, err := os.ReadDir(filepath.Join(*fDir, "legacy"))
	if err != nil {
		return err
	}
	for _, d := range names {
		if !strings.HasSuffix(d.Name(), ".go") {
			continue
		}
		epath := filepath.Join(*fDir, "legacy", d.Name())
		if err := fnc(epath); err != nil {
			return err
		}
	}
	return nil
}

func eachSrcAST(fs *token.FileSet, fnc func(path string, file *ast.File) error) error {
	return eachSrcFile(func(path, _ string) error {
		f, err := os.Open(path)
		if err != nil {
			return err
		}
		defer f.Close()
		file, err := parser.ParseFile(fs, path, f, parser.ParseComments|parser.SkipObjectResolution)
		if err != nil {
			return err
		}
		return fnc(path, file)
	})
}

func eachDstAST(fs *token.FileSet, fnc func(path string, file *ast.File) error) error {
	return eachDstFile(func(path string) error {
		f, err := os.Open(path)
		if err != nil {
			return err
		}
		defer f.Close()
		file, err := parser.ParseFile(fs, path, f, parser.ParseComments|parser.SkipObjectResolution)
		if err != nil {
			return err
		}
		return fnc(path, file)
	})
}
