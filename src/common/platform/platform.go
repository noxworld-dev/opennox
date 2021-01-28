package platform

import "time"

// Platform is an interface that controls time and randomness in the program.
type Platform interface {
	// Ticks returns a duration from the platform init.
	Ticks() time.Duration
	// Sleep wait for a specific duration.
	Sleep(dt time.Duration)
	// TimeSeed returns a time-based seed for the pseudorandom generator.
	TimeSeed() int64
	// RandInt generates a random integer.
	RandInt() int
	// RandSeed seeds the pseudorandom generator with s specific seed.
	RandSeed(seed int64)
	// RandSeedTime uses time-based seed for the pseudorandom generator.
	RandSeedTime()
}

var global Platform = New()

// Set the default platform.
func Set(p Platform) {
	global = p
}

// Get the default platform.
func Get() Platform {
	return global
}

// Ticks returns a duration from the platform init.
func Ticks() time.Duration {
	return global.Ticks()
}

// Sleep wait for a specific duration.
func Sleep(dt time.Duration) {
	global.Sleep(dt)
}

// TimeSeed returns a time-based seed for the pseudorandom generator.
func TimeSeed() int64 {
	return global.TimeSeed()
}

// RandInt generates a random integer.
func RandInt() int {
	return global.RandInt()
}

// RandSeed seeds the pseudorandom generator with s specific seed.
func RandSeed(seed int64) {
	global.RandSeed(seed)
}

// RandSeedTime uses time-based seed for the pseudorandom generator.
func RandSeedTime() {
	global.RandSeedTime()
}
