package main

var (
	Version = "v1.4.x"
	Commit  = "<dev>"
)

func ClientVersionString() string {
	return Version + " (" + Commit + ")"
}
