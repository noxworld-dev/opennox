package noxrender

import (
	"bytes"
	"crypto/md5"
	"encoding/hex"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"io"
	"os"
	"path/filepath"
	"strings"
	"testing"

	"github.com/stretchr/testify/require"

	"github.com/noxworld-dev/opennox-lib/bag"
	"github.com/noxworld-dev/opennox-lib/noximage"
	"github.com/noxworld-dev/opennox-lib/noxtest"
)

var drawBlends = []struct {
	name string
	mult Color16
	conf blendConf
}{
	{name: "default"},
	{name: "alpha 100", conf: blendConf{
		alphaEnabled: true, alpha: 0xff,
	}},
	{name: "alpha 50", conf: blendConf{
		alphaEnabled: true, alpha: 0x80,
	}},
	{name: "alpha custom", conf: blendConf{
		alphaEnabled: true, alpha: 0xaa,
	}},
	{name: "colorize", conf: blendConf{colorize17: true}, mult: Color16{R: 0xff, G: 0, B: 0xff}},
	{name: "multiply", conf: blendConf{multiply14: true}, mult: Color16{R: 0xff, G: 0xaa, B: 0xff}},
	{name: "alpha 100 mult", conf: blendConf{
		multiply14:   true,
		alphaEnabled: true, alpha: 0xff,
	}, mult: Color16{R: 0xff, G: 0xaa, B: 0xff}},
	{name: "alpha 50 mult", conf: blendConf{
		multiply14:   true,
		alphaEnabled: true, alpha: 0x80,
	}, mult: Color16{R: 0xff, G: 0xaa, B: 0xff}},
	{name: "alpha custom mult", conf: blendConf{
		multiply14:   true,
		alphaEnabled: true, alpha: 0xaa,
	}, mult: Color16{R: 0xff, G: 0xaa, B: 0xff}},
}

