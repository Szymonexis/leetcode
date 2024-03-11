#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jump(int* arr, int size);
void printArray(int* arr, int size);
void lprintf(const char* format, ...);

#endif  // MAIN_H
