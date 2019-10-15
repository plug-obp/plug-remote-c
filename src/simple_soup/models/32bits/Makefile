
INCL_PATH ?=
ss_model.o :
	$(shell m4 32bits.m4 > ss_model.c)
	$(CC) $(CC_OPTIONS) $(INCL_PATH) -I$(SRC_ROOT) -I. -c ss_model.c -o $(PLUG_MODEL_BIN_DIR)/ss_model.o
