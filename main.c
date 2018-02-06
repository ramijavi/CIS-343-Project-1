/**
 * CIS 343 - 02 Structures of Programming Languages
 * Project 1 - The Game of Life
 * 
 * @authors - Andy hing Hung & Javier Ramirez
 * 
 * The Game of Life was developed by John Conway (a British mathematician) in the 1970s. 
 * It is an example of a cellular automaton, a data structure that seems to evolve iteratively.
 * In this simulation we will use a set of rules to determine the survival or death of the cells.
 *
 * In this assignment we will focus our attention mostly on memory allocation & memory
 * management in general. 
 */

#include "file_utilities.h"


// Global variables declaration
// A double pointer holds a pointer to the board
// Two integrers hold the height and width
int **board;
int height, width;

// This function allocates memory to hold the 2D array
// that holds the board. It uses the function malloc
void allocateBoard(){

	int r = height, c = width, i, j;
 
   	board = (int **)malloc(r * sizeof(int *));
	for (i=0; i<r; i++){
        	board[i] = (int *)malloc(c * sizeof(int));
 	}
  
        for (i = 0; i <  r; i++){
        	for (j = 0; j < c; j++){
                	board[i][j] = 1;  // OR *(*(arr+i)+j) = ++count
                }
	}                             
}

// This function prints the board out
void printBoard(){

	int i, j;

	printf("\n");

	for (i = 0; i <  height; i++){
		
		printf("| ");
                
		for (j = 0; j < width; j++){
                        printf("%d", board[i][j]);
			printf(" | ");
        	}


		printf("\n");
        }
}


int main(int argc, char* argv[]){

	// Greet the player when the game is initialized
	printf("\nWelcome player. You are playing the game of life\n");
	
	// Check if the player entered correct input
	// Correct input should be two numbers 
	if(argc < 3 || argc > 3){
		// If input was not correct, the player is notified 
		// and the game is exited
		printf("\nUser did not specify height and width of game. Exiting...");
		return 0;
	}
	// If input is correct, then it's shown to the player
	printf("\nYou have chosen to play with a board of size : %s x %s \n", argv[1], argv[2]);
	
	height = atoi(argv[1]);
	width = atoi(argv[2]);
	
	allocateBoard();
 	
	printBoard();
/*
	char* height;
	height = malloc(strlen(argv[1]));
	height = strcat(height, argv[1]);
	printf("height is: %s \n", height);
	//printf("\n");
	char* width;
	width = malloc(strlen(argv[2]));
	width = strcat(width, argv[2]);
	printf("width is: %s \n", width);
	

	printf("Would you like to open an existing saved generation?\n");
	char openSave;
	char fileName[20];
	scanf("%c", &openSave);
	printf("\n");
	if(openSave == 'y'){
		printf("Enter the file name you wish to open. \n");
		scanf("%s", fileName);
		printf("The fileName is: %s \n", fileName);
		//fileName = malloc
	}
	else{
	
	}
	printf("openSave: %c \n",openSave);
	free(height);
	free(width);
*/
	return 0;
}

