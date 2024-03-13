#ifndef RANDOMIZED_SET_H
#define RANDOMIZED_SET_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../array/array.h"

typedef struct RandomizedSet {
  Array* chains;
  unsigned int size;
  unsigned int capacity;
  int hash;
  unsigned int maxChainLength;
} RandomizedSet;

RandomizedSet* randomizedSetCreate();
void randomizedSetFree(RandomizedSet* obj);
bool randomizedSetInsert(RandomizedSet* obj, int val);
bool randomizedSetRemove(RandomizedSet* obj, int val);
int randomizedSetGetRandom(RandomizedSet* obj);

#endif  // RANDOMIZED_SET_H