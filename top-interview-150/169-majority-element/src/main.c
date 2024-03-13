#include "main.h"


int main() {
  int size = 10;
  int arr[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2};

  int m = majorityElement(arr, size);

  printf("majority element: %d\n", m);

  return 0;
}

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You
may assume that the majority element always exists in the array.

Solution: Boyer-Moore voting algo
*/
int majorityElement(int* nums, int numsSize) {
  int count = 0;
  int candidate = 0;

  for (int i = 0; i < numsSize; i++) {
    if (count == 0) {
      candidate = nums[i];
    }

    if (nums[i] == candidate) {
      count++;
    } else {
      count--;
    }
  }

  return candidate;
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