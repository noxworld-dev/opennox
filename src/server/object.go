package server

type Obj interface {
	SObj() *Object
}

type Object struct {
	_ [772]byte // TODO
}
