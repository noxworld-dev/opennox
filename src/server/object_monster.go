package server

import (
	"fmt"
	"image/color"
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/object"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
	"github.com/noxworld-dev/opennox/v1/legacy/common/ccall"
)

type AIStackItem struct {
	Action ai.ActionType // 0, 0
	Args   [4]uintptr    // 1, 4 (8, 12, 16)
	Field5 uint32        // 5, 20
}

func (s *AIStackItem) Type() ai.ActionType {
	if s == nil {
		return ai.ACTION_INVALID
	}
	return s.Action
}

func (s *AIStackItem) ArgU32(i int) uint32 {
	return uint32(s.Args[i])
}

func (s *AIStackItem) ArgF32(i int) float32 {
	return math.Float32frombits(uint32(s.Args[i]))
}

func (s *AIStackItem) ArgPos(i int) types.Pointf {
	return types.Pointf{
		X: math.Float32frombits(uint32(s.Args[i+0])),
		Y: math.Float32frombits(uint32(s.Args[i+1])),
	}
}

func (s *AIStackItem) SetArgs(args ...any) {
	if s == nil {
		return
	}
	off := 0
	for _, v := range args {
		switch v := v.(type) {
		case int:
			s.Args[off] = uintptr(uint32(int32(v)))
		case uint:
			s.Args[off] = uintptr(uint32(v))
		case int32:
			s.Args[off] = uintptr(uint32(v))
		case uint32:
			s.Args[off] = uintptr(v)
		case unsafe.Pointer:
			s.Args[off] = uintptr(v)
		case float32:
			s.Args[off] = uintptr(math.Float32bits(v))
		case Obj:
			s.Args[off] = uintptr(v.SObj().CObj())
		case types.Pointf:
			s.Args[off+0] = uintptr(math.Float32bits(v.X))
			s.Args[off+1] = uintptr(math.Float32bits(v.Y))
			off++
		default:
			panic(fmt.Errorf("unsupported arg: %T", v))
		}
		off++
	}
}

func AsColor3(cl color.Color) Color3 {
	switch cl := cl.(type) {
	case color.Alpha:
		if cl.A < 128 {
			return Color3{}
		}
		return Color3{R: 255, G: 255, B: 255}
	case color.NRGBA:
		if cl.A < 128 {
			return Color3{}
		}
		return Color3{R: cl.R, G: cl.G, B: cl.B}
	case color.RGBA:
		if cl.A < 128 {
			return Color3{}
		}
		return Color3{R: cl.R, G: cl.G, B: cl.B}
	case color.Gray:
		return Color3{R: cl.Y, G: cl.Y, B: cl.Y}
	}
	r, g, b, _ := cl.RGBA()
	return Color3{
		R: byte(r >> 16),
		G: byte(g >> 16),
		B: byte(b >> 16),
	}
}

type Color3 struct {
	R, G, B byte
}

