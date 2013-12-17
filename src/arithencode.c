/******************************************************
						INCLUDES
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arithencode.h"
#include "arithmodel.h"
/*****************************************************/

/******************************************************
						CONSTANTES
******************************************************/
#define ASCII 127
#define CODE_VALUE_BITS 16
#define MAX_VALUE (((long)1<<CODE_VALUE_BITS)-1)
/*****************************************************/

/******************************************************
						GLOBALES
******************************************************/
// Borne inferieure.
long lowBound;
// Borne superieure.
long highBound;
// Frequence des caracteres.
int occurrences[ASCII];
// Liste des frequences des caracteres utilises.
int usedFreq[ASCII];
/*****************************************************/

/* Fonction d'initialisation avant encodage. */
void initEncoding() {
	lowBound = 0;
	highBound = MAX_VALUE;
	printf("long: %lu\n", sizeof(long));
	printf("%ld\n", MAX_VALUE);
}

/* Fonction qui s'occupe d'encoder le fichier d'entree.
   Renvoie un fichier de sortie. */
 void encodeProcess(char* inputFile, char* outputFile) {
	// Initialisation encodage.
	initEncoding();
	/* Ouverture du fichier d'entree.
	   Acces en lecture seulement. */
	FILE* iFile;
  	iFile = fopen(inputFile, "rb");
  	if (!iFile) {
  		printf("Impossible d'ouvrir le fichier.\n");
  		return;
  	}

  	// Initialisaton du modele.
  	initModel(occurrences);

	int c = 0;
	do {
		c = getc(iFile);
		encodeChar(c);
	} while (c != EOF);

	fclose (iFile);
}

/* Fonction qui encode caractere par caractere. */

void encodeChar(char c) {
	long interval = (highBound - lowBound) + 1;

	if (c < 0 || c >= ASCII) {
		printf("ERREUR : caractere inconnu.\n");
		exit(1);
	} 

	highBound = lowBound + (interval * occurrences[c]) / ASCII;
	lowBound = lowBound + (interval * occurrences[c-1]) / ASCII + 1;
	printf("caractere %c: [%ld, %ld]\n", c, highBound, lowBound);

	updateModel(occurrences, c);
}