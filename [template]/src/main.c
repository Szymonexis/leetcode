#include "main.h"

int main() {
  printf("Hello world!\n");
  return 0;
}

bool canJump(int* arr, int size) { return false; }

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
