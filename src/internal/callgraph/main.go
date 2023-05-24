package main

import (
	"encoding/csv"
	"flag"
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"io/fs"
	"log"
	"os"
	"os/exec"
	"path/filepath"
	"sort"
	"strings"
)

var (
	fDir         = flag.String("dir", "", "project root directory")
	fNoTranslate = flag.Bool("noconv", false, "do not run cxgo to convert C source; assume it's already done")
)

func main() {
	flag.Parse()
	if err := run(*fDir); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

func run(root string) error {
	if _, err := os.Stat(filepath.Join(root, "src")); err != nil {
		return fmt.Errorf("doesn't look like a root directory: missing ./src")
	}
	if _, err := exec.LookPath("cxgo"); err != nil {
		return fmt.Errorf("cxgo is not installed")
	}
	root, err := filepath.Abs(root)
	if err != nil {
		return err
	}
	ignoreC := map[string]int{
		// these are generated helpers, don't remove them
		"mem_getPtr":    1,
		"mem_getU8Ptr":  1,
		"mem_getU16Ptr": 1,
		"mem_getU32Ptr": 1,
		"mem_getU64Ptr": 1,
		"mem_getI8Ptr":  1,
		"mem_getI16Ptr": 1,
		"mem_getI32Ptr": 1,
		"mem_getI64Ptr": 1,
		// used by "safe" build tag
		"nox_strcat":  1,
		"nox_strcmp":  1,
		"nox_strcpy":  1,
		"nox_strlen":  1,
		"nox_memcmp":  1,
		"nox_memcpy":  1,
		"nox_malloc":  1,
		"nox_calloc":  1,
		"nox_realloc": 1,
		"nox_memset":  1,
		"nox_free":    1,
		// helper, may be used later
		"nox_memfile_read_u16": 1,
		"nox_memfile_read_i16": 1,
	}

	// Function usages from C side.
	usedC := make(map[string]int)
	// Functions usages from Go side.
	usedGo := make(map[string]int)
	// Functions declared on C side.
	declsC := make(map[string]struct{})
	// Functions declared on Go side (legacy package).
	declsLegacy := make(map[string]struct{})
	// Helps distinguish function identifiers from variables.
	isFunc := make(map[string]struct{})

	for k := range ignoreC {
		usedC[k] = 1
	}

	if !*fNoTranslate {
		// Convert C files to Go
		_ = os.RemoveAll(filepath.Join(root, "gonox"))
		_ = execIn(root, "cxgo", "-c", "./cxgo.yml")

		// Convert C headers to Go
		_ = os.RemoveAll(filepath.Join(root, "gonoxh"))
		_ = execIn(root, "cxgo", "-c", "./cxgo_h.yml")
	}

	cdir := filepath.Join(root, "gonox")   // requires cxgo run!
	chdir := filepath.Join(root, "gonoxh") // requires cxgo run!

	godir := filepath.Join(root, "src")
	legacydir := filepath.Join(godir, "legacy")

	scanDir := func(dir string, fnc func(file *ast.File)) error {
		return filepath.WalkDir(dir, func(path string, d fs.DirEntry, err error) error {
			if err != nil {
				return err
			}
			if d.IsDir() {
				if path == dir {
					return nil
				}
				return filepath.SkipDir
			}
			if filepath.Ext(path) != ".go" {
				return nil
			}
			fs := token.NewFileSet()
			f, err := os.Open(path)
			if err != nil {
				return err
			}
			defer f.Close()
			file, err := parser.ParseFile(fs, path, f, parser.SkipObjectResolution|parser.ParseComments)
			if err != nil {
				return err
			}
			fnc(file)
			return nil
		})
	}

	var (
		curNode string
	)
	cf, err := os.Create(filepath.Join(root, "callgraph.csv"))
	if err != nil {
		return err
	}
	defer cf.Close()
	cw := csv.NewWriter(cf)
	defer cw.Flush()
	cw.Write([]string{"Source", "Target"})
	addEdge := func(n1, n2 string) {
		cw.Write([]string{n1, n2})
	}
	addNode := func(name string) {
		if curNode == "" {
			return
		}
		addEdge(curNode, name)
	}

	// =======================================
	// Search for declarations

	// Scan converted C files for declarations
	err = scanDir(cdir, func(file *ast.File) {
		walkInDecl(file, "C.", nil, func(d ast.Decl) {
			switch d := d.(type) {
			case *ast.FuncDecl:

				declsC[d.Name.Name] = struct{}{}
				isFunc[d.Name.Name] = struct{}{}
			case *ast.GenDecl:
				for _, s := range d.Specs {
					switch s := s.(type) {
					case *ast.ValueSpec:
						for _, name := range s.Names {
							declsC[name.Name] = struct{}{}
						}
					}
				}
			}
		}, func(n ast.Node) {
			switch n := n.(type) {
			case *ast.Ident:
				usedC[n.Name]++
				addNode("C." + n.Name)
			}
		})
	})
	if err != nil {
		return err
	}

	// Scan converted C headers for declarations
	err = scanDir(chdir, func(file *ast.File) {
		walkInDecl(file, "C.", nil, func(d ast.Decl) {
			switch d := d.(type) {
			case *ast.FuncDecl:
				declsC[d.Name.Name] = struct{}{}
				isFunc[d.Name.Name] = struct{}{}
			}
		}, func(n ast.Node) {})
	})
	if err != nil {
		return err
	}

	// Scan Go source in the legacy package
	err = scanDir(legacydir, func(file *ast.File) {
		walkInDecl(file, "", nil, func(d ast.Decl) {
			switch d := d.(type) {
			case *ast.FuncDecl:
				if strings.Contains(d.Doc.Text(), "export "+d.Name.Name) {
					declsLegacy[d.Name.Name] = struct{}{}
					isFunc[d.Name.Name] = struct{}{}
					addEdge("C."+d.Name.Name, "legacy."+d.Name.Name)
				}
			}
		}, func(n ast.Node) {
			switch n := n.(type) {
			case *ast.SelectorExpr:
				if cname, ok := n.X.(*ast.Ident); !ok || cname.Name != "C" {
					return
				}
				usedGo[n.Sel.Name]++
				addNode("C." + n.Sel.Name)
			}
		})
	})
	if err != nil {
		return err
	}

	// Scan Go source in the main package
	err = scanDir(godir, func(file *ast.File) {
		walkInDecl(file, "", nil, func(d ast.Decl) {
			switch d := d.(type) {
			case *ast.FuncDecl:
				isFunc[d.Name.Name] = struct{}{}
			}
		}, func(n ast.Node) {
			switch n := n.(type) {
			case *ast.SelectorExpr:
				if cname, ok := n.X.(*ast.Ident); !ok || cname.Name != "legacy" {
					return
				}
				usedGo["legacy."+n.Sel.Name]++
				addNode("legacy." + n.Sel.Name)
			}
		})
	})
	if err != nil {
		return err
	}

	log.Printf("C decls: %d", len(declsC))
	log.Printf("exported Go decls: %d", len(declsLegacy))

	// =======================================
	// Search for usages, build call graph

	// Scan converted C files for declarations
	err = scanDir(cdir, func(file *ast.File) {
		walkInDecl(file, "C.", &curNode, nil, func(n ast.Node) {
			switch n := n.(type) {
			case *ast.Ident:
				usedC[n.Name]++

				_, okC := declsC[n.Name]
				_, okGo := declsLegacy[n.Name]
				_, ignore := ignoreC[n.Name]
				_, isfnc := isFunc[n.Name]
				if !ignore && isfnc && (okC || okGo) {
					addNode("C." + n.Name)
				}
			}
		})
	})
	if err != nil {
		return err
	}

	// Scan Go source in the legacy package
	err = scanDir(legacydir, func(file *ast.File) {
		walkInDecl(file, "", &curNode, nil, func(n ast.Node) {
			switch n := n.(type) {
			case *ast.SelectorExpr:
				cname, ok := n.X.(*ast.Ident)
				if !ok {
					return
				}
				switch cname.Name {
				case "C":
					usedGo[n.Sel.Name]++

					_, okC := declsC[n.Sel.Name]
					_, okGo := declsLegacy[n.Sel.Name]
					_, ignore := ignoreC[n.Sel.Name]
					_, isfnc := isFunc[n.Sel.Name]
					if !ignore && isfnc && (okC || okGo) {
						addNode("C." + n.Sel.Name)
					}
				case "legacy":
					usedGo["legacy."+n.Sel.Name]++

					_, okGo := declsLegacy[n.Sel.Name]
					_, isfnc := isFunc[n.Sel.Name]
					if isfnc && okGo {
						addNode("legacy." + n.Sel.Name)
					}
				}
			}
		})
	})
	if err != nil {
		return err
	}

	var unusedC []string
	for name := range declsC {
		if usedC[name]+usedGo[name] == 0 {
			unusedC = append(unusedC, name)
		}
	}
	var unexportGo []string
	for name := range declsLegacy {
		if usedC[name]+usedGo[name] == 0 {
			unexportGo = append(unexportGo, name)
		}
	}
	log.Printf("candidates for removal: %d", len(unusedC))
	log.Printf("candidates for unexport: %d", len(unexportGo))
	sort.Strings(unusedC)
	sort.Strings(unexportGo)
	for _, name := range unexportGo {
		log.Printf("candidate for unexport: %s", name)
	}
	for _, name := range unusedC {
		log.Printf("candidate for removal: %s", name)
	}
	return nil
}

func walkInDecl(file *ast.File, cpref string, cur *string, dfnc func(d ast.Decl), fnc func(n ast.Node)) {
	for _, d := range file.Decls {
		if dfnc != nil {
			dfnc(d)
		}
		switch d := d.(type) {
		case *ast.FuncDecl:
			if d.Body != nil {
				if cur != nil {
					*cur = cpref + d.Name.Name
				}
				ast.Inspect(d.Body, func(n ast.Node) bool {
					fnc(n)
					return true
				})
				if cur != nil {
					*cur = ""
				}
			}
		case *ast.GenDecl:
			for _, s := range d.Specs {
				switch s := s.(type) {
				case *ast.ValueSpec:
					for _, v := range s.Values {
						ast.Inspect(v, func(n ast.Node) bool {
							fnc(n)
							return true
						})
					}
				}
			}
		}
	}
}

func execIn(wd string, cmd string, args ...string) error {
	c := exec.Command(cmd, args...)
	c.Dir = wd
	c.Stderr = os.Stderr
	err := c.Run()
	if err != nil {
		log.Println(err)
	}
	return err
}
