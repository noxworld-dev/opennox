package opennox

import (
	"encoding/json"
	"net/http"
	"strconv"
	"strings"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/server"
)

type debugObjectType struct {
	Ind          int                 `json:"ind"`
	ID           string              `json:"id"`
	Class        object.Class        `json:"class"`
	MonsterClass object.MonsterClass `json:"monster_class,omitempty"`
	ArmorClass   object.ArmorClass   `json:"armor_class,omitempty"`
	WeaponClass  object.WeaponClass  `json:"weapon_class,omitempty"`
	OtherClass   object.OtherClass   `json:"other_class,omitempty"`
}

type debugObject struct {
	Ind          int                 `json:"ind"`
	ID           string              `json:"id,omitempty"`
	ScriptID     int                 `json:"script_id,omitempty"`
	Enabled      bool                `json:"enabled"`
	Class        object.Class        `json:"class"`
	Flags        object.Flags        `json:"flags,omitempty"`
	MonsterClass object.MonsterClass `json:"monster_class,omitempty"`
	ArmorClass   object.ArmorClass   `json:"armor_class,omitempty"`
	WeaponClass  object.WeaponClass  `json:"weapon_class,omitempty"`
	OtherClass   object.OtherClass   `json:"other_class,omitempty"`
	Type         *debugObjectType    `json:"type"`
	Dir1         server.Dir16        `json:"dir1,omitempty"`
	Dir2         server.Dir16        `json:"dir2,omitempty"`
	Pos          types.Pointf        `json:"pos"`
	Z            float32             `json:"z,omitempty"`
	Vel          types.Pointf        `json:"vel,omitempty"`
	Force        types.Pointf        `json:"force,omitempty"`
	Mass         float32             `json:"mass,omitempty"`
	Team         *debugTeamInfo      `json:"team,omitempty"`
	Inventory    []*debugObject      `json:"inventory,omitempty"`
	Equipment    []*debugObject      `json:"equipment,omitempty"`
	Field516     []*debugObject      `json:"field_516,omitempty"`
}

func dumpObjectType(t *server.ObjectType) *debugObjectType {
	if t == nil {
		return nil
	}
	return &debugObjectType{
		Ind:          t.Ind(),
		ID:           t.ID(),
		Class:        t.Class(),
		MonsterClass: t.MonsterClass(),
		ArmorClass:   t.ArmorClass(),
		WeaponClass:  t.WeaponClass(),
		OtherClass:   t.OtherClass(),
	}
}

func (obj *Object) dump() *debugObject {
	if obj == nil {
		return nil
	}
	var inv []*debugObject
	for _, it := range obj.Inventory() {
		inv = append(inv, it.dump())
	}
	var euip []*debugObject
	for _, it := range obj.Equipment() {
		euip = append(euip, it.dump())
	}
	var f516 []*debugObject
	for _, it := range obj.GetOwned516() {
		f516 = append(f516, it.dump())
	}
	return &debugObject{
		Ind:          obj.Ind(),
		ScriptID:     obj.ScriptIDVal,
		ID:           obj.ID(),
		Enabled:      obj.IsEnabled(),
		Class:        obj.Class(),
		Flags:        obj.Flags(),
		MonsterClass: obj.MonsterClass(),
		ArmorClass:   obj.ArmorClass(),
		WeaponClass:  obj.WeaponClass(),
		OtherClass:   obj.OtherClass(),
		Type:         dumpObjectType(obj.ObjectTypeC()),
		Dir1:         obj.Dir1(),
		Dir2:         obj.Dir2(),
		Pos:          obj.Pos(),
		Z:            obj.ZVal,
		Vel:          obj.Vel(),
		Force:        obj.Force(),
		Mass:         obj.Mass,
		Team:         dumpTeam(obj.Team()),
		Inventory:    inv,
		Equipment:    euip,
		Field516:     f516,
	}
}

func (obj *Object) MarshalJSON() ([]byte, error) {
	return json.Marshal(obj.dump())
}

func init() {
	http.HandleFunc("/debug/nox/types", func(w http.ResponseWriter, r *http.Request) {
		var out []*debugObjectType
		for _, t := range noxServer.Types.List() {
			out = append(out, dumpObjectType(t))
		}
		writeJSONResp(w, out)
	})
	http.HandleFunc("/debug/nox/objects", func(w http.ResponseWriter, r *http.Request) {
		qu := r.URL.Query()
		indStr := qu.Get("ind")
		if indStr == "" {
			writeJSONResp(w, noxServer.GetObjects())
			return
		}
		ind, err := strconv.ParseInt(indStr, 10, 32)
		if err != nil {
			http.Error(w, "Bad index", http.StatusBadRequest)
			return
		}
		obj := asObjectS(noxServer.Objs.GetObjectByInd(int(ind)))
		if obj == nil {
			http.Error(w, "Not found", http.StatusFound)
			return
		}
		all := obj.Flags()
		for _, word := range strings.Split(qu.Get("flags"), ",") {
			fname := word
			unset := false
			if strings.HasPrefix(fname, "-") {
				unset = true
				fname = fname[1:]
			}
			fl, err := object.ParseFlag(fname)
			if err != nil {
				http.Error(w, err.Error(), http.StatusBadRequest)
				return
			}
			if unset {
				all &^= fl
			} else {
				all |= fl
			}
		}
		obj.ObjFlags = uint32(all)
		writeJSONResp(w, obj)
	})
}
