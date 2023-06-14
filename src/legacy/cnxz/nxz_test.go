package cnxz_test

import (
	"crypto/sha1"
	"encoding/hex"
	"io"
	"os"
	"path/filepath"
	"testing"

	"github.com/noxworld-dev/opennox-lib/ifs"
	"github.com/noxworld-dev/opennox-lib/noxtest"
	"github.com/stretchr/testify/require"

	"github.com/noxworld-dev/opennox/v1/legacy/cnxz"
)

func TestDecompress(t *testing.T) {
	maps := noxtest.DataPath(t, "maps")
	files, err := os.ReadDir(maps)
	require.NoError(t, err)
	all := make(map[string]string)
	defer t.Logf("%#v", all)
	for _, fi := range files {
		mname := filepath.Join(maps, fi.Name(), fi.Name()+".map")
		zname := filepath.Join(maps, fi.Name(), fi.Name()+".nxz")
		if _, err = ifs.Stat(zname); err != nil {
			continue
		}
		t.Run(fi.Name(), func(t *testing.T) {
			mexp, mexpN := hashFile(t, mname)
			gotc, gotcN := decompressC(t, zname)
			require.Equal(t, mexpN, gotcN)
			require.Equal(t, mexp, gotc)
			all[fi.Name()] = mexp

			known, ok := knownMap[fi.Name()]
			require.True(t, ok)
			require.Equal(t, known, mexp)
		})
	}
}

func TestCompress(t *testing.T) {
	maps := noxtest.DataPath(t, "maps")
	files, err := os.ReadDir(maps)
	require.NoError(t, err)
	all := make(map[string]string)
	defer t.Logf("%#v", all)
	for _, fi := range files {
		mname := filepath.Join(maps, fi.Name(), fi.Name()+".map")
		zname := filepath.Join(maps, fi.Name(), fi.Name()+".nxz")
		if _, err = ifs.Stat(zname); err != nil {
			continue
		}
		t.Run(fi.Name(), func(t *testing.T) {
			mexp, mexpN := hashFile(t, zname)
			gotc, gotcN := compressC(t, mname)
			require.Equal(t, mexpN, gotcN)
			require.Equal(t, mexp, gotc)
			all[fi.Name()] = mexp

			known, ok := knownNXZ[fi.Name()]
			require.True(t, ok)
			require.Equal(t, known, mexp)
		})
	}
}

func decompressC(t testing.TB, path string) (string, int) {
	out, err := os.CreateTemp("", "nxzmap_*.map")
	require.NoError(t, err)
	defer func() {
		out.Close()
		_ = os.Remove(out.Name())
	}()
	err = cnxz.DecompressFile(path, out.Name())
	require.NoError(t, err)
	return hashFile(t, out.Name())
}

func compressC(t testing.TB, path string) (string, int) {
	out, err := os.CreateTemp("", "nxzmap_*.nxz")
	require.NoError(t, err)
	defer func() {
		out.Close()
		_ = os.Remove(out.Name())
	}()
	err = cnxz.CompressFile(path, out.Name())
	require.NoError(t, err)
	return hashFile(t, out.Name())
}

func hashReader(t testing.TB, r io.Reader) (string, int) {
	h := sha1.New()
	n, err := io.Copy(h, r)
	require.NoError(t, err)
	return hex.EncodeToString(h.Sum(nil)), int(n)
}

func hashFile(t testing.TB, path string) (string, int) {
	f, err := ifs.Open(path)
	require.NoError(t, err)
	defer f.Close()
	return hashReader(t, f)
}

