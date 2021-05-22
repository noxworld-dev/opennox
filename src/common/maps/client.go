package maps

import (
	"context"
	"errors"
	"fmt"
	"io"
	"net/http"
	"path/filepath"
	"strings"
	"time"

	"nox/v1/common"
	"nox/v1/common/fs"
)

const (
	DefaultPort = common.GameHTTPPort
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

// DownloadMap with a given name to dest.
func (c *Client) DownloadMap(ctx context.Context, dest string, name string) error {
	name = strings.TrimSuffix(strings.ToLower(name), Ext)
	url := c.base + "/api/v0/maps/" + name + "/download"
	Log.Println("GET", url)
	req, err := http.NewRequestWithContext(ctx, "GET", url, nil)
	if err != nil {
		return err
	}
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
	f, err := fs.Create(filepath.Join(dest, name+Ext))
	if err != nil {
		return err
	}
	defer f.Close()
	_, err = io.Copy(f, resp.Body)
	if err != nil {
		return err
	}
	err = f.Close()
	if err != nil {
		return err
	}
	return nil
}
