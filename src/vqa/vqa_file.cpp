//#include "stdafx.h"
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#define XCC
#include "vqa_file.h"

//#include <vfw.h>
//#include "image_file.h"
//#include "pcx_decode.h"
//#include "string_conversion.h"
#include "vqa_decode.h"
//#include "wav_structures.h"
//#include "xcc_log.h"

Cvqa_file::Cvqa_file(string filename)
{
	extAlContext = NULL;
	fileStream.open(filename, ios::in | ios::binary);
	bool success = fileStream.good();
	fileStream.seekg(0, ios::end);
	success = fileStream.good();
	fileSize = fileStream.tellg();
	success = fileStream.good();
	fileStream.seekg(0, ios::beg);
	success = fileStream.good();
	currentPosition = fileStream.tellg();
	success = fileStream.good();
}

bool Cvqa_file::is_valid()
{
	if (!fileStream.good())
	{
		return false;
	}
	
	int size = get_size(); // Filesize
	/*
	if (get_data())
	memcpy(&m_header, get_data(), sizeof(t_vqa_header));
	*/
	return !(sizeof(t_vqa_header) > size ||
		m_header.file_header.id != vqa_file_id ||
		m_header.id != vqa_form_id);
}

Cvqa_file::~Cvqa_file()
{
	fileStream.close();
	fileStream.clear();
}

int Cvqa_file::post_open()
{
	int error = read(&m_header, sizeof(t_vqa_header)); // Read header
	return error ? error : read_chunk_header();
}

struct t_list_entry
{
	int c_samples;
	short* audio;
};

struct cache_entry
{
    byte* frames_buffer;
    unsigned int frames_buffer_size;
    unsigned int frames_buffer_position;
    byte* audio_buffer;
    unsigned int audio_buffer_size;
    unsigned int audio_buffer_position;
    bool audio_is_queued;
    bool is_playing;
};

#define MAX_CACHES 5

