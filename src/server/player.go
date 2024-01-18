package server

import (
	"fmt"
	"image"
	"unsafe"

	"github.com/noxworld-dev/opennox-lib/common"
	"github.com/noxworld-dev/opennox-lib/player"
	"github.com/noxworld-dev/opennox-lib/types"

	"github.com/noxworld-dev/opennox/v1/common/ntype"
	"github.com/noxworld-dev/opennox/v1/legacy/common/alloc"
)

type classStatMult struct {
	// TODO: health and mana

	Strength float32
	Speed    float32
}

type serverPlayers struct {
	list []Player
	Mult struct {
		Warrior  classStatMult
		Wizard   classStatMult
		Conjurer classStatMult
	}
	Control  serverCtrlBuf
	HostUnit *Object
}

func (s *serverPlayers) init() {
	s.list, _ = alloc.Make([]Player{}, common.MaxPlayers)
	s.Mult.Warrior = classStatMult{
		Strength: 1,
		Speed:    1,
	}
	s.Mult.Wizard = classStatMult{
		Strength: 1,
		Speed:    1,
	}
	s.Mult.Conjurer = classStatMult{
		Strength: 1,
		Speed:    1,
	}
}

func (s *serverPlayers) ResetAll() {
	for i := range s.list {
		s.list[i] = Player{}
	}
}

func (s *serverPlayers) First() *Player {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() {
			return p
		}
	}
	return nil
}

func (s *serverPlayers) Next(it *Player) *Player {
	if it == nil {
		return nil
	}
	for i := it.Index() + 1; i < len(s.list); i++ {
		p := &s.list[i]
		if p.IsActive() {
			return p
		}
	}
	return nil
}

func (s *serverPlayers) Each(fnc func(it *Player) bool) {
	for it := s.First(); it != nil; it = s.Next(it) {
		if !fnc(it) {
			return
		}
	}
}

func (s *serverPlayers) EachReplaceable(fnc func(it *Player) bool) {
	for it := s.firstReplaceablePlayer(); it != nil; it = s.nextReplaceablePlayer(it) {
		if !fnc(it) {
			return
		}
	}
}

func (s *serverPlayers) firstReplaceablePlayer() *Player {
	for it := s.First(); it != nil; it = s.Next(it) {
		if it.Field3680&1 != 0 && it.Index() != -1 {
			return it
		}
	}
	return nil
}

func (s *serverPlayers) nextReplaceablePlayer(it *Player) *Player {
	for ; it != nil; it = s.Next(it) {
		if it.Field3680&1 != 0 && it.Index() != -1 {
			return it
		}
	}
	return nil
}

func (s *serverPlayers) ResetInd(ind ntype.PlayerInd) *Player {
	p := &s.list[ind]
	p.reset(ind)
	return p
}

func (s *serverPlayers) ByID(id int) *Player {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() && int(p.NetCodeVal) == id {
			return p
		}
	}
	return nil
}

func (s *serverPlayers) ByInd(i ntype.PlayerInd) *Player {
	if i < 0 || int(i) >= len(s.list) {
		return nil
	}
	p := &s.list[i]
	if !p.IsActive() {
		return nil
	}
	p.PlayerInd = byte(i)
	return p
}

func (s *serverPlayers) ByIndRaw(i ntype.PlayerInd) *Player {
	if i < 0 || int(i) >= len(s.list) {
		return nil
	}
	return &s.list[i]
}

func (s *serverPlayers) HasUnits() bool {
	for i := range s.list {
		p := &s.list[i]
		if p.PlayerUnit != nil {
			return true
		}
	}
	return false
}

func (s *serverPlayers) List() (out []*Player) {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() {
			out = append(out, p)
		}
	}
	return out
}

func (s *serverPlayers) Count() (n int) {
	for i := range s.list {
		p := &s.list[i]
		if p.IsActive() {
			n++
		}
	}
	return n
}

func (s *serverPlayers) ListSlots() (out []*Player) {
	for i := range s.list {
		p := &s.list[i]
		out = append(out, p)
	}
	return out
}

func (s *serverPlayers) NewRaw(id int) *Player {
	if p := s.ByID(id); p != nil {
		return p
	}
	for i := range s.list {
		p := &s.list[i]
		if !p.IsActive() {
			p.reset(ntype.PlayerInd(i))
			p.NetCodeVal = uint32(id)
			return p
		}
	}
	return nil
}