type MonsterUpdateData struct {
	Field0                uint32               // 0, 0
	Field1                uint32               // 1, 4
	Field2                uint32               // 2, 8
	Field3                uint32               // 3, 12
	Field4                uint32               // 4, 16
	Field5                uint32               // 5, 20
	Field6                uint32               // 6, 24
	Field7                uint32               // 7, 28
	Field8                uint32               // 8, 32
	Field9                uint32               // 9, 36
	Field10               uint32               // 10, 40
	Field11               uint32               // 11, 44
	Field12               uint32               // 12, 48
	Field13               uint32               // 13, 52
	Field14               uint32               // 14, 56
	Field15               uint32               // 15, 60
	Field16               uint32               // 16, 64
	Field17               uint32               // 17, 68
	Field18               uint32               // 18, 72
	Field19               uint32               // 19, 76
	Field20               uint32               // 20, 80
	Field21               uint32               // 21, 84
	Field22               uint32               // 22, 88
	Field23               uint32               // 23, 92
	Field24               uint32               // 24, 96
	Field25               uint32               // 25, 100
	Field26               uint32               // 26, 104
	Field27               uint32               // 27, 108
	Field28               uint32               // 28, 112
	Field29               uint32               // 29, 116
	Field30               uint32               // 30, 120
	Field31               uint32               // 31, 124
	Field32               uint32               // 32, 128
	Field33               uint32               // 33, 132
	Field34               uint32               // 34, 136
	Field35               uint32               // 35, 140
	Field36               uint32               // 36, 144
	Field37               uint32               // 37, 148
	Field38               uint32               // 38, 152
	Field39               uint32               // 39, 156
	Field40               uint32               // 40, 160
	Field41               uint32               // 41, 164
	Field42               uint32               // 42, 168
	Field43               uint32               // 43, 172
	Field44               uint32               // 44, 176
	Field45               uint32               // 45, 180
	Field46               uint32               // 46, 184
	Field47               uint32               // 47, 188
	Field48               uint32               // 48, 192
	Field49               uint32               // 49, 196
	Field50               uint32               // 50, 200
	Field51               uint32               // 51, 204
	Field52               uint32               // 52, 208
	Field53               uint32               // 53, 212
	Field54               uint32               // 54, 216
	Field55               uint32               // 55, 220
	Field56               uint32               // 56, 224
	Field57               uint32               // 57, 228
	Field58               uint32               // 58, 232
	Field59               uint32               // 59, 236
	Field60               uint32               // 60, 240
	Field61               uint32               // 61, 244
	Field62               uint32               // 62, 248
	Field63               uint32               // 63, 252
	Field64               uint32               // 64, 256
	Field65               uint32               // 65, 260
	Field66               uint32               // 66, 264
	Field67               uint32               // 67, 268
	Field68               uint32               // 68, 272
	Field69               uint32               // 69, 276
	Field70               uint32               // 70, 280
	Field71               uint32               // 71, 284
	Field72               uint32               // 72, 288
	Field73               uint32               // 73, 292
	Field74               uint32               // 74, 296
	Field75               uint32               // 75, 300
	Field76               uint32               // 76, 304
	Field77               uint32               // 77, 308
	Field78               uint32               // 78, 312
	Field79               uint32               // 79, 316
	Field80               uint32               // 80, 320
	Field81               uint32               // 81, 324
	Field82               uint32               // 82, 328
	Field83               uint32               // 83, 332
	Field84               uint32               // 84, 336
	Field85               uint32               // 85, 340
	Field86               uint32               // 86, 344
	Field87               uint32               // 87, 348
	Field88               uint32               // 88, 352
	Field89               uint32               // 89, 356
	Field90               uint32               // 90, 360
	Field91               uint32               // 91, 364
	Field92               uint32               // 92, 368
	Field93               uint32               // 93, 372
	Direction94           uint32               // 94, 376
	Pos95                 types.Pointf         // 95, 380
	Field97               uint32               // 97, 388, TODO: hear sound ind
	Field98               uint32               // 98, 392, TODO: some frame/timestamp
	Field99X              float32              // 99, 396
	Field99Y              float32              // 100, 400
	Field101              uint32               // 101, 404, TODO: hear frame/timestamp
	Field102              uint32               // 102, 408, TODO: hear distance
	HealthGraph103        [32]uint16           // 103, 412
	Field119              *[16]MonsterAnim     // 119, 476
	Field120_0            uint8                // 120, 480
	Field120_1            uint8                // 120, 481
	Field120_2            uint8                // 120, 482
	Field120_3            uint8                // 120, 483
	MonsterDef            *MonsterDef          // 121, 484
	SoundSet122           unsafe.Pointer       // 122, 488
	Field123              uint32               // 123, 492
	Field124              uint32               // 124, 496
	Field125              types.Pointf         // 125, 500
	Field127              uint32               // 127, 508
	Field128              uint32               // 128, 512
	Field129              uint32               // 129, 516, TODO: some timestamp
	Field130              uint32               // 130, 520
	Field131              uint32               // 131, 524
	Field132              uint32               // 132, 528
	Field133              uint32               // 133, 532
	Field134              uint32               // 134, 536
	Field135              uint32               // 135, 540
	AIStackInd            int8                 // 136, 544
	Field136_1            uint8                // 136, 545
	Field136_2            uint16               // 136, 546
	Field137              uint32               // 137, 548
	AIStack               [24]AIStackItem      // 138, 552
	Field282_0            uint8                // 282, 1128, TODO: current stamina?
	Field282_1            uint8                // 282, 1129
	Field282_2            uint16               // 282, 1130
	Field283              uint32               // 283, 1132
	Field284              uint32               // 284, 1136
	Field285              uint32               // 285, 1140
	Field286              uint32               // 286, 1144
	Field287              uint32               // 287, 1148
	Field288              uint32               // 288, 1152
	Field289              uint32               // 289, 1156
	Field290              uint32               // 290, 1160
	Field291              uint32               // 291, 1164
	Field292              uint32               // 292, 1168
	Field293              uint32               // 293, 1172
	Field294              uint32               // 294, 1176
	Field295              uint32               // 295, 1180
	Field296              uint32               // 296, 1184
	Field297              uint32               // 297, 1188
	Field298              uint32               // 298, 1192
	CurrentEnemy          *Object              // 299, 1196
	Field300              uint32               // 300, 1200
	Field301              uint32               // 301, 1204
	Field302              uint32               // 302, 1208
	Field303              uint32               // 303, 1212
	Field304              *Object              // 304, 1216
	Field305              uint32               // 305, 1220
	ScriptLookingForEnemy ScriptCallback       // 306, 1224
	ScriptEnemySighted    ScriptCallback       // 308, 1232
	ScriptChangeFocus     ScriptCallback       // 310, 1240
	ScriptIsHit           ScriptCallback       // 312, 1248
	ScriptRetreat         ScriptCallback       // 314, 1256
	ScriptDeath           ScriptCallback       // 316, 1264
	ScriptCollision       ScriptCallback       // 318, 1272
	ScriptHearEnemy       ScriptCallback       // 320, 1280
	ScriptEndOfWaypoint   ScriptCallback       // 322, 1288
	ScriptLostEnemy       ScriptCallback       // 324, 1296
	Aggression            float32              // 326, 1304
	Aggression2           float32              // 327, 1308
	Field328              float32              // 328, 1312
	Field329              float32              // 329, 1316
	Field330              float32              // 330, 1320
	Field331              uint32               // 331, 1324, TODO: strength stat?
	Field332              float32              // 332, 1328, TODO: speed stat?
	Field333              uint32               // 333, 1332, TODO: roam flags?
	RetreatLevel          float32              // 334, 1336
	Field335              uint32               // 335, 1340
	ResumeLevel           float32              // 336, 1344
	Field337              uint32               // 337, 1348
	Field338              float32              // 338, 1352, TODO: something health-related
	FleeRange             float32              // 339, 1356
	AIAction340           uint32               // 340, 1360
	Field341              uint32               // 341, 1364
	Field342              uint32               // 342, 1368
	Field343              uint32               // 343, 1372
	Field344              uint32               // 344, 1376
	Field345              uint32               // 345, 1380
	Field346              uint32               // 346, 1384
	Field347              uint32               // 347, 1388
	Field348              uint32               // 348, 1392
	Field349              uint32               // 349, 1396
	Field350              uint32               // 350, 1400
	Field351              uint32               // 351, 1404
	Field352              uint32               // 352, 1408
	Field353              uint32               // 353, 1412
	Field354              uint32               // 354, 1416
	Field355              uint32               // 355, 1420
	Field356              uint32               // 356, 1424
	Field357              uint32               // 357, 1428
	Field358              uint32               // 358, 1432
	Field359              uint32               // 359, 1436
	StatusFlags           object.MonsterStatus // 360, 1440
	Field361              uint32               // 361, 1444
	Field362_0            uint16               // 362, 1448
	Field362_2            uint16               // 362, 1450
	Field363              uint32               // 363, 1452
	Field364_0            uint16               // 364, 1456
	Field364_2            uint16               // 364, 1458
	Field365              uint32               // 365, 1460
	Field366_0            uint16               // 366, 1464
	Field366_2            uint16               // 366, 1466
	Field367              uint32               // 367, 1468
	Field368_0            uint16               // 368, 1472
	Field368_2            uint16               // 368, 1474
	Field369              uint32               // 369, 1476
	Field370_0            uint16               // 370, 1480
	Field370_2            uint16               // 370, 1482
	Field371              uint32               // 371, 1484
	Field372              uint32               // 372, 1488
	Field373              uint32               // 373, 1492
	Field374              uint32               // 374, 1496
	Field375              uint32               // 375, 1500
	Field376              float32              // 376, 1504
	Field377              uint32               // 377, 1508
	Field378              uint32               // 378, 1512
	Field379              uint32               // 379, 1516
	Field380              uint32               // 380, 1520
	Field381              uint32               // 381, 1524
	Field382              uint32               // 382, 1528
	Field383              uint32               // 383, 1532
	Field384              uint32               // 384, 1536
	Field385              uint32               // 385, 1540
	Field386              uint32               // 386, 1544
	Field387              uint32               // 387, 1548
	Field388              uint32               // 388, 1552
	Field389              uint32               // 389, 1556
	Field390              uint32               // 390, 1560
	Field391              uint32               // 391, 1564
	Field392              uint32               // 392, 1568
	Field393              uint32               // 393, 1572
	Field394              uint32               // 394, 1576
	Field395              uint32               // 395, 1580
	Field396              uint32               // 396, 1584
	Field397              uint32               // 397, 1588
	Field398              uint32               // 398, 1592
	Field399              uint32               // 399, 1596
	Field400              uint32               // 400, 1600
	Field401              uint32               // 401, 1604
	Field402              uint32               // 402, 1608
	Field403              uint32               // 403, 1612
	Field404              uint32               // 404, 1616
	Field405              uint32               // 405, 1620
	Field406              uint32               // 406, 1624
	Field407              uint32               // 407, 1628
	Field408              uint32               // 408, 1632
	Field409              uint32               // 409, 1636
	Field410              uint32               // 410, 1640
	Field411              uint32               // 411, 1644
	Field412              uint32               // 412, 1648
	Field413              uint32               // 413, 1652
	Field414              uint32               // 414, 1656
	Field415              uint32               // 415, 1660
	Field416              uint32               // 416, 1664
	Field417              uint32               // 417, 1668
	Field418              uint32               // 418, 1672
	Field419              uint32               // 419, 1676
	Field420              uint32               // 420, 1680
	Field421              uint32               // 421, 1684
	Field422              uint32               // 422, 1688
	Field423              uint32               // 423, 1692
	Field424              uint32               // 424, 1696
	Field425              uint32               // 425, 1700
	Field426              uint32               // 426, 1704
	Field427              uint32               // 427, 1708
	Field428              uint32               // 428, 1712
	Field429              uint32               // 429, 1716
	Field430              uint32               // 430, 1720
	Field431              uint32               // 431, 1724
	Field432              uint32               // 432, 1728
	Field433              uint32               // 433, 1732
	Field434              uint32               // 434, 1736
	Field435              uint32               // 435, 1740
	Field436              uint32               // 436, 1744
	Field437              uint32               // 437, 1748
	Field438              uint32               // 438, 1752
	Field439              uint32               // 439, 1756
	Field440              uint32               // 440, 1760
	Field441              uint32               // 441, 1764
	Field442              uint32               // 442, 1768
	Field443              uint32               // 443, 1772
	Field444              uint32               // 444, 1776
	Field445              uint32               // 445, 1780
	Field446              uint32               // 446, 1784
	Field447              uint32               // 447, 1788
	Field448              uint32               // 448, 1792
	Field449              uint32               // 449, 1796
	Field450              uint32               // 450, 1800
	Field451              uint32               // 451, 1804
	Field452              uint32               // 452, 1808
	Field453              uint32               // 453, 1812
	Field454              uint32               // 454, 1816
	Field455              uint32               // 455, 1820
	Field456              uint32               // 456, 1824
	Field457              uint32               // 457, 1828
	Field458              uint32               // 458, 1832
	Field459              uint32               // 459, 1836
	Field460              uint32               // 460, 1840
	Field461              uint32               // 461, 1844
	Field462              uint32               // 462, 1848
	Field463              uint32               // 463, 1852
	Field464              uint32               // 464, 1856
	Field465              uint32               // 465, 1860
	Field466              uint32               // 466, 1864
	Field467              uint32               // 467, 1868
	Field468              uint32               // 468, 1872
	Field469              uint32               // 469, 1876
	Field470              uint32               // 470, 1880
	Field471              uint32               // 471, 1884
	Field472              uint32               // 472, 1888
	Field473              uint32               // 473, 1892
	Field474              uint32               // 474, 1896
	Field475              uint32               // 475, 1900
	Field476              uint32               // 476, 1904
	Field477              uint32               // 477, 1908
	Field478              uint32               // 478, 1912
	Field479              uint32               // 479, 1916
	Field480              uint32               // 480, 1920
	Field481              uint32               // 481, 1924
	Field482              uint32               // 482, 1928
	Field483              uint32               // 483, 1932
	Field484              uint32               // 484, 1936
	Field485              uint32               // 485, 1940
	Field486              uint32               // 486, 1944
	Field487              uint32               // 487, 1948
	Field488              uint32               // 488, 1952
	Field489              uint32               // 489, 1956
	Field490              uint32               // 490, 1960
	Field491              uint32               // 491, 1964
	Field492              uint32               // 492, 1968
	Field493              uint32               // 493, 1972
	Field494              uint32               // 494, 1976
	Field495              uint32               // 495, 1980
	Field496              uint32               // 496, 1984
	Field497              uint32               // 497, 1988
	Field498              uint32               // 498, 1992
	Field499              uint32               // 499, 1996
	Field500              uint32               // 500, 2000
	Field501              uint32               // 501, 2004
	Field502              uint32               // 502, 2008
	Field503              uint32               // 503, 2012
	Field504              uint32               // 504, 2016
	Field505              uint32               // 505, 2020
	Field506              uint32               // 506, 2024
	Field507              uint32               // 507, 2028
	Field508              uint32               // 508, 2032
	Field509              uint32               // 509, 2036
	Field510              uint32               // 510, 2040
	Field511              uint32               // 511, 2044
	Field512              uint32               // 512, 2048
	Field513              uint32               // 513, 2052
	Field514              uint32               // 514, 2056, TODO: weapon damage type?
	Field515              uint32               // 515, 2060
	Field516              uint32               // 516, 2064
	Field517              uint32               // 517, 2068
	Field518              uint32               // 518, 2072
	Color                 [6]Color3            // 519, 2076
	Field523_2            uint8                // 523, 2094
	Field523_3            uint8                // 523, 2095
	DialogStartFunc       int32                // 524, 2096
	DialogEndFunc         int32                // 525, 2100
	DialogFlags           byte                 // 526, 2104
	DialogResult          byte                 // 526, 2105
	DialogPortraitBuf     [30]byte             // 526, 2106, TODO: size is a wild guess
	Field534              uint32               // 534, 2136
	Field535              uint32               // 535, 2140
	Field536              uint32               // 536, 2144
	Field537              uint32               // 537, 2148
	Field538              uint32               // 538, 2152
	Field539              uint32               // 539, 2156
	Field540              uint32               // 540, 2160
	Field541              uint32               // 541, 2164
	Field542              uint32               // 542, 2168
	Field543              uint32               // 543, 2172
	Field544              *Object              // 544, 2176, TODO: correct type?
	UpdateDataBot         *PlayerUpdateData    // 545, 2180
	Field546              uint32               // 546, 2184
	Field547              uint32               // 547, 2188
	Field548              *Object              // 548, 2192
	Field549              uint32               // 549, 2196
}

