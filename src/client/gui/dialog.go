package gui

const (
	DialogOKButton         = DialogFlags(1 << iota) // 0x1
	DialogCancelButton                              // 0x2
	DialogTextEntry1                                // 0x4
	DialogYesButton                                 // 0x8
	DialogNoButton                                  // 0x10
	DialogFlag6                                     // 0x20
	DialogLockMouse                                 // 0x40
	DialogTextEntry2                                // 0x80
	DialogDisconnectButton                          // 0x100
	DialogHelpButton                                // 0x200
)

type DialogFlags int

func (s DialogFlags) Has(s2 DialogFlags) bool {
	return s&s2 != 0
}
