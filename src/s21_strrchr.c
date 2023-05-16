#include "s21_string.h"

// Searches for the last occurrence of the character c (an unsigned char)
// in the string pointed to by the argument str
char *s21_strrchr(const char *str, int c) {
    char *rtnval = 0;

    do {
      if (*str == c)
        rtnval = (char*) str;
    } while (*str++);
    return (rtnval);
  }

