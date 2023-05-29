package legacy

import (
	"errors"
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/internal/cryptfile"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	Nox_savegame_rm                      func(name string, rmDir bool) error
	Nox_client_countPlayerFiles04_4DC7D0 func() int
	Nox_xxx_gameGet_4DB1B0               func() bool
	Sub_4DCC90                           func() int
	Sub_4DB1C0                           func() unsafe.Pointer
	Sub_4DCBF0                           func(a1 int)
	Sub_4460A0                           func(a1 int)
	Nox_xxx_serverIsClosing_446180       func() int
	Sub_4DCC10                           func(a1p *server.Object) int
	Sub_4DCFB0                           func(a1p *server.Object)
	Sub_4DD0B0                           func(a1p *server.Object)
	Nox_setSaveFileName_4DB130           func(s string)
)

// nox_setSaveFileName_4DB130
func nox_setSaveFileName_4DB130(s *char) {
	Nox_setSaveFileName_4DB130(GoString(s))
}

// nox_savegame_rm_4DBE10
func nox_savegame_rm_4DBE10(cname *char, rmDir int) {
	if cname == nil {
		return
	}
	saveName := GoString(cname)
	Nox_savegame_rm(saveName, rmDir != 0)
}

// nox_client_countPlayerFiles04_4DC7D0
func nox_client_countPlayerFiles04_4DC7D0() int { return Nox_client_countPlayerFiles04_4DC7D0() }

// nox_xxx_gameGet_4DB1B0
func nox_xxx_gameGet_4DB1B0() int { return bool2int(Nox_xxx_gameGet_4DB1B0()) }

// sub_4DCC90
func sub_4DCC90() int { return Sub_4DCC90() }

// sub_4DB1C0
func sub_4DB1C0() unsafe.Pointer { return Sub_4DB1C0() }

// sub_4DCBF0
func sub_4DCBF0(a1 int) { Sub_4DCBF0(a1) }

// sub_4460A0
func sub_4460A0(a1 int) { Sub_4460A0(a1) }

// nox_xxx_serverIsClosing_446180
func nox_xxx_serverIsClosing_446180() int { return Nox_xxx_serverIsClosing_446180() }

// sub_4DCC10
func sub_4DCC10(a1p *nox_object_t) int { return Sub_4DCC10(asObjectS(a1p)) }

// sub_4DCFB0
func sub_4DCFB0(a1p *nox_object_t) { Sub_4DCFB0(asObjectS(a1p)) }

// sub_4DD0B0
func sub_4DD0B0(a1p *nox_object_t) { Sub_4DD0B0(asObjectS(a1p)) }
func Nox_xxx_destroyEveryChatMB_528D60() {
	nox_xxx_destroyEveryChatMB_528D60()
}
func Nox_xxx_quickBarClose_4606B0() {
	nox_xxx_quickBarClose_4606B0()
}
func Nox_xxx_monstersAllBelongToHost_4DB6A0() {
	nox_xxx_monstersAllBelongToHost_4DB6A0()
}
func Nox_xxx_mapSavePlayerDataMB_41A230(a1 string) bool {
	return nox_xxx_mapSavePlayerDataMB_41A230(internCStr(a1)) != 0
}
func Nox_xxx_mapSaveMap_51E010(a1 string, a2 int) bool {
	return nox_xxx_mapSaveMap_51E010(internCStr(a1), int(a2)) != 0
}

func Sub_41A590(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if sub_41A590(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}

func Sub_41AA30(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if sub_41AA30(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}

func Sub_41AC30(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if sub_41AC30(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}

func Nox_xxx_guiFieldbook_41B420(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if nox_xxx_guiFieldbook_41B420(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}

func Nox_xxx_guiSpellbook_41B660(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if nox_xxx_guiSpellbook_41B660(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}

func Nox_xxx_guiEnchantment_41B9C0(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if nox_xxx_guiEnchantment_41B9C0(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}

func Sub_41BEC0(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if sub_41BEC0(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}

func Sub_41C080(cf *cryptfile.CryptFile, u *server.Object, pinfo *server.PlayerInfo) error {
	old := cryptfile.Global()
	cryptfile.SetGlobal(cf)
	defer cryptfile.SetGlobal(old)
	if sub_41C080(u.CObj(), pinfo.C()) == 0 {
		return errors.New("failed")
	}
	return nil
}
