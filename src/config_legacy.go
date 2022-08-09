package opennox

/*
#include <stdint.h>
#include "GAME1.h"
#include "GAME1_3.h"
#include "GAME2.h"
#include "GAME2_2.h"
#include "GAME3_2.h"
#include "GAME5_2.h"
#include "common__system__settings.h"
extern void* dword_587000_122852;
extern void* dword_587000_127004;
extern void* dword_587000_93164;
extern unsigned int dword_5d4594_1193156;
extern unsigned int nox_client_translucentFrontWalls_805844;
extern unsigned int nox_client_highResFrontWalls_80820;
extern unsigned int nox_client_highResFloors_154952;
extern unsigned int nox_client_lockHighResFloors_1193152;
extern unsigned int nox_client_fadeObjects_80836;
extern unsigned int nox_client_renderBubbles_80844;
extern unsigned int nox_client_renderGUI_80828;
extern uint32_t nox_server_connectionType_3596;
extern uint32_t nox_server_kickQuestPlayerMinVotes_229992;
extern uint32_t nox_server_resetQuestMinVotes_229988;
extern uint32_t nox_server_sanctuaryHelp_54276;
extern uint32_t nox_server_sendMotd_108752;
*/
import "C"
import (
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/cfg"
	"github.com/noxworld-dev/opennox-lib/ifs"

	"github.com/noxworld-dev/opennox/v1/common/alloc"
	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/memmap"
)

var (
	legacyUnlockSurface = false
	legacyGamma2Set     = false
	legacyGamma2        = 1.0
	legacyGamma         = 50
	legacyProfiled      = 0
)

//export nox_common_writecfgfile
func nox_common_writecfgfile(str *C.char) {
	if err := writeConfigLegacy(GoString(str)); err != nil {
		configLog.Printf("%s", err)
	}
}

func noxConfigRead(path string, skip bool) error {
	configLog.Printf("reading legacy: %q", path)
	ctrlEvent.Reset()
	f, err := ifs.Open(path)
	if err != nil {
		return err
	}
	defer f.Close()
	if err := parseLegacyConfig(f, skip); err != nil {
		return err
	}
	return nil
}

func nox_common_readcfgfile(path string, skip bool) error {
	err := noxConfigRead(path, skip)
	if err == nil {
		return nil
	} else if !os.IsNotExist(err) {
		return err
	}
	// not found: read default and write config back
	orig := err
	err = noxConfigRead("default.cfg", skip)
	if os.IsNotExist(err) {
		return orig
	} else if err != nil {
		return err
	}
	writeConfigLegacy("nox.cfg")
	return nil
}

func parseLegacyConfig(r io.Reader, skip bool) error {
	file, err := cfg.Parse(r)
	if err != nil {
		return fmt.Errorf("config parsing failed: %w", err)
	}
	if !skip {
		var sect cfg.Section
		if len(file.Sections) > 0 {
			sect = file.Sections[0]
		}
		if err := nox_common_parsecfg_all(sect); err != nil {
			return err
		}
	}
	var sect cfg.Section
	if len(file.Sections) > 1 {
		sect = file.Sections[1]
	}
	if err := nox_common_skipcfgfile_4331E0(sect, skip); err != nil {
		return err
	}
	return nil
}

