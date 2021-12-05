//#include "stdafx.h"

#define XCC
#include "vqa_decode.h"

//#include "shp_decode.h"


void convert_palet_18_to_24(const t_palet s, t_palet d)
{
	for (int i = 0; i < 256; i++)
	{
		d[i].r = (s[i].r & 63) * 255 / 63;
		d[i].g = (s[i].g & 63) * 255 / 63;
		d[i].b = (s[i].b & 63) * 255 / 63;
	}
}


void convert_palet_18_to_24(t_palet palet)
{
	convert_palet_18_to_24(palet, palet);
}

unsigned int fvqa_format80decompress(const uint8_t image_in[], uint8_t image_out[], int mod)
{
    unsigned char* Source = (uint8_t*)image_in;
    unsigned char* Dest = image_out;
    unsigned int Sp = 0;
    unsigned int Dp = 0;
    unsigned char com;
    unsigned int Count;
    unsigned int Posit;

    do
    {
        com = Source[Sp];
        Sp++;
        unsigned char b7 = com >> 7;
        if (b7 == 0) //command 2
        {
            Count = ((com & 0x70) >> 4) + 3;
            Posit = ((com & 0x0f) << 8) + Source[Sp];
            Sp++;
            Posit = Dp - Posit;
            for (unsigned int i = Posit; i < (Posit + Count); i++)
            {
                //Dest = (unsigned char*)realloc(Dest, Dp + 1);
                Dest[Dp] = Dest[i];
                Dp++;
            }
        }
        else if (b7 == 1) //command 1
        {
            unsigned char b6 = (com & 0x40) >> 6;
            if (b6 == 0)
            {
                Count = com & 0x3f;
                if (Count == 0) break;
                for (unsigned int i = 0; i < Count; i++)
                {
                    //Dest = (unsigned char*)realloc(Dest, Dp + 1);
                    Dest[Dp] = Source[Sp];
                    Sp++;
                    Dp++;
                }
            }
            else if (b6 == 1)
            {
                Count = com & 0x3f;
                if (Count < 0x3e) //command 3
                {
                    Count += 3;
                    if (mod) //check version
                        Posit = Dp - (Source[Sp + 1] * 256 + Source[Sp]);
                    else
                        Posit = Source[Sp + 1] * 256 + Source[Sp];
                    Sp += 2;
                    for (unsigned int i = Posit; i < (Posit + Count); i++)
                    {
                        //Dest = (unsigned char*)realloc(Dest, Dp + 1);
                        Dest[Dp] = Dest[i];
                        Dp++;
                    }
                }
                else if (Count == 0x3f) //command 5
                {
                    Count = Source[Sp + 1] * 256 + Source[Sp];
                    if (mod) //check version
                        Posit = Dp - (Source[Sp + 3] * 256 + Source[Sp + 2]);
                    else
                        Posit = Source[Sp + 3] * 256 + Source[Sp + 2];
                    Sp += 4;
                    for (unsigned int i = Posit; i < (Posit + Count); i++)
                    {
                        //Dest = (unsigned char*)realloc(Dest, Dp + 1);
                        Dest[Dp] = Dest[i];
                        Dp++;
                    }
                }
                else //command 4
                {
                    Count = Source[Sp + 1] * 256 + Source[Sp];
                    Sp += 2;
                    unsigned char b = Source[Sp];
                    Sp++;
                    for (unsigned int i = 0; i < Count; i++)
                    {
                        //Dest = (unsigned char*)realloc(Dest, Dp + 1);
                        Dest[Dp] = b;
                        Dp++;
                    }
                }
            }
        }
    } while (/*Sp < len*/1);  //check for end of inputdata, because not all chunks contain the ending uint8_t
    return Dp;
}

int decode80(const uint8_t image_in[], uint8_t image_out[])
{
    return fvqa_format80decompress(image_in, image_out, 0);
}

int decode80r(const uint8_t image_in[], uint8_t image_out[])
{
    return fvqa_format80decompress(image_in, image_out, 1);
}


Cvqa_decode::Cvqa_decode()
{
	cbf = new int[0x1fff * 16];
	cbf_new = new int[0x1fff * 16];
	m_in_decoded = new uint8_t[256 << 10];
}

