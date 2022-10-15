package main

import (
	"bytes"
	"flag"
	"fmt"
	"go/ast"
	"go/format"
	"go/parser"
	"go/printer"
	"go/token"
	"log"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"time"

	"golang.org/x/sync/errgroup"

	noxflags "github.com/noxworld-dev/opennox/v1/common/flags"
	"github.com/noxworld-dev/opennox/v1/common/sound"
	"github.com/noxworld-dev/opennox/v1/internal/noxfactor/c2gotok"
)

var (
	fPath = flag.String("path", ".", "path to scan")
)

func main() {
	flag.Parse()
	if err := run(*fPath); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run(path string) error {
	start := time.Now()
	r := new(Refactorer)
	err := r.ProcessDir(path)
	log.Println("DONE in", time.Since(start))
	return err
}

func (r *Refactorer) ProcessDir(path string) error {
	list, err := os.ReadDir(path)
	if err != nil {
		return err
	}
	var filtered []string
	for _, fi := range list {
		if fi.IsDir() {
			continue
		}
		if filepath.Ext(fi.Name()) != ".go" {
			continue
		}
		filtered = append(filtered, filepath.Join(path, fi.Name()))
	}
	list = nil
	r.defined = make(map[string]struct{})
	var eg errgroup.Group
	for _, fpath := range filtered {
		fpath := fpath
		eg.Go(func() error {
			return r.reformatC(fpath)
		})
	}
	if err := eg.Wait(); err != nil {
		return err
	}
	for _, fpath := range filtered {
		if err := r.preProcessFile(fpath); err != nil {
			return err
		}
	}
	for _, fpath := range filtered {
		if err := r.processFile(fpath); err != nil {
			return err
		}
	}
	return nil
}

type SrcDecl struct {
	Name string
	Src  string
}

func findExterns(data []byte) (out []SrcDecl) {
	const (
		extern = "extern "
	)
	for {
		i := bytes.Index(data, []byte(extern))
		if i < 0 {
			return
		}
		data = data[i:]
		i = bytes.IndexByte(data, ';')
		if i < 0 {
			return
		}
		line := bytes.TrimSpace(data[:i])
		if j := bytes.IndexByte(data[i+1:], '\n'); j >= 0 {
			i += j + 1
		}
		src := data[:i+1]
		data = data[i+1:]
		if i = bytes.IndexByte(line, '['); i > 0 {
			line = bytes.TrimSpace(line[:i])
			line = bytes.TrimSpace(line)
		}
		i = bytes.LastIndexAny(line, " \t")
		if i < 0 {
			continue
		}
		name := line[i+1:]
		if bytes.ContainsAny(name, "();,") {
			continue // TODO: support function vars
		}
		if i = bytes.IndexByte(name, '['); i > 0 {
			name = bytes.TrimSpace(name[:i])
		}
		name = bytes.TrimLeft(name, "*")
		out = append(out, SrcDecl{
			Name: string(name),
			Src:  string(src),
		})
	}
}

func removeUnusedExterns(data []byte) []byte {
	exts := findExterns(data)
	if len(exts) == 0 {
		return data
	}
	externUsages := make(map[int]int, len(exts))
	for ind, e := range exts {
		for cur := data; len(cur) > 0; {
			i := bytes.Index(cur, []byte(e.Name))
			if i < 0 {
				break
			}
			externUsages[ind]++
			cur = cur[i+len(e.Name):]
		}
		if n := externUsages[ind]; n > 1 || n == 0 {
			delete(externUsages, ind)
		}
	}
	if len(externUsages) == 0 {
		return data
	}
	var (
		replace []string
	)
	for ind := range externUsages {
		e := exts[ind]
		replace = append(replace, e.Src, "")
	}
	return []byte(strings.NewReplacer(replace...).Replace(string(data)))
}

func (r *Refactorer) reformatC(path string) error {
	src, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	data := src
	data = removeUnusedExterns(data)
	toks := c2gotok.Tokenize(data)
	toks = c2gotok.C2Go(toks)
	var buf bytes.Buffer
	c2gotok.Print(&buf, toks)
	if bytes.Equal(src, buf.Bytes()) {
		return nil
	}
	return os.WriteFile(path, buf.Bytes(), 0644)
}

func (r *Refactorer) preProcessFile(path string) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	fs := token.NewFileSet()
	f, err := parser.ParseFile(fs, path, data, parser.ParseComments)
	if err != nil {
		return err
	}
	for _, v := range f.Decls {
		switch v := v.(type) {
		case *ast.FuncDecl:
			if v.Recv == nil {
				r.defined[v.Name.Name] = struct{}{}
			}
		}
	}
	return nil
}