func (ud *MonsterUpdateData) GetAIStack() []AIStackItem {
	ind := ud.AIStackInd
	if ind < 0 {
		return nil
	}
	return ud.AIStack[:ind+1]
}

func (ud *MonsterUpdateData) AIStackHead() *AIStackItem {
	ind := ud.AIStackInd
	if ind < 0 {
		return nil
	}
	return &ud.AIStack[ind]
}

func (ud *MonsterUpdateData) PrintAIStack(frame uint32, event string) {
	ai.Log.Printf("%d: stack (%s):\n", frame, event)
	defer ai.Log.Println("----------------------------------------")
	stack := ud.GetAIStack()
	if len(stack) == 0 {
		return
	}
	for i := len(stack) - 1; i >= 0; i-- {
		typ := stack[i].Type()
		ai.Log.Printf("  %s", typ.String())
	}
}

func (ud *MonsterUpdateData) SetAggression(v float32) {
	ud.Aggression = v
	ud.Aggression2 = v
}

func (ud *MonsterUpdateData) DialogPortrait() string {
	return alloc.GoStringS(ud.DialogPortraitBuf[:])
}

func (ud *MonsterUpdateData) HasAction(act ai.ActionType) bool { // nox_xxx_checkMobAction_50A0D0
	if ud == nil {
		return false
	}
	for i := ud.AIStackInd; i >= 0; i-- {
		if ud.AIStack[i].Type() == act {
			return true
		}
	}
	return false
}

