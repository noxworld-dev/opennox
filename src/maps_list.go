package nox

/*
#include "defs.h"
void nox_common_list_clear_425760(nox_list_item_t* list);
extern nox_list_item_t nox_common_maplist;
void nox_common_scanAddMap(char* filename);
*/
import "C"
import (
	"os"

	"nox/v1/common/datapath"
	"nox/v1/common/fs"
	"nox/v1/common/maps"
)

var soloAllowMP = os.Getenv("NOX_SOLO_MP") == "true"

func scanMaps() (maps.MapList, error) {
	return maps.Scan(datapath.Path(maps.Dir), &maps.ScanOptions{
		Solo: soloAllowMP,
	})
}

func nox_common_scanAllMaps_4D07F0() error {
	C.nox_common_list_clear_425760(&C.nox_common_maplist)
	list, err := scanMaps()
	if err != nil && len(list) == 0 {
		return err
	}
	for _, m := range list {
		s := CString(m.Filename)
		C.nox_common_scanAddMap(s)
		StrFree(s)
	}
	return nil
}

//export nox_xxx_checkHasSoloMaps_40ABD0
func nox_xxx_checkHasSoloMaps_40ABD0() C.bool {
	return C.bool(nox_xxx_checkHasSoloMaps())
}

func nox_xxx_checkHasSoloMaps() bool {
	_, err := fs.Stat("maps\\con01a\\con01a.map")
	return err == nil
}
