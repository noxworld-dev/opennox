package opennox

import (
	"os"
	"path/filepath"
	"strings"
	"unsafe"

	crypt "github.com/noxworld-dev/noxcrypt"
	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/console"
	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/internal/binfile"
	"github.com/noxworld-dev/opennox/v1/internal/netstr"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/server"
)

var (
	dword_5d4594_1563044           = false
	dword_5d4594_1563064           = false
	dword_5d4594_1563048           = false
	dword_5d4594_825756            = false
	nox_xxx_serverIsClosing_825764 = false
	dword_5d4594_1563080           = 0
	dword_5d4594_1563084           unsafe.Pointer
	dword_5d4594_825752            = 0
	dword_5d4594_1563092           uint32
	dword_5d4594_825768            uint32
	dword_5d4594_1563088           uint32
	dword_5d4594_1559960           string
)

func nox_xxx_playerSaveToFile_41A140(path string, ind ntype.PlayerInd) bool {
	return legacy.Nox_xxx_playerSaveToFile_41A140(path, ind) != 0
}

func sub4DB790(a1 string) bool {
	legacy.Nox_xxx_mapLoadOrSaveMB_4DCC70(1)
	noxflags.SetGame(noxflags.GameFlag28)
	noxAudioServeT(500)
	res := nox_xxx_soloLoadGame_4DB7E0_savegame(a1)
	noxAudioServe()
	noxflags.UnsetGame(noxflags.GameFlag28)
	*memmap.PtrUint32(0x5D4594, 1563068) = noxServer.Frame()
	return res
}

func nox_client_makeSaveDir(name string) (string, error) {
	dir := datapath.Save(name)
	err := ifs.Mkdir(dir)
	return dir, err
}

func nox_savegame_rm(name string, rmdir bool) error {
	if name == "" {
		return nil
	}
	saveDir := datapath.Save(name)
	if err := ifs.RemoveAll(saveDir); err != nil {
		return err
	}
	// TODO: this should actually only remove the player file and map dirs; we just remove the whole dir instead
	//       implement it properly later, if it makes any difference
	if !rmdir {
		if err := ifs.Mkdir(saveDir); err != nil {
			return err
		}
	}
	return nil
}

func nox_client_copySave(from, to string) error {
	fromDir := datapath.Save(from)
	if err := nox_savegame_rm(to, true); err != nil {
		return err
	}
	toDir, err := nox_client_makeSaveDir(to)
	if err != nil {
		return err
	}
	// TODO: this should actually only copy the player file and map dirs; we just copy the whole dir instead
	//       implement it properly later, if it makes any difference
	return ifs.CopyDir(fromDir, toDir)
}

func nox_client_checkSaveMapExistsTmp(name string) (string, error) {
	name = strings.ToLower(name)
	if i := strings.IndexByte(name, ':'); i > 0 {
		name = name[:i]
	}
	dir := strings.TrimSuffix(name, ".map")
	fname := datapath.Save(common.SaveTmp, dir, name)
	if _, err := ifs.Stat(fname); err != nil {
		return "", err
	}
	return fname, nil
}

func nox_client_countPlayerFiles04_4DC7D0() int {
	cnt, err := nox_client_countPlayerFiles(0x4)
	if err != nil {
		gameLog.Println("count player files:", err)
		return 0
	}
	return cnt
}

func nox_client_countPlayerFiles(flag byte) (int, error) {
	dir := datapath.Save()
	list, err := ifs.ReadDir(dir)
	if os.IsNotExist(err) {
		return 0, nil
	} else if err != nil {
		return 0, err
	}
	cnt := 0
	for _, fi := range list {
		if fi.IsDir() {
			continue
		}
		if strings.ToLower(filepath.Ext(fi.Name())) != ".plr" {
			continue
		}
		fname := filepath.Join(dir, fi.Name())
		if sub_41A000_check0(fname)&flag != 0 {
			cnt++
		}
	}
	return cnt, nil
}

