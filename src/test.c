#include <check.h>
#include <string.h>

#include "./s21_string.h"

START_TEST(strtok_1) {
    char str4_1[] = "/testing/with/original/string.h/";
    char str4_2[] = "/testing/with/original/string.h/";
    char del4[3] = "/";
    char * nstr_1, * nstr_2;
    nstr_1 = strtok(str4_1, del4);
    nstr_2 = s21_strtok(str4_2, del4);
    while (nstr_1 != s21_NULL) {
        ck_assert_pstr_eq(nstr_1, nstr_2);
        nstr_1 = strtok(s21_NULL, del4);
        nstr_2 = s21_strtok(s21_NULL, del4);
    }
} END_TEST

START_TEST(strtok_2) {
    char str4_1[] = ". . testing with original string.h";
    char str4_2[] = ". . testing with original string.h";
    char del4[3] = ". ";
    char * nstr_1, * nstr_2;
    nstr_1 = strtok(str4_1, del4);
    nstr_2 = s21_strtok(str4_2, del4);
    while (nstr_1 != s21_NULL) {
        ck_assert_pstr_eq(nstr_1, nstr_2);
        nstr_1 = strtok(s21_NULL, del4);
        nstr_2 = s21_strtok(s21_NULL, del4);
    }
} END_TEST

START_TEST(strtok_3) {
    char str4_1[] = "testing with original string.h";
    char str4_2[] = "testing with original string.h";
    char del4[3] = ". ";
    char * nstr_1, * nstr_2;
    nstr_1 = strtok(str4_1, del4);
    nstr_2 = s21_strtok(str4_2, del4);
    while (nstr_1 != s21_NULL) {
        ck_assert_pstr_eq(nstr_1, nstr_2);
        nstr_1 = strtok(s21_NULL, del4);
        nstr_2 = s21_strtok(s21_NULL, del4);
    }
} END_TEST

