package sdl

import (
	"errors"
	"fmt"
	"os"

	"github.com/go-gl/gl/v3.3-core/gl"
	"github.com/veandco/go-sdl2/sdl"

	"nox/v1/client/seat"
	"nox/v1/common/env"
	"nox/v1/common/log"
	"nox/v1/common/types"
)

var (
	Log       = log.New("sdl")
	debugGpad = os.Getenv("NOX_DEBUG_GPAD") == "true"
)

var _ seat.Seat = &Window{}

// New creates a new SDL window which implements a Seat interface.
func New(title string, sz types.Size) (*Window, error) {
	// TODO: if we ever decide to use multiple windows, this will need to be moved elsewhere; same for sdl.Quit
	if err := sdl.Init(sdl.INIT_VIDEO | sdl.INIT_TIMER | sdl.INIT_GAMECONTROLLER); err != nil {
		return nil, fmt.Errorf("SDL Initialization failed: %w", err)
	}
	sdl.SetHint(sdl.HINT_RENDER_SCALE_QUALITY, "1")
	if err := sdl.GLSetAttribute(sdl.GL_CONTEXT_MAJOR_VERSION, 3); err != nil {
		return nil, fmt.Errorf("cannot set OpenGL version: %w", err)
	}
	if err := sdl.GLSetAttribute(sdl.GL_CONTEXT_MINOR_VERSION, 3); err != nil {
		return nil, fmt.Errorf("cannot set OpenGL version: %w", err)
	}
	if err := sdl.GLSetAttribute(sdl.GL_CONTEXT_PROFILE_CORE, 1); err != nil {
		return nil, fmt.Errorf("cannot set OpenGL core: %w", err)
	}
	if err := sdl.GLSetAttribute(sdl.GL_CONTEXT_FORWARD_COMPATIBLE_FLAG, 1); err != nil {
		return nil, fmt.Errorf("cannot set OpenGL forward: %w", err)
	}
	if err := sdl.GLSetAttribute(sdl.GL_DOUBLEBUFFER, 1); err != nil {
		return nil, fmt.Errorf("cannot set OpenGL attribute: %w", err)
	}

	win, err := sdl.CreateWindow(title, sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED, int32(sz.W), int32(sz.H),
		sdl.WINDOW_RESIZABLE|sdl.WINDOW_OPENGL)
	if err != nil {
		sdl.Quit()
		return nil, fmt.Errorf("SDL Window creation failed: %w", err)
	}
	h := &Window{
		win: win, prevSz: sz,
	}
	h.SetScreenMode(seat.Windowed)
	if err := h.initGL(); err != nil {
		_ = win.Destroy()
		sdl.Quit()
		return nil, err
	}
	return h, nil
}

type Window struct {
	win      *sdl.Window
	prevPos  types.Point
	prevSz   types.Size
	mode     seat.ScreenMode
	rel      bool
	mpos     types.Point
	onResize []func(sz types.Size)
	onInput  []func(ev seat.InputEvent)
	vao      uint32
	vbo      uint32
	ebo      uint32
	prog     uint32
	frag     uint32
	vert     uint32
}

func (win *Window) Close() error {
	if win.win == nil {
		return nil
	}
	win.closeGL()
	err := win.win.Destroy()
	win.win = nil
	win.onResize = nil
	win.onInput = nil
	sdl.Quit()
	return err
}

func (win *Window) OnInput(fnc func(ev seat.InputEvent)) {
	win.onInput = append(win.onInput, fnc)
}

func (win *Window) SetTextInput(enable bool) {
	if enable {
		sdl.StartTextInput()
	} else {
		sdl.StopTextInput()
	}
}

func (win *Window) ScreenSize() types.Size {
	w, h := win.win.GLGetDrawableSize()
	return types.Size{
		W: int(w), H: int(h),
	}
}

func (win *Window) screenPos() types.Point {
	x, y := win.win.GetPosition()
	return types.Point{
		X: int(x), Y: int(y),
	}
}

func (win *Window) displayRect() sdl.Rect {
	disp, err := win.win.GetDisplayIndex()
	if err != nil {
		Log.Println("can't get display index: ", err)
		return sdl.Rect{}
	}
	rect, err := sdl.GetDisplayBounds(disp)
	if err != nil {
		Log.Println("can't get display bounds: ", err)
		return sdl.Rect{}
	}
	return rect
}

func (win *Window) ScreenMaxSize() types.Size {
	rect := win.displayRect()
	return types.Size{
		W: int(rect.W), H: int(rect.H),
	}
}

