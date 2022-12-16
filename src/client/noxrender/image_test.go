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
		"b0986ab5abb96327e61b51b5f463e9a7",
		"b0986ab5abb96327e61b51b5f463e9a7",
		"af632036e3b488c17b12f26b664acc96",
		"ce999e49b83889cdfc7e72846be9e111",
		"cf36a4a0af8b7a850321ca8fc9a028f5",
		"87098cdbbb1fba4ee85e4972a84b7000",
		"87098cdbbb1fba4ee85e4972a84b7000",
		"c5afb4e593ac03c283db512d200a7bca",
		"55033061f1e05604b2eb3546cadc0efc",
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
		"f358578b4aa1c0ee777ce927e9200d53",
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
		"23ad7bc0b574cb7251ef60a741b8d134",
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
		"a1fead968ca44cbf76d59095d3ed28fd",
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
		"b81b17d275e7804acbc227983ba3bcba",
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
		"cef05356619b2bb28a98d24a39041f40",
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
		"a2f8d77e7425db3bbdfa0b1bb11d2066",
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
		"7f54c4af686745990c8a4120eba54996",
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
		"70eacd4fccacf15223920272b690a6e5",
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
		"5e5cf49d9683e1e7a835f3938ef0d7ee",
		"44aa6ac32b4a3d440912534f6c542c66",
	}},
	{image: "NFTK0181", typ: 4, exp: []string{
		"6de944c2a44e097a9d32772e5f742a57",
		"6de944c2a44e097a9d32772e5f742a57",
		"1be122ade9a68030f20b6ed158178b83",
		"d649aadc8fa30d0a24f0afd6ae7bb960",
		"e83f6bd916ad481f673c8497a7c4245b",
		"979a4c9df3690f80995d4349789349ab",
		"979a4c9df3690f80995d4349789349ab",
		"cc31c80d335777a455219a2179f7929e",
		"6794654d77124623e6c486711639be20",
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
		"def292874545fcdfe9ac9f46b04480cf",
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
		"3ea0568ae546ba5c9ca3c2afe70568f5",
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
		"6a70b9ac10d4c5e68f9eb9cf900370b2",
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
		"43ed456afaeb117b69e71350efdb89cd",
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
		"2e0bfe49a1e2f93df4b3c7b446026732",
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
		"9b85b4da51a9e98370723af742a742bc",
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
		"82af02ac4010b6b01289404649da6433",
		"ec9d36d5adcf582d03fc43b0d4bcacf6",
	}},
	{image: "PKA00002", typ: 4, exp: []string{
		"5031462ad86f772dce6a2a2e29dc3a3d",
		"5031462ad86f772dce6a2a2e29dc3a3d",
		"313ae234fbfd8146ecd067523f9cb6c3",
		"179d7cc285ae6d8c30ec5ec54d06ff1a",
		"527388f37613040064e4516646006148",
		"6f85b5988c1af58c67c123597bea74c9",
		"6f85b5988c1af58c67c123597bea74c9",
		"e33057ccf1470e62deaf83cf31633878",
		"be4c7a4681bebc36b34b532414ea6293",
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
		"5c5d5f7445c0a3483b2b95c4a919ac3f",
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
		"f00509f77fe28dd51b4e08b697333896",
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
		"a4581e216375d7b62212d92e522e3cc0",
		"889dab3a03f209bb6917d1b111eba8f4",
	}},
	{image: "UPACM001", typ: 4, exp: []string{
		"7e73fb7146ff89157940fcea86276082",
		"7e73fb7146ff89157940fcea86276082",
		"7793332676a1817227328887351b720a",
		"401eff92739de9e82f23c2bf22e9ed31",
		"6c8386876f19d3370ad389272a1b8ada",
		"883f13c557fce3dc31887ab27a08220c",
		"883f13c557fce3dc31887ab27a08220c",
		"3d65594ada295a220d829679a580de78",
		"484418a1e75b814dbd47cff4ad4b5caa",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		2: {R: 0, G: 0xff, B: 0},
		3: {R: 0, G: 0, B: 0xff},
		4: {R: 0, G: 0xff, B: 0xff},
	}},
	{image: "UPALA001", typ: 4, exp: []string{
		"1bbd16ef42c82a9a844c4e4fc5c840e7",
		"1bbd16ef42c82a9a844c4e4fc5c840e7",
		"70c5b83dc3c8a31845bb124e2176a318",
		"21fa74e2be0efce1ca7f2b514ff8b3f9",
		"674f9c768eaba22cfd8b9a88d9848a6c",
		"6d7a574befc603664a9e85c5dd24a5e8",
		"6d7a574befc603664a9e85c5dd24a5e8",
		"f9ec86e1936e54455f1a354f9036ec55",
		"0820f5b474ffd674c66aa8cdd1523f5b",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0, B: 0},
		3: {R: 0, G: 0, B: 0xff},
		4: {R: 0, G: 0xff, B: 0xff},
		5: {R: 0xff, G: 0xff, B: 0},
	}},
	{image: "UPBH0001", typ: 4, exp: []string{
		"26fee38fc6c225980353886462e10cfe",
		"26fee38fc6c225980353886462e10cfe",
		"fdfcca0a029b0bd9467a3aa5f8a8cffd",
		"fb74072a84ffe3d5e8b9f5aaf7561122",
		"d76389681a72693ae5b14828bbccc3c5",
		"cdb820697546908c0345cc06c06c8779",
		"cdb820697546908c0345cc06c06c8779",
		"4754ac080c7ec26333b2cf59e1510e18",
		"14beee4449551b355cb228093684bbd6",
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
		"1505d15c8a7144b56a9f8a3c62c848a0",
		"445ada322482a26dd49df7e5cb51637b",
	}},
	{image: "XABALA55", typ: 4, exp: []string{
		"a4bb6ed8695192c88875f6f704c8ce4a",
		"a4bb6ed8695192c88875f6f704c8ce4a",
		"ec01eaa031a93ac2c4406b277a5ad8d6",
		"184aef6ffac8d85a053a2aa676ce3093",
		"e7c4f4b8c486ef05349e467be894bbeb",
		"9fa60eef1cad1ce35c1e3bd93782f9cf",
		"9fa60eef1cad1ce35c1e3bd93782f9cf",
		"2fd749d6ed5cc5ba0fca50f28c0d954e",
		"907297cc35de10e282a1208bdbb85f2f",
	}, ops: map[int]Color16{
		1: {R: 0xff, G: 0xaa, B: 0xaa},
		3: {R: 0, G: 0xcc, B: 0xff},
		4: {R: 0, G: 0xff, B: 0},
		5: {R: 0xff, G: 0xff, B: 0},
	}},
	{image: "XICWR050", typ: 4, exp: []string{
		"9217b4f1ffeab95a36b24401b454a721",
		"9217b4f1ffeab95a36b24401b454a721",
		"96990e546c8f8c19df32671ec0e674c3",
		"a4715635facc1c0e5007b0c674c00948",
		"b6b51e0dbd2ab4c416d025bd4822c5f4",
		"9dd219e094b7241c27c55e0701b67594",
		"9dd219e094b7241c27c55e0701b67594",
		"dbe65d5bd495bce32936a2b23360986c",
		"6dc51e657caf8b2f542870664067650e",
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
		"45138cfb5a18a5c98cf0b935f90bc0c7",
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
						//d.colorMultOp[k] = v
						d.SetMaterial(k, v.Make())
					}
					b.conf.SetTo(d)
					if b.mult != (Color16{}) {
						d.SetColorMultA(b.mult)
					}

					r := NewRender(nil)
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
					//require.Empty(t, d.colorMultMiss)
					if skip {
						t.SkipNow()
					}
				})
			}
		})
	}
}
