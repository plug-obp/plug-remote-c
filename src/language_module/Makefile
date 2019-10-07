SHELL=/bin/bash

check_defined = \
    $(strip $(foreach 1,$1, \
        $(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
    $(if $(value $1),, \
      $(error Undefined $1$(if $2, ($2))))


$(call check_defined, BUILD_LOC, folder to put binary files)
$(call check_defined, CC, Compiler to use)
$(call check_defined, HARD_SPECIFIC_OPTIONS, Hardware-specific options to use)
$(call check_defined, BUILD_LOC, *.o files location)
$(call check_defined, BUILD_LIB_DIR, library location)

OPTIONS= $(COMMON_OPTIONS) $(HARD_SPECIFIC_OPTIONS)









gve_adapter.a : gve_adaptor.o 
	ar -r $(BUILD_LIB_DIR)/gve_adapter.a $(BUILD_LOC)/gve_adaptor.o

gve_adaptor.o: gve_adaptor.c
	$(CC) $(OPTIONS) -c gve_adaptor.c -o $(BUILD_LOC)/gve_adaptor.o