func (win *Window) setSize(sz types.Size) {
	Log.Printf("window size: %dx%d", sz.W, sz.H)
	win.win.SetSize(int32(sz.W), int32(sz.H))
}

func (win *Window) center() {
	win.win.SetPosition(sdl.WINDOWPOS_CENTERED, sdl.WINDOWPOS_CENTERED)
}

func (win *Window) ResizeScreen(sz types.Size) {
	if win.mode != seat.Windowed {
		return
	}
	win.setSize(sz)
	win.prevSz = sz
}

func (win *Window) setRelative(rel bool) {
	if win.rel == rel {
		return
	}
	win.rel = rel
	win.win.SetGrab(rel)
	sdl.SetRelativeMouseMode(rel)
}

func (win *Window) SetScreenMode(mode seat.ScreenMode) {
	if win.mode == mode {
		return
	}
	if win.mode == seat.Windowed {
		// preserve size and pos, so we can restore them later
		win.prevSz = win.ScreenSize()
		win.prevPos = win.screenPos()
	}
	switch mode {
	case seat.Windowed:
		win.win.SetFullscreen(0)
		win.win.SetResizable(true)
		win.win.SetBordered(true)
		win.setSize(win.prevSz)
		if win.prevPos != (types.Point{}) {
			win.win.SetPosition(int32(win.prevPos.X), int32(win.prevPos.Y))
		} else {
			win.center()
		}
		if env.IsDevMode() || env.IsE2E() {
			sdl.ShowCursor(sdl.ENABLE)
		} else {
			sdl.ShowCursor(sdl.DISABLE)
		}
		win.setRelative(false)
	case seat.Fullscreen:
		win.win.SetResizable(false)
		win.win.SetBordered(false)
		win.setSize(win.ScreenMaxSize())
		win.win.SetFullscreen(sdl.WINDOW_FULLSCREEN_DESKTOP)
		sdl.ShowCursor(sdl.DISABLE)
		win.setRelative(true)
	case seat.Borderless:
		win.win.SetFullscreen(0)
		win.win.SetResizable(false)
		win.win.SetBordered(true)
		win.setSize(win.ScreenMaxSize())
		win.center()
		sdl.ShowCursor(sdl.DISABLE)
		win.setRelative(false)
	}
	win.mode = mode
}

// SetGamma sets screen gamma parameter.
func (win *Window) SetGamma(v float32) {
	var ramp [256]uint16
	sdl.CalculateGammaRamp(v, &ramp)
	if err := win.win.SetGammaRamp(&ramp, &ramp, &ramp); err != nil {
		Log.Printf("cannot set gamma: %v", err)
	}
}

func (win *Window) OnScreenResize(fnc func(sz types.Size)) {
	win.onResize = append(win.onResize, fnc)
}

func (win *Window) initGL() error {
	gtx, err := win.win.GLCreateContext()
	if err != nil {
		return fmt.Errorf("OpenGL creation failed: %w", err)
	}
	err = win.win.GLMakeCurrent(gtx)
	if err != nil {
		return fmt.Errorf("OpenGL bind failed: %w", err)
	}
	sdl.GLSetSwapInterval(0)
	if err := gl.Init(); err != nil {
		return fmt.Errorf("OpenGL init failed: %w", err)
	}
	Log.Println("OpenGL version:", gl.GoStr(gl.GetString(gl.VERSION)))

	gl.GenVertexArrays(1, &win.vao)
	gl.BindVertexArray(win.vao)

	gl.GenBuffers(1, &win.vbo)
	gl.BindBuffer(gl.ARRAY_BUFFER, win.vbo)
	quad := []float32{
		// pos, tex
		-1, -1, 0, 1,
		-1, +1, 0, 0,
		+1, +1, 1, 0,
		+1, -1, 1, 1,
	}
	gl.BufferData(gl.ARRAY_BUFFER, len(quad)*4, gl.Ptr(quad), gl.STATIC_DRAW)

	gl.GenBuffers(1, &win.ebo)
	gl.BindBuffer(gl.ELEMENT_ARRAY_BUFFER, win.ebo)
	elems := []uint32{
		0, 1, 2,
		2, 3, 0,
	}
	gl.BufferData(gl.ELEMENT_ARRAY_BUFFER, len(elems)*4, gl.Ptr(elems), gl.STATIC_DRAW)

	if err := win.initProgram(); err != nil {
		return err
	}

	return nil
}

