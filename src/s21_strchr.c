#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *answer = (char *)str;
  int flag = 0;
  for (s21_size_t i = 0; i <= s21_strlen(str) && flag == 0; i++) {
    if (*answer == c)
      flag = 1;
    else
      answer++;
  }
  if (flag == 0) answer = s21_NULL;
  return answer;
}
