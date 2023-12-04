#include "s21_string.h"

// TODO: make non-nested code

// str1 : The Target string in which search has to be made.
// str2 : Argument string containing characters
// to match in target string.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t num = 0;
  int i = 0;
  for (; num == 0 && str1[i] != '\0'; i++) {
    for (int j = 0; num == 0 && str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        num = 1;
        i--;
      }
    }
  }
  return i;
}