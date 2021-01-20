package main

/*
#cgo CFLAGS: -w -fshort-wchar -fno-strict-aliasing -fno-strict-overflow
#cgo linux LDFLAGS: -Wl,-unresolved-symbols=ignore-all
#cgo darwin LDFLAGS: -Wl,-undefined,dynamic_lookup
#cgo windows LDFLAGS: -lSDL2
#cgo linux freebsd darwin openbsd pkg-config: sdl2
#cgo CFLAGS: -DNOX_NO_MOUSE_GRAB

int WinMain(void* hInstance, void* hPrevInstance, char* lpCmdLine, int nShowCmd);
*/
import "C"
import (
	"os"
	"strings"
	"unsafe"

	_ "nox/client"
	_ "nox/common"
	_ "nox/comw32"
	_ "nox/server"

	_ "github.com/veandco/go-sdl2/sdl"
)

// Nox only works on 32bit
var _ = [1]struct{}{}[unsafe.Sizeof(int(0))-4]

func main() {
	cmdline := strings.Join(os.Args, " ")
	C.WinMain(nil, nil, C.CString(cmdline), 0)
}