func (s *serverPlayers) CheckName(pl *Player) {
	for i := 2; ; i++ {
		ok := true
		for _, pl2 := range s.List() {
			if pl.Index() == pl2.Index() {
				continue
			}
			if pl.Name() == pl2.Name() {
				ok = false
				break
			}
		}
		if ok {
			return
		}
		pl.Info().SetNameSuff(fmt.Sprintf(" %d", i))
		pl.SetName(fmt.Sprintf("%s %d", pl.OrigName(), i))
	}
}

var _ = [1]struct{}{}[8-unsafe.Sizeof(PlayerNetData{})]

type PlayerNetData struct {
	Field0 uint16
	Field2 uint16
	Frame4 uint32
}

var _ = [1]struct{}{}[76-unsafe.Sizeof(PlayerJournal{})]

type PlayerJournal struct {
	EntryBuf [64]byte       // 0, 0
	Next     *PlayerJournal // 1, 64
	Prev     *PlayerJournal // 2, 68
	Field3   uint16         // 3, 72
	Field4   uint16         // 4, 74, likely just padding
}

var (
	_ = [1]struct{}{}[4828-unsafe.Sizeof(Player{})]
	_ = [1]struct{}{}[2185-unsafe.Offsetof(Player{}.info)]
	_ = [1]struct{}{}[2282-unsafe.Offsetof(Player{}.field2282)]
	_ = [1]struct{}{}[3596-unsafe.Offsetof(Player{}.Frame3596)]
	_ = [1]struct{}{}[4580-unsafe.Offsetof(Player{}.Field4580)]
	_ = [1]struct{}{}[4796-unsafe.Offsetof(Player{}.data4796)]
)

type MinimapItem struct {
	Field0  uint32
	Field4  *Object
	Field8  *MinimapItem
	Field12 *MinimapItem
}

var _ Obj = (*Player)(nil) // proxies Unit

