#include "main.h"

int main() {
  // int arr[] = {1, 2, 3, 4};
  // int excepcted[] = {24, 12, 8, 6};
  int arr[] = {-1, 1, 0, -3, 3};
  int excepcted[] = {0, 0, 9, 0, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  int returnSize;
  int* answer = productExceptSelf(arr, size, &returnSize);

  printf("excepcted:\t");
  printArray(excepcted, size);

  printf("answer:\t\t");
  printArray(answer, size);

  return 0;
}

/**
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int size, int* returnSize) {
  *returnSize = size;
  int* answer = malloc(sizeof(int) * size);

  for (int i = 0; i < size; ++i) {
    answer[i] = 1;
  }

  int left = 1, right = 1;
  for (int i = 0; i < size; ++i) {
    answer[i] *= left;
    left *= nums[i];

    int j = size - i - 1;
    answer[j] *= right;
    right *= nums[j];
  }

  return answer;
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
