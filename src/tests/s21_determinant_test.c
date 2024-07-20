#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_determinant_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  double result = 0;
  s21_determinant(&A, &result);
  double expected_result = 1;
  Matrix_operation_result res = 0;
  res = s21_determinant(&A, &result);
  s21_remove_matrix(&A);
  ck_assert(res == OK && result == expected_result);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  double result = 0;
  double expected_result = -2;
  Matrix_operation_result res = 0;
  res = s21_determinant(&A, &result);
  s21_remove_matrix(&A);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq(result, expected_result);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  double result = 0;
  s21_determinant(&A, &result);
  double expected_result = 0;
  Matrix_operation_result res = 0;
  res = s21_determinant(&A, &result);
  s21_remove_matrix(&A);
  ck_assert_msg(res == OK && result == expected_result,
                "Expected: %f Actual: %f Status: %d", expected_result, result,
                res);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 0;
  A.matrix[0][4] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;
  A.matrix[1][4] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 11111111111111111111111.0;
  A.matrix[2][3] = 0;
  A.matrix[2][4] = 0;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;
  A.matrix[3][4] = 0;
  A.matrix[4][0] = 0;
  A.matrix[4][1] = 0;
  A.matrix[4][2] = 0;
  A.matrix[4][3] = 0;
  A.matrix[4][4] = 1;

  double result = 0;
  double expected_result = 11111111111111111111111.0;
  Matrix_operation_result res = 0;
  res = s21_determinant(&A, &result);
  s21_remove_matrix(&A);
  ck_assert_msg(res == OK && result == expected_result,
                "Expected: %f Actual: %f Status: %d", expected_result, result,
                res);
}
END_TEST

START_TEST(s21_determinant_test_5) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = DBL_MAX - 5;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = DBL_MAX - 5;
  double result = 0;
  Matrix_operation_result res = 0;
  res = s21_determinant(&A, &result);
  s21_remove_matrix(&A);
  ck_assert_msg(res == CALCULATION_ERROR, "Expected: %d  Actual: %d ",
                CALCULATION_ERROR, res);
}
END_TEST

START_TEST(s21_determinant_test_6) {
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  double result = 0;
  Matrix_operation_result res = 0;
  res = s21_determinant(&A, &result);
  s21_remove_matrix(&A);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_determinant_test_7) {
  matrix_t A = {0};
  double result = 0;
  Matrix_operation_result res = 0;
  res = s21_determinant(&A, &result);
  s21_remove_matrix(&A);
  ck_assert(res == ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_test_8) {
  double result;

  ck_assert_int_eq(s21_determinant(NULL, &result), CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_determinant_test_9) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 57;
  A.matrix[0][1] = 453;
  A.matrix[1][0] = -99;
  A.matrix[1][1] = 36;
  double result_A = 0;
  double check_result_A = 46899;

  ck_assert_int_eq(s21_determinant(&A, &result_A), OK);
  ck_assert_double_eq(result_A, check_result_A);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_10) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 5435665.24;
  A.matrix[0][1] = -6535;
  A.matrix[0][2] = 65;
  A.matrix[1][0] = 89980.3;
  A.matrix[1][1] = -13;
  A.matrix[1][2] = -64357;
  A.matrix[2][0] = 65.7867;
  A.matrix[2][1] = 7078.0008;
  A.matrix[2][2] = 68746.1111;
  double result_A = 0;
  double check_result_A = 2511683626531045;

  ck_assert_int_eq(s21_determinant(&A, &result_A), OK);
  ck_assert_double_eq(result_A, check_result_A);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_11) {
  matrix_t A = {0};
  s21_create_matrix(6, 6, &A);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[0][5] = 6;

  A.matrix[1][0] = 7;
  A.matrix[1][1] = -8;
  A.matrix[1][2] = 9;
  A.matrix[1][3] = 10;
  A.matrix[1][4] = 11;
  A.matrix[1][5] = 12;

  A.matrix[2][0] = 13;
  A.matrix[2][1] = 14;
  A.matrix[2][2] = -15;
  A.matrix[2][3] = 16;
  A.matrix[2][4] = 17;
  A.matrix[2][5] = 18;

  A.matrix[3][0] = 19;
  A.matrix[3][1] = 20;
  A.matrix[3][2] = 21;
  A.matrix[3][3] = -22;
  A.matrix[3][4] = 23;
  A.matrix[3][5] = 24;

  A.matrix[4][0] = 25;
  A.matrix[4][1] = 26;
  A.matrix[4][2] = 27;
  A.matrix[4][3] = 28;
  A.matrix[4][4] = -29;
  A.matrix[4][5] = 30;

  A.matrix[5][0] = 31;
  A.matrix[5][1] = 32;
  A.matrix[5][2] = 33;
  A.matrix[5][3] = 34;
  A.matrix[5][4] = 35;
  A.matrix[5][5] = -36;
  double result_A = 0;
  double check_result_A = -937218816;

  ck_assert_int_eq(s21_determinant(&A, &result_A), OK);
  ck_assert_double_le_tol(result_A, check_result_A, 1e-06);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_12) {
  matrix_t A = {0}, B = {0};
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
  double result_A = 0;
  double result_B = 0;

  ck_assert_int_eq(s21_determinant(&A, &result_A), CALCULATION_ERROR);
  ck_assert_int_eq(s21_determinant(&A, &result_B), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_determinant_test_13) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;
  double result_A = 0;
  double check_result_A = 0;

  ck_assert_int_eq(s21_determinant(&A, &result_A), OK);
  ck_assert_double_eq(result_A, check_result_A);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_14) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 1.e-18;
  B.matrix[0][0] = 1.e+18;
  double result_A = 0;
  double result_B = 0;

  double check_result_A = 1.e-18;
  double check_result_B = 1.e+18;

  ck_assert_int_eq(s21_determinant(&A, &result_A), OK);
  ck_assert_int_eq(s21_determinant(&B, &result_B), OK);

  ck_assert_double_le_tol(result_A, check_result_A, 1e-06);
  ck_assert_double_le_tol(result_B, check_result_B, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s;
  s = suite_create("s21_determinant() tests");
  TCase *tc;
  tc = tcase_create("determinant");
  tcase_add_test(tc, s21_determinant_test_1);
  tcase_add_test(tc, s21_determinant_test_2);
  tcase_add_test(tc, s21_determinant_test_3);
  tcase_add_test(tc, s21_determinant_test_4);
  tcase_add_test(tc, s21_determinant_test_5);
  tcase_add_test(tc, s21_determinant_test_6);
  tcase_add_test(tc, s21_determinant_test_7);
  tcase_add_test(tc, s21_determinant_test_8);
  tcase_add_test(tc, s21_determinant_test_9);
  tcase_add_test(tc, s21_determinant_test_10);
  tcase_add_test(tc, s21_determinant_test_11);
  tcase_add_test(tc, s21_determinant_test_12);
  tcase_add_test(tc, s21_determinant_test_13);
  tcase_add_test(tc, s21_determinant_test_14);
  suite_add_tcase(s, tc);
  return s;
}

int s21_determinant_test(void) {
  Suite *s = s21_determinant_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}