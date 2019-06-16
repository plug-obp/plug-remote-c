LIB_DIR=../../lib
EXE_DIR=../../exe

all: gve_main_bare.o driver_software.o
	gcc -g ${EXE_DIR}/gve_main_bare.o ${LIB_DIR}/driver_software.o ${LIB_DIR}/buffer.o ${LIB_DIR}/fasthash.o ${LIB_DIR}/circular_buffer.o ${LIB_DIR}/gve_adaptor.o ${LIB_DIR}/linear_scan.o ../simple_soup/Default/ss_language_module.o ../simple_soup/Default/ss_interpreter.o ../simple_soup/Default/ss_metamodel.o ../simple_soup/Default/ss_model.o -o gve_main

gve_main_bare.o: gve_main_bare.c
	gcc -g  -I.. -c gve_main_bare.c -o ${EXE_DIR}/gve_main_bare.o

driver_software.o: driver_software.c
	gcc -g  -I.. -c driver_software.c -o ${LIB_DIR}/driver_software.o