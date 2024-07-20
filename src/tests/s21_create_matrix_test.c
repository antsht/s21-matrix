#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"

START_TEST(s21_create_matrix_test_1) {
  matrix_t A = {0};
  Matrix_operation_result res = 0;
  res = s21_create_matrix(1, 1, &A);
  ck_assert(res == OK && A.rows == 1 && A.columns == 1 && A.matrix != NULL);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  matrix_t A = {0};
  Matrix_operation_result res = 0;
  res = s21_create_matrix(10000, 10000, &A);
  ck_assert(res == OK && A.rows == 10000 && A.columns == 10000 &&
            A.matrix != NULL);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  matrix_t A = {0};
  Matrix_operation_result res = 0;
  res = s21_create_matrix(0, 0, &A);
  ck_assert(res == ERROR_INCORRECT_MATRIX && A.matrix == NULL);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  matrix_t A = {0};
  Matrix_operation_result res = 0;
  res = s21_create_matrix(-1, -1, &A);
  ck_assert(res == ERROR_INCORRECT_MATRIX && A.matrix == NULL);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  matrix_t A = {0};
  int rows = 3;
  int columns = 5;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A), OK);
  ck_assert_int_eq(A.rows, rows);
  ck_assert_int_eq(A.columns, columns);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  matrix_t A = {0};
  int rows = 0;
  int columns = 111;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  matrix_t A = {0};
  int rows = 2423;
  int columns = 0;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_8) {
  matrix_t A = {0};
  int rows = -9;
  int columns = 84;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_9) {
  matrix_t A = {0};
  int rows = 78;
  int columns = -57;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_10) {
  matrix_t A = {0};
  int rows = 0;
  int columns = 0;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_11) {
  matrix_t A = {0};
  int rows = -742;
  int columns = -123;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_12) {
  matrix_t A = {0};
  int rows = INT_MIN;
  int columns = INT_MIN;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &A),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_test_13) {
  matrix_t *test = NULL;
  int rows = 45363;
  int columns = 54;
  ck_assert_int_eq(s21_create_matrix(rows, columns, test),
                   ERROR_INCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_create_matrix() tests");
  TCase *tc;
  tc = tcase_create("create_matrix");
  tcase_add_test(tc, s21_create_matrix_test_1);
  tcase_add_test(tc, s21_create_matrix_test_2);
  tcase_add_test(tc, s21_create_matrix_test_3);
  tcase_add_test(tc, s21_create_matrix_test_4);
  tcase_add_test(tc, s21_create_matrix_test_5);
  tcase_add_test(tc, s21_create_matrix_test_6);
  tcase_add_test(tc, s21_create_matrix_test_7);
  tcase_add_test(tc, s21_create_matrix_test_8);
  tcase_add_test(tc, s21_create_matrix_test_9);
  tcase_add_test(tc, s21_create_matrix_test_10);
  tcase_add_test(tc, s21_create_matrix_test_11);
  tcase_add_test(tc, s21_create_matrix_test_12);
  tcase_add_test(tc, s21_create_matrix_test_13);
  suite_add_tcase(s, tc);
  return s;
}

int s21_create_matrix_test(void) {
  Suite *s = s21_create_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}