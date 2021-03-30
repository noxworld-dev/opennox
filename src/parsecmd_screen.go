package main

import (
	"context"
	"fmt"
	"image/png"
	"io"
	"log"
	"os"
	"path/filepath"
	"sync/atomic"

	"nox/client/system/parsecmd"
)

func init() {
	parseCmd.Register(parsecmd.Command{
		Token: "screen",
		Help:  "screen: Save a PNG screenshot to disk.",
		Flags: parsecmd.ClientServer,
		Func:  cmdScreenshot,
	})
}

var screenshotSeq uint32

func cmdScreenshot(tokInd int, tokens []string) bool {
	// Screenshot will wait for the next clean frame, so must run in a goroutine
	go func() {
		img, err := Screenshot(context.Background())
		if err != nil {
			log.Println("cannot take screenshot:", err)
			return
		}
		base := filepath.Join(getDataPath(), "nox")
		var w io.WriteCloser
		for {
			i := atomic.AddUint32(&screenshotSeq, 1)
			f, err := os.OpenFile(fmt.Sprintf("%s%d.png", base, i), os.O_WRONLY|os.O_CREATE|os.O_EXCL, 0644)
			if os.IsExist(err) {
				continue
			} else if err != nil {
				log.Println("cannot save screenshot:", err)
				return
			}
			w = f
			break
		}
		defer w.Close()
		err = png.Encode(w, img)
		if err != nil {
			log.Println("cannot encode screenshot:", err)
			return
		}
		err = w.Close()
		if err != nil {
			log.Println("cannot save screenshot:", err)
			return
		}
	}()
	return true
}
