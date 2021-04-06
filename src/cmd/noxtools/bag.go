package main

import (
	"archive/zip"
	"bytes"
	"encoding/json"
	"errors"
	"fmt"
	"image"
	_ "image/jpeg"
	"image/png"
	_ "image/png"
	"io"
	"log"
	"os"
	"path"
	"path/filepath"
	"strconv"
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
	fBag := cmd.PersistentFlags().StringP("bag", "b", "video.bag", "path to video.bag file")
	fIdx := cmd.PersistentFlags().StringP("idx", "i", "", "path to video.idx file (empty means auto)")

	cmdJSON := &cobra.Command{
		Use:     "idx2json [--bag video.bag] [--idx video.idx] [--out ./out.json]",
		Short:   "Reads Nox video.idx and dumps metadata stored there as JSON",
		Aliases: []string{"i2j"},
	}
	cmd.AddCommand(cmdJSON)
	{
		fOut := cmdJSON.Flags().StringP("out", "o", "video.idx.json", "output path for images or archive")
		cmdJSON.RunE = func(cmd *cobra.Command, args []string) error {
			cmd.SilenceUsage = true
			f, err := bag.OpenWithIndex(*fBag, *fIdx)
			if err != nil {
				return err
			}
			defer f.Close()

			list, err := f.Segments()
			if err != nil {
				return err
			}

			w, err := os.Create(*fOut)
			if err != nil {
				return err
			}
			defer w.Close()

			enc := json.NewEncoder(w)
			enc.SetIndent("", "\t")
			if err = enc.Encode(list); err != nil {
				return err
			}
			return w.Close()
		}
	}

	cmdExtract := &cobra.Command{
		Use:     "extract [--bag video.bag] [--idx video.idx] [--out ./out] [file ...]",
		Short:   "Extracts images from Nox video.bag file",
		Aliases: []string{"e"},
	}
	cmd.AddCommand(cmdExtract)
	{
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
			process := func(img *bag.ImageRec) error {
				im, err := img.Decode()
				if err != nil {
					return err
				}
				base := strings.TrimSuffix(img.Name, path.Ext(img.Name))
				if *fJSON {
					data, err := json.MarshalIndent(im.ImageMeta, "", "\t")
					if err != nil {
						return err
					}
					if err := writeFile(base+".json", data); err != nil {
						return err
					}
				}
				buf := bytes.NewBuffer(nil)
				err = png.Encode(buf, &im.RGBA)
				if err != nil {
					return err
				}
				if err := writeFile(base+".png", buf.Bytes()); err != nil {
					return err
				}
				if im.Mask != nil {
					buf.Reset()
					err = png.Encode(buf, im.Mask)
					if err != nil {
						return err
					}
					if err := writeFile(base+"_mask.png", buf.Bytes()); err != nil {
						return err
					}
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
	cmdDecompress := &cobra.Command{
		Use:   "decompress [--bag video.bag] [--idx video.idx]",
		Short: "Decompress Nox video.bag file and update video.idx accordingly",
	}
	cmd.AddCommand(cmdDecompress)
	{
		cmdDecompress.RunE = func(cmd *cobra.Command, args []string) error {
			return bag.Decompress(*fBag, *fIdx)
		}
	}
	cmdReplace := &cobra.Command{
		Use:   "replace [--bag video.bag] [--idx video.idx] ",
		Short: "Replace one or more sprites in the Nox video.bag file",
	}
	cmd.AddCommand(cmdReplace)
	{
		fSprites := cmdReplace.Flags().StringSliceP("sprite", "s", nil, "sprite in the format: index1=image1.png")
		cmdReplace.RunE = func(cmd *cobra.Command, args []string) error {
			var list []bag.Replacement
			for _, s := range *fSprites {
				sub := strings.SplitN(s, "=", 3)
				if len(sub) != 2 {
					return fmt.Errorf("sprites should be in the format: index1=image1.png; got: %q", s)
				}
				ind, err := strconv.Atoi(sub[0])
				if err != nil {
					return err
				}
				f, err := os.Open(sub[1])
				if err != nil {
					return err
				}
				img, _, err := image.Decode(f)
				_ = f.Close()
				if err != nil {
					return err
				}
				list = append(list, bag.Replacement{
					ImageInd: ind,
					Image:    img,
					Point:    nil, // TODO: allow overriding the point
				})
			}
			if len(list) == 0 {
				return errors.New("no sprites to replace")
			}
			cmd.SilenceUsage = true
			return bag.ReplaceSprites(*fBag, *fIdx, list)
		}
	}
}
