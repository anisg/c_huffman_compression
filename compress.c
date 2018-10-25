#include "huffman.h"

//=======================================================
//=============== Compression Main ======================

int usage(char *progname){
	printf("Usage: %s filename\n", progname);
	return -1;
}

int main(int ac, char *av[]){
	if (ac != 2)
		return usage(av[0]);
	String in;
	if (!fget(av[1], &in.s, &in.n))
		return -2;
	String out = compress(in);
	if (out.s == NULL)
		return -3;
	char *f = with_ext(av[1], ".compressed");
	if (!fput(f, out.s, out.n))
		return -4;
	printf("Done! created \'%s\'\n", f);
	return 0;
}