package main

import (
	"errors"
	"io/ioutil"
	"path/filepath"
	"strings"

	"github.com/spf13/cobra"

	"nox/common/crypt"
)

func cmdCryptEncode(cmd *cobra.Command, args []string, enc bool, fkey *int) error {
	var (
		in  string
		out string
	)
	if len(args) == 1 {
		suff, old := ".dec", ".enc"
		if enc {
			suff, old = ".enc", ".dec"
		}
		in = args[0]
		ext := filepath.Ext(in)
		base := strings.TrimSuffix(filepath.Base(in), ext)
		base = strings.TrimSuffix(base, old)
		out = filepath.Join(filepath.Dir(in), base+suff+ext)
	} else if len(args) == 2 {
		in = args[0]
		out = args[1]
	} else {
		return errors.New("expected one or two arguments")
	}
	key := *fkey
	if key <= 0 {
		var ok bool
		key, ok = crypt.KeyForFile(in)
		if !ok {
			return errors.New("key not specified and auto detection failed")
		}
	}
	// TODO: stream file
	data, err := ioutil.ReadFile(in)
	if err != nil {
		return err
	}
	if enc {
		err = crypt.Encode(data, key)
	} else {
		err = crypt.Decode(data, key)
	}
	if err != nil {
		return err
	}
	return ioutil.WriteFile(out, data, 0644)
}

func init() {
	cmd := &cobra.Command{
		Use:     "binfile command",
		Short:   "Tools for encrypting and decrypting Nox bin files (*.bin, *.map)",
		Aliases: []string{"bin"},
	}
	Root.AddCommand(cmd)

	cmdEnc := &cobra.Command{
		Use:     "encrypt [-k ind] input output",
		Short:   "Encrypts Nox bin files (*.bin, *.map)",
		Aliases: []string{"enc", "e"},
	}
	cmd.AddCommand(cmdEnc)
	fEncKey := cmdEnc.Flags().IntP("key", "k", 0, "key index to use")
	cmdEnc.RunE = func(cmd *cobra.Command, args []string) error {
		return cmdCryptEncode(cmd, args, true, fEncKey)
	}

	cmdDec := &cobra.Command{
		Use:     "decrypt [-k ind] input output",
		Short:   "Decrypts Nox bin files (*.bin, *.map)",
		Aliases: []string{"dec", "d"},
	}
	cmd.AddCommand(cmdDec)
	fDecKey := cmdDec.Flags().IntP("key", "k", 0, "key index to use")
	cmdDec.RunE = func(cmd *cobra.Command, args []string) error {
		return cmdCryptEncode(cmd, args, false, fDecKey)
	}
}
