package main

import (
	"archive/zip"
	"bytes"
	"encoding/json"
	"errors"
	"image/png"
	"io"
	"log"
	"os"
	"path"
	"path/filepath"
	"strings"

	"github.com/spf13/cobra"

	"nox/common/bag"
)

func init() {
	cmd := &cobra.Command{
		Use:     "videobag command",
		Short:   "Tools related to Nox video.bag and video.idx files",
		Aliases: []string{"bag"},
	}
	Root.AddCommand(cmd)

	cmdExtract := &cobra.Command{
		Use:     "extract [--bag video.bag] [--idx video.idx] [--out ./out] [file ...]",
		Short:   "Extracts images from Nox video.bag file",
		Aliases: []string{"e"},
	}
	cmd.AddCommand(cmdExtract)
	fBag := cmdExtract.Flags().StringP("bag", "b", "video.bag", "path to video.bag file")
	fIdx := cmdExtract.Flags().StringP("idx", "i", "", "path to video.idx file (empty means auto)")
	fOut := cmdExtract.Flags().StringP("out", "o", "", "output path for images or archive")
	fJSON := cmdExtract.Flags().BoolP("json", "j", false, "write additional image metadata as JSON")
	fZIP := cmdExtract.Flags().BoolP("zip", "z", false, "write files into a ZIP archive")
	cmdExtract.RunE = func(cmd *cobra.Command, args []string) error {
		cmd.SilenceUsage = true
		f, err := bag.OpenWithIndex(*fBag, *fIdx)
		if err != nil {
			return err
		}
		defer f.Close()

		writeFile := func(name string, data []byte) error {
			return os.WriteFile(filepath.Join(*fOut, name), data, 0644)
		}
		if *fZIP {
			zpath := *fOut
			if !strings.HasSuffix(zpath, ".zip") {
				zpath = filepath.Join(zpath, filepath.Base(*fBag)+".zip")
			}
			zf, err := os.Create(zpath)
			if err != nil {
				return err
			}
			defer zf.Close()

			zw := zip.NewWriter(zf)
			defer zw.Close()

			writeFile = func(name string, data []byte) error {
				w, err := zw.Create(name)
				if err != nil {
					return err
				}
				_, err = io.Copy(w, bytes.NewReader(data))
				return err
			}
		}
		process := func(img *bag.Image) error {
			im, pt, err := img.Decode()
			if err != nil {
				return err
			}
			base := strings.TrimSuffix(img.Name, path.Ext(img.Name))
			if *fJSON {
				data, err := json.MarshalIndent(pt, "", "\t")
				if err != nil {
					return err
				}
				if err := writeFile(base+".json", data); err != nil {
					return err
				}
			}
			buf := bytes.NewBuffer(nil)
			err = png.Encode(buf, im)
			if err != nil {
				return err
			}
			if err := writeFile(base+".png", buf.Bytes()); err != nil {
				return err
			}
			return nil
		}
		if len(args) == 0 {
			imgs, err := f.Images()
			if err != nil {
				return err
			}
			var last error
			for _, img := range imgs {
				if err := process(img); err != nil {
					last = err
					log.Println(img.Name, last)
				}
			}
			return last
		}
		var last error
		for _, name := range args {
			img, err := f.ImageByName(name)
			if err != nil {
				last = err
				log.Println(name, last)
				continue
			} else if img == nil {
				last = errors.New("not found")
				log.Println(name, last)
				continue
			}
			if err = process(img); err != nil {
				last = err
				log.Println(name, last)
			}
		}
		return last
	}
}
