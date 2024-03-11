#include "main.h"

/*
Implement the RandomizedSet class:

RandomizedSet() - Initializes the RandomizedSet object.

bool insert(int val) - Inserts an item val into the set if not present. Returns
true if the item was not present, false otherwise.

bool remove(int val) - Removes an item val from the set if present. Returns true
if the item was present, false otherwise.

int getRandom() - Returns a random element from the current set of elements
(it's guaranteed that at least one element exists when this method is called).

Each element must have the same probability of being returned. You must
implement the functions of the class such that each function works in average
O(1) time complexity.
*/

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/

RandomizedSet* randomizedSetCreate() {
  RandomizedSet* set = malloc(sizeof(RandomizedSet));
  if (set == NULL) {
    return NULL;
  }

  srand(time(NULL));

  unsigned int initialSize = 0;
  unsigned int initialCapacity = 10;
  unsigned int initialHash = 1;

  set->size = initialSize;
  set->capacity = initialCapacity;
  set->hash = initialHash;
  set->maxChainLength = initialCapacity;

  int valuesSize = (int)ceil(initialHash / (float)initialCapacity);
  set->values = malloc(valuesSize * sizeof(int*));
  if (set->values == NULL) {
    free(set);
    return NULL;
  }

  set->values[0] = malloc(initialCapacity * sizeof(int));
  if (set->values[0] == NULL) {
    free(set->values);
    free(set);
    return NULL;
  }

  return set;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
  
}

// binary search
bool randomizedSetRemove(RandomizedSet* obj, int val) {}

int randomizedSetGetRandom(RandomizedSet* obj) {}

void randomizedSetFree(RandomizedSet* obj) {}

void printArray(int* arr, int size) {
  printf("[");
  for (int i = 0; i < size; ++i) {
    printf("%d", arr[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

int main() {
  printf("Hello world!\n");
  return 0;
}
