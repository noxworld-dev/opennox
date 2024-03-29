package opennox

import (
	"context"
	"fmt"
	"image/png"
	"io"
	"os"
	"sync/atomic"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/log"

	"github.com/noxworld-dev/opennox-lib/console"
)

func init() {
	noxConsole.Register(&console.Command{
		Token:  "image",
		HelpID: "imagehelp",
		Flags:  console.ClientServer,
		Func:   cmdScreenshot,
	})
}

func cmdScreenshot(ctx context.Context, c *console.Console, tokens []string) bool {
	makeScreenshot()
	return true
}

var screenshotSeq uint32

func makeScreenshot() {
	// Screenshot will wait for the next clean frame, so must run in a goroutine
	go func() {
		img, err := noxClient.Screenshot(context.Background())
		if err != nil {
			log.Println("cannot take screenshot:", err)
			return
		}
		base := datapath.Data("nox")
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
}
