#include "main.h"

#define min(a, b) (a < b ? a : b)

int main() {
  // int size = 5;
  // int arr[] = {2, 3, 1, 1, 4};
  // int expected = 2;
  int size = 5;
  int arr[] = {2, 3, 0, 1, 4};
  int expected = 2;

  int result = jump(arr, size);

  printf("expected: %d\nresult: %d\n", expected, result);

  return 0;
}

/*
You are given arr 0-indexed array of integers arr of length size. You are
initially positioned at arr[0].

Each element arr[i] represents the maximum length of arr forward jump from index
i. In other words, if you are at arr[i], you can jump to any arr[i + j] where:

0 <= j <= arr[i]
and
i + j < size

Return the minimum number of jumps to reach arr[size - 1]. The test cases are
generated such that you can reach arr[size - 1].
*/
int jump(int* arr, int size) {
  if (size == 1) {
    return 0;
  }

  const int target = size - 1;
  int i = 0;
  int range = arr[i];
  int jumps = 1;
  lprintf("range: %d\ti: %d\n", range, i);
  while (i + range < target) {
    int nextRange = 0;
    int nextI = i;
    for (int j = i + 1; j <= min(target, i + range); ++j) {
      printArray(&arr[i], size - i);
      lprintf("nextRangeCandidate: %d\tarr[j]: %d\tj: %d\n",
              arr[j] - (range - j), arr[j], j);
      int nextRangeCandidate = arr[j] - (range - j);
      if (nextRange < nextRangeCandidate) {
        nextRange = arr[j];
        nextI = j;
      }
    }

    range = nextRange;
    i = nextI;
    ++jumps;

    lprintf("range: %d\ti: %d\n", range, i);
  }

  return jumps;
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

void lprintf(const char* format, ...) {
  va_list args;
  va_start(args, format);

  char* prefix = "[LOG]: ";
  int prefixLen = strlen(prefix);
  int newFormatLength = strlen(format) + prefixLen + 1;
  char* newFormat = malloc(newFormatLength * sizeof(char));

  strcpy(newFormat, prefix);
  strcat(newFormat, format);

  vprintf(newFormat, args);

  va_end(args);
  free(newFormat);
}
