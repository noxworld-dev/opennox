package opennox

/*
void nox_xxx_clientPlaySoundSpecial_452D80(int a1, int a2);
*/
import "C"

func clientPlaySoundSpecial(a1, a2 int) {
	C.nox_xxx_clientPlaySoundSpecial_452D80(C.int(a1), C.int(a2))
}
