package maps

import (
	"encoding/json"
	"net/http"
	"os"
	"path/filepath"

	"github.com/julienschmidt/httprouter"

	"nox/v1/common/fs"
)

var _ http.Handler = (*Server)(nil)

func NewServer(path string) *Server {
	s := &Server{path: path, mux: httprouter.New()}
	s.mux.Handle("HEAD", "/api/v0/maps/", s.handleMapList)
	s.mux.Handle("GET", "/api/v0/maps/", s.handleMapList)

	s.mux.Handle("HEAD", "/api/v0/maps/:map", s.handleMap)
	s.mux.Handle("GET", "/api/v0/maps/:map", s.handleMap)
	s.mux.Handle("GET", "/api/v0/maps/:map/download", s.handleMapDownload)
	return s
}

type Server struct {
	mux  *httprouter.Router
	path string
}

func (s *Server) RegisterOnMux(mux *http.ServeMux) {
	mux.Handle("/api/v0/maps/", s)
}

func (s *Server) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	Log.Println(r.Method, r.URL)
	s.mux.ServeHTTP(w, r)
}

func (s *Server) serveJSON(w http.ResponseWriter, obj interface{}) {
	w.Header().Set("Content-Type", "application/json")
	enc := json.NewEncoder(w)
	enc.SetIndent("", "\t")
	enc.Encode(obj)
}

func (s *Server) handleMapList(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	switch r.Method {
	default:
		w.WriteHeader(http.StatusMethodNotAllowed)
	case "HEAD", "OPTIONS":
		w.WriteHeader(http.StatusOK)
	case "GET":
		list, err := Scan(s.path, nil)
		if err != nil {
			Log.Println("error serving map list:", err)
			if len(list) == 0 {
				w.WriteHeader(http.StatusInternalServerError)
				return
			}
			// serve at least some maps
		}
		s.serveJSON(w, list)
	}
}

func (s *Server) handleMap(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	name := p.ByName("map")
	if name == "" {
		w.WriteHeader(http.StatusNotFound)
		return
	}
	info, err := ReadMapInfo(filepath.Join(s.path, name))
	if os.IsNotExist(err) {
		w.WriteHeader(http.StatusNotFound)
		return
	} else if err != nil {
		Log.Printf("error serving map %q: %v", name, err)
		w.WriteHeader(http.StatusInternalServerError)
		return
	}
	s.serveJSON(w, info)
}

func (s *Server) handleMapDownload(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	name := p.ByName("map")
	if name == "" {
		w.WriteHeader(http.StatusNotFound)
		return
	}
	fname := name + ".map"
	f, err := fs.Open(filepath.Join(s.path, name, fname))
	if os.IsNotExist(err) {
		w.WriteHeader(http.StatusNotFound)
		return
	} else if err != nil {
		Log.Printf("error serving map %q: %v", name, err)
		w.WriteHeader(http.StatusInternalServerError)
		return
	}
	defer f.Close()
	fi, err := f.Stat()
	if err != nil {
		Log.Printf("error serving map %q: %v", name, err)
		w.WriteHeader(http.StatusInternalServerError)
		return
	}
	http.ServeContent(w, r, fname, fi.ModTime(), f)
}
