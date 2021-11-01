#include <stdio.h>

#include "server__script__internal.h"
#include "server__script__panic.h"
#include "server__script__script.h"

bool nox_script_panic_memhack_is_enabled = false;

void nox_script_push(int val);
int nox_script_pop();

bool nox_script_panic_memhack_check(int fnc) {
	// ===[ Panic's memhack detection ]===
	// it usually triggers on a2=973231
	// 0x587000 + 245900 + 3892924 -> 0x979748 -> 0x5D4594 + 3821996 + 8 -> nox_script_stack[2]

	unsigned int off = 0x587000 + 245900 + 4*fnc;
	int stack_off = off - (0x5D4594 + 3821996);

	if (stack_off < 0 || stack_off+4 > 4096 || stack_off%4 != 0) {
		return false; // disallow other type of hacks
	}
	int stack_ind = stack_off/4;
	// function address we need to jump to
	// basically points to the following uint32 on the stack
	if (nox_script_stack_at(stack_ind) != 0x97974c) {
		return false;
	}
	stack_ind++;

	unsigned char stack_exp[] = {
		0x56, // push   esi
		// -> 0x5D4594 + 1558936 + 356 (safe location in a string buffer?)
		0xbe, 0x90, 0x10, 0x75, 0x00,             // mov    esi,0x751090
		// inject two functions there, see in replaced functions
		0xc7, 0x06, 0x68, 0x50, 0x72, 0x50,       // mov    uint32_t PTR [esi],0x50725068
		0xc7, 0x46, 0x04, 0x00, 0x68, 0x30, 0x72, // mov    uint32_t PTR [esi+0x4],0x72306800
		0xc7, 0x46, 0x08, 0x50, 0x00, 0xff, 0x54, // mov    uint32_t PTR [esi+0x8],0x54ff0050
		0xc7, 0x46, 0x0c, 0x24, 0x04, 0xff, 0x30, // mov    uint32_t PTR [esi+0xc],0x30ff0424
		0xc7, 0x46, 0x10, 0xff, 0x54, 0x24, 0x04, // mov    uint32_t PTR [esi+0x10],0x42454ff
		0xc7, 0x46, 0x14, 0x83, 0xc4, 0x0c, 0x31, // mov    uint32_t PTR [esi+0x14],0x310cc483
		0xc7, 0x46, 0x18, 0xc0, 0xc3, 0x90, 0x90, // mov    uint32_t PTR [esi+0x18],0x9090c3c0
		0xc7, 0x46, 0x1c, 0x56, 0x68, 0x50, 0x72, // mov    uint32_t PTR [esi+0x1c],0x72506856
		0xc7, 0x46, 0x20, 0x50, 0x00, 0xff, 0x14, // mov    uint32_t PTR [esi+0x20],0x14ff0050
		0xc7, 0x46, 0x24, 0x24, 0x8b, 0xf0, 0xff, // mov    uint32_t PTR [esi+0x24],0xfff08b24
		0xc7, 0x46, 0x28, 0x14, 0x24, 0x89, 0x30, // mov    uint32_t PTR [esi+0x28],0x30892414
		0xc7, 0x46, 0x2c, 0x83, 0xc4, 0x04, 0x5e, // mov    uint32_t PTR [esi+0x2c],0x5e04c483
		0xc7, 0x46, 0x30, 0xc3, 0x90, 0x90, 0x90, // mov    uint32_t PTR [esi+0x30],0x909090c3
		// override opcode 185 from nox_script_builtin_516850 to new func 1
		0x89, 0x35, 0x70, 0x33, 0x5c, 0x00,       // mov    uint32_t PTR ds:0x5c3370,esi
		// override opcode 89 from nox_script_fn59_513F20 to new func 2
		0xc7, 0x5, 0xf0, 0x31, 0x5c, 0x00, 0xac,  // mov    uint32_t PTR ds:0x5c31f0,0x7510ac
		0x10, 0x75, 0x00,                         //
		0x5e,                                     // pop    esi
		0xc3,                                     // ret
		0x90, 0x90                                // nop x2
	};
	int hack_len = sizeof(stack_exp)/4;
	if (stack_ind + hack_len >= 1024) {
		return false; // we expect all items of the hack to fit
	}
	// check that the exploit code is exactly the one we expect
	unsigned int* stack_dword = stack_exp;
	for (int i = 0; i < hack_len; i++) {
		if (stack_dword[i] != nox_script_stack_at(stack_ind+i)) {
			return false;
		}
	}
	// TODO: must set it back when the map shutdowns
	nox_script_panic_memhack_is_enabled = true;
	printf("noxscript: enabled Panic's memhack API\n");
	return true;
}

int nox_script_panic_memhack_sub_751090() {
	// Panic's replacement for nox_script_builtin_516850 (opcode 185)
	//
	//  0x68, 0x50, 0x72, 0x50, 0x00, // push   0x507250 // nox_script_pop
	//  0x68, 0x30, 0x72, 0x50, 0x00, // push   0x507230 // nox_script_push
	//  0xff, 0x54, 0x24, 0x04,       // call   uint32_t PTR [esp+0x4] // eax = nox_script_pop()
	//  0xff, 0x30,                   // push   uint32_t PTR [eax]
	//  0xff, 0x54, 0x24, 0x04,       // call   uint32_t PTR [esp+0x4] // nox_script_push(*eax)
	//  0x83, 0xc4, 0x0c,             // add    esp,0xc
	//  0x31, 0xc0,                   // xor    eax,eax
	//  0xc3,                         // ret
	unsigned int addr = nox_script_pop();
	printf("noxscript: mem read [0x%x]\n", addr);
	unsigned int val = 0; // TODO: read via memmap
	nox_script_push(val);
	return 0;
}

int nox_script_panic_memhack_write_7510AC() {
	// Panic's replacement for nox_script_fn59_513F20 (opcode 89)
	//
	//  0x56,                         // push   esi
	//  0x68, 0x50, 0x72, 0x50, 0x00, // push   0x507250            // nox_script_pop
	//  0xff, 0x14, 0x24,             // call   uint32_t PTR [esp]     //
	//  0x8b, 0xf0,                   // mov    esi,eax             // esi = nox_script_pop()
	//  0xff, 0x14, 0x24,             // call   uint32_t PTR [esp]     // eax = nox_script_pop()
	//  0x89, 0x30,                   // mov    uint32_t PTR [eax],esi // *eax = esi
	//  0x83, 0xc4, 0x04,             // add    esp,0x4
	//  0x5e,                         // pop    esi
	//  0xc3,                         // ret
	unsigned int val = nox_script_pop();
	unsigned int addr = nox_script_pop();
	printf("noxscript: mem write [0x%x] = %d\n", addr, val);
	// TODO: write via memmap
	return 0;
}

bool nox_script_panic_memhack_call(int fi, int* ret) {
	if (!nox_script_panic_memhack_is_enabled)
		return false;
	if (fi == 185) {
		*ret = nox_script_panic_memhack_sub_751090();
		return true;
	} else if (fi == 89) {
		*ret = nox_script_panic_memhack_write_7510AC();
		return true;
	}
	return false;
}
