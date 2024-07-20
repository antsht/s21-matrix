#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_mult_matrix_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  matrix_t expected = {0};
  s21_create_matrix(1, 1, &expected);
  expected.matrix[0][0] = 1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_mult_matrix(&A, &B, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
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
  expected.matrix[0][0] = 7;
  expected.matrix[0][1] = 10;
  expected.matrix[1][0] = 15;
  expected.matrix[1][1] = 22;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_mult_matrix(&A, &B, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A = {0};
  s21_create_matrix(4, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;
  A.matrix[3][0] = 7;
  A.matrix[3][1] = 8;
  matrix_t B = {0};
  s21_create_matrix(2, 4, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[0][3] = 4;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = 6;
  B.matrix[1][2] = 7;
  B.matrix[1][3] = 8;
  matrix_t expected = {0};
  s21_create_matrix(4, 4, &expected);
  expected.matrix[0][0] = 11;
  expected.matrix[0][1] = 14;
  expected.matrix[0][2] = 17;
  expected.matrix[0][3] = 20;
  expected.matrix[1][0] = 23;
  expected.matrix[1][1] = 30;
  expected.matrix[1][2] = 37;
  expected.matrix[1][3] = 44;
  expected.matrix[2][0] = 35;
  expected.matrix[2][1] = 46;
  expected.matrix[2][2] = 57;
  expected.matrix[2][3] = 68;
  expected.matrix[3][0] = 47;
  expected.matrix[3][1] = 62;
  expected.matrix[3][2] = 77;
  expected.matrix[3][3] = 92;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_mult_matrix(&A, &B, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
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
  res = s21_mult_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(0, 8, &A);
  s21_create_matrix(8, 8, &B);

  int res = s21_mult_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_test_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(89, 2, &A);
  s21_create_matrix(-18, 2, &B);

  Matrix_operation_result res = s21_mult_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_test_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(65, 47, &B);
  s21_create_matrix(-45, 47, &A);

  Matrix_operation_result res = s21_mult_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_test_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(1, 4, &B);

  Matrix_operation_result res = s21_mult_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_mult_matrix_test_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(12, 26, &A);
  s21_create_matrix(3, 26, &B);
  Matrix_operation_result res = s21_mult_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_mult_matrix_test_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};

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

  s21_create_matrix(3, 4, &check_result);

  check_result.matrix[0][0] = -212348213.652;
  check_result.matrix[0][1] = -623892.932;
  check_result.matrix[0][2] = 4816772.75896;
  check_result.matrix[0][3] = 8716200.160425998;
  check_result.matrix[1][0] = -11918812217883.271;
  check_result.matrix[1][1] = 576605646105885.1;
  check_result.matrix[1][2] = 1014142459486121.5;
  check_result.matrix[1][3] = 29134874173972.18;
  check_result.matrix[2][0] = -212870394.51999998;
  check_result.matrix[2][1] = 5272.68;
  check_result.matrix[2][2] = 5937538.5846;
  check_result.matrix[2][3] = 8768965.108259998;

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_mult_matrix() tests");
  TCase *tc;
  tc = tcase_create("mult_matrix");
  tcase_add_test(tc, s21_mult_matrix_test_1);
  tcase_add_test(tc, s21_mult_matrix_test_2);
  tcase_add_test(tc, s21_mult_matrix_test_3);
  tcase_add_test(tc, s21_mult_matrix_test_4);
  tcase_add_test(tc, s21_mult_matrix_test_5);
  tcase_add_test(tc, s21_mult_matrix_test_6);
  tcase_add_test(tc, s21_mult_matrix_test_7);
  tcase_add_test(tc, s21_mult_matrix_test_8);
  tcase_add_test(tc, s21_mult_matrix_test_9);
  tcase_add_test(tc, s21_mult_matrix_test_10);
  suite_add_tcase(s, tc);
  return s;
}

int s21_mult_matrix_test(void) {
  Suite *s = s21_mult_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}