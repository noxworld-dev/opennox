#pragma once

// To avoid excessive includes in runtime. That's dirty, but who cares.

#include "CommonHeader.h"

#include <fstream>
#include <iostream>
#include <string>

#pragma pack(push, 1)

const int wav_file_id = *(int*)"RIFF";
const int wav_form_id = *(int*)"WAVE";
const int wav_format_id = *(int*)"fmt ";
const int wav_fact_id = *(int*)"fact";
const int wav_data_id = *(int*)"data";

struct t_wav_chunk_header
{
	int id;
	int size;
};

struct t_wav_format_chunk
{
	t_wav_chunk_header header;
	short formattag;
	short c_channels;
	int samplerate;
	int byterate;
	short blockalign;
	short cbits_sample;
};

struct t_wav_header
{
	t_wav_chunk_header file_header;
	int form_type;
	t_wav_format_chunk format_chunk;
	t_wav_chunk_header data_chunk_header;
};

struct t_palet_entry
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

struct t_palet24rgb_entry
{
	uint8_t r, g, b;
};

struct t_palet24bgr_entry
{
	uint8_t b, g, r;
};

union t_palet32entry
{
	struct
	{
		uint8_t r, g, b, a;
	};
	unsigned int v;
};

union t_palet32bgr_entry
{
	struct
	{
		uint8_t b, g, r, a;
	};
	unsigned int v;
};

typedef t_palet_entry t_palet[256];

enum t_game
{
	game_ts,
	game_td,
};

struct t_vqa_chunk_header
{
	int id;
	int size;
};

struct t_vqa_header
{
	t_vqa_chunk_header file_header;
	// 'FORM'
	long long id;
	// 'WVQAVQHD'
	int startpos;
	short version;
	short video_flags;
	short c_frames;
	short cx;
	short cy;
	char cx_block;
	char cy_block;
	short fps;
	short c_colors;
	short cb_max_cbp_chunk;
	int unknown4;
	short unknown5;
	unsigned short samplerate;
	char c_channels;
	char cbits_sample;
	char unknown6[14];
};



const int vqa_c_mask = 0xff000000;
const int vqa_t_mask = 0x00ffffff;
const int vqa_file_id = *(int*)"FORM";
const long long vqa_form_id = { *(long long*)"WVQAVQHD" };
const int vqa_cbf_id = *(int*)"CBF\0";
const int vqa_cbp_id = *(int*)"CBP\0";
const int vqa_cpl_id = *(int*)"CPL\0";
const int vqa_finf_id = *(int*)"FINF";
const int vqa_sn2j_id = *(int*)"SN2J";
const int vqa_snd_id = *(int*)"SND\0";
const int vqa_vpt_id = *(int*)"VPT\0";
const int vqa_vpr_id = *(int*)"VPR\0";
const int vqa_vqfl_id = *(int*)"VQFL";
const int vqa_vqfr_id = *(int*)"VQFR";

#pragma pack(pop)

inline int reverse(int v)
{
    int v2 = v;
    uint8_t* vp = (uint8_t*)& v;
    uint8_t* v2p = (uint8_t*)& v2;
    vp[0] = v2p[3];
    vp[1] = v2p[2];
    vp[2] = v2p[1];
    vp[3] = v2p[0];
	return v;
}

// To avoid excessive includes in runtime. That's dirty, but who cares.
#ifdef XCC
#include "bitmap_image.hpp"
#include "vqa_decode.h"
#endif


#if 0
#include <Windows.h>
#include <InitGuid.h>
#include <Guiddef.h>
#include <dsound.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif

class Cvqa_file
{
public:
	Cvqa_file(string filename);
	~Cvqa_file();
	int post_open();
	int extract_as_pcx(const string& name);
	int extract_as_wav(const string& name);
	int extract_both();
	int read_chunk_header();
	int read_chunk(void* data);
	void set_empty_chunk();
	int skip_chunk();
	bool is_valid();

	void register_decode(int(*cb)(uint8_t* frame, dword cx, dword cy))
	{
		decodeCallback = cb;
	}

	void register_openal(ALCcontext* al_context)
	{
		extAlContext = al_context;
	}

	size_t get_size()
	{
		return fileSize;
	}

	size_t get_p()
	{
		return currentPosition;
	}

	void skip(size_t amount)
	{
		size_t finalpos = currentPosition + amount;

		fileStream.seekg(finalpos);
		currentPosition = fileStream.tellg();
	}

	int read(void* out, size_t size)
	{
		fileStream.read((char*)out, size);
		currentPosition = (int)currentPosition + size;
		if ((size_t)fileStream.tellg() != currentPosition)
		{
			return 1;
		}
		return 0;
	}

	int get_c_channels() const
	{
		return m_header.c_channels;
	}

	int get_c_frames() const
	{
		return m_header.c_frames;
	}

	int get_chunk_id() const
	{
		return m_chunk_header.id;
	}

	int get_chunk_size() const
	{
		return m_chunk_header.size;
	}

	int get_cx() const
	{
		return m_header.cx;
	}

	int get_cy() const
	{
		return m_header.cy;
	}

	int get_cx_block() const
	{
		return m_header.cx_block;
	}

	int get_cy_block() const
	{
		return m_header.cy_block;
	}

	const t_vqa_header& header() const
	{
		return m_header;
	}

	int get_samplerate() const
	{
		return m_header.samplerate;
	}

	bool is_audio_chunk() const
	{
		return (get_chunk_id() & vqa_t_mask) == vqa_snd_id;
	}

	bool is_video_chunk() const
	{
		return (get_chunk_id()) == vqa_vqfr_id;
	}

	int get_cbits_pixel() const
	{
		return m_header.video_flags & 0x10 ? 16 : 8;
	}

	int get_cbits_sample() const
	{
		return m_header.cbits_sample;
	}
private:
	t_vqa_chunk_header m_chunk_header;
	t_vqa_header m_header;
	ifstream fileStream;
	size_t fileSize;
	size_t currentPosition;
	ALCcontext* extAlContext;
	int(*decodeCallback)(uint8_t* frame, dword cx, dword cy);
};
