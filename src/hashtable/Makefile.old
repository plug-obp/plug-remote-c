LIB_DIR=../../lib
EXE_DIR=../../exe

all: linear_scan.o

test: linear_scan.o hashtable_test_main.o
	gcc -g ${LIB_DIR}/*.o ${EXE_DIR}/hashtable_test_main.o -o ${EXE_DIR}/hashtable_test.exe

hashtable_test_main.o: hashtable_test_main.c
	gcc -g ${CC_FLAGS} -I.. -c hashtable_test_main.c -o ${EXE_DIR}/hashtable_test_main.o

linear_scan.o: linear_scan.c
	gcc -g ${CC_FLAGS} -I.. -c linear_scan.c -o ${LIB_DIR}/linear_scan.o

clean:
	rm -rf ${LIB_DIR}/linear_scan.o ${LIB_DIR}/hashtable_test_main.o ${LIB_DIR}/hashtable_test_main.exe