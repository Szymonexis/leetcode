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
  int size = 150;
  int offset = -60;
  int* arr = malloc(size * sizeof(int));
  for (int i = 0; i < size; ++i) {
    arr[i] = offset + i;
  }

  RandomizedSet* set = randomizedSetCreate();

  for (int i = 0; i < size; ++i) {
    randomizedSetInsert(set, arr[i]);
    randomizedSetPrint(set);
    printf("\n");
  }

  for (int i = 0; i < size; ++i) {
    // @TODO: doesnt remove the last element in array
    randomizedSetRemove(set, arr[i]);
    randomizedSetPrint(set);
    printf("\n");
  }

  return 0;
}
