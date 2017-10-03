#EP2 - MAC0422 Sistemas Operacionais
#Guilherme Feulo do Espirito Santo       6431749
#Sergio Rosendo                          xxxxxxx */


CFLAGS = -Wall -O2 -std=gnu11
cc= gcc

ep2: error.o cyclist.o ep2.o
	$(cc) -o $@ $^ -pthread 
ep2.o: ep2.c error.h cyclist.h 
	$(cc) $(CFLAGS) -c ep2.c 
error.o: error.h error.c
	$(cc) $(CFLAGS) -c error.c
cyclist.o: cyclist.h cyclist.c
	$(cc) $(CFLAGS) -c cyclist.c
.PHONY clean:
clean:
	$(RM) *.o


