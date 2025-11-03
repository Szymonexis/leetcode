#ifndef MAIN_H
#define MAIN_H

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* intToRoman(int num);
char* appendChar(const char* str, char ch);
char* joinStrings(int count, char** strs);
char* createRoman(int n, int i);

#endif  // MAIN_H
