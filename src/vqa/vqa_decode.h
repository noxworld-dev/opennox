#pragma once
#include "CommonHeader.h"

#include "vqa_file.h"

#include "aud_decode.h"
//#include "palet.h"
//#include "cc_structures.h"
#include "ddpf_conversion.h"
//#include <virtual_binary.h>

class Cvqa_decode
{
private:
	int* cbf;
	int* cbf_new;
	uint8_t* cbf_write;
	int frame_index;
	int c_cbf_read;
	int mc_channels;
	int m_cx;
	int m_cy;
	int mcx_block;
	int mcy_block;
	uint8_t* m_in_decoded;
	t_game m_version;
	aud_decode aud_dl;
	aud_decode aud_dr;
	Cddpf_conversion m_pfc;
	int mcb_d_pixel;
public:
	void start_decode(const t_vqa_header& header);
	void set_pf(const DDPIXELFORMAT_VQA& pf, int cb_pixel);
	void decode_cbf_chunk(const uint8_t* in_raw, int cb_s);
	void decode_snd2_chunk(const uint8_t* in, int size, short* out);
	void decode_vpt_chunk(const uint8_t* in, uint8_t* out);
	void decode_vqfl_chunk(const uint8_t* s, int cb_s);
	void decode_vqfr_chunk(const uint8_t* in, uint8_t* out, t_palet palet);
	void write_block(uint8_t* out, int v, int count, int& x, int y) const;
	Cvqa_decode();
	~Cvqa_decode();
};