func nox_common_parsecfg_all(sect cfg.Section) error {
	sub_486670(0x4000, 0)
	sub_486670(0x4000, 1)
	sub_486670(0x4000, 2)
	for _, kv := range sect {
		switch kv.Key {
		case "Version":
			v, err := strconv.ParseUint(kv.Value, 10, 32)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			*memmap.PtrUint32(0x587000, 81284) = uint32(v)
		case "VideoMode":
			sub := strings.SplitN(kv.Value, " ", 3)
			if len(sub) < 2 {
				return fmt.Errorf("cannot parse %s: %q", kv.Key, kv.Value)
			}
			w, err := strconv.Atoi(sub[0])
			if err != nil {
				return fmt.Errorf("cannot parse %s width: %w", kv.Key, err)
			}
			h, err := strconv.Atoi(sub[1])
			if err != nil {
				return fmt.Errorf("cannot parse %s height: %w", kv.Key, err)
			}
			// TODO: should set resolution in the new config if it's not set
			_, _ = w, h
		case "VideoSize":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			nox_video_setCutSize(v)
		case "Gamma":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			legacyGamma = v
		case "Gamma2":
			v, err := strconv.ParseFloat(kv.Value, 64)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			legacyGamma2Set = true
			legacyGamma2 = v
		case "FXVolume":
			if err := sub_432CB0(kv.Value, 0); err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
		case "DialogVolume":
			if err := sub_432CB0(kv.Value, 1); err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
		case "MusicVolume":
			if err := sub_432CB0(kv.Value, 2); err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
		case "LastServer":
			StrCopyP(memmap.PtrOff(0x5D4594, 806060), 22, kv.Value)
		case "ServerName":
			name := kv.Value
			if memmap.Uint32(0x587000, 81284) == 0x10000 && name == "NoxWorld" {
				name = "User_Game"
			}
			name = strings.ReplaceAll(name, "_", " ")
			C.nox_xxx_gameSetServername_40A440(internCStr(name))
		case "UnlockSurface":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			legacyUnlockSurface = v != 0
		case "SoftShadowEdge":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			if v != 0 {
				noxflags.SetEngine(noxflags.EngineSoftShadowEdge)
			} else {
				noxflags.UnsetEngine(noxflags.EngineSoftShadowEdge)
			}
		case "DrawFrontWalls":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			nox_client_drawFrontWalls_80812 = v != 0
		case "TranslucentFrontWalls":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_client_translucentFrontWalls_805844 = C.uint(bool2int(v != 0))
		case "HighResFrontWalls":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_client_highResFrontWalls_80820 = C.uint(bool2int(v != 0))
		case "HighResFloors":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_client_highResFloors_154952 = C.uint(bool2int(v != 0))
		case "LockHighResFloors":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_client_lockHighResFloors_1193152 = C.uint(bool2int(v != 0))
		case "TexturedFloors":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			nox_client_texturedFloors_154956 = v != 0
			nox_xxx_tileSetDrawFn_481420()
			if v != 0 {
				C.dword_5d4594_1193156 = 0
			}
			nox_client_texturedFloors2_154960 = nox_client_texturedFloors_154956
		case "TranslucentConsole":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			guiCon.translucent = v != 0
		case "RenderGlow":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			noxClient.r.renderGlow = v != 0
		case "RenderGUI":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_client_renderGUI_80828 = C.uint(bool2int(v != 0))
		case "FadeObjects":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_client_fadeObjects_80836 = C.uint(bool2int(v != 0))
		case "TrackData":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			sub_578DE0(byte(v))
		case "RenderBubbles":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_client_renderBubbles_80844 = C.uint(bool2int(v != 0))
		case "SysopPassword":
			C.nox_xxx_sysopSetPass_40A610(internWStr(kv.Value))
		case "ServerPassword":
			v0 := sub_416640()
			dst := unsafe.Slice((*uint16)(unsafe.Pointer(&v0[78])), 8)
			WStrCopySlice(dst, kv.Value)
			dst[len(dst)-1] = 0
		case "Profiled":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			legacyProfiled = v
		case "SanctuaryHelp":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_server_sanctuaryHelp_54276 = C.uint(bool2int(v != 0))
		case "MaxPacketLossPct":
			v, err := strconv.ParseUint(kv.Value, 10, 32)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			*memmap.PtrUint32(0x587000, 81280) = uint32(v)
			*memmap.PtrUint32(0x587000, 292940) = uint32(float64(v) * 0.0099999998 * 10.0)
		case "SendMessageOfTheDay":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_server_sendMotd_108752 = C.uint(bool2int(v != 0))
		case "InternetUpdateRate":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_xxx_rateUpdate_40A6D0(C.int(v))
			if C.nox_xxx_rateGet_40A6C0() <= 0 || C.nox_xxx_rateGet_40A6C0() > 3 {
				C.nox_xxx_rateUpdate_40A6D0(1)
			}
		case "ConnectionType":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			found := false
			for _, t := range configConnTypes {
				if t.Val == v {
					found = true
					break
				}
			}
			if found {
				if v < 0 || v > 4 {
					v = 4
				}
				C.nox_server_connectionType_3596 = C.uint(v)
			}
		case "MapCycle":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.sub_4D0D90(C.int(bool2int(v != 0)))
		case "LANFilters":
			err := sub_432E50(kv.Value, 0)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
		case "INETFilters":
			err := sub_432E50(kv.Value, 1)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
		case "LessonLimit":
			max := len(configModeCodes)
			sub := strings.SplitN(kv.Value, ",", max)
			if len(sub) != max {
				return fmt.Errorf("invalid lessons value: %q", kv.Value)
			}
			for i, s := range sub {
				v, err := strconv.Atoi(s)
				if err != nil {
					return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
				}
				C.sub_409FB0_settings(C.short(configModeCodes[i]), C.ushort(v))
			}
		case "TimeLimit":
			max := len(configModeCodes)
			sub := strings.SplitN(kv.Value, ",", max)
			if len(sub) != max {
				return fmt.Errorf("invalid time limit value: %q", kv.Value)
			}
			for i, s := range sub {
				v, err := strconv.Atoi(s)
				if err != nil {
					return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
				}
				C.sub_40A040_settings(C.short(configModeCodes[i]), C.uchar(v))
			}
		case "PlayerSkeletons":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			*(*uint32)(unsafe.Pointer(&v1[58])) = uint32(bool2int(v > 0))
		case "BroadcastGestures":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			*(*uint32)(unsafe.Pointer(&v1[62])) = uint32(bool2int(v > 0))
		case "LatencyCompensation":
			sub := strings.SplitN(kv.Value, " ", 2)
			if len(sub) != 2 {
				return fmt.Errorf("invalid lattency compensation value: %q", kv.Value)
			}
			n1, err := strconv.Atoi(sub[0])
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			n2, err := strconv.Atoi(sub[1])
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			*(*uint32)(unsafe.Pointer(&v1[66])) = uint32(n1)
			*(*uint32)(unsafe.Pointer(&v1[70])) = uint32(n2)
		case "Closed":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			if v > 0 {
				v1[100] |= 0x10
			} else {
				v1[100] &= 0xEF
			}
		case "Private":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			if v > 0 {
				v1[100] |= 0x20
			} else {
				v1[100] &= 0xDF
			}
		case "AudioThreshold":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			if v < 0 {
				v = 0
			}
			if v > 100 {
				v = 100
			}
			v1 := sub_416640()
			*(*uint32)(unsafe.Pointer(&v1[74])) = uint32(v)
		case "MaxPlayers":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			if v < 1 {
				v = 1
			}
			if v > noxMaxPlayers {
				v = noxMaxPlayers
			}
			v1 := sub_416640()
			v1[104] = byte(v)
			C.nox_xxx_servSetPlrLimit_409F80(C.int(v))
		case "RestrictedClasses":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			v1[100] |= byte(v) & 0x7
		case "RestrictedPing":
			sub := strings.SplitN(kv.Value, " ", 2)
			if len(sub) != 2 {
				return fmt.Errorf("invalid ping limit value: %q", kv.Value)
			}
			n1, err := strconv.Atoi(sub[0])
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			n2, err := strconv.Atoi(sub[1])
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			*(*uint16)(unsafe.Pointer(&v1[105])) = uint16(n1)
			*(*uint16)(unsafe.Pointer(&v1[107])) = uint16(n2)
		case "LimitMaxRes":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			v1 := sub_416640()
			if v > 0 {
				v1[102] |= 0x80
			} else {
				v1[102] &= 0x7F
			}
		case "ItemRespawn":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			if v != 0 {
				C.sub_409E70(2)
			} else {
				C.sub_409EC0(2)
			}
		case "CamperAlarm":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			if v != 0 {
				C.sub_409E70(0x2000)
			} else {
				C.sub_409EC0(0x2000)
			}
		case "MinKickVotes":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			*memmap.PtrUint32(0x587000, 229980) = uint32(v)
		case "ResetQuestMinVotes":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_server_resetQuestMinVotes_229988 = C.uint(v)
		case "KickQuestPlayerMinVotes":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			C.nox_server_kickQuestPlayerMinVotes_229992 = C.uint(v)
		case "Fullscreen":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			g_fullscreen_cfg = v
			if noxClient.getWindowMode() <= -4 {
				noxClient.updateFullScreen(g_fullscreen_cfg)
			}
			changeWindowedOrFullscreen()
		case "Stretched":
			v, err := strconv.Atoi(kv.Value)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			g_scaled_cfg = v
			noxClient.setStretchIfNotSet(v != 0)
		case "InputSensitivity":
			v, err := strconv.ParseFloat(kv.Value, 32)
			if err != nil {
				return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
			}
			noxClient.setSensitivity(float32(v))
		default:
			for _, ci := range configCycleIndexes {
				if ci.Name == kv.Key {
					v, err := strconv.Atoi(kv.Value)
					if err != nil {
						return fmt.Errorf("cannot parse %s: %w", kv.Key, err)
					}
					C.sub_4D0DC0(C.int(ci.Flags), C.int(v))
					break
				}
			}
		}
	}
	return nil
}

