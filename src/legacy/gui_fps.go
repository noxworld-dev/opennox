package legacy

import "C"

var (
	Sub_470A80 func()
	Sub_4706C0 func(a1 int)
)

//export sub_470A80
func sub_470A80() { Sub_470A80() }

//export sub_4706C0
func sub_4706C0(a1 int) { Sub_4706C0(a1) }
