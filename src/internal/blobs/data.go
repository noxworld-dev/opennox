package blobs

import (
	"errors"
	"fmt"
	"io"
	"io/ioutil"
	"os"
)

func blobFile(blob uintptr) string {
	return Path(fmt.Sprintf("blob_%X.dat", blob))
}

// IsBlobZero check if blob contains zeros only.
func IsBlobZero(blob uintptr) bool {
	_, err := os.Stat(blobFile(blob))
	if os.IsNotExist(err) {
		return true
	}
	return false
}

// BlobRead reads certain blob region, given blob base and the offset.
func BlobRead(blob, off uintptr, p []byte) error {
	if IsBlobZero(blob) {
		copy(p, make([]byte, len(p)))
		return nil
	}
	f, err := os.Open(blobFile(blob))
	if err != nil {
		return err
	}
	defer f.Close()
	_, err = f.Seek(int64(off), io.SeekStart)
	if err != nil {
		return err
	}
	_, err = io.ReadFull(f, p)
	return err
}

func splitBlobData(blob, off, size uintptr) error {
	if IsBlobZero(blob) {
		return nil // nothing to do
	}
	data, err := ReadFile(blobFile(blob))
	if err != nil {
		return err
	}
	end := off + size
	if uintptr(len(data)) < end {
		return errors.New("blob too short for the split")
	}
	// we won't touch the original file, just write the second half
	if uintptr(len(data)) == end {
		return nil // nothing to write, actually
	}
	return ioutil.WriteFile(blobFile(blob+end), data[end:], 0644)
}
