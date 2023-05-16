#include "s21_string.h"

// Returns a new string in which a specified string (str) is inserted at
// a specified index position (start_index) in the given string (src).
// In case of any error, return NULL
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *res = s21_NULL;
    if (src && str) {
        s21_size_t n = s21_strlen(src);
        if (start_index <= n) {
            s21_size_t m = s21_strlen(str);
            res = (char *) calloc(n+m+1, sizeof(char));
            if (res != s21_NULL) {
                s21_size_t i;
                for (i = 0; i < start_index; i++) {
                    res[i] = src[i];
                }
                for (i = 0; i < m; i++) {
                    res[start_index+i] = str[i];
                }
                for (i = start_index; i < n; i++) {
                    res[m+i] = src[i];
                }
                res[n+m] = '\0';
            }
        }
    }
    return res;
}
