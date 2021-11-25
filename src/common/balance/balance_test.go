package balance

import (
	"testing"

	"github.com/stretchr/testify/require"

	"nox/v1/common/noxtest"
)

func TestReadBalance(t *testing.T) {
	f, err := ReadBalance(noxtest.DataPath(t, GamedataFile))
	require.NoError(t, err)
	require.Equal(t, float64(0.2), f.FloatDef("", "BerserkerPainRatio", -1))
	require.Equal(t, float64(0.2), f.FloatDef(TagSolo, "BerserkerPainRatio", -1))
	require.Equal(t, float64(-1), f.FloatDef("", "BerserkerDamage", -1))
	require.Equal(t, float64(100), f.FloatDef(TagSolo, "BerserkerDamage", -1))
	require.Equal(t, float64(150), f.FloatDef(TagArena, "BerserkerDamage", -1))
	require.Equal(t, float64(0.60), f.FloatDef("", "RepairCoefficient", -1))
	require.Equal(t, float64(150), f.FloatDef(TagArena, "WarriorMaxHealth", -1))
	require.Equal(t, []float64{0.5, 0.7, 1.0, 1.3, 1.6}, f.Array(TagSolo, "EnergyBoltDamage"))
	require.Equal(t, []float64{1.3, 1.6, 2.0, 2.3, 2.6}, f.Array(TagArena, "EnergyBoltDamage"))
	require.Equal(t, []float64{
		-1,
		0, 5000, 11000, 18200, 26840,
		37208, 49650, 64580, 82495, 103995,
		126891, 151276, 177246, 204903, 234359,
		265729, 299139, 334720, 372613, 412970,
		455950, 501723, 550472, 602390, 657682,
		716568, 779282, 846072, 917204, 992959,
		2000000000,
	}, f.Array("", "XPTable"))
}
