package main

import (
	"encoding/json"
	"net/http"

	"nox/v1/common/object"
	"nox/v1/common/types"
)

type debugObjectType struct {
	Ind        int               `json:"ind"`
	ID         string            `json:"id"`
	Class      object.Class      `json:"class"`
	ArmorClass object.ArmorClass `json:"armor_class,omitempty"`
}

type debugObject struct {
	Ind        int               `json:"ind"`
	ID         string            `json:"id,omitempty"`
	Enabled    bool              `json:"enabled"`
	Class      object.Class      `json:"class"`
	ArmorClass object.ArmorClass `json:"armor_class,omitempty"`
	Pos        types.Pointf      `json:"pos"`
	Type       *debugObjectType  `json:"type"`
	Inventory  []*debugObject    `json:"inventory,omitempty"`
	Field516   []*debugObject    `json:"field_516,omitempty"`
}

var _ json.Marshaler = &ObjectType{}

func (t *ObjectType) dump() *debugObjectType {
	if t == nil {
		return nil
	}
	return &debugObjectType{
		Ind:        t.Ind(),
		ID:         t.ID(),
		Class:      t.Class(),
		ArmorClass: t.ArmorClass(),
	}
}

func (t *ObjectType) MarshalJSON() ([]byte, error) {
	return json.Marshal(t.dump())
}

func (obj *Object) dump() *debugObject {
	if obj == nil {
		return nil
	}
	var inv []*debugObject
	for _, it := range obj.Inventory() {
		inv = append(inv, it.dump())
	}
	var f516 []*debugObject
	for _, it := range obj.GetOwned516() {
		f516 = append(f516, it.dump())
	}
	return &debugObject{
		Ind:        obj.Ind(),
		ID:         obj.ID(),
		Enabled:    obj.IsEnabled(),
		Class:      obj.Class(),
		ArmorClass: obj.ArmorClass(),
		Pos:        obj.Pos(),
		Type:       obj.ObjectTypeC().dump(),
		Inventory:  inv,
		Field516:   f516,
	}
}

func (obj *Object) MarshalJSON() ([]byte, error) {
	return json.Marshal(obj.dump())
}

func init() {
	http.HandleFunc("/debug/nox/types", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, getObjectTypes())
	})
	http.HandleFunc("/debug/nox/objects", func(w http.ResponseWriter, r *http.Request) {
		writeJSONResp(w, getObjects())
	})
}
