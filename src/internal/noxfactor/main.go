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
	"time"

	"golang.org/x/sync/errgroup"

	noxflags "nox/v1/common/flags"
	"nox/v1/internal/noxfactor/c2gotok"
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

func (r *Refactorer) reformatC(path string) error {
	data, err := os.ReadFile(path)
	if err != nil {
		return err
	}
	toks := c2gotok.Tokenize(data)
	toks = c2gotok.C2Go(toks)
	var buf bytes.Buffer
	c2gotok.Print(&buf, toks)
	if bytes.Equal(data, buf.Bytes()) {
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

func (r *Refactorer) processFile(path string) error {
	r.fileChanged = false
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
	ast.Walk(r, f)
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
	"nox_new_window_from_file":                "newWindowFromFile",
	"nox_gui_makeAnimation_43C5B0":            "nox_gui_makeAnimation",
	"nox_xxx_dialogMsgBoxCreate_449A10":       "NewDialogWindow",
	"nox_xxx_windowFocus_46B500":              "guiFocus",
	"nox_game_addStateCode_43BDD0":            "gameAddStateCode",
	"nox_game_getStateCode_43BE10":            "gameGetStateCode",
	"nox_xxx_gLoadImg_42F970":                 "nox_xxx_gLoadImg",
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
	"nox_game_SetCliDrawFunc":                 "gameSetCliDrawFunc",
	"nox_client_getMousePos_4309F0":           "getMousePos",
	"sub_43F140":                              "noxAudioServeT",
	"nox_platform_get_ticks":                  "platformTicks",
	"nox_float2int":                           "int",
}

func (r *Refactorer) visitGoCall(n *ast.CallExpr, fnc *ast.Ident) {
	if fnc.Name == r.inDecl {
		return
	}
	switch fnc.Name {
	case "getMemIntPtr":
		n.Fun = selExpr("memmap", "PtrInt32")
		r.fileChanged = true
	case "getMemU64Ptr":
		n.Fun = selExpr("memmap", "PtrUint64")
		r.fileChanged = true
	case "getMemU32Ptr":
		n.Fun = selExpr("memmap", "PtrUint32")
		r.fileChanged = true
	case "getMemU16Ptr":
		n.Fun = selExpr("memmap", "PtrUint16")
		r.fileChanged = true
	case "getMemI16Ptr":
		n.Fun = selExpr("memmap", "PtrInt16")
		r.fileChanged = true
	case "getMemByte":
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
			n.Args = []ast.Expr{n.Args[0], n.Args[2]}
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
			r.visitCall(n)
		}
	case "nox_xxx_wndSetProc_46B2C0":
		if len(n.Args) == 2 {
			n.Fun = recvCall(n.Args[0], "setFunc94")
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_xxx_wndSetDrawFn_46B340":
		if len(n.Args) == 2 {
			n.Fun = recvCall(n.Args[0], "setDraw")
			n.Args = []ast.Expr{n.Args[1]}
			r.fileChanged = true
			r.visitCall(n)
		}
	case "nox_window_set_all_funcs":
		if len(n.Args) == 4 {
			n.Fun = recvCall(n.Args[0], "SetAllFuncs")
			n.Args = n.Args[1:]
			if isZero(n.Args[0]) {
				n.Args[0] = ident("nil")
				r.fileChanged = true
			}
			if isZero(n.Args[1]) {
				n.Args[1] = ident("nil")
				r.fileChanged = true
			}
			if isZero(n.Args[2]) {
				n.Args[2] = ident("nil")
				r.fileChanged = true
			}
			r.fileChanged = true
			r.visitCall(n)
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
			n.Fun = selExpr("noxrend", "DrawString")
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
func (r *Refactorer) visitCall(n *ast.CallExpr) {
	switch fnc := n.Fun.(type) {
	case *ast.Ident:
		r.visitGoCall(n, fnc)
	case *ast.SelectorExpr:
		pkg, ok := fnc.X.(*ast.Ident)
		if !ok {
			return
		}
		switch pkg.Name {
		case "C":
			r.visitCCall(n, fnc.Sel.Name)
		case "noxflags":
			r.visitFlagsCall(n, fnc.Sel.Name)
		}
	}
}

func (r *Refactorer) Visit(n ast.Node) ast.Visitor {
	switch n := n.(type) {
	case *ast.Ident:
		if newName := identGoRename[n.Name]; newName != "" {
			n.Name = newName
			r.fileChanged = true
		}
	case *ast.FuncDecl:
		r.inDecl = n.Name.Name
	case *ast.CallExpr:
		r.visitCall(n)
	}
	return r
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
