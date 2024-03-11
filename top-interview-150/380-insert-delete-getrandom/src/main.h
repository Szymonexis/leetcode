#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct RandomizedSet {
  int** values;
  unsigned int size;
  unsigned int capacity;
  int hash;
  unsigned int maxChainLength;
} RandomizedSet;

RandomizedSet* randomizedSetCreate();
bool randomizedSetInsert(RandomizedSet* obj, int val);
bool randomizedSetRemove(RandomizedSet* obj, int val);
int randomizedSetGetRandom(RandomizedSet* obj);
void randomizedSetFree(RandomizedSet* obj);

void printArray(int* arr, int size);

#endif  // MAIN_H