type Player struct {
	Field0              uint32             // 0, 0
	Field4              uint32             // 1, 4
	Field8              uint16             // 2, 8
	Field10             uint16             // 2, 10
	Field12             uint16             // 3, 12
	field14             uint16             // 3, 14
	NetData16           [255]PlayerNetData // 4, 16
	PlayerUnit          *Object            // 514, 2056
	NetCodeVal          uint32             // 515, 2060
	PlayerInd           byte               // 516, 2064
	_                   [3]byte            // 516, 2065
	Field2068           uint32             // 517, 2068
	Field2072           [10]uint16         // 518, 2072
	Active              byte               // 523, 2092
	Field2096Buf        [12]byte           // 524, 2096
	Field2108           uint32             // 527, 2108
	SerialBuf           [22]byte           // 528, 2112
	field2134           byte
	Field2135           byte
	Lessons             int32  // 534, 2136
	Field2140           uint32 // 535, 2140
	Field2144           uint32 // 536, 2144
	field2148           uint32 // 537, 2148
	Field2152           uint32 // 538, 2152
	Field2156           uint32 // 539, 2156
	field2160           uint32 // 540, 2160
	GoldVal             uint32 // 541, 2164
	Field2168           uint32 // 542, 2168
	Field2172           byte   // 543, 2172
	_                   [12]byte
	info                [97]byte    // 2185
	field2282           uint16      // 2282
	CursorVec           image.Point // 2284
	Color5              uint32      // 573, 2292
	Color0              uint32      // 574, 2296
	Color4              uint32      // 575, 2300
	Color1              uint32      // 576, 2304
	Color3              uint32      // 577, 2308
	Color2              uint32      // 578, 2312
	Field2316           uint32      // 579, 2316
	Field2320           uint32      // 580, 2320
	Field2324           uint32      // 581, 2324
	Field2328           uint32      // 582, 2328
	Field2332           uint32      // 583, 2332
	Field2336           uint32      // 584, 2336
	Field2340           uint32      // 585, 2340
	Field2344           uint32      // 586, 2344
	Field2348           uint32      // 587, 2348
	Field2352           uint32      // 588, 2352
	Field2356           uint32      // 589, 2356
	Field2360           uint32      // 590, 2360
	Field2364           uint32      // 591, 2364
	Field2368           uint32      // 592, 2368
	Field2372           uint32      // 593, 2372
	Field2376           uint32      // 594, 2376
	Field2380           uint32      // 595, 2380
	Field2384           uint32      // 596, 2384
	Field2388           uint32      // 597, 2388
	Field2392           uint32      // 598, 2392
	Field2396           uint32      // 599, 2396
	Field2400           uint32      // 600, 2400
	Field2404           uint32      // 601, 2404
	Field2408           uint32      // 602, 2408
	Field2412           uint32      // 603, 2412
	Field2416           uint32      // 604, 2416
	Field2420           uint32      // 605, 2420
	Field2424           uint32      // 606, 2424
	Field2428           uint32      // 607, 2428
	Field2432           uint32      // 608, 2432
	Field2436           uint32      // 609, 2436
	Field2440           uint32      // 610, 2440
	Field2444           uint32      // 611, 2444
	Field2448           uint32      // 612, 2448
	Field2452           uint32      // 613, 2452
	Field2456           uint32      // 614, 2456
	Field2460           uint32      // 615, 2460
	Field2464           uint32      // 616, 2464
	Field2468           uint32      // 617, 2468
	Field2472           uint32      // 618, 2472
	Field2476           uint32      // 619, 2476
	Field2480           uint32      // 620, 2480
	Field2484           uint32      // 621, 2484
	Field2488           uint32      // 622, 2488
	Field2492           uint32      // 623, 2492
	Field2496           uint32      // 624, 2496
	Field2500           uint32      // 625, 2500
	Field2504           uint32      // 626, 2504
	Field2508           uint32      // 627, 2508
	Field2512           uint32      // 628, 2512
	Field2516           uint32      // 629, 2516
	Field2520           uint32      // 630, 2520
	Field2524           uint32      // 631, 2524
	Field2528           uint32      // 632, 2528
	Field2532           uint32      // 633, 2532
	Field2536           uint32      // 634, 2536
	Field2540           uint32      // 635, 2540
	Field2544           uint32      // 636, 2544
	Field2548           uint32      // 637, 2548
	Field2552           uint32      // 638, 2552
	Field2556           uint32      // 639, 2556
	Field2560           uint32      // 640, 2560
	Field2564           uint32      // 641, 2564
	Field2568           uint32      // 642, 2568
	Field2572           uint32      // 643, 2572
	Field2576           uint32      // 644, 2576
	Field2580           uint32      // 645, 2580
	Field2584           uint32      // 646, 2584
	Field2588           uint32      // 647, 2588
	Field2592           uint32      // 648, 2592
	Field2596           uint32      // 649, 2596
	Field2600           uint32      // 650, 2600
	Field2604           uint32      // 651, 2604
	Field2608           uint32      // 652, 2608
	Field2612           uint32      // 653, 2612
	Field2616           uint32      // 654, 2616
	Field2620           uint32      // 655, 2620
	Field2624           uint32      // 656, 2624
	Field2628           uint32      // 657, 2628
	Field2632           uint32      // 658, 2632
	Field2636           uint32      // 659, 2636
	Field2640           uint32      // 660, 2640
	Field2644           uint32      // 661, 2644
	Field2648           uint32      // 662, 2648
	Field2652           uint32      // 663, 2652
	Field2656           uint32      // 664, 2656
	Field2660           uint32      // 665, 2660
	Field2664           uint32      // 666, 2664
	Field2668           uint32      // 667, 2668
	Field2672           uint32      // 668, 2672
	Field2676           uint32      // 669, 2676
	Field2680           uint32      // 670, 2680
	Field2684           uint32      // 671, 2684
	Field2688           uint32      // 672, 2688
	Field2692           uint32      // 673, 2692
	Field2696           uint32      // 674, 2696
	Field2700           uint32      // 675, 2700
	Field2704           uint32      // 676, 2704
	Field2708           uint32      // 677, 2708
	Field2712           uint32      // 678, 2712
	Field2716           uint32      // 679, 2716
	Field2720           uint32      // 680, 2720
	Field2724           uint32      // 681, 2724
	Field2728           uint32      // 682, 2728
	Field2732           uint32      // 683, 2732
	Field2736           uint32      // 684, 2736
	Field2740           uint32      // 685, 2740
	Field2744           uint32      // 686, 2744
	Field2748           uint32      // 687, 2748
	Field2752           uint32      // 688, 2752
	Field2756           uint32      // 689, 2756
	Field2760           uint32      // 690, 2760
	Field2764           uint32      // 691, 2764
	Field2768           uint32      // 692, 2768
	Field2772           uint32      // 693, 2772
	Field2776           uint32      // 694, 2776
	Field2780           uint32      // 695, 2780
	Field2784           uint32      // 696, 2784
	Field2788           uint32      // 697, 2788
	Field2792           uint32      // 698, 2792
	Field2796           uint32      // 699, 2796
	Field2800           uint32      // 700, 2800
	Field2804           uint32      // 701, 2804
	Field2808           uint32      // 702, 2808
	Field2812           uint32      // 703, 2812
	Field2816           uint32      // 704, 2816
	Field2820           uint32      // 705, 2820
	Field2824           uint32      // 706, 2824
	Field2828           uint32      // 707, 2828
	Field2832           uint32      // 708, 2832
	Field2836           uint32      // 709, 2836
	Field2840           uint32      // 710, 2840
	Field2844           uint32      // 711, 2844
	Field2848           uint32      // 712, 2848
	Field2852           uint32      // 713, 2852
	Field2856           uint32      // 714, 2856
	Field2860           uint32      // 715, 2860
	Field2864           uint32      // 716, 2864
	Field2868           uint32      // 717, 2868
	Field2872           uint32      // 718, 2872
	Field2876           uint32      // 719, 2876
	Field2880           uint32      // 720, 2880
	Field2884           uint32      // 721, 2884
	Field2888           uint32      // 722, 2888
	Field2892           uint32      // 723, 2892
	Field2896           uint32      // 724, 2896
	Field2900           uint32      // 725, 2900
	Field2904           uint32      // 726, 2904
	Field2908           uint32      // 727, 2908
	Field2912           uint32      // 728, 2912
	Field2916           uint32      // 729, 2916
	Field2920           uint32      // 730, 2920
	Field2924           uint32      // 731, 2924
	Field2928           uint32      // 732, 2928
	Field2932           uint32      // 733, 2932
	Field2936           uint32      // 734, 2936
	Field2940           uint32      // 735, 2940
	Field2944           uint32      // 736, 2944
	Field2948           uint32      // 737, 2948
	Field2952           uint32      // 738, 2952
	Field2956           uint32      // 739, 2956
	Field2960           uint32      // 740, 2960
	Field2964           uint32      // 741, 2964
	Field2968           uint32      // 742, 2968
	Field2972           uint32      // 743, 2972
	Field2976           uint32      // 744, 2976
	Field2980           uint32      // 745, 2980
	Field2984           uint32      // 746, 2984
	Field2988           uint32      // 747, 2988
	Field2992           uint32      // 748, 2992
	Field2996           uint32      // 749, 2996
	Field3000           uint32      // 750, 3000
	Field3004           uint32      // 751, 3004
	Field3008           uint32      // 752, 3008
	Field3012           uint32      // 753, 3012
	Field3016           uint32      // 754, 3016
	Field3020           uint32      // 755, 3020
	Field3024           uint32      // 756, 3024
	Field3028           uint32      // 757, 3028
	Field3032           uint32      // 758, 3032
	Field3036           uint32      // 759, 3036
	Field3040           uint32      // 760, 3040
	Field3044           uint32      // 761, 3044
	Field3048           uint32      // 762, 3048
	Field3052           uint32      // 763, 3052
	Field3056           uint32      // 764, 3056
	Field3060           uint32      // 765, 3060
	Field3064           uint32      // 766, 3064
	Field3068           uint32      // 767, 3068
	Field3072           uint32      // 768, 3072
	Field3076           uint32      // 769, 3076
	Field3080           uint32      // 770, 3080
	Field3084           uint32      // 771, 3084
	Field3088           uint32      // 772, 3088
	Field3092           uint32      // 773, 3092
	Field3096           uint32      // 774, 3096
	Field3100           uint32      // 775, 3100
	Field3104           uint32      // 776, 3104
	Field3108           uint32      // 777, 3108
	Field3112           uint32      // 778, 3112
	Field3116           uint32      // 779, 3116
	Field3120           uint32      // 780, 3120
	Field3124           uint32      // 781, 3124
	Field3128           uint32      // 782, 3128
	Field3132           uint32      // 783, 3132
	Field3136           uint32      // 784, 3136
	Field3140           uint32      // 785, 3140
	Field3144           uint32      // 786, 3144
	Field3148           uint32      // 787, 3148
	Field3152           uint32      // 788, 3152
	Field3156           uint32      // 789, 3156
	Field3160           uint32      // 790, 3160
	Field3164           uint32      // 791, 3164
	Field3168           uint32      // 792, 3168
	Field3172           uint32      // 793, 3172
	Field3176           uint32      // 794, 3176
	Field3180           uint32      // 795, 3180
	Field3184           uint32      // 796, 3184
	Field3188           uint32      // 797, 3188
	Field3192           uint32      // 798, 3192
	Field3196           uint32      // 799, 3196
	Field3200           uint32      // 800, 3200
	Field3204           uint32      // 801, 3204
	Field3208           uint32      // 802, 3208
	Field3212           uint32      // 803, 3212
	Field3216           uint32      // 804, 3216
	Field3220           uint32      // 805, 3220
	Field3224           uint32      // 806, 3224
	Field3228           uint32      // 807, 3228
	Field3232           uint32      // 808, 3232
	Field3236           uint32      // 809, 3236
	Field3240           uint32      // 810, 3240
	Field3244           uint32      // 811, 3244
	Field3248           uint32      // 812, 3248
	Field3252           uint32      // 813, 3252
	Field3256           uint32      // 814, 3256
	Field3260           uint32      // 815, 3260
	Field3264           uint32      // 816, 3264
	Field3268           uint32      // 817, 3268
	Field3272           uint32      // 818, 3272
	Field3276           uint32      // 819, 3276
	Field3280           uint32      // 820, 3280
	Field3284           uint32      // 821, 3284
	Field3288           uint32      // 822, 3288
	Field3292           uint32      // 823, 3292
	Field3296           uint32      // 824, 3296
	Field3300           uint32      // 825, 3300
	Field3304           uint32      // 826, 3304
	Field3308           uint32      // 827, 3308
	Field3312           uint32      // 828, 3312
	Field3316           uint32      // 829, 3316
	Field3320           uint32      // 830, 3320
	Field3324           uint32      // 831, 3324
	Field3328           uint32      // 832, 3328
	Field3332           uint32      // 833, 3332
	Field3336           uint32      // 834, 3336
	Field3340           uint32      // 835, 3340
	Field3344           uint32      // 836, 3344
	Field3348           uint32      // 837, 3348
	Field3352           uint32      // 838, 3352
	Field3356           uint32      // 839, 3356
	Field3360           uint32      // 840, 3360
	Field3364           uint32      // 841, 3364
	Field3368           uint32      // 842, 3368
	Field3372           uint32      // 843, 3372
	Field3376           uint32      // 844, 3376
	Field3380           uint32      // 845, 3380
	Field3384           uint32      // 846, 3384
	Field3388           uint32      // 847, 3388
	Field3392           uint32      // 848, 3392
	Field3396           uint32      // 849, 3396
	Field3400           uint32      // 850, 3400
	Field3404           uint32      // 851, 3404
	Field3408           uint32      // 852, 3408
	Field3412           uint32      // 853, 3412
	Field3416           uint32      // 854, 3416
	Field3420           uint32      // 855, 3420
	Field3424           uint32      // 856, 3424
	Field3428           uint32      // 857, 3428
	Field3432           uint32      // 858, 3432
	Field3436           uint32      // 859, 3436
	Field3440           uint32      // 860, 3440
	Field3444           uint32      // 861, 3444
	Field3448           uint32      // 862, 3448
	Field3452           uint32      // 863, 3452
	Field3456           uint32      // 864, 3456
	Field3460           uint32      // 865, 3460
	Field3464           uint32      // 866, 3464
	Field3468           uint32      // 867, 3468
	Field3472           uint32      // 868, 3472
	Field3476           uint32      // 869, 3476
	Field3480           uint32      // 870, 3480
	Field3484           uint32      // 871, 3484
	Field3488           uint32      // 872, 3488
	Field3492           uint32      // 873, 3492
	Field3496           uint32      // 874, 3496
	Field3500           uint32      // 875, 3500
	Field3504           uint32      // 876, 3504
	Field3508           uint32      // 877, 3508
	Field3512           uint32      // 878, 3512
	Field3516           uint32      // 879, 3516
	Field3520           uint32      // 880, 3520
	Field3524           uint32      // 881, 3524
	Field3528           uint32      // 882, 3528
	Field3532           uint32      // 883, 3532
	Field3536           uint32      // 884, 3536
	Field3540           uint32      // 885, 3540
	Field3544           uint32      // 886, 3544
	Field3548           uint32      // 887, 3548
	Field3552           uint32      // 888, 3552
	Field3556           uint32      // 889, 3556
	Field3560           uint32      // 890, 3560
	Field3564           uint32      // 891, 3564
	Field3568           uint32      // 892, 3568
	Field3572           uint32      // 893, 3572
	Field3576           uint32      // 894, 3576
	Field3580           uint32
	Field3584           uint32
	Field3588           uint32
	Field3592           uint32
	Frame3596           uint32
	Field3600           uint32         // 900, 3600
	Field3604           uint32         // 901, 3604
	field3608           uint32         // 902, 3608
	field3612           uint32         // 903, 3612
	field3616           uint32         // 904, 3616
	field3620           uint32         // 905, 3620
	field3624           uint32         // 906, 3624
	CameraFollowObj     *Object        // 907, 3628
	Pos3632Vec          types.Pointf   // 908, 3632
	Obj3640             *Object        // 910, 3640
	Journal             *PlayerJournal // 911, 3644, pointer to journal
	SummonOrderAll      uint32         // 912, 3648
	field3652           uint32
	Field3656           uint32
	field3660           uint32
	field3664           uint32
	field3668           uint32
	Field3672           uint32 // 3672
	Field3676           byte   // 3676, TODO: status?
	_                   [3]byte
	Field3680           uint32 // 920, 3680, TODO: some flags?
	Level               uint8  // 921, 3684
	_                   [3]byte
	Field3688           uint32
	Field3692           uint32
	SpellLvl            [137]uint32 // 3696
	BeastScrollLvl      [41]uint32  // 4244
	_                   [43]uint32
	Field4580           *MinimapItem // 1145, 4580
	ProtUnitHPCur       uint32       // 1146, 4584
	ProtPlayerGold      uint32       // 1147, 4588
	ProtUnitHPMax       uint32       // 1148, 4592
	ProtUnitManaCur     uint32       // 1149, 4596
	ProtUnitManaMax     uint32       // 1150, 4600
	ProtUnitExperience  uint32       // 1151, 4604
	ProtUnitMass        uint32       // 1152, 4608
	ProtUnitBuffs       uint32       // 1153, 4612
	ProtPlayerClass     uint32       // 1154, 4616
	ProtPlayerField2235 uint32       // 1155, 4620
	ProtPlayerField2239 uint32       // 1156, 4624
	ProtPlayerOrigName  uint32       // 1157, 4628
	Prot4632            uint32       // 1158, 4632
	Prot4636            uint32       // 1159, 4636
	Prot4640            uint32       // 1160, 4640
	ProtPlayerLevel     uint32       // 1161, 4644
	Field4648           int32        // 1162, 4648
	field4652           uint32       // 1163, 4652
	field4656           uint32       // 1164, 4656
	field4660           uint32       // 1165, 4660
	field4664           uint32       // 1166, 4664
	field4668           uint32       // 1167, 4668
	field4672           uint32       // 1168, 4672
	field4676           uint32       // 1169, 4676
	field4680           uint32       // 1170, 4680
	field4684           uint32       // 1171, 4684
	field4688           uint32       // 1172, 4688
	field4692           uint32       // 1173, 4692
	field4696           uint32       // 1174, 4696
	Field4700           uint32       // 1175, 4700
	NameFinal           [28]uint16   // 4704, server-approved player name // TODO: size is a wild guess
	SaveNameBuf         [4]byte      // 1190, 4760
	field4764           uint32       // 1191, 4764
	field4768           uint32       // 1192, 4768
	field4772           uint32       // 1193, 4772
	field4776           uint32       // 1194, 4776
	field4780           uint32       // 1195, 4780
	field4784           uint32       // 1196, 4784
	field4788           uint32       // 1197, 4788
	Field4792           uint32       // 1198, 4792
	data4796            [8]uint32    // 1199, 4796
}

