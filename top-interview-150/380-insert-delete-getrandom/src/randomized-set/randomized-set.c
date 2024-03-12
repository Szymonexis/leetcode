#include "./randomized-set.h"

RandomizedSet* randomizedSetCreate() {
  RandomizedSet* set = malloc(sizeof(RandomizedSet));
  if (set == NULL) {
    return NULL;
  }

  srand(time(NULL));

  return NULL;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) { return false; }

bool randomizedSetRemove(RandomizedSet* obj, int val) { return false; }

int randomizedSetGetRandom(RandomizedSet* obj) { return 0; }

void randomizedSetFree(RandomizedSet* obj) {}