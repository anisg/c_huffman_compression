CC=gcc
CFLAGS=-Wall -g
LDFLAGS=

all: compress decompress

compress: compress.o huffman.o use.o
	$(CC) -o $@ $^ $(LDFLAGS)

decompress: decompress.o huffman.o use.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean: ; rm -f *.o
fclean: clean ; rm -f compress decompress *.compressed *.decompressed
re: clean fclean all

.PHONY: all clean fclean re
