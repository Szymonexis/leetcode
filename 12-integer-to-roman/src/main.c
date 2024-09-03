#include "main.h"

const char* SYMBOLS = "IVXLCDM";

int main() {
  char* str = intToRoman(3009);

  printf("%s\n", str);

  return 0;
}

char* appendChar(const char* str, char ch) {
  int len = strlen(str);
  char* new_str = (char*)malloc((len + 2) * sizeof(char));

  if (new_str == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }

  strcpy(new_str, str);
  new_str[len] = ch;
  new_str[len + 1] = '\0';

  return new_str;
}

char* joinStrings(int count, char** strs) {
  int total_length = 0;

  for (int i = 0; i < count; i++) {
    char* str = strs[i];
    total_length += strlen(str);
  }

  char* result = (char*)malloc((total_length + 1) * sizeof(char));
  result[0] = '\0';

  for (int i = 0; i < count; i++) {
    char* str = strs[i];
    strcat(result, str);
  }

  return result;
}

char* createRoman(int n, int i) {
  char* str = "";

  char f = SYMBOLS[i];
  char s = SYMBOLS[i + 1];
  char t = SYMBOLS[i + 2];

  switch (n) {
    case 1:
      str = appendChar(str, f);
      break;
    case 2:
      str = appendChar(str, f);
      str = appendChar(str, f);
      break;
    case 3:
      str = appendChar(str, f);
      str = appendChar(str, f);
      str = appendChar(str, f);
      break;
    case 4:
      str = appendChar(str, f);
      str = appendChar(str, s);
      break;
    case 5:
      str = appendChar(str, s);
      break;
    case 6:
      str = appendChar(str, s);
      str = appendChar(str, f);
      break;
    case 7:
      str = appendChar(str, s);
      str = appendChar(str, f);
      str = appendChar(str, f);
      break;
    case 8:
      str = appendChar(str, s);
      str = appendChar(str, f);
      str = appendChar(str, f);
      str = appendChar(str, f);
      break;
    case 9:
      str = appendChar(str, f);
      str = appendChar(str, t);
      break;
  }

  return str;
}

char* intToRoman(int num) {
  if (num < 1 || num > 3999) {
    return "";
  }

  int numCp = num;

  int s = num % 10;
  num = num - s;

  int t = num % 100;
  num = num - t;
  t = t / 10;

  int h = num % 1000;
  num = num - h;
  h = h / 100;

  int th = num % 10000;
  th = th / 1000;

  int si = 0;
  int ti = 2;
  int hi = 4;

  char* ss = createRoman(s, si);
  char* ts = createRoman(t, ti);
  char* hs = createRoman(h, hi);

  char* ths = "";
  for (int i = 0; i < th; i++) {
    ths = appendChar(ths, 'M');
  }

  char** strs = (char**)malloc((4) * sizeof(char*));
  strs[3] = ss;
  strs[2] = ts;
  strs[1] = hs;
  strs[0] = ths;
  return joinStrings(4, strs);
}
