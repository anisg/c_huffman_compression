# c_huffman_compression
small C project for understanding huffman code


## usage:

```shell
 make && make clean
```
it will create 2 binaries (`compress` and `decompress`)

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
├── compress.c       #main of compress program
├── decompress.c     #main of decompress program
├── huffman.c        #contains compress and decompress algorithms
├── huffman.h
├── use.c            #utility functions and datastructure (MinQueue)
└── use.h
```
