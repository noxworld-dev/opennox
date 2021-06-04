package maps

import (
	"archive/zip"
	"context"
	"errors"
	"fmt"
	"io"
	"net/http"
	"os"
	"path/filepath"
	"strings"
	"time"

	"nox/v1/common"
	"nox/v1/common/fs"
)

const (
	DefaultPort      = common.GameHTTPPort
	mapFileSizeLimit = 30 * 1024 * 1024 // 30 MB
)

var (
	ErrAPIUnsupported = errors.New("map API not supported")
	ErrNotFound       = errors.New("map not found")
)

type Client struct {
	cli  *http.Client
	base string
}

func NewClient(ctx context.Context, addr string) (*Client, error) {
	if addr == "" {
		return nil, errors.New("no address")
	}
	if !strings.Contains(addr, ":") {
		addr = fmt.Sprintf("%s:%d", addr, DefaultPort)
	}
	url := fmt.Sprintf("http://%s", addr)
	cli := &Client{cli: http.DefaultClient, base: url}
	ctx, cancel := context.WithTimeout(ctx, 2*time.Second)
	defer cancel()
	err := cli.checkAPI(ctx)
	if err != nil {
		return nil, err
	}
	return cli, nil
}

func (c *Client) Close() error {
	return nil
}

func (c *Client) checkAPI(ctx context.Context) error {
	req, err := http.NewRequestWithContext(ctx, "HEAD", c.base+"/api/v0/maps", nil)
	if err != nil {
		return err
	}
	resp, err := c.cli.Do(req)
	if err != nil {
		return err
	}
	defer resp.Body.Close()
	if resp.StatusCode != http.StatusOK {
		return ErrAPIUnsupported
	}
	return nil
}

// limitReader returns a Reader that reads from r but stops with an error after n bytes.
func limitReader(r io.Reader, n int64) io.Reader { return &limitedReader{r, n} }

// A limitedReader reads from R but limits the amount of data returned to just N bytes.
// Each call to Read updates N to reflect the new amount remaining.
// Read returns error when N <= 0. It returns EOF when the underlying R returns EOF.
type limitedReader struct {
	R io.Reader // underlying reader
	N int64     // max bytes remaining
}

func (l *limitedReader) Read(p []byte) (n int, err error) {
	if l.N <= 0 {
		return 0, errors.New("file download limit reached")
	}
	if int64(len(p)) > l.N {
		p = p[0:l.N]
	}
	n, err = l.R.Read(p)
	l.N -= int64(n)
	return
}

// DownloadMap with a given name to dest.
func (c *Client) DownloadMap(ctx context.Context, dest string, name string) error {
	name = strings.TrimSuffix(strings.ToLower(name), Ext)
	url := c.base + "/api/v0/maps/" + name + "/download"
	Log.Println("GET", url)
	req, err := http.NewRequestWithContext(ctx, "GET", url, nil)
	if err != nil {
		return err
	}
	req.Header.Set("Accept", contentTypeZIP+", */*;q=0.8")
	resp, err := c.cli.Do(req)
	if err != nil {
		return err
	}
	defer resp.Body.Close()

	switch resp.StatusCode {
	case http.StatusNotImplemented:
		return ErrAPIUnsupported
	case http.StatusNotFound:
		return ErrNotFound
	default:
		return fmt.Errorf("status: %s", resp.Status)
	case http.StatusOK:
	}
	dest = filepath.Join(dest, name)
	if err := fs.Mkdir(dest); err != nil {
		return err
	}
	r := limitReader(resp.Body, mapFileSizeLimit)
	switch resp.Header.Get("Content-Type") {
	case contentTypeZIP:
		// maps compressed with ZIP
		tmp, err := os.CreateTemp("", "nox_map_*.zip")
		if err != nil {
			return err
		}
		defer func() {
			_ = tmp.Close()
			_ = os.Remove(tmp.Name())
		}()
		sz, err := io.Copy(tmp, r)
		if err != nil {
			return err
		}
		_, err = tmp.Seek(0, io.SeekStart)
		if err != nil {
			return err
		}
		Log.Println("unpacking map zip archive:", tmp.Name())
		zf, err := zip.NewReader(tmp, sz)
		if err != nil {
			return err
		}
		for _, f := range zf.File {
			path := strings.ToLower(f.Name)
			if !IsAllowedFile(path) {
				Log.Println("skipping disallowed file", path)
				continue
			}
			path = filepath.Join(dest, path)
			if err := fs.Mkdir(filepath.Dir(path)); err != nil {
				return err
			}
			err := func() error {
				w, err := fs.Create(path)
				if err != nil {
					return err
				}
				defer w.Close()

				r, err := zf.Open(f.Name)
				if err != nil {
					return err
				}
				defer r.Close()

				_, err = io.Copy(w, r)
				if err != nil {
					return err
				}
				return w.Close()
			}()
			if err != nil {
				return err
			}
		}
		return nil
	default:
		// regular map files served directly
		f, err := fs.Create(filepath.Join(dest, name+Ext))
		if err != nil {
			return err
		}
		defer f.Close()
		_, err = io.Copy(f, r)
		if err != nil {
			return err
		}
		return f.Close()
	}
}