var drawCases = []struct {
	name     string
	image    string
	imageInd int
	typ      int
	ops      map[int]Color16
	exp      []string
}{
	{image: "APA00001", typ: 4, exp: []string{
		"3025b96287195669def5f8ac83e76c4e",
		"3025b96287195669def5f8ac83e76c4e",
		"0773281b60891ca3da02520c77f12470",
		"36faf96e429bedb9ee586deb463bafc1",
		"c529c23007f1f297ce58c6e16870cb49",
		"c302782a877fd68910ec420fc01be728",
		"c302782a877fd68910ec420fc01be728",
		"4d246020ec770ce1381497da8af6aeab",
		"1f9ca1fa1a43b5a22783d78d029b8a36",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		3: {R: 0, G: 0xff, B: 0},
	}},
	{image: "Bsumon06", typ: 3, exp: []string{
		"9eabb0cec4ee3841d84566dd8206e265",
		"9eabb0cec4ee3841d84566dd8206e265",
		"d303599a27abd90068f5f2e65444196e",
		"00f55e67b57d113d4973c3bfaffb894e",
		"0ddcd0c455a9b9693af5b132ce724b7e",
		"11c1203c9626815fde394c42694b1ca0",
		"11c1203c9626815fde394c42694b1ca0",
		"73b60f0c41d8a7d49caa7829c15a69f9",
		"e6bfd57ed11b537545ddee6aa938c108",
	}},
	{image: "EGS00001", typ: 5, exp: []string{
		"4c7d630593a9a515b70aee245a6aa958",
		"b1e4fe18e6675ee08937726eb75a11e3",
		"2ba1aa9a07d21885f7d7f75d691406d0",
		"fbcde47b5ab30b779ca92d68dcb0d206",
		"4c7d630593a9a515b70aee245a6aa958",
		"c761575433aa281c4d72208e29282a6d",
		"c761575433aa281c4d72208e29282a6d",
		"2ba1aa9a07d21885f7d7f75d691406d0",
		"fbcde47b5ab30b779ca92d68dcb0d206",
	}},
	{image: "EPD00004", typ: 5, exp: []string{
		"dbe3e3b6116f29757a69ecd879fcb768",
		"2b2da6902026462ac9b9834ada3c403f",
		"e6d0c080e7b9143fc88494ecc80720de",
		"a8e34b876ebce1bed8815d50036f6038",
		"8bc1826384a69754385ce1422280ebd8",
		"4d51b96f4631abeb31ed92ec2a67cd05",
		"4d51b96f4631abeb31ed92ec2a67cd05",
		"f407fe7e0c06f9e2ae24bf345093b3df",
		"d2fafa9fc0142b1834a843c6a66a0bd0",
	}},
	{image: "EPSN0005", typ: 5, exp: []string{
		"fb3f0639f9d63d0e56627f0f301422f3",
		"4ab19dd2b7616c5fa36efc97480851fe",
		"aff199f6c4d865abb772351e24e07256",
		"a79f3d3d1614853d2ac0704b1275e360",
		"694db198a07f658da280e8fde8f4dc03",
		"c0617ff336813b4ea8d059f0498e2ade",
		"c0617ff336813b4ea8d059f0498e2ade",
		"3da3891590092043c673f37a9a1951b0",
		"253e3e8e18f9230f9f66ea0bc7f41484",
	}},
	{image: "EXLAN003", typ: 5, exp: []string{
		"a3a06637942030e010a593087ff13517",
		"b57cf1083ec42f71292df711165c0246",
		"66aea684325d6e4323866f80ad2a1793",
		"b7c1601281732bc94fda6a00b35bcd40",
		"40eb4032f36f95121fdc3198249eccfc",
		"f332f74595facb5b419e4b10b5d6f514",
		"f332f74595facb5b419e4b10b5d6f514",
		"abb976a5cfa4450a1d69246870805e88",
		"de9de975f270cd1bf4dcc3018b396528",
	}},
	{image: "fsdie17", typ: 5, exp: []string{
		"3f1fb34913698f2a0bdf943fee805459",
		"c59d57c7973114feb608d904b9623ecf",
		"6dfe8d9d21c37d2f965a739da396ba4c",
		"6e661070812380253d806c7412f86765",
		"45e8bf3ce6ee5abbb4813d40d1a26954",
		"3135e44408eb22950258109ca5f1fc7f",
		"3135e44408eb22950258109ca5f1fc7f",
		"cb1c631d04a6b19198ead953744c1f66",
		"4d40df0edb277173bdbaf43d7296a7a6",
	}},
	{image: "GHDIE003", typ: 5, exp: []string{
		"c5d6b9bfd1057cea9ed7eee0264bc96b",
		"37daf0a11a961648083b567b4f7a5621",
		"5a44a7cf2428c400dce2a54ae3f05b29",
		"7a3d92e66d0f20e0780d656a41e0a781",
		"f83afbc6b168eae1913777dea3cb6298",
		"840683001490a0a671c8ca006e8329c8",
		"840683001490a0a671c8ca006e8329c8",
		"98f5588ffa0e79389dbe6d7673392f8b",
		"87aa449cc5cf52d5b1ed452fe72e0981",
	}},
	{image: "hdg000v1", typ: 3, exp: []string{
		"f8f2f5e8cba8fd52c680ee53aad072ad",
		"f8f2f5e8cba8fd52c680ee53aad072ad",
		"d8ccf8cb2b6a880a83eea6c53a4532a5",
		"7170ab399717f281117e969c2e2f8935",
		"6e2c2c413b33f8d4d8636e16c8cae478",
		"289018d87428a172a0aa6e2de1f787bb",
		"289018d87428a172a0aa6e2de1f787bb",
		"857c5504c9addd9fa445184c56ebd3cd",
		"f009a827b04da2b3a3e16dfca3c1e7e9",
	}},
	{image: "Mgrdy31", typ: 3, exp: []string{
		"76290f904d302c4b30e2bdc761a04dfa",
		"76290f904d302c4b30e2bdc761a04dfa",
		"c008fcf18ac1be9bc77c72b456aec3b1",
		"7d11360e978ec2284909f899908b6982",
		"4a2837956d2e9fe2e0548cf1af2c1a40",
		"3267919c4528ab32fd9cc52bdb984f72",
		"3267919c4528ab32fd9cc52bdb984f72",
		"bc58b3ba5fdaf5e038c23442713f15c0",
		"e40fda82f1e80859e8f261399881d4af",
	}},
	{image: "MNLoadr1", typ: 3, exp: []string{
		"0a61078a45e47888cb47ae85057e195d",
		"0a61078a45e47888cb47ae85057e195d",
		"f897c1e1dac6020cbb4706d2c0101690",
		"380e630255dc20ec04be861adcd8f1af",
		"f149fc2244e99d9b39f6792ac6ffc0eb",
		"fa95207009d5b83876056117f6d88bf8",
		"fa95207009d5b83876056117f6d88bf8",
		"e1b8897fdb3c637e0de15ed95f654d12",
		"44aa6ac32b4a3d440912534f6c542c66",
	}},
	{image: "NFTK0181", typ: 4, exp: []string{
		"d82bea34510ab38387cf73dfab037576",
		"d82bea34510ab38387cf73dfab037576",
		"f39fff5bf3c78832370e9bf419af5875",
		"14f029cecaea7cc2425416eccba7801c",
		"0bef0212d4abe0f5fdb585479125fe69",
		"bf87795571cb71c3115d236b667f5035",
		"bf87795571cb71c3115d236b667f5035",
		"d227535871a546a0fe3b08879d106cdb",
		"e51a48996bf1b14797031dca29ef77bc",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		2: {R: 0, G: 0xff, B: 0},
		3: {R: 0, G: 0, B: 0xff},
		6: {R: 0, G: 0xff, B: 0xff},
	}},
	{image: "NHDT0013", typ: 5, exp: []string{
		"b651bddfc0df20a2864acf883b844f44",
		"943fcbe205741d513a572785f200fbe6",
		"6851a1a4526a0b4668fac7144bbcecd5",
		"fe32fe3fd7f43147eb6abe484b786fa7",
		"5feece65af223a19de468c8cd26ead55",
		"f010e4f25d489da1b2bad13a8c4ba4d5",
		"f010e4f25d489da1b2bad13a8c4ba4d5",
		"6e5946281411642dde98c07b0e056be6",
		"fe7acf628e11f96d7506d81cb369afb2",
	}},
	{image: "NHDT0163", typ: 5, exp: []string{
		"1997520c0af7a6e3ac948f6f1ab30c9d",
		"9e78c3e9295ab4ce0d336730b4c52a6b",
		"7eaa33bf63008a24d41e2d6e304b8e79",
		"db49bc0ba5c3f69c11156b1dbe2a79ee",
		"af5ad68b08b9e721f78f61816bb58cb3",
		"68bf743646a44e8088b9c46e3375be74",
		"68bf743646a44e8088b9c46e3375be74",
		"64e2c7201758de3eb626b38fa6f2b136",
		"415692320369f32e1770823c2141de7c",
	}},
	{image: "OGMM0001", typ: 5, exp: []string{
		"383f18bace01670a656d5db90346a8ce",
		"3c96c9445ab2593bace2d6916b9ec8dd",
		"f60671aee93fc77ab5562ed54e566202",
		"bc59fbfb1cb68896a4df1aed97aa9eca",
		"3d2c3493a27f4187c63ee999b1f41923",
		"e03b49d86331cb1dcfc48cc09d22c3ca",
		"e03b49d86331cb1dcfc48cc09d22c3ca",
		"4c8211ab889961da4cecab7e89dbff41",
		"9d8aad67b94fe6d6d68bf70ff2b64060",
	}},
	{image: "OGWW0002", typ: 5, exp: []string{
		"e504457b4ce8652348385a9513a28785",
		"5f08bd2c43464d3b538884b2b91c43b4",
		"f977cf92e565608288c143ba61c1e174",
		"bbd43fbc19246e650b9c28fbd0bc8fb7",
		"05eddb31107a0b051c7338eff1291460",
		"f2628bdf561fd67c0a733e8c8b381950",
		"f2628bdf561fd67c0a733e8c8b381950",
		"e43f65e179868e882aaed8031906832f",
		"8b49297d9b1df211f98c7f1f666469d0",
	}},
	{image: "OICS0001", typ: 3, exp: []string{
		"f030d9fa82ddbfa88c4cc31f52416125",
		"f030d9fa82ddbfa88c4cc31f52416125",
		"6a6abb4b1fffc3d8b803c12ce1ebfa42",
		"e77d7850fa18ca17ed481d5f2acd922c",
		"546d9a2ffc1ac9bf47f5f6cf78048e31",
		"f8c6ca659bb8cb0f7f191c975d3ea7cd",
		"f8c6ca659bb8cb0f7f191c975d3ea7cd",
		"9dc18e748b9e0426416ee4fde4b3d23a",
		"d36a8e306758dc429fd2bb94bc8273f5",
	}},
	{image: "OIX00002", typ: 5, exp: []string{
		"45e7ad1197e84c3d7f0f15deb573fd36",
		"557bd70beacb08a60ada0132fc4bf561",
		"6ece04f3ebd5c1cff6837c3f6b64948f",
		"f7c34a4d28765c39b1f3718480601b83",
		"1c7c056fbc0f7e2f14b0e19a1f4fa3e0",
		"8bd8209adb007a1ae9cd279e64ed2a2b",
		"8bd8209adb007a1ae9cd279e64ed2a2b",
		"0492e3461313f094f37d3fc05fe6ed3f",
		"e13bab5552fc9d707d3f0bc338019112",
	}},
	{image: "PGWBD001", typ: 3, exp: []string{
		"7b0891245d5df7460733895625ebe621",
		"7b0891245d5df7460733895625ebe621",
		"f808e6c4c8ba8534729b958879380c1a",
		"719c9b1daa74e50d714e218c8548d252",
		"48da9cc2b440a77f0bd3fcac31fe6de7",
		"55aa7486c849f97260ad8ae13b9b379d",
		"55aa7486c849f97260ad8ae13b9b379d",
		"273721ba5e5c491841661cc546a8a582",
		"ec9d36d5adcf582d03fc43b0d4bcacf6",
	}},
	{image: "PKA00002", typ: 4, exp: []string{
		"8f7c1fa7c92ad8e650b7d41cb996a759",
		"8f7c1fa7c92ad8e650b7d41cb996a759",
		"de860358f9828ff9ccc53f048f125bd4",
		"8c0b12f1d194b6f1be227e4ac1cc22a9",
		"9fc19bae1f44c286dd76c94d451fd71a",
		"55271da11194c293da6e26c949215e88",
		"55271da11194c293da6e26c949215e88",
		"c77a7796e85c3ccb04082a8282acd06b",
		"5f0907ea909eecf932e2be9de3fb1e62",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		3: {R: 0, G: 0xff, B: 0},
		4: {R: 0, G: 0, B: 0xff},
	}},
	{image: "PQMMGBA0", typ: 3, exp: []string{
		"7aaabc3e6c0c4f29e95e3f686c5191dc",
		"7aaabc3e6c0c4f29e95e3f686c5191dc",
		"1f48909bb95f2f9fb36364c55caa95ed",
		"4214acd36144768a04cfcbc4e8260f66",
		"71828e433536332709cdf67073241485",
		"4c234ba6e83aad636d358ecb823baac5",
		"4c234ba6e83aad636d358ecb823baac5",
		"81081d059b6ef0315399f6d882ed74ec",
		"b8c0367d784c5bf16307111481b2f9bc",
	}},
	{image: "QFER0002", typ: 5, exp: []string{
		"cd98becff59f78904b9f027a36646bb6",
		"13755b197a101caeae2c35ee7fb96998",
		"df58d074acbe39ea254d458da0f53a13",
		"da4eb6a045251585a259cad621eb4dda",
		"baf0a95c852bb8f303b7fc10aab72904",
		"5f9475ead61f88f484ffbb634a0e5089",
		"5f9475ead61f88f484ffbb634a0e5089",
		"f8db5197d3abf02a49a01d1e6c91f9b7",
		"f9c4c114d9197386ee391dcb526f8a88",
	}},
	{image: "UCU00000", typ: 3, exp: []string{
		"ea02eee7ca690a3d0643b52d27509944",
		"ea02eee7ca690a3d0643b52d27509944",
		"89176e9fb293e497e207eaaec31d2db2",
		"ccf4463461cbbe0d17468c1212139615",
		"da4813f38b3e53427be4d1086c0ff677",
		"9be3a38e6b3ac4663e298f9b921aa7a4",
		"9be3a38e6b3ac4663e298f9b921aa7a4",
		"63c51ae8789857ddfbe0f444663999dd",
		"889dab3a03f209bb6917d1b111eba8f4",
	}},
	{image: "UPACM001", typ: 4, exp: []string{
		"f365d6586204dd591449b9ae9e1ab37b",
		"f365d6586204dd591449b9ae9e1ab37b",
		"1a91ec0d16be1ef688db9cf84695aae4",
		"634c351701f757c54caff32f3e9f86f7",
		"9079fc57548893546bf419a7f4bc2f82",
		"129f32fddb7b7c9821346f9bce8f78e0",
		"129f32fddb7b7c9821346f9bce8f78e0",
		"a5a2796b1def24a92c062033afafcda1",
		"5ff7c2a3956fc3b4be899affc2e9663d",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		2: {R: 0, G: 0xff, B: 0},
		3: {R: 0, G: 0, B: 0xff},
		4: {R: 0, G: 0xff, B: 0xff},
	}},
	{image: "UPALA001", typ: 4, exp: []string{
		"a37144781cd0aa44aecf3720f19ea81b",
		"a37144781cd0aa44aecf3720f19ea81b",
		"1fc31ae058512cb12922b9e577174d6a",
		"0880b61cddfd01b49b27f4249862ffeb",
		"2fbc21fe224b9b70665368c6080d23c5",
		"0b1b5f1c78435da4f27877e699b06ede",
		"0b1b5f1c78435da4f27877e699b06ede",
		"dd3655a6dc125af9f85382b5d48008c6",
		"ab924ec96ed457e38ac7d77d10c0c101",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		3: {R: 0, G: 0, B: 0xff},
		4: {R: 0, G: 0xff, B: 0xff},
		5: {R: 0xff, G: 0xff, B: 0},
	}},
	{image: "UPBH0001", typ: 4, exp: []string{
		"910d7a9d1e5009a3fa7f7ed69f8d92d8",
		"910d7a9d1e5009a3fa7f7ed69f8d92d8",
		"8babb34382d6ba1acafeafdc287a96a3",
		"de879c921c35256ca18e086f0a9b70b3",
		"eb1027a55fab86d8465dc44b932a1f1f",
		"e2dadb406be7d874455b5645a3bbba0d",
		"e2dadb406be7d874455b5645a3bbba0d",
		"83ed11da9ed122c880762eee5eeffe58",
		"afc4f8465d43e6d9c75f0add54ab34b8",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		2: {R: 0, G: 0xff, B: 0},
		4: {R: 0, G: 0, B: 0xff},
		5: {R: 0, G: 0xff, B: 0xff},
		6: {R: 0xff, G: 0xee, B: 0xee},
	}},
	{image: "WAZWD002", typ: 3, exp: []string{
		"b6fcca4f3a15e082ddd3428bd29c584c",
		"b6fcca4f3a15e082ddd3428bd29c584c",
		"029bd6ca15a42ccf35970264ccd146bb",
		"66926fe56521cfbac39be700891aad25",
		"66da687be67aabb50173c38d41bb44c7",
		"b821407a3549a6645d00a87b397697a0",
		"b821407a3549a6645d00a87b397697a0",
		"443bd2d617734750443f0b2b781d69e9",
		"445ada322482a26dd49df7e5cb51637b",
	}},
	{image: "XABALA55", typ: 4, exp: []string{
		"c841846c3046b34530f1c8da92463930",
		"c841846c3046b34530f1c8da92463930",
		"6ce8c85a29b8e23b3d8a60d30e1e8005",
		"539e45402e393e8477297c61a40f154b",
		"3b5d7f6a3a9d3b75be2a3392ea0d8b49",
		"578267e1bc7f161c07ba211f2ba8cdb9",
		"578267e1bc7f161c07ba211f2ba8cdb9",
		"8c75ce3f0b0e0ac544d74cba7e28ea44",
		"9fc0561a065fb67dbf3879348882e7b1",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0xaa, B: 0xaa},
		3: {R: 0, G: 0xcc, B: 0xff},
		4: {R: 0, G: 0xff, B: 0},
		5: {R: 0xff, G: 0xff, B: 0},
	}},
	{image: "XICWR050", typ: 4, exp: []string{
		"f66484fea9b416cd9553b5734c2862bf",
		"f66484fea9b416cd9553b5734c2862bf",
		"55be2677639fbf1eb6fc6979234cc5c4",
		"6e422a93136d8aa9154874a55750d0b1",
		"953d1fbd1f9dd96e69aa2f6ed494cd73",
		"600e19be66ce24054a01f8e901b5b85a",
		"600e19be66ce24054a01f8e901b5b85a",
		"57ead8aaab013fba2848bc874da473c5",
		"775f0f34d695ec94a698630e2fef442a",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		2: {R: 0, G: 0xbb, B: 0xff},
		3: {R: 0, G: 0xff, B: 0},
		4: {R: 0xff, G: 0xff, B: 0},
	}},
	{image: "XSTAFN93", typ: 3, exp: []string{
		"2a67ba304ea8554c9e6e23ffe3190729",
		"2a67ba304ea8554c9e6e23ffe3190729",
		"795bc11b7011db8a9fd13472857e87c1",
		"79a90f968610a2d467b4d2265ef67d8b",
		"fa712540b6e40034a8463179d4c46272",
		"39828ad113ffda232e6c015ded1cd509",
		"39828ad113ffda232e6c015ded1cd509",
		"9b30acb0142c26c9c2a5b27337c53a31",
		"2456ebf6925303cbd2ab098184b8e802",
	}},
}

