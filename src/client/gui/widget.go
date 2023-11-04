package gui

func NewButtonOrCheckboxRaw(g *GUI, parent *Window, status StatusFlags, px, py, w, h int, draw *WindowData) *Window {
	st := draw.Style
	if st.IsPushButton() {
		return NewButtonRaw(g, parent, status, px, py, w, h, draw)
	} else if st.IsCheckBox() {
		return NewCheckBoxRaw(g, parent, status, px, py, w, h, draw)
	}
	return nil
}
