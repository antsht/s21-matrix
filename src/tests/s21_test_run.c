#include "s21_test.h"

int main(void) {
  int number_failed = 0;
  number_failed = s21_create_matrix_test();
  number_failed += s21_remove_matrix_test();
  number_failed += s21_eq_matrix_test();
  number_failed += s21_sum_matrix_test();
  number_failed += s21_sub_matrix_test();

  return number_failed;
}