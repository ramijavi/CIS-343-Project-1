/*
 * This is the source file that contains all the helper functions
 * that are called from the main()
 *
 * @authors - Andy Hing Hung & Javier Ramirez
 * @version - Winter 2018
 */


#include "file_utilities.h"

/* This function reads the file, creates the board, and populates the cells */
int read_file( char* filename, char ***buffer){

	//ch is the current char in the file.
	char ch;

	//This is the file pointer.
      	FILE *in;

	//We open the file and do a read.
	in = fopen (filename,"r" );

	//This variables are for the height, width and generation.
	int height, width, genNum;

	//This counter will tell us if we are currently
	//on the line for height,width, or generation.
	int counter = 0;

	//This variable holds the numbers to be
	//converted to integer
	char buf[1024];
	
	//If file doesn't exist, exist.
	if ( in == NULL ){

		printf ( "file could not be opened!\n" );
		exit (1);

      	} else { //File exists, do the logic.

		while(counter < 3){

			//Idea from for reading a line from a combination of authors,
			//https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
			fgets(buf, sizeof(buf), in);
		    	buf[strlen(buf) - 1] = '\0';

			if(counter == 0){
				height = atoi(buf);
			} else if(counter == 1){
				width = atoi(buf);
			} else{
				genNum = atoi(buf);
			}
			counter++;
		}
		//this array will contain the cells
		char populateArray[height*width];

		//Allocates the board
		allocateBoard(buffer,height, width);

		//keeps track where in the popArray we are
		int popCounter = 0;

		//Goes through every character in the file,
		//code example from Xiang Cao, professor @ GVSU
		while ( ! feof(in) )   {
			//Scans the character from filename
			fscanf ( in, "%c", &ch);

			//makes sure this character is not an integer and a new line.
			if(!(ch > 48 && ch < 58) &&  ch != 10){
				populateArray[popCounter] = ch;
				popCounter++;
			}
     		}
		//Populate the board given the populate Array.
		populateBoard(buffer, populateArray,height,width);	
	}

	fclose(in);
	return 0;
}

// This function writes the current board to a file, or a save.
int write_file( char* filename, char **buffer, int height, int width,int gen,int size){

	//ch is the current char in the file.
	char ch;

	//This is the file pointer.
	FILE *out;

	//We open/create the file and do a write.
	out = fopen(filename,"w");

	//To know if we are writing the board
	//information, or the cells.
	int index = 0;
	int sizeSave = 0;

	//Used for the for-loop to go through the board.
	int i,k;

	//Used to create a new line.
	char newLine = 10;
	
	while (index < 4){
		//Write the height first
		if(index == 0){
			fprintf(out, "%d\n", height);
			index++;
		}
		//Write the width second
		else if(index == 1){
			fprintf(out, "%d\n", width);
			index++;
		}
		//Write the generation third
		else if(index == 2){
			fprintf(out,"%d\n",gen);
			index++;
			//break;
		}
		//Write the board.
		else {
			for(i = 0; i < height; i++){
				
				for(k = 0; k < width; k++){
					//writes the cell
					fprintf(out,"%c",buffer[i][k]);

					//Make sure its not the first cell and if 
					//its the last, new line.
					if((k + 1) % width == 0 && k != 0){
						fprintf(out,"%c",newLine);
					}
				}
			}
			//Increment the index so that we dont loop for ever.
			index++;
		}

	}
	//Close FILE reader
	fclose(out);
	return 0;
}


// Getting the size of the file,from Yuushi on 
// https://codereview.stackexchange.com/questions/73553/finding-the-size-of-a-file
int getSize(char* filename){
	FILE *in;
	in = fopen(filename,"r");
	fseek(in, 0, SEEK_END);
	int size = ftell(in);
	rewind(in);
	fclose(in);
	return size;
}

// This function allocates memory to hold the 2D array
// that holds the board. Thanks to: Abhay Rathi
// https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
void allocateBoard(char*** board,int height,int width){

	int r = height, c = width, i, j;
   	char emptyCell = ' ';
	*board = (char **)malloc(r * sizeof(char *));

	for (i=0; i<r; i++){
        	(*board)[i] = (char *)malloc(c * sizeof(char ));
 	}
  
        for (i = 0; i <  r; i++){
        	for (j = 0; j < c; j++){
                	(*board)[i][j] = emptyCell;  // OR *(*(arr+i)+j) = ++count
                }
	}
 
	//return board;    
                        
}

// This function prints the board out with "|"
// in between the cells.
void printBoard(char** board, int height, int width){
	//Variables for our for-loop.
	int i, j;
	printf("\n");

	for (i = 0; i <  height; i++){
		
		printf("| ");
         	for (j = 0; j < width; j++){
                        printf("%c", board[i][j]);
			printf(" | ");
        	}

		printf("\n");
        }
	printf("\n");
}

// This function frees the board that is malloced.
void freeBoard(char*** board, int height){
	int i = 0;
	for(i = 0; i < height; i++){
		free((*board)[i]);
	}
    
	free(*board);
}

