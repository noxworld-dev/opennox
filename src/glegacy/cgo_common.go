package legacy

/*
#cgo CFLAGS: -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo linux CFLAGS: -fstack-protector-strong

#cgo CFLAGS: -Werror=return-type
#cgo CFLAGS: -Werror=implicit-function-declaration
#cgo CFLAGS: -Werror=pointer-arith
#cgo CFLAGS: -Werror=implicit-int
#cgo CFLAGS: -Werror=unused-label
#cgo CFLAGS: -Werror=address
//#cgo CFLAGS: -Werror=unused-variable
//#cgo CFLAGS: -Werror=cast-function-type
#cgo CFLAGS: -Werror=stringop-overflow
//#cgo linux CFLAGS: -Werror=attribute-warning
#cgo linux CFLAGS: -Werror=uninitialized
//#cgo linux CFLAGS: -Werror=parentheses // FIXME: resolve issues related to this flag
//#cgo linux CFLAGS: -Werror=switch-outside-range

#cgo CFLAGS: -Wno-pointer-to-int-cast
#cgo CFLAGS: -Wno-int-to-pointer-cast
#cgo CFLAGS: -Wno-incompatible-pointer-types
#cgo CFLAGS: -Wno-int-conversion
#cgo CFLAGS: -Wno-format
#cgo CFLAGS: -Wno-shift-count-overflow
#cgo CFLAGS: -Wno-pedantic
#cgo CFLAGS: -Wno-bad-function-cast
#cgo CFLAGS: -Wno-strict-prototypes
#cgo CFLAGS: -Wno-discarded-qualifiers
#cgo CFLAGS: -Wno-return-local-addr
#cgo CFLAGS: -Wno-unused-result

#cgo windows LDFLAGS: -lws2_32
#cgo linux LDFLAGS: -lm
#cgo CFLAGS: -DNOX_CGO
*/
