#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arithencode.h"
#include "arithdecode.h"

int main(int argc, char** argv) {
	if (argc < 3) {
		printf("Argument(s) manquant(s).\n");
		return -1;
	} 
	
	char* inputFile = argv[1];
	char* outputFile = argv[2];

	if (strcmp(argv[1], argv[2]) == 0)
		printf("Fichiers identiques.\n");
	else
		encodeProcess(inputFile, outputFile);

	return 0;
 }