func (p *Player) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *Player) String() string {
	return fmt.Sprintf("Player(%q)", p.Name())
}

func (p *Player) IsActive() bool {
	return p != nil && p.Active != 0
}

func (p *Player) Index() int {
	if p == nil {
		return -1
	}
	return int(p.PlayerInd)
}

func (p *Player) PlayerIndex() ntype.PlayerInd {
	if p == nil {
		return -1
	}
	return ntype.PlayerInd(p.PlayerInd)
}

func (p *Player) NetCode() int {
	if p == nil {
		return -1
	}
	return int(p.NetCodeVal)
}

func (p *Player) Gold() int {
	return int(p.GoldVal)
}

func (p *Player) CursorPos() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	return types.Pointf{
		X: float32(p.CursorVec.X),
		Y: float32(p.CursorVec.Y),
	}
}

func (p *Player) SetCursorPos(pos image.Point) {
	p.CursorVec = pos
}

func (p *Player) Pos3632() types.Pointf {
	if p == nil {
		return types.Pointf{}
	}
	return p.Pos3632Vec
}

func (p *Player) SetPos3632(pt types.Pointf) {
	p.Pos3632Vec = pt
}

func (p *Player) reset(ind ntype.PlayerInd) {
	*p = Player{
		PlayerInd:      byte(ind),
		Active:         1,
		SummonOrderAll: 4,
	}
}