var knownLibs = map[string][2]string{
	"image":    {"", "image"},
	"alloc":    {"", "github.com/noxworld-dev/opennox/v1/common/alloc"},
	"memmap":   {"", "github.com/noxworld-dev/opennox/v1/common/memmap"},
	"noxflags": {"noxflags", "github.com/noxworld-dev/opennox/v1/common/flags"},
}

func (r *Refactorer) processFile(path string) error {
	r.fileChanged = false
	r.fileCxgo = strings.HasPrefix(filepath.Base(path), "zzz_")
	log.Println(path)
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	fs := token.NewFileSet()
	f, err := parser.ParseFile(fs, path, data, parser.ParseComments)
	if err != nil {
		return err
	}
	added := make(map[[2]string]struct{})
	for _, id := range f.Unresolved {
		path, ok := knownLibs[id.Name]
		if !ok {
			continue
		}
		if _, ok = added[path]; !ok {
			added[path] = struct{}{}
		}
	}
	if len(added) > 0 && r.fileCxgo {
		r.fileChanged = true
		var imports *ast.GenDecl
		for _, d := range f.Decls {
			if gd, ok := d.(*ast.GenDecl); ok && gd.Tok == token.IMPORT {
				imports = gd
				break
			}
		}
		if imports == nil {
			imports = &ast.GenDecl{Tok: token.IMPORT}
			f.Decls = append([]ast.Decl{imports}, f.Decls...)
		}
		for path := range added {
			var name *ast.Ident
			if path[0] != "" {
				name = ident(path[0])
			}
			imports.Specs = append(imports.Specs, &ast.ImportSpec{
				Name: name,
				Path: &ast.BasicLit{Kind: token.STRING, Value: strconv.Quote(path[1])},
			})
		}
	}
	for i, d := range f.Decls {
		f.Decls[i] = r.visitDecl(d)
	}
	if !r.fileChanged {
		return nil
	}
	var buf bytes.Buffer
	err = format.Node(&buf, fs, f)
	if err != nil {
		log.Println(err)
		buf.Reset()
		err = printer.Fprint(&buf, fs, f)
		if err != nil {
			return err
		}
	}
	return os.WriteFile(path, buf.Bytes(), 0644)
}

type Refactorer struct {
	fileChanged bool
	fileCxgo    bool
	inDecl      string
	defined     map[string]struct{}
}

var identGoRename = map[string]string{
	"NOX_MAX_WIDTH":  "noxMaxWidth",
	"NOX_MAX_HEIGHT": "noxMaxHeight",
}

var callGoRename = map[string]string{
	"nox_xxx_clientPlaySoundSpecial_452D80":   "clientPlaySoundSpecial",
	"nox_common_setEngineFlag":                "noxflags.SetEngine",
	"nox_common_resetEngineFlag":              "noxflags.UnsetEngine",
	"nox_gui_makeAnimation_43C5B0":            "nox_gui_makeAnimation",
	"nox_xxx_dialogMsgBoxCreate_449A10":       "NewDialogWindow",
	"nox_xxx_windowFocus_46B500":              "guiFocus",
	"nox_game_addStateCode_43BDD0":            "gameAddStateCode",
	"nox_game_getStateCode_43BE10":            "gameGetStateCode",
	"nox_xxx_guiFontPtrByName_43F360":         "guiFontPtrByName",
	"nox_xxx_checkHasSoloMaps_40ABD0":         "nox_xxx_checkHasSoloMaps",
	"nox_xxx_wndShowModalMB_46A8C0":           "nox_xxx_wndShowModalMB",
	"nox_xxx_cryptClose_4269F0":               "cryptFileClose",
	"nox_xxx_cryptSeekCur_40E0A0":             "nox_xxx_cryptSeekCur",
	"nox_xxx_cryptOpen_426910":                "cryptFileOpen",
	"nox_xxx_getFirstUpdatable2Object_4DA840": "firstServerObjectUpdatable2",
	"nox_xxx_wndSetCaptureMain_46ADC0":        "nox_xxx_wndSetCaptureMain",
	"nox_xxx_wndClearCaptureMain_46ADE0":      "nox_xxx_wndClearCaptureMain",
	"nox_xxx_wndGetCaptureMain_46AE00":        "nox_xxx_wndGetCaptureMain",
	"nox_client_getServerPort_43B320":         "clientGetServerPort",
	"nox_client_getMousePos_4309F0":           "getMousePos",
	"sub_43F140":                              "noxAudioServeT",
	"nox_xxx_utilFindSound_40AF50":            "sound.ByName",
	"nox_platform_get_ticks":                  "platformTicks",
	"nox_float2int":                           "int",
}

