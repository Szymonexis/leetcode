#include "main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
  // int arr[] = {2, 3, 1, 2, 4, 2, 3, 3, 1, 2, 2, 3, 1};
  // int expected = 3;

  // int arr[] = {3, 0, 6, 1, 5};
  // int expected = 3;

  // int arr[] = {1, 3, 1};
  // int expected = 1;

  int arr[] = {4, 4, 0, 0};
  int expected = 2;

  int size = sizeof(arr) / sizeof(int);
  int h = hIndex(arr, size);

  printf("result: %d\nexpected: %d\n", h, expected);

  return 0;
}

void merge(int* arr, int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++) L[i] = arr[l + i];
  for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int* arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

/*
Given an array of integers citations where citations[i] is the number of
citations a researcher received for their ith paper, return the researcher's
h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as
the maximum value of h such that the given researcher has published at least h
papers that have each been cited at least h times.
*/
int hIndex(int* arr, int size) {
  mergeSort(arr, 0, size - 1);

  printArray(arr, size);

  if (size <= 0) {
    return 0;
  }

  for (int i = 0; i < size; ++i) {
    if (arr[i] <= i) {
      return i;
    }
  }

  return size;
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
