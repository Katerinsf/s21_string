#include "s21_string.h"

// Returns a new string in which all leading and trailing occurrences of
// a set of specified characters (trim_chars) from the given string (src) are removed.
// In case of any error, return NULL
void *s21_trim(const char *src, const char *trim_chars) {
    char *res = s21_NULL;
    if (src && *src && trim_chars) {
        s21_size_t n = s21_strlen(src);
        s21_size_t m = s21_strlen(trim_chars);
        s21_size_t i = 0, j = 0, k = 0;
        s21_size_t flag = 0;
        for (i = 0; i < n; i++) {
            flag = 0;
            for (k = 0; k < m; k++) {
                if (src[i] != trim_chars[k]) {
                    flag++;
                }
            }
            if (flag == m) {
                break;
            }
        }
        for (j = n-1; j != 0; j--) {
            flag = 0;
            for (k = 0; k < m; k++) {
                if (src[j] != trim_chars[k]) {
                    flag++;
                }
            }
            if (flag == m) {
                break;
            }
        }
        if (j - i > 0) {
            res = (char *)calloc(j-i+2, sizeof(char));
            for (s21_size_t p = 0; p < j-i+1; p++) {
                res[p] = src[i+p];
            }
            res[j-i+1] = '\0';
        }
    }
    return res;
}
