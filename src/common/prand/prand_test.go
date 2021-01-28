package prand

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestRand(t *testing.T) {
	r := New(0)

	expi := []int{
		4, 90, 129, 204, 133,
		241, 199, 21, 0, 220,
	}
	var goti []int
	for i := 0; i < 10; i++ {
		goti = append(goti, r.Int(0, 0xff))
	}
	require.Equal(t, expi, goti)

	expf := []float64{
		-0.625629450097, 0.48100220475199995,
		0.169072524263, 0.6241034934529999,
		0.7668385600460002, 1.513107660623,
		-0.849665824666, 1.8381297814730004,
		-0.25812556471899994, -0.483718383247,
	}
	var gotf []float64
	for i := 0; i < 10; i++ {
		gotf = append(gotf, r.Float(-1, +2))
	}
	require.Equal(t, expf, gotf)
}
