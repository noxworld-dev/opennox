#pragma once
#include "CommonHeader.h"

struct DDPIXELFORMAT_VQA
{
	unsigned long dwRGBAlphaBitMask;
	unsigned long dwRBitMask;
	unsigned long dwGBitMask;
	unsigned long dwBBitMask;
};

class Cddpf_conversion
{
public:
	int get_color(int a, int r, int g, int b);
	int get_color(int r, int g, int b);
	int get_color(int v);
	void set_pf(const DDPIXELFORMAT_VQA& pf);
private:
	int a_shift, r_shift, g_shift, b_shift;
	int a_size, r_size, g_size, b_size;
};