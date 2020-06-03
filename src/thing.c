#include "proto.h"

nox_memfile* nox_loaded_thing_bin = 0;

nox_memfile* nox_open_thing_bin(void) {
	nox_memfile* things = nox_loaded_thing_bin;
	if (!things) {
		things = nox_memfile_load("thing.bin", 7);
	}
	return things;
}

bool nox_ensure_thing_bin(void) {
	nox_loaded_thing_bin = nox_open_thing_bin();
	return nox_loaded_thing_bin != 0;
}

void nox_free_thing_bin(void) {
	if (nox_loaded_thing_bin) {
		nox_memfile_free(nox_loaded_thing_bin);
		nox_loaded_thing_bin = 0;
	}
}