type MonMeleeAttackFunc func(obj *Object) int32

type MonsterDef struct {
	Name0                        [64]byte                       // 0, 0, TODO: size is a guess
	Experience64                 uint32                         // 16, 64
	Health68                     uint32                         // 17, 68
	HealthQuest72                uint32                         // 18, 72
	Speed76                      uint32                         // 19, 76
	RetreatRatio80               float32                        // 20, 80
	ResumeRatio84                float32                        // 21, 84
	FleeRange88                  float32                        // 22, 88
	StatusFlags92                object.MonsterStatus           // 23, 92
	RunMultiplier96              float32                        // 24, 96
	MoveSndFrameA100             uint32                         // 25, 100
	MoveSndFrameB104             uint32                         // 26, 104
	MeleeAttackFrame108          uint32                         // 27, 108
	MeleeAttackRange112          float32                        // 28, 112
	MeleeAttackDamage116         uint32                         // 29, 116
	MeleeAttackImpact120         float32                        // 30, 120
	MeleeAttackDamageType124     uint32                         // 31, 124
	MeleeAttackDelayMin128       uint32                         // 32, 128
	MeleeAttackDelayMax132       uint32                         // 33, 132
	MeleeAttackPoisonChange136   uint32                         // 34, 136
	MeleeAttackPoisonStrength140 uint32                         // 35, 140
	MeleeAttackPoisonMax144      uint32                         // 36, 144
	MissileName148               [64]byte                       // 37, 148, TODO: size is a guess
	MissileAttackRange212        float32                        // 53, 212
	MissileAttackFrame216        uint32                         // 54, 216
	MissileAttackDelayMin220     uint32                         // 55, 220
	MissileAttackDelayMax224     uint32                         // 56, 224
	DieFunc228                   unsafe.Pointer                 // 57, 228
	DeadFunc232                  unsafe.Pointer                 // 58, 232
	MeleeStrikeFunc236           ccall.Func[MonMeleeAttackFunc] // 59, 236
	TypeInd240                   uint32                         // 60, 240
	Next244                      *MonsterDef                    // 61, 244
}

