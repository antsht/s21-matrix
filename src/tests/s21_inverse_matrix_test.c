#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"
START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);

  ck_assert(res == OK);
  ck_assert(0.5 == result.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &A);
  s21_remove_matrix(&A);
  ck_assert(res == ERROR_INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  matrix_t expected = {0};
  s21_create_matrix(2, 2, &expected);
  expected.matrix[0][0] = -2;
  expected.matrix[0][1] = 1;
  expected.matrix[1][0] = 1.5;
  expected.matrix[1][1] = -0.5;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
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
  expected.matrix[0][0] = -1.0 / 3.0;
  expected.matrix[0][1] = 0;
  expected.matrix[0][2] = 0;
  expected.matrix[0][3] = 2.0 / 3.0;
  expected.matrix[1][0] = 0;
  expected.matrix[1][1] = -1.0 / 3.0;
  expected.matrix[1][2] = 2.0 / 3.0;
  expected.matrix[1][3] = 0;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 2.0 / 3.0;
  expected.matrix[2][2] = -1.0 / 3.0;
  expected.matrix[2][3] = 0;
  expected.matrix[3][0] = 2.0 / 3.0;
  expected.matrix[3][1] = 0;
  expected.matrix[3][2] = 0;
  expected.matrix[3][3] = -1.0 / 3.0;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);
  int comp_res = s21_eq_matrix(&expected, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
  ck_assert(res == OK && comp_res == SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  matrix_t result = {0};
  Matrix_operation_result res = 0;
  res = s21_inverse_matrix(&A, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  ck_assert(res == CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(0, -1, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), ERROR_INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_7) {
  matrix_t A = {0};
  matrix_t result = {0};
  s21_create_matrix(3, 2, &A);
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(res, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_8) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};

  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 57;
  A.matrix[0][1] = 453;
  A.matrix[1][0] = -99;
  A.matrix[1][1] = 36;

  s21_create_matrix(2, 2, &check_result);

  check_result.matrix[0][0] = 0.00076760698522356553;
  check_result.matrix[0][1] = -0.00965905456406319964;
  check_result.matrix[1][0] = 0.00211091920936480522;
  check_result.matrix[1][1] = 0.00121537772660397876;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_9) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};

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

  check_result.matrix[0][0] = 0.00000018;
  check_result.matrix[0][1] = 0.00000017;
  check_result.matrix[0][2] = 0.00000016;
  check_result.matrix[1][0] = -0.00000246;
  check_result.matrix[1][1] = 0.00014877;
  check_result.matrix[1][2] = 0.00013928;
  check_result.matrix[2][0] = 0.00000025;
  check_result.matrix[2][1] = -0.00001531;
  check_result.matrix[2][2] = 0.0000002;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_10) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check_result = {0};

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

  check_result.matrix[0][0] = -0.16400797484629245856;
  check_result.matrix[0][1] = 0.0360318502184232716;
  check_result.matrix[0][2] = 0.01603450522273765362;
  check_result.matrix[0][3] = 0.00876274340612470162;
  check_result.matrix[0][4] = 0.00500148729408351955;
  check_result.matrix[0][5] = 0.00270294189228057496;

  check_result.matrix[1][0] = 0.06543971050619623924;
  check_result.matrix[1][1] = -0.05220002753337807507;
  check_result.matrix[1][2] = 0.00662398993065030397;
  check_result.matrix[1][3] = 0.00528726900847880544;
  check_result.matrix[1][4] = 0.00459586163494182345;
  check_result.matrix[1][5] = 0.00417333490666922334;

  check_result.matrix[2][0] = 0.04740288952969548576;
  check_result.matrix[2][1] = 0.00858451394983516848;
  check_result.matrix[2][2] = -0.027336711088822186;
  check_result.matrix[2][3] = 0.00505557071530241237;
  check_result.matrix[2][4] = 0.00456881992433237704;
  check_result.matrix[2][5] = 0.00427136110762846656;

  check_result.matrix[3][0] = 0.04084404553824066631;
  check_result.matrix[3][1] = 0.0079607108528218025;
  check_result.matrix[3][2] = 0.00576848854046054492;
  check_result.matrix[3][3] = -0.01775595593676173057;
  check_result.matrix[3][4] = 0.00455898657501985107;
  check_result.matrix[3][5] = 0.00430700699888637319;

  check_result.matrix[4][0] = 0.03745154002541920797;
  check_result.matrix[4][1] = 0.00763805407850454424;
  check_result.matrix[4][2] = 0.00565048834871023332;
  check_result.matrix[4][3] = 0.00492773717423957481;
  check_result.matrix[4][4] = -0.01268747895048662787;
  check_result.matrix[4][5] = 0.00432544452884735938;

  check_result.matrix[5][0] = 0.03537834221202831677;
  check_result.matrix[5][1] = 0.00744087493864399752;
  check_result.matrix[5][2] = 0.00557837712041837624;
  check_result.matrix[5][3] = 0.00490110518651815031;
  check_result.matrix[5][4] = 0.00455079211725941277;
  check_result.matrix[5][5] = -0.00955217698062092684;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &check_result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check_result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_11) {
  matrix_t A = {0};
  matrix_t result_A = {0};
  matrix_t B = {0};
  matrix_t result_B = {0};
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

  ck_assert_int_eq(s21_inverse_matrix(&A, &result_A), CALCULATION_ERROR);
  ck_assert_int_eq(s21_inverse_matrix(&B, &result_B), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_inverse_matrix_test_12) {
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;

  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_inverse_matrix_suite(void) {
  Suite *s;
  s = suite_create("s21_inverse_matrix() tests");
  TCase *tc;
  tc = tcase_create("inverse_matrix");
  tcase_add_test(tc, s21_inverse_matrix_test_1);
  tcase_add_test(tc, s21_inverse_matrix_test_2);
  tcase_add_test(tc, s21_inverse_matrix_test_3);
  tcase_add_test(tc, s21_inverse_matrix_test_4);
  tcase_add_test(tc, s21_inverse_matrix_test_5);
  tcase_add_test(tc, s21_inverse_matrix_test_6);
  tcase_add_test(tc, s21_inverse_matrix_test_7);
  tcase_add_test(tc, s21_inverse_matrix_test_8);
  tcase_add_test(tc, s21_inverse_matrix_test_9);
  tcase_add_test(tc, s21_inverse_matrix_test_10);
  tcase_add_test(tc, s21_inverse_matrix_test_11);
  tcase_add_test(tc, s21_inverse_matrix_test_12);
  suite_add_tcase(s, tc);
  return s;
}

int s21_inverse_matrix_test(void) {
  Suite *s = s21_inverse_matrix_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return number_failed;
}