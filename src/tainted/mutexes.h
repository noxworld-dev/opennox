#ifndef NOX_MUTEXES_H
#define NOX_MUTEXES_H

typedef struct {
#ifndef NOX_CGO
	void* p;
#else
	unsigned int p;
#endif // NOX_CGO
} nox_mutex_t;

void nox_mutex_init(nox_mutex_t* m);
void nox_mutex_free(nox_mutex_t* m);
void nox_mutex_lock(nox_mutex_t* m);
void nox_mutex_unlock(nox_mutex_t* m);

#endif // NOX_MUTEXES_H
