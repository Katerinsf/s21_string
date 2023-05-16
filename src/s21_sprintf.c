#include "s21_string.h"

// Sends formatted output to a string pointed to, by str
int s21_sprintf(char *str, const char *format, ...) {
    char *ptr = str;
    int n_symb = 0;
    struct_format Params;
    va_list arg;
    va_start(arg, format);
    int flag_format = 0;

    while (*format) {
        if (*format == '%') {
            struct_init(&Params);
            do {
                format++;
                flag_format = format_init(*format, &Params);
            } while (flag_format == 1 && *format);

            if (flag_format == 2) {
                conversion(&str, format, &Params, arg);
            }
            if (flag_format == 0) {
                continue;
            }
            if (flag_format == 1) {
                continue;
            }
            format++;
        } else {
            *str = *format;
            format++;
            str++;
        }
    }
    *str = '\0';
    n_symb = str-ptr;
    va_end(arg);
    return n_symb;
}
