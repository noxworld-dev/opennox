package netstr

import (
	"errors"
	"fmt"
	"syscall"
)

func ErrIsInUse(err error) bool {
	return errors.Is(err, syscall.EADDRINUSE)
}

func NewConnectErr(code int, err error) *ConnectFailErr {
	if code == 0 {
		code = -1
	}
	return &ConnectFailErr{
		Err:  err,
		Code: code,
	}
}

type ConnectFailErr struct {
	Err  error
	Code int
}

func (e *ConnectFailErr) Error() string {
	return fmt.Sprintf("CONNECT_SERVER failed: %s (code=%d)", e.Err, e.Code)
}

func (e *ConnectFailErr) Unwrap() error {
	return e.Err
}