var configCycleIndexes = []struct {
	Name  string
	Flags uint32
}{
	{Name: "DeathmatchMapCycleIndex", Flags: 0x100},
	{Name: "HighlanderMapCycleIndex", Flags: 0x400},
	{Name: "CaptureMapCycleIndex", Flags: 0x20},
	{Name: "FlagballMapCycleIndex", Flags: 0x40},
	{Name: "KingOfTheRealmMapCylceIndex", Flags: 0x10},
	{Name: "QuestMapCycleIndex", Flags: 0x1000},
}

var configModeCodes = []uint32{
	0x100,
	0x400,
	0x20,
	0x40,
	0x10,
}

var configConnTypes = []struct {
	Name string
	Val  int
}{
	{Name: "Modem", Val: 0x4},
	{Name: "ISDN", Val: 0x3},
	{Name: "Cable/T1", Val: 0x1},
	{Name: "Undefined", Val: 0x0},
}

func sub_432CB0(val string, ind int) error {
	v, err := strconv.ParseUint(val, 10, 32)
	if err != nil {
		return err
	}
	if v&0x80000000 == 0 {
		if v > 0x4000 {
			v = 0x4000
		}
		sub_486670(int(v), ind)
	} else {
		sub_486670(0, ind)
	}
	return nil
}

