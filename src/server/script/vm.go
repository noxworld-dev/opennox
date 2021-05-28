package script

// EventType is a type of script events.
type EventType string

const (
	EventMapInitialize = EventType("MapInitialize")
	EventMapEntry      = EventType("MapEntry")
	EventMapExit       = EventType("MapExit")
	EventMapShutdown   = EventType("MapShutdown")
	EventPlayerDeath   = EventType("PlayerDeath")
)

// VM is an interface for a virtual machine running the script engine.
type VM interface {
	// Exec executes text as a script source code.
	Exec(s string) error
	// ExecFile executes a script from the file.
	ExecFile(path string) error
	// OnFrame must be called when a new game frame is complete.
	OnFrame()
	// OnEvent is called when a certain scrip event happens.
	OnEvent(typ EventType)
	// Close the VM and free resources.
	Close() error
}