func sub_41A000_check0(path string) byte {
	path = ifs.Denormalize(path)
	save, freeSave := alloc.Make([]byte{}, 1280)
	defer freeSave()
	legacy.Sub_41A000(path, (*legacy.Nox_savegame_xxx)(unsafe.Pointer(&save[0])))
	return save[0]
}

func nox_xxx_savePlayerMB_41C8F0(data []byte) int {
	path := getString10984()
	const expSize = 216 // TODO: limit was *getMemIntPtr(0x587000, 55984) == 700, see #304
	if !noxflags.HasGame(noxflags.GameHost) && len(data) < expSize {
		str := strMan.GetStringInFile("Wol.c:WolApierror", "XferPlyr.c")
		noxConsole.Print(console.ColorBlue, str)
		str2 := strMan.GetStringInFile("Wol.c:Wolapierror", "XferPlyr.c")
		nox_xxx_printCentered_445490(str2)
		saveLog.Printf("SavePlayerOnClient: Error - character file too small %q (%d vs %d)\n", path, len(data), expSize)
		return 0
	}

	ifs.MkdirAll(datapath.Save())

	f, err := binfile.BinfileOpen(path, binfile.WriteOnly)
	if err != nil {
		saveLog.Printf("SavePlayerOnClient: Unable to open file %q\n", path)
		return 0
	}
	if err := f.SetKey(crypt.SaveKey); err != nil {
		_ = f.Close()
		saveLog.Printf("SavePlayerOnClient: Unable to key file %q: %v\n", path, err)
		return 0
	}
	if len(data) != 0 {
		f.Write(data)
	}
	f.Close()

	if noxflags.HasGame(noxflags.GameModeQuest) {
		*memmap.PtrUint8(0x85B3FC, 12257) = byte(legacy.Get_dword_5d4594_1049844())
	} else {
		*memmap.PtrUint8(0x85B3FC, 12257) = 0
	}
	if legacy.Nox_xxx_mapSavePlayerDataMB_41A230(path) == 0 {
		networkLogPrint("SavePlayerOnClient: Unable to save client data to file\n")
		return 0
	}
	str := strMan.GetStringInFile("CharacterSaved", "XferPlyr.c")
	noxConsole.Print(console.ColorBlue, str)
	str2 := strMan.GetStringInFile("CharacterSaved", "XferPlyr.c")
	nox_xxx_printCentered_445490(str2)
	return 1
}

func sub_4DB100() {
	dword_5d4594_1563080 = 0
	dword_5d4594_1563084 = nil
	legacy.Set_dword_5d4594_1563096(0)
	dword_5d4594_1563064 = false
	dword_5d4594_1563092 = 0
	dword_5d4594_1563088 = 0
	*memmap.PtrUint32(0x5D4594, 1563072) = 0
	*memmap.PtrUint32(0x5D4594, 1563068) = 0
}

func nox_xxx_gameGet_4DB1B0() int {
	return dword_5d4594_1563080
}

func sub_4DCC90() int {
	v := 1
	if dword_5d4594_1563080 != 1 {
		v = bool2int(dword_5d4594_1563092 != 0)
	}
	return v
}

func sub_4DB1C0() unsafe.Pointer {
	return dword_5d4594_1563084
}

func sub_4DCBF0(a1 int) {
	dword_5d4594_1563064 = a1 != 0
}

func sub_446060() {
	dword_5d4594_825768 = 0
}

func sub_446030() bool {
	return dword_5d4594_825768 != 0
}

func sub_446090() bool {
	return dword_5d4594_825752 == 0
}

func sub_4460B0() bool {
	return dword_5d4594_825756
}

func sub_4460A0(a1 int) {
	dword_5d4594_825756 = a1 != 0
}

func serverQuitAck() {
	dword_5d4594_825752--
	if dword_5d4594_825752 == 0 {
		sub_446380()
	}
}

func sub_40BBC0(ind netstr.Handle, a2 byte) {
	if a2 == 2 {
		if sub_446030() {
			serverQuitAck()
			if sub_446090() {
				nox_game_exit_xxx2()
				sub_446060()
			}
		}
	} else if a2 == 3 {
		nox_game_exit_xxx2()
	}
}

