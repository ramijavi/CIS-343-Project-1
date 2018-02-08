#include "file_utilities.h"

int read_file( char* filename, char **buffer){
	printf("yay i got called. %s f \n", filename);
	//allocateBoard();
	char ch;
      	FILE *in;
	in = fopen (filename,"r" );
	int height, width;
	int counter = 0;
	if ( in == NULL ){

	printf ( "file could not be opened!\n" );
	exit (1);
      	}
	else {
	while ( ! feof(in) )   {
	//Scans the character from filename
	fscanf ( in, "%c", &ch );
		//printf("%c", ch);
		
		if(ch > 48 && ch < 58 && counter == 0){
		height = ch - '0';
		counter++;
		printf("\n");
		printf("height is %d",height);
		}
		else if(ch > 48 && ch < 58 && counter == 1){
		width = ch - '0';
		//counter++;
		printf("\n");
		printf("width is %d",width);
		}
		else {
		printf("%c",ch);
		//implement code to write to the buffer.
		}
	//if(ch > 64 && ch < 91){
	 //toLowerCase(&ch);
	
	//Writes to output.txt
	//fprintf ( out, "%c", ch );
	//closes while
      	}	
	//closes else
	}
	fclose(in);
	return 0;
}
//THe size is how many characters are in the file.
int write_file( char* filename, char *buffer, int size){

	return 0;
}
