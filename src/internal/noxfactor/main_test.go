package main

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestNoxFactor(t *testing.T) {
	if err := run("../../"); err != nil {
		t.Fatal(err)
	}
}

func TestFindExterns(t *testing.T) {
	got := findExterns([]byte(`
extern uint32_t some_var_123;
extern void *some_var_456 ;
extern int **arr1[5];
extern int **arr2 [1 + 5] ;
`))
	require.Equal(t, []SrcDecl{
		{Name: "some_var_123", Src: "extern uint32_t some_var_123;\n"},
		{Name: "some_var_456", Src: "extern void *some_var_456 ;\n"},
		{Name: "arr1", Src: "extern int **arr1[5];\n"},
		{Name: "arr2", Src: "extern int **arr2 [1 + 5] ;\n"},
	}, got)
}
