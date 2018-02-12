/**
 * CIS 343 - 02 Structures of Programming Languages
 * Project 1 - The Game of Life
 * 
 * The Game of Life was developed by John Conway (a British mathematician) in the 1970s. 
 * It is an example of a cellular automaton, a data structure that seems to evolve iteratively.
 * In this simulation we will use a set of rules to determine the survival or death of the cells.
 *
 * In this assignment we will focus our attention mostly on memory allocation & memory
 * management in general. 
 *
 * @authors - Andy Hing Hung & Javier Ramirez
 * @version - Winter 2018
 */

#include "file_utilities.h"

int main(int argc, char* argv[]){

	/* Declaring local variables */
	char **board;
        char **tempBoard;
        int height, width, generation, size;
	int keepPlaying = 1;	
	char openSave;
        char fileName[20];
	char fileSave[20];
	char doNext;
	int runGen;	

	/* Greet the player when the game is initialized */
	printf("\nWelcome player. You are playing the game of life\n");
	
	/* Ask user if they want to start playing the game */
	printf("To start the game, type 'y'. Or to close, type a random letter.\n");
	scanf("%c", &openSave);
	printf("\n");

	/* If user wants to open a file */
	if(openSave == 'y'){
		/* Ask the player for the file name */
		printf("Enter the file name you wish to open. 10x10.txt or 15x15.txt \n");
		scanf("%s", fileName);

		/* Display the file name*/
		printf("The fileName is: %s \n", fileName);

		/* Call a function to read the file. We pass the file name */
		/* and the address of the board variable */
		read_file(fileName, &board);	

		/* Get the dimensions, generation and size of the new board */
		height = getHeight(fileName);
		width = getWidth(fileName);
		generation = getGen(fileName);
		size = getSize(fileName);		

		/* Allocating memory for the temporary board */
		allocateBoard(&tempBoard,height,width);

		/* Display the board dimensions and generation */
		printf("The file was succesfully loaded\n");
		printf("The height is %d, width is, %d and gen is %d \n", height, width, generation);
		printf("The file size is: %d",size);
		
		/* Display board */
		printBoard(board,height,width);		
	}
	/* If user does not want to open a file */
	else{
		/* Print a closing message and exit application */
		printf("You didn't type 'y'. Closing..\n");
		exit(0);
	}
	
	/* This loop will execute until the player wants to exit the game */
	while (keepPlaying == 1){
		/* Ask the user what they want to do next */
		printf("What would you like to do next?\nEnter 's' to save file, 'l' to load a file, ");
		printf("'g' to run ONE generation, and 'G' to run more than one generation. If you want to "); 
		printf("exit, enter 'e'\n");
		scanf("  %c", &doNext);
		
		if(doNext == 's'){
		/* If user enters 's', then the game will be written onto a file */
			
			/* Ask user for file name */
			printf("What name do you want to save your game under? (Remember to add .txt)\n");
			scanf(" %s", fileSave);

			/* Call save function */
		 	write_file(fileSave, board, height, width, generation, getSize("bill.txt"));
				
		} else if(doNext == 'l'){
		/* If user enters 'l', a saved generation will be loaded */
			
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

                	/* Get the dimensions, generation and size of the new board */
                	height = getHeight(fileName);
                	width = getWidth(fileName);
                	generation = getGen(fileName);
			size = getSize(fileName);
			
			/* Allocating memory for the temp board */
                	allocateBoard(&tempBoard, height, width);

                	/* Display the board dimensions, generation and size */
                	printf("The file was succesfully loaded\n");
                	printf("The height is %d, width is, %d and gen is %d \n",height, width,generation);
			printf("The size of the file is: %d", size);
			
                	/* Display board */
                	printBoard(board,height,width);
		
		} else if(doNext == 'g'){
		/* If user enters 'g', the game will run one generation */
			
			/* Copy the board onto the temp board */
	                copyBoard(&tempBoard, board, height, width);
		
			/* Call run generation function */
			runGeneration(&board, tempBoard, height, width);
		
			/* Increase the generation by one */			
			generation++;
		
			/* Display the board */
			printBoard(board, height, width);
			
		} else if(doNext == 'G'){
		/* If user enters 'G', the game will run for as many generations as specified */
		
			/* Variable for counting the generations */
			runGen = 0;		
	
			/* Ask the user for the number of generations to run */
			printf("How many generations do you want to run?\n");
			scanf(" %d", &runGen);
			
			/* Run the specified number of generations */
			while(runGen > 0){

				/* Copy the board onto the temp board */
	                        copyBoard(&tempBoard, board, height, width);

        	                /* Call run generation function */
                	        runGeneration(&board, tempBoard, height, width);

                	        /* Increase the generation by one */
                	        generation++;

                	        /* Display the board */
                	        printBoard(board, height, width);
	
				runGen--;
			}

		} else if(doNext == 'e'){
		/* If user enter 'e', then exit the loop */
			keepPlaying = 0;
		}		
	}
	
	/* Print exit message and exit the game */
	printf("Exiting game...\n");
	exit(0);

	return 0;
}