func stringExpr(n ast.Expr, changed *bool) ast.Expr {
	switch n := n.(type) {
	case *ast.CallExpr:
		if len(n.Args) != 1 {
			return n
		}
		fnc, ok := n.Fun.(*ast.Ident)
		if !ok {
			return n
		}
		switch fnc.Name {
		case "CString":
			*changed = true
			return n.Args[0]
		}
	}
	return n
}

func isFuncCall(name string, n ast.Expr) (*ast.CallExpr, bool) {
	call, ok := n.(*ast.CallExpr)
	if !ok {
		return nil, false
	}
	switch fnc := call.Fun.(type) {
	case *ast.Ident:
		if name == fnc.Name {
			return call, true
		}
	case *ast.SelectorExpr:
		if x, ok := fnc.X.(*ast.Ident); ok && name == x.Name+"."+fnc.Sel.Name {
			return call, true
		}
	}
	return nil, false
}

func unwrapFunc(n ast.Expr, changed *bool) ast.Expr {
	if isZero(n) {
		*changed = true
		return ident("nil")
	}
	if call, ok := isFuncCall("unsafe.Pointer", n); ok && len(call.Args) == 1 {
		if call, ok := isFuncCall("libc.FuncAddr", call.Args[0]); ok && len(call.Args) == 1 {
			*changed = true
			return call.Args[0]
		}
	}
	return n
}

