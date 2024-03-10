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
You are given a 0-indexed array of integers a of length s. You are initially
positioned at a[0].

Each element a[i] represents the maximum length of a forward jump from index
i. In other words, if you are at a[i], you can jump to any a[i + j] where:

0 <= j <= a[i] and
i + j < s

Return the minimum number of jumps to reach a[s - 1]. The test cases are
generated such that you can reach a[s - 1].
*/
int jump(int* a, int s) {
  if (s == 1) {
    return 0;
  }

  int maxReach = 0;
  int jumps = 0;
  for (int i = 0; i < s - 1; ++i) {
    int newMaxReach = i + a[i];
    if (maxReach < newMaxReach) {
      maxReach = newMaxReach;
      jumps++;
    }

    if (maxReach >= s - 1) {
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
