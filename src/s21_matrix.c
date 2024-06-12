#include "s21_matrix.h"

#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  result->rows = rows;
  result->columns = columns;
  result->matrix = NULL;
  if (rows < 1 || columns < 1) return ERROR_INCORRECT_MATRIX;
  Matrix_operation_result status = OK;
  result->matrix = (double**)malloc(rows * sizeof(double*));
  if (result->matrix == NULL) status = ERROR_INCORRECT_MATRIX;

  for (int i = 0; i < rows && status == OK; i++) {
    result->matrix[i] = (double*)malloc(columns * sizeof(double));
    if (result->matrix[i] == NULL) status = ERROR_INCORRECT_MATRIX;
  }
  if (status != OK) s21_remove_matrix(result);
  return status;
}

void s21_remove_matrix(matrix_t* A) {
  if (A != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) result = FAILURE;
  for (int i = 0; i < A->rows && result == SUCCESS; i++) {
    for (int j = 0; j < A->columns && result == SUCCESS; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) result = FAILURE;
    }
  }
  return result;
}

int s21_s___matrix(matrix_t* A, matrix_t* B, int b_sign, matrix_t* result) {
  int status = OK;
  if (A->rows != B->rows || A->columns != B->columns) {
    status = ERROR_INCORRECT_MATRIX;
  }
  if (status == OK) {
    s21_remove_matrix(result);
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + b_sign * B->matrix[i][j];
      }
    }
  }

  return status;
}
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  return s21_s___matrix(A, B, 1, result);
}
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  return s21_s___matrix(A, B, -1, result);
}
/*

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);
*/

void s21_print_matrix(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%f ", A->matrix[i][j]);
    }
    printf("\n");
  }
}