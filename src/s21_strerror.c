#include "s21_errno.h"
#include "s21_string.h"

char *s21_strerror(int errnum) {
  if (errnum > s21_max || errnum < s21_min) {
    char *msg = (char *)malloc(100 * sizeof(char));
    sprintf(msg, "%s%d", s21_unknown, errnum);
    return msg;  // + errnum;
  } else {
    char *errors[] = s21_errors;
    return errors[errnum];
  }
}
