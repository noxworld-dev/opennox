package legacy

// only import C, but do nothing; cgo_safe defines NOX_CGO_MEMMAP instead

import "os"

var cgoSafe = os.Getenv("NOX_SAFE") == "true"
