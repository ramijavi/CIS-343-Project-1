#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef file_utilities_h
#define file_utilities_h


// This function will read data from a chosen file
int read_file (char*, char***);

// This function will save data onto a file
int write_file(char*, char*, int);

//
void allocateBoard(char***,int, int);

//
void printBoard(char**, int, int);

//
void freeBoard(char***, int);

//
int getHeight(char*);

//
int getWidth(char*);

//
int getGen(char*);

//
void populateBoard(char***, char*,int,int);
#endif