Cvqa_decode::~Cvqa_decode()
{
	delete[] m_in_decoded;
	delete[] cbf_new;
	delete[] cbf;
}

void Cvqa_decode::start_decode(const t_vqa_header& header)
{
	aud_dl.init();
	aud_dr.init();
	c_cbf_read = 0;
	cbf_write = reinterpret_cast<uint8_t*>(cbf_new);
	mc_channels = header.c_channels;
	m_cx = header.cx;
	m_cy = header.cy;
	mcx_block = header.cx_block;
	mcy_block = header.cy_block;
	mcb_d_pixel = 1;
	m_version = header.video_flags & 0x10 ? game_ts : game_td;
	frame_index = 0;
}

void Cvqa_decode::set_pf(const DDPIXELFORMAT_VQA& pf, int cb_pixel)
{
	m_pfc.set_pf(pf);
	mcb_d_pixel = cb_pixel;
}

void Cvqa_decode::decode_snd2_chunk(const uint8_t* in, int size, short* out)
{
	if (mc_channels == 1 || m_version != game_ts)
		aud_dl.decode_chunk(in, out, 2 * size);
	else
	{
		short* left = new short[size];
		short* right = new short[size];
		aud_dl.decode_chunk(in, left, size);
		aud_dr.decode_chunk(in + (size >> 1), right, size);
		const short* rl = left;
		const short* rr = right;
		short* w = out;
		for (int i = 0; i < size; i++)
		{
			*w++ = *rl++;
			*w++ = *rr++;
		}
		delete[] right;
		delete[] left;
	}
}

void Cvqa_decode::write_block(uint8_t* out, int v, int count, int& x, int y) const
{
	while (count--)
	{
		const uint8_t* r = reinterpret_cast<const uint8_t*>(cbf) + mcb_d_pixel * mcx_block * mcy_block * v;
		uint8_t* w = out + mcb_d_pixel * (mcx_block * x + m_cx * mcy_block * y);
		for (int b = 0; b < mcy_block; b++)
		{
			memcpy(w, r, mcb_d_pixel * mcx_block);
			r += mcb_d_pixel * mcx_block;
			w += mcb_d_pixel * m_cx;
		}
		x++;
	}
}

void Cvqa_decode::decode_vpt_chunk(const uint8_t* in, uint8_t* out)
{
	int cx_b = m_cx / mcx_block;
	int cy_b = m_cy / mcy_block;
	if (mcb_d_pixel > 1)
	{
		const uint8_t* r = in;
		for (int y = 0; y < cy_b; y++)
		{
			for (int x = 0; x < cx_b; )
			{
				int v = *r++;
				v |= *r++ << 8;
				int count = v & 0x1fff;
				int count2 = (count & 0x1f00) + 0x100 >> 7;
				switch (v >> 13)
				{
				case 0:
					x += count;
					break;
				case 1:
					write_block(out, count & 0xff, count2, x, y);
					break;
				case 2:
					write_block(out, count & 0xff, 1, x, y);
					while (count2--)
						write_block(out, *r++, 1, x, y);
					break;
				case 3:
					write_block(out, count, 1, x, y);
					break;
				case 5:
					write_block(out, count, *r++, x, y);
					break;
				}
			}
		}
	}
	else
	{
		const uint8_t* r1 = in;
		const uint8_t* r2 = in + cx_b * cy_b;
		int* w1 = reinterpret_cast<int*>(out);
		for (int y = 0; y < cy_b; y++)
		{
			int* w2 = w1;
			for (int x = 0; x < cx_b; x++)
			{
				int v = *r1++;
				int w = *r2++;
				int* w3 = w2;
				if (w < 0xf)
				{
					v = w << 8 | v;
					const int* r3 = cbf + mcy_block * v;
					for (int i = 0; i < mcy_block; i++)
					{
						*w3 = *r3++;
						w3 += cx_b;
					}
				}
				else
				{
					v = v << 24 | v << 16 | v << 8 | v;
					for (int i = 0; i < mcy_block; i++)
					{
						*w3 = v;
						w3 += cx_b;
					}
				}
				w2++;
			}
			w1 += cx_b * mcy_block;
		}
	}
}

