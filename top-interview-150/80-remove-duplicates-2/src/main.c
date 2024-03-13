#include "main.h"


int main() {
  int size = 11;
  int arr[] = {1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 5};

  int k = removeDuplicates(arr, size);

  printArray(arr, k);

  return 0;
}

/*
Given an integer array nums sorted in non-decreasing order, remove some
duplicates in-place such that each unique element appears at most twice. The
relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you
must instead have the result be placed in the first part of the array nums. More
formally, if there are k elements after removing the duplicates, then the first
k elements of nums should hold the final result. It does not matter what you
leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the
input array in-place with O(1) extra memory.
*/
int removeDuplicates(int* arr, int size) {
  if (size <= 0) {
    return 0;
  }

  int curr = arr[0];
  int d = 0;
  int dups = 0;
  int j = 1;
  for (int i = j; i < size; ++i) {
    if (curr != arr[i]) {
      d = 0;
      arr[j] = arr[i];
      curr = arr[i];
      ++j;
    } else if (d == 0) {
      arr[j] = curr;
      ++j;
      d = 1;
    } else {
      dups++;
    }
  }

  return size - dups;
}

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