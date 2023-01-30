package opennox

// for export
import (
	"fmt"

	"github.com/noxworld-dev/opennox/v1/legacy"
)

const (
	noxProtoVersionLegacy  = NoxVersion(0x0001039A) // 0.1.922
	noxProtoVersionHighRes = NoxVersion(0x000F039A) // 0.15.922
)

type NoxVersion uint32

func (v NoxVersion) Build() int {
	return int(v & 0xffff)
}

func (v NoxVersion) Major() int {
	return int((v >> 24) & 0xff)
}

func (v NoxVersion) Minor() int {
	return int((v >> 16) & 0xff)
}

func (v NoxVersion) String() string {
	return fmt.Sprintf("%d.%d.%d", v.Major(), v.Minor(), v.Build())
}

var versionCode = NOX_CLIENT_VERS_CODE

func getVersionCode() NoxVersion {
	return versionCode
}

func nox_client_setVersion_409AE0(v uint32) {
	setVersionCode(NoxVersion(v))
}

func setVersionCode(vers NoxVersion) {
	if versionCode != vers {
		versionCode = vers
		legacy.Nox_server_gameSettingsUpdated_40A670()
	}
}