void Cvqa_decode::decode_cbf_chunk(const uint8_t* s, int cb_s)
{
	const short* r = reinterpret_cast<const short*>(s);
	int count = cb_s >> 1;
	switch (mcb_d_pixel)
	{
	case 1:
		memcpy(cbf, s, cb_s);
		break;
	case 2:
		{
			short* w = reinterpret_cast<short*>(cbf);
			while (count--)
			{
				int v = *r++;
                if (m_pfc.is_native())
                {
                    *w++ = (short)v;
                }
                else
                {
                    *w++ = m_pfc.get_color((v >> 10 & 0x1f) * 255 / 31, (v >> 5 & 0x1f) * 255 / 31, (v & 0x1f) * 255 / 31);
                }
			}
			break;
		}
	case 3:
		{
			uint8_t* w = reinterpret_cast<uint8_t*>(cbf);
			while (count--)
			{
				int v = *r++;
				int u = m_pfc.get_color((v >> 10 & 0x1f) * 255 / 31, (v >> 5 & 0x1f) * 255 / 31, (v & 0x1f) * 255 / 31);
				*w++ = u & 0xff;
				*w++ = u >> 8 & 0xff;
				*w++ = u >> 16 & 0xff;
			}
			break;
		}
	case 4:
		{
			int* w = reinterpret_cast<int*>(cbf);
			while (count--)
			{
				int v = *r++;
				*w++ = m_pfc.get_color((v >> 10 & 0x1f) * 255 / 31, (v >> 5 & 0x1f) * 255 / 31, (v & 0x1f) * 255 / 31);
			}
			break;
		}
	}
}

void Cvqa_decode::decode_vqfl_chunk(const uint8_t* s, int cb_s)
{
	if (s[3] == 'Z')
	{
		int cb_in = s[8]
			? decode80(s + 8, m_in_decoded)
			: decode80r(s + 9, m_in_decoded);
		decode_cbf_chunk(m_in_decoded, cb_in);
	}
	else
		decode_cbf_chunk(s + 8, cb_s - 8);
}

void Cvqa_decode::decode_vqfr_chunk(const uint8_t* in_raw, uint8_t* out, t_palet palet)
{
	if (!in_raw)
		return;
	bool cbf_compressed = 0;
	const uint8_t* in = 0;
	uint8_t* in_decoded = m_in_decoded;
	while (1)
	{
		int id = *(int*)in_raw & vqa_t_mask;
		int size = reverse(*(int*)(in_raw + 4));
		bool compressed = in_raw[3] == 'Z';
		int cb_in = 0;
		if (id == vqa_cbp_id)
		{
			memcpy(cbf_write, in_raw + 8, size);
			cbf_compressed = compressed;
			c_cbf_read++;
			cbf_write += size;
		}
		else if (compressed)
		{
			if (in_raw[8])
				cb_in = decode80(in_raw + 8, in_decoded);
			else
				cb_in = decode80r(in_raw + 9, in_decoded);
			in = in_decoded;
		}
		else
		{
			in = in_raw + 8;
			cb_in = size;
		}
		if (id == vqa_cbf_id)
			decode_cbf_chunk(in, cb_in);
		else if (id == vqa_cpl_id)
		{
			memcpy(palet, in, cb_in);
			convert_palet_18_to_24(palet);
		}
		else if (id == vqa_vpr_id || id == vqa_vpt_id)
		{
			decode_vpt_chunk(in, out);
			break;
		}
		// read from even position
		in_raw += 8 + (size + 1 & ~1);
	}
	frame_index++;
	if (c_cbf_read & ~7)
	{
		if (cbf_compressed)
			decode80(reinterpret_cast<const uint8_t*>(cbf_new), reinterpret_cast<uint8_t*>(cbf));
		else
			memcpy(cbf, cbf_new, cbf_write - reinterpret_cast<const uint8_t*>(cbf_new));
		c_cbf_read = 0;
		cbf_write = reinterpret_cast<uint8_t*>(cbf_new);
	}
}
