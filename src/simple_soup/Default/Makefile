
target ?= -
ifeq (arm,$(target))
	CROSS_COMPILER=arm-none-eabi
	OPTIONS=-mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostartfiles -g -Wall -Wextra -shared
	EXT=elf
else
  	CROSS_COMPILER= 
	OPTIONS=
	EXT=o
endif



SRC_ROOTFS=..
#MODEL=$(SRC_ROOTFS)/models/one_counter
#MODEL=$(SRC_ROOTFS)/models/one_counter_static
MODEL=$(SRC_ROOTFS)/models/two_counters
COMPILER=gcc




ifeq (arm,$(target))
all: metamodel.$(EXT) model.$(EXT) interpreter.$(EXT) 


else
all: simple_main.$(EXT) metamodel.$(EXT) model.$(EXT) interpreter.$(EXT) 
	$(CROSS_COMPILER)-$(COMPILER) $(OPTIONS) -g *.$(EXT) -o simple_main
endif


ss_language_module.$(EXT): $(SRC_ROOTFS)/ss_language_module.c
	$(CROSS_COMPILER)-$(COMPILER) $(OPTIONS) -g -c $(SRC_ROOTFS)/ss_language_module.c -I../$(SRC_ROOTFS)/language_module -I${MODEL} -o ss_language_module.$(EXT)

run: clean all
	./simple_main

simple_main.$(EXT): $(SRC_ROOTFS)/simple_main.c
	$(CROSS_COMPILER)-$(COMPILER) $(OPTIONS) -g -c $(SRC_ROOTFS)/simple_main.c -I${MODEL} -o simple_main.$(EXT)

metamodel.$(EXT): $(SRC_ROOTFS)/ss_metamodel.c
	$(CROSS_COMPILER)-$(COMPILER) $(OPTIONS) -g -c $(SRC_ROOTFS)/ss_metamodel.c -I${MODEL} -o ss_metamodel.$(EXT) 

model.$(EXT): ${MODEL}/ss_model.c
	$(CROSS_COMPILER)-$(COMPILER) $(OPTIONS) -g -c ${MODEL}/ss_model.c -I${MODEL} -I$(SRC_ROOTFS) -o ss_model.$(EXT)

interpreter.$(EXT): $(SRC_ROOTFS)/ss_interpreter.c
	$(CROSS_COMPILER)-$(COMPILER) $(OPTIONS) -g -c $(SRC_ROOTFS)/ss_interpreter.c -I${MODEL} -o ss_interpreter.$(EXT)

clean:
	rm -rf *.$(EXT)
	rm -rf simple_main



clean-all: 
	rm -rf *.o 
	rm -rf *.elf
	rm -rf simple_main