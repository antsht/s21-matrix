#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &A);
  s21_remove_matrix(&A);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -2;
  expected.matrix[0][1] = 1;
  expected.matrix[1][0] = 1.5;
  expected.matrix[1][1] = -0.5;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 2;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;
  matrix_t expected = {0};
  s21_create_matrix(4, 4, &expected);
  expected.matrix[0][0] = -1.0 / 3.0;
  expected.matrix[0][1] = 0;
  expected.matrix[0][2] = 0;
  expected.matrix[0][3] = 2.0 / 3.0;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = -1.0 / 3.0;
  expected.matrix[1][2] = 2.0 / 3.0;
  expected.matrix[1][3] = 0;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 2.0 / 3.0;
  expected.matrix[2][2] = -1.0 / 3.0;
  expected.matrix[2][3] = 0;
  expected.matrix[3][0] = 2.0 / 3.0;
  expected.matrix[3][1] = 0;
  expected.matrix[3][2] = 0;
  expected.matrix[3][3] = -1.0 / 3.0;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_inverse_matrix() tests");
  TCase *tc;
  tc = tcase_create("inverse_matrix");
  tcase_add_test(tc, s21_inverse_matrix_test_1);
  tcase_add_test(tc, s21_inverse_matrix_test_2);
  tcase_add_test(tc, s21_inverse_matrix_test_3);
  tcase_add_test(tc, s21_inverse_matrix_test_4);
  tcase_add_test(tc, s21_inverse_matrix_test_5);
  suite_add_tcase(s, tc);
  return s;
}

int s21_inverse_matrix_test(void) {
  Suite *s = s21_inverse_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}