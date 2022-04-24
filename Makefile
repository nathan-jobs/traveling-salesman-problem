CFLAGS = -ansi -Wall -pedantic -Wfatal-errors
LDFLAGS = -lMLV -lm

CC = gcc

OBJ = main.o affichage.o Ville.o Visite.o Population.o test.o
	

pvc : $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) 

main.o : main.c affichage.h test.h
test.o : test.c test.h Visite.h Population.h Ville.h affichage.h
affichage.o : affichage.c affichage.h Population.h Ville.h
Population.o : Population.c Population.h Visite.h Ville.h
Visite.o : Visite.c Visite.h Ville.h
Ville.o : Ville.c Ville.h




%.o : %.c
	$(CC) -c $<  $(CFLAGS) 
	
clean : 
	rm -f *.o
	
mrproper : clean
	rm -f $@




