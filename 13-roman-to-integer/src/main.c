#include "main.h"

int main() {
  // Input: s = "III"
  // Output: 3
  // char s[] = "III";
  // int o = 3;

  // Input: s = "LVIII"
  // Output: 58
  // char s[] = "LVIII";
  // int o = 58;

  // Input: s = "MCMXCIV"
  // Output: 1994
  char s[] = "MCMXCIV";
  int o = 1994;

  int r = romanToInt(s);
  printf("romanToInt(\"%s\") = %d\n", s, r);
  printf("Expected: %d\n", o);

  return 0;
}

/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and
M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together.
12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII. Instead, the number four is written
as IV. Because the one is before the five we subtract it making four. The same
principle applies to the number nine, which is written as IX. There are six
instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.


Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.


Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
int romanToInt(char* s) {
  char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  int value[] = {1, 5, 10, 50, 100, 500, 1000};
  int len = strlen(s);
  int sum = 0;
  int* sumVals = (int*)malloc(sizeof(int) * len);
  char c = s[0];
  int j = 0;
  while (s[j] != '\0') {
    int i = 0;
    while (s[j] != roman[i]) {
      ++i;
    }
    int v = value[i];
    sumVals[j++] = v;
  }

  for (int i = 0; i < len - 1; ++i) {
    if (sumVals[i] >= sumVals[i + 1]) {
      sum += sumVals[i];
    } else {
      sum -= sumVals[i];
    }
  }

  sum += sumVals[len - 1];

  return sum;
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