func (p *Player) SObj() *Object {
	if p == nil {
		return nil
	}
	return p.PlayerUnit
}

func (p *Player) Info() *PlayerInfo {
	if p == nil {
		return nil
	}
	return (*PlayerInfo)(unsafe.Pointer(&p.info)) // inaccessible due to alignment issues
}

func (p *Player) OrigName() string {
	return p.Info().Name()
}

func (p *Player) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return p.Info().PlayerClass()
}

func (p *Player) SetName(v string) {
	alloc.StrCopy16(p.NameFinal[:], v)
}

func (p *Player) Name() string {
	return alloc.GoString16S(p.NameFinal[:])
}

func (p *Player) SaveName() string {
	return alloc.GoString(&p.SaveNameBuf[0])
}

func (p *Player) Serial() string {
	return alloc.GoStringS(p.SerialBuf[:])
}

func (p *Player) SetSerial(v string) {
	alloc.StrCopy(p.SerialBuf[:], v)
}

func (p *Player) Field2096() string {
	return alloc.GoStringS(p.Field2096Buf[:])
}

func (p *Player) SetField2096(v string) {
	alloc.StrCopy(p.Field2096Buf[:], v)
}

func (p *Player) CameraUnlock() { // nox_xxx_playerCameraUnlock_4E6040
	if p == nil {
		return
	}
	p.CameraFollowObj = nil
}

