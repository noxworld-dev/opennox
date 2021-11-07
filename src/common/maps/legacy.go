package maps

import (
	"os"
	"path/filepath"
	"strings"

	"nox/v1/common/datapath"
	"nox/v1/common/fs"
)

func NewNativeDownloader(dir string) *NativeDownloader {
	if dir == "" {
		dir = datapath.Maps()
	}
	d := &NativeDownloader{
		dir: dir,
	}
	d.Reset()
	return d
}

type mapDownloadPart struct {
	Ind  uint
	Data []byte
	Next *mapDownloadPart
	Prev *mapDownloadPart
}

type NativeDownloader struct {
	dir        string
	path       string
	downloadOK bool
	file       *os.File
	curPart    uint
	sizeCur    uint
	sizeTotal  uint
	first      *mapDownloadPart
	last       *mapDownloadPart
}

func (d *NativeDownloader) WritePart(ind uint, data []byte) {
	if len(data) == 0 {
		return
	}
	if ind == d.curPart {
		d.file.Write(data)
		d.sizeCur += uint(len(data))
		d.curPart++
	} else {
		buf := make([]byte, len(data))
		copy(buf, data)
		v3 := &mapDownloadPart{
			Ind:  ind,
			Data: buf,
			Prev: d.last,
		}
		if d.last != nil {
			d.last.Next = v3
		}
		d.last = v3
		if d.first == nil {
			d.first = v3
		}
	}

	// outer loop accounts for packet reordering
	for d.first != nil {
		found := false
		// in-order packets
		for it := d.first; it != nil; it = it.Next {
			if d.curPart != it.Ind {
				continue
			}
			found = true
			d.file.Write(it.Data)
			d.sizeCur += uint(len(it.Data))
			d.curPart++
			if v6 := it.Prev; v6 != nil {
				v6.Next = it.Next
			} else {
				d.first = it.Next
			}
			if v7 := it.Next; v7 != nil {
				v7.Prev = it.Prev
			} else {
				d.last = it.Prev
			}
			it.Data = nil
		}
		if !found {
			break
		}
	}
}

func (d *NativeDownloader) CancelAndCleanup() {
	if d.file != nil {
		d.file.Close()
	}
	mapDownloadCleanupDir(d.dir, d.path)
	d.Reset()
}

func (d *NativeDownloader) CancelAndDelete() {
	d.file.Close()
	fs.Remove(d.path)
	d.file = nil
	d.downloadOK = false
	d.curPart = 1
	d.sizeTotal = 0
	d.sizeCur = 0

	var v1 *mapDownloadPart
	for v0 := d.first; v0 != nil; v0 = v1 {
		v1 = v0.Next
		*v0 = mapDownloadPart{}
	}
	d.path = ""
	d.last = nil
	d.first = nil
}

func (d *NativeDownloader) DownloadOK() bool {
	return d.downloadOK
}

func (d *NativeDownloader) Complete() bool {
	return d.downloadOK && d.sizeCur >= d.sizeTotal
}

func (d *NativeDownloader) Progress() float64 {
	return float64(d.sizeCur) / float64(d.sizeTotal)
}

func (d *NativeDownloader) Reset() {
	if d.file != nil {
		d.file.Close()
	}
	d.file = nil
	d.downloadOK = false
	d.last = nil
	d.first = nil
	d.sizeTotal = 0
	d.sizeCur = 0
	d.curPart = 1
	d.path = ""
}

func (d *NativeDownloader) Start(path string, sz uint) error {
	d.Reset()
	path = fs.Normalize(path)
	mdir := filepath.Dir(path)
	ext := filepath.Ext(path)
	mname := strings.TrimSuffix(filepath.Base(path), ext)
	mapDownloadCleanupDir(d.dir, mname)
	if _, err := fs.Stat(mdir); os.IsNotExist(err) {
		fs.MkdirAll(mdir)
	}
	d.path = path
	f, err := fs.Create(d.path)
	if err != nil {
		return err
	}
	d.file = f
	d.curPart = 1
	d.downloadOK = true
	d.sizeTotal = sz
	return nil
}

func mapDownloadCleanupDir(ddir, path string) {
	if !strings.ContainsAny(path, "\\/") {
		ext := filepath.Ext(path)
		name := strings.TrimSuffix(path, ext)
		path = filepath.Join(ddir, path, name, path)
	}
	if _, err := os.Stat(path); err == nil {
		fs.Remove(path)
	}
}
