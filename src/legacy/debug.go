package legacy

/*
unsigned int sub_4D42E0(const char* a1);
*/
import "C"

var (
	Sub_57C490_2 func(key string)
)

//export sub_57C490_2
func sub_57C490_2(a1 *C.char) {
	Sub_57C490_2(GoString(a1))
}

func Sub_4D42E0(s string) {
	C.sub_4D42E0(internCStr(s))
}
