#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"

START_TEST(s21_eq_matrix_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  ck_assert(s21_eq_matrix(&A, &B) == SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 2;
  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.000001;
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1.000002;
  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.0000001;
  matrix_t B = {0};
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1.0000002;
  ck_assert(s21_eq_matrix(&A, &B) == SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  matrix_t A = {0};
  s21_create_matrix(2, 1, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  matrix_t B = {0};
  s21_create_matrix(1, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  ck_assert(s21_eq_matrix(&A, &B) == FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_6) {
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

  matrix_t B = {0};
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;
  ck_assert(s21_eq_matrix(&A, &B) == SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_eq_matrix() tests");
  TCase *tc;
  tc = tcase_create("eq_matrix");
  tcase_add_test(tc, s21_eq_matrix_test_1);
  tcase_add_test(tc, s21_eq_matrix_test_2);
  tcase_add_test(tc, s21_eq_matrix_test_3);
  tcase_add_test(tc, s21_eq_matrix_test_4);
  tcase_add_test(tc, s21_eq_matrix_test_5);
  tcase_add_test(tc, s21_eq_matrix_test_6);
  suite_add_tcase(s, tc);
  return s;
}

int s21_eq_matrix_test(void) {
  Suite *s = s21_eq_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}