package memguard

import "syscall"

// PageSize returns a page size which allocations made by New will be aligned to.
func PageSize() int {
	return syscall.Getpagesize()
}

// New creates a memory region with a given size that is not allowed for the application to read or write.
// It can be useful for faking pointers passed to C and instead using those addresses as handles on Go side.
func New(size int) ([]byte, func()) {
	return newPage(size)
}
