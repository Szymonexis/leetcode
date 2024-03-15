#include "./randomized-set.h"

#include "randomized-set.h"

const long long int HASH_LOWER_BOUND = 64;

RandomizedSet* randomizedSetCreate() {
  RandomizedSet* set = malloc(sizeof(RandomizedSet));
  set->hash = HASH_LOWER_BOUND;
  set->size = 0;

  Array** chains = malloc(set->hash * sizeof(Array*));
  for (long long int i = 0; i < set->hash; ++i) {
    chains[i] = arrayCreate(10, false, false, 0);
  }
  set->chains = chains;

  srand(time(NULL));

  return set;
}

bool randomizedSetInsert(RandomizedSet* set, int val) {
  long long int index = val % set->hash;
  index = index < 0 ? set->hash + index : index;
  int res = arrayInsert(set->chains[index], val);

  switch (res) {
    // insertion successful
    case 0:
      set->size++;
      return true;

    // over size limit - can't occur
    case 1:
      return false;

    // chain is full - resize
    case 2: {
      long long int oldHash = set->hash;
      long long int newHash = oldHash * 2;
      unsigned long long int newSize = set->size + 1;

      int k = 0;
      int* allValues = malloc(newSize * sizeof(int));
      for (long long int i = 0; i < oldHash; ++i) {
        for (unsigned int j = 0; j < set->chains[i]->size; ++j) {
          allValues[k++] = set->chains[i]->values[j];
        }
      }
      allValues[newSize - 1] = val;

      for (long long int i = 0; i < oldHash; ++i) {
        arrayFree(set->chains[i]);
      }
      free(set->chains);

      Array** newChains = malloc(newHash * sizeof(Array*));
      for (long long int i = 0; i < newHash; ++i) {
        newChains[i] = arrayCreate(10, false, false, 0);
      }

      set->hash = newHash;
      set->chains = newChains;
      set->size = newSize;

      for (unsigned long long int i = 0; i < newSize; ++i) {
        int val = allValues[i];
        long long int index = val % set->hash;
        index = index < 0 ? set->hash + index : index;
        arrayInsert(set->chains[index], val);
      }

      return true;
    }

    // duplicate
    case 3:
      return false;

    default:
      return false;
  }
}

bool randomizedSetRemove(RandomizedSet* set, int val) {
  long long int index = val % set->hash;
  index = index < 0 ? set->hash + index : index;
  long int res = arrayPopVal(set->chains[index], val);

  switch (res) {
    // value not found
    case LONG_MIN:
      return false;

    // value found
    default: {
      unsigned long long int newSize = set->size == 0 ? 0 : set->size - 1;
      if (newSize > set->hash / 2 || set->hash <= HASH_LOWER_BOUND) return true;

      long long int oldHash = set->hash;
      long long int newHash = oldHash / 2;

      int k = 0;
      int* allValues = malloc(newSize * sizeof(int));
      for (long long int i = 0; i < oldHash; ++i) {
        for (unsigned int j = 0; j < set->chains[i]->size; ++j) {
          allValues[k++] = set->chains[i]->values[j];
        }
      }

      for (long long int i = 0; i < oldHash; ++i) {
        arrayFree(set->chains[i]);
      }
      free(set->chains);

      Array** newChains = malloc(newHash * sizeof(Array*));
      for (long long int i = 0; i < newHash; ++i) {
        newChains[i] = arrayCreate(10, false, false, 0);
      }

      set->hash = newHash;
      set->chains = newChains;
      set->size = newSize;

      for (unsigned long long int i = 0; i < newSize; ++i) {
        int val = allValues[i];
        long long int index = val % set->hash;
        index = index < 0 ? set->hash + index : index;
        arrayInsert(set->chains[index], val);
      }

      return true;
    }
  }
}

int randomizedSetGetRandom(RandomizedSet* set) { return 0; }

void randomizedSetFree(RandomizedSet* set) {}

void randomizedSetPrint(RandomizedSet* set) {
  printf("hash: %lld\n", set->hash);

  printf("{\n");
  for (long long int i = 0; i < set->hash; ++i) {
    printf("\t[%lld]:", i);
    arrayPrint(set->chains[i], "\t", 0);
  }
  printf("}\n");
}