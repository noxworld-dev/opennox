package main

import "bytes"

func indexToken(data []byte, start, end byte) int {
	cnt := 1
	for i, b := range data {
		switch b {
		case start:
			cnt++
		case end:
			cnt--
			if cnt == 0 {
				return i
			}
		}
	}
	return -1
}

func indexTokenAll(data []byte, token byte) int {
	bcnt := 0
	scnt := 0
	for i, b := range data {
		switch b {
		case '(':
			bcnt++
		case '[':
			scnt++
		case ')':
			if bcnt == 0 {
				return -1
			}
			bcnt--
		case ']':
			if scnt == 0 {
				return -1
			}
			scnt--
		}
		if scnt == 0 && bcnt == 0 {
			if b == token {
				return i
			}
			continue
		}
	}
	return -1
}

func splitToken(data []byte, token byte) [][]byte {
	var out [][]byte
	for {
		i := indexTokenAll(data, token)
		if i < 0 {
			if len(data) > 0 {
				out = append(out, data)
			}
			return out
		}
		out = append(out, data[:i])
		data = data[i+1:]
	}
}

func unbrace(data []byte) []byte {
	data = bytes.TrimSpace(data)
	if len(data) == 0 {
		return nil
	}
	if data[0] != '(' {
		return data
	}
	i := indexToken(data[1:], '(', ')')
	if i < 0 {
		return data
	}
	i++
	if i != len(data)-1 {
		return data
	}
	return unbrace(data[1:i])
}
