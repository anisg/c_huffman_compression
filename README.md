# c_huffman_compression
small C project for understanding huffman code


## install:

```shell
 make && make clean
```
it will create 2 binaries (`compress` and `decompress`)

## usage:

```shell
 ./compress filename               #will create filename.compressed
 
 ./decompress filename.compressed  #will create filename.decompressed
```

note: after executing the 2 binaries, filename.decompressed will be equal to filename


## code

```
.
├── Makefile
├── README.md
├── main_cmpr.c      #main of compress program
├── main_dcmpr.c     #main of decompress program
├── huffman.c        #contains compress and decompress algorithms
├── huffman.h
├── use.c            #utility functions and datastructure (MinQueue)
└── use.h
```
