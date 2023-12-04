// all little

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper = s21_NULL;
  if (str) {
    size_t length = s21_strlen(str);
    upper = (char *)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < s21_strlen(str); ++i) {
      char a = str[i];
      upper[i] = a >= 'a' && a <= 'z' ? a - 32 : a;
    }
    upper[length] = '\0';
  }
  return upper;
}
