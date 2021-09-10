#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char * filename;
	if (argc >= 2) {
		filename = argv[1];
	}
	else {
		filename = "./example.txt";
	}
	
	FILE *inputFile = fopen(filename, "rw"); 

	if (inputFile == NULL) {
		printf("Couldn't open file");
		return -1;
	}

	fseek(inputFile, 0, SEEK_END);
	long fileLength = ftell(inputFile);
	rewind(inputFile);

	char * buff = malloc(sizeof(char) * fileLength);
	fread(buff, 1, fileLength, inputFile);

	printf("%s\n", buff);

	fclose(inputFile);
  return 0;
}