//+build none


void  sub_47DA70(_DWORD* a1, LPDIDEVICEOBJECTDATA a2);

LPDIRECTINPUTA g_dinput_keyboard;
LPDIRECTINPUTDEVICEA g_device_keyboard;

LPDIRECTINPUTA g_dinput_mouse;
LPDIRECTINPUTDEVICEA g_device_mouse;

//----- (0047D8B0) --------------------------------------------------------
int unacquireMouse_sub_47D8B0() { return g_device_mouse->lpVtbl->Unacquire(g_device_mouse); }

//----- (0047D8C0) --------------------------------------------------------
int acquireMouse_sub_47D8C0() { return g_device_mouse->lpVtbl->Acquire(g_device_mouse); }

//----- (0047D8D0) --------------------------------------------------------
signed int nox_xxx_initMouse_47D8D0() {
	wchar_t* v0;    // eax
	DIPROPDWORD v4; // [esp+20h] [ebp-2Ch]
	DIDEVCAPS_DX3 v9;

	if (DirectInputCreateA(*(HINSTANCE*)getMemAt(0x5D4594, 823784), 0x300u, &g_dinput_mouse, 0) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_CreateFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 73);
		sub_4516C0(v0);
	}
	if (g_dinput_mouse->lpVtbl->CreateDevice(g_dinput_mouse, &GUID_SysMouse, &g_device_mouse, 0) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_CreateDeviceFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 87);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetCooperativeLevel(g_device_mouse, nox_video_getWindow_401FD0(),
													DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_SetCoopFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 105);
		sub_4516C0(v0);
	}
	v4.diph.dwSize = 20;
	v4.diph.dwHeaderSize = 16;
	v4.diph.dwObj = 0;
	v4.diph.dwHow = 0;
	v4.dwData = 256;
	if (g_device_mouse->lpVtbl->SetProperty(g_device_mouse, DIPROP_BUFFERSIZE, (LPCDIPROPHEADER)&v4) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_SetPropertyFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 123);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->SetDataFormat(g_device_mouse, &c_dfDIMouse) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_SetFormatFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 135);
		sub_4516C0(v0);
	}
	if (g_device_mouse->lpVtbl->Acquire(g_device_mouse) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:IM_AquireFailed", 0,
								   (int)"C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 147);
		sub_4516C0(v0);
	}
	v9.dwSize = 24;
	if (g_device_mouse->lpVtbl->GetCapabilities(g_device_mouse, (LPDIDEVCAPS)&v9) >= 0)
		*getMemU8Ptr(0x5D4594, 1193128) = v9.dwButtons;
	*getMemU32Ptr(0x5D4594, 1193108) = 1;
	sub_42EBB0(2, sub_47D890, 0, "DXInput");
	sub_42EBB0(1, nox_xxx_showWindow_47D8A0, 0, "DXInput");
	return 1;
}
// 47D890: using guessed type int sub_47D890();

//----- (0047DA70) --------------------------------------------------------
void  sub_47DA70(_DWORD* a1, LPDIDEVICEOBJECTDATA a2) {
	switch (a2->dwOfs) {
	case DIMOFS_X:
		*a1 = a2->dwData;
		break;
	case DIMOFS_Y:
		a1[1] = a2->dwData;
		break;
	case DIMOFS_Z:
		OnLibraryNotice_265(&a1, 2, a2);
		a1[2] = a2->dwData;
		break;
	case DIMOFS_BUTTON0:
		a1[5] = (a2->dwData >> 7) & 1;
		a1[7] = a2->dwSequence;
		break;
	case DIMOFS_BUTTON1:
		a1[8] = (a2->dwData >> 7) & 1;
		a1[10] = a2->dwSequence;
		break;
	case DIMOFS_BUTTON2:
		a1[11] = (a2->dwData >> 7) & 1;
		a1[13] = a2->dwSequence;
		break;
	default:
		return;
	}
}