func sub_40B850(ind netstr.Handle, act byte) {
	if act == 2 && sub_446030() {
		serverQuitAck()
		if sub_446090() {
			nox_game_exit_xxx2()
			sub_446060()
		}
	}
}

func sub_40B810(act byte, data []byte) {
	nox_xxx_soloGameEscMenuCallback_40AF90(common.MaxPlayers-1, 0, act, memmap.String(0x5D4594, 4664), data)
	sub_40B850(netstr.Global.First(), act)
}

func nox_xxx_serverIsClosing_446180() int {
	return bool2int(nox_xxx_serverIsClosing_825764)
}

func nox_xxx_serverIsClosing446180() bool {
	return nox_xxx_serverIsClosing_825764
}

func sub_446140() {
	nox_xxx_serverIsClosing_825764 = true
	if noxflags.HasGame(noxflags.GameModeQuest) {
		if noxflags.HasGame(noxflags.GameHost) {
			sub_4D6B10(false)
		}
	}
}

func sub_4DCE30() {
	if !dword_5d4594_1563048 {
		sub_4169F0()
	}
	sub_446140()
}

func sub_419F00() bool {
	return *memmap.PtrUint32(0x5D4594, 527716) != 0
}

func sub_419EB0(i ntype.PlayerInd, val int) {
	if val == 1 {
		*memmap.PtrUint32(0x5D4594, 527716) |= 1 << i
	} else {
		*memmap.PtrUint32(0x5D4594, 527716) &^= 1 << i
	}
}

func sub_419EE0(a1 ntype.PlayerInd) bool {
	return (*memmap.PtrUint32(0x5D4594, 527716) & (1 << a1)) != 0
}

func sub_4DCC10(a1p *server.Object) int {
	u := asObjectS(a1p)
	v := true
	if dword_5d4594_1563092 != 0 && dword_5d4594_1563092+dword_5d4594_1563088 > u.getServer().Frame() {
		v = false
	}
	if *(*uint32)(unsafe.Add(u.UpdateData, 284)) != 0 { // TODO: which type is expected here?
		v = false
	}
	if u.Flags().Has(object.FlagNoUpdate) {
		v = false
	}
	if u.Flags().Has(object.FlagDead) {
		v = false
	}
	if legacy.Sub_45D9B0() == 1 {
		return 0
	}
	return bool2int(v)
}

func sub_4DCE00() {
	if dword_5d4594_1563044 {
		if !sub_419F00() {
			sub_4DCE30()
			dword_5d4594_1563044 = false
		}
	}
}

func sub_446520(i int, data []byte) {
	if len(data) != 0 {
		buf, _ := alloc.Make([]byte{}, len(data))
		copy(buf, data)
		*memmap.PtrPtr(0x5D4594, 826056+4*uintptr(i)) = unsafe.Pointer(&buf[0])
		*memmap.PtrUint32(0x5D4594, 826048+4*uintptr(i)) = uint32(len(buf))
		*memmap.PtrUint32(0x5D4594, 826064+4*uintptr(i)) = 1
	}
}

func sub_446580(i int) {
	if memmap.Uint32(0x5D4594, 826056+4*uintptr(i)) != 0 {
		alloc.FreePtr(*memmap.PtrPtr(0x5D4594, 826056+4*uintptr(i)))
		*memmap.PtrUint32(0x5D4594, 826056+4*uintptr(i)) = 0
		*memmap.PtrUint32(0x5D4594, 826048+4*uintptr(i)) = 0
		*memmap.PtrUint32(0x5D4594, 826064+4*uintptr(i)) = 0
	}
}

