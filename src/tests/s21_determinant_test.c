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
    s21_determinant(&A, &result);
    double expected_result = -2;
    Matrix_operation_result res = 0;
    res = s21_determinant(&A, &result);
    s21_remove_matrix(&A);
    ck_assert(res == OK && result == expected_result);
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
    ck_assert(res == OK && result == expected_result);
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