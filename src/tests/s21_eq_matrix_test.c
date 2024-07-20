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

START_TEST(s21_eq_matrix_test_7) {
  matrix_t A = {0}, B = {0};

  int rows = 1;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 426.46246;
  B.matrix[0][0] = 426.46246;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_8) {
  matrix_t A = {0}, B = {0};
  int rows_1 = 3;
  int columns_1 = 5;
  int rows_2 = 4;
  int columns_2 = 7;
  s21_create_matrix(rows_1, columns_1, &A);
  s21_create_matrix(rows_2, columns_2, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_9) {
  matrix_t A = {0}, B = {0};
  int rows_1 = 31;
  int columns = 8;
  int rows_2 = 54;
  s21_create_matrix(rows_1, columns, &A);
  s21_create_matrix(rows_2, columns, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_10) {
  matrix_t A = {0}, B = {0};
  int rows = 11;
  int columns_1 = 4;
  int columns_2 = 8;
  s21_create_matrix(rows, columns_1, &A);
  s21_create_matrix(rows, columns_2, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_11) {
  matrix_t A = {0}, B = {0};
  int rows = 3;
  int columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_12) {
  matrix_t A = {0}, B = {0};
  int rows = 1;
  int columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 9081;
  A.matrix[0][1] = -5741;
  B.matrix[0][0] = -6346;
  B.matrix[0][1] = 4636;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_13) {
  matrix_t A = {0}, B = {0};
  int rows = 4;
  int columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = -42.0;
  A.matrix[0][1] = -6.0;
  A.matrix[0][2] = -66.0;
  A.matrix[0][3] = -4.0;
  A.matrix[0][4] = -96.0;
  A.matrix[1][0] = -14.0;
  A.matrix[1][1] = 40.0;
  A.matrix[1][2] = 56.0;
  A.matrix[1][3] = 92.0;
  A.matrix[1][4] = -7.0;
  A.matrix[2][0] = 33.0;
  A.matrix[2][1] = 64.0;
  A.matrix[2][2] = -91.0;
  A.matrix[2][3] = -34.0;
  A.matrix[2][4] = 55.0;
  A.matrix[3][0] = -79.0;
  A.matrix[3][1] = 51.0;
  A.matrix[3][2] = -75.0;
  A.matrix[3][3] = -26.0;
  A.matrix[3][4] = -3.0;
  B.matrix[0][0] = -42.00000000025071;
  B.matrix[0][1] = -6.0000000467236045;
  B.matrix[0][2] = -66.00000000847012;
  B.matrix[0][3] = -3.9999999180681494;
  B.matrix[0][4] = -96.00000005425697;
  B.matrix[1][0] = -13.999999960174542;
  B.matrix[1][1] = 39.99999991655606;
  B.matrix[1][2] = 55.99999994462708;
  B.matrix[1][3] = 92.00000002015003;
  B.matrix[1][4] = -6.99999997591102;
  B.matrix[2][0] = 32.99999999683639;
  B.matrix[2][1] = 63.99999995102012;
  B.matrix[2][2] = -91.00000000732605;
  B.matrix[2][3] = -33.999999952088494;
  B.matrix[2][4] = 55.000000087920355;
  B.matrix[3][0] = -79.00000004131194;
  B.matrix[3][1] = 51.00000002282117;
  B.matrix[3][2] = -74.99999992879957;
  B.matrix[3][3] = -26.00000004169098;
  B.matrix[3][4] = -3.0000000387943504;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_14) {
  matrix_t A = {0};
  int rows = 2;
  int columns = 1;
  s21_create_matrix(rows, columns, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_test_15) {
  matrix_t A = {0}, B = {0};
  int rows = 17;
  int columns = 6;
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 1.3;
      B.matrix[i][j] = 1.30;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_16) {
  matrix_t B = {0};
  int rows = 22;
  int columns = 15;
  s21_create_matrix(rows, columns, &B);
  ck_assert_int_eq(s21_eq_matrix(NULL, &B), FAILURE);
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
  tcase_add_test(tc, s21_eq_matrix_test_7);
  tcase_add_test(tc, s21_eq_matrix_test_8);
  tcase_add_test(tc, s21_eq_matrix_test_9);
  tcase_add_test(tc, s21_eq_matrix_test_10);
  tcase_add_test(tc, s21_eq_matrix_test_11);
  tcase_add_test(tc, s21_eq_matrix_test_12);
  tcase_add_test(tc, s21_eq_matrix_test_13);
  tcase_add_test(tc, s21_eq_matrix_test_14);
  tcase_add_test(tc, s21_eq_matrix_test_15);
  tcase_add_test(tc, s21_eq_matrix_test_16);
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