func (r *Refactorer) visitGoCall(n *ast.CallExpr, fnc *ast.Ident) {
	if fnc.Name == r.inDecl {
		return
	}
	switch fnc.Name {
	case "gameFPS":
		n.Fun = selExpr("noxServer", "TickRate")
		r.fileChanged = true
	case "gameFrame":
		n.Fun = selExpr("noxServer", "Frame")
		r.fileChanged = true
	case "getMemIntPtr":
		n.Fun = selExpr("memmap", "PtrInt32")
		r.fileChanged = true
	case "getMemU64Ptr", "mem_getU64Ptr":
		n.Fun = selExpr("memmap", "PtrUint64")
		r.fileChanged = true
	case "getMemU32Ptr", "mem_getU32Ptr":
		n.Fun = selExpr("memmap", "PtrUint32")
		r.fileChanged = true
	case "getMemU16Ptr", "mem_getU16Ptr":
		n.Fun = selExpr("memmap", "PtrUint16")
		r.fileChanged = true
	case "getMemI16Ptr", "mem_getI16Ptr":
		n.Fun = selExpr("memmap", "PtrInt16")
		r.fileChanged = true
	case "getMemByte", "mem_getU8Ptr":
		n.Fun = selExpr("memmap", "Uint8")
		r.fileChanged = true
	case "getMemAt":
		n.Fun = selExpr("memmap", "PtrOff")
		r.fileChanged = true
	case "nox_common_gameFlags_check_40A5C0":
		n.Fun = selExpr("noxflags", "HasGame")
		r.fileChanged = true
		r.visitCall(n)
	case "nox_xxx_setGameFlags_40A4D0":
		n.Fun = selExpr("noxflags", "SetGame")
		r.fileChanged = true
		r.visitCall(n)
	case "nox_common_gameFlags_unset_40A540":
		n.Fun = selExpr("noxflags", "UnsetGame")
		r.fileChanged = true
		r.visitCall(n)
	case "nox_common_randomInt_415FA0":
		n.Fun = selExpr("noxRndCounter1", "IntClamp")
		r.fileChanged = true
	case "nox_strman_loadString_40F1D0":
		if len(n.Args) == 4 && isZero(n.Args[1]) {
			n.Fun = selExpr("strMan", "GetStringInFile")
			n.Args = []ast.Expr{stringExpr(n.Args[0], &r.fileChanged), stringExpr(n.Args[2], &r.fileChanged)}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_memfile_skip":
		if len(n.Args) == 2 {
			n.Fun = recvCall(n.Args[0], "Skip")
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_memfile_read_u8":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "ReadU8")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_memfile_read_i8":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "ReadI8")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_memfile_read_u16":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "ReadU16")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_memfile_read_i16":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "ReadI16")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_memfile_read_u32":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "ReadU32")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_memfile_read_i32":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "ReadI32")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_gLoadImg_42F970":
		n.Fun = ident("nox_xxx_gLoadImg")
		r.fileChanged = true
		fallthrough
	case "nox_xxx_gLoadImg":
		if len(n.Args) == 1 {
			n.Args[0] = stringExpr(n.Args[0], &r.fileChanged)
		}
	case "nox_game_SetCliDrawFunc":
		n.Fun = ident("noxClient.setDrawFunc")
		r.fileChanged = true
		fallthrough
	case "setDrawFunc":
		if len(n.Args) == 1 {
			n.Args[0] = unwrapFunc(n.Args[0], &r.fileChanged)
		}
	case "nox_new_window_from_file":
		n.Fun = ident("newWindowFromFile")
		r.fileChanged = true
		fallthrough
	case "newWindowFromFile":
		if len(n.Args) == 2 {
			n.Args[0] = stringExpr(n.Args[0], &r.fileChanged)
			n.Args[1] = unwrapFunc(n.Args[1], &r.fileChanged)
		}
	case "nox_xxx_wndGetID_46B0A0":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "ID")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_wndSetWindowProc_46B300":
		if len(n.Args) == 2 {
			n.Fun = recvCall(n.Args[0], "setFunc93")
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCallRecv(n.Fun.(*ast.SelectorExpr), n)
		}
	case "nox_xxx_wndSetProc_46B2C0":
		if len(n.Args) == 2 {
			n.Fun = recvCall(n.Args[0], "setFunc94")
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCallRecv(n.Fun.(*ast.SelectorExpr), n)
		}
	case "nox_xxx_wndSetDrawFn_46B340":
		if len(n.Args) == 2 {
			n.Fun = recvCall(n.Args[0], "setDraw")
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCallRecv(n.Fun.(*ast.SelectorExpr), n)
		}
	case "nox_gui_winSetFunc96_46B070":
		if len(n.Args) == 2 {
			n.Fun = recvCall(n.Args[0], "setTooltipFunc")
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCallRecv(n.Fun.(*ast.SelectorExpr), n)
		}
	case "nox_window_set_all_funcs":
		if len(n.Args) == 4 {
			n.Fun = recvCall(n.Args[0], "SetAllFuncs")
			n.Args = n.Args[1:]
			r.fileChanged = true
			r.visitCallRecv(n.Fun.(*ast.SelectorExpr), n)
		}
	case "nox_xxx_windowDestroyMB_46C4E0":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "Destroy")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_wndGetChildByID_46B0C0":
		if len(n.Args) == 2 {
			if isZero(n.Args[0]) {
				n.Fun = ident("GUIChildByID")
			} else {
				n.Fun = recvCall(n.Args[0], "ChildByID")
			}
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_window_call_field_93":
		if len(n.Args) == 4 {
			n.Fun = recvCall(n.Args[0], "Func93")
			n.Args = []ast.Expr{call("asWindowEvent", n.Args[1:]...)}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_window_call_field_94_fnc":
		if len(n.Args) == 6 {
			n.Fun = ident("nox_window_call_field_94")
			n.Args = n.Args[:4]
		}
		fallthrough
	case "nox_window_call_field_94":
		if len(n.Args) == 4 {
			n.Fun = recvCall(n.Args[0], "Func94")
			n.Args = []ast.Expr{call("asWindowEvent", n.Args[1:]...)}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_window_set_hidden":
		if len(n.Args) == 2 {
			switch {
			case isZero(n.Args[1]):
				n.Fun = recvCall(n.Args[0], "Show")
				n.Args = []ast.Expr{}
				r.fileChanged = true
				r.visitCall(n)
			case isOne(n.Args[1]):
				n.Fun = recvCall(n.Args[0], "Hide")
				n.Args = []ast.Expr{}
				r.fileChanged = true
				r.visitCall(n)
			default:
				n.Fun = recvCall(n.Args[0], "SetHidden")
				n.Args = []ast.Expr{n.Args[1]}
				r.fileChanged = true
				r.visitCall(n)
			}
		}
	case "wndIsShown_nox_xxx_wndIsShown_46ACC0":
		if len(n.Args) == 1 {
			call := callExpr(recvCall(n.Args[0], "Flags"))
			n.Fun = recvCall(call, "IsHidden")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "asWindowEvent":
		if len(n.Args) == 3 {
			switch a1 := n.Args[0].(type) {
			case *ast.BasicLit:
				if a1.Kind == token.INT {
					if v, err := strconv.ParseUint(a1.Value, 10, 64); err == nil {
						a1.Value = "0x" + strconv.FormatUint(v, 16)
						r.fileChanged = true
					}
				}
			}
		}
	case "NewDialogWindow":
		if len(n.Args) == 6 {
			if isZero(n.Args[1]) {
				n.Args[1] = strLit("")
				r.fileChanged = true
			}
			if isZeroInt(n.Args[4]) {
				n.Args[4] = ident("nil")
				r.fileChanged = true
			}
			if isZeroInt(n.Args[5]) {
				n.Args[5] = ident("nil")
				r.fileChanged = true
			}
		}
	case "nox_xxx_setMouseBounds_430A70":
		if len(n.Args) == 4 {
			n.Fun = ident("setMouseBounds")
			n.Args = []ast.Expr{callExpr(selExpr("image", "Rect"), n.Args[0], n.Args[2], n.Args[1], n.Args[3])}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_drawString_43F6E0":
		if len(n.Args) == 4 {
			n.Fun = selExpr("noxClient.r", "DrawString")
			if isZeroInt(n.Args[0]) {
				n.Args[0] = ident("nil")
			}
			n.Args = []ast.Expr{n.Args[0], n.Args[1], callExpr(selExpr("image", "Pt"), n.Args[2], n.Args[3])}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_window_setPos_46A9B0":
		if len(n.Args) == 3 {
			n.Fun = recvCall(n.Args[0], "SetPos")
			n.Args = []ast.Expr{callExpr(selExpr("image", "Pt"), n.Args[1], n.Args[2])}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_fileReadWrite_426AC0_file3_fread":
		if len(n.Args) == 2 {
			n.Fun = ident("cryptFileReadWrite")
			n.Args = []ast.Expr{sliceExprLeft(n.Args[0], n.Args[1])}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_fileCryptReadCrcMB_426C20":
		if len(n.Args) == 2 {
			n.Fun = ident("cryptFileReadMaybeAlign")
			n.Args = []ast.Expr{sliceExprLeft(n.Args[0], n.Args[1])}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_common_playerInfoGetByID_417040":
		if len(n.Args) == 1 {
			n.Fun = selExpr("noxServer", "getPlayerByID")
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_server_getFirstObject_4DA790":
		if len(n.Args) == 0 {
			n.Fun = selExpr("noxServer", "firstServerObject")
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_server_getFirstObjectUninited_4DA870":
		if len(n.Args) == 0 {
			n.Fun = selExpr("noxServer", "firstServerObjectUninited")
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_server_getNextObject_4DA7A0", "nox_xxx_getNextUpdatable2Object_4DA850":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "Next")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_inventoryGetFirst_4E7980":
		if len(n.Args) == 1 {
			n.Fun = recvCall(n.Args[0], "FirstItem")
			n.Args = []ast.Expr{}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_strman_get_lang_code":
		if len(n.Args) == 0 {
			n.Fun = selExpr("strMan", "Lang")
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_common_randomIntMinMax_415FF0":
		if len(n.Args) == 4 {
			n.Fun = ident("randomIntMinMax")
			n.Args = n.Args[:2]
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_spellNameToN_4243F0":
		if len(n.Args) == 1 {
			n.Fun = selExpr("spell", "ParseID")
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_getTTByNameSpriteMB_44CFC0":
		if len(n.Args) == 1 {
			n.Fun = selExpr("nox_things", "IndByID")
			n.Args[0] = stringExpr(n.Args[0], &r.fileChanged)
			r.fileChanged = true
		}
	case "clientPlaySoundSpecial":
		if len(n.Args) == 2 {
			if l, ok := n.Args[0].(*ast.BasicLit); ok && l.Kind == token.INT {
				if v, err := strconv.ParseUint(l.Value, 0, 64); err == nil {
					n.Args[0] = &ast.Ident{Name: sound.ID(v).GoString()}
					r.fileChanged = true
				}
			}
		}
	case "nox_xxx_aud_501960":
		if len(n.Args) == 4 {
			if l, ok := n.Args[0].(*ast.BasicLit); ok && l.Kind == token.INT {
				if v, err := strconv.ParseUint(l.Value, 0, 64); err == nil {
					n.Args[0] = &ast.Ident{Name: sound.ID(v).GoString()}
					r.fileChanged = true
				}
			}
		}
	default:
		if newName := callGoRename[fnc.Name]; newName != "" {
			fnc.Name = newName
			r.fileChanged = true
		}
	}
}

func (r *Refactorer) visitCCall(n *ast.CallExpr, fnc string) {
	if fnc == r.inDecl || fnc+"_raw" == r.inDecl {
		return
	}
	if _, ok := r.defined[fnc]; ok {
		n.Fun = n.Fun.(*ast.SelectorExpr).Sel
		r.fileChanged = true
	}
}
func (r *Refactorer) visitFlagsCall(n *ast.CallExpr, fnc string) {
	switch fnc {
	case "HasGame", "SetGame", "UnsetGame":
		if len(n.Args) != 1 {
			return
		}
		arg, ok := n.Args[0].(*ast.BasicLit)
		if !ok || arg.Kind != token.INT {
			return
		}
		val, err := strconv.ParseUint(arg.Value, 0, 64)
		if err != nil {
			log.Println(err)
			return
		}
		r.fileChanged = true
		n.Args[0] = &ast.Ident{Name: noxflags.GameFlag(val).GoString()}
	}
}
func (r *Refactorer) visitMemmapCall(n *ast.CallExpr, fnc string) {
	switch fnc {
	case "PtrOff", "PtrPtr",
		"PtrUint8", "PtrInt8", "PtrUint16", "PtrInt16",
		"PtrUint32", "PtrInt32", "PtrUint64", "PtrInt64",
		"PtrFloat32", "PtrFloat64",
		"Uint8", "Int8", "Uint16", "Int16",
		"Uint32", "Int32", "Uint64", "Int64",
		"Float32", "Float64":
		if len(n.Args) != 2 {
			return
		}
		arg, ok := n.Args[1].(*ast.BasicLit)
		if !ok || arg.Kind != token.INT || !strings.HasPrefix(arg.Value, "0x") {
			return
		}
		val, err := strconv.ParseUint(arg.Value, 0, 64)
		if err != nil {
			log.Println(err)
			return
		}
		r.fileChanged = true
		arg.Value = strconv.FormatUint(val, 10)
	}
}
func (r *Refactorer) visitUnsafeCall(n *ast.CallExpr, fnc string) ast.Expr {
	switch fnc {
	case "Pointer":
		if len(n.Args) != 1 {
			return n
		}
		if call, ok := isFuncCall("libc.FuncAddr", n.Args[0]); ok {
			r.fileChanged = true
			return call.Args[0]
		}
	}
	return n
}
func (r *Refactorer) visitLibcCall(n *ast.CallExpr, fnc string) {
	switch fnc {
	case "AsFunc":
		if len(n.Args) == 2 {
			n.Fun = ident("cgoAsFunc")
			r.fileChanged = true
		}
	case "FuncAddr":
		if len(n.Args) == 1 {
			n.Fun = ident("cgoFuncAddr")
			r.fileChanged = true
		}
	}
}
func (r *Refactorer) visitCallRecv(sel *ast.SelectorExpr, n *ast.CallExpr) {
	switch sel.Sel.Name {
	case "setTooltipFunc":
		if len(n.Args) == 1 {
			n.Args[0] = unwrapFunc(n.Args[0], &r.fileChanged)
		}
	case "SetAllFuncs":
		if len(n.Args) == 3 {
			for i := range n.Args {
				n.Args[i] = unwrapFunc(n.Args[i], &r.fileChanged)
			}
		}
	}
}
func (r *Refactorer) visitCall(n *ast.CallExpr) ast.Expr {
	switch fnc := n.Fun.(type) {
	case *ast.Ident:
		r.visitGoCall(n, fnc)
	case *ast.SelectorExpr:
		pkg, ok := fnc.X.(*ast.Ident)
		if !ok {
			r.visitCallRecv(fnc, n)
			return n
		}
		switch pkg.Name {
		case "C":
			r.visitCCall(n, fnc.Sel.Name)
		case "noxflags":
			r.visitFlagsCall(n, fnc.Sel.Name)
		case "memmap":
			r.visitMemmapCall(n, fnc.Sel.Name)
		case "unsafe":
			return r.visitUnsafeCall(n, fnc.Sel.Name)
		case "libc":
			r.visitLibcCall(n, fnc.Sel.Name)
		default:
			r.visitCallRecv(fnc, n)
		}
	}
	return n
}
func (r *Refactorer) visitBinaryExpr(n *ast.BinaryExpr) ast.Expr {
	switch n.Op {
	case token.EQL:
		c1, ok1 := isFuncCall("libc.FuncAddr", n.X)
		c2, ok2 := isFuncCall("libc.FuncAddr", n.Y)
		if ok1 && ok2 {
			r.fileChanged = true
			return call("cgoFuncEqual", c1.Args[0], c2.Args[0])
		}
		if b, ok := n.Y.(*ast.Ident); ok && b.Name == "true" {
			r.fileChanged = true
			return n.X
		}
	case token.NEQ:
		c1, ok1 := isFuncCall("libc.FuncAddr", n.X)
		c2, ok2 := isFuncCall("libc.FuncAddr", n.Y)
		if ok1 && ok2 {
			r.fileChanged = true
			return not(call("cgoFuncEqual", c1.Args[0], c2.Args[0]))
		}
		if b, ok := n.Y.(*ast.Ident); ok && b.Name == "true" {
			r.fileChanged = true
			return not(n.X)
		}
	}
	return n
}
func (r *Refactorer) visitStarExpr(n *ast.StarExpr) ast.Expr {
	switch x := n.X.(type) {
	case *ast.CallExpr:
		if len(x.Args) != 1 {
			return n
		}
		par, ok := x.Fun.(*ast.ParenExpr)
		if !ok {
			return n
		}
		ptyp, ok := par.X.(*ast.StarExpr)
		if !ok {
			return n
		}
		_, ok = ptyp.X.(*ast.FuncType)
		if !ok {
			return n
		}
		return call("cgoAsFunc", star(callExpr(paren(star(ident("uint32"))), x.Args[0])), callExpr(par, ident("nil")))
	}
	return n
}

func (r *Refactorer) visitDecl(n ast.Decl) ast.Decl {
	switch n := n.(type) {
	case *ast.FuncDecl:
		r.inDecl = n.Name.Name
		r.visitStmt(n.Body)
	case *ast.GenDecl:
		for _, s := range n.Specs {
			switch s := s.(type) {
			case *ast.ValueSpec:
				s.Type = r.visitExpr(s.Type)
				for i, v := range s.Names {
					s.Names[i] = r.visitExpr(v).(*ast.Ident)
				}
				for i, v := range s.Values {
					s.Values[i] = r.visitExpr(v)
				}
			case *ast.TypeSpec, *ast.ImportSpec:
				// skip
			default:
				panic(fmt.Errorf("unsupported spec type: %T", s))
			}
		}
	default:
		panic(fmt.Errorf("unsupported decl type: %T", n))
	}
	return n
}

func (r *Refactorer) visitStmt(n ast.Stmt) ast.Stmt {
	switch n := n.(type) {
	case nil, *ast.BranchStmt, *ast.EmptyStmt:
		// skip
	case *ast.ExprStmt:
		n.X = r.visitExpr(n.X)
	case *ast.DeclStmt:
		n.Decl = r.visitDecl(n.Decl)
	case *ast.BlockStmt:
		for i, st := range n.List {
			n.List[i] = r.visitStmt(st)
		}
	case *ast.IfStmt:
		n.Init = r.visitStmt(n.Init)
		n.Cond = r.visitExpr(n.Cond)
		n.Body = r.visitStmt(n.Body).(*ast.BlockStmt)
		n.Else = r.visitStmt(n.Else)
	case *ast.ForStmt:
		n.Init = r.visitStmt(n.Init)
		n.Cond = r.visitExpr(n.Cond)
		n.Post = r.visitStmt(n.Post)
		n.Body = r.visitStmt(n.Body).(*ast.BlockStmt)
	case *ast.LabeledStmt:
		n.Stmt = r.visitStmt(n.Stmt)
	case *ast.ReturnStmt:
		for i, e := range n.Results {
			n.Results[i] = r.visitExpr(e)
		}
	case *ast.RangeStmt:
		n.Key = r.visitExpr(n.Key)
		n.Value = r.visitExpr(n.Value)
		n.X = r.visitExpr(n.X)
		n.Body = r.visitStmt(n.Body).(*ast.BlockStmt)
	case *ast.AssignStmt:
		for i, e := range n.Lhs {
			n.Lhs[i] = r.visitExpr(e)
		}
		for i, e := range n.Rhs {
			n.Rhs[i] = r.visitExpr(e)
		}
	case *ast.IncDecStmt:
		n.X = r.visitExpr(n.X)
	case *ast.DeferStmt:
		n.Call = r.visitExpr(n.Call).(*ast.CallExpr)
	case *ast.GoStmt:
		n.Call = r.visitExpr(n.Call).(*ast.CallExpr)
	case *ast.SendStmt:
		n.Chan = r.visitExpr(n.Chan)
		n.Value = r.visitExpr(n.Value)
	case *ast.SwitchStmt:
		n.Init = r.visitStmt(n.Init)
		n.Tag = r.visitExpr(n.Tag)
		n.Body = r.visitStmt(n.Body).(*ast.BlockStmt)
	case *ast.TypeSwitchStmt:
		n.Init = r.visitStmt(n.Init)
		n.Assign = r.visitStmt(n.Assign)
		n.Body = r.visitStmt(n.Body).(*ast.BlockStmt)
	case *ast.SelectStmt:
		n.Body = r.visitStmt(n.Body).(*ast.BlockStmt)
	case *ast.CaseClause:
		for i, e := range n.List {
			n.List[i] = r.visitExpr(e)
		}
		for i, st := range n.Body {
			n.Body[i] = r.visitStmt(st)
		}
	case *ast.CommClause:
		n.Comm = r.visitStmt(n.Comm)
		for i, st := range n.Body {
			n.Body[i] = r.visitStmt(st)
		}
	default:
		panic(fmt.Errorf("unsupported stmt type: %T", n))
	}
	return n
}

func (r *Refactorer) visitExpr(n ast.Expr) ast.Expr {
	switch n := n.(type) {
	case nil, *ast.BasicLit,
		*ast.ArrayType, *ast.FuncType, *ast.MapType, *ast.ChanType, *ast.StructType, *ast.InterfaceType:
		// skip
	case *ast.Ident:
		if newName := identGoRename[n.Name]; newName != "" {
			n.Name = newName
			r.fileChanged = true
		}
	case *ast.ParenExpr:
		n.X = r.visitExpr(n.X)
	case *ast.StarExpr:
		n.X = r.visitExpr(n.X)
		return r.visitStarExpr(n)
	case *ast.UnaryExpr:
		n.X = r.visitExpr(n.X)
	case *ast.BinaryExpr:
		n.X = r.visitExpr(n.X)
		n.Y = r.visitExpr(n.Y)
		return r.visitBinaryExpr(n)
	case *ast.SelectorExpr:
		n.Sel = r.visitExpr(n.Sel).(*ast.Ident)
		n.X = r.visitExpr(n.X)
	case *ast.IndexExpr:
		n.X = r.visitExpr(n.X)
		n.Index = r.visitExpr(n.Index)
	case *ast.SliceExpr:
		n.X = r.visitExpr(n.X)
		n.Low = r.visitExpr(n.Low)
		n.High = r.visitExpr(n.High)
		n.Max = r.visitExpr(n.Max)
	case *ast.CallExpr:
		if p, ok := n.Fun.(*ast.ParenExpr); ok {
			if id, ok := p.X.(*ast.Ident); ok {
				n.Fun = id
				r.fileChanged = true
			}
		}
		n.Fun = r.visitExpr(n.Fun)
		for i, a := range n.Args {
			n.Args[i] = r.visitExpr(a)
		}
		return r.visitCall(n)
	case *ast.TypeAssertExpr:
		n.X = r.visitExpr(n.X)
	case *ast.CompositeLit:
		for i, e := range n.Elts {
			n.Elts[i] = r.visitExpr(e)
		}
	case *ast.KeyValueExpr:
		n.Key = r.visitExpr(n.Key)
		n.Value = r.visitExpr(n.Value)
	case *ast.FuncLit:
		n.Body = r.visitStmt(n.Body).(*ast.BlockStmt)
	case *ast.IndexListExpr:
		for i, a := range n.Indices {
			n.Indices[i] = r.visitExpr(a)
		}
	default:
		panic(fmt.Errorf("unsupported expr type: %T", n))
	}
	return n
}

func intLit(val int) *ast.BasicLit {
	return &ast.BasicLit{Kind: token.INT, Value: strconv.FormatInt(int64(val), 10)}
}

func strLit(val string) *ast.BasicLit {
	return &ast.BasicLit{Kind: token.STRING, Value: strconv.Quote(val)}
}

func ident(name string) *ast.Ident {
	return &ast.Ident{Name: name}
}

func not(e ast.Expr) ast.Expr {
	return &ast.UnaryExpr{Op: token.NOT, X: e}
}

func star(e ast.Expr) ast.Expr {
	return &ast.StarExpr{X: e}
}

func paren(e ast.Expr) ast.Expr {
	return &ast.ParenExpr{X: e}
}

func selExpr(pkg, name string) *ast.SelectorExpr {
	return &ast.SelectorExpr{X: ident(pkg), Sel: ident(name)}
}

func recvCall(r ast.Expr, name string) *ast.SelectorExpr {
	return &ast.SelectorExpr{X: r, Sel: ident(name)}
}

func call(name string, args ...ast.Expr) *ast.CallExpr {
	return callExpr(ident(name), args...)
}

func callExpr(fnc ast.Expr, args ...ast.Expr) *ast.CallExpr {
	return &ast.CallExpr{Fun: fnc, Args: args}
}

func sliceExprLeft(exp ast.Expr, ri ast.Expr) *ast.SliceExpr {
	return &ast.SliceExpr{X: exp, High: ri}
}

func isZeroInt(exp ast.Expr) bool {
	switch exp := exp.(type) {
	case *ast.BasicLit:
		return exp.Kind == token.INT && exp.Value == "0"
	}
	return false
}

func isZero(exp ast.Expr) bool {
	switch exp := exp.(type) {
	case *ast.Ident:
		return exp.Name == "nil"
	case *ast.BasicLit:
		return exp.Kind == token.INT && exp.Value == "0"
	}
	return false
}

func isOne(exp ast.Expr) bool {
	switch exp := exp.(type) {
	case *ast.BasicLit:
		return exp.Kind == token.INT && (exp.Value == "1" || exp.Value == "0x1")
	}
	return false
}