var knownMap = map[string]string{
	"BankShot": "02dc0b538163110f0d65be346b01ce8bc1d3033f",
	"BluDeath": "91f4fafa47305754cf5446525f8112f85d7e0082",
	"Bunker":   "e9d85366d9607c3b43e3207f8e1a2c781d2e85bb",
	"CapFlag":  "143b12a5306ad475197bf637410d7c4e4d51d190",
	"EndGame":  "d790407896f8ddacc26798974350d7874faef08c",
	"Estate":   "1ee08fc870f7ff5529c1cb5cf36ad15dd7f0733a",
	"FlagBall": "8422cfc81283dcd9b0c7d56949047b4007a9a830",
	"FlagWar":  "ff83c039ca6f978e4510999f7a8fa9b614a5c6ea",
	"FortNox":  "65eb96b1b42d175d2dc51efe625bdf2aac62b424",
	"Fortress": "21a42c91581f2adb9aceb101c045d3311e3a94f0",
	"FreezOut": "638093db34fe511b9a5edaf14374f6020a5c2717",
	"G_CastlD": "7f40b314a71726ffbd7ce3da58cf1eff913473fe",
	"G_Castle": "0df92aaef167fd392dacd674dad0927bc47969de",
	"G_CryptD": "442220a231101efc4626489f25dc53bc085571fe",
	"G_Crypts": "1a72f10851427faef3af3421add4244204cbe0eb",
	"G_ForesD": "6d46ede5148b04a811aa47fd50e798e2550e6568",
	"G_Forest": "3d7bfea269817d59af3597e5373b362eb6d8c197",
	"G_LOTD":   "102fd4ebf35288cacdbee1fb3434f253506efb72",
	"G_LOTDD":  "f74f5b259a3ae6120d068d04a962c337b01b93ae",
	"G_Lava":   "f685fe254d1fe4ff6d748ec5c712c7e7079593d9",
	"G_Mines":  "e64e015917190742ada66f0dbadda618c51a089c",
	"G_Swamp":  "f0c5a8d611777f6414a9cb905429f981a4c2a12d",
	"G_TemplD": "25cb90b016cdc2f520cac9f6cd842aae1304f91a",
	"G_Temple": "b19fc0c688b8eb612c3f76ce7869b7104bf101be",
	"Inferno":  "2cefcc00bfd9ed11e728ac4158163dc08dfc8e76",
	"Kingdoms": "ab7f727ef1dda32eefafa269d61b47796d6903c9",
	"Library":  "c8685a35fc78e0a1f37603501e3174655c508fb7",
	"LostTomb": "a027d877f9b686091ab77aea6ff21712fe36ede0",
	"ManaMine": "bc5c7dcf6cde17678c09c73e7ecd740849938a3e",
	"MiniMine": "66279862814368589918c3b4319f7dbd1d007b82",
	"MnaVault": "2e4f1ea9270983aedb37c18e10011633169af027",
	"Oasis":    "d4378f8f1bf05634722d54eba29eaed2fb99fa00",
	"So_Beach": "994fad5a09e1477fc2b083a299576ad6f31dd2df",
	"So_Brin":  "94d009b3a7f390836004ab7ffa1bb5feabad550e",
	"So_Druid": "fc70743ca0d63e5e77f1b11f598f5832698fb597",
	"So_Dun":   "70588c44fafa76b97bc99d033ddd1d6b0bb3172d",
	"So_FOV":   "102193d9603d572b55a1e4f63fb8786f73c33290",
	"So_Galav": "7360e6a30c04656f8ffa190c319ebf8d0a349256",
	"So_Grok":  "7779fdf85d735e924e89b233476079ee53db7e41",
	"So_Ix":    "2fe8580707a048d12b1f565d95f85bf0f87b81a0",
	"So_LOD":   "0891da797c58203504c55e589be54a3850f825a4",
	"So_Mines": "bdc2ad0c0c67e4e1c90e947051f93672bf6479d2",
	"So_Mount": "b255e2a3375b00f8d79f25fd230674e28e8ba7ae",
	"So_Open":  "a99c6a4fda59867f43309a6a453e7335d4670f5a",
	"So_Swamp": "8d3b90e3768c5ecaf3593371ae6ade161d1f5dad",
	"So_Waste": "fb673c15580e9b9dfcb461297582ace728cdd320",
	"So_Woods": "23c65216c3531637a8d273949423272c29c620dc",
	"SpyFort":  "39cc78cca7ce9fc7f39c65a604e2e94efcc08dae",
	"TreeHaus": "26409e39086458a045613a327ae717afc7d1a455",
	"TriLevel": "e3db0cd7398d6bace8500fd649fe45375a85c130",
}

