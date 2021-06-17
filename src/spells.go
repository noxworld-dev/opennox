package main

/*
void nox_xxx_spellCastByBook_4FCB80();
void nox_xxx_spellCastByPlayer_4FEEF0();
*/
import "C"

func nox_xxx_spellBookReact_4FCB70() {
	C.nox_xxx_spellCastByBook_4FCB80()
	C.nox_xxx_spellCastByPlayer_4FEEF0()
}
