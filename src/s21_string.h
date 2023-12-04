#ifndef S21_STRING_H
#define S21_STRING_H

#define s21_NULL ((void *)0)

#include <stdio.h>
#include <stdlib.h>

typedef long unsigned int s21_size_t;

size_t s21_strlen(const char *str);
// kate
char *s21_strchr(const char *str, int c);
// kate strlen
int s21_strncmp(const char *str1, const char *str2, size_t n);
// kate
char *s21_strerror(int errnum); /*ЗАМЕНИТЬ НА НАШ SPRINTF!*/
// kate sprintf
int s21_memcmp(const void *str1, const void *str2, size_t n);
// kirill
char *s21_strncat(char *dest, const char *src, size_t n);
// kirill
char *s21_strncpy(char *dest, const char *src, size_t n);
// kirill
char *s21_strpbrk(const char *str1, const char *str2);
// kirill
char *s21_strrchr(const char *str, int c);
// kirill strlen
char *s21_strstr(const char *haystack, const char *needle);
// pelka strlen
char *s21_strtok(char *str, const char *delim);
// pelka strspn
void *s21_to_upper(const char *str);
// pelka strlen
void *s21_to_lower(const char *str);
// pelka strlen
void *s21_trim(const char *src, const char *trim_chars);
// pelka strlen strchr strncpy
void *s21_memchr(const void *str, int c, size_t n);
// den
void *s21_memcpy(void *dest, const void *src, size_t n);
// den
void *s21_memset(void *str, int c, size_t n);
// den
size_t s21_strcspn(const char *str1, const char *str2);
// den
void *s21_insert(const char *src, const char *str, size_t start_index);
// den

#endif
