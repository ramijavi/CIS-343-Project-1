#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef file_utilities_h
#define file_utilities_h


// This function will read data from a chosen file
int read_file (char*, char**);

// This function will save data onto a file
int write_file(char*, char*, int);


#endif