//----- (0047DB20) --------------------------------------------------------
char  sub_47DB20(signed int* a1) {
	HRESULT v2;            // eax
	HRESULT v4;            // eax
	DIDEVICEOBJECTDATA v5; // [esp+14h] [ebp-10h]
	DWORD dw;

	a1[0] = 0;
	a1[1] = 0;
	a1[2] = 0;
	a1[5] = 0;
	a1[7] = 0;
	a1[8] = 0;
	a1[10] = 0;
	a1[11] = 0;
	a1[13] = 0;

	if (g_device_mouse) {
		dw = 1;
		v2 = g_device_mouse->lpVtbl->GetDeviceData(g_device_mouse, 16, &v5, &dw, 0);
		if (v2 == DIERR_NOTACQUIRED || v2 == DIERR_INPUTLOST) {
			v4 = g_device_mouse->lpVtbl->Acquire(g_device_mouse);
			if (v4 >= 0 && v4 <= 1)
				return -1;
		} else if (!v2 && dw) {
			sub_47DA70(a1, &v5);
			return 1;
		}
	}
	return 0;
}

//----- (0047D660) --------------------------------------------------------
UINT  nox_xxx_initJoystick_47D660(UINT uJoyID, int a2) {
	UINT result;              // eax
	UINT v3;                  // esi
	wchar_t* v4;              // eax
	__int64 v5;               // rax
	__int64 v6;               // [esp+10h] [ebp-3Ch]
	struct joyinfoex_tag pji; // [esp+18h] [ebp-34h]

	result = joyGetNumDevs();
	if (result) {
		pji.dwSize = 52;
		pji.dwFlags = 255;
		if (joyGetPosEx(uJoyID, &pji)) {
			result = 0;
		} else {
			v3 = 48 * uJoyID;
			*getMemU32Ptr(0x5D4594, v3 + 1189612) = 200;
			*getMemU32Ptr(0x5D4594, v3 + 1189620) = 0;
			*getMemU32Ptr(0x5D4594, v3 + 1189604) = -100;
			*getMemU32Ptr(0x5D4594, v3 + 1189628) = 0;
			*getMemU32Ptr(0x5D4594, v3 + 1189616) = 200;
			*getMemU32Ptr(0x5D4594, v3 + 1189624) = 0;
			*getMemU32Ptr(0x5D4594, v3 + 1189608) = -100;
			*getMemU32Ptr(0x5D4594, v3 + 1189632) = 0;
			if (joyGetDevCapsA(uJoyID, (LPJOYCAPSA)getMemAt(0x5D4594, 404 * uJoyID + 1189700), 0x194u)) {
				v4 = nox_strman_loadString_40F1D0("ReadCapsFailed", 0,
										   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Jstick.c", 79);
				sub_4517A0(v4, uJoyID);
				result = 0;
			} else {
				v6 = *getMemUintPtr(0x5D4594, 404 * uJoyID + 1189748);
				*getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189636) =
					(__int64)(200.0 / (double)*getMemUintPtr(0x5D4594, 404 * uJoyID + 1189740) * 1000000.0);
				v5 = (__int64)(200.0 / (double)v6 * 1000000.0);
				HIDWORD(v5) = *getMemU32Ptr(0x5D4594, 404 * uJoyID + 1189760);
				*getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189640) = v5;
				*(_DWORD*)a2 = HIDWORD(v5);
				result = 2;
			}
		}
	}
	return result;
}

//----- (0047D7A0) --------------------------------------------------------
DWORD*  sub_47D7A0(DWORD* a1, UINT uJoyID) {
	DWORD* result;            // eax
	DWORD v3;                 // ebx
	DWORD v4;                 // edi
	struct joyinfoex_tag pji; // [esp+8h] [ebp-34h]

	pji.dwSize = 52;
	pji.dwFlags = 131;
	if (joyGetPosEx(uJoyID, &pji) == 167) {
		result = a1;
		a1[2] = 0;
		*a1 = 0;
		a1[1] = 0;
	} else {
		a1[2] = pji.dwButtons;
		*a1 = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189636) *
			  (pji.dwXpos - *getMemU32Ptr(0x5D4594, 404 * uJoyID + 1189736)) / 0xF4240;
		v3 = *a1;
		a1[1] = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189640) *
				(pji.dwYpos - *getMemU32Ptr(0x5D4594, 404 * uJoyID + 1189744)) / 0xF4240;
		v4 = a1[1];
		*a1 = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189604) + v3;
		a1[1] = *getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189608) + v4;
		if (*getMemU32Ptr(0x5D4594, 48 * uJoyID + 1189620))
			*a1 = -*a1;
		result = *(DWORD**)getMemAt(0x5D4594, 48 * uJoyID + 1189624);
		if (result)
			a1[1] = -a1[1];
	}
	return result;
}

