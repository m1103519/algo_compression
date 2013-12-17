/******************************************************
						INCLUDES
******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "arithmodel.h"
/*****************************************************/

/******************************************************
						CONSTANTES
******************************************************/
#define ASCII 256
/*****************************************************/

/* Fonction d'initialisation du modele. */
void initModel(int* occurrences) {
	int i;
	// Initialisation des tableaux.
	for (i = 0; i < ASCII; ++i) {
		occurrences[i] = 0;
	}
}

/* Fonction de rafraichissement du modele. */
void updateModel(int* occurrences, int c) {
	// Determine la frequence de chaque caractere.
	occurrences[c]++;
}

/* Fonction de reallocation du modele. */
void reallocModel(int* occurrences, int* usedFreq, int charRead) {
	/* Allocation dynamique du tableau des frequences 
	   de caracteres utilises. */
	charRead = 7;
	usedFreq = malloc(charRead * (sizeof(int)));
	if (usedFreq == NULL)
		exit(EXIT_FAILURE);
	int i;
	// Changement de tableau.
	// occurrences -> usedFreq.
	for (i = 0; i < charRead; ++i) {
			if (occurrences[i] == 0) continue;
			usedFreq[i] = occurrences[i];
			printf("%d\n", i);
	}
	// Liberation de la memoire.
	free(occurrences);
}
