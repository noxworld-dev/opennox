package opennox

import (
	"github.com/noxworld-dev/noxscript/ns/v4"

	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
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
	if obj == nil {
		for _, it := range s.s.getPlayerUnits() {
			legacy.Nox_xxx_comJournalEntryAdd_427500(it.SObj(), msg, typ)
		}
	} else {
		legacy.Nox_xxx_comJournalEntryAdd_427500(obj.(server.Obj).SObj(), msg, typ)
		if (typ & 0xB) != 0 {
			s.s.Audio.EventObj(sound.SoundJournalEntryAdd, toObject(obj.(server.Obj)), 0, 0)
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

func (s noxScriptNS) JournalEntryStr(obj ns.Obj, msg string, typ ns.EntryType) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) JournalEditStr(obj ns.Obj, message string, typ ns.EntryType) {
	//TODO implement me
	panic("implement me")
}

func (s noxScriptNS) JournalDeleteStr(obj ns.Obj, message string) {
	//TODO implement me
	panic("implement me")
}
