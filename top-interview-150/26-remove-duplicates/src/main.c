#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  int nums[10] = {1, 1, 1, 2, 3, 4, 4, 5, 6, 6};

  int k = removeDuplicates(nums, 10);

  printArray(nums, k);

  return 0;
}

/*
Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once. The
relative order of the elements should be kept the same. Then return the number
of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you
need to do the following things:

- Change the array nums such that the first k elements of nums contain the
unique elements in the order they were present in nums initially. The remaining
elements of nums are not important as well as the size of nums.
- Return k.
*/
int removeDuplicates(int* nums, int numsSize) {
  if (numsSize <= 0) {
    return 0;
  }

  int curr = nums[0];
  int dups = 0;
  int j = 1;
  for (int i = 1; i < numsSize; ++i) {
    if (curr != nums[i]) {
      nums[j] = nums[i];
      curr = nums[i];
      ++j;
    } else {
      dups++;
    }
  }

  return numsSize - dups;
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
