#include "main.h"

int main() {
  // int size = 5;
  // int arr[] = {2, 3, 1, 1, 4};
  // bool expected = true;
  // int size = 5;
  // int arr[] = {3, 2, 1, 0, 4};
  // bool expected = false;
  int size = 1;
  int arr[] = {0};
  bool expected = true;

  bool result = canJump(arr, size);

  printf("expected: %d\nresult: %d\n", expected, result);

  return 0;
}

/*
You are given an integer array nums. You are initially positioned at the array's
first index, and each element in the array represents your maximum jump length
at that position.

Return true if you can reach the last index, or false otherwise.
*/
bool canJump(int* a, int s) {
  if (s == 1) {
    return true;
  }

  int m = 0;
  for (int i = 0; i < s - 1; ++i) {
    if (i > m) {
      return false;
    }

    int nm = i + a[i];
    m = m > nm ? m : nm;

    if (m >= s - 1) {
      return true;
    }
  }

  return false;
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