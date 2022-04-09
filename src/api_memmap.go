package opennox

import (
	"archive/zip"
	"fmt"
	"net/http"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

func init() {
	http.HandleFunc("/debug/nox/memmap/validate", func(w http.ResponseWriter, r *http.Request) {
		memmap.ValidateZeros()
	})
	http.HandleFunc("/debug/nox/memmap/snapshot", func(w http.ResponseWriter, r *http.Request) {
		zw := zip.NewWriter(w)
		defer zw.Close()
		for _, b := range memmap.Blobs() {
			w, err := zw.Create(fmt.Sprintf("blob_%X.dat", b.Addr))
			if err != nil {
				break
			}
			w.Write(b.Data)
		}
	})
}
