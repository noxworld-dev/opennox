package seat

type Seat interface {
	Screen
	Input
	// Tick runs event processing, triggering all relevant callback functions.
	Tick()
	// Close the seat and release resources.
	Close() error
}
