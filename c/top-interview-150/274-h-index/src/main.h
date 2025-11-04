#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printArray(int* arr, int size);
int hIndex(int* arr, int size);
void merge(int* arr, int l, int m, int r);
void mergeSort(int* arr, int l, int r);

#endif  // MAIN_H
