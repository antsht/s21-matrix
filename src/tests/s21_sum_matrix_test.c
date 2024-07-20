#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_sum_matrix_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  matrix_t expected = {0};
  s21_create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 2;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_sum_matrix(&A, &B, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t B = {0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 2;
  expected.matrix[0][1] = 4;
  expected.matrix[1][0] = 6;
  expected.matrix[1][1] = 8;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_sum_matrix(&A, &B, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 2;
  expected.matrix[0][1] = 4;
  expected.matrix[1][0] = 6;
  expected.matrix[1][1] = 8;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_sum_matrix(&A, &A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_sum_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  Matrix_operation_result res = 0;
  res = s21_sum_matrix(&A, &A, &A);
  s21_remove_matrix(&A);
  ck_assert(res == ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_sum_matrix_test_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(8, 8, &A);
  s21_create_matrix(8, -8, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(89, 2, &A);
  s21_create_matrix(89, -2, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(65, 47, &B);
  s21_create_matrix(0, 0, &A);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 4, &A);
  s21_create_matrix(9, 4, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(25, 11, &A);
  s21_create_matrix(9, 4, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_11) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(12, 26, &A);
  s21_create_matrix(11, 26, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_12) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  A.matrix[0][0] = -547.63657;
  A.matrix[0][1] = -14.7969;
  A.matrix[1][0] = -689.32425;
  A.matrix[1][1] = 40.0;
  A.matrix[2][0] = 780.0;
  A.matrix[2][1] = 1143.956856;

  B.matrix[0][0] = 2545.357;
  B.matrix[0][1] = 14.8845;
  B.matrix[1][0] = 689.5;
  B.matrix[1][1] = -45740;
  B.matrix[2][0] = 780.0;
  B.matrix[2][1] = -1564.25;
  s21_create_matrix(3, 2, &check_result);

  check_result.matrix[0][0] = 1997.72043;
  check_result.matrix[0][1] = 0.0876;
  check_result.matrix[1][0] = 0.17575;
  check_result.matrix[1][1] = -45700;
  check_result.matrix[2][0] = 1560;
  check_result.matrix[2][1] = -420.293144;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&result);

  ck_assert_int_eq(s21_sum_matrix(&B, &A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_sum_matrix_test_13) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 1, &B);

  A.matrix[0][0] = DBL_MAX;
  A.matrix[1][0] = DBL_MIN;
  B.matrix[0][0] = DBL_MAX;
  B.matrix[1][0] = DBL_MIN;
  s21_create_matrix(2, 1, &check_result);

  check_result.matrix[0][0] = INFINITY;
  check_result.matrix[1][0] = NAN;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&result);

  ck_assert_int_eq(s21_sum_matrix(&B, &A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_sum_matrix_test_14) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.e-18;
  B.matrix[0][0] = 1.e+18;
  s21_create_matrix(1, 1, &check_result);

  check_result.matrix[0][0] = 1.e+18;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&result);

  ck_assert_int_eq(s21_sum_matrix(&B, &A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_sum_matrix_test_15) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 3, &B);

  A.matrix[0][0] = 12343.57456;
  A.matrix[0][1] = -2545.87089;
  A.matrix[0][2] = 99999.325246;

  B.matrix[0][0] = -709689679.6346;
  B.matrix[0][1] = 0.000063567456;
  B.matrix[0][2] = 1324546456999;
  s21_create_matrix(1, 3, &check_result);

  check_result.matrix[0][0] = -709677336.06004;
  check_result.matrix[0][1] = -2545.870826432544;
  check_result.matrix[0][2] = 1324546556998.325246;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&result);

  ck_assert_int_eq(s21_sum_matrix(&B, &A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

Suite *s21_sum_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_sum_matrix() tests");
  TCase *tc;
  tc = tcase_create("sum_matrix");
  tcase_add_test(tc, s21_sum_matrix_test_1);
  tcase_add_test(tc, s21_sum_matrix_test_2);
  tcase_add_test(tc, s21_sum_matrix_test_3);
  tcase_add_test(tc, s21_sum_matrix_test_4);
  tcase_add_test(tc, s21_sum_matrix_test_5);
  tcase_add_test(tc, s21_sum_matrix_test_6);
  tcase_add_test(tc, s21_sum_matrix_test_7);
  tcase_add_test(tc, s21_sum_matrix_test_8);
  tcase_add_test(tc, s21_sum_matrix_test_9);
  tcase_add_test(tc, s21_sum_matrix_test_10);
  tcase_add_test(tc, s21_sum_matrix_test_11);
  tcase_add_test(tc, s21_sum_matrix_test_12);
  tcase_add_test(tc, s21_sum_matrix_test_13);
  tcase_add_test(tc, s21_sum_matrix_test_14);
  tcase_add_test(tc, s21_sum_matrix_test_15);
  suite_add_tcase(s, tc);
  return s;
}

int s21_sum_matrix_test(void) {
  Suite *s = s21_sum_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}