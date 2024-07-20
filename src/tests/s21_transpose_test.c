#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_transpose_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t expected = {0};
  s21_create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_transpose(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 3;
  expected.matrix[1][0] = 2;
  expected.matrix[1][1] = 4;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_transpose(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t A = {0};
  s21_create_matrix(2, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;

  matrix_t expected = {0};
  s21_create_matrix(4, 2, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 5;
  expected.matrix[1][0] = 2;
  expected.matrix[1][1] = 6;
  expected.matrix[2][0] = 3;
  expected.matrix[2][1] = 7;
  expected.matrix[3][0] = 4;
  expected.matrix[3][1] = 8;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_transpose(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t A = {0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.columns = -1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_transpose(&A, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  ck_assert(res == ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(8, 0, &A);

  ck_assert_int_eq(s21_transpose(&A, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_test_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(-89, 2, &A);

  ck_assert_int_eq(s21_transpose(&A, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_test_7) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(65, -47, &A);

  ck_assert_int_eq(s21_transpose(&A, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_test_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result_A = {0};
  matrix_t check_result_A = {0};
  matrix_t result_B = {0};
  matrix_t check_result_B = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 4, &B);

  A.matrix[0][0] = 876.678;
  A.matrix[0][1] = -1445;
  A.matrix[1][0] = 0.23432;
  A.matrix[1][1] = 1324312462347;
  A.matrix[2][0] = 878.78;
  A.matrix[2][1] = 0.0;

  B.matrix[0][0] = -242234;
  B.matrix[0][1] = 6;
  B.matrix[0][2] = 6756.57;
  B.matrix[0][3] = 9978.567;
  B.matrix[1][0] = -9;
  B.matrix[1][1] = 435.4;
  B.matrix[1][2] = 765.7879;
  B.matrix[1][3] = 22;
  s21_create_matrix(2, 3, &check_result_A);
  s21_create_matrix(4, 2, &check_result_B);

  check_result_A.matrix[0][0] = 876.678;
  check_result_A.matrix[0][1] = 0.23432;
  check_result_A.matrix[0][2] = 878.78;
  check_result_A.matrix[1][0] = -1445;
  check_result_A.matrix[1][1] = 1324312462347;
  check_result_A.matrix[1][2] = 0.0;

  check_result_B.matrix[0][0] = -242234;
  check_result_B.matrix[0][1] = -9;
  check_result_B.matrix[1][0] = 6;
  check_result_B.matrix[1][1] = 435.4;
  check_result_B.matrix[2][0] = 6756.57;
  check_result_B.matrix[2][1] = 765.7879;
  check_result_B.matrix[3][0] = 9978.567;
  check_result_B.matrix[3][1] = 22;

  ck_assert_int_eq(s21_transpose(&A, &result_A), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_A, &check_result_A), SUCCESS);

  ck_assert_int_eq(s21_transpose(&B, &result_B), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_B, &check_result_B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_A);
  s21_remove_matrix(&result_B);
  s21_remove_matrix(&check_result_A);
  s21_remove_matrix(&check_result_B);
}
END_TEST

START_TEST(s21_transpose_test_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result_A = {0};
  matrix_t check_result_A = {0};
  matrix_t result_B = {0};
  matrix_t check_result_B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.e-18;
  B.matrix[0][0] = 1.e+18;
  s21_create_matrix(1, 1, &check_result_A);
  s21_create_matrix(1, 1, &check_result_B);

  check_result_A.matrix[0][0] = 1.e-18;
  check_result_B.matrix[0][0] = 1.e+18;

  ck_assert_int_eq(s21_transpose(&A, &result_A), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_A, &check_result_A), SUCCESS);

  ck_assert_int_eq(s21_transpose(&B, &result_B), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_B, &check_result_B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_A);
  s21_remove_matrix(&result_B);
  s21_remove_matrix(&check_result_A);
  s21_remove_matrix(&check_result_B);
}
END_TEST

START_TEST(s21_transpose_test_10) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 57;
  A.matrix[0][1] = 453;
  A.matrix[1][0] = -99;
  A.matrix[1][1] = 36;
  s21_create_matrix(2, 2, &check_result);

  check_result.matrix[0][0] = 57;
  check_result.matrix[0][1] = -99;
  check_result.matrix[1][0] = 453;
  check_result.matrix[1][1] = 36;

  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

Suite *s21_transpose_suite(void) {
  Suite *s;
  s = suite_create("s21_transpose() tests");
  TCase *tc;
  tc = tcase_create("transpose");
  tcase_add_test(tc, s21_transpose_test_1);
  tcase_add_test(tc, s21_transpose_test_2);
  tcase_add_test(tc, s21_transpose_test_3);
  tcase_add_test(tc, s21_transpose_test_4);
  tcase_add_test(tc, s21_transpose_test_5);
  tcase_add_test(tc, s21_transpose_test_6);
  tcase_add_test(tc, s21_transpose_test_7);
  tcase_add_test(tc, s21_transpose_test_8);
  tcase_add_test(tc, s21_transpose_test_9);
  tcase_add_test(tc, s21_transpose_test_10);
  suite_add_tcase(s, tc);
  return s;
}

int s21_transpose_test(void) {
  Suite *s = s21_transpose_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}