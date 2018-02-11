#include "file_utilities.h"

// This function reads the file and creates the board.
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

// This function writes the current board to a file, or a save.(The size is how many characters are in the file. what are we using it for?)
int write_file( char* filename, char **buffer, int height, int width,int gen,int size){
	char ch;
	FILE *out;
	out = fopen(filename,"w");
	int index = 0;
	while (index < size){
	


	}
	fclose(out);
	return 0;
}


//from https://codereview.stackexchange.com/questions/73553/finding-the-size-of-a-file	
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
// that holds the board. It uses the function malloc
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

void runGeneration(char*** board, char** tempBoard, int height, int width){
	int i, j, neighborCount;

	printf("I made to runGen!\n");
	
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			printf("\n\n INSIDE FORFOR LOOP\n");
			
			neighborCount = 0;
			
			if(j != width - 1){
                                if (tempBoard[i][j+1] == 'O'){
                                        neighborCount++;
                                }
                        }
                        if(j != 0){
                                if (tempBoard[i][j-1] == 'O'){
                                        neighborCount++;
                                }
                        }
                        if(i != height - 1){
                                if (tempBoard[i+1][j] == 'O'){
                                        neighborCount++;
                                }
                        }
                        if(i != 0){
                                if (tempBoard[i-1][j] == 'O'){
                                        neighborCount++;
                                }
                        }
                        if((i != height - 1) && (j != width - 1)){
                                if (tempBoard[i+1][j+1] == 'O'){
                                        neighborCount++;
                                }
                        }
                        if((i != height - 1) && ( j != 0)){
                                if (tempBoard[i+1][j-1] == 'O'){
                                        neighborCount++;
                                }
                        }
                        if((i != 0) && (j != width -1)){
                                if (tempBoard[i-1][j+1] == 'O'){
                                        neighborCount++;
                                }
			}
			if((i != height != 0) && (j != 0)){ 
                                if (tempBoard[i-1][j-1] == 'O'){
                                        neighborCount++;
                                }
			}

			if(((neighborCount < 2) || (neighborCount > 3)) && tempBoard[i][j] == 'O'){
				(*board)[i][j] = 'X';
			} 
			else if ((neighborCount == 3) && tempBoard[i][j] == 'X'){
				(*board)[i][j] = 'O';
			}
		}
	}	
}
