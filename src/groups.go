package opennox

import (
	"fmt"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"

	"github.com/noxworld-dev/opennox/v1/legacy"
	"github.com/noxworld-dev/opennox/v1/server"
)

var _ = [1]struct{}{}[96-unsafe.Sizeof(server.MapGroup{})]

func (s *Server) Sub504720(a1, a2 uint32) int32 {
	s.groupsAdjust(a1, a2)
	for it := s.MapGroups.Refs; it != nil; it = it.Next4 {
		s.MapGroups.AddNewMapGroup57C3B0(it.Field0)
	}
	return 1
}

func (s *Server) PendingObjByScriptID4CFFE0(sid int) *server.Object {
	for it := s.Objs.Pending; it != nil; it.Next() {
		if it.ScriptIDVal == sid {
			return it
		}
	}
	return nil
}

func (s *Server) groupsAdjust(dx, dy uint32) {
	di := s.MapGroups.NextMapGroupIndex()
	for it := s.MapGroups.Refs; it != nil; it = it.Next4 {
		name := fmt.Sprintf("%s%%%d", it.Field0.ID(), legacy.Get_dword_5d4594_3835312())
		it.Field0.SetID(name)
		it.Field0.Ind += di

		for it2 := it.Field0.List; it2 != nil; it2 = it2.Next8 {
			switch it.Field0.GroupType() {
			case server.MapGroupObjects:
				if p := s.PendingObjByScriptID4CFFE0(it2.Data1()); p != nil {
					it2.Raw0 = p.Extent
				}
			case server.MapGroupWaypoints:
				if p := s.WPs.PendingByIndTmp(it2.Raw0); p != nil {
					it2.Raw0 = p.Index
				}
			case server.MapGroupWalls:
				it2.Raw0 = (dx + it2.Raw0*common.GridStep) / common.GridStep
				it2.Raw4 = (dy + it2.Raw4*common.GridStep) / common.GridStep
			case server.MapGroupGroups:
				it2.Raw0 += di
			}
		}
	}
}

func (s *Server) GroupByID(id string, typ server.MapGroupKind) *server.MapGroup {
	for p := s.MapGroups.GetFirstMapGroup(); p != nil; p = p.Next() {
		if mapGroupType(p) != typ {
			continue
		}
		id2 := p.ID()
		if id == id2 || strings.HasSuffix(id2, ":"+id) {
			return p
		}
	}
	return nil
}

// mapGroupType determines the group's type recursively.
func mapGroupType(g *server.MapGroup) server.MapGroupKind {
	return legacy.Nox_server_scriptGetGroupId_57C2D0(g.C())
}
