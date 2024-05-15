#include "main.h"

int main() {
  // Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
  // Output: 6
  int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int o = 6;

  int hs = sizeof(h) / sizeof(h[0]);

  int r = trap(h, hs);
  printf("r: %d\n", r);
  printf("o: %d\n", o);
  assert(r == o);

  return 0;
}

/*
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:
n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/
int trap(int* height, int heightSize) {
  int ans = 0;
  int* l = (int*)malloc(heightSize * sizeof(int));  // l[i] := max(height[0..i])
  int* r = (int*)malloc(heightSize * sizeof(int));  // r[i] := max(height[i..n))

  // Calculate l[i]
  for (int i = 0; i < heightSize; ++i) {
    if (i == 0) {
      l[i] = height[i];
      continue;
    }

    if (height[i] > l[i - 1]) {
      l[i] = height[i];
    } else {
      l[i] = l[i - 1];
    }
  }

  // Calculate r[i]
  for (int i = heightSize - 1; i >= 0; --i) {
    if (i == heightSize - 1) {
      r[i] = height[i];
      continue;
    }

    if (height[i] > r[i + 1]) {
      r[i] = height[i];
    } else {
      r[i] = r[i + 1];
    }
  }

  // Calculate trapped water
  for (int i = 0; i < heightSize; ++i) {
    if (l[i] < r[i]) {
      ans += l[i] - height[i];
    } else {
      ans += r[i] - height[i];
    }
  }

  // Free dynamically allocated memory
  free(l);
  free(r);

  return ans;
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

void printMountains(int* arr, int size) {
  char block = '#';
  char space = ' ';

  int max = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int i = max; i > 0; --i) {
    for (int j = 0; j < size; ++j) {
      if (arr[j] >= i) {
        printf("%c", block);
      } else {
        printf("%c", space);
      }
    }
    printf("\n");
  }
}
