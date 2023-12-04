#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (!src) {
    dest = s21_NULL;
  } else {
    s21_size_t size = 0;
    while (*src && n) {
      dest[size] = *src;
      src++;
      size++;
      dest[size] = '\0';
      n--;
    }
  }
  return dest;
}