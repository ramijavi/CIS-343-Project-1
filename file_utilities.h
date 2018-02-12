/*
 * This is the header file for our Game Of Life Project
 *
 * @authors - Andy Hing Hung & Javier Ramirez
 * @version - Winter 2018
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef file_utilities_h
#define file_utilities_h


/* This function will read data from a chosen file */
int read_file (char*, char***);

/* This function will save data onto a file */
int write_file(char*, char**, int,int,int,int);

/* This function returns the size of the file */
int getSize(char*);

/* This function allocates memory to hold the board array */
void allocateBoard(char***,int, int);

/* This function prints the board on the terminal */
void printBoard(char**, int, int);

/* This function frees the memory that holds the board */
void freeBoard(char***, int);

/* This function gets the height of the board */
int getHeight(char*);

/* This function gets the width of the board */
int getWidth(char*);

/* This function gets the generation of the board */
int getGen(char*);

/* This function populates the board */
void populateBoard(char***, char*, int, int);

/* This function copys the second param board to the first */
void copyBoard(char***, char**, int, int);

/* This function will run a generation */
void runGeneration(char***, char**, int, int);

#endif
