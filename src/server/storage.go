package server

import (
	"errors"
	"io/fs"
	"net/url"
	"os"
	"path/filepath"
	"sync"

	"github.com/noxworld-dev/opennox-lib/datapath"
)

func newStore(dir string) *storage {
	_ = os.MkdirAll(dir, 0755)
	return &storage{
		dir:     dir,
		temp:    make(map[string]*tempStorage),
		persist: make(map[string]*fileStorage),
	}
}

type storage struct {
	mu      sync.Mutex
	temp    map[string]*tempStorage
	persist map[string]*fileStorage
	dir     string
}

func (s *storage) Session(name string) Storage {
	if name == "" {
		name = "default"
	}
	s.mu.Lock()
	defer s.mu.Unlock()
	store := s.temp[name]
	if store == nil {
		store = &tempStorage{kv: make(map[string][]byte)}
		s.temp[name] = store
	}
	return store
}

func (s *storage) Persistent(name string) Storage {
	if name == "" {
		name = "default"
	}
	s.mu.Lock()
	defer s.mu.Unlock()
	store := s.persist[name]
	if store == nil {
		store = &fileStorage{
			dir:   filepath.Join(s.dir, escapeKey(name)),
			cache: make(map[string][]byte),
		}
		s.persist[name] = store
	}
	return store
}

type serverStorage struct {
	global *storage
	pmu    sync.Mutex
	player map[string]*storage
}

func (s *serverStorage) init() {
	s.global = newStore(datapath.Data("data", "global"))
	s.player = make(map[string]*storage)
}

func (s *serverStorage) playerKey(p *Player) string {
	return p.Serial() + "_" + p.OrigName()
}

func (s *serverStorage) forPlayer(p *Player) *storage {
	s.pmu.Lock()
	defer s.pmu.Unlock()
	key := s.playerKey(p)
	store := s.player[key]
	if store == nil {
		store = newStore(datapath.Data("data", "player", key))
		s.player[key] = store
	}
	return store
}

type Storage interface {
	Get(key string) ([]byte, error)
	Set(key string, data []byte) error
}

type tempStorage struct {
	mu sync.RWMutex
	kv map[string][]byte
}

func (t *tempStorage) Get(key string) ([]byte, error) {
	t.mu.RLock()
	defer t.mu.RUnlock()
	val := t.kv[key]
	if len(val) == 0 {
		return nil, nil
	}
	return append([]byte{}, val...), nil
}

func (t *tempStorage) Set(key string, val []byte) error {
	t.mu.Lock()
	defer t.mu.Unlock()
	if len(val) == 0 {
		delete(t.kv, key)
	} else {
		t.kv[key] = append([]byte{}, val...)
	}
	return nil
}

type fileStorage struct {
	dir   string
	mu    sync.RWMutex
	cache map[string][]byte
}

func (t *fileStorage) keyPath(key string) string {
	return filepath.Join(t.dir, escapeKey(key)+".json")
}

func (t *fileStorage) Get(key string) ([]byte, error) {
	t.mu.RLock()
	val, ok := t.cache[key]
	t.mu.RUnlock()
	if ok {
		if len(val) == 0 {
			return nil, nil
		}
		return append([]byte{}, val...), nil
	}
	t.mu.Lock()
	defer t.mu.Unlock()
	val, ok = t.cache[key]
	if ok {
		if len(val) == 0 {
			return nil, nil
		}
		return append([]byte{}, val...), nil
	}
	val, err := os.ReadFile(t.keyPath(key))
	if errors.Is(err, fs.ErrNotExist) {
		err = nil
	} else if err != nil {
		return nil, err
	}
	t.cache[key] = val
	if len(val) == 0 {
		return nil, nil
	}
	return append([]byte{}, val...), nil
}

func (t *fileStorage) Set(key string, val []byte) error {
	t.mu.Lock()
	defer t.mu.Unlock()
	t.cache[key] = append([]byte{}, val...)
	path := t.keyPath(key)
	if err := os.MkdirAll(filepath.Dir(path), 0755); err != nil {
		return err
	}
	return os.WriteFile(path, val, 0644)
}

func escapeKey(key string) string {
	return url.PathEscape(key)
}

func (s *serverStorage) Session(name string) Storage {
	return s.global.Session(name)
}

func (s *serverStorage) Persistent(name string) Storage {
	return s.global.Persistent(name)
}

func (s *serverStorage) PlayerSession(p *Player, name string) Storage {
	return s.forPlayer(p).Session(name)
}

func (s *serverStorage) PlayerPersistent(p *Player, name string) Storage {
	return s.forPlayer(p).Persistent(name)
}