func (p *Player) CameraFollow(obj Obj) {
	if p == nil {
		return
	}
	p.CameraFollowObj = toObject(obj)
}

func (p *Player) CameraToggle(obj Obj) { // nox_xxx_playerCameraFollow_4E6060
	if p == nil {
		return
	}
	if p.CameraFollowObj == toObject(obj) {
		p.CameraUnlock()
	} else {
		p.CameraFollow(obj)
	}
}

func (p *Player) CameraTarget() *Object {
	if p == nil {
		return nil
	}
	return p.CameraFollowObj
}

func (p *Player) ObserveTarget() *Object { // nox_xxx_playerGetPossess_4DDF30
	if p == nil {
		return nil
	}
	if p.Field3680&2 == 0 {
		return nil
	}
	return p.CameraFollowObj
}

func (p *Player) Sub422140() {
	if p != nil {
		p.field3660 = 0xDEADFACE
		p.field3664 = 0xDEADFACE
	}
}

var (
	_ = [1]struct{}{}[97-unsafe.Sizeof(PlayerInfo{})]
	_ = [1]struct{}{}[0-unsafe.Offsetof(PlayerInfo{}.name)]
	_ = [1]struct{}{}[66-unsafe.Offsetof(PlayerInfo{}.playerClass)]
	_ = [1]struct{}{}[89-unsafe.Offsetof(PlayerInfo{}.nameSuff)]
)

