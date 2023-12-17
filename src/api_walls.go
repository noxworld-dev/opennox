package opennox

import (
	"image"
	"net/http"
	"strconv"
)

func init() {
	http.HandleFunc("/debug/nox/walls", func(w http.ResponseWriter, r *http.Request) {
		x, err1 := strconv.Atoi(r.URL.Query().Get("x"))
		y, err2 := strconv.Atoi(r.URL.Query().Get("y"))
		if err1 == nil && err2 == nil {
			wl := noxServer.Walls.GetWallAtGridRaw(image.Point{X: x, Y: y})
			writeJSONResp(w, wl)
		} else {
			writeJSONResp(w, noxServer.Walls.All())
		}
	})
}
