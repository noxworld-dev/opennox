package legacy

import (
	"github.com/noxworld-dev/noxscript/ns/v4"

	"github.com/noxworld-dev/opennox/v1/server"
)

func Nox_xxx_comJournalEntryAdd_427500(a1 *server.Object, msg ns.StringID, a3 ns.EntryType) {
	str := CString(string(msg))
	defer StrFree(str)
	nox_xxx_comJournalEntryAdd_427500(asObjectC(a1), str, int16(a3))
}