type PlayerInfo struct {
	name        [50]byte // 2185 (+0) // TODO: size is a guess
	field2235   [4]byte  // 2235 (+50)
	field2239   [4]byte  // 2239 (+54)
	field2243   [4]byte  // 2243 (+58)
	field2247   [4]byte  // 2247 (+62)
	playerClass byte     // 562, 2251 (+66)
	isFemale    byte     // 562, 2252 (+67)
	field2253   [2]byte  // 2253 (+68)
	Field2255   byte     // 2255 (+70)
	field2256   [2]byte  // 2256 (+71)
	Field2258   byte     // 2258 (+73)
	field2259   [2]byte  // 2259 (+74)
	Field2261   byte     // 2261 (+76)
	field2262   [2]byte  // 2262 (+77)
	Field2264   byte     // 2264 (+79)
	field2265   [2]byte  // 2265 (+80)
	Field2267   byte     // 2267 (+82)
	Field2268   byte     // 2268 (+83)
	Field2269   byte     // 2269 (+84)
	Field2270   byte     // 2270 (+85)
	Field2271   byte     // 2271 (+86)
	Field2272   byte     // 2272 (+87)
	Field2273   byte     // 2273 (+88)
	nameSuff    [8]byte  // 2274 (+89)
}

func (p *PlayerInfo) C() unsafe.Pointer {
	return unsafe.Pointer(p)
}

