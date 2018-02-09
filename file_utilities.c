#include "file_utilities.h"

int read_file( char* filename, char ***buffer){
	printf("yay i got called. %s\n", filename);
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
				//printf("The height of the board is: ");
		    		//printf("%d\n", height);
			} else if(counter == 1){
				width = atoi(buf);
				//printf("The width of the board is: ");
				//printf("%d\n", width);
			} else{
				genNum = atoi(buf);
				//printf("The generation number is: ");
				//printf("%d\n", genNum);
			}
			counter++;
		}
		char populateArray[height*width];
		allocateBoard(buffer,height, width);
		//printBoard(buffer,height,width);
		int popCounter = 0;
		while ( ! feof(in) )   {
			//Scans the character from filename
			fscanf ( in, "%c", &ch );
			//printf("%c", ch);
		
			if(!(ch > 48 && ch < 58) &&  ch != 10){
				//printf("%c",ch);
				populateArray[popCounter] = ch;
				printf("%c",ch);
				popCounter++;
			}
			//if(ch > 64 && ch < 91){
			//toLowerCase(&ch);
			//Writes to output.txt
			//fprintf ( out, "%c", ch );
			//closes while
		
     		}
		
		populateBoard(buffer, populateArray,height,width);
		//printBoard(buffer,height,width);	
		
	}

	fclose(in);
	return 0;
}
// The size is how many characters are in the file.
int write_file( char* filename, char *buffer, int size){

	return 0;
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

void freeBoard(char*** board, int height){
	int i = 0;
	for(i = 0; i < height; i++){
		free((*board)[i]);
	}
    
	free(*board);
}

int getHeight(char* filename){
	FILE *in;
	in = fopen (filename,"r" );
	int height;
	char buf[1024];
	
	fgets(buf, sizeof(buf), in);
	buf[strlen(buf) - 1] = '\0'; // eat the newline fgets() stores
	height = atoi(buf);
	return height;
}

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
				printf("The width of the board is: ");
				//printf("%d\n", width);
			} 
			counter++;
	}
	return width;
}

int getGen(char* filename){

}

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

