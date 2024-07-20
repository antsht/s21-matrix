#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_calc_complements_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;

  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_calc_complements(&A, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  Matrix_operation_result res = 0;
  res = s21_calc_complements(&A, &A);
  s21_remove_matrix(&A);
  ck_assert(res == ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = 4;
  expected.matrix[0][1] = -3;
  expected.matrix[1][0] = -2;
  expected.matrix[1][1] = 1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_calc_complements(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 2;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 2;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;
  matrix_t expected = {0};
  s21_create_matrix(4, 4, &expected);
  expected.matrix[0][0] = -3;
  expected.matrix[0][1] = 0;
  expected.matrix[0][2] = 0;
  expected.matrix[0][3] = 6;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = -3;
  expected.matrix[1][2] = 6;
  expected.matrix[1][3] = 0;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 6;
  expected.matrix[2][2] = -3;
  expected.matrix[2][3] = 0;
  expected.matrix[3][0] = 6;
  expected.matrix[3][1] = 0;
  expected.matrix[3][2] = 0;
  expected.matrix[3][3] = -3;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_calc_complements(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t A = {0};
  matrix_t expected = {0};
  matrix_t result = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &expected);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  expected.matrix[0][0] = 0;
  expected.matrix[0][1] = 10;
  expected.matrix[0][2] = -20;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = -14;
  expected.matrix[1][2] = 8;
  expected.matrix[2][0] = -8;
  expected.matrix[2][1] = -2;
  expected.matrix[2][2] = 4;

  int res = s21_calc_complements(&A, &result);

  ck_assert_int_eq(res, OK);

  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq(result.matrix[i][j], expected.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_6) {
  matrix_t result = {0};
  matrix_t A = {0};
  s21_create_matrix(0, 0, &A);

  ck_assert_int_eq(s21_calc_complements(&A, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_7) {
  matrix_t result = {0};
  matrix_t A = {0};
  s21_create_matrix(3, 2, &A);

  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_8) {
  matrix_t result = {0};
  matrix_t check_result = {0};
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 57;
  A.matrix[0][1] = 453;
  A.matrix[1][0] = -99;
  A.matrix[1][1] = 36;

  s21_create_matrix(2, 2, &check_result);

  check_result.matrix[0][0] = 36;
  check_result.matrix[0][1] = 99;
  check_result.matrix[1][0] = -453;
  check_result.matrix[1][1] = 57;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_calc_complements_test_9) {
  matrix_t result = {0};
  matrix_t check_result = {0};
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

  s21_create_matrix(3, 3, &check_result);

  check_result.matrix[0][0] = 454625198.04130000;
  check_result.matrix[0][1] = -6190029535.26322937;
  check_result.matrix[0][2] = 636881490.61134005;
  check_result.matrix[1][0] = 449715906.09049994;
  check_result.matrix[1][1] = 373680842215.31268311;
  check_result.matrix[1][2] = -38474072833.33669281;
  check_result.matrix[2][0] = 420573840;
  check_result.matrix[2][1] = 349828956570.17999268;
  check_result.matrix[2][2] = 517357612.38000005;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_calc_complements_test_10) {
  matrix_t result = {0};
  matrix_t check_result = {0};
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

  s21_create_matrix(6, 6, &check_result);

  check_result.matrix[0][0] = 153711360;
  check_result.matrix[0][1] = -61331328;
  check_result.matrix[0][2] = -44426880;
  check_result.matrix[0][3] = -38279808;
  check_result.matrix[0][4] = -35100288;
  check_result.matrix[0][5] = -33157248;

  check_result.matrix[1][0] = -33769728;
  check_result.matrix[1][1] = 48922848;
  check_result.matrix[1][2] = -8045568;
  check_result.matrix[1][3] = -7460928;
  check_result.matrix[1][4] = -7158528;
  check_result.matrix[1][5] = -6973728;

  check_result.matrix[2][0] = -15027840;
  check_result.matrix[2][1] = -6208128;
  check_result.matrix[2][2] = 25620480;
  check_result.matrix[2][3] = -5406336;
  check_result.matrix[2][4] = -5295744;
  check_result.matrix[2][5] = -5228160;

  check_result.matrix[3][0] = -8212608;
  check_result.matrix[3][1] = -4955328;
  check_result.matrix[3][2] = -4738176;
  check_result.matrix[3][3] = 16641216;
  check_result.matrix[3][4] = -4618368;
  check_result.matrix[3][5] = -4593408;

  check_result.matrix[4][0] = -4687488;
  check_result.matrix[4][1] = -4307328;
  check_result.matrix[4][2] = -4281984;
  check_result.matrix[4][3] = -4272768;
  check_result.matrix[4][4] = 11890944;
  check_result.matrix[4][5] = -4265088;

  check_result.matrix[5][0] = -2533248;
  check_result.matrix[5][1] = -3911328;
  check_result.matrix[5][2] = -4003200;
  check_result.matrix[5][3] = -4036608;
  check_result.matrix[5][4] = -4053888;
  check_result.matrix[5][5] = 8952480;

  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s;
  s = suite_create("s21_calc_complements() tests");
  TCase *tc;
  tc = tcase_create("calc_complements");
  tcase_add_test(tc, s21_calc_complements_test_1);
  tcase_add_test(tc, s21_calc_complements_test_2);
  tcase_add_test(tc, s21_calc_complements_test_3);
  tcase_add_test(tc, s21_calc_complements_test_4);
  tcase_add_test(tc, s21_calc_complements_test_5);
  tcase_add_test(tc, s21_calc_complements_test_6);
  tcase_add_test(tc, s21_calc_complements_test_7);
  tcase_add_test(tc, s21_calc_complements_test_8);
  tcase_add_test(tc, s21_calc_complements_test_9);
  tcase_add_test(tc, s21_calc_complements_test_10);
  suite_add_tcase(s, tc);
  return s;
}

int s21_calc_complements_test(void) {
  Suite *s = s21_calc_complements_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}