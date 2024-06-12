SHELL:=/bin/bash
CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11 -pedantic
CFLAGS_BIN=$(subst -c ,,$(CFLAGS))
TESTFLAGS=-fprofile-arcs -ftest-coverage
LDFLAGS=
SOURCES=$(wildcard s21_*.c)
TEST_SOURCES=$(wildcard tests/s21_*.c)
OBJECTS=$(SOURCES:.c=.o)
LIBNAME=s21_string.a
S21_DEBUG?=false
ifeq ($(S21_DEBUG),true)   
	DEBUG_FLAGS=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
else
	DEBUG_FLAGS=
endif

.PHONY: all
all: $(LIBNAME)

.PHONY: check
check:
	cppcheck --enable=all --suppress=missingIncludeSystem ./
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n tests/*.c
	clang-format -n tests/*.h

.PHONY: $(LIBNAME)
$(LIBNAME): build clean

.PHONY: build
build: $(OBJECTS)
	ar rcs $(LIBNAME) $(OBJECTS)

.PHONY: test
test: CFLAGS_BIN += $(TESTFLAGS)
test: build clean
	$(CC) $(CFLAGS_BIN) $(DEBUG_FLAGS) $(TEST_SOURCES) $(LIBNAME) -o tests/tests -lcheck -lm -lsubunit

.PHONY: clean
clean:
	rm -f {.,tests}/*.o {.,tests}/*.gcda {.,tests}/*.gcno
	rm -rf report
	rm -f tests/{s21_test.info,s21_test,tests}

.PHONY: cleanall
cleanall:
	rm -f {.,tests}/*.o {.,tests}/*.gcda {.,tests}/*.gcno *.a
	rm -rf report
	rm -f tests/{s21_test.info,s21_test,tests}

.PHONY: gcov_report
gcov_report: test
	$(CC) --coverage $(CFLAGS_BIN) $(DEBUG_FLAGS) $(SOURCES) $(TEST_SOURCES) -o tests/s21_test -lcheck -lm -lsubunit -lgcov
	./tests/s21_test
	lcov -t "s21_test" -o tests/s21_test.info -c -d .
	genhtml -o report tests/s21_test.info

.PHONY: test_format
test_format:
	$(CC) $(CFLAGS_BIN) $(DEBUG_FLAGS) $(SOURCES) tests/test_format.c -o tests/test_format
	./tests/test_format

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $< -o $@