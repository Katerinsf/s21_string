FLAGS = -Wall -Werror -Wextra -std=c11
OBJECTS_C = s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memmove.c s21_memset.c s21_strcat.c s21_strncat.c \
		  s21_strchr.c s21_strcmp.c s21_strncmp.c s21_strcpy.c s21_strcspn.c s21_strerror.c s21_strlen.c \
		  s21_strpbrk.c s21_strrchr.c s21_strspn.c s21_strstr.c s21_strncpy.c s21_strtok.c s21_sprintf.c \
		  s21_helper_func.c s21_to_lower.c s21_to_upper.c s21_trim.c s21_insert.c
OBJECTS_O = s21_memchr.o s21_memcmp.o s21_memcpy.o s21_memmove.o s21_memset.o s21_strcat.o s21_strncat.o \
		    s21_strchr.o s21_strcmp.o s21_strncmp.o s21_strcpy.o s21_strcspn.o s21_strerror.o s21_strlen.o \
		    s21_strpbrk.o s21_strrchr.o s21_strspn.o s21_strstr.o s21_strncpy.o s21_strtok.o s21_sprintf.o \
		    s21_helper_func.o s21_insert.o s21_trim.o s21_to_lower.o s21_to_upper.o

all: s21_string.a gcov_report
rebuild: gcov_report test
s21_string.o:
	gcc $(FLAGS) -c $(OBJECTS_C)
clean:
	rm -rf *.o test out *.info *.gcda *.gcno *.gcov *.gch *.out *.a
test: s21_string.o
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(OBJECTS_C) -o test test.c -lcheck -lm -lpthread
	./test

s21_string.a: s21_string.o
	ar rc s21_string.a $(OBJECTS_O)
	ranlib s21_string.a
gcov_report: s21_string.o test
	gcov test.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out