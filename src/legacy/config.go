package legacy

var (
	WriteConfigLegacy func(name string)
)

// nox_common_writecfgfile
func nox_common_writecfgfile(str *byte) {
	WriteConfigLegacy(GoString(str))
}
