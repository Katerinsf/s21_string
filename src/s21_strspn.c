#include "s21_string.h"

// Calculates the length of the initial segment of str1
// which consists entirely of characters in str2
s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t n;
    const char* p;
    for (n=0; *str1; str1++, n++) {
      for (p=str2; *p && *p != *str1; p++) {
      }
      if (!*p)
        break;
    }
    return n;
  }