func newBackgroundPattern16(w, h int) *noximage.Image16 {
	pix := noximage.NewImage16(image.Rect(0, 0, w, h))
	step := h
	if w < h {
		step = w
	}
	step /= 8
	if step == 0 {
		step = 1
	}
	black := image.NewUniform(color.Black)
	white := image.NewUniform(color.White)
	for y := 0; y < h; y += step {
		for x := 0; x < w; x += step {
			c := black
			if (x+y)/step%2 != 0 {
				c = white
			}
			clip := image.Rect(x, y, x+step, y+step)
			draw.Draw(pix, clip, c, image.Pt(0, 0), draw.Src)
		}
	}
	return pix
}

func TestDrawImage(t *testing.T) {
	datadir := noxtest.DataPath(t)
	f, err := bag.Open(filepath.Join(datadir, "video.bag"))
	require.NoError(t, err)
	defer f.Close()
	debug := os.Getenv("NOX_RENDER_DEBUG") == "true"
	var (
		h   = md5.New()
		buf bytes.Buffer
	)
	const outDir = ".testOut"
	if debug {
		err = os.MkdirAll(outDir, 0755)
		require.NoError(t, err)
	}
	for _, c := range drawCases {
		name := c.name
		if name == "" {
			name = c.image
		}
		t.Run(name, func(t *testing.T) {
			var bim *bag.ImageRec
			if c.imageInd == 0 {
				bim, err = f.ImageByName(c.image)
				require.NoError(t, err)
			} else {
				imgs, err := f.Images()
				require.NoError(t, err)
				bim = imgs[c.imageInd]
			}
			data, err := bim.Raw()
			require.NoError(t, err)
			hdr, sz, err := bim.DecodeHeader()
			require.NoError(t, err)
			t.Logf("typ: %d, off: %v", int(hdr.Type), hdr.Point)
			require.Equal(t, c.typ, int(hdr.Type))
			if debug {
				pimg, err := bim.Decode()
				require.NoError(t, err)
				f, err := os.Create(filepath.Join(outDir, c.image+".png"))
				require.NoError(t, err)
				defer f.Close()
				err = png.Encode(f, pimg)
				require.NoError(t, err)
			}

			img := NewRawImage(int(bim.Type), data)
			csz := image.Point{
				X: (sz.X + hdr.Point.X) * 2,
				Y: (sz.Y + hdr.Point.Y) * 2,
			}
			pos := image.Pt(sz.X/2, sz.Y/2)

			for i, b := range drawBlends {
				t.Run(b.name, func(t *testing.T) {
					pix := newBackgroundPattern16(csz.X, csz.Y)
					d := newRenderData(csz.X, csz.Y)
					for k, v := range c.ops {
						d.colorMultOp[k] = v
					}
					d.blendConf = b.conf
					if b.mult != (Color16{}) {
						d.colorMult = b.mult
					}

					r := NewRender()
					r.SetPixBuffer(pix)
					r.SetData(d)

					r.DrawImage16(img, pos)

					h.Reset()
					buf.Reset()

					var w io.Writer = h
					if debug {
						fname := filepath.Join(outDir, c.image+"_"+strings.ReplaceAll(b.name, " ", "_")+".png")
						out, err := os.Create(fname)
						require.NoError(t, err)
						defer out.Close()
						w = io.MultiWriter(w, out)
					}
					err = png.Encode(w, pix)
					require.NoError(t, err)

					got := hex.EncodeToString(h.Sum(nil))
					skip := false
					exp := ""
					if i < len(c.exp) {
						exp = c.exp[i]
					}
					if exp == "" {
						skip = true
						t.Logf("%q", got)
					} else {
						require.Equal(t, exp, got)
					}
					if debug {
						rgba := image.NewNRGBA(pix.Rect)
						draw.Draw(rgba, pix.Rect, pix, image.Pt(0, 0), draw.Src)
						h.Reset()
						h.Write(rgba.Pix)
						rgbaHex := hex.EncodeToString(h.Sum(nil))
						t.Logf("RGBA32: %q", rgbaHex)
					}
					require.Empty(t, d.colorMultMiss)
					if skip {
						t.SkipNow()
					}
				})
			}
		})
	}
}
