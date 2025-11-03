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
  Array** chains;
  long long int hash;
  unsigned long long int size;
} RandomizedSet;

RandomizedSet* randomizedSetCreate();
void randomizedSetFree(RandomizedSet* set);
bool randomizedSetInsert(RandomizedSet* set, int val);
bool randomizedSetRemove(RandomizedSet* set, int val);
int randomizedSetGetRandom(RandomizedSet* set);

// helpers
void randomizedSetPrint(RandomizedSet* set);

#endif  // RANDOMIZED_SET_H