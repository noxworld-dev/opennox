//go:build !safe
// +build !safe

package nox

// only import C, but do nothing; cgo_safe defines NOX_CGO_MEMMAP instead

import "C"
