#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *ch = s21_NULL;
  int len = s21_strlen(str) + 1;
  for (int i = len - 1; i >= 0; i--) {
    if (str[i] == (char)c) {
      ch = (char *)&str[i];
      break;
    }
  }
  return ch;
}