func nox_xxx_soloGameEscMenuCallback_40AF90(ind ntype.PlayerInd, a2 byte, act byte, a4 string, data []byte) {
	switch act {
	case 1:
		sub_446520(1, data)
	case 2:
		nox_xxx_savePlayerMB_41C8F0(data)
		if noxflags.HasGame(noxflags.GameModeQuest) {
			if sub_4460B0() {
				sub_446140()
			} else {
				netSendGauntlet()
			}
		} else if sub_446030() && sub_446090() {
			nox_game_exit_xxx2()
			sub_446060()
		}
	case 3:
		path := datapath.Save("_temp_.dat")
		if nox_xxx_SavePlayerDataFromClient_41CD70(path, data) {
			if noxServer.nox_xxx_isQuest_4D6F50() && ind == common.MaxPlayers-1 {
				sub4DCEE0(path)
			} else {
				res := legacy.Nox_xxx_cliPlrInfoLoadFromFile_41A2E0(path, ind)
				if noxflags.HasGame(noxflags.GameModeQuest) {
					if res != 0 {
						if pl := noxServer.GetPlayerByInd(ind); pl != nil {
							if u := pl.UnitC(); u != nil {
								ud := u.UpdateDataPlayer()
								ud.Field138 = 0
							}
						}
					} else {
						noxServer.GetPlayerByInd(ind).Disconnect(4)
					}
				}
				ifs.Remove(path)
			}
		} else if noxflags.HasGame(noxflags.GameModeQuest) && ind != common.MaxPlayers-1 {
			nox_xxx_playerCallDisconnect_4DEAB0(ind, 4)
		}
	}
}

func nox_xxx_SavePlayerDataFromClient_41CD70(path string, data []byte) bool {
	f, err := binfile.BinfileOpen(path, binfile.WriteOnly)
	if err != nil {
		saveLog.Printf("SavePlayerDataFromClient: Can't open file %q: %v\n", path, err)
		return false
	}
	defer f.Close()
	if err := f.SetKey(crypt.SaveKey); err != nil {
		saveLog.Printf("SavePlayerDataFromClient: Can't key file %q: %v\n", path, err)
		return false
	}
	if len(data) != 0 {
		f.Write(data)
	}
	return true
}

func sub_4DB9C0() {
	s := noxServer
	var next *server.Object
	for it := s.FirstServerObject(); it != nil; it = next {
		next = it.Next()
		if legacy.Nox_xxx_isUnit_4E5B50(it.SObj()) != 0 {
			asObjectS(it).Delete()
		}
	}
	next = nil
	for it := s.Objs.UpdatableList2; it != nil; it = next {
		next = it.Next()
		if legacy.Sub_4E5B80(it.SObj()) != 0 {
			asObjectS(it).Delete()
		}
	}
}

func sub_4738D0() int {
	legacy.Nox_xxx_bookHideMB_45ACA0(1)
	return 1
}

func nox_xxx_soloLoadGame_4DB7E0_savegame(a1 string) bool {
	if a1 == "" {
		return false
	}
	if noxflags.HasGame(noxflags.GameClient) && sub_4738D0() == 0 {
		return false
	}
	sub_4DB9C0()
	if a1 != common.SaveTmp && nox_client_copySave(a1, common.SaveTmp) != nil {
		return false
	}
	path := datapath.Save(common.SaveTmp, common.PlayerFile)
	if _, err := ifs.Stat(path); os.IsNotExist(err) {
		str := strMan.GetStringInFile("AutoSaveNotFound", "SaveGame.c")
		legacy.PrintToPlayers(str)
		return false
	}
	v5, _ := sub41D090(path)
	noxServer.SetFirstObjectScriptID(server.ObjectScriptID(v5))
	noxServer.ResetObjectScriptIDs()
	nox_xxx_gameSetSwitchSolo_4DB220(1)
	nox_xxx_gameSetNoMPFlag_4DB230(1)
	if legacy.Nox_xxx_cliPlrInfoLoadFromFile_41A2E0(path, common.MaxPlayers-1) == 0 {
		return false
	}
	legacy.Nox_xxx_cliPrepareGameplay1_460E60()
	legacy.Nox_xxx_cliPrepareGameplay2_4721D0()
	pl := noxServer.GetPlayerByInd(common.MaxPlayers - 1)
	pl.Name()
	mname := pl.SaveName()
	noxServer.nox_xxx_gameSetMapPath_409D70(mname + ".map")
	dword_5d4594_1559960 = datapath.Save(common.SaveTmp, mname, mname+".map")
	noxServer.SwitchMap(mname + ".map")
	nox_xxx_cliPlayMapIntro_44E0B0(0)
	if legacy.Nox_xxx_plrLoad_41A480(path) == 0 {
		return false
	}
	guiCon.Clear()
	legacy.Sub_445450()
	legacy.Nox_xxx_destroyEveryChatMB_528D60()
	str := strMan.GetStringInFile("GameLoaded", "C:\\NoxPost\\src\\Server\\Xfer\\SaveGame\\SaveGame.c")
	legacy.PrintToPlayers(str)
	return true
}

