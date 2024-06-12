#include <check.h>

#include "../s21_matrix.h"
#include "s21_test.h"

START_TEST(s21_remove_matrix_test_1) {
    matrix_t m;
    Matrix_operation_result res = 0;
    res = s21_create_matrix(1, 1, &m);
    ck_assert(res == OK);
    s21_remove_matrix(&m);
    ck_assert(m.matrix == NULL);
}
END_TEST


Suite *s21_remove_matrix_suite(void) {
    Suite *s;
    s = suite_create("s21_matrix");
    TCase *tc;
    tc = tcase_create("remove_matrix");
    tcase_add_test(tc, s21_remove_matrix_test_1);
    suite_add_tcase(s, tc);
    return s;
}

int s21_remove_matrix_test(void) {
    Suite *s = s21_remove_matrix_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_NORMAL);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return number_failed;
}