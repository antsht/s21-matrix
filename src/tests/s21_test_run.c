#include "s21_test.h"

int main(void) {
  int number_failed = 0;
  number_failed = s21_matrix_test1();
  number_failed += s21_matrix_test2();

  return number_failed;
}