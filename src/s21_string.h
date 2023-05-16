#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h> 
#include <float.h>
#include <stdarg.h>
#include <limits.h>
#include <wchar.h>

#define s21_size_t unsigned long long
#define s21_NULL (void*)0
#define buff_size 5000
#define eps 1e-100


typedef struct struct_format {
    int flag_Plus;
    int flag_Minus;
    int flag_Space; 
    int flag_Width;
    int Width;
    int flag_Precision;
    int Precision;
    int Lenght_l;
    int Lenght_h;
} struct_format;

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strcmp(const char* str1, const char* str2);
char* s21_strcpy(char* dest, const char* src);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);



int s21_sprintf(char *str, const char *format, ...);
void conversion(char **str, const char *format, struct_format *Params, va_list arg);

void char_conv(char **str, struct_format *Params, char c);
void num_conv(char **str, struct_format *Params, char *str_arg);
void str_conv(char **str, struct_format *Params, char *str_arg);

char *int_in_str(long long int a, struct_format *Params);
char *double_in_str(double a, struct_format *Params);
char *uns_int_in_str(unsigned long long int a, struct_format *Params);

int format_init(char c, struct_format *Params);
void struct_init(struct_format *Params);
int format_check(char c, struct_format *Params);

int flag_check(char c);
int digit_check(char c);
int length_check(char c);
int specifier_check(char c);

int int_size(long long int a);
int double_size(double a);
double round_frac_ten(double a, int n);
int frac_size(double a);

int inf_nan_check(double a);
char *inf_nan_in_str(double a);


double int_double(double a);
void mirror(char *end, int *start, int n);
double round_frac(double a, int n);
char *lint_in_str(long int a, struct_format *Params);
char *sint_in_str(short int a, struct_format *Params);

#endif  //  SRC_S21_STRING_H_