#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  int size = 6;
  int arr[] = {7, 1, 5, 3, 6, 4};

  int max = maxProfit(arr, size);

  printf("maxProfit: %d\n", max);

  return 0;
}

/*
You are given an array prices where prices[i] is the price of a given stock on
the ith day.

You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.
*/
// O(n log n) attempt is good but seems to be taking too long...
int maxProfit(int* arr, int size) {
  int j = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] > arr[j]) {
      j = i;
    }
  }

  int max = 0;
  for (int i = 0; i < j; ++i) {
    int diff = arr[j] - arr[i];
    if (diff > max) {
      max = diff;
    }
  }

  return max;
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