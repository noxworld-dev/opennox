package opennox

import (
	"github.com/noxworld-dev/opennox-lib/platform"
	"github.com/noxworld-dev/opennox-lib/prand"
)

var (
	noxRndCounter1 = prand.New(0)
	noxRndCounter2 = prand.New(0)
)

func noxCommonInitRandom() {
	v := platform.TimeSeed()
	noxRndCounter1.Reset(int(v))
	noxRndCounter2.Reset(int(v))
}

func nox_common_randomInt_415FA0(min, max int) int {
	return noxRndCounter1.IntClamp(min, max)
}

func nox_common_randomIntMinMax_415FF0(min, max int) int {
	return randomIntMinMax(min, max)
}

func randomIntMinMax(min, max int) int {
	return noxRndCounter2.Int(min, max)
}

func nox_common_randomFloat_416030(min, max float64) float64 {
	return noxRndCounter1.FloatClamp(min, max)
}

func nox_common_randomFloatXxx_416090(min, max float64) float64 {
	return noxRndCounter2.Float(min, max)
}
