package nox

/*
#include "GAME4.h"
#include "GAME4_3.h"
*/
import "C"
import "unsafe"

var noxObjectParseTable = []struct {
	Name string
	Func unsafe.Pointer
}{

	{"CARRYCAPACITY", C.nox_xxx_parseCapacity_535B80},
	{"CLASS", C.nox_xxx_parseClass_535B00},
	{"SUBCLASS", C.nox_xxx_parseSubclass_535B30},
	{"EXTENT", C.nox_xxx_parseExtent_535990},
	{"FLAGS", C.nox_xxx_parseFlags_535AD0},
	{"HEALTH", C.nox_xxx_parseHealth_535A60},
	{"LIGHTINTENSITY", C.nox_xxx_parseLightIntensity_535C20},
	{"MASS", C.nox_xxx_parseMass_535B60},
	{"MENUICON", C.nox_xxx_parseMenuIcon_535C30},
	{"PRETTYIMAGE", C.nox_xxx_parsePrettyImage_0_535C80},
	{"SPEED", C.nox_xxx_parseSpeed_535A20},
	{"WEIGHT", C.nox_xxx_parseWeight_535BB0},
	{"MATERIAL", C.nox_xxx_parseMaterial_535BE0},
	{"EXPERIENCE", C.nox_xxx_parseXP_535970},
	{"COLLIDE", C.nox_xxx_parseCollide_536EC0},
	{"DAMAGE", C.nox_xxx_parseDamageFn_536C60},
	{"DAMAGESOUND", C.nox_xxx_parseDamageSound_536CF0},
	{"DIE", C.nox_xxx_parseDieProc_536B80},
	{"DROP", C.nox_xxx_parseDrop_536A20},
	{"INIT", C.nox_xxx_parseInitProc_536930},
	{"CREATE", C.nox_xxx_parseCreateProc_536830},
	{"PICKUP", C.nox_xxx_parsePickup_536710},
	{"UPDATE", C.nox_xxx_parseUpdate_536620},
	{"USE", C.nox_xxx_parseUseFn_5363F0},
	{"XFER", C.nox_xxx_parseXFer_5360A0},
	{"DRAW", C.nox_xxx_parseDraw_535CD0},
	{"ZSIZE", C.nox_xxx_parseZSize_5359B0},
	{"WORTH", C.nox_xxx_parseWorth_535A00},
}
