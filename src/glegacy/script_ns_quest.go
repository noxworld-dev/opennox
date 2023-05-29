package legacy

/*
#include "defs.h"
void nox_xxx_comJournalEntryAdd_427500(nox_object_t* a1, char* a2, short a3);
*/
import "C"
import (
	"github.com/noxworld-dev/noxscript/ns/v4"

	"github.com/noxworld-dev/opennox/v1/server"
)

func Nox_xxx_comJournalEntryAdd_427500(a1 *server.Object, msg ns.StringID, a3 ns.EntryType) {
	str := CString(string(msg))
	defer StrFree(str)
	C.nox_xxx_comJournalEntryAdd_427500(asObjectC(a1), str, C.short(a3))
}
