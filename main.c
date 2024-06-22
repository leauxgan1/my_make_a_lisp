#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* args[]) {
	if (argc < 2) {
		printf("Please enter the filename you would like to interpret\n");
		return 0 ;
	} else if (argc > 2) {
		printf("Please enter only one file to interpret\n");
		return 0;
	}

	size_t read;
	size_t len = 7;	
	printf("The filename entered was %s\n", args[1]);
	
	char fileName[1024];
       	sprintf(fileName,"../%s",args[1]);
	FILE* programFile = fopen("../","r");

	char* line;
	if (!programFile) {
		return 0;
	}
	printf("File was opened!\n");
	printf("This is the first line in the file...\n");
	if ((read = getline(&line,&len, programFile)) == -1) {
		printf("Program did not have first line, exiting\n");
		fclose(programFile);
		return 0;
	}
	printf("Line: %s",line);

	fclose(programFile);


}
