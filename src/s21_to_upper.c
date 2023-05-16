#include "s21_string.h"

// Returns a copy of string (str) converted to uppercase.
// In case of any error, return NULL
void *s21_to_upper(const char *str) {
    char *res = s21_NULL;
    if (str != s21_NULL) {
        s21_size_t n = s21_strlen(str);
        res = (char *) calloc(n+1, sizeof(char));
        if (res != s21_NULL) {
            for (s21_size_t i = 0; i < n; i++) {
                if (str[i] <= 'z' && str[i] >= 'a') {
                    res[i] = str[i] - ('a' - 'A');
                } else {
                    res[i] = str[i];
                }
            }
            res[n] = '\0';
        }
    }
    return res;
}