func sub_432E50(val string, ind int) error {
	sub := strings.SplitN(val, ",", 12)
	if len(sub) > 12 {
		return fmt.Errorf("invalid filter values: %q", val)
	}
	arr, freeArr := alloc.Make([]int32{}, 12)
	defer freeArr()
	for i, s := range sub {
		v, err := strconv.Atoi(s)
		if err != nil {
			return err
		}
		arr[i] = int32(v)
	}
	C.sub_489FF0(C.int(ind), C.int(arr[0]), unsafe.Pointer(&arr[1]))
	return nil
}

func nox_common_skipcfgfile_4331E0(sect cfg.Section, skip bool) error {
	for _, kv := range sect {
		if nox_client_parseConfigHotkeysLine(kv.Key, kv.Value) == 0 {
			return fmt.Errorf("cannot parse binding %s: %q", kv.Key, kv.Value)
		}
	}
	return nil
}

func writeConfigLegacy(path string) error {
	configLog.Printf("writing legacy: %q", path)
	cfile := &cfg.File{Sections: make([]cfg.Section, 2)}
	writeConfigLegacyMain(&cfile.Sections[0])
	writeConfigHotkeys(&cfile.Sections[1])
	f, err := ifs.Create(path)
	if err != nil {
		return err
	}
	defer f.Close()
	return cfile.WriteTo(f)
}

