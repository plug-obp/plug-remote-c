SHELL=/bin/bash

check_defined = \
    $(strip $(foreach 1,$1, \
        $(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
    $(if $(value $1),, \
      $(error Undefined $1$(if $2, ($2))))



$(call check_defined, CC, Compiler to use)
$(call check_defined, AR, Archiver to use)
$(call check_defined, CC_OPTIONS, Compilation options to use)
$(call check_defined, MODEL_PATH, ss_model to use)
$(call check_defined, PLUG_MODEL_BIN_DIR, *.o files location)
$(call check_defined, PLUG_MODEL_LIB_DIR, library location)
$(call check_defined, LANGUAGE_MODULE_LOC, location of the language_module.h file )


#COMMON_OPTIONS= -Wall -g -O0

#OPTIONS = $(COMMON_OPTIONS) $(HARD_SPECIFIC_OPTIONS)
export CC_OPTIONS

SRC_ROOT = $(shell pwd)
export SRC_ROOT 

all : ss_interpreter.o ss_model.o ss_metamodel.o ss_language_module.o
	$(AR) -r $(PLUG_MODEL_LIB_DIR)/libplug_model.a $(PLUG_MODEL_BIN_DIR)/*.o 
ss_interpreter.o : 
	$(CC) $(CC_OPTIONS) -I$(MODEL_PATH) -c ss_interpreter.c -o $(PLUG_MODEL_BIN_DIR)/ss_interpreter.o
	
	
ss_model.o : 
	pushd .; cd $(MODEL_PATH) ; $(MAKE) ; popd   
	
	
ss_metamodel.o : 
	$(CC) $(CC_OPTIONS) -I$(MODEL_PATH) -c ss_metamodel.c -o $(PLUG_MODEL_BIN_DIR)/ss_metamodel.o
	
ss_language_module.o : 
	$(CC) $(CC_OPTIONS) -I$(LANGUAGE_MODULE_LOC) -I$(MODEL_PATH) -c ss_language_module.c -o $(PLUG_MODEL_BIN_DIR)/ss_language_module.o
	
	
clean : 
	rm $(PLUG_MODEL_LIB_DIR)/*.a
	rm $(PLUG_MODEL_BIN_DIR)/*.o
	