package noxflags

import (
	"encoding/json"
	"fmt"
	"math/bits"
	"strconv"
	"strings"
)

var (
	engine       EngineFlag
	engineByName = make(map[string]EngineFlag)
)

func init() {
	cur := EngineFlag(1)
	for i := 0; i < 32; i++ {
		engineByName[cur.String()] = cur
		cur <<= 1
	}
}

const (
	EngineFlag1            = EngineFlag(1 << 0)
	EngineShowExtents      = EngineFlag(1 << 1)
	EngineFlag3            = EngineFlag(1 << 2)
	EngineShowAI           = EngineFlag(1 << 3)
	EngineAdmin            = EngineFlag(1 << 4)
	EngineGodMode          = EngineFlag(1 << 5)
	EngineFlag7            = EngineFlag(1 << 6)
	EngineFlag8            = EngineFlag(1 << 7)
	EngineFlag9            = EngineFlag(1 << 8)
	EngineWindowed         = EngineFlag(1 << 9)
	EngineSoftShadowEdge   = EngineFlag(1 << 10)
	EngineNoSoftLights     = EngineFlag(1 << 11)
	EngineGameLoopMemdump  = EngineFlag(1 << 12)
	EngineFlag14           = EngineFlag(1 << 13)
	EngineFlag15           = EngineFlag(1 << 14)
	EngineNetDebug         = EngineFlag(1 << 15)
	EngineNoTextRendering  = EngineFlag(1 << 16)
	EngineFlag18           = EngineFlag(1 << 17)
	EngineNoRendering      = EngineFlag(1 << 18)
	EngineFlag20           = EngineFlag(1 << 19)
	EngineNoFloorRendering = EngineFlag(1 << 20)
	EngineReplayWrite      = EngineFlag(1 << 21)
	EngineReplayRead       = EngineFlag(1 << 22)
	EngineLogToFile        = EngineFlag(1 << 23)
	EngineLogToConsole     = EngineFlag(1 << 24)
	EngineLockResolution   = EngineFlag(1 << 25)
	EngineFlag27           = EngineFlag(1 << 26)
	EngineSaveDebug        = EngineFlag(1 << 27)
	EngineAddNetworkTest   = EngineFlag(1 << 28)
	EngineLogBand          = EngineFlag(1 << 29)
	EngineSleep            = EngineFlag(1 << 30)
	EnginePause            = EngineFlag(1 << 31)
)

var (
	_ json.Marshaler   = EngineFlag(0)
	_ json.Unmarshaler = (*EngineFlag)(nil)
)

func ParseEngineFlag(s string) (EngineFlag, error) {
	if strings.Contains(s, ",") {
		var out EngineFlag
		for _, s := range strings.Split(s, ",") {
			v, err := ParseEngineFlag(s)
			if err != nil {
				return out, err
			}
			out |= v
		}
		return out, nil
	} else if strings.Contains(s, "|") {
		var out EngineFlag
		for _, s := range strings.Split(s, "|") {
			v, err := ParseEngineFlag(s)
			if err != nil {
				return out, err
			}
			out |= v
		}
		return out, nil
	}
	if v, ok := engineByName[s]; ok {
		return v, nil
	}
	s = strings.TrimPrefix(s, "Engine")
	if v, ok := engineByName[s]; ok {
		return v, nil
	}
	v, err := strconv.ParseUint(s, 0, 32)
	if err != nil {
		return 0, fmt.Errorf("cannot parse game flag: %q", s)
	}
	return EngineFlag(v), nil
}

type EngineFlag uint

func (f *EngineFlag) UnmarshalJSON(p []byte) error {
	var arr []string
	err := json.Unmarshal(p, &arr)
	if err == nil {
		*f = 0
		for _, s := range arr {
			v, err := ParseEngineFlag(s)
			if err != nil {
				return err
			}
			*f |= v
		}
		return nil
	}
	var v uint32
	if err2 := json.Unmarshal(p, &v); err2 != nil {
		return err
	}
	*f = EngineFlag(v)
	return nil
}

func (f EngineFlag) MarshalJSON() ([]byte, error) {
	return json.Marshal(f.SplitString())
}