func writeConfigLegacyMain(sect *cfg.Section) {
	v1 := sub_416640()
	if _, ok := sect.Get("Version"); !ok {
		sect.Set("Version", "65540")
	}
	mode := noxClient.videoGetGameMode()
	sect.Set("VideoMode", fmt.Sprintf("%d %d 16", mode.X, mode.Y))
	sect.Set("Stretched", strconv.Itoa(g_scaled_cfg))
	sect.Set("Fullscreen", strconv.Itoa(g_fullscreen_cfg))
	sect.Set("VideoSize", strconv.Itoa(nox_video_getCutSize()))
	sect.Set("Gamma", strconv.Itoa(legacyGamma))
	if legacyGamma2Set {
		sect.Set("Gamma2", strconv.FormatFloat(legacyGamma2, 'g', -1, 32))
	}
	sect.Set("InputSensitivity", strconv.FormatFloat(float64(noxClient.getSensitivity()), 'g', -1, 32))

	v := 0
	if C.sub_453070() == 1 {
		v = int(*(*uint32)(unsafe.Add(unsafe.Pointer(C.dword_587000_127004), 4)) >> 16)
	}
	sect.Set("FXVolume", strconv.Itoa(v))

	v = 0
	if C.sub_44D990() == 1 {
		v = int(*(*uint32)(unsafe.Add(unsafe.Pointer(C.dword_587000_122852), 4)) >> 16)
	}
	sect.Set("DialogVolume", strconv.Itoa(v))

	v = 0
	if C.sub_43DC30() == 1 {
		v = int(*(*uint32)(unsafe.Add(unsafe.Pointer(C.dword_587000_93164), 4)) >> 16)
	}
	sect.Set("MusicVolume", strconv.Itoa(v))

	sect.Set("LastServer", GoStringP(memmap.PtrOff(0x5D4594, 806060)))
	sect.Set("ServerName", sub_433890())
	sect.Set("UnlockSurface", strconv.Itoa(bool2int(legacyUnlockSurface)))
	sect.Set("SoftShadowEdge", strconv.Itoa(bool2int(noxflags.HasEngine(noxflags.EngineSoftShadowEdge))))
	sect.Set("DrawFrontWalls", strconv.Itoa(bool2int(nox_client_drawFrontWalls_80812)))
	sect.Set("TranslucentFrontWalls", strconv.Itoa(int(C.nox_client_translucentFrontWalls_805844)))
	sect.Set("HighResFrontWalls", strconv.Itoa(int(C.nox_client_highResFrontWalls_80820)))
	sect.Set("HighResFloors", strconv.Itoa(int(C.nox_client_highResFloors_154952)))
	sect.Set("LockHighResFloors", strconv.Itoa(int(C.nox_client_lockHighResFloors_1193152)))
	sect.Set("TexturedFloors", strconv.Itoa(bool2int(nox_client_texturedFloors_154956)))
	sect.Set("TranslucentConsole", strconv.Itoa(bool2int(guiCon.translucent)))
	sect.Set("RenderGlow", strconv.Itoa(bool2int(noxClient.r.renderGlow)))
	sect.Set("RenderGUI", strconv.Itoa(int(C.nox_client_renderGUI_80828)))
	sect.Set("FadeObjects", strconv.Itoa(int(C.nox_client_fadeObjects_80836)))
	sect.Set("RenderBubbles", strconv.Itoa(int(C.nox_client_renderBubbles_80844)))
	sect.Set("TrackData", strconv.Itoa(int(sub_578DF0())))
	sect.Set("SysopPassword", GoWString(C.nox_xxx_sysopGetPass_40A630()))
	sect.Set("ServerPassword", GoWString((*wchar_t)(unsafe.Pointer(&v1[78]))))
	sect.Set("Profiled", strconv.Itoa(bool2int(legacyProfiled != 0)))
	sect.Set("SanctuaryHelp", strconv.Itoa(int(C.nox_server_sanctuaryHelp_54276)))
	sect.Set("MaxPacketLossPct", strconv.Itoa(int(memmap.Uint32(0x587000, 81280))))
	sect.Set("SendMessageOfTheDay", strconv.Itoa(int(C.nox_server_sendMotd_108752)))
	sect.Set("MapCycle", strconv.Itoa(int(C.sub_4D0D70())))
	sect.Set("ConnectionType", strconv.Itoa(int(C.nox_server_connectionType_3596)))
	sect.Set("InternetUpdateRate", strconv.Itoa(int(C.nox_xxx_rateGet_40A6C0())))
	sect.Set("LessonLimit", sub_4337B0())
	sect.Set("TimeLimit", sub_433820())
	sect.Set("PlayerSkeletons", strconv.Itoa(int(*(*uint32)(unsafe.Pointer(&v1[58])))))
	sect.Set("BroadcastGestures", strconv.Itoa(int(*(*uint32)(unsafe.Pointer(&v1[62])))))
	sect.Set("LatencyCompensation", fmt.Sprintf("%d %d", *(*uint32)(unsafe.Pointer(&v1[66])), *(*uint32)(unsafe.Pointer(&v1[70]))))
	sect.Set("Closed", strconv.Itoa(bool2int((v1[100]>>4)&0x1 != 0)))
	sect.Set("Private", strconv.Itoa(bool2int((v1[100]>>5)&0x1 != 0)))
	sect.Set("AudioThreshold", strconv.Itoa(int(*(*uint32)(unsafe.Pointer(&v1[74])))))
	sect.Set("MaxPlayers", strconv.Itoa(noxServer.getServerMaxPlayers()))
	sect.Set("RestrictedClasses", strconv.Itoa(int(v1[100]&0x7)))
	sect.Set("RestrictedPing", fmt.Sprintf("%d %d", *(*uint16)(unsafe.Pointer(&v1[105])), *(*uint16)(unsafe.Pointer(&v1[107]))))
	sect.Set("LimitMaxRes", strconv.Itoa(int(v1[102]>>7)))
	sect.Set("CamperAlarm", strconv.Itoa(bool2int((C.nox_xxx_getServerSubFlags_409E60()>>13)&0x1 != 0)))
	sect.Set("ItemRespawn", strconv.Itoa(int(C.sub_409F40(2))))
	sect.Set("MinKickVotes", strconv.Itoa(int(memmap.Uint32(0x587000, 229980))))
	sect.Set("ResetQuestMinVotes", strconv.Itoa(int(C.nox_server_resetQuestMinVotes_229988)))
	sect.Set("KickQuestPlayerMinVotes", strconv.Itoa(int(C.nox_server_kickQuestPlayerMinVotes_229992)))

	v16, arr := sub_48A020(0)
	sect.Set("LANFilters", fmt.Sprintf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		v16, arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], arr[10],
	))
	v16, arr = sub_48A020(1)
	sect.Set("INETFilters", fmt.Sprintf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
		int(v16), arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9], arr[10],
	))
	for _, ci := range configCycleIndexes {
		sect.Set(ci.Name, strconv.Itoa(int(C.sub_4D0DE0(C.int(ci.Flags)))))
	}
}

func sub_48A020(ind int) (int, []int32) {
	v := int(memmap.Uint32(0x5D4594, 1193372+4*uintptr(ind)))
	arr := unsafe.Slice((*int32)(memmap.PtrOff(0x5D4594, 1193388+44*uintptr(ind))), 11)
	return v, arr
}

func sub_4337B0() string {
	var arr []string
	for _, m := range configModeCodes {
		arr = append(arr, strconv.Itoa(int(C.nox_xxx_servGamedataGet_40A020(C.short(m)))))
	}
	return strings.Join(arr, ",")
}

func sub_433820() string {
	var arr []string
	for _, m := range configModeCodes {
		arr = append(arr, strconv.Itoa(int(C.sub_40A180(C.short(m)))))
	}
	return strings.Join(arr, ",")
}

func sub_433890() string {
	name := noxServer.getServerName()
	name = strings.ReplaceAll(name, " ", "_")
	return name
}
