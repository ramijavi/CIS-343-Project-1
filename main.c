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

	/* Declaring local variables */
	char **board;
        char **tempBoard;
        int height, width, generation;
	int keepPlaying = 1;	
	char openSave;
        char fileName[20];
	char doNext;	

	/* Greet the player when the game is initialized */
	printf("\nWelcome player. You are playing the game of life\n");
	
	/* Check if the player entered correct input */
	/* Correct input should be two numbers */
	if(argc < 3 || argc > 3){
		/* If input was not correct, the player is notified */ 
		/* and the game is exited */
		printf("\nUser did not specify height and width of game. Exiting...");
		return 0;
	}
	/* If input is correct, then it's shown to the player */
	printf("\nYou have chosen to play with a board of size : %s x %s \n", argv[1], argv[2]);

	/* The size of the board is stored in our variables */
	height = atoi(argv[1]);
	width = atoi(argv[2]);
	
	/* We allocate memory for our board, as well as a temp board */
	allocateBoard(&board,height,width);
 	allocateBoard(&tempBoard,height,width);
	/* Prints board */
	printBoard(board,height,width);
	
	/* Ask user if they would like to open a file */
	printf("Would you like to open an existing saved generation?(y / n)\n");
	scanf("%c", &openSave);
	printf("\n");
	/* If user wants to open a file */
	if(openSave == 'y'){
		/* Ask the player for the file name */
		printf("Enter the file name you wish to open. \n");
		scanf("%s", fileName);
		/* Display file name*/
		printf("The fileName is: %s \n", fileName);
		/* Call a function to free both boards */
		freeBoard(&board, height);
		freeBoard(&tempBoard, height);
		/* Call a function to read the file. We pass the file name */
		/* and the address of the board variable */
		read_file(fileName, &board);
		/* Get the dimensions and generation of the new board */
		height = getHeight(fileName);
		width = getWidth(fileName);
		generation = getGen(fileName);
		/* Allocating memory for the temp board */
		allocateBoard(&tempBoard, height, width);
		/* Display the board dimensions and generation */
		printf("The file was succesfully loaded\n");
		printf("The height is %d, width is, %d and gen is %d \n", height, width, generation);
		/* Display board */
		printBoard(board,height,width);

	}
	/* If user do not want to open a file */
	else{
		printf("They said no %s", fileName);
		exit(0);
	}
	
	while (keepPlaying == 1){
		/* Ask the user what they want to do next */
		printf("What would you like to do next?\nEnter 's' to save file, 'l' to load a file, ");
		printf("'g' to run ONE generation, and 'G' to run more than one generation. If you want to "); 
		printf("exit, enter 'e'\n");
		scanf("%c", &doNext);
		
		if(doNext == 's'){


		} else if(doNext == 'l'){
			
			/* Ask the player for the file name */
	                printf("Enter the file name you wish to open. \n");
        	        scanf("%s", fileName);
               		/* Display file name*/
         	       	printf("The fileName is: %s \n", fileName);
 	        	/* Call a function to free both boards */
        	        freeBoard(&board, height);
        	        freeBoard(&tempBoard, height);
               		/* Call a function to read the file. We pass the file name */
               		/* and the address of the board variable */
                	read_file(fileName, &board);
                	/* Get the dimensions and generation of the new board */
                	height = getHeight(fileName);
                	width = getWidth(fileName);
                	generation = getGen(fileName);
			/* Allocating memory for the temp board */
                	allocateBoard(&tempBoard, height, width);
                	/* Display the board dimensions and generation */
                	printf("The file was succesfully loaded\n");
                	printf("The height is %d, width is, %d and gen is %d \n",height, width,generation);
                	/* Display board */
                	printBoard(board,height,width);


		} else if(doNext == 'g'){


		} else if(doNext == 'G'){


		} else if(doNext == 'e'){

			keepPlaying = 0;
		}
	}

	printf("Exiting game...");
	exit(0);

	return 0;
}



