//go:build !safe

package opennox

// only import C, but do nothing; cgo_safe defines NOX_CGO_MEMMAP instead

import "C"
import "os"

var cgoSafe = os.Getenv("NOX_SAFE") == "true"
