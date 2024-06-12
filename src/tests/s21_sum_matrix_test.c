#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_sum_matrix_test_1) {
    matrix_t A;
    s21_create_matrix(1, 1, &A);
    A.matrix[0][0] = 1;
    matrix_t B;
    s21_create_matrix(1, 1, &B);
    B.matrix[0][0] = 1;
    matrix_t expected;
    s21_create_matrix(1, 1, &expected);
    expected.matrix[0][0] = 2;
    matrix_t result;
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
    matrix_t A;
    s21_create_matrix(2, 2, &A);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;
    matrix_t B;
    s21_create_matrix(2, 2, &B);
    B.matrix[0][0] = 1;
    B.matrix[0][1] = 2;
    B.matrix[1][0] = 3;
    B.matrix[1][1] = 4;
    matrix_t expected;
    s21_create_matrix(2, 2, &expected);
    expected.matrix[0][0] = 2;
    expected.matrix[0][1] = 4;
    expected.matrix[1][0] = 6;
    expected.matrix[1][1] = 8;
    matrix_t result;
    Matrix_operation_result res = 0;
    res = s21_sum_matrix(&A, &B, &result);
    // s21_print_matrix(&result);
    // s21_print_matrix(&expected);
    int comp_res = s21_eq_matrix(&expected, &result);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
    ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
    matrix_t A;
    s21_create_matrix(2, 2, &A);
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;
    matrix_t B;
    s21_create_matrix(1, 1, &B);
    B.matrix[0][0] = 1;
    matrix_t result;
    Matrix_operation_result res = 0;
    res = s21_sum_matrix(&A, &B, &result);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&result);
    ck_assert(res == ERROR_INCORRECT_MATRIX);
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