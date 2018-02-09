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
	char **board;
	char **tempBoard;
	int height, width, generation;
	height = atoi(argv[1]);
	width = atoi(argv[2]);
	
	allocateBoard(&board,height,width);
 	allocateBoard(&tempBoard,height,width);
	printBoard(board,height,width);
	
	printf("Would you like to open an existing saved generation?\n");
	char openSave;
	char fileName[20];
	scanf("%c", &openSave);
	printf("\n");
	if(openSave == 'y'){
		printf("Enter the file name you wish to open. \n");
		scanf("%s", fileName);
		printf("The fileName is: %s \n", fileName);
		freeBoard(&board, height);
		read_file(fileName, &board);
		height = getHeight(fileName);
		width = getWidth(fileName);
		generation = getGen(fileName);
		printf("The height is %d, width is, %d and Gen. is %d \n",height, width,generation);
		printBoard(board,height,width);
		
		
	}
	else{
		printf("They said no %s", fileName);
		exit(0);
	}
	//free(board, height);
	
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
	

	
	printf("openSave: %c \n",openSave);
	free(height);
	free(width);
*/
	return 0;
}



