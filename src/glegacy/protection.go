package legacy

/*
extern unsigned int dword_5d4594_2516356;
int nox_xxx_protectionCreateStructForInt_56F280(int a1, int a2);
int nox_xxx_protectionCreateStructForFloat_56F480(int a1, float a2);
*/

func Nox_xxx_protectionCreateStructForInt_56F280(a1 int, a2 int) int {
	return int(nox_xxx_protectionCreateStructForInt_56F280(int(a1), int(a2)))
}
func Nox_xxx_protectionCreateStructForFloat_56F480(a1 int, a2 float32) int {
	return int(nox_xxx_protectionCreateStructForFloat_56F480(int(a1), float32(a2)))
}
