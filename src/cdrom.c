#include "cdrom.h"

#if 1
int sub_423CC0(int a1) { return 0; }

int sub_423C60() { return 0; }

unsigned char sub_423EC0() { return 0; }
#else
//----- (00423CC0) --------------------------------------------------------
int sub_423CC0(int a1) {
	int result; // eax

	if (*getMemU32Ptr(0x5D4594, 588112) && a1 == 1)
		result = *getMemU32Ptr(0x5D4594, 588096) == 530;
	else
		result = 0;
	return result;
}

//----- (00423BB0) --------------------------------------------------------
int sub_423BB0() {
	int result;            // eax
	uintptr_t dwParam2[5]; // [esp+0h] [ebp-14h]

	result = *getMemU32Ptr(0x5D4594, 588112);
	if (!*getMemU32Ptr(0x5D4594, 588112)) {
		dwParam2[0] = 0;
		dwParam2[4] = 0;
		dwParam2[2] = 516;
		dwParam2[3] = 0;
		dwParam2[1] = 0;
		if (mciSendCommandA(0, 0x803u, 0x3102u, (uintptr_t)dwParam2)) {
			result = *getMemU32Ptr(0x5D4594, 588112);
		} else {
			result = 1;
			*getMemU32Ptr(0x5D4594, 588108) = dwParam2[1];
			*getMemU32Ptr(0x5D4594, 588112) = 1;
		}
	}
	return result;
}

//----- (00423C20) --------------------------------------------------------
MCIERROR sub_423C20(void* this) {
	MCIERROR result;    // eax
	uintptr_t dwParam2; // [esp+0h] [ebp-4h]

	dwParam2 = (uintptr_t)this;
	result = *getMemU32Ptr(0x5D4594, 588112);
	if (*getMemU32Ptr(0x5D4594, 588112)) {
		dwParam2 = 0;
		result = mciSendCommandA(*(MCIDEVICEID*)getMemAt(0x5D4594, 588108), 0x804u, 2u, (uintptr_t)&dwParam2);
		*getMemU32Ptr(0x5D4594, 588112) = 0;
	}
	return result;
}

//----- (00423C60) --------------------------------------------------------
int sub_423C60() {
	if (!*getMemU32Ptr(0x5D4594, 588112))
		return 0;
	*getMemU32Ptr(0x5D4594, 588092) = nox_video_getWindow_401FD0();
	*getMemU32Ptr(0x5D4594, 588100) = 4;
	*getMemU32Ptr(0x5D4594, 588104) = 0;
	*getMemU32Ptr(0x5D4594, 588096) = 0;
	return mciSendCommandA(*(MCIDEVICEID*)getMemAt(0x5D4594, 588108), 0x814u, 0x101u,
						   (uintptr_t)getMemAt(0x5D4594, 588092)) == 0;
}

//----- (00423CF0) --------------------------------------------------------
int nox_xxx_noxCDinDriver_423CF0() {
	char* v0;                       // ebp
	int result;                     // eax
	uint32_t* v2;                   // ecx
	unsigned char* v3;              // edx
	int v4;                         // [esp+10h] [ebp-1A0h]
	int v5;                         // [esp+14h] [ebp-19Ch]
	int v6;                         // [esp+18h] [ebp-198h]
	uint8_t SectorsPerCluster[144]; // [esp+1Ch] [ebp-194h]
	char Buffer[260];               // [esp+ACh] [ebp-104h]

	getMemByte(0x5D4594, 588116) = 0;
	if (!GetLogicalDriveStringsA(0x104u, Buffer))
		return 0;
	v0 = Buffer;
	if (!strlen(Buffer))
		return 0;
	while (GetDriveTypeA(v0) != 5 || !sub_423ED0(v0, (uint32_t)SectorsPerCluster) ||
		   _strnicmp("NOX", (const char*)&SectorsPerCluster[4], 3u)) {
		v0 += strlen(v0) + 1;
		if (!strlen(v0))
			return 0;
	}
	v5 = 0;
	v6 = 0;
	v4 = 0;
	if (_strcmpi((const char*)&SectorsPerCluster[72], "CDFS") || *(uint32_t*)&SectorsPerCluster[136] > 0u) {
		return 0;
	}
	if (SetVolumeLabelA(v0, (const char*)getMemAt(0x587000, 64676))) {
		SetVolumeLabelA(v0, (const char*)&SectorsPerCluster[4]);
		return 0;
	}
	strcpy(Buffer, v0);
	*(uint16_t*)&Buffer[strlen(Buffer)] = *getMemU16Ptr(0x587000, 64684);
	sub_423F80(Buffer, (int)&v6, (int)&v5, (int)&v4);
	v2 = *(uint32_t**)getMemAt(0x587000, 64660);
	result = 2;
	if (*getMemU32Ptr(0x587000, 64660)) {
		v3 = getMemAt(0x587000, 64660);
		do {
			if ((unsigned int)v4 >= *v2 && (unsigned int)v6 >= v2[1] && (unsigned int)v5 >= v2[2])
				break;
			v2 = (uint32_t*)*((uint32_t*)v3 - 1);
			v3 -= 4;
			--result;
		} while (v2);
	}
	if (result == 1) {
		if (SectorsPerCluster[7] == 50)
			goto LABEL_23;
		return 0;
	}
	if (result != 2)
		return 0;
	if (SectorsPerCluster[7] != 49)
		return 0;
LABEL_23:
	*getMemU8Ptr(0x5D4594, 588116) = *v0;
	return result;
}
// 423CF0: using guessed type char Buffer[260];

//----- (00423EC0) --------------------------------------------------------
unsigned char sub_423EC0() { return getMemByte(0x5D4594, 588116); }

//----- (00423ED0) --------------------------------------------------------
int sub_423ED0(const char* lpRootPathName, uint32_t SectorsPerCluster) {
	uint32_t v2;                     // esi
	const char* v3;                  // edi
	int result;                      // eax
	uint32_t v5;                     // eax
	bool v6;                         // zf
	uint32_t NumberOfFreeClusters;   // [esp+8h] [ebp-10h]
	uint32_t TotalNumberOfClusters;  // [esp+Ch] [ebp-Ch]
	uint32_t FileSystemFlags;        // [esp+10h] [ebp-8h]
	uint32_t MaximumComponentLength; // [esp+14h] [ebp-4h]

	v2 = SectorsPerCluster;
	memset((void*)SectorsPerCluster, 0, 0x90u);
	v3 = lpRootPathName;
	*(uint32_t*)v2 = GetDriveTypeA(lpRootPathName);
	result = GetDiskFreeSpaceA(v3, &SectorsPerCluster, (uint32_t*)&lpRootPathName, &NumberOfFreeClusters,
							   &TotalNumberOfClusters);
	if (result) {
		v5 = (uint32_t)lpRootPathName * SectorsPerCluster;
		v6 = NumberOfFreeClusters == 0;
		*(uint32_t*)(v2 + 136) = NumberOfFreeClusters * (uint32_t)lpRootPathName * SectorsPerCluster;
		if (v6) {
			*(uint32_t*)(v2 + 140) = TotalNumberOfClusters * v5;
			result = GetVolumeInformationA(v3, (char*)(v2 + 4), 0x40u, (uint32_t*)(v2 + 68), &MaximumComponentLength,
										   &FileSystemFlags, (char*)(v2 + 72), 0x40u);
		} else {
			result = 0;
		}
	}
	return result;
}
#endif
