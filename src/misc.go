package nox

func abs(v int) int {
	if v < 0 {
		return -v
	}
	return v
}

func bool2int(v bool) int {
	if v {
		return 1
	}
	return 0
}
