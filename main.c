
#include "file_utilities.h"

void initilize();

int main(int argc, char* argv[]){
	printf("Welcome player. You are playing the game of life\n");
	if(argc < 3){
		printf("User did not specify height and widith of game. Exiting..");
		return 0;
	}
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
