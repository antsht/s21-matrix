#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum {
  OK = 0,
  ERROR_INCORRECT_MATRIX = 1,
  CALCULATION_ERROR = 2
} Matrix_operation_result;

int s21_create_matrix(int rows, int columns, matrix_t *result);

void s21_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-6L

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_s___matrix(matrix_t *A, matrix_t *B, int b_sign, matrix_t *result);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_get_minor(matrix_t *A, int row, int column, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

void s21_swap_rows(matrix_t *A, int i, int j);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void s21_print_matrix(matrix_t *A);

bool s21_is_valid_matrix(const matrix_t *A);

void fill_matrix(int rows, int columns, matrix_t *result);

#endif