LIB_DIR=../../lib
EXE_DIR=../../exe

all: circular_buffer.o 

test: circular_buffer.o circular_buffer_test_main.o
	gcc ${LIB_DIR}/*.o ${EXE_DIR}/circular_buffer_test_main.o -o ${EXE_DIR}/circular_buffer_test.exe

circular_buffer_test_main.o: circular_buffer_test_main.c
	gcc -g -I.. -c circular_buffer_test_main.c -o ${EXE_DIR}/circular_buffer_test_main.o

circular_buffer.o: circular_buffer.c
	gcc -g -I.. -c circular_buffer.c -o ${LIB_DIR}/circular_buffer.o

clean:
	rm -rf ${LIB_DIR}/circular_buffer.o ${EXE_DIR}/circular_buffer_test_main.o ${EXE_DIR}/circular_buffer_test.exe