int Cvqa_file::extract_both()
{
    cache_entry caches[MAX_CACHES];
    for (int i = 0; i < MAX_CACHES; i++)
    {
        caches[i].frames_buffer_size = get_cx() * get_cy() * 2 * header().fps * 2;
        caches[i].frames_buffer = (byte*)malloc(caches[i].frames_buffer_size);
        memset(caches[i].frames_buffer, 0, caches[i].frames_buffer_size);
        caches[i].frames_buffer_position = 0;
        caches[i].audio_buffer_size = get_samplerate() * (16 / 8) * get_c_channels() * 3; // we reserve for audio buffer a bit more space to prevent is_playing setting because of audio and underfeeding frames buffer
        caches[i].audio_buffer = (byte*)malloc(caches[i].audio_buffer_size);
        memset(caches[i].audio_buffer, 0, caches[i].audio_buffer_size);
        caches[i].audio_buffer_position = 0;
        caches[i].audio_is_queued = false;
        caches[i].is_playing = false;
    }

    int writeCache = 0;
    int readCache = 0;

    ALCcontext* alContext;
    ALCdevice* device = NULL;
	// Initialize OpenAL
	if (extAlContext != NULL)
	{
        alContext = extAlContext;
	}
	else
	{
        device = alcOpenDevice(NULL);
        alContext = alcCreateContext(device, NULL);
	}
    ALCcontext* previousContext = alcGetCurrentContext();
    alcMakeContextCurrent(alContext);
	if (extAlContext == NULL)
	{
		extAlContext = alContext;
	}

    ALuint source;

    // Request a source name
    alGenSources((ALuint)1, &source);

    // Set the default volume
    alSourcef(source, AL_GAIN, 1);

    // Set the default position of the sound
    alSource3f(source, AL_POSITION, 0, 0, 0);

    // Disable looping
    alSourcei(source, AL_LOOPING, 0);

    ALenum format = AL_FORMAT_MONO16;
    if (get_c_channels() == 2)
    {
        format = AL_FORMAT_STEREO16;
    }

    ALuint frequency = get_samplerate();

    ALuint buffers[MAX_CACHES];
    ALuint busyBuffers[MAX_CACHES];
    ALuint buffersProc[MAX_CACHES];
    memset(buffersProc, 0, sizeof(buffersProc));
    memset(buffers, 0, sizeof(buffers));
    memset(busyBuffers, 0, sizeof(busyBuffers));
    ALint buffersProcessed = 0;
    // Request a buffer name
    alGenBuffers(MAX_CACHES, buffers);


	bool isPlaying = false;


	int error = 0;
	Cvqa_decode vqa_d;
	vqa_d.start_decode(header());
	int cx = get_cx();
	int cy = get_cy();
	DDPIXELFORMAT_VQA pf;
	pf.dwRGBAlphaBitMask = 1 << 15;
	pf.dwRBitMask = 0x1f << 10;
	pf.dwGBitMask = 0x1f << 5;
	pf.dwBBitMask = 0x1f;
	vqa_d.set_pf(pf, 2);
	int cs_remaining = 0;

	/*ofstream audio;
	audio.open(name + ".wav", ios::binary | ios::trunc);
	t_wav_header header;
	memset(&header, 0, sizeof(t_wav_header));
	audio.write((char*)&header, sizeof(t_wav_header));*/


	byte* frame = new byte[2 * cx * cy];
    byte* frameDraw = new byte[2 * cx * cy];

	int currentFrame = 0;
	int soundBytesOnFrame = 0;

	int delayT = 0;
	int changesTOTAL = 0;
	bool defaultTOTALset = false;
	int defaultTOTAL = 0;

    unsigned int cachedFramesReadPosition = 0;

    dword startTime = SDL_GetTicks();

    int delayedPreviously = 0;

    int fpsCompensator = 0;

    long long allCallbackTime = 0;
    int howMuchCallbacks = 0;

	while (true)
	{
		int previousFrame = currentFrame;

        bool cachesFull = true;

        if (caches[writeCache].is_playing)
        {
            for (int i = 1; i <= (MAX_CACHES - 1); i++)
            {
                int nextWriteCache = writeCache + i;
                if (nextWriteCache > (MAX_CACHES - 1))
                {
                    nextWriteCache = 0;
                }
                if (!caches[nextWriteCache].is_playing)
                {
                    writeCache = nextWriteCache;
                    cachesFull = false;
                    break;
                }
            }
        }
        else
        {
            cachesFull = false;
        }

        if (currentFrame >= get_c_frames())
        {
            // We decoded everything, let's break out of the loop in case if the caches aren't playing anymore
            bool cachesFinished = true;
            for (int i = 0; i < MAX_CACHES; i++)
            {
                if (caches[i].is_playing)
                {
                    cachesFinished = false;
                    break;
                }
            }

            if (cachesFinished)
            {
                break;
            }
        }
        else if (cachesFull)
        {
            // We do nothing, as all caches are full, we need to wait until another cache would become available
            // Or we decoded everything and now waiting for caches to play out
        }
		else if (get_chunk_id() == vqa_vqfl_id)
		{
			byte* data = new byte[get_chunk_size()];
			read_chunk(data);
			vqa_d.decode_vqfl_chunk(data, get_chunk_size());
		}
		else if (is_video_chunk())
		{
			if (get_cbits_pixel() == 8)
			{
				printf("Unsupported video frame!\n");
			}
			else
			{
				byte* data = new byte[get_chunk_size()];
				read_chunk(data);
				vqa_d.decode_vqfr_chunk(data, frame, NULL);
				delete[] data;

				/*string filename = name + "_" + to_string(currentFrame) + ".bmp";
				bitmap_image bmp(cx, cy);
				byte* red = new byte[cx*cy];
				byte* green = new byte[cx*cy];
				byte* blue = new byte[cx*cy];
				for (int j = 0; j < cx * cy; j++)
				{
				red[j] = frame[j * 3];
				green[j] = frame[j * 3 + 1];
				blue[j] = frame[j * 3 + 2];
				}
				bmp.import_rgb(red, green, blue);
				bmp.save_image(filename);
				delete[] red;
				delete[] green;
				delete[] blue;*/
				// Raw frame in here (frame)

                byte* cachedFrame = &(caches[writeCache].frames_buffer[caches[writeCache].frames_buffer_position]);
                memcpy(cachedFrame, frame, 2 * cx * cy);
                caches[writeCache].frames_buffer_position += 2 * cx * cy;
                if (caches[writeCache].frames_buffer_position == caches[writeCache].frames_buffer_size)
                {
                    caches[writeCache].is_playing = true;
                }
                else if (caches[writeCache].frames_buffer_position > caches[writeCache].frames_buffer_size)
                {
                    printf("Frames buffer overrun!\n");
                }

				currentFrame++;
			}
		}
		else if (is_audio_chunk())
		{
			t_list_entry e;
			int size = get_chunk_size();
			if (get_chunk_id() >> 24 == '0')
			{
				printf("Unsupported audio frame!\n");
			}
			else
			{
				e.c_samples = size << 1;
				e.audio = new short[2 * size];
				byte* data = new byte[size];
				read_chunk(data);
				vqa_d.decode_snd2_chunk(data, size, e.audio);
			}
			cs_remaining += e.c_samples;

            byte* cachedAudio = &(caches[writeCache].audio_buffer[caches[writeCache].audio_buffer_position]);
            memcpy(cachedAudio, e.audio, 2 * e.c_samples);
            caches[writeCache].audio_buffer_position += 2 * e.c_samples;
            if (caches[writeCache].audio_buffer_position == caches[writeCache].audio_buffer_size)
            {
                caches[writeCache].is_playing = true;
            }
            else if (caches[writeCache].audio_buffer_position > caches[writeCache].audio_buffer_size)
            {
                printf("Audio buffer overrun!\n");
            }

			//audio.write((char*)e.audio, 2 * e.c_samples);
		}
		else
		{
			skip_chunk();
		}

		bool abort = false;

        // Process caches
        bool cachesUnavailable = true;

        if (!caches[readCache].is_playing)
        {
            for (int i = 1; i <= (MAX_CACHES - 1); i++)
            {
                int nextReadCache = readCache + i;
                if (nextReadCache > (MAX_CACHES - 1))
                {
                    nextReadCache = 0;
                }
                if (caches[nextReadCache].is_playing)
                {
                    readCache = nextReadCache;
                    /*// On read cache change we need to reset the frame buffer position
                    cachedFramesReadPosition = 0;*/
                    cachesUnavailable = false;
                    break;
                }
            }
        }
        else
        {
            cachesUnavailable = false;
        }

        if (cachesUnavailable)
        {
            // We do nothing here, as we're waiting for caches to be populated
        }
        else
        {
            // First process audio
            if (!caches[readCache].audio_is_queued)
            {
                ALuint currentBuffer = 0;
                ALuint dataSize = caches[readCache].audio_buffer_position; // We check the latest write position, as we don't need the non-filled parts

                while (currentBuffer == 0)
                {
                    ALint buffersProcessed = 0;
                    alGetSourcei(source, AL_BUFFERS_PROCESSED, &buffersProcessed);
                    if (buffersProcessed > 0)
                    {
                        ALuint unqueuedBuffers[MAX_CACHES];
                        memset(unqueuedBuffers, 0, sizeof(unqueuedBuffers));
                        alSourceUnqueueBuffers(source, buffersProcessed, unqueuedBuffers);
                        for (int j = 0; j < MAX_CACHES; j++)
                        {
                            if (0 != unqueuedBuffers[j])
                            {
                                for (int i = 0; i < MAX_CACHES; i++)
                                {
                                    if (unqueuedBuffers[j] == busyBuffers[i])
                                    {
                                        busyBuffers[i] = 0;
                                        break;
                                    }
                                }
                                for (int i = 0; i < MAX_CACHES; i++)
                                {
                                    if (0 == buffers[i])
                                    {
                                        buffers[i] = unqueuedBuffers[j];
                                        break;
                                    }
                                }
                            }
                        }
                    }

                    for (int i = 0; i < MAX_CACHES; i++)
                    {
                        if (0 != buffers[i])
                        {
                            currentBuffer = buffers[i];
                            buffers[i] = 0;
                            break;
                        }
                    }
                    for (int i = 0; i < MAX_CACHES; i++)
                    {
                        if (0 == busyBuffers[i])
                        {
                            busyBuffers[i] = currentBuffer;
                            break;
                        }
                    }
                } // while (currentBuffer == 0)

                alBufferData(currentBuffer, format, caches[readCache].audio_buffer, dataSize, frequency);
                alSourceQueueBuffers(source, 1, &currentBuffer);

                caches[readCache].audio_is_queued = true;
            } // if (!caches[readCache].audio_is_queued)

            // We start the audio AFTER the first frame of the cache was already played
            if (cachedFramesReadPosition == cx * cy * 2)
            {
                ALenum state;
                alGetSourcei(source, AL_SOURCE_STATE, &state);
                if (!isPlaying || state != AL_PLAYING)
                {
                    if (isPlaying)
                    {
                        printf("Movie restarting sound... Previous state = %d, delay = %d\n", state, delayedPreviously);
                        delayedPreviously = 0;
                    }
                    alSourceRewind(source);
                    alSourcePlay(source);
                    isPlaying = true;
                }
            }

            // Process video frame here
            memcpy(frameDraw, &(caches[readCache].frames_buffer[cachedFramesReadPosition]), cx * cy * 2);
            cachedFramesReadPosition += cx * cy * 2;

            unsigned int howMuchFrames = caches[readCache].frames_buffer_position / (cx * cy * 2);
            unsigned int howMuchMilliseconds = (caches[readCache].audio_buffer_position * 1000) / (get_samplerate() * (16 / 8) * get_c_channels());

            if (cachedFramesReadPosition == caches[readCache].frames_buffer_position)
            {
                // The cache is empty, reset it and release, and prepare for next cache
                cachedFramesReadPosition = 0;
                memset(caches[readCache].frames_buffer, 0, caches[readCache].frames_buffer_size);
                memset(caches[readCache].audio_buffer, 0, caches[readCache].audio_buffer_size);
                caches[readCache].frames_buffer_position = 0;
                caches[readCache].audio_buffer_position = 0;
                caches[readCache].audio_is_queued = false;
                caches[readCache].is_playing = false;
            }
            else if (cachedFramesReadPosition > caches[readCache].frames_buffer_position)
            {
                printf("Frames READ buffer overrun!\n");
            }

            int command = 0;
            if (decodeCallback != NULL)
            {
                command = decodeCallback(frameDraw, cx, cy);                
            }
            switch (command)
            {
            case -1:
                abort = true;
                break;
            default:
                break;
            }
            if (abort)
            {
                break;
            }

            long long timeBetweenFrames = (long long)(howMuchMilliseconds / howMuchFrames) + delayedPreviously + fpsCompensator / howMuchFrames;

            fpsCompensator = fpsCompensator % howMuchFrames + howMuchMilliseconds % howMuchFrames;

            dword currentTime = SDL_GetTicks();
            timeBetweenFrames -= currentTime - startTime;
            if (timeBetweenFrames > (long long)(howMuchMilliseconds / howMuchFrames))
            {
                printf("Bigger delay than anticipated %d\n", timeBetweenFrames);
            }
            else if (timeBetweenFrames < (long long)(howMuchMilliseconds / howMuchFrames - 10))
            {
                printf("Smaller delay than anticipated %d\n", timeBetweenFrames);
            }
            if (timeBetweenFrames > 0)
            {
                delayedPreviously = 0;
                dword beforeSleepTime = SDL_GetTicks();
                // We need to wait between frames
#ifdef __EMSCRIPTEN__
                emscripten_sleep(timeBetweenFrames);
#else
                SDL_Delay(timeBetweenFrames);
#endif
                dword afterSleepTime = SDL_GetTicks();
                delayedPreviously -= afterSleepTime - beforeSleepTime - timeBetweenFrames;
            }
            else
            {
                // How much time we "won back"
                delayedPreviously += (howMuchMilliseconds / howMuchFrames) - (currentTime - startTime);
            }
            startTime = SDL_GetTicks();
        }

		if (abort)
		{
			break;
		}
	}
	delete[] frame;
    delete[] frameDraw;
	if (isPlaying)
	{
        alSourceStop(source);
	}

    memset(buffersProc, 0, sizeof(buffersProc));
    alGetSourcei(source, AL_BUFFERS_PROCESSED, &buffersProcessed);
    alSourceUnqueueBuffers(source, buffersProcessed, buffersProc);

    for (int i = 0; i < MAX_CACHES; i++)
    {
        if (0 != busyBuffers[i])
        {
            for (int j = 0; j < MAX_CACHES; j++)
            {
                if (0 == buffers[j])
                {
                    buffers[j] = busyBuffers[i];
                    break;
                }
            }
            busyBuffers[i] = 0;
        }
    }

    alDeleteBuffers(MAX_CACHES, buffers);
    alDeleteSources(1, &source);
    alcMakeContextCurrent(previousContext);
    if (device != NULL)
    {
        alcDestroyContext(alContext);
        extAlContext = NULL;
        alcCloseDevice(device);
        device = NULL;
    }

    for (int i = 0; i < MAX_CACHES; i++)
    {
        free(caches[i].frames_buffer);
        free(caches[i].audio_buffer);
    }

	//directSoundBuffer->Release();
	//directSoundObj->Release();

	/*audio.seekp(0, ios::beg);
	header.file_header.id = wav_file_id;
	header.file_header.size = sizeof(header) - sizeof(header.file_header) + cs_remaining;
	header.form_type = wav_form_id;
	header.format_chunk.header.id = wav_format_id;
	header.format_chunk.header.size = sizeof(header.format_chunk) - sizeof(header.format_chunk.header);
	header.format_chunk.formattag = 1;
	header.format_chunk.c_channels = get_c_channels();
	header.format_chunk.samplerate = get_samplerate();
	header.format_chunk.byterate = 2 * get_c_channels() * get_samplerate();
	header.format_chunk.blockalign = 2 * get_c_channels();
	header.format_chunk.cbits_sample = 16;
	header.data_chunk_header.id = wav_data_id;
	header.data_chunk_header.size = cs_remaining << 1;
	audio.write((char*)&header, sizeof(t_wav_header));

	audio.close();*/


	return error;
}

