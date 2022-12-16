package opennox

/*
#include "defs.h"
void nox_xxx_comJournalEntryAdd_427500(nox_object_t* a1, char* a2, short a3);
*/
import "C"
import (
	"github.com/noxworld-dev/opennox-lib/script/noxscript/ns"

	"github.com/noxworld-dev/opennox/v1/common/sound"
)

func (s noxScriptNS) GetQuestStatus(name string) int {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) GetQuestStatusFloat(name string) float32 {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) SetQuestStatus(status int, name string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) SetQuestStatusFloat(status float32, name string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) ResetQuestStatus(name string) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) JournalEntry(obj ns.Obj, msg ns.StringID, typ ns.EntryType) {
	str := CString(string(msg))
	defer StrFree(str)
	if obj == nil {
		for _, it := range s.s.getPlayerUnits() {
			C.nox_xxx_comJournalEntryAdd_427500(it.CObj(), str, C.short(typ))
		}
	} else {
		C.nox_xxx_comJournalEntryAdd_427500(obj.(noxObject).CObj(), str, C.short(typ))
		if (typ & 0xB) != 0 {
			s.s.AudioEventObj(sound.SoundJournalEntryAdd, obj.(noxObject).AsObject().AsUnit(), 0, 0)
		}
	}
}

func (s noxScriptNS) JournalEdit(obj ns.Obj, message ns.StringID, typ ns.EntryType) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) JournalDelete(obj ns.Obj, message ns.StringID) {
	//TODO implement me
	panic("implement me")
}
