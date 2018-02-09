#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef file_utilities_h
#define file_utilities_h


// This function will read data from a chosen file
int read_file (char*, char***);

// This function will save data onto a file
int write_file(char*, char***, int);

// This function allocates the board to act like 
// a 2d array.
void allocateBoard(char***,int, int);

// This function prints the board on the terminal.
void printBoard(char**, int, int);

// This function allocates memory to hold the 2D array
// that holds the board. It uses the function malloc.
void freeBoard(char***, int);

// This function gets the height of the board.
int getHeight(char*);

// This function gets the width of the board.
int getWidth(char*);

// This function gets the generation of the board.
int getGen(char*);

// This function populates the board.
void populateBoard(char***, char*,int,int);


#endif
