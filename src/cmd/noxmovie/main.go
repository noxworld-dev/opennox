package main

import (
	"errors"
	"flag"
	"fmt"
	"image"
	"image/draw"
	"io"
	_ "net/http/pprof"
	"os"
	"time"

	"nox/v1/client/audio/ail"
	"nox/v1/client/render"
	"nox/v1/client/seat"
	"nox/v1/client/seat/sdl"
	"nox/v1/common/alloc/handles"
	"nox/v1/common/noximage"
	"nox/v1/common/types"

	"github.com/noxworld-dev/vqa-decode/movies"
	"github.com/timshannon/go-openal/openal"
	"github.com/youpy/go-wav"
)

var (
	fMovie = flag.String("i", "intro.vqa", "movie file to open")
)

func main() {
	flag.Parse()
	if err := run(*fMovie); err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
}

type Frame struct {
	Image *noximage.Image16
	Audio [][2]int16
}

type MoviePlayer struct {
	queue     chan *Frame
	movie     *movies.VqaFile
	file      io.Closer
	seat      seat.Seat
	oldInputs seat.InputConfig
	renderer  *render.Renderer
	audioDrv  ail.Driver
	audioSrc  ail.Sample
	stop      chan struct{}
}

func (player *MoviePlayer) Start() {
	go player.decode()
}

func (player *MoviePlayer) decode() {
	for {
		select {
		case <-player.stop:
			return
		default:
		}
		frame, samples, err := player.movie.DecodeNextFrame()
		if err != nil {
			return
		}
		img16 := noximage.NewImage16(frame.Rect)
		draw.Draw(img16, img16.Rect, frame, image.Pt(0, 0), draw.Src)
		select {
		case <-player.stop:
			return
		case player.queue <- &Frame{
			Image: img16,
			Audio: samples,
		}:
		}
	}
}

func NewPlayer(fname string, mvSeat seat.Seat, audioDrv ail.Driver) (plr *MoviePlayer, err error) {
	vqaFile, err := os.Open(fname)
	if err != nil {
		return nil, err
	}

	vqa, err := movies.OpenMovieWithHandle(vqaFile)
	if err != nil {
		return nil, err
	}

	rend, err := render.New(mvSeat)
	if err != nil {
		return nil, err
	}
	queue := make(chan *Frame, vqa.Header.Fps*2)
	stop := make(chan struct{})

	audioSrc := audioDrv.AllocateSample()

	oldInputs := mvSeat.ReplaceInputs(nil)

	var player = &MoviePlayer{
		queue:     queue,
		movie:     vqa,
		file:      vqaFile,
		seat:      mvSeat,
		renderer:  rend,
		audioDrv:  audioDrv,
		audioSrc:  audioSrc,
		stop:      stop,
		oldInputs: oldInputs,
	}

	// TODO: actually replace the preexisting events
	mvSeat.OnInput(func(ev seat.InputEvent) {
		switch ev := ev.(type) {
		case seat.WindowEvent:
			switch ev {
			case seat.WindowClosed:
				// If user tries to close the window, stop the loop.
				player.Close()
			}
		case *seat.KeyboardEvent, *seat.MouseButtonEvent:
			// Stop the loop on keyboard or mouse key press as well.
			player.Close()
		}
	})

	return player, nil
}

func (player *MoviePlayer) Close() {
	select {
	case <-player.stop:
		return
	default:
	}
	close(player.stop)
	player.file.Close()
	player.audioSrc.Stop()
	player.audioSrc.Release()
	player.seat.ReplaceInputs(player.oldInputs)
}

func convertSampleToData(samples []wav.Sample, format openal.Format) []byte {
	var output = make([]byte, len(samples)*2*2)
	for i := 0; i < len(samples); i++ {
		left := samples[i].Values[0]
		right := samples[i].Values[1]
		output[i*4] = byte(left & 0xFF)
		output[i*4+1] = byte((left >> 8) & 0xFF)
		if format == openal.FormatMono16 {
			output[i*4+2] = output[i*2]
			output[i*4+3] = output[i*2+1]
		} else {
			output[i*4+2] = byte(right & 0xFF)
			output[i*4+3] = byte((right >> 8) & 0xFF)
		}
	}
	return output
}