int Cvqa_file::extract_as_pcx(const string& name)
{
	int error = 0;
	Cvqa_decode vqa_d;
	vqa_d.start_decode(header());
	int cx = get_cx();
	int cy = get_cy();
	if (get_cbits_pixel() == 8)
	{
		t_palet palet;
		byte* frame = new byte[cx * cy];
		for (int i = 0; i < get_c_frames(); i++)
		{
			while (!is_video_chunk())
				skip_chunk();

			byte* data = new byte[get_chunk_size()];
			read_chunk(data);
			vqa_d.decode_vqfr_chunk(data, frame, palet);
			delete[] data;
		}
		delete[] frame;
	}
	else
	{
		DDPIXELFORMAT_VQA pf;
		pf.dwRGBAlphaBitMask = 0;
		pf.dwRBitMask = 0x0000ff;
		pf.dwGBitMask = 0x00ff00;
		pf.dwBBitMask = 0xff0000;
		vqa_d.set_pf(pf, 3);
		byte* frame = new byte[3 * cx * cy];

		for (int i = 0; i < get_c_frames(); i++)
		{
			if (get_chunk_id() == vqa_vqfl_id)
			{
				byte* data = new byte[get_chunk_size()];
				read_chunk(data);
				vqa_d.decode_vqfl_chunk(data, get_chunk_size());
			}
			while (!is_video_chunk())
				skip_chunk();
			byte* data = new byte[get_chunk_size()];
			read_chunk(data);
			vqa_d.decode_vqfr_chunk(data, frame, NULL);

			string filename = name + "_" + to_string(i) + ".bmp";
			bitmap_image bmp(cx, cy);
			byte* red = new byte[cx*cy];
			byte* green = new byte[cx*cy];
			byte* blue = new byte[cx*cy];
			for (int j = 0; j < cx * cy; j++)
			{
				red[j] = frame[j * 3];
				green[j] = frame[j * 3 + 1];
				blue[j] = frame[j * 3 + 2];
			}
			bmp.import_rgb(red, green, blue);
			bmp.save_image(filename);
			delete[] red;
			delete[] green;
			delete[] blue;
			// Raw frame in here (frame)


			delete[] data;
		}
		delete[] frame;
	}
	return error;
}

