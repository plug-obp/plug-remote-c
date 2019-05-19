
MODEL=models/counters

all: metamodel.o model.o interpreter.o

metamodel.o: ss_metamodel.c
	gcc -c ss_metamodel.c -I${MODEL} -o ss_metamodel.o

model.o: ${MODEL}/ss_model.c
	gcc -c ${MODEL}/ss_model.c -I${MODEL} -I. -o ss_model.o

interpreter.o: ss_interpreter.c
	gcc -c ss_interpreter.c -I${MODEL} -o ss_interpreter.o

clean:
	rm -rf metamodel.o model.o interpreter.o