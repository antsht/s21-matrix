#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_mult_number_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t expected = {0};
  s21_create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 2;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_mult_number(&A, 2, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 0.5;
  expected.matrix[0][1] = 1;
  expected.matrix[1][0] = 1.5;
  expected.matrix[1][1] = 2;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_mult_number(&A, 0.5, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.columns = -1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_mult_number(&A, 0, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  ck_assert(res == ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(0, -2, &A);
  double elem = 1.4;

  ck_assert_int_eq(s21_mult_number(&A, elem, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_test_5) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(-2, 7, &A);
  double elem = 234.534;

  ck_assert_int_eq(s21_mult_number(&A, elem, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_test_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(0, 0, &A);
  double elem = 5.79;

  ck_assert_int_eq(s21_mult_number(&A, elem, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_test_7) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &check_result);
  A.matrix[0][0] = 342.62456;
  check_result.matrix[0][0] = 1458290.30150704;

  double elem = 4256.234;

  ck_assert_int_eq(s21_mult_number(&A, elem, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_mult_number_test_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result_A = {0};
  matrix_t check_result_A = {0};
  matrix_t result_B = {0};
  matrix_t check_result_B = {0};

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

  s21_create_matrix(3, 2, &check_result_A);
  s21_create_matrix(3, 2, &check_result_B);

  double elem = 7578.67346;

  check_result_A.matrix[0][0] = -4150358.7387844322;
  check_result_A.matrix[0][1] = -112140.873320274;
  check_result_A.matrix[1][0] = -5224163.398809405;
  check_result_A.matrix[1][1] = 303146.9384;
  check_result_A.matrix[2][0] = 5911365.2988;
  check_result_A.matrix[2][1] = 8669675.46395224176;

  check_result_B.matrix[0][0] = 19290429.54212522;
  check_result_B.matrix[0][1] = 112804.76511537;
  check_result_B.matrix[1][0] = 5225495.35067;
  check_result_B.matrix[1][1] = -346648524.0604;
  check_result_B.matrix[2][0] = 5911365.2988;
  check_result_B.matrix[2][1] = -11854939.959805;

  ck_assert_int_eq(s21_mult_number(&A, elem, &result_A), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_A, &check_result_A), SUCCESS);

  ck_assert_int_eq(s21_mult_number(&B, elem, &result_B), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_B, &check_result_B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_A);
  s21_remove_matrix(&check_result_A);
  s21_remove_matrix(&result_B);
  s21_remove_matrix(&check_result_B);
}
END_TEST

START_TEST(s21_mult_number_test_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result_A = {0};
  matrix_t check_result_A = {0};
  matrix_t result_B = {0};
  matrix_t check_result_B = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 1, &B);

  A.matrix[0][0] = DBL_MAX;
  A.matrix[1][0] = DBL_MIN;
  B.matrix[0][0] = DBL_MAX;
  B.matrix[1][0] = DBL_MIN;
  s21_create_matrix(2, 1, &check_result_A);
  s21_create_matrix(2, 1, &check_result_B);

  double elem_1 = 1.0;
  double elem_2 = -1.0;

  check_result_A.matrix[0][0] = DBL_MAX;
  check_result_A.matrix[1][0] = DBL_MIN;

  check_result_B.matrix[0][0] = -DBL_MAX;
  check_result_B.matrix[1][0] = -DBL_MIN;

  ck_assert_int_eq(s21_mult_number(&A, elem_1, &result_A), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_A, &check_result_A), SUCCESS);

  ck_assert_int_eq(s21_mult_number(&B, elem_2, &result_B), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_B, &check_result_B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_A);
  s21_remove_matrix(&check_result_A);
  s21_remove_matrix(&result_B);
  s21_remove_matrix(&check_result_B);
}
END_TEST

START_TEST(s21_mult_number_test_10) {
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

  double elem_1 = 1.0e+21;
  double elem_2 = 1.0e-21;

  check_result_A.matrix[0][0] = 1.e+3;
  check_result_B.matrix[0][0] = 1.e-3;

  ck_assert_int_eq(s21_mult_number(&A, elem_1, &result_A), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_A, &check_result_A), SUCCESS);

  ck_assert_int_eq(s21_mult_number(&B, elem_2, &result_B), OK);
  ck_assert_int_eq(s21_eq_matrix(&result_B, &check_result_B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_A);
  s21_remove_matrix(&check_result_A);
  s21_remove_matrix(&result_B);
  s21_remove_matrix(&check_result_B);
}
END_TEST

START_TEST(s21_mult_number_test_11) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result_A = {0};
  matrix_t check_result_A = {0};
  matrix_t result_B = {0};
  matrix_t check_result_B = {0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 3, &B);

  A.matrix[0][0] = 12343.57456;
  A.matrix[0][1] = -2545.87089;
  A.matrix[0][2] = 99999.325246;

  B.matrix[0][0] = -709689679.6346;
  B.matrix[0][1] = 0.000063567456;
  B.matrix[0][2] = 1324546456999.0;
  s21_create_matrix(1, 3, &check_result_A);
  s21_create_matrix(1, 3, &check_result_B);

  double elem_1 = 0;
  double elem_2 = -21.678409;

  check_result_A.matrix[0][0] = 0;
  check_result_A.matrix[0][1] = 0;
  check_result_A.matrix[0][2] = 0;

  check_result_B.matrix[0][0] = 15384943138.1978282928466796875;
  check_result_B.matrix[0][1] = -0.001378041310257504;
  check_result_B.matrix[0][2] = -28714059834325.234591;

  ck_assert_int_eq(s21_mult_number(&A, elem_1, &result_A), OK);
  int res_A = s21_eq_matrix(&result_A, &check_result_A);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_A);
  s21_remove_matrix(&check_result_A);
  ck_assert_int_eq(res_A, SUCCESS);

  ck_assert_int_eq(s21_mult_number(&B, elem_2, &result_B), OK);
  int res_b = s21_eq_matrix(&result_B, &check_result_B);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result_B);
  s21_remove_matrix(&check_result_B);
  ck_assert_int_eq(res_b, SUCCESS);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s;
  s = suite_create("s21_mult_number() tests");
  TCase *tc;
  tc = tcase_create("mult_number");
  tcase_add_test(tc, s21_mult_number_test_1);
  tcase_add_test(tc, s21_mult_number_test_2);
  tcase_add_test(tc, s21_mult_number_test_3);
  tcase_add_test(tc, s21_mult_number_test_4);
  tcase_add_test(tc, s21_mult_number_test_5);
  tcase_add_test(tc, s21_mult_number_test_6);
  tcase_add_test(tc, s21_mult_number_test_7);
  tcase_add_test(tc, s21_mult_number_test_8);
  tcase_add_test(tc, s21_mult_number_test_9);
  tcase_add_test(tc, s21_mult_number_test_10);
  tcase_add_test(tc, s21_mult_number_test_11);
  suite_add_tcase(s, tc);
  return s;
}

int s21_mult_number_test(void) {
  Suite *s = s21_mult_number_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}