int Cvqa_file::extract_as_wav(const string& name)
{
	int error = 0;
	typedef vector<t_list_entry> t_list;
	t_list list;
	int cs_remaining = 0;	
	Cvqa_decode vqa_d;
	vqa_d.start_decode(header());
	for (int i = 0; i < get_c_frames(); i++)
	{
		while (1)
		{
			if (is_audio_chunk())
			{
				t_list_entry e;
				int size = get_chunk_size();
				if (get_chunk_id() >> 24 == '0')
				{
					e.c_samples = size >> 1;
					e.audio = new short[size / 2];
					read_chunk(e.audio);
					size /= 4;
				}
				else
				{
					e.c_samples = size << 1;
					e.audio = new short[2 * size];
					byte* data = new byte[size];
					read_chunk(data);
					vqa_d.decode_snd2_chunk(data, size, e.audio);
				}
				cs_remaining += e.c_samples;
				list.push_back(e);				
			}
			else if (is_video_chunk())
				break;				
			else
				skip_chunk();
		}
		skip_chunk();
	}

	// We've got RAW PCM here in list - one chunk per list item.

	ofstream file;
	file.open(name, ios::binary | ios::trunc);
	t_wav_header header;
	memset(&header, 0, sizeof(t_wav_header));
	header.file_header.id = wav_file_id;
	header.file_header.size = sizeof(header) - sizeof(header.file_header) + cs_remaining;
	header.form_type = wav_form_id;
	header.format_chunk.header.id = wav_format_id;
	header.format_chunk.header.size = sizeof(header.format_chunk) - sizeof(header.format_chunk.header);
	header.format_chunk.formattag = 1;
	header.format_chunk.c_channels = get_c_channels();
	header.format_chunk.samplerate = get_samplerate();
	header.format_chunk.byterate = 2 * get_c_channels() * get_samplerate();
	header.format_chunk.blockalign = 2 * get_c_channels();
	header.format_chunk.cbits_sample = 16;
	header.data_chunk_header.id = wav_data_id;
	header.data_chunk_header.size = cs_remaining << 1;
	file.write((char*)&header, sizeof(t_wav_header));
	for (auto& i : list)
	{
		file.write((char*)i.audio, 2 * i.c_samples);
		delete[] i.audio;
	}
	file.close();


	/*Cfile32 f;
	error = f.open(name, GENERIC_WRITE);
	if (!error)
	{
		t_wav_header header;
		memset(&header, 0, sizeof(t_wav_header));
		header.file_header.id = wav_file_id;
		header.file_header.size = sizeof(header) - sizeof(header.file_header) + cs_remaining;
		header.form_type = wav_form_id;
		header.format_chunk.header.id = wav_format_id;
		header.format_chunk.header.size = sizeof(header.format_chunk) - sizeof(header.format_chunk.header);
		header.format_chunk.formattag = 1;
		header.format_chunk.c_channels = get_c_channels();
		header.format_chunk.samplerate = get_samplerate();
		header.format_chunk.byterate = 2 * get_c_channels() * get_samplerate();
		header.format_chunk.blockalign = 2 * get_c_channels();
		header.format_chunk.cbits_sample = 16;
		header.data_chunk_header.id = wav_data_id;
		header.data_chunk_header.size = cs_remaining << 1;
		error = f.write(&header, sizeof(t_wav_header));
		if (!error)
		{
			for (auto& i : list)
			{
				f.write(i.audio, 2 * i.c_samples);
				delete[] i.audio;
			}
		}
		f.close();
	}*/
	return error;
}

int Cvqa_file::read_chunk_header()
{
	if (get_p() & 1) // Get position (seek)
		skip(1); // Skip 1 byte
	int error = read(&m_chunk_header, sizeof(t_vqa_chunk_header));
	m_chunk_header.size = reverse(m_chunk_header.size);
	return error;
}

int Cvqa_file::read_chunk(void* data)
{
	int error = read(data, get_chunk_size());
	return error ? error : read_chunk_header();
}

/*Cvirtual_binary Cvqa_file::read_chunk()
{
	Cvirtual_binary d;
	return read_chunk(d.write_start(get_chunk_size())) ? Cvirtual_binary() : d;
}*/

void Cvqa_file::set_empty_chunk()
{
	m_chunk_header.size = 0;
}

int Cvqa_file::skip_chunk()
{
	skip(get_chunk_size()); // Skip seek
	return read_chunk_header();	
}