var knownNXZ = map[string]string{
	"BankShot": "faf124081214b592aa07f56b671f7181b8b20ecf",
	"BluDeath": "f90fc4e3bb03a547d9e782c59a66e03f662f1fba",
	"Bunker":   "c19bd6ae86f336799415f48055d6784b86fc3591",
	"CapFlag":  "f5b08c00c9cd56cd28ee1958cb7fbb69aaf24826",
	"EndGame":  "5300e6a9e0eb0f9fe549f753bfc42fe3d316d1dd",
	"Estate":   "9f7aea338e343fe3e58520ad83d9b6e90edef00a",
	"FlagBall": "c61f2ce9fd6f0cf45569e74095384324824ba51a",
	"FlagWar":  "2054c9ef5e789a94d9ade27bd62981af66b90357",
	"FortNox":  "5be9c55636854c90079a5cf2aa190aa719e3eeed",
	"Fortress": "c6267d305ec6232eaec2f3365c9b4bafbd992602",
	"FreezOut": "d71765ffa8e7c000aba407f2a5e2287199afbc09",
	"G_CastlD": "4eb31c5d90b6cd31da1ca7c8e8fd987b1d0e5566",
	"G_Castle": "8c33a08c4804247660942a4941bec74faab15597",
	"G_CryptD": "8ab9f6514683f84f895db867278b1edb61bae6b3",
	"G_Crypts": "57691e5ab5e0d1b3bf78f713b7a64d8d2d3517d5",
	"G_ForesD": "f52c3447facecd975024f879b0651fec5dfdbdc3",
	"G_Forest": "645062f73d3234ff7893a249f1660597466b82b6",
	"G_LOTD":   "d3a53835b2a28591a3ebfe971e6b2550bfb52ac7",
	"G_LOTDD":  "22fa0ed6afa5a6e61a024dde68ab41c46b295fe4",
	"G_Lava":   "4f3568e9ad4eacd666db89bb7f8d536bff54fff2",
	"G_Mines":  "2c79ebfdfaa236574a2fd4ff0021aeac4bfd3137",
	"G_Swamp":  "11096b5747921aa08f0140acf08ffb8790de94fa",
	"G_TemplD": "80ce2e57a2659f425a982a3b11cab05b508f1754",
	"G_Temple": "a471137dd6a25b3a5f20ed1aacd0805c82d5b482",
	"Inferno":  "57f1a2bda06bdc49bef1c297b007aa5e75c49b08",
	"Kingdoms": "b6fbf1a36c399dba5571e11396f36da6526bdd1a",
	"Library":  "bec03278af98599253504853d7e279ae3f528213",
	"LostTomb": "ce7da83ff629194d85d3c96351d2a27e6f9bffda",
	"ManaMine": "20358f705202038241a6b676d95652cf11e6280c",
	"MiniMine": "99b535049d6d3d972e3b7d8ec1d9903707f9926f",
	"MnaVault": "d503bcab8f4b85d26816c9694a5a53bc7ec4ce8f",
	"Oasis":    "a7a0bea0675380d5c6efe3684bfe44ca71e01473",
	"So_Beach": "df6b45c12297dbdc434794798ff3ac678312dd65",
	"So_Brin":  "e9c38635aff4795bfabc3c8c0ac098c959aabe2f",
	"So_Druid": "28d0ae20ae8ed749463a2be05e724946f9b88cd8",
	"So_Dun":   "1aa2d83b21e00968ecc8782a9517d1bad012c7ce",
	"So_FOV":   "7072b35b3111a25e0ca97c8c6f85399ba973f80a",
	"So_Galav": "e423532a385ed4f042fb7f9f1ee30eca6e139f30",
	"So_Grok":  "f05951eb159bddc726019dd1ecad6141f6c5985d",
	"So_Ix":    "f2cbe801f25ae00ba6f4edd36dcc08b03fc06314",
	"So_LOD":   "db6e82e14a63856ddcedda1cbd709c8797e51376",
	"So_Mines": "5d1d105adb775953fee791efc80ed28d7063d4e6",
	"So_Mount": "b516d792eb373e44572237b09a87dfbb811df852",
	"So_Open":  "090eede120fd12dfedea93e99486d067dacc6721",
	"So_Swamp": "e73a1c06e17b22a8a8dff92274ec3cd54821bc0a",
	"So_Waste": "994e33defdb45a9f05dad45dcaeb9e1df82c0e1c",
	"So_Woods": "bd6d6b0c1f910ec388301f433b8fc8838c978c24",
	"SpyFort":  "a86346182caa80a42cc4bc575474931a3af85a95",
	"TreeHaus": "f9ded28d499bcb402247c98db246fa8ab8e66b6e",
	"TriLevel": "420dfd339cf9089f09a4feb697e7f9f995289812",
}
