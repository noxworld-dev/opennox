package opennox

import (
	"os"

	"github.com/noxworld-dev/opennox-lib/datapath"
	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/maps"

	"github.com/noxworld-dev/opennox/v1/common/memmap"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

var soloAllowMP = os.Getenv("NOX_SOLO_MP") == "true"

func scanMaps() (maps.MapList, error) {
	return maps.Scan(datapath.Data(maps.Dir), &maps.ScanOptions{
		Solo: soloAllowMP,
	})
}

func nox_common_scanAllMaps_4D07F0() error {
	nox_common_list_clear_425760(legacy.Get_nox_common_maplist())
	list, err := scanMaps()
	if err != nil && len(list) == 0 {
		return err
	}
	for _, m := range list {
		nox_common_scanAddMap(m.Filename)
	}
	return nil
}

func nox_common_scanAddMap(filename string) {
	name := filename
	if len(name) > 9 {
		name = name[:8] // FIXME: can we split by path separator? extension?
	}
	if err := nox_common_checkMapFile(name); err != nil {
		gameLog.Println("map list:", err)
		return
	}
	mp, _ := alloc.New(legacy.Nox_map_list_item{})
	legacy.Sub_425770(mp)
	alloc.StrCopyZero(mp.Name[:], name)
	mp.Field_6 = 1
	mp.Field_7 = memmap.Uint32(0x973F18, 3800)
	mp.Field_8_0 = memmap.Uint8(0x973F18, 3804)
	mp.Field_8_1 = memmap.Uint8(0x973F18, 3805)
	legacy.Nox_common_maplist_add_4D0760(mp)
}

func nox_xxx_checkHasSoloMaps() bool {
	_, err := ifs.Stat(datapath.Maps("con01a", "con01a.map"))
	return err == nil
}
