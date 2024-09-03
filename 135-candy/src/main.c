#include "main.h"

int main() {
  // Input: ratings = [1,0,2]
  // Output: 5
  // int r[] = {1, 0, 2};
  // int o = 5;

  // Input: ratings = [1,2,2]
  // Output: 4
  // int r[] = {1, 2, 2};
  // int o = 4;

  // Input: ratings = [1,2,87,87,87,2,1]
  // Output: 13
  // int r[] = {1, 2, 87, 87, 87, 2, 1};
  // int o = 13;

  // Input: ratings = [29,51,87,87,72,12]
  // Output: 12
  int r[] = {29, 51, 87, 87, 72, 12};
  int o = 12;

  int rs = sizeof(r) / sizeof(r[0]);
  int res = candy(r, rs);
  printf("o = %d\n", o);
  printf("res = %d\n", res);

  return 0;
}

/*
There are n children standing in a line. Each child is assigned a rating value
given in the integer array ratings.

You are giving candies to these children subjected to the following
requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies
to the children.
*/
int candy(int* r, int rs) {
  int c[rs];
  for (int i = 0; i < rs; i++) {
    c[i] = 1;
  }

  for (int i = 1; i < rs; i++) {
    if (r[i] > r[i - 1]) {
      c[i] = c[i - 1] + 1;
    }
  }

  for (int i = rs - 2; i >= 0; i--) {
    if (r[i] > r[i + 1] && c[i] <= c[i + 1]) {
      c[i] = c[i + 1] + 1;
    }
  }

  int tc = 0;
  for (int i = 0; i < rs; i++) {
    tc += c[i];
  }

  return tc;
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
