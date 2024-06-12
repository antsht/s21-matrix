#include <check.h>

#include "s21_test.h"

START_TEST(s21_matrix_test_1) { ck_assert(1 == 1); }
END_TEST

Suite *s21_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_matrix");
  TCase *tc_matrix;
  tc_matrix = tcase_create("matrix");
  tcase_add_test(tc_matrix, s21_matrix_test_1);
  suite_add_tcase(s, tc_matrix);
  return s;
}

int s21_matrix_test1(void) {
  Suite *s = s21_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}