func nox_xxx_gameSetSoloSavePath_4DB270(a1 string) {
	dword_5d4594_1559960 = a1
}

func sub_4DCD40() {
	dword_5d4594_1563048 = sub_416A00()
	sub_4169E0()
	dword_5d4594_1563044 = true
	path := datapath.Save("_temp_.dat")
	for _, u := range noxServer.getPlayerUnits() {
		ud := u.UpdateDataPlayer()
		pl := asPlayerS(ud.Player)
		if pl.Field4792 != 0 && ud.Field138 != 1 {
			if nox_xxx_playerSaveToFile_41A140(path, pl.PlayerIndex()) {
				sub41CFA0(path, pl.PlayerIndex())
			}
			ifs.Remove(path)
		}
	}
}

func sub_4DCFB0(a1p *server.Object) {
	u := asObjectS(a1p)
	if u == nil {
		return
	}
	ud := u.UpdateDataPlayer()
	pl := asPlayerS(ud.Player)
	if pl.Index() == common.MaxPlayers-1 {
		return
	}
	if pl.Field4792 != 0 && ud.Field138 != 1 {
		if sub_419EE0(pl.PlayerIndex()) {
			nox_xxx_player_4D7960(pl.Index())
			return
		}
		FileName := datapath.Save("_temp_.dat")
		v2 := true
		if nox_xxx_playerSaveToFile_41A140(FileName, pl.PlayerIndex()) {
			v2 = sub41CFA0(FileName, pl.PlayerIndex())
		}
		ifs.Remove(FileName)
		if v2 {
			nox_xxx_player_4D7960(pl.Index())
		}
	} else {
		noxServer.GetPlayerByInd(pl.PlayerIndex()).Disconnect(4)
	}
}

func nox_xxx_player_4D7960(a1 int) {
	*memmap.PtrUint32(0x5D4594, 1556300) |= 1 << a1
}

func sub41CFA0(a1 string, a2 ntype.PlayerInd) bool {
	if sub_419EE0(a2) {
		return false
	}
	sz := legacy.Nox_xxx_computeServerPlayerDataBufferSize_41CC50(a1)
	if sz == 0 {
		return false
	}
	f, err := binfile.BinfileOpen(a1, binfile.ReadOnly)
	if err != nil {
		saveLog.Printf("SendPlayerSaveDataToClient: Can't open file %q: %v\n", a1, err)
		return false

	}
	defer f.Close()
	if err := f.SetKey(crypt.SaveKey); err != nil {
		saveLog.Printf("SavePlayerOnClient: Unable to key file %q: %v\n", a1, err)
		return false
	}
	buf, free := alloc.Make([]byte{}, sz)
	defer free()

	f.Read(buf)
	sub_419EB0(a2, 1)
	sub_40BC60(a2, 2, "SAVEDATA", buf, true)
	return true
}

func sub_4DD0B0(a1p *server.Object) {
	u := asObjectS(a1p)
	if u == nil {
		return
	}
	pl := u.ControllingPlayer()
	if nox_xxx_player_4D7980(pl.Index()) {
		noxServer.GetPlayerByInd(pl.PlayerIndex()).Disconnect(4)
	} else {
		sub_419EB0(pl.PlayerIndex(), 0)
		nox_xxx_sendGauntlet_4DCF80(pl.PlayerIndex(), 0)
	}
}

