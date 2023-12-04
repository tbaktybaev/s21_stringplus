// all big
#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *lower = s21_NULL;
  if (str) {
    size_t length = s21_strlen(str);
    lower = (char *)malloc(sizeof(char) * (length + 1));
    for (size_t i = 0; i < length; i++) {
      char a = str[i];
      lower[i] = a >= 'A' && a <= 'Z' ? a + 32 : a;
    }
    lower[length] = '\0';
  }
  return lower;
}
