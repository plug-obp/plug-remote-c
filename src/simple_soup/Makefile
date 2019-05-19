
#MODEL=models/one_counter
MODEL=models/one_counter_static

all: simple_main.o metamodel.o model.o interpreter.o 
	gcc -g *.o -o simple_main

run: clean all
	./simple_main

simple_main.o: simple_main.c
	gcc -g -c simple_main.c -I${MODEL} -o simple_main.o

metamodel.o: ss_metamodel.c
	gcc -g -c ss_metamodel.c -I${MODEL} -o ss_metamodel.o

model.o: ${MODEL}/ss_model.c
	gcc -g -c ${MODEL}/ss_model.c -I${MODEL} -I. -o ss_model.o

interpreter.o: ss_interpreter.c
	gcc -g -c ss_interpreter.c -I${MODEL} -o ss_interpreter.o

clean:
	rm -rf *.o
	rm -rf simple_main