func (p *PlayerInfo) PlayerClass() player.Class {
	if p == nil {
		return 0
	}
	return player.Class(p.playerClass)
}

func (p *PlayerInfo) SetPlayerClass(v player.Class) {
	p.playerClass = byte(v)
}

func (p *PlayerInfo) IsFemale() bool {
	if p == nil {
		return false
	}
	return p.isFemale != 0
}

func (p *PlayerInfo) SetIsFemale(v byte) {
	p.isFemale = v
}

func (p *PlayerInfo) Name() string {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.name[0])), len(p.name)/2)
	return alloc.GoString16S(arr[:])
}

func (p *PlayerInfo) SetName(v string) {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.name[0])), len(p.name)/2)
	alloc.StrCopy16(arr, v)
}

func (p *PlayerInfo) NameSuff() string {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.nameSuff[0])), len(p.nameSuff)/2)
	return alloc.GoString16S(arr[:])
}

func (p *PlayerInfo) SetNameSuff(v string) {
	arr := unsafe.Slice((*uint16)(unsafe.Pointer(&p.nameSuff[0])), len(p.nameSuff)/2)
	alloc.StrCopy16(arr, v)
}

func (p *PlayerInfo) Field2235() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2235))
}

func (p *PlayerInfo) Field2239() uint32 {
	return *(*uint32)(unsafe.Pointer(&p.field2239))
}

func (p *PlayerInfo) Field2253() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2253))
}

func (p *PlayerInfo) Field2256() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2256))
}

func (p *PlayerInfo) Field2259() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2259))
}

func (p *PlayerInfo) Field2262() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2262))
}

func (p *PlayerInfo) Field2265() uint16 {
	return *(*uint16)(unsafe.Pointer(&p.field2265))
}

func (p *PlayerInfo) SetField2235(v uint32) {
	*(*uint32)(unsafe.Pointer(&p.field2235)) = v
}

func (p *PlayerInfo) SetField2239(v uint32) {
	*(*uint32)(unsafe.Pointer(&p.field2239)) = v
}

func (p *PlayerInfo) SetField2253(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2253)) = v
}

func (p *PlayerInfo) SetField2256(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2256)) = v
}

func (p *PlayerInfo) SetField2259(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2259)) = v
}

func (p *PlayerInfo) SetField2262(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2262)) = v
}

func (p *PlayerInfo) SetField2265(v uint16) {
	*(*uint16)(unsafe.Pointer(&p.field2265)) = v
}
