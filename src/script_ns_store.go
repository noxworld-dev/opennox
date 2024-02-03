package opennox

import (
	"encoding/json"
	"errors"

	"github.com/noxworld-dev/noxscript/ns/v4"

	"github.com/noxworld-dev/opennox/v1/server"
)

type nsStorage struct {
	s     *Server
	store server.Storage
}

func (s nsStorage) Get(key string, obj any) error {
	data, err := s.store.Get(key)
	if err != nil {
		return err
	} else if len(data) == 0 {
		return errors.New("not found")
	}
	return json.Unmarshal(data, obj)
}

func (s nsStorage) Set(key string, obj any) error {
	data, err := json.Marshal(obj)
	if err != nil {
		return err
	}
	return s.store.Set(key, data)
}

func (s noxScriptNS) toStorage(store server.Storage) ns.Storage {
	return nsStorage{s: s.s, store: store}
}

func (s noxScriptNS) Store(typ ns.StorageType) ns.Storage {
	switch typ := typ.(type) {
	case ns.Session:
		return s.toStorage(s.s.Storage.Session(typ.Name))
	case ns.Persistent:
		return s.toStorage(s.s.Storage.Persistent(typ.Name))
	}
	return s.toStorage(s.s.Storage.Session("default"))
}

func (p nsPlayer) Store(typ ns.StorageType) ns.Storage {
	s := p.s.noxScriptP()
	switch typ := typ.(type) {
	case ns.Session:
		return s.toStorage(s.s.Storage.PlayerSession(p.p, typ.Name))
	case ns.Persistent:
		return s.toStorage(s.s.Storage.PlayerPersistent(p.p, typ.Name))
	}
	return s.toStorage(s.s.Storage.PlayerSession(p.p, "default"))
}
