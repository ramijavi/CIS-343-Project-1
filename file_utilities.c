#include "file_utilities.h"

// This function reads the file, creates the board, and populates the cells.
// Usage of FILE was thanks to Xiang Cao, professor at GVSU.
int read_file( char* filename, char ***buffer){

	char ch;
      	FILE *in;
	in = fopen (filename,"r" );
	int height, width, genNum;
	int counter = 0;
	char name[10];
	char buf[1024];
	
	if ( in == NULL ){
		printf ( "file could not be opened!\n" );
		exit (1);
      	} else {
		while(counter < 3){
			fgets(buf, sizeof(buf), in);
		    	buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
			if(counter == 0){
				height = atoi(buf);
			} else if(counter == 1){
				width = atoi(buf);
			} else{
				genNum = atoi(buf);
			}
			counter++;
		}

		char populateArray[height*width];
		allocateBoard(buffer,height, width);
		int popCounter = 0;

		while ( ! feof(in) )   {
			//Scans the character from filename
			fscanf ( in, "%c", &ch);
		
			if(!(ch > 48 && ch < 58) &&  ch != 10){
				populateArray[popCounter] = ch;
				popCounter++;
			}
     		}
		
		populateBoard(buffer, populateArray,height,width);	
	}

	fclose(in);
	return 0;
}

// This function writes the current board to a file, or a save.
int write_file( char* filename, char **buffer, int height, int width,int gen,int size){
	char ch;
	FILE *out;
	out = fopen(filename,"w");
	int index = 0;
	int sizeSave = 0;
	int i,k;
	char newLine = 10;
	
	while (index < 4){
		if(index == 0){
			fprintf(out, "%d\n", height);
			index++;
		}
		else if(index == 1){
			fprintf(out, "%d\n", width);
			index++;
		}
		else if(index == 2){
			fprintf(out,"%d\n",gen);
			index++;
			//break;
		}
		else {
			for(i = 0; i < height; i++){
				
				for(k = 0; k < width; k++){
					
					fprintf(out,"%c",buffer[i][k]);
					if((k + 1) % width == 0 && k != 0){
						fprintf(out,"%c",newLine);
					}
				}
			}
			index++;
		}

	}
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

// This function prints the board out
void printBoard(char** board, int height, int width){

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
int getHeight(char* filename){
	FILE *in;
	in = fopen (filename,"r" );
	int height;
	char buf[1024];
	
	fgets(buf, sizeof(buf), in);
	buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
	height = atoi(buf);
	fclose(in);
	return height;
}

// This function gets the width of the current board.
int getWidth(char* filename){
	FILE *in;
	in = fopen (filename,"r" );
	int width;
	char buf[1024];
	int counter = 0;
	while(counter < 2){
			fgets(buf, sizeof(buf), in);
		    	buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
			 if(counter == 1){
				width = atoi(buf);
			} 
			counter++;
	}
	fclose(in);
	return width;
}

// This function gets the generation of the current board.
int getGen(char* filename){
	FILE *in;
	in = fopen (filename,"r" );
	int generation;
	char buf[1024];
	int counter = 0;
	while(counter < 3){
			fgets(buf, sizeof(buf), in);
		    	buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
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

void copyBoard(char*** board, char** board2, int height, int width){
	//freeBoard(board,height,width);
	//allocateBoard(tempBoard,height,width);
	int i,k;
	for(i = 0; i < height; i++){
		for(k = 0; k < width; k++){
		//printf("The char is %c",(*board)[i][k]);
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
