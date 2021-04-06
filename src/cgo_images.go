package main

/*
#include "defs.h"
*/
import "C"
import (
	"log"
	"unsafe"

	"nox/common/bag"
)

var noxImages struct {
	bySect map[[2]int]unsafe.Pointer
}

func init() {
	noxImages.bySect = make(map[[2]int]unsafe.Pointer)
}

func internImagePCX(img *bag.Image) unsafe.Pointer {
	data := bag.EncodePCX(img)
	return C.CBytes(data)
}

//export nox_video_getImagePixdata_new
func nox_video_getImagePixdata_new(img *C.nox_video_bag_image_t) unsafe.Pointer {
	if img == nil {
		return nil
	}
	switch img.typ {
	default:
		return nil
	case 3, 4, 5, 6:
	}
	sect := int(img.sect_ind)
	offs := int(img.offset)

	key := [2]int{sect, offs}
	if ptr, ok := noxImages.bySect[key]; ok {
		return ptr
	}

	im, err := imageByBagSection(sect, offs)
	if err != nil {
		log.Println(err)
		return nil
	} else if im == nil {
		noxImages.bySect[key] = nil
		return nil
	}
	ptr := internImagePCX(im)
	noxImages.bySect[key] = ptr
	return ptr
}
