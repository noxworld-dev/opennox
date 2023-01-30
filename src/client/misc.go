package client

import "strings"

func firstWord(s string) string {
	if i := strings.IndexAny(s, " \t\n\r"); i > 0 {
		return s[:i]
	}
	return s
}
