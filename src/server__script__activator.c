#include "defs.h"
#include "server__script__internal.h"
#include "server__script__script.h"
#include "common__crypt.h"

extern unsigned int nox_frame_xxx_2598000;
extern nox_script_xxx_t* nox_script_arr_xxx_1599636;

typedef struct nox_script_activator_t nox_script_activator_t;
typedef struct nox_script_activator_t {
	unsigned int frame; // 0, 0
	unsigned int callback; // 1, 4
	unsigned int arg; // 2, 8
	int id; // 3, 12
	nox_object_t* trigger; // 4, 16
	nox_object_t* caller; // 5, 20
	nox_script_activator_t* next; // 6, 24
	nox_script_activator_t* prev; // 7, 28
} nox_script_activator_t;
_Static_assert(sizeof(nox_script_activator_t) == 32, "wrong size of nox_script_activator_t structure!");

nox_script_activator_t* nox_script_activatorsList_2487236 = 0;
nox_script_activator_t* nox_script_activatorsFreeList_2487240 = 0;
unsigned int nox_script_activatorsLastID = 1;

//----- (0051AD20) --------------------------------------------------------
int nox_script_activatorNextHandle_51AD20() {
	int id = ++nox_script_activatorsLastID;
	if (nox_script_activatorsLastID > 32000) {
		id = 1;
		nox_script_activatorsLastID = 1;
	}
	return id;
}

//----- (0051AC60) --------------------------------------------------------
void nox_script_activatorCancelAll_51AC60() {
	nox_script_activator_t* last = 0;
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it; it = it->next) {
		last = it;
	}
	if (last) {
		last->next = nox_script_activatorsFreeList_2487240;
		nox_script_activatorsFreeList_2487240 = nox_script_activatorsList_2487236;
		nox_script_activatorsList_2487236 = 0;
	}
}

//----- (0051AD40) --------------------------------------------------------
nox_script_activator_t* nox_xxx_scriptActivatorNew_51AD40() {
	nox_script_activator_t* act = nox_script_activatorsFreeList_2487240;
	if (act) {
		nox_script_activatorsFreeList_2487240 = nox_script_activatorsFreeList_2487240->next;
		return act;
	}
	return malloc(sizeof(nox_script_activator_t));
}

//----- (0051AD90) --------------------------------------------------------
nox_script_activator_t* nox_script_activatorDoneNext_51AD90(nox_script_activator_t* act) {
	nox_script_activator_t* next = act->next;
	if (next)
		next->prev = act->prev;

	nox_script_activator_t* v3 = act->prev;
	if (v3)
		v3->next = act->next;

	if (act == nox_script_activatorsList_2487236)
		nox_script_activatorsList_2487236 = act->next;

	nox_script_activator_t* out = act->next;

	act->next = nox_script_activatorsFreeList_2487240;
	nox_script_activatorsFreeList_2487240 = act;

	act->prev = 0;
	return out;
}

//----- (0051AD60) --------------------------------------------------------
bool nox_script_activatorCancel_51AD60(int id) {
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it; it = it->next) {
		if (it->id == id) {
			nox_script_activatorDoneNext_51AD90(it);
			return 1;
		}
	}
	return 0;
}

//----- (0051AE60) --------------------------------------------------------
void nox_script_activatorClearObj_51AE60(nox_object_t* obj) {
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it;) {
		if (it->trigger == obj) {
			it = nox_script_activatorDoneNext_51AD90(it);
		} else {
			if (it->caller == obj)
				it->caller = 0;
			it = it->next;
		}
	}
}

void nox_script_activator_append(nox_script_activator_t* act) {
	nox_script_activator_t* last = 0;
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it; it = it->next) {
		last = it;
	}
	if (last) {
		last->next = act;
		act->prev = last;
	} else {
		nox_script_activatorsList_2487236 = act;
		act->prev = 0;
	}
}

//----- (0051ACA0) --------------------------------------------------------
void nox_script_activatorTimer_51ACA0(int df, int callback, int arg) {
	nox_script_activator_t* act = nox_xxx_scriptActivatorNew_51AD40();
	if (!act) {
		nox_script_push(0);
		return;
	}
	act->frame = nox_frame_xxx_2598000 + df;
	act->callback = callback;
	act->arg = arg;
	int id = nox_script_activatorNextHandle_51AD20();
	act->id = id;
	act->trigger = 0;
	act->caller = 0;
	act->next = 0;
	nox_script_push(id);
	nox_script_activator_append(act);
}

//----- (0051AEA0) --------------------------------------------------------
int nox_script_activatorSave_51AEA0() {
	int v7 = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&v7, 2u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&nox_frame_xxx_2598000, 4u);

	int cnt = 0;
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it; it = it->next) {
		cnt++;
	}
	nox_xxx_fileReadWrite_426AC0_file3_fread(&cnt, 4u);
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it; it = it->next) {
		nox_xxx_fileReadWrite_426AC0_file3_fread(&it->frame, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&it->callback, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&it->arg, 4u);
		nox_object_t* obj = it->trigger;
		int oid = 0;
		if (obj)
			oid = obj->script_id;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&oid, 4u);
		obj = it->caller;
		oid = 0;
		if (obj)
			oid = obj->script_id;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&oid, 4u);
	}
	return 1;
}

//----- (0051AF80) --------------------------------------------------------
int nox_script_activatorLoad_51AF80() {
	int vers = 1;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&vers, 2u);
	if (vers > 1 || vers <= 0) {
		return 0;
	}
	int saveFrame = 0;
	unsigned int cnt = 0;
	nox_xxx_fileReadWrite_426AC0_file3_fread(&saveFrame, 4u);
	nox_xxx_fileReadWrite_426AC0_file3_fread(&cnt, 4u);
	for (int i = 0; i < cnt; i++) {
		int frame;
		int callback;
		int arg;
		int trigger;
		int caller;
		nox_xxx_fileReadWrite_426AC0_file3_fread(&frame, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&callback, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&arg, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&trigger, 4u);
		nox_xxx_fileReadWrite_426AC0_file3_fread(&caller, 4u);

		nox_script_activator_t* act = nox_xxx_scriptActivatorNew_51AD40();
		if (!act)
			return 0;
		act->frame = nox_frame_xxx_2598000 + (frame - saveFrame);
		act->callback = callback;
		act->arg = arg;
		act->id = nox_script_activatorNextHandle_51AD20();
		act->trigger = trigger;
		act->caller = caller;
		act->next = 0;
		nox_script_activator_append(act);
	}
	return 1;
}

//----- (0051ADF0) --------------------------------------------------------
void nox_script_activatorRun_51ADF0() {
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it;) {
		if (it->frame > nox_frame_xxx_2598000) {
			it = it->next;
		} else {
			int callback = it->callback;
			nox_object_t* caller = it->caller;
			nox_object_t* trigger = it->trigger;
			if (nox_script_arr_xxx_1599636[callback].size_28) {
				nox_script_push(it->arg);
			}
			it = nox_script_activatorDoneNext_51AD90(it);
			nox_script_callByIndex_507310(callback, caller, trigger);
		}
	}
}

//----- (0051B0C0) --------------------------------------------------------
void nox_script_activatorResolveObjs_51B0C0() {
	for (nox_script_activator_t* it = nox_script_activatorsList_2487236; it; it = it->next) {
		if (it->trigger)
			it->trigger = nox_server_scriptValToObjectPtr_511B60(it->trigger);
		if (it->caller)
			it->caller = nox_server_scriptValToObjectPtr_511B60(it->caller);
	};
}
