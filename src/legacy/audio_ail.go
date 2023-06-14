package legacy

import (
	"unsafe"

	"github.com/noxworld-dev/opennox/v1/legacy/client/audio/ail"
)

var (
	Sub_43EA20                    func(a1 unsafe.Pointer) int
	Sub_43E9F0                    func()
	Sub_43E940                    func(a1 unsafe.Pointer) int
	Sub_43EFD0                    func(a1 unsafe.Pointer)
	Sub_43EC10                    func() int
	Sub_43F130                    func() int
	Sub_43ED00                    func(a1p unsafe.Pointer) int
	Sub_43D650                    func()
	Sub_43D680                    func()
	Sub_43D6A0                    func()
	Sub_44D640                    func()
	Sub_44D7E0                    func(a1 int) int
	Nox_xxx_musicStartPlay_43D6C0 func(a1p unsafe.Pointer) int
	Sub_44D660                    func(a1 string) bool
	Sub_43F060                    func(a1p unsafe.Pointer) int
	Sub_43EC30                    func(a1 unsafe.Pointer) int
	Sub_43ECB0                    func(a1 unsafe.Pointer) int
)

type WIN32_FIND_DATAA struct {
	FileAttributes     uint32
	ftCreationTime     FILETIME
	ftLastAccessTime   FILETIME
	ftLastWriteTime    FILETIME
	nFileSizeHigh      uint32
	nFileSizeLow       uint32
	dwReserved0        uint32
	dwReserved1        uint32
	cFileName          [MAX_PATH]byte
	cAlternateFileName [14]byte
}

func FindFirstFileA(a1 *byte, f *WIN32_FIND_DATAA) uintptr {
	return uintptr(unsafe.Pointer(compatFindFirstFileA((*byte)(unsafe.Pointer(a1)), (*WIN32_FIND_DATAA)(unsafe.Pointer(f)))))
}

func FindNextFileA(h uintptr, f *WIN32_FIND_DATAA) int {
	return int(compatFindNextFileA(HANDLE(unsafe.Pointer(h)), (*WIN32_FIND_DATAA)(unsafe.Pointer(f))))
}

func FindClose(h uintptr) {
	compatFindClose(HANDLE(unsafe.Pointer(h)))
}

var _ = [1]struct{}{}[32-unsafe.Sizeof(AudioSample{})]

type AudioSample struct {
	Dev    ail.Driver     // 0, 0
	Field1 unsafe.Pointer // 1, 4
	Smp    ail.Sample     // 2, 8
	Field3 uint32         // 3, 12
	Field4 unsafe.Pointer // 4, 16
	Data1  *byte          // 5, 20
	Data2  *byte          // 6, 24
	Flag7  uint32         // 7, 28
}

// Sub_43E8E0
func Sub_43E8E0(a1 int) {}

// Sub_43E910
func Sub_43E910(a1 int) {}

// sub_43F050
func sub_43F050() int {
	return 0
}

// sub_43F0D0
func sub_43F0D0(int32) {
}

// sub_43F030
func sub_43F030(a1 int) int {
	panic("abort")
}

// AIL_set_stream_volume
func AIL_set_stream_volume(s HSTREAM, volume int32) {
	ail.Stream(unsafe.Pointer(s)).SetVolume(int(volume))
}

// AIL_stream_position
func AIL_stream_position(s HSTREAM) int32 {
	return int32(ail.Stream(unsafe.Pointer(s)).Position())
}

// AIL_stream_status
func AIL_stream_status(s HSTREAM) int32 {
	return int32(ail.Stream(unsafe.Pointer(s)).Status())
}

// AIL_load_sample_buffer
func AIL_load_sample_buffer(s HSAMPLE, num uint32, buf unsafe.Pointer, sz uint32) {
	ail.Sample(unsafe.Pointer(s)).LoadBuffer(num, unsafe.Slice((*byte)(buf), int(sz)))
}

// AIL_sample_buffer_ready
func AIL_sample_buffer_ready(s HSAMPLE) int32 {
	return int32(ail.Sample(unsafe.Pointer(s)).BufferReady())
}

// AIL_sample_user_data
func AIL_sample_user_data(s HSAMPLE) unsafe.Pointer {
	v := ail.Sample(unsafe.Pointer(s)).UserData()
	if v == nil {
		return nil
	}
	return unsafe.Pointer(v.(*AudioSample))
}

// sub_43F010
func sub_43F010(a1 unsafe.Pointer) int {
	p := *(**AudioSample)(unsafe.Add(a1, 272))
	p.Smp.Stop()
	return 0
}

// sub_43EA20
func sub_43EA20(a1 unsafe.Pointer) int {
	return Sub_43EA20(a1)
}

// sub_43E9F0
func sub_43E9F0(a1 unsafe.Pointer) {
	Sub_43E9F0()
}

// sub_43E940
func sub_43E940(a1 unsafe.Pointer) int {
	return Sub_43E940(a1)
}

// sub_43EFD0
func sub_43EFD0(a1 unsafe.Pointer) {
	Sub_43EFD0(a1)
}

// sub_43EC10
func sub_43EC10(a1 unsafe.Pointer) {
	Sub_43EC10()
}

// sub_43F130
func sub_43F130() int32 {
	return int32(Sub_43F130())
}

// sub_43ED00
func sub_43ED00(a1p unsafe.Pointer) int {
	return Sub_43ED00(a1p)
}

// sub_43D650
func sub_43D650() {
	Sub_43D650()
}

// sub_43D680
func sub_43D680() {
	Sub_43D680()
}

