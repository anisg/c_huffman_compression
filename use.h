#ifndef USE_H
# define USE_H

typedef int bool;
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/mman.h>

//=======================================================
//==================== Sort =============================

void sort(void *arr, uint64_t n, uint64_t len, int (*comp)(void *a, void *b));

//=======================================================
//==================== MinQueue =========================

typedef struct s_minQueue {
	void *arr;
	int  n; //item count
	int  mn; //max n limit
	int  len; //item size
	int (*less)(void *a, void *b);
}              MinQueue;

//note: MinQueue with fixed length
MinQueue *minQueue(void *arr, uint64_t n, uint64_t len, int (*less)(void *a, void *b));
bool mqEmpty(MinQueue *mq);
void *mqExtractMin(MinQueue *mq);
bool mqInsert(MinQueue *mq, void *d);

//=======================================================
//==================== String ===========================

typedef struct	s_string {
	char     *s;
	uint64_t n;
}				String;

String string(char *s, uint64_t n);//pack (s,n) to String

//=======================================================
//==================== OTHER ============================

bool fget(const char *filename, char **ptr, size_t *l);
bool fput(const char *filename, char *ptr, size_t l);
char *with_ext(const char *filename, char *ext);
char *remove_ext(const char *filename, char *ext);

//=======================================================

#endif