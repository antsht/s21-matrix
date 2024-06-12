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
    matrix_t expected= {0};
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
    matrix_t expected= {0};
    s21_create_matrix(2, 2, &expected);
    expected.matrix[0][0] = 7;
    expected.matrix[0][1] = 10;
    expected.matrix[1][0] = 15;
    expected.matrix[1][1] = 22;
    matrix_t result = {0};
    Matrix_operation_result res = 0;
    res = s21_mult_matrix(&A, &B, &result);
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
    matrix_t expected= {0};
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
    ck_assert(res == ERROR_INCORRECT_MATRIX);
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