#include "s21_string.h"

// Adds an argument to the end of the string in the desired format
void conversion(char **str, const char *format, struct_format *Params, va_list arg) {
    if (*format == 'c') {
        char c = (char)va_arg(arg, int);
        char_conv(str, Params, c);
    }

    if (*format == 'd' || *format == 'i') {
        char *temp;
        if (Params->Lenght_l) {
            long int lint = va_arg(arg, long int);
            temp = int_in_str(lint, Params);
        } else if (Params->Lenght_h) {
            short int sint = (short int)va_arg(arg, int);
            temp = int_in_str(sint, Params);
        } else {
            int iint = va_arg(arg, int);
            temp = int_in_str(iint, Params);
        }
        num_conv(str, Params, temp);
        free(temp);
    }

    if (*format == 'f') {
        double dbl = va_arg(arg, double);
        if (inf_nan_check(dbl)) {
            char *temp = inf_nan_in_str(dbl);
            num_conv(str, Params, temp);
        } else {
            char *temp = double_in_str(dbl, Params);
            num_conv(str, Params, temp);
            free(temp);
        }
    }

    if (*format == 's') {
        char *string = va_arg(arg, char *);
        str_conv(str, Params, string);
    }

    if (*format == 'u') {
        char *temp;
        if (Params->Lenght_l) {
            unsigned long int lint = (unsigned long int)va_arg(arg, unsigned long int);
            temp = uns_int_in_str(lint, Params);
        } else if (Params->Lenght_h) {
            unsigned short int sint = (unsigned short int)va_arg(arg, unsigned int);
            temp = uns_int_in_str(sint, Params);
        } else {
            unsigned int iint = (unsigned)va_arg(arg, unsigned int);
            temp = uns_int_in_str(iint, Params);
        }
        num_conv(str, Params, temp);
        free(temp);
    }

    if (*format == '%') {
        char_conv(str, Params, '%');
    }
}


// Adds a character to string
void char_conv(char **str, struct_format *Params, char c) {
    if (Params->flag_Minus) {
        **str = c;
        (*str)++;
    }
    if (Params->flag_Width == 1) {
        for (int i = 0; i < Params->Width - 1; i++) {
            **str = ' ';
            (*str)++;
        }
    }
    if (!Params->flag_Minus) {
        **str = c;
        (*str)++;
    }
}

// Adds a number to string
void num_conv(char **str, struct_format *Params, char *str_arg) {
    if (Params->flag_Width) {
        s21_size_t len = s21_strlen(str_arg);
        s21_size_t size = (s21_size_t)Params->Width > len ? (s21_size_t)Params->Width : len;
        if (!Params->flag_Minus) {
            for (s21_size_t i = 0; i < size-len; i++) {
                **str = ' ';
                (*str)++;
            }
        }
        for (s21_size_t i = 0; i < len; i++) {
            **str = *str_arg;
            (*str)++;
            str_arg++;
        }
        if (Params->flag_Minus) {
            for (s21_size_t i = 0; i < size-len; i++) {
                **str = ' ';
                (*str)++;
            }
        }
    } else {
        for (s21_size_t i = 0; i < s21_strlen(str_arg); i++) {
            **str = *(str_arg+i);
            (*str)++;
        }
    }
}

// Adds a string to string
void str_conv(char **str, struct_format *Params, char *str_arg) {
    s21_size_t len;
    if (Params->flag_Precision && (s21_size_t)Params->Precision < s21_strlen(str_arg)) {
        len = (s21_size_t)Params->Precision;
    } else {
        len = s21_strlen(str_arg);
    }
    s21_size_t size = ((s21_size_t)Params->Width > len && Params->flag_Width) ?
      (s21_size_t)Params->Width : len;
    if (!Params->flag_Minus) {
        for (s21_size_t i = 0; i < size-len; i++) {
            **str = ' ';
            (*str)++;
        }
    }
    for (s21_size_t i = 0; i < len; i++) {
        **str = *str_arg;
        (*str)++;
        str_arg++;
    }
    if (Params->flag_Minus) {
        for (s21_size_t i = 0; i < size-len; i++) {
            **str = ' ';
            (*str)++;
        }
    }
}


// Converts integer to string
char *int_in_str(long long int a, struct_format *Params) {
    int n = 1;  // string and number length
    int k = 1;  // number of digits in a number
    char *str = (char *)calloc(n, sizeof(char));
    if (a < 0) {
        str[n-1] = '-';
        n++;
        str = (char *)realloc(str, (n)*sizeof(char));
        a *= -1;
    } else {
        if (Params->flag_Plus && a != 0) {
            str[n-1] = '+';
            n++;
            str = (char *)realloc(str, (n)*sizeof(char));
        }
        if (Params->flag_Space && a != 0 && !Params->flag_Plus) {
            str[n-1] = ' ';
            n++;
            str = (char *)realloc(str, (n)*sizeof(char));
        }
    }
    k = int_size(a);
    if (Params->flag_Precision) {
        int j = Params->Precision > k ? Params->Precision : k;
        j -= k;
        for (int i = 0; i < j; i++) {
            str[n-1] = '0';
            n++;
            str = (char *)realloc(str, (n)*sizeof(char));
        }
    }
    str = (char *)realloc(str, (n+k)*sizeof(char));
    n += k;
    str[n-1]  = '\0';
    n--;
    while (k) {
        str[n-1] = (char)llabs((a%10)) + '0';
        a/=10;
        k--;
        n--;
    }
    return str;
}

