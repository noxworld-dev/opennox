#include "chaticon.h"
#include "../../proto.h"

extern int nox_win_width;
extern int nox_win_height;

//----- (00445650) --------------------------------------------------------
int sub_445650()
{
    unsigned short * v0; // eax

    *(unsigned int *)& byte_5D4594[825748] = sub_42F970( "ChatIcon");
    *(unsigned int *)& byte_5D4594[825744] = nox_window_new(
            0,
            136,
            nox_win_width - 50,
            nox_win_height / 2 - 50,
            50,
            50,
            0);
    sub_46AE60(*(int*)& byte_5D4594[825744], *(int*)& byte_5D4594[825748]);
    nox_window_set_all_funcs( *(unsigned int * *)& byte_5D4594[825744], 0, sub_4456E0, 0);
    v0 = loadString_sub_40F1D0((char*)& byte_587000[107980], 0, "C:\\NoxPost\\src\\client\\Gui\\chaticon.c", 73);
    sub_46B000((unsigned short *)(*(unsigned int *)& byte_5D4594[825744] + 36), v0);
    return 1;
}
