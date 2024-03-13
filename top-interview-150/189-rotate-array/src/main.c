#include "main.h"


int main() {
  int k = 3;
  int size = 4;
  int nums[] = {-1, -100, 3, 99};
  printArray(nums, size);

  rotate(nums, size, k);

  printArray(nums, size);

  int corr[] = {3, 99, -1, -100};
  printf("should be:\n");
  printArray(corr, size);

  return 0;
}

/*
Given an integer array nums, rotate the array to the right by k steps, where k
is non-negative.

1. Example 1:

```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

2. Example 2:

```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```

Constraints:

- 1 <= nums.maxChainLength <= 105
- -231 <= nums[i] <= 231 - 1
- 0 <= k <= 105
 */
void rotate(int* arr, int size, int k) {
  // adjust for negative k and normalize k
  // to be within the range of 0 to size - 1
  k = ((k * -1) % size + size) % size;
  if (k == 0) {
    return;
  }

  int* newArr = malloc(sizeof(int) * size);
  if (newArr == NULL) {
    free(newArr);
    return;
  }

  for (int i = 0; i < size; ++i) {
    int j = (i + k) % size;
    newArr[i] = arr[j];
  }

  memcpy(arr, newArr, sizeof(int) * size);
  free(newArr);
};

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