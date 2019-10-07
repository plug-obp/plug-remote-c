SHELL=/bin/bash

check_defined = \
    $(strip $(foreach 1,$1, \
        $(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
    $(if $(value $1),, \
      $(error Undefined $1$(if $2, ($2))))


$(call check_defined, GVE_ADAPTER_BIN_DIR, folder to put binary files)
$(call check_defined, GVE_ADAPTER_LIB_DIR, library location)
$(call check_defined, CC, Compiler to use)
$(call check_defined, CC_OPTIONS, compilation options)


all : $(GVE_ADAPTER_LIB_DIR)/libgve_adaptor.a $(GVE_ADAPTER_BIN_DIR)/gve_adaptor.o 

$(GVE_ADAPTER_LIB_DIR)/libgve_adaptor.a : $(GVE_ADAPTER_BIN_DIR)/gve_adaptor.o 
	ar -r $(GVE_ADAPTER_LIB_DIR)/libgve_adaptor.a $(GVE_ADAPTER_BIN_DIR)/gve_adaptor.o

$(GVE_ADAPTER_BIN_DIR)/gve_adaptor.o : gve_adaptor.c
	$(CC) $(CC_OPTIONS) -c gve_adaptor.c -o $(GVE_ADAPTER_BIN_DIR)/gve_adaptor.o
	
	
	
clean : 	
	rm $(GVE_ADAPTER_BIN_DIR)/*
	rm $(GVE_ADAPTER_LIB_DIR)/*
	