package server

import "github.com/noxworld-dev/opennox/v1/common/unit/ai"

var aiActions = make(map[ai.ActionType]AIAction)

type AIAction interface {
	Type() ai.ActionType
	Start(u *Object)
	Update(u *Object)
	End(u *Object)
	Cancel(u *Object)
}

func RegisterAIAction(act AIAction) {
	if _, ok := aiActions[act.Type()]; ok {
		panic("already registered")
	}
	aiActions[act.Type()] = act
}

func GetAIAction(typ ai.ActionType) AIAction {
	return aiActions[typ]
}
