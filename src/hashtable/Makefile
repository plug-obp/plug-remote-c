

all : hashtable_test_main.o linear_scan.o murmur3.o buffer.o
	$(AR)  hashtable_test_main.o linear_scan.o murmur3.o buffer.o test_hashtable.elf

hashtable_test_main.o :
	$(CC) $(CC_OPTS) -I../hashable -I../hash -I../hash/murmur3 -I../buffer -c hashtable_test_main.c -o hashtable_test_main.o
linear_scan.o :
	$(CC) $(CC_OPTS) -I../hashable -I../hash -I../hash/murmur3 -I../buffer -c linear_scan.c -o linear_scan.o
murmur3.o :
	$(CC) $(CC_OPTS) -I../hashable -I../hash -I../hash/murmur3 -I../buffer -c ../hash/murmur3/murmur3.c -o murmur3.o
buffer.o :
	$(CC) $(CC_OPTS) -I../hashable -I../hash -I../hash/murmur3 -I../buffer -c ../buffer/buffer.c -o buffer.o -DMURMUR3



















