#ifndef ARRAY_H
#define ARRAY_H

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Array {
  int* values;
  unsigned int size;
  unsigned int capacity;
  bool allowResize;
  bool allowDuplicates;
  int allowSorting;
} Array;

/// @brief constructor for Array struct
/// @param initialCapacity
/// @param allowResize if true the initialCapacity will only be accepted if is
/// power of `2^n` where `n >= 0`
/// @param allowDuplicates
/// @param allowSorting if < 0 then in desc order, > 0 asc order, == 0 no
/// sorting
/// @return an initialized Array struct
Array* arrayCreate(unsigned int initialCapacity, bool allowResize,
                   bool allowDuplicates, int allowSorting);

/// @brief frees all allocated memory associated with Array struct
/// @param array
void arrayFree(Array* array);

/// @brief supports up to `INT16_MAX` size
/// @param array
/// @param val
/// @return if insertion was successful or not
bool arrayInsert(Array* array, int val);

/// @brief
/// @param array
/// @param val
/// @return `-1` if value not found - index of value otherwise
long int arrayFindIndex(Array* array, int val);

/// @brief
/// @param array
/// @param val
/// @return `INT16_MIN` if value doesnt exist - found value otherwise
long int arrayPopVal(Array* array, int val);

/// @brief
/// @param array
/// @param index
/// @return `INT16_MIN` if index is incorrect - value otherwise
int arrayPopIndex(Array* array, unsigned int index);

/// @brief prints the Array struct to stdout
/// @param array
void arrayPrint(Array* array);

// helperFuncs

/// @brief an Array struct helper func - not ment to be used outside Array
/// struct context
/// @param array
void _sort(Array* array);

/// @brief an Array struct helper func - not ment to be used outside Array
/// struct context
/// @param array
/// @param a
/// @param b
/// @param soft
/// @return
bool _compare(Array* array, int a, int b, bool soft, bool invert);

/// @brief an Array struct helper func - not ment to be used outside Array
/// struct context
/// @param a
/// @param b
/// @param soft
/// @return
bool _compareAsc(int a, int b, bool soft);

/// @brief an Array struct helper func - not ment to be used outside Array
/// struct context
/// @param a
/// @param b
/// @param soft
/// @return
bool _compareDesc(int a, int b, bool soft);

/// @brief an Array struct helper func - not ment to be used outside Array
/// struct context
/// @param x
/// @return
bool _isPowerOfTwo(unsigned int x);

#endif  // ARRAY_H