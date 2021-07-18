package env

import "os"

func IsDevMode() bool {
	return os.Getenv("NOX_DEV") == "true"
}
