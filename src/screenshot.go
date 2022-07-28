package opennox

import (
	"context"
	"image"
	"image/jpeg"
	"image/png"
	"net/http"
	"strconv"
	"time"
)

type screenshots struct {
	req chan chan<- image.Image
}

func (c *screenshots) Init(cli *Client) {
	c.req = make(chan chan<- image.Image)
}

func init() {
	http.HandleFunc("/nox/screenshot", screenshotHandler)
}

func (c *Client) maybeScreenshot() {
	select {
	case <-time.After(time.Millisecond):
		return
	case out := <-c.screenshots.req:
		defer close(out)
		out <- c.r.CopyPixBuffer()
	}
}

func (c *Client) Screenshot(ctx context.Context) (image.Image, error) {
	out := make(chan image.Image, 1)
	select {
	case <-ctx.Done():
		return nil, ctx.Err()
	case c.screenshots.req <- out:
	}
	select {
	case <-ctx.Done():
		return nil, ctx.Err()
	case img := <-out:
		return img, nil
	}
}

func screenshotHandler(w http.ResponseWriter, r *http.Request) {
	ctx := r.Context()
	img, err := noxClient.Screenshot(ctx)
	if err != nil {
		w.WriteHeader(http.StatusInternalServerError)
		w.Write([]byte(err.Error()))
		return
	} else if img == nil {
		w.WriteHeader(http.StatusNotImplemented)
		return
	}
	qu := r.URL.Query()
	switch qu.Get("f") {
	case "png":
		_ = png.Encode(w, img)
	case "jpg", "jpeg":
		fallthrough
	default:
		var opt *jpeg.Options
		if q, err := strconv.Atoi(qu.Get("q")); err == nil {
			if q >= 1 && q <= 100 {
				opt = &jpeg.Options{Quality: q}
			}
		}
		_ = jpeg.Encode(w, img, opt)
	}
}
