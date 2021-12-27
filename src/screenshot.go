package nox

import (
	"context"
	"image"
	"image/jpeg"
	"image/png"
	"net/http"
	"strconv"
	"time"
)

var screenshots struct {
	req chan chan<- image.Image
}

func init() {
	screenshots.req = make(chan chan<- image.Image)
	http.HandleFunc("/nox/screenshot", screenshotHandler)
}

func maybeScreenshot() {
	select {
	case <-time.After(time.Millisecond):
		return
	case out := <-screenshots.req:
		defer close(out)
		out <- noxrend.CopyPixBuffer()
	}
}

func Screenshot(ctx context.Context) (image.Image, error) {
	out := make(chan image.Image, 1)
	select {
	case <-ctx.Done():
		return nil, ctx.Err()
	case screenshots.req <- out:
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
	img, err := Screenshot(ctx)
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