// This function gets the height of the current board.
// Re-using our read_file logic.
int getHeight(char* filename){
	FILE *in;
	in = fopen (filename,"r" );
	int height;
	char buf[1024];
	
	fgets(buf, sizeof(buf), in);
	buf[strlen(buf) - 1] = '\0'; 
	height = atoi(buf);
	fclose(in);
	return height;
}

// This function gets the width of the current board.
// Re-using our read_file logic.
int getWidth(char* filename){
	FILE *in;
	in = fopen (filename,"r" );
	int width;
	char buf[1024];
	int counter = 0;
	while(counter < 2){
			fgets(buf, sizeof(buf), in);
		    	buf[strlen(buf) - 1] = '\0'; 
			 if(counter == 1){
				width = atoi(buf);
			} 
			counter++;
	}
	fclose(in);
	return width;
}

// This function gets the generation of the current board.
// Re-using our read_file logic.
int getGen(char* filename){
	FILE *in;
	in = fopen (filename,"r" );
	int generation;
	char buf[1024];
	int counter = 0;
	while(counter < 3){
			fgets(buf, sizeof(buf), in);
		    	buf[strlen(buf) - 1] = '\0'; 
			 if(counter == 2){
				generation = atoi(buf);
			} 
			counter++;
	}
	fclose(in);
	return generation;
}

// This function populates the board.
void populateBoard(char*** board, char* popArray, int height, int width){
	int i,k;
	int counter = 0;
	for(i = 0; i < height; i++){
		for(k = 0; k < width; k++){
			(*board)[i][k] = popArray[counter];
			counter++;
		}
	}
}

//This function copies the board over.
void copyBoard(char*** board, char** board2, int height, int width){
	
	int i,k;
	for(i = 0; i < height; i++){
		for(k = 0; k < width; k++){
		(*board)[i][k] = board2[i][k];
		}
	}

}

// This function will run a generation on the board.
void runGeneration(char*** board, char** tempBoard, int height, int width){
	/* The variables i and j will be used in the for loops */	
	/* NeighborCount will be used to count how many neighbors each cell has */
	int i, j, neighborCount;

	/* Nested for loop to iterate through every element of the board array */	
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			/* Reset the neighbor count to 0 for every cell */
			neighborCount = 0;
			
			/* Check if the cell is not on the right border of the board */
			if(j != width - 1){
				/* Check if the spot to its right has a live cell */
                                if (tempBoard[i][j+1] == 'o'){
					/* If there is, increment neighbor count*/
                                        neighborCount++;
                                }
                        }
			/* Check if the cell is not on the left border of the board */
                        if(j != 0){
				/* Check if the spot to its left has a live cell */
                                if (tempBoard[i][j-1] == 'o'){
                                        neighborCount++;
                                }
                        }
			/* Check if the cell is not on the bottom border of the board */
                        if(i != height - 1){
				/* Check if the spot below has a live cell */
                                if (tempBoard[i+1][j] == 'o'){
                                        neighborCount++;
                                }
                        }
			/* Check if the cell is not on the top border of the board*/
                        if(i != 0){
				/* Check if the spot above has a live cell*/
                                if (tempBoard[i-1][j] == 'o'){
                                        neighborCount++;
                                }
                        }
			/* Check if the cell is not on the bottom right corner */
                        if((i != height - 1) && (j != width - 1)){
				/* Check if the spot to its bottom right has a live cell */
                                if (tempBoard[i+1][j+1] == 'o'){
                                        neighborCount++;
                                }
                        }
			/* Check if the cell is not on the bottom left corner */
                        if((i != height - 1) && ( j != 0)){
				/* Check if the spot to its bottom left has a live cell */
                                if (tempBoard[i+1][j-1] == 'o'){
                                        neighborCount++;
                                }
                        }
			/* Check if the cell is not on the top right corner */
                        if((i != 0) && (j != width -1)){
				/* Check if the spot to its top right has a live cell */
                                if (tempBoard[i-1][j+1] == 'o'){
                                        neighborCount++;
                                }
			}
			/* Check if the cell is not on the top left corner */
			if((i != 0) && (j != 0)){ 
				/* Check if the spot to its top left has a live cell*/
                                if (tempBoard[i-1][j-1] == 'o'){
                                        neighborCount++;
                                }
			}
			/* At this point, we should have the exact number of neighbors that the current cell has */
			/* We check if the cell will survive or not depending on the number of neighbors that it has */
	
			/* If the cell is currently alive and has less than 2 or more than 3 neighbors */
			if(((neighborCount < 2) || (neighborCount > 3)) && tempBoard[i][j] == 'o'){
				/* Then that cell will die */
				(*board)[i][j] = 'x';
			} 
			/* If the cell is currently dead and has exactly 3 neighbors */
			else if ((neighborCount == 3) && tempBoard[i][j] == 'x'){
				/* Then it will come back to life */
				(*board)[i][j] = 'o';
			}
		}
	}	
}
