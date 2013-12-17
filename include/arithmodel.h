#ifndef __ARITHMODEL__
#define __ARITHMODEL__

void initModel(int* occurrences);
void updateModel(int* occurrences, int c);
void reallocModel(int* occurrences, int* usedFreq, int charRead);

#endif