func (f EngineFlag) GoString() string {
	switch f {
	case EngineFlag1:
		return pkg + ".EngineFlag1"
	case EngineShowExtents:
		return pkg + ".EngineShowExtents"
	case EngineFlag3:
		return pkg + ".EngineFlag3"
	case EngineShowAI:
		return pkg + ".EngineShowAI"
	case EngineAdmin:
		return pkg + ".EngineAdmin"
	case EngineGodMode:
		return pkg + ".EngineGodMode"
	case EngineFlag7:
		return pkg + ".EngineFlag7"
	case EngineFlag8:
		return pkg + ".EngineFlag8"
	case EngineFlag9:
		return pkg + ".EngineFlag9"
	case EngineWindowed:
		return pkg + ".EngineWindowed"
	case EngineSoftShadowEdge:
		return pkg + ".EngineSoftShadowEdge"
	case EngineNoSoftLights:
		return pkg + ".EngineNoSoftLights"
	case EngineGameLoopMemdump:
		return pkg + ".EngineGameLoopMemdump"
	case EngineFlag14:
		return pkg + ".EngineFlag14"
	case EngineFlag15:
		return pkg + ".EngineFlag15"
	case EngineNetDebug:
		return pkg + ".EngineNetDebug"
	case EngineNoTextRendering:
		return pkg + ".EngineNoTextRendering"
	case EngineFlag18:
		return pkg + ".EngineFlag18"
	case EngineNoRendering:
		return pkg + ".EngineNoRendering"
	case EngineFlag20:
		return pkg + ".EngineFlag20"
	case EngineNoFloorRendering:
		return pkg + ".EngineNoFloorRendering"
	case EngineReplayWrite:
		return pkg + ".EngineReplayWrite"
	case EngineReplayRead:
		return pkg + ".EngineReplayRead"
	case EngineLogToFile:
		return pkg + ".EngineLogToFile"
	case EngineLogToConsole:
		return pkg + ".EngineLogToConsole"
	case EngineLockResolution:
		return pkg + ".EngineLockResolution"
	case EngineFlag27:
		return pkg + ".EngineFlag27"
	case EngineSaveDebug:
		return pkg + ".EngineSaveDebug"
	case EngineAddNetworkTest:
		return pkg + ".EngineAddNetworkTest"
	case EngineLogBand:
		return pkg + ".EngineLogBand"
	case EngineSleep:
		return pkg + ".EngineSleep"
	case EnginePause:
		return pkg + ".EnginePause"
	}
	if bits.OnesCount(uint(f)) == 1 {
		return fmt.Sprintf(pkg+".EngineFlag(0x%x)", uint(f))
	}
	return strings.Join(f.SplitGoString(), " | ")
}

func (f EngineFlag) String() string {
	switch f {
	case EngineFlag1:
		return "Flag1"
	case EngineShowExtents:
		return "ShowExtents"
	case EngineFlag3:
		return "Flag3"
	case EngineShowAI:
		return "ShowAI"
	case EngineAdmin:
		return "Admin"
	case EngineGodMode:
		return "GodMode"
	case EngineFlag7:
		return "Flag7"
	case EngineFlag8:
		return "Flag8"
	case EngineFlag9:
		return "Flag9"
	case EngineWindowed:
		return "Windowed"
	case EngineSoftShadowEdge:
		return "SoftShadowEdge"
	case EngineNoSoftLights:
		return "NoSoftLights"
	case EngineGameLoopMemdump:
		return "GameLoopMemdump"
	case EngineFlag14:
		return "Flag14"
	case EngineFlag15:
		return "Flag15"
	case EngineNetDebug:
		return "NetDebug"
	case EngineNoTextRendering:
		return "NoTextRendering"
	case EngineFlag18:
		return "Flag18"
	case EngineNoRendering:
		return "NoRendering"
	case EngineFlag20:
		return "Flag20"
	case EngineNoFloorRendering:
		return "NoFloorRendering"
	case EngineReplayWrite:
		return "ReplayWrite"
	case EngineReplayRead:
		return "ReplayRead"
	case EngineLogToFile:
		return "LogToFile"
	case EngineLogToConsole:
		return "LogToConsole"
	case EngineLockResolution:
		return "LockResolution"
	case EngineFlag27:
		return "Flag27"
	case EngineSaveDebug:
		return "SaveDebug"
	case EngineAddNetworkTest:
		return "AddNetworkTest"
	case EngineLogBand:
		return "LogBand"
	case EngineSleep:
		return "Sleep"
	case EnginePause:
		return "Pause"
	}
	if bits.OnesCount(uint(f)) == 1 {
		return fmt.Sprintf("EngineFlag(0x%x)", uint(f))
	}
	return strings.Join(f.SplitString(), " | ")
}

func (f EngineFlag) Split() []EngineFlag {
	var (
		list []EngineFlag
		cur  = EngineFlag(1)
	)
	for f != 0 {
		if f&0x1 != 0 {
			list = append(list, cur)
		}
		cur <<= 1
		f >>= 1
	}
	return list
}

func (f EngineFlag) SplitGoString() []string {
	var arr []string
	for _, v := range f.Split() {
		arr = append(arr, v.GoString())
	}
	return arr
}

func (f EngineFlag) SplitString() []string {
	var arr []string
	for _, v := range f.Split() {
		arr = append(arr, v.String())
	}
	return arr
}

// Has checks if one of the flags is set.
func (f EngineFlag) Has(f2 EngineFlag) bool {
	return f&f2 != 0
}

// HasAll checks if all of the flags are set.
func (f EngineFlag) HasAll(f2 EngineFlag) bool {
	return f&f2 == f2
}

// GetEngine returns all engine flags.
func GetEngine() EngineFlag {
	return engine
}

// ResetEngine resets all engine flags.
func ResetEngine() {
	engine = 0
}

// HasEngine check if one of the engine flags is set.
func HasEngine(f EngineFlag) bool {
	return engine.Has(f)
}

// SetEngine sets one or more engine flags.
func SetEngine(f EngineFlag) {
	if engine&f == f {
		return // already set
	}
	engine |= f
}

// UnsetEngine resets one or more engine flags.
func UnsetEngine(f EngineFlag) {
	if engine&f == 0 {
		return // already unset
	}
	engine &= ^f
}

// ToggleEngine toggles one or more engine flags.
func ToggleEngine(f EngineFlag) {
	for _, fl := range f.Split() {
		if HasEngine(fl) {
			UnsetEngine(fl)
		} else {
			SetEngine(fl)
		}
	}
}
