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

#define MAX_AUDIO_BUFFERS 1000

int Cvqa_file::extract_both()
{
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

    ALenum format = AL_FORMAT_MONO16;
    if (get_c_channels() == 2)
    {
        format = AL_FORMAT_STEREO16;
    }

    ALuint frequency = get_samplerate();

    ALuint buffers[MAX_AUDIO_BUFFERS];
    ALuint busyBuffers[MAX_AUDIO_BUFFERS];
    memset(&buffers, 0, sizeof(buffers));
    memset(&busyBuffers, 0, sizeof(busyBuffers));
    // Request a buffer name
    alGenBuffers(MAX_AUDIO_BUFFERS, buffers);


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

	int currentFrame = 0;
	int soundBytesOnFrame = 0;

	dword startTime = SDL_GetTicks();

	int delayT = 0;
	int changesTOTAL = 0;
	bool defaultTOTALset = false;
	int defaultTOTAL = 0;
	while (currentFrame < get_c_frames())
	{
		int previousFrame = currentFrame;

		if (get_chunk_id() == vqa_vqfl_id)
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
			//audio.write((char*)e.audio, 2 * e.c_samples);

            ALuint currentBuffer = 0;
            ALuint dataSize = 2 * e.c_samples;

            while (currentBuffer == 0)
            {
                ALint buffersProcessed = 0;
                alGetSourcei(source, AL_BUFFERS_PROCESSED, &buffersProcessed);
                if (buffersProcessed > 0)
                {
                    ALuint uiBuffer;
                    alSourceUnqueueBuffers(source, 1, &uiBuffer);
                    for (int i = 0; i < MAX_AUDIO_BUFFERS; i++)
                    {
                        if (uiBuffer == busyBuffers[i])
                        {
                            busyBuffers[i] = 0;
                            break;
                        }
                    }
                    for (int i = 0; i < MAX_AUDIO_BUFFERS; i++)
                    {
                        if (0 == buffers[i])
                        {
                            buffers[i] = uiBuffer;
                            break;
                        }
                    }
                }

                for (int i = 0; i < MAX_AUDIO_BUFFERS; i++)
                {
                    if (0 != buffers[i])
                    {
                        currentBuffer = buffers[i];
                        buffers[i] = 0;
                        break;
                    }
                }
                for (int i = 0; i < MAX_AUDIO_BUFFERS; i++)
                {
                    if (0 == busyBuffers[i])
                    {
                        busyBuffers[i] = currentBuffer;
                        break;
                    }
                }
            }

            alBufferData(currentBuffer, format, e.audio, dataSize, frequency);
            alSourceQueueBuffers(source, 1, &currentBuffer);

            soundBytesOnFrame = soundBytesOnFrame + (2 * e.c_samples);

            ALint position = 0;
            ALint playingBuffer = 0;
            ALint playingBufferSize = 0;
            alGetSourcei(source, AL_BYTE_OFFSET, &position);
            alGetSourcei(source, AL_BUFFER, &playingBuffer);
            if (playingBuffer != 0)
                alGetBufferi(playingBuffer, AL_SIZE, &playingBufferSize);

            int queuedDataSize = 0;

            for (int i = 0; i < MAX_AUDIO_BUFFERS; i++)
            {
                if (0 != busyBuffers[i] && playingBuffer != busyBuffers[i])
                {
                    ALint bufferSize = 0;
                    alGetBufferi(busyBuffers[i], AL_SIZE, &bufferSize);
                    queuedDataSize += bufferSize;
                }
            }

            int newDelay = playingBufferSize - position + queuedDataSize;
            int change = newDelay - delayT;
            delayT = delayT + change;
            if (isPlaying)
            {
                if (!defaultTOTALset)
                {
                    defaultTOTAL = changesTOTAL;
                    defaultTOTALset = true;
                }
                else
                {
                    changesTOTAL = changesTOTAL + change;
                }
            }
            assert(delayT = newDelay);

		}
		else
		{
			skip_chunk();
		}

		bool abort = false;

		// We need to wait for the next frame and process other data
		while (previousFrame < currentFrame)
		{
			int command = 0;
			if (decodeCallback != NULL)
			{
				command = decodeCallback(frame, cx, cy);
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
			dword currentTime = SDL_GetTicks();
			// We adjust frame rate based on sound stream
			int adjust = 0;
			if (defaultTOTALset)
			{
				adjust = changesTOTAL - defaultTOTAL;
				if (adjust < -soundBytesOnFrame)
				{
					adjust = -soundBytesOnFrame;
				}
				if (adjust > soundBytesOnFrame)
				{
					adjust = soundBytesOnFrame;
				}
			}
            dword frameRate = (1000 * (soundBytesOnFrame + adjust)) / (2 * get_c_channels() * get_samplerate());
			if (currentTime - startTime >= frameRate)
			{
                ALenum state;
                alGetSourcei(source, AL_SOURCE_STATE, &state);
				if (!isPlaying || state != AL_PLAYING)
				{
                    alSourcePlay(source);
					isPlaying = true;
				}
				soundBytesOnFrame = 0;
				startTime = SDL_GetTicks();
				break;
			}
			dword toSleep = dword(frameRate) - (currentTime - startTime);
			if (toSleep > 0)
			{
#ifdef __EMSCRIPTEN__
                emscripten_sleep(toSleep);
#else
                SDL_Delay(toSleep);
#endif
			}
		}

		if (abort)
		{
			break;
		}
	}
	delete[] frame;
	if (isPlaying)
	{
        alSourceStop(source);
	}

    ALint buffersProcessed = 0;
    ALuint buffersProc[MAX_AUDIO_BUFFERS];
    memset(buffersProc, 0, sizeof(buffersProc));
    alGetSourcei(source, AL_BUFFERS_PROCESSED, &buffersProcessed);
    alSourceUnqueueBuffers(source, buffersProcessed, buffersProc);

    for (int i = 0; i < MAX_AUDIO_BUFFERS; i++)
    {
        if (0 != busyBuffers[i])
        {
            for (int j = 0; j < MAX_AUDIO_BUFFERS; j++)
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

    alDeleteBuffers(MAX_AUDIO_BUFFERS, buffers);
    alDeleteSources(1, &source);
    alcMakeContextCurrent(previousContext);
    if (device != NULL)
    {
        alcDestroyContext(alContext);
        extAlContext = NULL;
        alcCloseDevice(device);
        device = NULL;
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