//----- (0047FB10) --------------------------------------------------------
void nox_xxx_initKeyboard_47FB10() {
	wchar_t* v0;     // eax
	wchar_t* v1;     // eax
	wchar_t* v2;     // eax
	int v3;          // edi
	HWND v4;         // eax
	wchar_t* v5;     // eax
	wchar_t* v6;     // eax
	wchar_t* v7;     // eax
	DIPROPDWORD v15; // [esp+24h] [ebp-14h]

	if (DirectInputCreateA(*(HINSTANCE*)getMemAt(0x5D4594, 823784), 0x300u, &g_dinput_keyboard, 0) < 0) {
		v0 = nox_strman_loadString_40F1D0("Dxinput.c:OK_CreateFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   827);
		sub_4516C0(v0);
	}

	if (g_dinput_keyboard->lpVtbl->CreateDevice(g_dinput_keyboard, &GUID_SysKeyboard, &g_device_keyboard, NULL) < 0) {
		v1 = nox_strman_loadString_40F1D0("Dxinput.c:OK_CreateDeviceFailed", 0,
								   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 841);
		sub_4516C0(v1);
	}

	if (g_device_keyboard->lpVtbl->SetDataFormat(g_device_keyboard, &c_dfDIKeyboard) < 0) {
		v2 = nox_strman_loadString_40F1D0("Dxinput.c:OK_SetFormatFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   853);
		sub_4516C0(v2);
	}

	if (g_device_keyboard->lpVtbl->SetCooperativeLevel(g_device_keyboard, nox_video_getWindow_401FD0(),
													   DISCL_BACKGROUND | DISCL_NONEXCLUSIVE) < 0) {
		v5 = nox_strman_loadString_40F1D0("Dxinput.c:OK_SetCoopFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   868);
		sub_4516C0(v5);
	}

	v15.diph.dwSize = 20;
	v15.diph.dwHeaderSize = 16;
	v15.diph.dwObj = 0;
	v15.diph.dwHow = 0;
	v15.dwData = 256;
	if (g_device_keyboard->lpVtbl->SetProperty(g_device_keyboard, DIPROP_BUFFERSIZE, &v15) < 0) {
		v6 = nox_strman_loadString_40F1D0("Dxinput.c:OK_SetPropertyFailed", 0,
								   "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c", 886);
		sub_4516C0(v6);
	}

	if (g_device_keyboard->lpVtbl->Acquire(g_device_keyboard) < 0) {
		v7 = nox_strman_loadString_40F1D0("Dxinput.c:OK_AquireFailed", 0, "C:\\NoxPost\\src\\Client\\Io\\Win95\\Dxinput.c",
								   899);
		sub_4516C0(v7);
	}

	dword_5d4594_1193132 = GetKeyState(20) & 1;
	dword_5d4594_1193132 = dword_5d4594_1193132;
	nox_xxx_keyboard_47DBD0();
}

// ORIGINAL
//----- (0047F950) --------------------------------------------------------
/*unsigned __int16  nox_input_scanCodeToAlpha_47F950(unsigned __int16 a1)
{
  unsigned __int16 result; // ax
  int scrollLockStatus;

  scrollLockStatus = GetKeyState(145);
  if ( a1 > 0xFFu )
	return a1;
  if ( a1 == 42 || a1 == 54 )
  {
	*(_DWORD *)getMemAt(0x5D4594, 1193136) = nox_input_keyboardGetKeyState_430970(a1) == 2;
	return 0;
  }
  if ( a1 != 58 )
  {
	if ( (_BYTE)a1 == getMemByte(0x5D4594, 1193144) )
	{
	  *(_DWORD *)getMemAt(0x5D4594, 1193140) = nox_input_keyboardGetKeyState_430970(a1) == 2;
	  result = 0;
	}
	else if ( *(_DWORD *)getMemAt(0x5D4594, 1193140) )
	{
	  result = *(_WORD *)getMemAt(0x5D4594, 1191572 + 6*(unsigned __int8)a1 + 4);
	}
	else if ( *(_DWORD *)getMemAt(0x5D4594, 1193136)
	   || *(_DWORD *)&dword_5d4594_1193132
	   && iswalpha(*(_WORD *)getMemAt(0x5D4594, 1191572 + 6*(unsigned __int8)a1)) )
	{

	if (scrollLockStatus)
	{
		result = asc_9800B0[3 * (unsigned __int8)a1 + 0x108];
	}
	else
	{
	  result = *(_WORD *)getMemAt(0x5D4594, 1191572 + 6*(unsigned __int8)a1 + 2);
	}
	}
	else
	{
	if (scrollLockStatus)
	{
		result = asc_9800B0[3 * (unsigned __int8)a1];
	}
	else
	{
		result = *(_WORD *)getMemAt(0x5D4594, 1191572 + 6*(unsigned __int8)a1);
	}
	}
	return result;
  }
  if ( sub_430950(a1) )
	return 0;
  if ( nox_input_keyboardGetKeyState_430970(a1) == 2 )
	*(_DWORD *)&dword_5d4594_1193132 = 1 - *(_DWORD *)&dword_5d4594_1193132;
  sub_4309B0(a1, 1);
  return 0;
}*/

//----- (0047FCC0) --------------------------------------------------------
int nox_xxx_freeKeyboard_47FCC0() {
	g_device_keyboard->lpVtbl->Unacquire(g_device_keyboard);
	return g_dinput_keyboard->lpVtbl->Release(g_dinput_keyboard);
}

//----- (0047FA80) --------------------------------------------------------
void nox_xxx_getKeyFromKeyboardImpl_47FA80(nox_keyboard_btn_t* ev) {
	HRESULT v2;            // eax
	char v3;               // al
	char v4;               // dl
	HRESULT v5;            // eax
	DIDEVICEOBJECTDATA v6; // [esp+14h] [ebp-10h]
	DWORD dw;

	ev->code = 0;
	ev->seq = 0;
	if (g_device_keyboard) {
		dw = 1;
		v2 = g_device_keyboard->lpVtbl->GetDeviceData(g_device_keyboard, 16, &v6, &dw, 0);
		if (v2 == DIERR_INPUTLOST) {
			v5 = g_device_keyboard->lpVtbl->Acquire(g_device_keyboard);
			if (v5 >= 0 && v5 <= 1)
				ev->code = -1;
		} else if (!v2 && dw) {
			ev->code = v6.dwOfs; // key code
			ev->state = (v6.dwData & 0x80 != 0) + 1;
			ev->port = 0;
			ev->data_3_size = 0;
			ev->seq = v6.dwSequence;
		}
	}
}

int sub_47D890() { return unacquireMouse_sub_47D8B0(); }

//----- (004453A0) --------------------------------------------------------
int nox_input_pollEvents_4453A0() {
	struct tagMSG Msg; // [esp+4h] [ebp-1Ch]

	while (PeekMessageA(&Msg, 0, 0, 0, 0)) {
		if (!GetMessageA(&Msg, 0, 0, 0))
			break;
		TranslateMessage(&Msg);
		DispatchMessageA(&Msg);
	}
	if (!*getMemU32Ptr(0x5D4594, 823800))
		return 0;
	PostMessageA(*(HWND*)getMemAt(0x5D4594, 823796), WM_CLOSE, 0, 0);
	return 1;
}
