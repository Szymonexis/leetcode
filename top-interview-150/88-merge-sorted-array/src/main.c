#include "main.h"


int main() {
  int nums1Size = 6;
  int nums1[] = {1, 2, 3, 0, 0, 0};
  int m = 3;
  int nums2Size = 3;
  int nums2[] = {2, 5, 6};
  int n = 3;

  printArray(nums1, nums1Size);
  printArray(nums2, nums2Size);

  merge(nums1, nums1Size, m, nums2, nums2Size, n);

  printArray(nums1, nums1Size);

  return 0;
}

void merge(int* out, int outSize, int m, int* nums2, int nums2Size, int n) {
  int i = m - 1;      // Last index of the first part
  int j = n - 1;      // Last index of the second part
  int k = m + n - 1;  // Last index of the merged array

  while (j >= 0) {
    if (i >= 0 && out[i] > nums2[j]) {
      out[k] = out[i];
      i--;
    } else {
      out[k] = nums2[j];
      j--;
    }
    k--;
  }
}

void testRand() {
  srand(time(NULL));

  int pointersSize = 2;
  void** pointers = calloc(pointersSize, sizeof(int*));
  int sizeA = 10;
  int sizeB = 10;

  int* arrayA = getRandomArray(sizeA);
  int* arrayB = getRandomArray(sizeB);
  pointers[0] = arrayA;
  pointers[1] = arrayB;

  printArray(arrayA, sizeA);
  printArray(arrayB, sizeB);

  merge(arrayA, sizeA, 5, arrayB, sizeB, 5);

  freeAll(pointers, pointersSize);
}

int* getRandomArray(int size) {
  int* array = (int*)malloc(size * sizeof(int));

  if (array == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    int randomNumber = 10 * i + rand() % 10;
    array[i] = randomNumber;
  }

  return array;
}

void printArray(int* array, int size) {
  printf("[");
  for (int i = 0; i < size; ++i) {
    printf(i == size - 1 ? "%d" : "%d, ", array[i]);
  }
  printf("]\n");
}

void freeAll(void** pointers, int size) {
  for (int i = 0; i < size; ++i) {
    free(pointers[i]);
  }
  free(pointers);
}