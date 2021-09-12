package noxscript

import (
	"fmt"
)

var (
	_ error = &ErrNoFunc{}
	_ error = &Error{}
)

type ErrNoFunc struct {
	Func string
}

func (e *ErrNoFunc) Error() string {
	return fmt.Sprintf("noxscript: undefined function: %q", e.Func)
}

type Error struct {
	Func string
	Err  error
}

func (e *Error) Error() string {
	if e.Func == "" {
		return fmt.Errorf("noxscript: %w", e.Err).Error()
	}
	return fmt.Errorf("noxscript: %s: %w", e.Func, e.Err).Error()
}

func (e *Error) Unwrap() error {
	return e.Err
}
