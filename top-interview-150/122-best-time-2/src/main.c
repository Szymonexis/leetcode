#include "main.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 6;
  int arr[] = {7, 1, 5, 3, 6, 4};
  // int size = 5;
  // int arr[] = {7, 6, 4, 3, 1};
  // int size = 5;
  // int arr[] = {1, 2, 3, 4, 5};
  // int size = 6;
  // int arr[] = {6, 1, 3, 2, 4, 7};
  // int size = 3;
  // int arr[] = {2, 1, 4};

  int max = maxProfit(arr, size);

  printArray(arr, size);
  printf("maxProfit: %d\n", max);

  return 0;
}

/*
You are given an integer array prices where prices[i] is the price of a given
stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at
most one share of the stock at any time. However, you can buy it then
immediately sell it on the same day.

Find and return the maximum profit you can achieve.

---

Example 1:

```
  Input: prices = [7,1,5,3,6,4]
  Output: 7
  Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
  5-1 = 4. Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit =
  6-3 = 3. Total profit is 4 + 3 = 7.
```

Example 2:

```
  Input: prices = [1,2,3,4,5]
  Output: 4
  Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
  5-1 = 4. Total profit is 4.
```

Example 3:

```
  Input: prices = [7,6,4,3,1]
  Output: 0
  Explanation: There is no way to make a positive profit, so we never buy the
  stock to achieve the maximum profit of 0.
```
*/
int maxProfit(int *arr, int size) {
  if (size == 0) return 0;

  int min = 0;
  int max = 0;
  int sum = 0;
  int lookingForMin = 1;

  int rows = size / 2;
  int cols = 2;
  int mmpi = 0;
  int **minMaxPairs = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; ++i) {
    minMaxPairs[i] = (int *)malloc(cols * sizeof(int));

    minMaxPairs[i][0] = 0;
    minMaxPairs[i][1] = 0;
  }

  for (int i = 0; i < size; ++i) {
    if (lookingForMin) {
      if (arr[min] > arr[i]) {
        min = i;
      } else {
        lookingForMin = 0;
        max = i;
      }
    } else {
      if (arr[max] < arr[i]) {
        max = i;
      } else {
        lookingForMin = 1;
        minMaxPairs[mmpi][0] = min;
        minMaxPairs[mmpi][1] = max;
        if (!(!min && !max)) {
          mmpi++;
        }
        min = i;
      }
    }
  }

  if (arr[min] < arr[max] && max && mmpi < size / 2) {
    minMaxPairs[mmpi][0] = min;
    minMaxPairs[mmpi][1] = max;
  }

  print2DArray(minMaxPairs, size / 2, 2);

  for (int i = 0; i < size / 2; ++i) {
    int min = minMaxPairs[i][0];
    int max = minMaxPairs[i][1];

    if (!min && !max || min >= max) {
      continue;
    }

    sum += arr[max] - arr[min];
  }

  return sum;
}

void printArray(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; ++i) {
    printf("%d", arr[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

void print2DArray(int **arr, int rows, int cols) {
  printf("[\n");
  for (int i = 0; i < rows; ++i) {
    printf("  [");
    for (int j = 0; j < cols; ++j) {
      printf("%d", arr[i][j]);
      if (j < cols - 1) {
        printf(", ");
      }
    }
    printf("]");
    if (i < rows - 1) {
      printf(",");
    }
    printf("\n");
  }
  printf("]\n");
}