package blobs

import (
	"bytes"
	"go/token"
	"io/ioutil"
	"log"
	"path/filepath"
)

// RewriteAccess rewrite blob accesses in Path using provided function.
// The function must change a pointer value and return true if the change must be persisted.
func RewriteAccess(fnc func(a *Access) (bool, error)) error {
	return EachFile(func(path string) error {
		data, err := ReadFile(path)
		if err != nil {
			return err
		}
		ext := filepath.Ext(path)
		blobAccesses := BlobAccessesC
		if ext == ".go" {
			blobAccesses = BlobAccessesGo
		}
		changed := 0
		for {
			fs := token.NewFileSet()
			acc, err := blobAccesses(fs, path, data)
			if err != nil {
				return err
			}
			var (
				old StringPos
				sa  *Access
			)
			for _, a := range acc {
				old = a.Expr
				save, err := fnc(&a)
				if err != nil {
					return err
				} else if save {
					sa = &a
					break
				}
			}
			if sa == nil {
				if changed == 0 {
					return nil
				}
				log.Println("rewriting", path)
				return ioutil.WriteFile(Path(path), data, 0644)
			}
			// replace access and parse again; it's slow but correct
			data = bytes.Replace(data, []byte(old.Val), []byte(sa.String()), 1)
			changed++
		}
	})
}