func nox_xxx_player_4D7980(a1 int) bool {
	return (*memmap.PtrUint32(0x5D4594, 1556300) & (1 << a1)) != 0
}

func sub_450750() byte {
	return memmap.Uint8(0x5D4594, 831252)
}

func nox_xxx_saveDoAutosaveMB_4DB370_savegame(name string) int {
	sub_478000()
	legacy.Nox_xxx_quickBarClose_4606B0()
	pl := noxServer.GetPlayerByInd(common.MaxPlayers - 1)
	if pl == nil {
		return 0
	}
	u := pl.UnitC()
	if u == nil {
		return 0
	}
	if name == "" {
		return 0
	}
	if u.Flags().Has(object.FlagDead) {
		return 0
	}
	if err := ifs.Mkdir(datapath.Save()); err != nil {
		saveLog.Printf("cannot create common saves dir: %v", err)
		return 0
	}
	if _, err := nox_client_makeSaveDir(common.SaveTmp); err != nil {
		saveLog.Printf("cannot create temp save dir: %v", err)
		return 0
	}
	mname := noxServer.getServerMap()
	if err := ifs.Mkdir(datapath.Save(common.SaveTmp, mname)); err != nil {
		saveLog.Printf("cannot create save dir: %v", err)
		return 0
	}
	if !nox_xxx_saveMakePlayerLocation_4DB600(dword_5d4594_1563084) {
		return 0
	}
	mname = noxServer.getServerMap()
	path := datapath.Save(common.SaveTmp, mname, mname+".map")
	if legacy.Nox_xxx_mapSaveMap_51E010(path, 0) == 0 {
		return 0
	}
	legacy.Nox_xxx_monstersAllBelongToHost_4DB6A0()
	v14 := datapath.Save(common.SaveTmp, common.PlayerFile)
	*memmap.PtrUint32(0x85B3FC, 10980) &= 0xFFFFFFF7
	if memmap.Uint32(0x5D4594, 1563076) != 0 {
		*memmap.PtrUint32(0x85B3FC, 10980) |= 8
	}
	*memmap.PtrUint8(0x85B3FC, 12257) = sub_450750()
	if !nox_xxx_playerSaveToFile_41A140(v14, pl.PlayerIndex()) {
		return 0
	}
	if legacy.Nox_xxx_mapSavePlayerDataMB_41A230(v14) == 0 {
		return 0
	}
	if name != common.SaveTmp {
		str := strMan.GetStringInFile("AutoSaveComplete", "SaveGame.c")
		legacy.PrintToPlayers(str)
		if err := nox_client_copySave(common.SaveTmp, name); err != nil {
			saveLog.Printf("failed to copy save file: %v", err)
			return 0
		}
	}
	dword_5d4594_1563092 = 0
	dword_5d4594_1563088 = 0
	return 1
}

func nox_xxx_saveMakePlayerLocation_4DB600(a1 unsafe.Pointer) bool {
	s := noxServer
	pl := s.GetPlayerByInd(common.MaxPlayers - 1)
	if pl == nil {
		return false
	}
	u := pl.UnitC()
	if u == nil {
		return false
	}
	obj := s.NewObjectByTypeID("SaveGameLocation")
	if obj == nil {
		return false
	}
	pos := u.Pos()
	if a1 != nil {
		ptr := *(*unsafe.Pointer)(unsafe.Add(a1, 700))
		pos = types.Pointf{
			X: *(*float32)(unsafe.Add(ptr, 80)),
			Y: *(*float32)(unsafe.Add(ptr, 84)),
		}
	}
	s.CreateObjectAt(obj, nil, pos)
	s.ObjectsNewAdd()
	obj.ScriptIDVal = u.ScriptIDVal
	var next *Object
	for it := u.FirstOwned516(); it != nil; it = next {
		next = it.NextOwned512()
		if it.Flags().Has(object.FlagActive) {
			it.SetOwner(asObjectS(obj))
		}
	}
	return true
}