func (win *Window) closeGL() {
	gl.DeleteProgram(win.prog)
	gl.DeleteShader(win.vert)
	gl.DeleteShader(win.frag)
	gl.DeleteBuffers(1, &win.vbo)
	gl.DeleteBuffers(1, &win.ebo)
	gl.DeleteVertexArrays(1, &win.vao)
}

func (win *Window) compileShader(typ uint32, src string) (uint32, error) {
	s := gl.CreateShader(typ)
	cstr, free := gl.Strs(src)
	gl.ShaderSource(s, 1, cstr, nil)
	free()
	gl.CompileShader(s)
	var st int32
	gl.GetShaderiv(s, gl.COMPILE_STATUS, &st)
	if st == gl.FALSE {
		var sz int32
		gl.GetShaderiv(s, gl.INFO_LOG_LENGTH, &sz)
		text := make([]byte, sz+1)
		gl.GetShaderInfoLog(s, sz, nil, &text[0])
		return 0, errors.New(string(text))
	}
	return s, nil
}

func (win *Window) initProgram() error {
	const glVertShader = `#version 150 core
in vec2 position;
in vec2 texcoord;

out vec2 Texcoord;

void main()
{
	Texcoord = texcoord;
    gl_Position = vec4(position, 0.0, 1.0);
}
` + "\x00"

	const glFragShader = `#version 150 core
uniform sampler2D tex;
in vec2 Texcoord;

out vec4 outColor;

void main()
{
    outColor = texture(tex, Texcoord);
}
` + "\x00"

	vert, err := win.compileShader(gl.VERTEX_SHADER, glVertShader)
	if err != nil {
		return fmt.Errorf("cannot compile vertex shader: %w", err)
	}
	frag, err := win.compileShader(gl.FRAGMENT_SHADER, glFragShader)
	if err != nil {
		return fmt.Errorf("cannot compile vertex shader: %w", err)
	}

	prog := gl.CreateProgram()
	gl.AttachShader(prog, vert)
	gl.AttachShader(prog, frag)
	gl.BindFragDataLocation(prog, 0, gl.Str("outColor\x00"))
	gl.LinkProgram(prog)

	var st int32
	gl.GetProgramiv(prog, gl.LINK_STATUS, &st)
	if st == gl.FALSE {
		var sz int32
		gl.GetProgramiv(prog, gl.INFO_LOG_LENGTH, &sz)
		text := make([]byte, sz+1)
		gl.GetProgramInfoLog(prog, sz, nil, &text[0])
		return errors.New(string(text))
	}
	win.prog = prog

	gl.UseProgram(prog)
	gl.Uniform1i(gl.GetUniformLocation(prog, gl.Str("tex\x00")), 0)

	posAttr := gl.GetAttribLocation(prog, gl.Str("position\x00"))
	gl.EnableVertexAttribArray(uint32(posAttr))
	gl.VertexAttribPointer(uint32(posAttr), 2, gl.FLOAT, false, 4*4, gl.PtrOffset(0*4))

	texAttr := gl.GetAttribLocation(prog, gl.Str("texcoord\x00"))
	gl.EnableVertexAttribArray(uint32(texAttr))
	gl.VertexAttribPointer(uint32(texAttr), 2, gl.FLOAT, false, 4*4, gl.PtrOffset(2*4))
	return nil
}

func (win *Window) Clear() {
	gl.Disable(gl.DEPTH_TEST)
	gl.ClearColor(0, 0, 0, 1)
	gl.Clear(gl.COLOR_BUFFER_BIT)
}

func (win *Window) Present() {
	win.win.GLSwap()
}

