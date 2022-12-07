package server

type File interface {
	Skip(n int)
	ReadU8() uint8
	ReadI8() int8
	ReadU16() uint16
	ReadI16() int16
	ReadU32() uint32
	ReadI32() int32
	ReadString8() (string, error)
}
