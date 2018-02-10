program: main.o file_utilities.o
	gcc -o program main.o file_utilities.o

main.o: main.c file_utilities.h
	gcc -c main.c

file_utilities.o: file_utilities.c file_utilities.h
	gcc -c file_utilities.c

clean: 
	rm -f *.o program 
