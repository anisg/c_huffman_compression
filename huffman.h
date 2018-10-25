#ifndef COMPRESS_H
# define COMPRESS_H

#include "use.h"

#define NOP 256

//=======================================================
//==================== Bit Array ========================

bool getbit(char *a, uint64_t p);
void setbit(char *a, uint64_t p);
void clearbit(char *a, uint64_t p);


//=======================================================
//==================== Other ============================

typedef struct s_node{
	uint32_t v; //value: between 0 and 255 and NOP
	uint32_t freq;
	struct s_node *l;
	struct s_node *r;
}              Node;

typedef struct s_encoded_node8{
	unsigned char v;
	uint8_t freq;
} __attribute__((packed)) EncodedNode8;

typedef struct s_encoded_node16{
	unsigned char v;
	uint16_t freq;
} __attribute__((packed)) EncodedNode16;

typedef struct s_encoded_node32{
	unsigned char v;
	uint32_t freq;
} __attribute__((packed)) EncodedNode32;

typedef EncodedNode32 EncodedNode;

typedef struct s_char_code{
	uint64_t rep;
	int n;
} CharCode;

String compress(String b);
String decompress(String b);

#endif