// sub_43D6A0
func sub_43D6A0() {
	Sub_43D6A0()
}

// sub_44D640
func sub_44D640() {
	Sub_44D640()
}

// sub_44D7E0
func sub_44D7E0(a1 int32) int {
	return Sub_44D7E0(int(a1))
}

// nox_xxx_musicStartPlay_43D6C0
func nox_xxx_musicStartPlay_43D6C0(a1p *int32) int {
	return Nox_xxx_musicStartPlay_43D6C0(unsafe.Pointer(a1p))
}

// sub_44D660
func sub_44D660(a1 *byte) int {
	return bool2int(Sub_44D660(GoString(a1)))
}

// sub_43F060
func sub_43F060(a1p *uint32) int {
	return Sub_43F060(unsafe.Pointer(a1p))
}

// sub_43EC30
func sub_43EC30(a1p unsafe.Pointer) int {
	return Sub_43EC30(a1p)
}

// sub_43ECB0
func sub_43ECB0(a1p unsafe.Pointer) {
	Sub_43ECB0(a1p)
}

func Get_dword_5d4594_831092() ail.Driver {
	return ail.Driver(dword_5d4594_831092)
}

func Sub_43D2D0() {
	sub_43D2D0()
}

func Sub_486620(v unsafe.Pointer) {
	sub_486620((*uint32)(v))
}

func Sub_42EBB0(a1 int, a2 unsafe.Pointer, a3 int, a4 string) {
	sub_42EBB0(uint32(a1), a2, int32(a3), internCStr(a4))
}

func Get_dword_587000_127004() unsafe.Pointer {
	return dword_587000_127004
}

func Sub_43F0E0(v unsafe.Pointer) int {
	return int(sub_43F0E0((*uint32)(v)))
}

func Sub_43EE00(v *AudioSample) {
	sub_43EE00(unsafe.Pointer(v))
}

func Sub_43EDB0(v ail.Sample) {
	sub_43EDB0((HSAMPLE)(unsafe.Pointer(v)))
}

func Get_dword_5d4594_816364() ail.Stream {
	return ail.Stream(dword_5d4594_816364)
}

func Set_dword_5d4594_816364(v ail.Stream) {
	dword_5d4594_816364 = uint32(v)
}

func Set_dword_5d4594_816092(v int) {
	dword_5d4594_816092 = uint32(v)
}

func Get_dword_5d4594_831088() ail.Stream {
	return ail.Stream(dword_5d4594_831088)
}

func Set_dword_5d4594_831088(v ail.Stream) {
	dword_5d4594_831088 = uint32(v)
}

func Sub_413890() string {
	return GoString(sub_413890())
}

func Nox_xxx_parseSoundSetBin_424170(path string) int {
	return int(nox_xxx_parseSoundSetBin_424170(internCStr(path)))
}

func Sub_486670(v int, ind int) {
	sub_486670(int32(v), int32(ind))
}

func Nox_xxx_WorkerHurt_44D810() {
	nox_xxx_WorkerHurt_44D810()
}

func Sub_43D8E0() {
	sub_43D8E0()
}

func Sub_43DC00() {
	sub_43DC00()
}

func Sub_44D960() {
	sub_44D960()
}

func Sub_453050() {
	sub_453050()
}

func Sub_44D5C0(s ail.Stream, a2 int) {
	sub_44D5C0(int32(s), int32(a2))
}

func Get_dword_5d4594_816376() ail.Driver {
	return ail.Driver(dword_5d4594_816376)
}

func Sub_486320(p unsafe.Pointer, a2 int) {
	sub_486320((*uint32)(p), int32(a2))
}

func Sub_486350(p unsafe.Pointer, a2 int) {
	sub_486350(p, int32(a2))
}

func Sub_43D3C0(s ail.Stream, a2 int) {
	sub_43D3C0(int32(s), int32(a2))
}

func Get_dword_587000_122856() int {
	return int(dword_587000_122856)
}

func Get_dword_587000_122848() int {
	return int(dword_587000_122848)
}

func Get_dword_5d4594_830872() int {
	return int(dword_5d4594_830872)
}

func Set_dword_587000_122856(v int) {
	dword_587000_122856 = uint32(v)
}

func Sub_486640(a1 unsafe.Pointer, a2 int) int {
	return int(sub_486640(a1, int32(a2)))
}

func Get_dword_5d4594_805984() unsafe.Pointer {
	return dword_5d4594_805984
}

func Set_dword_5d4594_805984(v unsafe.Pointer) {
	dword_5d4594_805984 = v
}

func Set_dword_587000_81128(v unsafe.Pointer) {
	dword_587000_81128 = v
}

func Sub_4864A0(v unsafe.Pointer) {
	sub_4864A0((*uint32)(v))
}

func Sub_451850(a1 unsafe.Pointer, a2 unsafe.Pointer) {
	sub_451850(int32(uintptr(a1)), a2)
}

func Sub_4866A0(a1 int) int {
	return int(sub_4866A0(int32(a1)))
}

func Sub_486FA0(a1 int) {
	sub_486FA0(int32(a1))
}

func Sub_487D00(a1 unsafe.Pointer) {
	sub_487D00((*uint32)(a1))
}

func Sub_487150(a1 int, a2 unsafe.Pointer) unsafe.Pointer {
	return unsafe.Pointer(sub_487150(int32(a1), a2))
}

func Sub_487790(a1 unsafe.Pointer, a2 int) int {
	return int(sub_487790(int32(uintptr(a1)), int32(a2)))
}
