package main

/*
#include "defs.h"
void nox_common_list_clear_425760(nox_list_item_t* list);
extern nox_list_item_t nox_common_maplist;
void nox_common_scanAddMap(char* filename);
*/
import "C"
import (
	"nox/v1/common/maps"
)

func nox_common_scanAllMaps_4D07F0() error {
	C.nox_common_list_clear_425760(&C.nox_common_maplist)
	list, err := maps.Scan(getDataPath("maps"), nil)
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
