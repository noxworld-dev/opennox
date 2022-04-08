package noxmovie

import (
	"image"
	"image/draw"
	"io"
	"os"
	"time"

	"nox/v1/client/audio/ail"
	"nox/v1/client/render"
	"nox/v1/client/seat"
	"nox/v1/common/noximage"

	"github.com/noxworld-dev/vqa-decode/movies"
	"github.com/timshannon/go-openal/openal"
	"github.com/youpy/go-wav"
)

type Frame struct {
	Image *noximage.Image16
	Audio [][2]int16
}

type MoviePlayer struct {
	queue        chan *Frame
	movie        *movies.VqaFile
	file         io.Closer
	seat         seat.Seat
	oldInputs    seat.InputConfig
	renderer     *render.Renderer
	audioDrv     ail.Driver
	audioSrc     ail.Sample
	audioBuffers openal.Buffers
	stop         chan struct{}
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

func NewPlayerWithHandle(file io.ReadSeekCloser, mvSeat seat.Seat, audioDrv ail.Driver) (plr *MoviePlayer, err error) {
	vqa, err := movies.OpenMovieWithHandle(file)
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
		file:      file,
		seat:      mvSeat,
		renderer:  rend,
		audioDrv:  audioDrv,
		audioSrc:  audioSrc,
		stop:      stop,
		oldInputs: oldInputs,
	}

	// TODO: actually replace the preexisting events
	mvSeat.OnInput(func(ev seat.InputEvent) {
		switch evt := ev.(type) {
		case seat.WindowEvent:
			switch evt {
			case seat.WindowClosed:
				// If user tries to close the window, stop the loop.
				player.Close()
			}
		case *seat.KeyboardEvent:
			if evt.Pressed {
				// Stop the loop on keyboard key press as well.
				player.Close()
			}
		case *seat.MouseButtonEvent:
			if evt.Pressed {
				// Stop the loop on mouse key press as well.
				player.Close()
			}
		}
	})

	return player, nil
}

func NewPlayer(fname string, mvSeat seat.Seat, audioDrv ail.Driver) (plr *MoviePlayer, err error) {
	vqaFile, err := os.Open(fname)
	if err != nil {
		return nil, err
	}

	return NewPlayerWithHandle(vqaFile, mvSeat, audioDrv)
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

	// First we need to release the audio source, and only then delete the (possibly) attached buffers
	player.audioSrc.Release()
	if len(player.audioBuffers) > 0 {
		player.audioBuffers.Delete()
	}

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
		sampleDuration            = time.Second / time.Duration(player.movie.Header.SampleRate)
		currentFrameImg *noximage.Image16 = nil
	)
	//var currentFrameImg *noximage.Image16 = nil
	select {
	case <-player.stop:
		return
	case <-time.After(time.Second / time.Duration(player.movie.Header.Fps/5)):
	}


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
					player.audioBuffers = append(player.audioBuffers, buffer)
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
					nextFrame = nil
					break audioloop
				}
			}
		}

		if (nextFrame != nil) {

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
 
			samplesWithCommitedFrames += len(nextFrame.Audio)
		}

		// Run audio callbacks.
		ail.Serve()

		if currentFrameImg != nil {
			player.renderer.CopyBuffer(currentFrameImg)
		}

		// Now let's calculate the sleep time
		// First let's get where we are at our playback
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

		if nextFrame == nil {
			break;
		}

		currentFrameImg = nextFrame.Image

		//currentFrameImg = nextFrame.Image
		currentFrame++
	}
}