// Converts unsigned integer to string
char *uns_int_in_str(unsigned long long int a, struct_format *Params) {
    int n = 1;  // string and number length
    int k = 1;  // number of digits in a number
    char *str = (char *)calloc(n, sizeof(char));

    k = double_size((double)a);
    if (Params->flag_Precision) {
        int j = Params->Precision > k ? Params->Precision : k;
        j -= k;
        for (int i = 0; i < j; i++) {
            str[n-1] = '0';
            n++;
            str = (char *)realloc(str, (n)*sizeof(char));
        }
    }

    str = (char *)realloc(str, (n+k)*sizeof(char));
    n += k;
    str[n-1]  = '\0';
    n--;
    while (k) {
        str[n-1] = (char)(a%10) + '0';
        a/=10;
        k--;
        n--;
    }
    return str;
}

// Converts double to string
char *double_in_str(double a, struct_format *Params) {
    double b;  // integer part of numbers
    double c;  // fractional part of numbers
    int n = 1;  // string and number length
    int k = 1;  // number of digits in integer part of numbers
    int k2 = 1;  // number of digits in integer part of numbers
    int f = 1;  // number of digits in fractional part of numbers
    char *str = (char *)calloc(n, sizeof(char));
    int flag = 0;  // flag for sign

    if (a < 0) {
        str[n-1] = '-';
        n++;
        a *= -1;
        flag = 1;
    } else {
        if (Params->flag_Plus && a > 0) {
            str[n-1] = '+';
            n++;
            flag = 1;
        }
        if (Params->flag_Space && a > 0) {
            str[n-1] = ' ';
            n++;
            flag = 1;
        }
    }
    c = modf(a, &b);
    k = double_size(a);
    n += k;
    if (Params->flag_Precision == 0) {
        f = 6;
        n += f+1;
        c = round_frac_ten(c, f);
    } else {
        if (Params->Precision != 0) {
            f = Params->Precision;
            n += f+1;
            c = round_frac_ten(c, f);
        } else {
            c = round_frac_ten(c, f);
            f = 0;
        }
    }
    if (c >= pow(10, f)) {
        b++;
        if (b >= pow(10, k)) {
            n++;
            k++;
        }
    }
    k2 = k;
    str = (char *)realloc(str, n*sizeof(char));
    str[n-1]  = '\0';
    n--;
    while (k) {
        str[k-1+flag] = (char)(trunc(fmod(b, 10))) + '0';
        b = trunc((b)/10);
        k--;
    }
    k = k2;
    str[k+flag] = f ? '.' : '\0';
    while (f) {
        str[k+flag+f] = (char)(c - trunc(c/10)*10) + '0';
        c/=10;
        f--;
    }
    return str;
}


// Zero initialization of a structure
void struct_init(struct_format *Params) {
    Params->flag_Plus = 0;
    Params->flag_Minus = 0;
    Params->flag_Space = 0;
    Params->flag_Width = 0;
    Params->Width = 0;
    Params->flag_Precision = 0;
    Params->Precision = 0;
    Params->Lenght_l = 0;
    Params->Lenght_h = 0;
}

// Specifies format options
int format_init(char c, struct_format *Params) {
    int res = 0;
    if (flag_check(c)) {
        if (c == '-') {
            Params->flag_Minus = 1;
        }
        if (c == '+') {
            Params->flag_Plus = 1;
        }
        if (c == ' ') {
            Params->flag_Space = 1;
        }
        res = 1;
    }
    if (digit_check(c) == 1) {
        if (Params->flag_Precision == 0) {
            Params->Width = Params->Width * 10 + (int)c - 48;
            Params->flag_Width = 1;
        } else {
            Params->Precision = Params->Precision * 10 + (int)c - 48;
        }
        res = 1;
    }
    if (c == '.') {
        Params->flag_Precision = 1;
        res = 1;
    }
    if (length_check(c)) {
        if (c == 'h') {
            Params->Lenght_h = 1;
        }
        if (c == 'l') {
            Params->Lenght_l = 1;
        }
        res = 1;
    }
    if (specifier_check(c)) {
        res = 2;
    }
    return res;
}

// Checks flags
int flag_check(char c) {
    int res = 0;
    if (c == '-' || c == '+' || c == ' ') {
        res = 1;
    }
    return res;
}

// Checks number
int digit_check(char c) {
    int res = 0;
    if (((int)c >= 48 && (int)c <= 57)) {
        res = 1;
    }
    return res;
}

// Checks length
int length_check(char c) {
    int res = 0;
    if (c == 'h' || c == 'l' || c == 'L') {
        res = 1;
    }
    return res;
}

// Checks specifier
int specifier_check(char c) {
    int res = 0;
    if (c == 'c' || c == 'd' || c == 'i' || c == 'f' || c == 's' || c == 'u' || c == '%') {
            res = 1;
    }
    return res;
}


// Searches for the number of digits in an integer
int int_size(long long int a) {
    int n = 1;
    while (a/10) {
        n++;
        a /= 10;
    }
    return n;
}

// Searches for the number of digits in integer part of double
int double_size(double a) {
    int n = 1;
    while ((int)(a/10)) {
        n++;
        a /= 10;
    }
    return n;
}

// Rounds the fractional part with the specified precision
double round_frac_ten(double a, int n) {
    while (n) {
        a *= 10;
        n--;
    }
    a = round(a);
    return a;
}

// Searches for the number of digits in fractional part of double
int frac_size(double a) {
    int n = 0;
    while ((long long)(a*10)%10 != 0) {
        n++;
        a*=10;
        a -= trunc(a);
    }
    return n;
}


// Checks inf
int inf_nan_check(double a) {
    int res = (a == -INFINITY || a == INFINITY || a == NAN) ? 1 : 0;
    return res;
}

// Creates a string to output inf
char *inf_nan_in_str(double a) {
    char *str;
    if (a == -INFINITY) {
        str = "-inf";
    }
    if (a == INFINITY) {
        str = "inf";
    }
    if (a == NAN) {
        str = "nan";
    }
    return str;
}
