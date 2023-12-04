// деление строки на более мелкие по символу

#include "s21_string.h"

int IsDelim(char c, const char *delim) {
  int result = 0;
  const char *temp_delim = delim;
  while (*temp_delim != '\0') {
    if (*temp_delim == c) {
      result = 1;
      break;
    }
    ++temp_delim;
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *temp_str = s21_NULL;
  if (str == s21_NULL && temp_str == s21_NULL) {
    return s21_NULL;
  }
  static int f_last = 0;
  if (str != s21_NULL) {
    temp_str = str;
    f_last = 0;
  }
  while (IsDelim(*temp_str, delim)) {
    ++temp_str;
  }
  if (*temp_str == '\0') f_last = 1;
  char *temp = temp_str;
  const char *temp_dim = delim;
  int find_flag = 0;
  while (*temp_str != '\0') {
    while (*temp_dim != '\0') {
      if (*temp_dim == *temp_str) {
        find_flag = 1;
        break;
      }
      ++temp_dim;
    }
    if (find_flag) {
      break;
    }
    temp_dim = delim;
    ++temp_str;
  }
  if (find_flag) {
    *temp_str = '\0';
    ++temp_str;
  } else if (f_last) {
    temp = s21_NULL;
  } else {
    f_last = 1;
  }
  return temp;
}