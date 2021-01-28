// Package prand implements predictable random number generator, as used by Nox.
package prand

// New creates a new predictable random number generator with a given table index.
func New(i int) *Rand {
	r := new(Rand)
	r.Reset(i)
	return r
}

// Rand is a predictable random number generator.
type Rand struct {
	i uint32
}

// Reset the table index to a give value.
func (r *Rand) Reset(i int) {
	r.i = uint32(i) % uint32(len(table))
}

// Index returns the current index.
func (r *Rand) Index() int {
	return int(r.i)
}

// step returns the current index and advances the generator.
func (r *Rand) step() int {
	i := int(r.i)
	r.i++
	if int(r.i) >= len(table) {
		r.i = 0
	}
	return i
}

// Int returns an integer in given bounds and advances the generator.
func (r *Rand) Int(min, max int) int {
	// sub_415FF0
	i := r.step()
	return min + int(table[i])%(max-min+1)
}

// Float returns a float in given bounds and advances the generator.
func (r *Rand) Float(min, max float64) float64 {
	// sub_416090
	i := r.step()
	return min + (max-min)*(float64(table[i])*0.000030518509)
}

func (r *Rand) IntClamp(min, max int) int {
	// sub_415FA0
	if max-min == -1 { // TODO: check if Nox works with < 0 condition
		return max
	}
	return r.Int(min, max)
}

func (r *Rand) FloatClamp(min, max float64) float64 {
	// sub_416030
	dv := max - min
	if dv == 0.0 { // TODO: check if Nox works with < 0 condition
		return max
	}
	return r.Float(min, max)
}
