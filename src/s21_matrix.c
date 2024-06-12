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


/*
#define SUCCESS 1
#define FAILURE 0
int s21_eq_matrix(matrix_t* A, matrix_t* B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);
*/