type monsterFieldKind int

const (
	monsterFieldInt        = monsterFieldKind(0)
	monsterFieldFloat      = monsterFieldKind(1)
	monsterFieldSound      = monsterFieldKind(2)
	monsterFieldStrikeFunc = monsterFieldKind(3)
	monsterFieldDieFunc    = monsterFieldKind(4)
	monsterFieldDeadFunc   = monsterFieldKind(5)
	monsterFieldStatus     = monsterFieldKind(6)
	monsterFieldString     = monsterFieldKind(7)
	monsterFieldDamageType = monsterFieldKind(8)
)

type monsterDefField struct {
	Name string
	Kind monsterFieldKind
	Off  int
}

var monsterDefFields = []monsterDefField{
	{Name: "EXPERIENCE", Kind: monsterFieldInt, Off: 64},
	{Name: "HEALTH", Kind: monsterFieldInt, Off: 68},
	{Name: "SPEED", Kind: monsterFieldInt, Off: 76},
	{Name: "RUN_MULTIPLIER", Kind: monsterFieldFloat, Off: 96},
	{Name: "RETREAT_RATIO", Kind: monsterFieldFloat, Off: 80},
	{Name: "RESUME_RATIO", Kind: monsterFieldFloat, Off: 84},
	{Name: "STATUS", Kind: monsterFieldStatus, Off: 92},
	{Name: "MOVE_SOUND_FRAME_A", Kind: monsterFieldInt, Off: 100},
	{Name: "MOVE_SOUND_FRAME_B", Kind: monsterFieldInt, Off: 104},
	{Name: "FLEE_RANGE", Kind: monsterFieldFloat, Off: 88},
	{Name: "MELEE_ATTACK_DAMAGE", Kind: monsterFieldInt, Off: 116},
	{Name: "MELEE_ATTACK_DAMAGE_TYPE", Kind: monsterFieldDamageType, Off: 124},
	{Name: "MELEE_ATTACK_IMPACT", Kind: monsterFieldFloat, Off: 120},
	{Name: "MELEE_ATTACK_RANGE", Kind: monsterFieldFloat, Off: 112},
	{Name: "MELEE_ATTACK_FRAME", Kind: monsterFieldInt, Off: 108},
	{Name: "MELEE_ATTACK_MIN_DELAY", Kind: monsterFieldInt, Off: 128},
	{Name: "MELEE_ATTACK_MAX_DELAY", Kind: monsterFieldInt, Off: 132},
	{Name: "MELEE_ATTACK_POISON_CHANCE", Kind: monsterFieldInt, Off: 136},
	{Name: "MELEE_ATTACK_POISON_STRENGTH", Kind: monsterFieldInt, Off: 140},
	{Name: "MELEE_ATTACK_POISON_MAX", Kind: monsterFieldInt, Off: 144},
	{Name: "MISSILE_NAME", Kind: monsterFieldString, Off: 148},
	{Name: "MISSILE_ATTACK_RANGE", Kind: monsterFieldFloat, Off: 212},
	{Name: "MISSILE_ATTACK_FRAME", Kind: monsterFieldInt, Off: 216},
	{Name: "MISSILE_ATTACK_MIN_DELAY", Kind: monsterFieldInt, Off: 220},
	{Name: "MISSILE_ATTACK_MAX_DELAY", Kind: monsterFieldInt, Off: 224},
	{Name: "MELEE_STRIKE_FUNCTION", Kind: monsterFieldStrikeFunc, Off: 236},
	{Name: "DIE_FUNCTION", Kind: monsterFieldDieFunc, Off: 228},
	{Name: "DEAD_FUNCTION", Kind: monsterFieldDeadFunc, Off: 232},
	{Name: "QUESTHEALTH", Kind: monsterFieldInt, Off: 72},
}
