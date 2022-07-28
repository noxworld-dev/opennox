package opennox

/*
void nox_xxx_clientPlaySoundSpecial_452D80(int a1, int a2);
int nox_xxx_utilFindSound_40AF50(char* a1);
*/
import "C"
import (
	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func clientPlaySoundSpecial(snd sound.ID, a2 int) {
	C.nox_xxx_clientPlaySoundSpecial_452D80(C.int(snd), C.int(a2))
}

//export nox_xxx_utilFindSound_40AF50
func nox_xxx_utilFindSound_40AF50(name *C.char) C.int {
	return C.int(sound.ByName(GoString(name)))
}

//export nox_xxx_getSndName_40AF80
func nox_xxx_getSndName_40AF80(id C.int) *C.char {
	return internCStr(sound.ID(id).String())
}
