package blobs

import (
	"bytes"
	"go/token"
	"io/ioutil"
	"log"
	"path/filepath"
	"time"
)

// RewriteAccess rewrite blob accesses in Path using provided function.
// The function must change a pointer value and return true if the change must be persisted.
func RewriteAccess(fnc func(a *Access) (bool, error)) error {
	var buf bytes.Buffer
	return EachFile(func(path string) error {
		buf.Reset()
		start := time.Now()
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
			if changed == 1 {
				log.Println("rewriting", path)
			}
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
				if changed > 0 {
					buf.Write(data)
					if err := ioutil.WriteFile(Path(path), buf.Bytes(), 0644); err != nil {
						return err
					}
					if dt := time.Since(start); dt > time.Second {
						log.Println("rewriting", path, ":", dt)
					}
				}
				return nil
			}
			if ext != ".go" {
				// write unaffected part, leave the rest
				si := fs.Position(sa.Expr.Pos[0])
				buf.Write(data[:si.Offset])
				data = data[si.Offset:]
			}
			// replace access and parse again; it's slow but correct
			data = bytes.Replace(data, []byte(old.Val), []byte(sa.String()), 1)
			changed++
		}
	})
}
