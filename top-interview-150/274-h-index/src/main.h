#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int size);
int hIndex(int* arr, int size);
void merge(int* arr, int l, int m, int r);
void mergeSort(int* arr, int l, int r);

#endif  // MAIN_H
