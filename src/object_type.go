package opennox

import (
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

func sub_4E3B80(ind int) bool {
	return noxServer.Types.ByInd(ind).Icon != -1
}

func (s *Server) FreeObjectTypes() {
	s.Server.FreeObjectTypes()
	nox_xxx_free_42BF80()
}

var _ = [1]struct{}{}[20-unsafe.Sizeof(server.HealthData{})]

func (s *Server) createObject(t *server.ObjectType, p types.Pointf) *server.Object {
	obj := s.Objs.NewObject(t)
	if obj == nil {
		return nil
	}
	s.CreateObjectAt(obj, nil, p)
	return obj
}