func (win *Window) InputTick() {
	for {
		switch ev := sdl.PollEvent().(type) {
		case nil:
			// no more events
			return
		case *sdl.TextEditingEvent:
			win.processTextEditingEvent(ev)
		case *sdl.TextInputEvent:
			win.processTextInputEvent(ev)
		case *sdl.KeyboardEvent:
			win.processKeyboardEvent(ev)
		case *sdl.MouseButtonEvent:
			win.processMouseButtonEvent(ev)
		case *sdl.MouseMotionEvent:
			win.processMotionEvent(ev)
		case *sdl.MouseWheelEvent:
			win.processWheelEvent(ev)
		case *sdl.ControllerAxisEvent:
			if debugGpad {
				Log.Printf("SDL event: SDL_CONTROLLERAXISMOTION (%x): joy=%d, axis=%d, val=%d\n",
					ev.GetType(), ev.Which, ev.Axis, ev.Value)
			}
			win.processGamepadAxisEvent(ev)
		case *sdl.ControllerButtonEvent:
			if debugGpad {
				Log.Printf("SDL event: SDL_CONTROLLERBUTTON (%x): joy=%d, btn=%d, state=%d\n",
					ev.GetType(), ev.Which, ev.Button, ev.State)
			}
			win.processGamepadButtonEvent(ev)
		case *sdl.ControllerDeviceEvent:
			switch ev.GetType() {
			case sdl.CONTROLLERDEVICEADDED:
				if debugGpad {
					Log.Printf("SDL event: SDL_CONTROLLERDEVICEADDED (%x): joy=%d\n", ev.GetType(), ev.Which)
				}
				win.processGamepadDeviceEvent(ev)
			case sdl.CONTROLLERDEVICEREMOVED:
				if debugGpad {
					Log.Printf("SDL event: SDL_CONTROLLERDEVICEREMOVED (%x): joy=%d\n", ev.GetType(), ev.Which)
				}
				win.processGamepadDeviceEvent(ev)
			case sdl.CONTROLLERDEVICEREMAPPED:
				if debugGpad {
					Log.Printf("SDL event: SDL_CONTROLLERDEVICEREMAPPED (%x)\n", ev.GetType())
				}
			}
		case *sdl.WindowEvent:
			win.processWindowEvent(ev)
		case *sdl.QuitEvent:
			win.processQuitEvent(ev)
		}
		// TODO: touch events for WASM
	}
}

func (win *Window) inputEvent(ev seat.InputEvent) {
	for _, fnc := range win.onInput {
		fnc(ev)
	}
}

func (win *Window) processQuitEvent(ev *sdl.QuitEvent) {
	win.inputEvent(seat.WindowClosed)
}

func (win *Window) processWindowEvent(ev *sdl.WindowEvent) {
	switch ev.GetType() {
	case sdl.WINDOWEVENT_FOCUS_LOST:
		win.inputEvent(seat.WindowUnfocused)
	case sdl.WINDOWEVENT_FOCUS_GAINED:
		win.inputEvent(seat.WindowFocused)
	}
}

func (win *Window) processTextEditingEvent(ev *sdl.TextEditingEvent) {
	win.inputEvent(&seat.TextEditEvent{
		Text: ev.GetText(),
	})
}

func (win *Window) processTextInputEvent(ev *sdl.TextInputEvent) {
	win.inputEvent(&seat.TextInputEvent{
		Text: ev.GetText(),
	})
}

func (win *Window) processKeyboardEvent(ev *sdl.KeyboardEvent) {
	key := scanCodeToKeyNum[ev.Keysym.Scancode]
	win.inputEvent(&seat.KeyboardEvent{
		Key:     key,
		Pressed: ev.State == sdl.PRESSED,
	})
}

func (win *Window) processMouseButtonEvent(ev *sdl.MouseButtonEvent) {
	pressed := ev.State == sdl.PRESSED
	// TODO: handle focus, or move to other place
	//if pressed {
	//	h.iface.WindowEvent(WindowFocus)
	//}

	var button seat.MouseButton
	switch ev.Button {
	case sdl.BUTTON_LEFT:
		button = seat.MouseButtonLeft
	case sdl.BUTTON_RIGHT:
		button = seat.MouseButtonRight
	case sdl.BUTTON_MIDDLE:
		button = seat.MouseButtonMiddle
	default:
		return
	}
	win.inputEvent(&seat.MouseButtonEvent{
		Button:  button,
		Pressed: pressed,
	})
}

func (win *Window) processMotionEvent(ev *sdl.MouseMotionEvent) {
	win.inputEvent(&seat.MouseMoveEvent{
		Relative: win.rel,
		Pos:      types.Point{X: int(ev.X), Y: int(ev.Y)},
		Rel:      types.Pointf{X: float32(ev.XRel), Y: float32(ev.YRel)},
	})
}

func (win *Window) processWheelEvent(ev *sdl.MouseWheelEvent) {
	win.inputEvent(&seat.MouseWheelEvent{
		Wheel: int(ev.Y),
	})
}

func (win *Window) processGamepadButtonEvent(ev *sdl.ControllerButtonEvent) {
	// TODO: handle gamepads (again)
}

func (win *Window) processGamepadAxisEvent(ev *sdl.ControllerAxisEvent) {
	// TODO: handle gamepads (again)
}

func (win *Window) processGamepadDeviceEvent(ev *sdl.ControllerDeviceEvent) {
	// TODO: handle gamepads (again)
}
