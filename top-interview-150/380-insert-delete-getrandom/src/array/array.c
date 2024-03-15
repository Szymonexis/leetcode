#include "array.h"

Array* arrayCreate(unsigned int initialCapacity, bool allowResize,
                   bool allowDuplicates, int allowSorting) {
  Array* array = malloc(sizeof(Array));

  bool capIsPowerOfTwo = _isPowerOfTwo(initialCapacity);
  unsigned int capacity = !allowResize || capIsPowerOfTwo ? initialCapacity : 1;

  array->allowResize = allowResize;
  array->allowDuplicates = allowDuplicates;
  array->capacity = capacity;
  array->values = malloc(initialCapacity * sizeof(int));
  array->size = 0;
  array->allowSorting = allowSorting;

  return array;
}

void arrayFree(Array* array) {
  free(array->values);
  free(array);
}

int arrayInsert(Array* array, int val) {
  if (array->size >= INT_MAX) return 1;
  if (!array->allowResize && array->size == array->capacity) return 2;
  if (!array->allowDuplicates && arrayFindIndex(array, val) != -1) return 3;

  if (array->size == array->capacity) {
    array->capacity *= 2;
    array->values = realloc(array->values, array->capacity * sizeof(int));
  }

  array->values[array->size] = val;
  array->size++;

  if (array->allowSorting) _sort(array);

  return 0;
}

int* arrayGetValues(Array* array) {
  int* values = malloc(array->size * sizeof(int));

  for (int i = 0; i < array->size; ++i) {
    values[i] = array->values[i];
  }

  return values;
}

long int arrayFindIndex(Array* array, int val) {
  if (array->size == 0) {
    return -1;
  }

  // perform normal linear search
  if (!array->allowSorting) {
    for (int i = 0; i < array->size; ++i) {
      if (array->values[i] == val) return i;
    }

    return -1;
  }

  // perform faster binary search
  unsigned int lo = 0, hi = array->size ? array->size - 1 : 0;

  if (array->values[lo] == val) return lo;
  if (array->values[hi] == val) return hi;

  bool desc = array->allowSorting < 0;
  while (lo <= hi && lo >= 0 && lo < array->size && hi >= 0 &&
         hi < array->size) {
    unsigned int mid = lo + (hi - lo) / 2;

    if (array->values[mid] == val) {
      return mid;
    }

    if (_compare(array, array->values[mid], val, false, desc)) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  return -1;
}

long int arrayPopVal(Array* array, int val) {
  int index = arrayFindIndex(array, val);

  if (index == -1) return LONG_MIN;

  int foundValue = array->values[index];

  unsigned int newSize = array->size - 1;
  bool skipped = false;
  for (unsigned int i = 0, j = 0; j < newSize; ++i, ++j) {
    if (!skipped && i == index) {
      skipped = true;
      ++i;
      continue;
    }

    array->values[j] = array->values[i];
  }

  array->size = newSize;
  if (array->allowResize && array->capacity != 1 &&
      array->capacity / 2 > array->size) {
    array->capacity /= 2;
  }

  return foundValue;
}

int arrayPopIndex(Array* array, unsigned int index) {
  if (index > array->size - 1) {
    return INT_MIN;
  }

  int foundValue = array->values[index];

  unsigned int newSize = array->size - 1;
  bool skipped = false;
  for (unsigned int i = 0, j = 0; j < newSize; ++i, ++j) {
    if (!skipped && i == index) {
      skipped = true;
      ++i;
      continue;
    }

    array->values[j] = array->values[i];
  }

  array->size = newSize;
  if (array->allowResize && array->capacity != 1 &&
      array->capacity / 2 > array->size) {
    array->capacity /= 2;
  }

  return foundValue;
}

void arrayPrint(Array* array, char* prefix, int v) {
  if (v >= 1) {
    if (v >= 2) {
      char* asc = "asc";
      char* desc = "desc";
      char* allowSorting = "none";
      if (array->allowSorting > 0) allowSorting = asc;
      if (array->allowSorting < 0) allowSorting = desc;

      char* allowDuplicates = array->allowDuplicates ? "true" : "false";
      char* allowResize = array->allowResize ? "true" : "false";

      printf("%sallowDuplicates: %s\n", prefix, allowDuplicates);
      printf("%sallowResize: %s\n", prefix, allowResize);
      printf("%sallowSorting: %s\n", prefix, allowSorting);
      printf("%scapacity: %d\n", prefix, array->capacity);
      printf("%ssize: %d\n", prefix, array->size);
    }

    printf("%svalues: [", prefix);
    for (int i = 0; i < array->size; ++i) {
      printf("%d", array->values[i]);

      if (i < array->size - 1) {
        printf(", ");
      }
    }
    printf("]\n");
  } else {
    printf("%s[", prefix);
    for (int i = 0; i < array->size; ++i) {
      printf("%d", array->values[i]);

      if (i < array->size - 1) {
        printf(", ");
      }
    }
    printf("]\n");
  }
}

// using non-recursive mergesort
void _sort(Array* array) {
  if (!array->allowSorting) {
    return;
  }

  unsigned int size = array->size;
  int* a = array->values;
  int* b = malloc(size * sizeof(int));

  int rght, wid, rend;
  int i, j, m, t;

  for (int k = 1; k < size; k *= 2) {
    for (int left = 0; left + k < size; left += k * 2) {
      rght = left + k;
      rend = rght + k;

      if (rend > size) rend = size;

      m = left;
      i = left;
      j = rght;

      while (i < rght && j < rend) {
        if (_compare(array, a[i], a[j], false, false)) {
          b[m++] = a[i++];
        } else {
          b[m++] = a[j++];
        }
      }

      while (i < rght) {
        b[m++] = a[i++];
      }

      while (j < rend) {
        b[m++] = a[j++];
      }

      for (m = left; m < rend; m++) {
        a[m] = b[m];
      }
    }
  }

  free(b);
}

bool _compare(Array* array, int a, int b, bool soft, bool invert) {
  if (array->allowSorting > 0) {
    if (invert) return _compareAsc(b, a, soft);
    return _compareAsc(a, b, soft);
  }

  if (array->allowSorting < 0) {
    if (invert) return _compareDesc(b, a, soft);
    return _compareDesc(a, b, soft);
  };

  return false;
};

bool _compareAsc(int a, int b, bool soft) { return soft ? a < b : a <= b; }

bool _compareDesc(int a, int b, bool soft) { return soft ? a > b : a >= b; }

bool _isPowerOfTwo(unsigned int x) { return x != 0 && (x & (x - 1)) == 0; }
