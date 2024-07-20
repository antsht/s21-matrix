#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"

START_TEST(s21_remove_matrix_test_1) {
  matrix_t A = {0};
  Matrix_operation_result res = 0;
  res = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  ck_assert(res == OK);
  ck_assert(A.matrix == NULL);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  matrix_t A;
  Matrix_operation_result res = 0;
  res = s21_create_matrix(10, 25, &A);
  s21_remove_matrix(&A);
  ck_assert(res == OK);
  ck_assert_int_eq(A.columns, 0);
  ck_assert_int_eq(A.rows, 0);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_3) {
  matrix_t *A = NULL;
  s21_remove_matrix(A);
  ck_assert_ptr_null(A);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_remove_matrix() tests");
  TCase *tc;
  tc = tcase_create("remove_matrix");
  tcase_add_test(tc, s21_remove_matrix_test_1);
  tcase_add_test(tc, s21_remove_matrix_test_2);
  tcase_add_test(tc, s21_remove_matrix_test_3);
  suite_add_tcase(s, tc);
  return s;
}

int s21_remove_matrix_test(void) {
  Suite *s = s21_remove_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}