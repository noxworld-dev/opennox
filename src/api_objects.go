package opennox

import (
	"encoding/json"
	"net/http"
	"strconv"
	"strings"

	"github.com/noxworld-dev/opennox-lib/object"

	"github.com/noxworld-dev/opennox/v1/server"
)

var _ json.Marshaler = &Object{}
var _ json.Marshaler = &server.ObjectType{}

func (obj *Object) MarshalJSON() ([]byte, error) {
	return obj.SObj().MarshalJSON()
}

func init() {
	http.HandleFunc("/debug/nox/types", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, noxServer.Types.List())
	})
	http.HandleFunc("/debug/nox/objects", func(w http.ResponseWriter, r *http.Request) {
		qu := r.URL.Query()
		indStr := qu.Get("ind")
		if indStr == "" {
			writeJSONResp(w, noxServer.GetObjects())
			return
		}
		ind, err := strconv.ParseInt(indStr, 10, 32)
		if err != nil {
			http.Error(w, "Bad index", http.StatusBadRequest)
			return
		}
		obj := asObjectS(noxServer.Objs.GetObjectByInd(int(ind)))
		if obj == nil {
			http.Error(w, "Not found", http.StatusFound)
			return
		}
		all := obj.Flags()
		for _, word := range strings.Split(qu.Get("flags"), ",") {
			fname := word
			unset := false
			if strings.HasPrefix(fname, "-") {
				unset = true
				fname = fname[1:]
			}
			fl, err := object.ParseFlag(fname)
			if err != nil {
				http.Error(w, err.Error(), http.StatusBadRequest)
				return
			}
			if unset {
				all &^= fl
			} else {
				all |= fl
			}
		}
		obj.ObjFlags = uint32(all)
		writeJSONResp(w, obj)
	})
}
