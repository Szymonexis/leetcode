#include "main.h"

int main() {
  // int size = 5;
  // int arr[] = {2, 3, 1, 1, 4};
  // int expected = 2;
  int size = 5;
  int arr[] = {2, 3, 0, 1, 4};
  int expected = 2;

  int result = jump(arr, size);

  printf("expected: %d\nresult: %d\n", expected, result);

  return 0;
}

/*
You are given arr 0-indexed array of integers arr of length size. You are
initially positioned at arr[0].

Each element arr[i] represents the maximum length of arr forward jump from index
i. In other words, if you are at arr[i], you can jump to any arr[i + j] where:

0 <= j <= arr[i]
and
i + j < size

Return the minimum number of jumps to reach arr[size - 1]. The test cases are
generated such that you can reach arr[size - 1].
*/
int jump(int* arr, int size) {
  if (size == 1) {
    return 0;
  }

  int maxReach = 0;
  int jumps = 0;
  for (int i = 0; i < size - 1; ++i) {
    int newMaxReach = i + arr[i];
    if (maxReach < newMaxReach) {
      maxReach = newMaxReach;
      jumps++;
    }

    if (maxReach >= size - 1) {
      break;
    }
  }

  return jumps;
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
