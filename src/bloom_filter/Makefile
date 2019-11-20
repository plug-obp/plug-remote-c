
INCL += -I. 
INCL += -I../set 
INCL += -I../hashable
INCL += -I../buffer
# INCL += -I../hashtable
c += -I../hash

BIN +=  bloom_filter_test.o 
BIN += bloom_filter.o
BIN += set.o 
run : bf_test
	./bf_test
OPT = -Wall -g -std=c99

bf_test : clean bloom_filter_test.c bloom_filter.o set.o 
	gcc $(OPT) $(INCL) -c bloom_filter_test.c -o bloom_filter_test.o 
	gcc $(OPT) $(BIN) -o bf_test


bloom_filter.o : bloom_filter.c set.o 
	gcc $(OPT) $(INCL) -c bloom_filter.c -o bloom_filter.o 

set.o : ../set/set.c
	gcc $(OPT) $(INCL) -c ../set/set.c -o set.o 


clean : 
	rm -f ./*.o
	rm bf_test