/**
 * CIS 343 - 02 Structures of Programming Languages
 * Project 1 - The Game of Life
 * 
 * @authors - Andy Hung & Javier Ramirez
 * 
 * The Game of Life was developed by John Conway (a British mathematician) in the 1970s. 
 * It is an example of a cellular automaton, a data structure that seems to evolve iteratively.
 * In this simulation we will use a set of rules to determine the survival or death of the cells.
 *
 * In this assignment we will focus our attention mostly on memory allocation & memory
 * management in general. 
 */
#include "file_utilities.h"

void initilize();

int main(int argc, char* argv[]){

	// Greet the player when the game is initialized
	printf("Welcome player. You are playing the game of life\n");
	
	// Check if the player entered correct input
	// Correct input should be two numbers 
	if(argc < 3 || argc > 3){
		// If input was not correct, the player is notified 
		// and the game is exited
		printf("User did not specify height and width of game. Exiting...");
		return 0;
	}
	// If input is correct, then it's shown to the player
	printf("You have chosen to play with a board of size : %s x %s \n", argv[1], argv[2]);
	

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
	scanf("%c", &openSave);
	printf("\n");
	printf("openSave: %c \n",openSave);
	free(height);
	free(width);
	return 0;
}

void initialize_board(){

	
}
