package c2gotok

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"testing"

	"github.com/stretchr/testify/require"
)

const testInput = `
#include "defs.h"
#include "input.h"

extern uint32_t nox_server_resetQuestMinVotes_229988;
extern uint32_t nox_server_kickQuestPlayerMinVotes_229992;

unsigned int g_scaled_cfg = 0;
#ifdef NOX_CGO
//----- (004317B0) --------------------------------------------------------
int nox_common_readcfgfile(const char* path, int a2);
#endif // NOX_CGO
//----- (004317B0) --------------------------------------------------------
int nox_common_readcfgfile(const char* path, int a2) {
	sub_42CD90();
	FILE* file = nox_fs_open_text(path);
	if (file) {
		if (a2 || nox_common_parsecfg_all(file)) {
			if (nox_common_skipcfgfile_4331E0(file, (int)a2)) {
				nox_fs_close(file);
				return 1;
			}
		}
		nox_fs_close(file);
		file = 0;
	}
	sub_42CD90();
	file = (int*)nox_fs_open_text("default.cfg");
	if (!file) {
		return 0;
	}
	if (!(a2 || nox_common_parsecfg_all(file))) {
		nox_fs_close(file);
		return 0;
	}
	if (!nox_common_skipcfgfile_4331E0(file, a2)) {
		nox_fs_close(file);
		return 0;
	}
	if int(*a)&b == 0 {
		return 0;
	}
#ifdef NOX_CGO
	*(uint32_t*)&dword_5d4594_805836 = 0;
	*(uint16_t* *)dword_5d4594_805836 = 0;
#endif // NOX_CGO
	do {
		nox_fs_close(file);
		nox_common_writecfgfile("nox.cfg");
	} while (a < 10);
	return 1;
}
`

func TestTokens(t *testing.T) {
	toks := Tokenize([]byte(testInput))
	f, err := os.Create("tokens.txt")
	require.NoError(t, err)
	defer f.Close()
	for _, t := range toks {
		fmt.Fprintf(f, "%d\t%s\t%q\n", t.Pos, t.Tok.String(), t.Lit)
	}
	var buf bytes.Buffer
	Print(&buf, toks)
	require.Equal(t, testInput, buf.String())
}

const testExpC2Go = `
#include "defs.h"
#include "input.h"

extern uint32 nox_server_resetQuestMinVotes_229988;
extern uint32 nox_server_kickQuestPlayerMinVotes_229992;

uint32 g_scaled_cfg = 0;
#ifdef NOX_CGO
//----- (004317B0) --------------------------------------------------------
int nox_common_readcfgfile(byte* path, int a2);
#endif // NOX_CGO
//----- (004317B0) --------------------------------------------------------
int nox_common_readcfgfile(byte* path, int a2) {
	sub_42CD90();
	FILE* file = nox_fs_open_text(path);
	if file {
		if a2 || nox_common_parsecfg_all(file) {
			if nox_common_skipcfgfile_4331E0(file, int(a2)) {
				nox_fs_close(file);
				return 1;
			}
		}
		nox_fs_close(file);
		file = 0;
	}
	sub_42CD90();
	file = (*int)nox_fs_open_text("default.cfg");
	if !file {
		return 0;
	}
	if !(a2 || nox_common_parsecfg_all(file)) {
		nox_fs_close(file);
		return 0;
	}
	if !nox_common_skipcfgfile_4331E0(file, a2) {
		nox_fs_close(file);
		return 0;
	}
	if int(*a)&b == 0 {
		return 0;
	}
#ifdef NOX_CGO
	*(*uint32)(&dword_5d4594_805836)= 0;
	*(**uint16)(dword_5d4594_805836)= 0;
#endif // NOX_CGO
	for {
		nox_fs_close(file);
		nox_common_writecfgfile("nox.cfg");
		if !(a < 10) {
			break
		}
	}
	return 1;
}
`

func TestTokensC2Go(t *testing.T) {
	toks := Tokenize([]byte(testInput))
	toks = C2Go(toks)
	var buf bytes.Buffer
	Print(&buf, toks)
	err := os.WriteFile("tokens_c2go.txt", buf.Bytes(), 9644)
	require.NoError(t, err)
	require.Equal(t, testExpC2Go, buf.String())
}

func TestTokensAll(t *testing.T) {
	var (
		fbuf, buf bytes.Buffer
	)
	const dir = "../../"
	list, err := os.ReadDir(dir)
	require.NoError(t, err)
	for _, fi := range list {
		if fi.IsDir() {
			continue
		}
		switch filepath.Ext(fi.Name()) {
		default:
			continue
		case ".c", ".h":
		}
		t.Run(fi.Name(), func(t *testing.T) {
			f, err := os.Open(filepath.Join(dir, fi.Name()))
			require.NoError(t, err)
			defer f.Close()
			fbuf.Reset()
			_, err = io.Copy(&fbuf, f)
			require.NoError(t, err)

			toks := Tokenize(fbuf.Bytes())

			buf.Reset()
			Print(&buf, toks)
			require.Equal(t, fbuf.String(), buf.String())
		})
	}

}
