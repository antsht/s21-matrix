#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum {
  OK = 0,
  ERROR_INCORRECT_MATRIX = 1,
  CALCULATION_ERROR = 2
} Matrix_operation_result;

int s21_create_matrix(int rows, int columns, matrix_t* result);

void s21_remove_matrix(matrix_t* A);

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-7L

int s21_eq_matrix(matrix_t* A, matrix_t* B);

int s21_s___matrix(matrix_t *A, matrix_t *B, int b_sign, matrix_t *result);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void s21_print_matrix(matrix_t *A);

bool is_valid_matrix(matrix_t *A);

#endif