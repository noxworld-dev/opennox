package opennox

/*

 */
import "C"

//export sub_445B40
func sub_445B40() C.int {
	sub_413A00(0)
	if sub4DB790("AUTOSAVE") {
		return 1
	}
	v2 := strMan.GetStringInFile("GUISave.c:SaveErrorTitle", "guiquit.c")
	v1 := strMan.GetStringInFile("GUISave.c:SaveErrorTitle", "guiquit.c")
	NewDialogWindow(nil, v1, v2, 33, nil, nil)
	return 1
}
