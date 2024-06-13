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

Suite *s21_mult_number_suite(void) {
  Suite *s;
  s = suite_create("s21_mult_number() tests");
  TCase *tc;
  tc = tcase_create("mult_number");
  tcase_add_test(tc, s21_mult_number_test_1);
  tcase_add_test(tc, s21_mult_number_test_2);
  tcase_add_test(tc, s21_mult_number_test_3);
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