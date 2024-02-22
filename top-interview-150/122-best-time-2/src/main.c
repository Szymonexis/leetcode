#include "main.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 6;
  int arr[] = {7, 1, 5, 3, 6, 4};

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
/*
chuj, nie dziala dla tego:

Input: [1,2,3,4,5]
Output: 0
Expected: 4

*/
int maxProfit(int* arr, int size) {
  if (size == 0) return 0;

  int minFound = 0;
  int sum = 0;
  int min = 0;
  int max = 0;

  for (int i = 1; i < size; ++i) {
    if (arr[i] < arr[min] && minFound == 0) {
      min = i;
      max = min;
    } else if (arr[i] > arr[max]) {
      minFound = 1;
      max = i;
    } else {
      sum += arr[max] - arr[min];
      max = i;
      min = i;
      minFound = 0;
    }

    // printf("sum: %d\tmin: %d\tmax: %d\tarr[min]: %d\tarr[max]: %d\n", sum,
    // min,
    //        max, arr[min], arr[max]);
  }

  return sum;
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