#include "s21_string.h"

void *s21_trim(const char *str, const char *trim_chars) {
  char *res = s21_NULL;
  if (str && trim_chars) {
    const char *start = str;
    const char *end = str + s21_strlen(str);
    while (*start && s21_strchr(trim_chars, *start)) {
      start++;
    }
    while (end > start && s21_strchr(trim_chars, *(end - 1))) {
      end--;
    }
    res = malloc((end - start + 1) * sizeof(char));
    if (res) {
      s21_strncpy(res, start, end - start);
      *(res + (end - start)) = '\0';
    }
  }

  return res;
}
