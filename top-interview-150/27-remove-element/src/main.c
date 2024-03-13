#include "main.h"


int main() {
  int val = 3;
  int size = 4;
  int* arr = malloc(sizeof(int) * size);
  int temp[] = {3, 2, 2, 3};

  memcpy(arr, temp, sizeof(int) * size);

  int newSize = removeElement(arr, size, val);

  printf("%d\n", newSize);
  printArray(arr, newSize);

  return 0;
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

/*
  Given an integer array nums and an integer val, remove all occurrences of val
  in nums in-place. The order of the elements may be changed. Then return the
  number of elements in nums which are not equal to val.

  Consider the number of elements in nums which are not equal to val be k, to
  get accepted, you need to do the following things:
  - Change the array nums such that the first k elements of nums contain the
  elements which are not equal to val. The remaining elements of nums are not
  important as well as the size of nums.
  - Return k.
*/
int removeElement(int* nums, int numsSize, int val) {
  int j = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == val) {
      j++;
    } else if (j > 0) {
      nums[i - j] = nums[i];
    }
  }

  return numsSize - j;
}