START_TEST(up_1) {
    char *text = "Hello,\nCat!\0!!\n";
    char *text_res = "HELLO,\nCAT!\0!!\n";

    char *str = (char*)s21_to_upper(text);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(up_2) {
    char *text = "\0-aa";
    char *text_res = "\0";

    char *str = (char*)s21_to_upper(text);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(up_3) {
    char *text = s21_NULL;
    char *text_res = s21_NULL;

    char *str = (char*)s21_to_upper(text);
    ck_assert_ptr_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(low_1) {
    char *text = "Hello,\nCat!\0!!\n";
    char *text_res = "hello,\ncat!\0!!\n";

    char *str = (char*)s21_to_lower(text);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(low_2) {
    char *text = "\0-AA";
    char *text_res = "\0";

    char *str = (char*)s21_to_lower(text);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(low_3) {
    char *text = s21_NULL;
    char *text_res = s21_NULL;

    char *str = (char*)s21_to_lower(text);
    ck_assert_ptr_eq(str, text_res);
    free(str);
} END_TEST



START_TEST(insert_1) {
    char *text1 = "12345", *text2 = "---";
    int n = 2;
    char *text_res = "12---345";

    char *str = (char*)s21_insert(text1, text2, n);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(insert_2) {
    char *text1 = "\0", *text2 = "---";
    int n = 0;
    char *text_res = "---";

    char *str = (char*)s21_insert(text1, text2, n);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(insert_3) {
    char *text1 = "---", *text2 = "\0";
    int n = 0;
    char *text_res = "---";

    char *str = (char*)s21_insert(text1, text2, n);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(insert_4) {
    char *text1 = s21_NULL, *text2 = "---";
    int n = 0;
    char *text_res = s21_NULL;

    char *str = (char*)s21_insert(text1, text2, n);
    ck_assert_ptr_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(insert_5) {
    char *text1 = "00", *text2 = "---";
    int n = 8;
    char *text_res = s21_NULL;

    char *str = (char*)s21_insert(text1, text2, n);
    ck_assert_ptr_eq(str, text_res);
    free(str);
} END_TEST


START_TEST(trim_1) {
    char *text1 = "#*/*#/Myau!//!*/#";
    char *text2 = "#/*";
    char *text_res = "Myau!//!";

    char *str = (char*)s21_trim(text1, text2);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(trim_2) {
    char *text1 = "   2232fvjhfj1234   ";
    char *text2 = " 1 2 3 4 ";
    char *text_res = "fvjhfj";

    char *str = (char*)s21_trim(text1, text2);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

START_TEST(trim_3) {
    char *text1 = "   2232fvjhfj1234   ";
    char *text2 = s21_NULL;
    char *text_res = s21_NULL;

    char *str = (char*)s21_trim(text1, text2);
    ck_assert_ptr_eq(str, text_res);
//    free(str);
} END_TEST

START_TEST(trim_4) {
    char *text1 = s21_NULL;
    char *text2 = " 1 2 3 4 ";
    char *text_res = s21_NULL;

    char *str = (char*)s21_trim(text1, text2);
    ck_assert_ptr_eq(str, text_res);
//    free(str);
} END_TEST

START_TEST(trim_5) {
    char *text1 = "   2232fvjhfj1234   ";
    char *text2 = "\0";
    char *text_res = "   2232fvjhfj1234   ";

    char *str = (char*)s21_trim(text1, text2);
    ck_assert_str_eq(str, text_res);
    free(str);
} END_TEST

// START_TEST(trim_6) {
//    char *text1 = "\0";
//    char *text2 = "   2232fvjhfj1234   ";
//    char *text_res = "\0";
//
//    char *str = (char*)s21_trim(text1, text2);
//    ck_assert_str_eq(str, text_res);
//    free(str);
//} END_TEST

START_TEST(test_s21_strcspn) {
    const char *str1 = "askjdnka";
    const char *str2 = "sjhdbf";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg1) {
    const char *str1 = "\n";
    const char *str2 = " \n";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg2) {
    const char *str1 = "\t";
    const char *str2 = " \t";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg3) {
    const char *str1 = " \n";
    const char *str2 = "\n";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_neg4) {
    const char *str1 = " \t";
    const char *str2 = "\t";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_zero1) {
    const char *str1 = " \0";
    const char *str2 = "\0";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strcspn_zero2) {
    const char *str1 = "\0";
    const char *str2 = " \0";
    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strerror) {
    int errnum = 5;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

// START_TEST(test_s21_strerror_neg) {
//    int errnum = -50;
//    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
//}
// END_TEST

START_TEST(test_s21_strerror_zero) {
    int errnum = 0;
    ck_assert_str_eq(strerror(errnum), s21_strerror(errnum));
}
END_TEST

START_TEST(test_s21_strpbrk) {
    const char *str1 = "askjdnka";
    const char *str2 = "sjhdbf";
    ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg1) {
    const char *str1 = "\n";
    const char *str2 = " \n";

    ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg2) {
    const char *str1 = "\t";
    const char *str2 = " \t";
    ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg3) {
    const char *str1 = " \n";
    const char *str2 = "\n";
    ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strpbrk_neg4) {
    const char *str1 = " \t";
    const char *str2 = "\t";
    ck_assert_int_eq(*strpbrk(str1, str2), *s21_strpbrk(str1, str2));
}
END_TEST

START_TEST(test_s21_strlen) {
    const char *str = "test";
    ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

// ------------------------ memchr ----------------------
START_TEST(memchr_1) {
    char str[] = "1234567890";
    char c = '0';
    s21_size_t n = 10;

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
} END_TEST

START_TEST(memchr_2) {
    char str[] = "Hello w\0orld\0";
    char c = 'r';
    s21_size_t n = 10;

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
} END_TEST

START_TEST(memchr_3) {
    char str[] = "Hello world";
    char c = ' ';
    s21_size_t n = 10;

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
} END_TEST

// START_TEST(memchr_4) {
//    char str[] = "a\n\0";
//    char c = ' ';
//    s21_size_t n = 5;
//
//    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
// } END_TEST

START_TEST(memchr_5) {
    char str[] = "\0";
    char c = ' ';
    s21_size_t n = 2;

    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
} END_TEST

START_TEST(s21_memchr_test01) {
    char *s1 = "";
    fail_unless(memchr(s1, 'x', 0) == s21_memchr(s1, 'x', 0));
}
END_TEST

START_TEST(s21_memchr_test02) {
    char *s2 = "abcdefabcdef";
    fail_unless(memchr(s2, 'y', 0) == s21_memchr(s2, 'y', 0));
}
END_TEST

START_TEST(s21_memchr_test03) {
    char *s3 = "11111111111111111111";
    fail_unless((char *)memchr(s3, '1', 20) - s3 == (char *)s21_memchr(s3, '1', 20) - s3);
}
END_TEST

START_TEST(s21_memchr_test04) {
    char *s2 = "abcdefabcdef";
    fail_unless((char *)memchr(s2, 'a', 1) - s2 == (char *)s21_memchr(s2, 'a', 1) - s2);
}
END_TEST

START_TEST(s21_memchr_test05) {
    char *s2 = "abcdefabcdef";

    fail_unless((char *)memchr(s2, 'd', 12) - s2 == (char *)s21_memchr(s2, 'd', 12) - s2);
}
END_TEST

START_TEST(s21_memchr_test06) {
    char *s2 = "abcdefabcdef";
    fail_unless((char *)memchr(s2, 'f', 12) - s2 == (char *)s21_memchr(s2, 'f', 12) - s2);
}
END_TEST

START_TEST(s21_memchr_test07) {
    char *s2 = "abcdefabcdef";
    fail_unless(memchr(s2, 'd', 2) == s21_memchr(s2, 'd', 2));
}
END_TEST


// ------------------------ memcmp ----------------------
START_TEST(memcmp_1) {
    char str1[] = "1234567890";
    char str2[] = "1234567890";
    s21_size_t n = 10;

    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
} END_TEST

// START_TEST(memcmp_2) {
//    char str1[] = "Hello w\0orld\0";
//    char str2[] = "Hello w\0old\0";
//    s21_size_t n = 14;
//
//    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
//} END_TEST

// START_TEST(memcmp_3) {
//    char str1[] = "Hello world";
//    char str2[] = "world";
//    s21_size_t n = 11;
//
//    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
// } END_TEST

// START_TEST(memcmp_4) {
//    char str1[] = "a\n\0";
//    char str2[] = "a\n\0";
//    s21_size_t n = 5;
//
//    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
// } END_TEST

// START_TEST(memcmp_5) {
//    char str1[] = "\0";
//    char str2[] = "\0\n";
//    s21_size_t n = 5;
//
//    ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
// } END_TEST

START_TEST(s21_memcmp_test01) {
    char *s1 = "a";
    char *s2 = "a";

    fail_unless(memcmp(s1, s2, 1) == s21_memcmp(s1, s2, 1));
}
END_TEST

START_TEST(s21_memcmp_test02) {
    char *s1 = "a";
    char *s3 = "b";

    fail_unless(memcmp(s1, s3, 1) == s21_memcmp(s1, s3, -1));
}
END_TEST

START_TEST(s21_memcmp_test03) {
    char *s3 = "b";
    char *s4 = "c";

    fail_unless(memcmp(s4, s3, 1) == s21_memcmp(s4, s3, 1));
}
END_TEST


// ------------------------ memcpy ----------------------
START_TEST(memcpy_1) {
    char str0[100] = "---";
    char str1[100] = "---";
    char str2[100] = "0123456789";
    s21_size_t n = 9;

    ck_assert_str_eq(s21_memcpy(str1, str2, n), memcpy(str0, str2, n));
} END_TEST

START_TEST(memcpy_2) {
    char str0[100] = "-1-";
    char str1[100] = "-2-";
    char str2[100] = "Hello w\0old\0";
    s21_size_t n = 15;

    ck_assert_str_eq(s21_memcpy(str1, str2, n), memcpy(str0, str2, n));
} END_TEST

START_TEST(memcpy_3) {
    char str0[100] = "-1-";
    char str1[100] = "-2-";
    char str2[100] = "Hello world\0hello";
    s21_size_t n = 10;

    ck_assert_str_eq(s21_memcpy(str1, str2, n), memcpy(str0, str2, n));
} END_TEST

START_TEST(memcpy_4) {
    char str0[100] = "---";
    char str1[100] = "ABC\n\0";
    char str2[100] = "ABC\n\0A";
    char str3[100] = "---";
    s21_size_t n = 5;

    ck_assert_str_eq(s21_memcpy(str0, str1, n), memcpy(str3, str2, n));
} END_TEST

START_TEST(memcpy_5) {
    char str0[100] = "---";
    char str1[100] = "\0";
    char str2[100] = "\0\n";
    char str3[100] = "---";
    s21_size_t n = 3;

    ck_assert_str_eq(s21_memcpy(str0+1, str2, n), memcpy(str3+1, str1, n));
} END_TEST

START_TEST(s21_memcpy_test01) {
    char s1[5] = "a";
    char s2[5] = "a";
    char s3[2] = "b";

    ck_assert_str_eq(s21_memcpy(s1, s3, 1), memcpy(s2, s3, 1));
}
END_TEST

// ------------------------ memmove ----------------------
START_TEST(memmove_1) {
    char str0[100] = "12345";
    char str1[100] = "12345";
    s21_size_t n = 3;

    ck_assert_str_eq(s21_memmove(&str1[1], &str1[2], n), memmove(&str0[1], &str0[2], n));
} END_TEST

START_TEST(memmove_2) {
    char str0[100] = "---";
    char str1[100] = "Hello w\0orld\0";
    char str2[100] = "Hello w\0orld\0";
    char str3[100] = "---";
    s21_size_t n = 15;

    ck_assert_str_eq(s21_memmove(str0, str1, n), memmove(str3, str2, n));
} END_TEST

START_TEST(memmove_3) {
    char str0[100] = "---";
    char str1[100] = "Hello world\0";
    char str2[100] = "Hello world\0hello";
    char str3[100] = "---";
    s21_size_t n = 18;

    ck_assert_str_eq(s21_memmove(str0, str1, n), memmove(str3, str2, n));
} END_TEST

START_TEST(memmove_4) {
    char str0[100] = "---";
    char str1[100] = "ABC\n\0A";
    char str2[100] = "ABC\n\0A";
    char str3[100] = "---";
    s21_size_t n = 10;

    ck_assert_str_eq(s21_memmove(str0, str1, n), memmove(str3, str2, n));
} END_TEST

START_TEST(memmove_5) {
    char str0[100] = "1--";
    char str1[100] = "\0";
    char str2[100] = "\0\n";
    char str3[100] = "---";
    s21_size_t n = 1;

    ck_assert_str_eq(s21_memmove(str0, str1, n), memmove(str3, str2, n));
} END_TEST

START_TEST(s21_memmove_test01) {
    char str0[100];
    char str1[100] = "Hello";
    char str2[100] = "Hello";
    char str3[100];
    s21_size_t n = 18;
    // s21_memmove(str0, str1, 18);
    // memmove(str3, str2, 18);

    ck_assert_str_eq(s21_memmove(str0, str1, n), memmove(str3, str2, n));
}
END_TEST

START_TEST(d_simple) {
    char str1[buff_size] = "Kitty", str2[buff_size] = "Kitty";
    char *format = "Cats have %d lives!";
    int value = 7;

    ck_assert_int_eq(s21_sprintf(str1+2, format, value), sprintf(str2+2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(i_simple) {
    char str1[buff_size], str2[buff_size];
    char *format = "I will have %i cats!";
    int value = 40;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_width) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10d!";
    int value = -101;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(i_width) {
    char str1[buff_size], str2[buff_size];
//    char *format = "Myau, cat number %10i!";
    int value = 101;

    ck_assert_int_eq(s21_sprintf(str1, "Myau, cat number %10i!", value),
    sprintf(str2, "Myau, cat number %10i!", value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_width_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-25d!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(i_width_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-25i!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_width_plus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%+25d!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(i_width_plus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%+25i!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_width_space) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2d!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(i_width_space) {
    char str1[buff_size], str2[buff_size];
//    char *format = "Cats is cool!% 2i!";
    int value = -777;

    ck_assert_int_eq(s21_sprintf(str1, "Cats is cool!% 2i!", value),
                     sprintf(str2, "Cats is cool!% 2i!", value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_width_plus_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-+25d!";
    int value = -777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(i_width_plus_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-+25i!";
    int value = -777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

// ------------------------ f -------------------------
START_TEST(f_simple) {
    char str1[buff_size] = "Kitty", str2[buff_size] = "Kitty";
    char *format = "Cats have %f lives!";
    double value = 7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_1) {
    char str1[buff_size], str2[buff_size];
    char *format = "I will have %3f cats!";
    double value = 7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_2) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10f!";
    double value = -7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %-20f!";
    double value = 7.123456789;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_space) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have % f lives!";
    double value = 7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_spec_1) {
    char str1[buff_size], str2[buff_size];
    char *format = "I will have %3.8f cats!";
    double value = 7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_spec_2) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10.5f!";
    double value = -7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_minus_plus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %-+20f!";
    double value = 7.001;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_minus_plus_spec) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %-+30.15f lives!";
    double value = -7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_spec_l) {
    char str1[buff_size], str2[buff_size];
    char *format = "I will have %3.8lf cats!";
    double value = -7.1234567;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_spec_3) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10.0f!";
    double value = 99.9999999;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_plus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %+20f!";
    double value = -7.001;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_spec_4) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10.1f!";
    double value = 99999998.9999999999;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

// ----------------- u ------------------

START_TEST(u_simple) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %u lives!";
    int value = 7;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10u!";
    int value = -101;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-25u!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width_plus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%+25u!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width_space) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2u!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width_space_prec) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2.5u!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width_plus_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-+25u!";
    int value = -777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width_space_prec_h) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2.5hu!";
    short int value = -777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_width_space_prec_l) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2.5lu!";
    long int value = -777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST


// ------------------------ c ----------------------
START_TEST(c_simple_1) {
    char str1[buff_size] = "Kitty", str2[buff_size] = "Kitty";
    char *format = "Cats have %c lives!";
    char value = '7';

    ck_assert_int_eq(s21_sprintf(str1+4, format, value), sprintf(str2+4, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_simple_2) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %c lives!";
    int value = 7;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_width) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10c!";
    int value = 101;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_width_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-25c!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_width_plus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%+25c!";
    char value = '$';

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_width_space) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2c!";
    char value = '&';

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_width_space_prec_1) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2.5c!";
    int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_width_space_prec_2) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-2.5c!";
    long int value = 777;

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
}

START_TEST(c_width_plus_minus) {
        char str1[buff_size], str2[buff_size];
        char *format = "Cats is cool!%-+25c!";
        int value = -777;

        ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
        ck_assert_str_eq(str1, str2);
}

// START_TEST(c_width_plus_minus_l) {
//     char str1[buff_size], str2[buff_size];
//     char *format = "Cats is cool!%-+25lc!";
//     int value = -777;

//     ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
//     ck_assert_str_eq(str1, str2);
// }



// --------------------- s ------------------------
START_TEST(s_simple) {
        char str1[buff_size], str2[buff_size];
        char *format = "Cats have %s lives!";
        char *value = "seven";

        ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
        ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s_width) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10s!";
    char *value = "101";

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s_width_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-25s!";
    char *value = "Myau";

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s_width_plus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%+25s!";
    char *value = "Myau";

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s_width_space) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2s!";
    char *value = "Myau";

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s_space_prec) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% .25s!";
    char *value = "Myau";

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s_width_plus_minus) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-+25s!";
    char *value = "Myau";

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s_width_space_prec) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!% 2.5s!";
    char *value = "Myau";

    ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
    ck_assert_str_eq(str1, str2);
} END_TEST

// START_TEST(s_width_space_prec_l) {
//     char str1[buff_size], str2[buff_size];
//     char *format = "Cats is cool!% 2.5ls!";
//     char *value = "Myau";

//     ck_assert_int_eq(s21_sprintf(str1, format, value), sprintf(str2, format, value));
//     ck_assert_str_eq(str1, str2);
// } END_TEST


// ----------------- % ----------------
START_TEST(f_width_pros) {
    char str1[buff_size], str2[buff_size];
//    char *format = "Myau, cat number %%!";

    ck_assert_int_eq(s21_sprintf(str1, "Myau, cat number %%!"), sprintf(str2, "Myau, cat number %%!"));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_width_pros2) {
    char str1[buff_size], str2[buff_size];
//    char *format = "Myau, cat number %%%%!";

    ck_assert_int_eq(s21_sprintf(str1, "Myau, cat number %%%%!"), sprintf(str2, "Myau, cat number %%%%!"));
    ck_assert_str_eq(str1, str2);
} END_TEST

// START_TEST(f_width_pros3) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %10%";
//
//    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(f_width_pros4) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %-10%";
//
//    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(f_width_pros5) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have % 10.5%";
//
//    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(f_width_pros6) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %+-10.5%";
//
//    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));
//    ck_assert_str_eq(str1, str2);
//} END_TEST


// ------------------- all -------------------
// START_TEST(d_s_f_c_1) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %d lives!%s!%%%c%f%%";
//    int value1 = -7;
//    char *value2 = "Myau";
//    char value3 = '7';
//    double value4 = 7.1234567;
//
//
//    ck_assert_int_eq(s21_sprintf(str1, "Cats have %d lives!%s!%%%c%f%%", -7, "Myau", '7', 7.1234567),
//                     sprintf(str2, "Cats have %d lives!%s!%%%c%f%%", -7, "Myau", '7', 7.1234567));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// --------------------- min max ----------------

START_TEST(d_imin) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %d lives!";
    // int value = INT_MIN;

    ck_assert_int_eq(s21_sprintf(str1, format, INT_MIN), sprintf(str2, format, INT_MIN));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_imax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %d lives!";
    // int value = INT_MAX;

    ck_assert_int_eq(s21_sprintf(str1, format, INT_MAX), sprintf(str2, format, INT_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_simin) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %hd lives!";
    // short int value = SHRT_MIN;

    ck_assert_int_eq(s21_sprintf(str1, format, SHRT_MIN), sprintf(str2, format, SHRT_MIN));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_simax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %hd lives!";
    // short int value = SHRT_MAX;

    ck_assert_int_eq(s21_sprintf(str1, format, SHRT_MAX), sprintf(str2, format, SHRT_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_limin) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %ld lives!";
    // short int value = SHRT_MIN;

    ck_assert_int_eq(s21_sprintf(str1, format, LONG_MIN), sprintf(str2, format, LONG_MIN));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(d_limax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %ld lives!";
    // short int value = SHRT_MAX;

    ck_assert_int_eq(s21_sprintf(str1, format, LONG_MAX), sprintf(str2, format, LONG_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST


START_TEST(c_smin) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %c lives!";
    // char value = '7';
    ck_assert_int_eq(s21_sprintf(str1, format, SCHAR_MIN), sprintf(str2, format, SCHAR_MIN));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_smax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %c lives!";
    // char value = '7';
    ck_assert_int_eq(s21_sprintf(str1, format, SCHAR_MAX), sprintf(str2, format, SCHAR_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_min) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %c lives!";
    // char value = '7';
    ck_assert_int_eq(s21_sprintf(str1, format, SCHAR_MIN), sprintf(str2, format, CHAR_MIN));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_max) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %c lives!";
    // char value = '7';
    ck_assert_int_eq(s21_sprintf(str1, format, SCHAR_MAX), sprintf(str2, format, CHAR_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(c_umax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %c lives!";
    // char value = '7';
    ck_assert_int_eq(s21_sprintf(str1, format, UCHAR_MAX), sprintf(str2, format, UCHAR_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST


START_TEST(u_imax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %u lives!";
    // int value = 7;
    ck_assert_int_eq(s21_sprintf(str1, format, UINT_MAX), sprintf(str2, format, UINT_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_simax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %hu lives!";
    // int value = 7;
    ck_assert_int_eq(s21_sprintf(str1, format, USHRT_MAX), sprintf(str2, format, USHRT_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(u_limax) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %lu lives!";
    // int value = 7;
    ck_assert_int_eq(s21_sprintf(str1, format, ULONG_MAX), sprintf(str2, format, ULONG_MAX));
    ck_assert_str_eq(str1, str2);
} END_TEST


START_TEST(f_inf1) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %f lives!";
    // double value = INFINITY;
    ck_assert_int_eq(s21_sprintf(str1, format, INFINITY), sprintf(str2, format, INFINITY));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(f_inf2) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats have %f lives!";
    // double value = INFINITY;
    ck_assert_int_eq(s21_sprintf(str1, format, -INFINITY), sprintf(str2, format, -INFINITY));
    ck_assert_str_eq(str1, str2);
} END_TEST



// --------------- error ----------------
// START_TEST(err1) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %www lives!";
//
//    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(err2) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %";
//
//    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(err3) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %12l";
//
//    ck_assert_int_eq(s21_sprintf(str1, "Cats have %12l"), sprintf(str2, "Cats have %12l"));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(d_s_f_c_err_1) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %d lives!%s!%%%c%%";
//    int value1 = -7;
//    char *value2 = "Myau";
//    char value3 = '7';
//    double value4 = 7.1234567;
//    ck_assert_int_eq(s21_sprintf(str1, format, value1, value2, value3, value4),
//                     sprintf(str2, format, value1, value2, value3, value4));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(d_s_f_c_err_2) {
//     char str1[buff_size], str2[buff_size];
//     char *format = "Cats have %d lives!%s!%%%d%%";
//     int value1 = -7;
//     char *value2 = "Myau";
//     // char value3 = '7';
//     // double value4 = 7.1234567;
//     ck_assert_int_eq(s21_sprintf(str1, format, value1, value2),
//         sprintf(str2, format, value1, value2));
//     ck_assert_str_eq(str1, str2);
// } END_TEST

// START_TEST(d_s_f_c_change) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %d lives!!%%%c%f%%";
//    int value1 = -7;
//    char value3 = '7';
//    double value4 = 7.1234567;
//
//
//    ck_assert_int_eq(s21_sprintf(str1, format, value3, value4, value1),
//                     sprintf(str2, format, value3, value4, value1));
//    ck_assert_str_eq(str1, str2);
//} END_TEST

// START_TEST(d_s_f_c_more_max) {
//    char str1[buff_size], str2[buff_size];
//    char *format = "Cats have %d lives!!%%%c%f%%%u";
//    // int value1 = -71111111111111;
//    // char value2 = 11111111;
//    // double value4 = 3.5e30;
//
//    ck_assert_int_eq(s21_sprintf(str1, format, 71111111111111, 11111111, 3.5e20, -71111111111111),
//                     sprintf(str2, format, 71111111111111, 11111111, 3.5e20, -71111111111111));
//    ck_assert_str_eq(str1, str2);
//} END_TEST



START_TEST(i_width_16x) {
    char str1[buff_size], str2[buff_size];
    char *format = "Myau, cat number %10i!";
    // int value = 101;

    ck_assert_int_eq(s21_sprintf(str1, format, 0x1F), sprintf(str2, format, 0x1F));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(i_width_plus_minus_16x) {
    char str1[buff_size], str2[buff_size];
    char *format = "Cats is cool!%-+25i!";
    // int value = -777;

    ck_assert_int_eq(s21_sprintf(str1, format, 0x1F), sprintf(str2, format, 0x1F));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_strcmp_test01) {
    char str1[20] = "abc";
    char str2[20] = "abc";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// START_TEST(s21_strcmp_test02) {
//    char str1[20] = "abc";
//    char str3[20] = "aba";
//
//    ck_assert_int_eq(s21_strcmp(str1, str3), strcmp(str1, str3));
//}
// END_TEST

START_TEST(s21_strcmp_test03) {
    char str1[20] = "abc";
    char str4[20] = "abd";

    ck_assert_int_eq(s21_strcmp(str1, str4), strcmp(str1, str4));
}
END_TEST

// START_TEST(s21_strcmp_test04) {
//    char str1[20] = "abc";
//    char str5[20] = "ab";
//
//    ck_assert_int_eq(s21_strcmp(str1, str5), strcmp(str1, str5));
//}
// END_TEST

// START_TEST(s21_strcmp_test05) {
//    char str1[20] = "abc";
//    char str6[20] = "abcd";
//
//    ck_assert_int_eq(s21_strcmp(str1, str6), strcmp(str1, str6));
//}
// END_TEST

/**
 *s21_strncmp_test
 */

START_TEST(s21_strncmp_test01) {
    char str1[3] = "ab";
    char str2[3] = "ab";

    ck_assert_int_eq(s21_strncmp(str1, str2, 2), strncmp(str1, str2, 2));
}
END_TEST

START_TEST(s21_strncmp_test02) {
    char str1[4] = "abc";
    char str2[4] = "aac";

    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(s21_strncmp_test03) {
    char str1[4] = "abc";
    char str2[4] = "acc";

    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

// START_TEST(s21_strncmp_test04) {
//    char str1[4] = "abc";
//    char str2[3] = "ab";
//
//    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
//}
// END_TEST

// START_TEST(s21_strncmp_test05) {
//    char str1[3] = "ab";
//    char str2[4] = "abc";
//
//    ck_assert_int_eq(s21_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
//}
// END_TEST

/**
 *s21_strcpy_test
 */

START_TEST(s21_strcpy_test01) {
    char hello01[20] = "Hello";
    char hello02[20] = "Hello";
    char peer01[20] = "Peer";
    char peer02[20] = "Peer";

    ck_assert_str_eq(s21_strcpy(hello01, peer01), strcpy(hello02, peer02));
}
END_TEST

START_TEST(s21_strcpy_test02) {
    char hello01[20] = "Hello";
    char hello02[20] = "Hello";
    char peer01[20] = "Peer";
    char peer02[20] = "Peer";

    ck_assert_str_ne(s21_strcpy(peer01, hello01), strcpy(hello02, peer02));
}
END_TEST

START_TEST(s21_strcpy_test03) {
    char hello01[20] = "Hello";
    char hello02[20] = "Hello";
    char peer01[20] = "Peer";
    char peer02[20] = "Peer";
    ck_assert_ptr_ne(s21_strcpy(hello01, peer01), strcpy(hello02, peer02));
}
END_TEST

START_TEST(s21_strcpy_test04) {
    char hello[20] = "Hello";
    char peer01[20] = "Peer";
    char peer02[20] = "\0";

    ck_assert_ptr_eq(s21_strcpy(hello, peer01), strcpy(hello, peer02));
}
END_TEST

/*
***s21_strncpy_test***
*/

START_TEST(s21_strncpy_test01) {
    char hello01[20] = "Hello";
    char hello02[20] = "Hello";
    char peer01[20] = "Peer";
    char peer02[20] = "Peer";

    ck_assert_str_eq(s21_strncpy(hello01, peer01, 3),
                     strncpy(hello02, peer02, 3));
}
END_TEST

START_TEST(s21_strncpy_test02) {
    char hello01[20] = "Hello";
    char hello02[20] = "Hello";
    char peer01[20] = "Peer";
    char peer02[20] = "Peer";

    ck_assert_str_ne(s21_strncpy(hello01, peer01, 3),
                     strncpy(hello02, peer02, 4));
}
END_TEST

START_TEST(s21_strncpy_test03) {
    char hello[20] = "Hello";
    char peer01[20] = "Peer";
    char hello2[20] = "Hello";

    ck_assert_str_eq(s21_strncpy(hello, peer01, 4), strncpy(hello2, peer01, 4));
}
END_TEST

// START_TEST(s21_strncpy_test04) {
//    char hello[20] = "Hello";
//    char peer01[20] = "Peer";
//    char peer02[20] = "Peer";
//
//    ck_assert_str_eq(s21_strncpy(hello, peer01, 25), peer02);
//}
// END_TEST

START_TEST(test_memset_fewwords) {
    char str[100] = "Lolachka the best";
    ck_assert_str_eq(memset(str, 'a', 6), s21_memset(str, 'a', 6));
} END_TEST

START_TEST(test_memset_empty) {
    char str[100] = "";
    ck_assert_str_eq(memset(str, 'b', 6), s21_memset(str, 'b', 6));
} END_TEST

START_TEST(test_memset_lowercase_1) {
    char str[100] = "say my name, say my name...";
    ck_assert_str_eq(memset(str, 'm', 10), s21_memset(str, 'm', 10));
} END_TEST

// START_TEST(test_memset_lowercase_0) {
//    char str[100] = "say my name, say my name...";
//    ck_assert_str_eq(memset(str, 't', 0), s21_memset(str, 't', 0));
//} END_TEST

START_TEST(test_memset_uppercase_1) {
    char str[100] = "say my name, say my name...";
    ck_assert_str_eq(memset(str, 'L', 5), s21_memset(str, 'L', 5));
} END_TEST

START_TEST(test_memset_uppercase_2) {
    char str[100] = "I BECOME SO NUMB";
    ck_assert_str_eq(memset(str, 'L', 5), s21_memset(str, 'L', 5));
} END_TEST

START_TEST(test_memset_word) {
    char str[100] = "sometimes";
    ck_assert_str_eq(memset(str, 'k', 5), s21_memset(str, 'k', 5));
} END_TEST

START_TEST(test_memset_toomuch) {
    char str[100] = "sometimes";
    ck_assert_str_eq(memset(str, 'd', 20), s21_memset(str, 'd', 5));
} END_TEST

START_TEST(test_memset_linebrake_1) {
    char str[100] = "/n";
    ck_assert_str_eq(memset(str, 'd', 1), s21_memset(str, 'd', 1));
} END_TEST

START_TEST(test_memset_linebrake_0) {
    char str[100] = "/n";
    ck_assert_str_eq(memset(str, 'j', 3), s21_memset(str, 'j', 3));
} END_TEST

START_TEST(test_memset_linebrake_2) {
    char str[100] = "ZOO";
    ck_assert_str_eq(memset(str, '\n', 3), s21_memset(str, '\n', 3));
} END_TEST

// strcat tests

START_TEST(test_strcat_1symbol) {
    char str[100] = "Lolachka the best";
    const char arr[]= "!";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_word) {
    char str[100] = "Lolachka the best";
    const char arr[]= "AEEE";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_linebrake) {
    char str[100] = "Lolachka the best";
    const char arr[]= "\n";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_empty) {
    char str[100] = "";
    const char arr[]= "";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_empty_1) {
    char str[100] = "";
    const char arr[]= "cat";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_linebrake_num) {
    char str[100] = "\n";
    const char arr[]= "LOLAA56";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_linebrake_1) {
    char str[100] = "Lolachka\0zaya";
    const char arr[]= "MRRR";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_linebrake_2) {
    char str[100] = "\0";
    const char arr[]= "lala la-i";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

START_TEST(test_strcat_uppercase) {
    char str[100] = "LASKAVAYA MAYA NEZHNAYA";
    const char arr[]= "MRRR_123";
    ck_assert_str_eq(strcat(str, arr), s21_strcat(str, arr));
} END_TEST

// strncat tests

START_TEST(test_strncat_fewwords_full) {
    char str[100] = "Lolachka the best";
    const char arr[]= "! Alex toxic boy";
    ck_assert_str_eq(strncat(str, arr, 16), s21_strncat(str, arr, 16));
} END_TEST

START_TEST(test_strncat_fewwords_cut) {
    char str[100] = "Lolachka the best";
    const char arr[]= "! Alex toxic boy";
    ck_assert_str_eq(strncat(str, arr, 12), s21_strncat(str, arr, 12));
} END_TEST

START_TEST(test_strncat_nullsymbol) {
    char str[100] = "Lolachka\0 the best";
    const char arr[]= "! Alex toxic boy";
    ck_assert_str_eq(strncat(str, arr, 12), s21_strncat(str, arr, 12));
} END_TEST

START_TEST(test_strncat_linebrake_0) {
    char str[100] = "my ne znali dryg dryga";
    const char arr[]= "\n";
    ck_assert_str_eq(strncat(str, arr, 3), s21_strncat(str, arr, 3));
} END_TEST

START_TEST(test_strncat_linebrake_1) {
    char str[100] = "lola\njulia";
    const char arr[]= "\n";
    ck_assert_str_eq(strncat(str, arr, 1), s21_strncat(str, arr, 1));
} END_TEST

START_TEST(test_strncat_emptyconst) {
    char str[100] = "you put the over in lover in lover";
    const char arr[]= "";
    ck_assert_str_eq(strncat(str, arr, 7), s21_strncat(str, arr, 7));
} END_TEST

START_TEST(test_strncat_emptyarr) {
    char str[100] = "";
    const char arr[]= "you put the over in lover in lover";
    ck_assert_str_eq(strncat(str, arr, 4), s21_strncat(str, arr, 4));
} END_TEST

START_TEST(test_strncat_nullsymbol_empty) {
    char str[100] = "\0";
    const char arr[]= "you";
    ck_assert_str_eq(strncat(str, arr, 1), s21_strncat(str, arr, 1));
} END_TEST

START_TEST(test_strncat_symbols) {
    char str[100] = "1223+12+1";
    const char arr[]= ":991_0";
    ck_assert_str_eq(strncat(str, arr, 4), s21_strncat(str, arr, 4));
} END_TEST

// Strchr tests

START_TEST(test_strchr_symbols_find) {
    const char arr[]= ":991_0";
    ck_assert_str_eq(strchr(arr, '1'), s21_strchr(arr, '1'));
} END_TEST

START_TEST(test_strchr_symbols_notfind) {
    const char arr[]= ":991_0";
    ck_assert_ptr_eq(strchr(arr, 'a'), s21_strchr(arr, 'a'));
} END_TEST

START_TEST(test_strchr_strfind) {
    const char arr[]= "Lolachka the best";
    ck_assert_str_eq(strchr(arr, 'a'), s21_strchr(arr, 'a'));
} END_TEST

START_TEST(test_strchr_strnotind) {
    const char arr[]= "Lolachka the best";
    ck_assert_ptr_eq(strchr(arr, '1'), s21_strchr(arr, '1'));
} END_TEST

START_TEST(test_strchr_linebrake_0) {
    const char arr[]= "\n";
    ck_assert_ptr_eq(strchr(arr, 'c'), s21_strchr(arr, 'c'));
} END_TEST

START_TEST(test_strchr_linebrake_find) {
    const char arr[]= "lalita\n Julia Werner";
    ck_assert_str_eq(strchr(arr, '\n'), s21_strchr(arr, '\n'));
} END_TEST

START_TEST(test_strchr_linebrake_notfind) {
    const char arr[]= "lalita123 Julia Werner";
    ck_assert_ptr_eq(strchr(arr, '\n'), s21_strchr(arr, '\n'));
} END_TEST

START_TEST(test_strchr_empty) {
    const char arr[]= "";
    ck_assert_ptr_eq(strchr(arr, '2'), s21_strchr(arr, '2'));
} END_TEST

START_TEST(test_strchr_empty_1) {
    const char arr[]= "lalalala tanthyut zvezdy i luna4555\n shine";
    ck_assert_str_eq(strchr(arr, '\0'), s21_strchr(arr, '\0'));
} END_TEST

// Strrchr test

START_TEST(test_strrchr_letters_find) {
    const char *str1 = "askjdnka";
    const char str2 = 'd';

    ck_assert_str_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(test_strrchr_letters_notfind) {
    const char *str1 = "askjdnka";
    const char str2 = '0';

    ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(test_strrchr_numbers_find) {
    const char *str1 = "123654987";
    const char str2 = '5';

    ck_assert_str_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(test_strrchr_numbers_notfind) {
    const char *str1 = "123654987";
    const char str2 = '-';

    ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(test_strrchr_linebrake_find) {
    const char *str1 = "123654\n987";
    const char str2 = '\n';

    ck_assert_str_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(test_strrchr_linebrake_notfind) {
    const char *str1 = "123654oeoriireo987";
    const char str2 = '\n';

    ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

START_TEST(test_strrchr_nullsymbol_notfind) {
    const char *str1 = "wew654oeor\0iireo987";
    const char str2 = 'i';

    ck_assert_ptr_eq(strrchr(str1, str2), s21_strrchr(str1, str2));
}
END_TEST

// Strspn tests

START_TEST(test_s21_strspn_num_find) {
    const char *str1 = "0123456789";
    const char *str2 = "456";

    ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_letters_notfind) {
    const char *str1 = "ask jdn ka";
    const char *str2 = "li";

    ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_letters) {
    const char *str1 = "askljdni  \nka";
    const char *str2 = "li";

    ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_num_find2) {
    const char *str1 = "9012++12+1";
    const char *str2 = "+1";

    ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_linebrake_find) {
    const char *str1 = "12365\n4987";
    const char *str2 = "\n";

    ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_linebrake_notfind) {
    const char *str1 = "lolacka luchshaya";
    const char *str2 = "\n";

    ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

START_TEST(test_s21_strspn_nullsymbol) {
    const char *str1 = "1236-15\04987-1";
    const char *str2 = "-1";

    ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
}
END_TEST

// Strstr test

START_TEST(test_strstr_words_find) {
    const char *str1 = "lolacka luchshaya";
    const char *str2 = "lol";

    ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_words_notfind) {
    const char *str1 = "askjdnka";
    const char *str2 = "0";

    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_numdubble_find) {
    const char *str1 = "12365498798";
    const char *str2 = "98";

    ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_linebrake_find) {
    const char *str1 = "1236\n54987";
    const char *str2 = "\n5";

    ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_linebrake_notfind) {
    const char *str1 = "123654987";
    const char *str2 = "\n";

    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_nullsymbol_notfind) {
    const char *str1 = "lallaal\0 fjrehf ebdhe";
    const char *str2 = "bhe";

    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_nullsymbol_find) {
    const char *str1 = "la-1llaal\0 fjrehf -ebdhe";
    const char *str2 = "laal";

    ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_empty) {
    const char *str1 = "";
    const char *str2 = "laal";

    ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(test_strstr_empty1) {
    const char *str1 = "loa pdkj hedh";
    const char *str2 = "";

    ck_assert_str_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

// START_TEST(test_strtok) {
//     char *str = "the string to be";

//     ck_assert_str_eq(strtok(str, " "), s21_strtok(str, " "));
// }
// END_TEST

// START_TEST(test_strtok_empty2) {
//     char *str = "the/dfg/dfg/";

//     ck_assert_str_eq(strstr(str, "/"), s21_strtok(str, "/"));
// }
// END_TEST


Suite *s21_string_suite(void) {
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;
    s = suite_create("s21_string");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, up_1);
    tcase_add_test(tc_core, up_2);
    tcase_add_test(tc_core, up_3);

    tcase_add_test(tc_core, low_1);
    tcase_add_test(tc_core, low_2);
    tcase_add_test(tc_core, low_3);

    tcase_add_test(tc_core, insert_1);
    tcase_add_test(tc_core, insert_2);
    tcase_add_test(tc_core, insert_3);
    tcase_add_test(tc_core, insert_4);
    tcase_add_test(tc_core, insert_5);

    tcase_add_test(tc_core, trim_1);
    tcase_add_test(tc_core, trim_2);
    tcase_add_test(tc_core, trim_3);
    tcase_add_test(tc_core, trim_4);
    tcase_add_test(tc_core, trim_5);
//    tcase_add_test(tc_core, trim_6);

    // tcase_add_test(tc_core, test_strtok);
    // tcase_add_test(tc_core, test_strtok_empty2);

    tcase_add_test(tc_core, test_s21_strcspn);
    tcase_add_test(tc_core, test_s21_strerror);
    tcase_add_test(tc_core, test_s21_strlen);
    tcase_add_test(tc_core, test_s21_strpbrk);
    tcase_add_test(tc_core, memchr_1);
    tcase_add_test(tc_core, memchr_2);
    tcase_add_test(tc_core, memchr_3);
//    tcase_add_test(tc_core, memchr_4);
    tcase_add_test(tc_core, memchr_5);
    tcase_add_test(tc_core, s21_memchr_test01);
    tcase_add_test(tc_core, s21_memchr_test02);
    tcase_add_test(tc_core, s21_memchr_test03);
    tcase_add_test(tc_core, s21_memchr_test04);
    tcase_add_test(tc_core, s21_memchr_test05);
    tcase_add_test(tc_core, s21_memchr_test06);
    tcase_add_test(tc_core, s21_memchr_test07);


    tcase_add_test(tc_core, memcmp_1);
//    tcase_add_test(tc_core, memcmp_2);
//    tcase_add_test(tc_core, memcmp_3);
//    tcase_add_test(tc_core, memcmp_4);
//    tcase_add_test(tc_core, memcmp_5);
    tcase_add_test(tc_core, s21_memcmp_test01);
    tcase_add_test(tc_core, s21_memcmp_test02);
    tcase_add_test(tc_core, s21_memcmp_test03);


    tcase_add_test(tc_core, memcpy_1);
    tcase_add_test(tc_core, memcpy_2);
    tcase_add_test(tc_core, memcpy_3);
    tcase_add_test(tc_core, memcpy_4);
    tcase_add_test(tc_core, memcpy_5);
    tcase_add_test(tc_core, s21_memcpy_test01);


    tcase_add_test(tc_core, memmove_1);
    tcase_add_test(tc_core, memmove_2);
    tcase_add_test(tc_core, memmove_3);
    tcase_add_test(tc_core, memmove_4);
    tcase_add_test(tc_core, memmove_5);
    tcase_add_test(tc_core, s21_memmove_test01);

    tcase_add_test(tc_core, strtok_1);
    tcase_add_test(tc_core, strtok_2);
    tcase_add_test(tc_core, strtok_3);

    tcase_add_test(tc_core, d_simple);
    tcase_add_test(tc_core, i_simple);
    tcase_add_test(tc_core, d_width);
    tcase_add_test(tc_core, i_width);
    tcase_add_test(tc_core, d_width_minus);
    tcase_add_test(tc_core, i_width_minus);
    tcase_add_test(tc_core, d_width_plus);
    tcase_add_test(tc_core, i_width_plus);
    tcase_add_test(tc_core, d_width_space);
    tcase_add_test(tc_core, i_width_space);
//    tcase_add_test(tc_core, d_width_space_prec);
//    tcase_add_test(tc_core, i_width_space_prec);
//    tcase_add_test(tc_core, d_width_space_prec_l);
//    tcase_add_test(tc_core, i_width_space_prec_l);
    tcase_add_test(tc_core, d_width_plus_minus);
    tcase_add_test(tc_core, i_width_plus_minus);
//    tcase_add_test(tc_core, d_width_space_prec_h);
//    tcase_add_test(tc_core, i_width_space_prec_h);

    // ------------------------ f -------------------------
    tcase_add_test(tc_core, f_simple);
    tcase_add_test(tc_core, f_width_1);
    tcase_add_test(tc_core, f_width_2);
    tcase_add_test(tc_core, f_width_minus);
    tcase_add_test(tc_core, f_space);
    tcase_add_test(tc_core, f_width_spec_1);
    tcase_add_test(tc_core, f_width_spec_2);
    tcase_add_test(tc_core, f_width_minus_plus);
    tcase_add_test(tc_core, f_width_minus_plus_spec);
    tcase_add_test(tc_core, f_width_spec_l);
    tcase_add_test(tc_core, f_width_spec_3);
    tcase_add_test(tc_core, f_width_plus);
    tcase_add_test(tc_core, f_width_spec_4);

    // ----------------- u ------------------
    tcase_add_test(tc_core, u_simple);
    tcase_add_test(tc_core, u_width);
    tcase_add_test(tc_core, u_width_minus);
    tcase_add_test(tc_core, u_width_plus);
    tcase_add_test(tc_core, u_width_space);
    tcase_add_test(tc_core, u_width_space_prec);
    tcase_add_test(tc_core, u_width_plus_minus);
    tcase_add_test(tc_core, u_width_space_prec_h);
    tcase_add_test(tc_core, u_width_space_prec_l);

    // ------------------------ c ----------------------
    tcase_add_test(tc_core, c_simple_1);
    tcase_add_test(tc_core, c_simple_2);
    tcase_add_test(tc_core, c_width);
    tcase_add_test(tc_core, c_width_minus);
    tcase_add_test(tc_core, c_width_plus);
    tcase_add_test(tc_core, c_width_space);
    tcase_add_test(tc_core, c_width_space_prec_1);
    tcase_add_test(tc_core, c_width_space_prec_2);
    tcase_add_test(tc_core, c_width_plus_minus);

    // --------------------- s ------------------------
    tcase_add_test(tc_core, s_simple);
    tcase_add_test(tc_core, s_width);
    tcase_add_test(tc_core, s_width_minus);
    tcase_add_test(tc_core, s_width_plus);
    tcase_add_test(tc_core, s_width_space);
    tcase_add_test(tc_core, s_space_prec);
    tcase_add_test(tc_core, s_width_plus_minus);
    tcase_add_test(tc_core, s_width_space_prec);

    // ----------------- % ----------------
    tcase_add_test(tc_core, f_width_pros);
    tcase_add_test(tc_core, f_width_pros2);
//    tcase_add_test(tc_core, f_width_pros3);
//    tcase_add_test(tc_core, f_width_pros4);
//    tcase_add_test(tc_core, f_width_pros5);
//    tcase_add_test(tc_core, f_width_pros6);

    // ------------------- all -------------------
//    tcase_add_test(tc_core, d_s_f_c_1);
//    tcase_add_test(tc_core, d_s_f_c_2);
//    tcase_add_test(tc_core, d_s_f_c_3);
//    tcase_add_test(tc_core, d_s_f_c_4);
//    tcase_add_test(tc_core, d_s_f_c_5);

    // --------------------- min max ----------------
    tcase_add_test(tc_core, d_imin);
    tcase_add_test(tc_core, d_imax);
    tcase_add_test(tc_core, d_simin);
    tcase_add_test(tc_core, d_simax);
    tcase_add_test(tc_core, d_limin);
    tcase_add_test(tc_core, d_limax);

    tcase_add_test(tc_core, c_smin);
    tcase_add_test(tc_core, c_smax);
    tcase_add_test(tc_core, c_min);
    tcase_add_test(tc_core, c_max);
    tcase_add_test(tc_core, c_umax);

    tcase_add_test(tc_core, u_imax);
    tcase_add_test(tc_core, u_simax);
    tcase_add_test(tc_core, u_limax);

    tcase_add_test(tc_core, f_inf1);
    tcase_add_test(tc_core, f_inf2);


    // --------------- error -------------
//    tcase_add_test(tc_core, err1);
//    tcase_add_test(tc_core, err2);
//    tcase_add_test(tc_core, err3);
//    tcase_add_test(tc_core, d_s_f_c_1);
//    tcase_add_test(tc, d_s_f_c_err_2);
//    tcase_add_test(tc_core, d_s_f_c_change);
//    tcase_add_test(tc_core, d_s_f_c_more_max);

    tcase_add_test(tc_core, i_width_16x);
    tcase_add_test(tc_core, i_width_plus_minus_16x);
//    tcase_add_test(tc_core, i_width_space_prec_h_16x);

    tcase_add_test(tc_core, s21_strcmp_test01);
//    tcase_add_test(tc_core, s21_strcmp_test02);
    tcase_add_test(tc_core, s21_strcmp_test03);
//    tcase_add_test(tc_core, s21_strcmp_test04);
//    tcase_add_test(tc_core, s21_strcmp_test05);
    tcase_add_test(tc_core, s21_strncmp_test01);
    tcase_add_test(tc_core, s21_strncmp_test02);
    tcase_add_test(tc_core, s21_strncmp_test03);
//    tcase_add_test(tc_core, s21_strncmp_test04);
//    tcase_add_test(tc_core, s21_strncmp_test05);
    tcase_add_test(tc_core, s21_strcpy_test01);
    tcase_add_test(tc_core, s21_strcpy_test02);
    tcase_add_test(tc_core, s21_strcpy_test03);
    tcase_add_test(tc_core, s21_strcpy_test04);
    tcase_add_test(tc_core, s21_strncpy_test01);
    tcase_add_test(tc_core, s21_strncpy_test02);
    tcase_add_test(tc_core, s21_strncpy_test03);
//    tcase_add_test(tc_core, s21_strncpy_test04);

    tcase_add_test(tc_core, test_memset_fewwords);
    tcase_add_test(tc_core, test_memset_empty);
    tcase_add_test(tc_core, test_memset_lowercase_1);
//    tcase_add_test(tc_core, test_memset_lowercase_0);
    tcase_add_test(tc_core, test_memset_uppercase_1);
    tcase_add_test(tc_core, test_memset_uppercase_2);
    tcase_add_test(tc_core, test_memset_word);
    tcase_add_test(tc_core, test_memset_toomuch);
    tcase_add_test(tc_core, test_memset_linebrake_1);
    tcase_add_test(tc_core, test_memset_linebrake_0);
    tcase_add_test(tc_core, test_memset_linebrake_2);


    tcase_add_test(tc_core, test_strcat_1symbol);
    tcase_add_test(tc_core, test_strcat_word);
    tcase_add_test(tc_core, test_strcat_linebrake);
    tcase_add_test(tc_core, test_strcat_empty);
    tcase_add_test(tc_core, test_strcat_empty_1);
    tcase_add_test(tc_core, test_strcat_linebrake_num);
    tcase_add_test(tc_core, test_strcat_linebrake_1);
    tcase_add_test(tc_core, test_strcat_linebrake_2);
    tcase_add_test(tc_core, test_strcat_uppercase);


    tcase_add_test(tc_core, test_strncat_fewwords_full);
    tcase_add_test(tc_core, test_strncat_fewwords_cut);
    tcase_add_test(tc_core, test_strncat_nullsymbol);
    tcase_add_test(tc_core, test_strncat_linebrake_1);
    tcase_add_test(tc_core, test_strncat_linebrake_0);
    tcase_add_test(tc_core, test_strncat_emptyconst);
    tcase_add_test(tc_core, test_strncat_emptyarr);
    tcase_add_test(tc_core, test_strncat_nullsymbol_empty);
    tcase_add_test(tc_core, test_strncat_symbols);


    tcase_add_test(tc_core, test_strchr_symbols_find);
    tcase_add_test(tc_core, test_strchr_symbols_notfind);
    tcase_add_test(tc_core, test_strchr_strfind);
    tcase_add_test(tc_core, test_strchr_strnotind);
    tcase_add_test(tc_core, test_strchr_linebrake_0);
    tcase_add_test(tc_core, test_strchr_linebrake_find);
    tcase_add_test(tc_core, test_strchr_linebrake_notfind);
    tcase_add_test(tc_core, test_strchr_empty);
    tcase_add_test(tc_core, test_strchr_empty_1);


    tcase_add_test(tc_core, test_strrchr_letters_find);
    tcase_add_test(tc_core, test_strrchr_letters_notfind);
    tcase_add_test(tc_core, test_strrchr_numbers_find);
    tcase_add_test(tc_core, test_strrchr_numbers_notfind);
    tcase_add_test(tc_core, test_strrchr_linebrake_find);
    tcase_add_test(tc_core, test_strrchr_linebrake_notfind);
    tcase_add_test(tc_core, test_strrchr_nullsymbol_notfind);


    tcase_add_test(tc_core, test_s21_strspn_num_find);
    tcase_add_test(tc_core, test_s21_strspn_letters_notfind);
    tcase_add_test(tc_core, test_s21_strspn_letters);
    tcase_add_test(tc_core, test_s21_strspn_num_find2);
    tcase_add_test(tc_core, test_s21_strspn_linebrake_find);
    tcase_add_test(tc_core, test_s21_strspn_linebrake_notfind);
    tcase_add_test(tc_core, test_s21_strspn_nullsymbol);


    tcase_add_test(tc_core, test_strstr_words_find);
    tcase_add_test(tc_core, test_strstr_words_notfind);
    tcase_add_test(tc_core, test_strstr_numdubble_find);
    tcase_add_test(tc_core, test_strstr_linebrake_find);
    tcase_add_test(tc_core, test_strstr_linebrake_notfind);
    tcase_add_test(tc_core, test_strstr_nullsymbol_notfind);
    tcase_add_test(tc_core, test_strstr_nullsymbol_find);
    tcase_add_test(tc_core, test_strstr_empty);
    tcase_add_test(tc_core, test_strstr_empty1);



    suite_add_tcase(s, tc_core);

    tc_limits = tcase_create("Limits");

    tcase_add_test(tc_limits, test_s21_strcspn_neg1);
    tcase_add_test(tc_limits, test_s21_strcspn_neg2);
    tcase_add_test(tc_limits, test_s21_strcspn_neg3);
    tcase_add_test(tc_limits, test_s21_strcspn_neg4);
    tcase_add_test(tc_limits, test_s21_strcspn_zero1);
    tcase_add_test(tc_limits, test_s21_strcspn_zero2);
//    tcase_add_test(tc_limits, test_s21_strerror_neg);
    tcase_add_test(tc_limits, test_s21_strerror_zero);
    tcase_add_test(tc_limits, test_s21_strpbrk_neg1);
    tcase_add_test(tc_limits, test_s21_strpbrk_neg2);
    tcase_add_test(tc_limits, test_s21_strpbrk_neg3);
    tcase_add_test(tc_limits, test_s21_strpbrk_neg4);





    suite_add_tcase(s, tc_limits);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = s21_string_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_SILENT);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return(number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