func (player *MoviePlayer) Play() {
	// TODO: if we got no audio, we could probably still keep displaying frames...
	// Note that the frame delays are all calculated based on sound position
	audioSrc := player.audioSrc.GetSource()
	if audioSrc == nil {
		player.Close()
		return
	}
	alSrc := openal.Source(*audioSrc)
	alSrc.SetLooping(false)
	alSrc.SetPosition(&openal.Vector{0, 0, 0})
	alSrc.SetGain(1)

	framesChan := make(chan *Frame, player.movie.Header.Fps)

	var (
		currentFrame              = 0
		samplesWithCommitedFrames = 0
		queuedSamples             = 0
		finishedSamples           = 0
		audioBuffers              openal.Buffers
	)
	defer func() {
		// Cleanup audio buffers
		for i := 0; i < len(audioBuffers); i++ {
			audioBuffers[i].Delete()
		}
	}()
	//var currentFrameImg *noximage.Image16 = nil
	time.Sleep(time.Second / time.Duration(player.movie.Header.Fps/5))
loop:
	for {
		// Process input events.
		player.seat.InputTick()

		// Run until movie player tells us to stop.
		select {
		case <-player.stop:
			break loop
		default:
		}

		var nextFrame *Frame

		// First, we attempt to buffer several frames of audio in advance to avoid audio overruns
	audioloop:
		for {
			select {
			case <-player.stop:
				break loop
			case newFrame := <-player.queue:
				var buffer openal.Buffer
				if len(audioBuffers) < 1 {
					buffer = openal.NewBuffer()
				} else {
					buffer = audioBuffers[0]
					audioBuffers = audioBuffers[1:]
				}
				sampleRate := int32(player.movie.Header.SampleRate)
				buffer.SetDataStereo16(newFrame.Audio, sampleRate)
				queuedSamples += len(newFrame.Audio)
				alSrc.QueueBuffer(buffer)
				if alSrc.State() != openal.Playing {
					alSrc.Play()
				}
				select {
				default:
					nextFrame = <-framesChan
					framesChan <- newFrame
					break audioloop
				case framesChan <- newFrame:
				}
			default:
				select {
				case nextFrame = <-framesChan:
					break audioloop
				default:
					break loop
				}
			}
		}

		// Now cleanup any finished audio buffers
		if processedCount := alSrc.BuffersProcessed(); processedCount > 0 {
			buffersProcessed := make(openal.Buffers, processedCount)
			alSrc.UnqueueBuffers(buffersProcessed)
			audioBuffers = append(audioBuffers, buffersProcessed...)
			for i := 0; i < len(buffersProcessed); i++ {
				b := audioBuffers[i]
				samples := b.GetSize() / ((b.GetBits() / 8) * b.GetChannels())
				finishedSamples += int(samples)
			}
		}

		// Now time to deal with the frame
		player.renderer.CopyBuffer(nextFrame.Image)
		samplesWithCommitedFrames += len(nextFrame.Audio)

		// Run audio callbacks.
		ail.Serve()

		// Now let's calculate the sleep time
		// First let's get where we are at our playback
		sampleDuration := time.Second / time.Duration(player.movie.Header.SampleRate)
		currentSample := int(alSrc.GetOffsetSamples())
		currentPosition := time.Duration(currentSample+finishedSamples) * sampleDuration
		// Now let's determine when the next frame should be displayed
		// We assume it should be no later than the next audio queue up
		expectedSamplesCount := samplesWithCommitedFrames
		expectedPosition := time.Duration(expectedSamplesCount) * sampleDuration
		// Now let's determine the next wake up call time
		if sleep := expectedPosition - currentPosition; sleep > 0 {
			select {
			case <-player.stop:
				break loop
			case <-time.After(sleep):
			}
		}
		//currentFrameImg = nextFrame.Image
		currentFrame++
	}
}

func run(fname string) error {
	// Handles needed for communication with C (currently used by audio backend).
	// TODO: move them to engine instead
	handles.Init()
	defer handles.Release()

	// Initialize SDL window.
	sz := types.Size{
		W: 640,
		H: 480,
	}
	win, err := sdl.New("Nox Movie Player", sz)
	if err != nil {
		return err
	}
	defer win.Close()

	// Initialize audio.
	ail.Startup()
	defer ail.Shutdown()

	drv := ail.WaveOutOpen()
	if e := ail.LastError(); e != "" {
		return errors.New(e)
	}

	plr, err := NewPlayer(fname, win, drv)
	if err != nil {
		return err
	}
	defer plr.Close()

	plr.Start()
	plr.Play()
	return nil
}
