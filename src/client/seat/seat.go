package seat

type Seat interface {
	Screen
	Input
	// Close the seat and release resources.
	Close() error
}
