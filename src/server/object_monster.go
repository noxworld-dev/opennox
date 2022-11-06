package server

import (
	"math"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/unit/ai"
)

type AIStackItem struct {
	Action uint32     // 0, 0
	Args   [4]uintptr // 1, 4
	Field5 uint32     // 5, 20
}

func (s *AIStackItem) Type() ai.ActionType {
	if s == nil {
		return ai.ACTION_INVALID
	}
	return ai.ActionType(s.Action)
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

type MonsterUpdateData struct {
	Field0                  uint32           // 0, 0
	Field1                  uint32           // 1, 4
	Field2                  uint32           // 2, 8
	Field3                  uint32           // 3, 12
	Field4                  uint32           // 4, 16
	Field5                  uint32           // 5, 20
	Field6                  uint32           // 6, 24
	Field7                  uint32           // 7, 28
	Field8                  uint32           // 8, 32
	Field9                  uint32           // 9, 36
	Field10                 uint32           // 10, 40
	Field11                 uint32           // 11, 44
	Field12                 uint32           // 12, 48
	Field13                 uint32           // 13, 52
	Field14                 uint32           // 14, 56
	Field15                 uint32           // 15, 60
	Field16                 uint32           // 16, 64
	Field17                 uint32           // 17, 68
	Field18                 uint32           // 18, 72
	Field19                 uint32           // 19, 76
	Field20                 uint32           // 20, 80
	Field21                 uint32           // 21, 84
	Field22                 uint32           // 22, 88
	Field23                 uint32           // 23, 92
	Field24                 uint32           // 24, 96
	Field25                 uint32           // 25, 100
	Field26                 uint32           // 26, 104
	Field27                 uint32           // 27, 108
	Field28                 uint32           // 28, 112
	Field29                 uint32           // 29, 116
	Field30                 uint32           // 30, 120
	Field31                 uint32           // 31, 124
	Field32                 uint32           // 32, 128
	Field33                 uint32           // 33, 132
	Field34                 uint32           // 34, 136
	Field35                 uint32           // 35, 140
	Field36                 uint32           // 36, 144
	Field37                 uint32           // 37, 148
	Field38                 uint32           // 38, 152
	Field39                 uint32           // 39, 156
	Field40                 uint32           // 40, 160
	Field41                 uint32           // 41, 164
	Field42                 uint32           // 42, 168
	Field43                 uint32           // 43, 172
	Field44                 uint32           // 44, 176
	Field45                 uint32           // 45, 180
	Field46                 uint32           // 46, 184
	Field47                 uint32           // 47, 188
	Field48                 uint32           // 48, 192
	Field49                 uint32           // 49, 196
	Field50                 uint32           // 50, 200
	Field51                 uint32           // 51, 204
	Field52                 uint32           // 52, 208
	Field53                 uint32           // 53, 212
	Field54                 uint32           // 54, 216
	Field55                 uint32           // 55, 220
	Field56                 uint32           // 56, 224
	Field57                 uint32           // 57, 228
	Field58                 uint32           // 58, 232
	Field59                 uint32           // 59, 236
	Field60                 uint32           // 60, 240
	Field61                 uint32           // 61, 244
	Field62                 uint32           // 62, 248
	Field63                 uint32           // 63, 252
	Field64                 uint32           // 64, 256
	Field65                 uint32           // 65, 260
	Field66                 uint32           // 66, 264
	Field67                 uint32           // 67, 268
	Field68                 uint32           // 68, 272
	Field69                 uint32           // 69, 276
	Field70                 uint32           // 70, 280
	Field71                 uint32           // 71, 284
	Field72                 uint32           // 72, 288
	Field73                 uint32           // 73, 292
	Field74                 uint32           // 74, 296
	Field75                 uint32           // 75, 300
	Field76                 uint32           // 76, 304
	Field77                 uint32           // 77, 308
	Field78                 uint32           // 78, 312
	Field79                 uint32           // 79, 316
	Field80                 uint32           // 80, 320
	Field81                 uint32           // 81, 324
	Field82                 uint32           // 82, 328
	Field83                 uint32           // 83, 332
	Field84                 uint32           // 84, 336
	Field85                 uint32           // 85, 340
	Field86                 uint32           // 86, 344
	Field87                 uint32           // 87, 348
	Field88                 uint32           // 88, 352
	Field89                 uint32           // 89, 356
	Field90                 uint32           // 90, 360
	Field91                 uint32           // 91, 364
	Field92                 uint32           // 92, 368
	Field93                 uint32           // 93, 372
	Field94                 uint32           // 94, 376
	Field95                 uint32           // 95, 380
	Field96                 uint32           // 96, 384
	Field97                 uint32           // 97, 388, TODO: hear sound ind
	Field98                 uint32           // 98, 392, TODO: some frame/timestamp
	Field99X                float32          // 99, 396
	Field99Y                float32          // 100, 400
	Field101                uint32           // 101, 404, TODO: hear frame/timestamp
	Field102                uint32           // 102, 408, TODO: hear distance
	Field103                uint32           // 103, 412
	Field104                uint32           // 104, 416
	Field105                uint32           // 105, 420
	Field106                uint32           // 106, 424
	Field107                uint32           // 107, 428
	Field108                uint32           // 108, 432
	Field109                uint32           // 109, 436
	Field110                uint32           // 110, 440
	Field111                uint32           // 111, 444
	Field112                uint32           // 112, 448
	Field113                uint32           // 113, 452
	Field114                uint32           // 114, 456
	Field115                uint32           // 115, 460
	Field116                uint32           // 116, 464
	Field117                uint32           // 117, 468
	Field118                uint32           // 118, 472
	Field119                *[16]MonsterAnim // 119, 476
	Field120_0              uint8            // 120, 480
	Field120_1              uint8            // 120, 481
	Field120_2              uint8            // 120, 482
	Field120_3              uint8            // 120, 483
	Field121                unsafe.Pointer   // 121, 484
	Field122                uint32           // 122, 488
	Field123                uint32           // 123, 492
	Field124                uint32           // 124, 496
	Field125                uint32           // 125, 500
	Field126                uint32           // 126, 504
	Field127                uint32           // 127, 508
	Field128                uint32           // 128, 512
	Field129                uint32           // 129, 516, TODO: some timestamp
	Field130                uint32           // 130, 520
	Field131                uint32           // 131, 524
	Field132                uint32           // 132, 528
	Field133                uint32           // 133, 532
	Field134                uint32           // 134, 536
	Field135                uint32           // 135, 540
	AIStackInd              int8             // 136, 544
	Field136_1              uint8            // 136, 545
	Field136_2              uint16           // 136, 546
	Field137                uint32           // 137, 548
	AIStack                 [24]AIStackItem  // 138, 552
	Field282_0              uint8            // 282, 1128, TODO: current stamina?
	Field282_1              uint8            // 282, 1129
	Field282_2              uint16           // 282, 1130
	Field283                uint32           // 283, 1132
	Field284                uint32           // 284, 1136
	Field285                uint32           // 285, 1140
	Field286                uint32           // 286, 1144
	Field287                uint32           // 287, 1148
	Field288                uint32           // 288, 1152
	Field289                uint32           // 289, 1156
	Field290                uint32           // 290, 1160
	Field291                uint32           // 291, 1164
	Field292                uint32           // 292, 1168
	Field293                uint32           // 293, 1172
	Field294                uint32           // 294, 1176
	Field295                uint32           // 295, 1180
	Field296                uint32           // 296, 1184
	Field297                uint32           // 297, 1188
	Field298                uint32           // 298, 1192
	CurrentEnemy            *Object          // 299, 1196
	Field300                uint32           // 300, 1200
	Field301                uint32           // 301, 1204
	Field302                uint32           // 302, 1208
	Field303                uint32           // 303, 1212
	Field304                uint32           // 304, 1216
	Field305                uint32           // 305, 1220
	Field306                uint32           // 306, 1224
	ScriptLookingForEnemyCB int32            // 307, 1228
	Field308                uint32           // 308, 1232
	ScriptEnemySightedCB    int32            // 309, 1236
	Field310                uint32           // 310, 1240
	ScriptChangeFocusCB     int32            // 311, 1244
	Field312                uint32           // 312, 1248
	ScriptIsHitCB           int32            // 313, 1252
	Field314                uint32           // 314, 1256
	ScriptRetreatCB         int32            // 315, 1260
	Field316                uint32           // 316, 1264
	ScriptDeathCB           int32            // 317, 1268
	Field318                uint32           // 318, 1272
	ScriptCollisionCB       int32            // 319, 1276
	Field320                uint32           // 320, 1280 // TODO: monster hear script callback base?
	ScriptHearEnemyCB       int32            // 321, 1284
	Field322                uint32           // 322, 1288
	ScriptEndOfWaypointCB   int32            // 323, 1292
	Field324                uint32           // 324, 1296
	ScriptLostEnemyCB       int32            // 325, 1300
	Field326                uint32           // 326, 1304
	Field327                uint32           // 327, 1308
	Field328                float32          // 328, 1312
	Field329                uint32           // 329, 1316
	Field330                uint32           // 330, 1320
	Field331                uint32           // 331, 1324
	Field332                uint32           // 332, 1328
	Field333                uint32           // 333, 1332
	Field334                uint32           // 334, 1336
	Field335                uint32           // 335, 1340
	Field336                float32          // 336, 1344
	Field337                uint32           // 337, 1348
	Field338                uint32           // 338, 1352
	Field339                uint32           // 339, 1356
	Field340                uint32           // 340, 1360
	Field341                uint32           // 341, 1364
	Field342                uint32           // 342, 1368
	Field343                uint32           // 343, 1372
	Field344                uint32           // 344, 1376
	Field345                uint32           // 345, 1380
	Field346                uint32           // 346, 1384
	Field347                uint32           // 347, 1388
	Field348                uint32           // 348, 1392
	Field349                uint32           // 349, 1396
	Field350                uint32           // 350, 1400
	Field351                uint32           // 351, 1404
	Field352                uint32           // 352, 1408
	Field353                uint32           // 353, 1412
	Field354                uint32           // 354, 1416
	Field355                uint32           // 355, 1420
	Field356                uint32           // 356, 1424
	Field357                uint32           // 357, 1428
	Field358                uint32           // 358, 1432
	Field359                uint32           // 359, 1436
	Field360                uint32           // 360, 1440 // TODO: flags?
	Field361                uint32           // 361, 1444
	Field362                uint32           // 362, 1448
	Field363                uint32           // 363, 1452
	Field364                uint32           // 364, 1456
	Field365                uint32           // 365, 1460
	Field366                uint32           // 366, 1464
	Field367                uint32           // 367, 1468
	Field368                uint32           // 368, 1472
	Field369                uint32           // 369, 1476
	Field370                uint32           // 370, 1480
	Field371                uint32           // 371, 1484
	Field372                uint32           // 372, 1488
	Field373                uint32           // 373, 1492
	Field374                uint32           // 374, 1496
	Field375                uint32           // 375, 1500
	Field376                uint32           // 376, 1504
	Field377                uint32           // 377, 1508
	Field378                uint32           // 378, 1512
	Field379                uint32           // 379, 1516
	Field380                uint32           // 380, 1520
	Field381                uint32           // 381, 1524
	Field382                uint32           // 382, 1528
	Field383                uint32           // 383, 1532
	Field384                uint32           // 384, 1536
	Field385                uint32           // 385, 1540
	Field386                uint32           // 386, 1544
	Field387                uint32           // 387, 1548
	Field388                uint32           // 388, 1552
	Field389                uint32           // 389, 1556
	Field390                uint32           // 390, 1560
	Field391                uint32           // 391, 1564
	Field392                uint32           // 392, 1568
	Field393                uint32           // 393, 1572
	Field394                uint32           // 394, 1576
	Field395                uint32           // 395, 1580
	Field396                uint32           // 396, 1584
	Field397                uint32           // 397, 1588
	Field398                uint32           // 398, 1592
	Field399                uint32           // 399, 1596
	Field400                uint32           // 400, 1600
	Field401                uint32           // 401, 1604
	Field402                uint32           // 402, 1608
	Field403                uint32           // 403, 1612
	Field404                uint32           // 404, 1616
	Field405                uint32           // 405, 1620
	Field406                uint32           // 406, 1624
	Field407                uint32           // 407, 1628
	Field408                uint32           // 408, 1632
	Field409                uint32           // 409, 1636
	Field410                uint32           // 410, 1640
	Field411                uint32           // 411, 1644
	Field412                uint32           // 412, 1648
	Field413                uint32           // 413, 1652
	Field414                uint32           // 414, 1656
	Field415                uint32           // 415, 1660
	Field416                uint32           // 416, 1664
	Field417                uint32           // 417, 1668
	Field418                uint32           // 418, 1672
	Field419                uint32           // 419, 1676
	Field420                uint32           // 420, 1680
	Field421                uint32           // 421, 1684
	Field422                uint32           // 422, 1688
	Field423                uint32           // 423, 1692
	Field424                uint32           // 424, 1696
	Field425                uint32           // 425, 1700
	Field426                uint32           // 426, 1704
	Field427                uint32           // 427, 1708
	Field428                uint32           // 428, 1712
	Field429                uint32           // 429, 1716
	Field430                uint32           // 430, 1720
	Field431                uint32           // 431, 1724
	Field432                uint32           // 432, 1728
	Field433                uint32           // 433, 1732
	Field434                uint32           // 434, 1736
	Field435                uint32           // 435, 1740
	Field436                uint32           // 436, 1744
	Field437                uint32           // 437, 1748
	Field438                uint32           // 438, 1752
	Field439                uint32           // 439, 1756
	Field440                uint32           // 440, 1760
	Field441                uint32           // 441, 1764
	Field442                uint32           // 442, 1768
	Field443                uint32           // 443, 1772
	Field444                uint32           // 444, 1776
	Field445                uint32           // 445, 1780
	Field446                uint32           // 446, 1784
	Field447                uint32           // 447, 1788
	Field448                uint32           // 448, 1792
	Field449                uint32           // 449, 1796
	Field450                uint32           // 450, 1800
	Field451                uint32           // 451, 1804
	Field452                uint32           // 452, 1808
	Field453                uint32           // 453, 1812
	Field454                uint32           // 454, 1816
	Field455                uint32           // 455, 1820
	Field456                uint32           // 456, 1824
	Field457                uint32           // 457, 1828
	Field458                uint32           // 458, 1832
	Field459                uint32           // 459, 1836
	Field460                uint32           // 460, 1840
	Field461                uint32           // 461, 1844
	Field462                uint32           // 462, 1848
	Field463                uint32           // 463, 1852
	Field464                uint32           // 464, 1856
	Field465                uint32           // 465, 1860
	Field466                uint32           // 466, 1864
	Field467                uint32           // 467, 1868
	Field468                uint32           // 468, 1872
	Field469                uint32           // 469, 1876
	Field470                uint32           // 470, 1880
	Field471                uint32           // 471, 1884
	Field472                uint32           // 472, 1888
	Field473                uint32           // 473, 1892
	Field474                uint32           // 474, 1896
	Field475                uint32           // 475, 1900
	Field476                uint32           // 476, 1904
	Field477                uint32           // 477, 1908
	Field478                uint32           // 478, 1912
	Field479                uint32           // 479, 1916
	Field480                uint32           // 480, 1920
	Field481                uint32           // 481, 1924
	Field482                uint32           // 482, 1928
	Field483                uint32           // 483, 1932
	Field484                uint32           // 484, 1936
	Field485                uint32           // 485, 1940
	Field486                uint32           // 486, 1944
	Field487                uint32           // 487, 1948
	Field488                uint32           // 488, 1952
	Field489                uint32           // 489, 1956
	Field490                uint32           // 490, 1960
	Field491                uint32           // 491, 1964
	Field492                uint32           // 492, 1968
	Field493                uint32           // 493, 1972
	Field494                uint32           // 494, 1976
	Field495                uint32           // 495, 1980
	Field496                uint32           // 496, 1984
	Field497                uint32           // 497, 1988
	Field498                uint32           // 498, 1992
	Field499                uint32           // 499, 1996
	Field500                uint32           // 500, 2000
	Field501                uint32           // 501, 2004
	Field502                uint32           // 502, 2008
	Field503                uint32           // 503, 2012
	Field504                uint32           // 504, 2016
	Field505                uint32           // 505, 2020
	Field506                uint32           // 506, 2024
	Field507                uint32           // 507, 2028
	Field508                uint32           // 508, 2032
	Field509                uint32           // 509, 2036
	Field510                uint32           // 510, 2040
	Field511                uint32           // 511, 2044
	Field512                uint32           // 512, 2048
	Field513                uint32           // 513, 2052
	Field514                uint32           // 514, 2056, TODO: weapon damage type?
	Field515                uint32           // 515, 2060
	Field516                uint32           // 516, 2064
	Field517                uint32           // 517, 2068
	Field518                uint32           // 518, 2072
	Field519                uint32           // 519, 2076
	Field520                uint32           // 520, 2080
	Field521                uint32           // 521, 2084
	Field522                uint32           // 522, 2088
	Field523_0              uint16           // 523, 2092
	Field523_2              uint8            // 523, 2094
	Field523_3              uint8            // 523, 2095
	Field524                uint32           // 524, 2096
	Field525                uint32           // 525, 2100
	Field526                uint32           // 526, 2104
	Field527                uint32           // 527, 2108
	Field528                uint32           // 528, 2112
	Field529                uint32           // 529, 2116
	Field530                uint32           // 530, 2120
	Field531                uint32           // 531, 2124
	Field532                uint32           // 532, 2128
	Field533                uint32           // 533, 2132
	Field534                uint32           // 534, 2136
	Field535                uint32           // 535, 2140
	Field536                uint32           // 536, 2144
	Field537                uint32           // 537, 2148
	Field538                uint32           // 538, 2152
	Field539                uint32           // 539, 2156
	Field540                uint32           // 540, 2160
	Field541                uint32           // 541, 2164
	Field542                uint32           // 542, 2168
	Field543                uint32           // 543, 2172
	Field544                uint32           // 544, 2176
	Field545                uint32           // 545, 2180
	Field546                uint32           // 546, 2184
	Field547                uint32           // 547, 2188
	Field548                *Object          // 548, 2192
	Field549                uint32           // 549, 2196
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
