package input

import (
	"testing"

	"github.com/stretchr/testify/require"
)

func TestMouseStateCode(t *testing.T) {
	states := []MouseStateCode{
		NOX_MOUSE_LEFT_DOWN,
		NOX_MOUSE_LEFT_DRAG_END,
		NOX_MOUSE_LEFT_UP,
		NOX_MOUSE_LEFT_PRESSED,
		NOX_MOUSE_RIGHT_DOWN,
		NOX_MOUSE_RIGHT_DRAG_END,
		NOX_MOUSE_RIGHT_UP,
		NOX_MOUSE_RIGHT_PRESSED,
		NOX_MOUSE_MIDDLE_DOWN,
		NOX_MOUSE_MIDDLE_DRAG_END,
		NOX_MOUSE_MIDDLE_UP,
		NOX_MOUSE_MIDDLE_PRESSED,
	}
	for i, btn := range []MouseButton{
		-1, NOX_MOUSE_LEFT, NOX_MOUSE_RIGHT, NOX_MOUSE_MIDDLE,
	} {
		t.Run(btn.String(), func(t *testing.T) {
			for j, st := range []MouseState{
				NOX_MOUSE_DOWN, NOX_MOUSE_DRAG_END, NOX_MOUSE_UP, NOX_MOUSE_PRESSED,
			} {
				t.Run(st.String(), func(t *testing.T) {
					bst := ToMouseState(btn, st)
					t.Log(bst)
					if i != 0 {
						require.Equal(t, states[4*(i-1)+j], bst)
					}
					btn2, st2 := bst.Split()
					require.Equal(t, btn, btn2)
					require.Equal(t, st, st2)
				})
			}
		})
	}
}
