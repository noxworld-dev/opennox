package things

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestThingFixAttrs(t *testing.T) {
	arr := fixThingAttrs("MASS = 6  DESTROY = DefaultDestroy")
	require.Equal(t, []string{"MASS = 6", "DESTROY = DefaultDestroy"}, arr)
}
