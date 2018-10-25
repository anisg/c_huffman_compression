#include "use.h"

//=======================================================
//==================== Sort =============================

void swap(void *a, void *b, uint64_t len){
	void *tmp = malloc(len);

	memcpy(tmp, a, len);
	memcpy(a, b, len);
	memcpy(b, tmp, len);
	free(tmp);
}

void sort(void *arr, uint64_t n, uint64_t len, int (*comp)(void *a, void *b)){
	//n^2 quick impl
	for (int i = 1; i < n; i++){
		void *a = arr + ((i-1)*len);
		void *b = arr + (i*len);
		if (comp(a, b)){
			swap(a, b, len);
			i = 0;
		}
	}
}

//=======================================================
//==================== MinQueue =========================

MinQueue *minQueue(void *arr, uint64_t n, uint64_t len, int (*less)(void *a, void *b)){
	MinQueue *mq = malloc(sizeof(*mq));

	mq->arr = malloc(len * n);
	memcpy(mq->arr, arr, len*n);
	mq->n = n;
	mq->mn = n;
	mq->len = len;
	mq->less = less;
	//insert in the mq
	for (int i = 0; i < n; i++){
		mqInsert(mq, arr + (i*len));
	}
	return mq;
}

bool mqEmpty(MinQueue *mq){
	return (mq->n == 0);
}

void *mqExtractMin(MinQueue *mq){
	if (mqEmpty(mq))
		return NULL;
	void *tmp = malloc(mq->len);
	memcpy(tmp, mq->arr + 0, mq->len);
	mq->n -= 1;
	if (mq->n == 0)
		return tmp;
	memcpy(mq->arr + 0, mq->arr + (mq->n * mq->len), mq->len);
	int len = mq->len;
	int i = 0;
	while (TRUE){
		int mini = i;
		int l = 2*i+1;
		int r = 2*i+2;
		if (l < mq->n && !mq->less(mq->arr + (mini * len), mq->arr + (l * len)))
			mini = l;
		if (r < mq->n && !mq->less(mq->arr + (mini * len), mq->arr + (r * len)))
			mini = r;
		if (mini != i){
			swap(mq->arr + (i * len), mq->arr + (mini * len), len);
			i = mini;
		}
		else
			break;
	}
	return tmp;
}

bool mqInsert(MinQueue *mq, void *d){
	//O(log2(n))
	if (mq->n == mq->mn)
		return FALSE;
	int len = mq->len;
	int i = mq->n;

	memcpy(mq->arr + (mq->n * len), d, len); //add at the end
	mq->n += 1;
	//order
	while (i != 0){
		void *parent = mq->arr + (((i-1)/2) * len);
		void *node = mq->arr + (i * len);
		if (mq->less(node, parent)){
			swap(node, parent, len);
			i = ((i-1)/2);
		}
		else
			break;

	}
	return TRUE;
}


//=======================================================
//==================== String ===========================

String string(char *s, uint64_t n){
	return (String){s,n};
}

//=======================================================
//==================== OTHER ============================

bool fget(const char *filename, char **ptr, size_t *l){
	int       fd;
	struct stat buf;

	if (stat(filename, &buf) < 0)
		return FALSE;
	if (!S_ISREG(buf.st_mode))
		return FALSE;
	if ((fd = open(filename, 0, buf.st_mode)) < 0)
		return FALSE;
	(*ptr) = mmap(NULL, buf.st_size, 3, 2, fd, 0);
	(*l) = buf.st_size;
	close(fd);
	return TRUE;
}

bool fput(const char *filename, char *ptr, size_t l)
{
	int fd;
	mode_t m = 0755;	
	struct stat buf;
	if (!(stat(filename, &buf) < 0)){
		//file exist
		if (!S_ISREG(buf.st_mode)) return FALSE;
		m = buf.st_mode;
	}
	if ((fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, m)) < 0)
		return FALSE;
	write(fd, ptr, l);
	close(fd);
	return TRUE;
}

char *with_ext(const char *filename, char *ext){
	char *x =  malloc(strlen(filename) + strlen(ext) + 1);
	memcpy(x, filename, strlen(filename));
	memcpy(x + strlen(filename), ext, strlen(ext)+1);
	return x;
}

char *remove_ext(const char *filename, char *ext){
	char *p = strrchr(filename, '.'); //seek last '.'
	if (p == NULL || strcmp(p, ext) != 0)
		return strdup(filename);
	p[0] = '\0';
	char *x = malloc(strlen(filename)+1);
	memcpy(x, filename, strlen(filename)+1);
	p[0] = '.';
	return x;
}