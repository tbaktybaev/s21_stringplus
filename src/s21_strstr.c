// ищет указатель на первое вхождение в строке

#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *done = s21_NULL;
  int str = s21_strlen(haystack);
  int search = s21_strlen(needle);
  for (int i = 0; i < str - search + 1; ++i) {
    int count = 0;
    for (int j = 0; j < search; ++j) {
      if (haystack[i + j] == needle[j]) {
        ++count;
      }
    }
    if (count == search) {
      done = (char *)haystack + i;
      break;
    }
  }
  return done;
}
