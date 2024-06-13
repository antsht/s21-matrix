#include "s21_matrix.h"

#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  s21_remove_matrix(result);
  result->rows = rows;
  result->columns = columns;
  result->matrix = NULL;
  if (rows < 1 || columns < 1) return ERROR_INCORRECT_MATRIX;
  Matrix_operation_result status = OK;
  result->matrix = (double**)malloc(rows * sizeof(double*));
  if (result->matrix == NULL) status = ERROR_INCORRECT_MATRIX;

  for (int i = 0; i < rows && status == OK; i++) {
    result->matrix[i] = (double*)calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) status = ERROR_INCORRECT_MATRIX;
  }
  if (status != OK) s21_remove_matrix(result);
  return status;
}

void s21_remove_matrix(matrix_t* A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) || A->rows != B->rows ||
      A->columns != B->columns) {
    result = FAILURE;
  }
  if (A != B) {
    for (int i = 0; i < A->rows && result == SUCCESS; i++) {
      for (int j = 0; j < A->columns && result == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}

int s21_s___matrix(matrix_t* A, matrix_t* B, int b_sign, matrix_t* result) {
  int status = OK;
  if (A == result || B == result || !s21_is_valid_matrix(A) ||
      !s21_is_valid_matrix(B) || A->rows != B->rows || A->columns != B->columns) {
    status = ERROR_INCORRECT_MATRIX;
  }
  if (status == OK) {
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

int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  int status = OK;
  if (A == result || !s21_is_valid_matrix(A)) status = ERROR_INCORRECT_MATRIX;
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return status;
}
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int status = OK;
  if (A == result || B == result || !s21_is_valid_matrix(A) ||
      !s21_is_valid_matrix(B) || A->columns != B->rows)
    status = ERROR_INCORRECT_MATRIX;
  if (status == OK) {
    status = s21_create_matrix(A->rows, B->columns, result);
  }
  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return status;
}
int s21_transpose(matrix_t* A, matrix_t* result) {
  int status = OK;
  if (A == result || !s21_is_valid_matrix(A)) status = ERROR_INCORRECT_MATRIX;
  if (status == OK) {
    status = s21_create_matrix(A->columns, A->rows, result);
  }
  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}

int s21_get_minor(matrix_t* A, int row, int column, matrix_t* result) {
  int status = OK;
  if (A == result || !s21_is_valid_matrix(A)) {status = ERROR_INCORRECT_MATRIX;}
  if (status == OK) {
    status = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  }
  if (status == OK) {
    int i = 0, j = 0;
    for (int k = 0; k < A->rows; ++k) {
      if (k == row) continue;
      for (int l = 0; l < A->columns; ++l) {
        if (l == column) continue;
        result->matrix[i][j] = A->matrix[k][l];
        j++;
      }
      i++;
      j = 0;
    }
  }
  return status;
}

int s21_determinant(matrix_t* A, double* result) {
  int status = OK;
  if (!s21_is_valid_matrix(A)){
    status = ERROR_INCORRECT_MATRIX;}

  if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  }
  if (status == OK) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else {
      *result = 0;
      int sign = 1;
      for (int i = 0; i < A->rows && status == OK; ++i) {
        matrix_t minor = {0};
        s21_get_minor(A, 0, i, &minor);
        double minor_det = 0;
        status = s21_determinant(&minor, &minor_det);
        s21_remove_matrix(&minor);
        if (status == OK) {
          long double tmp_result = 0;
          tmp_result = (long double)(*result) + (long double)A->matrix[0][i] *
                                                    (long double)minor_det *
                                                    sign;
          if (fabsl(tmp_result) > DBL_MAX)
            status = CALCULATION_ERROR;
          else
            *result = (double)tmp_result;
        }
        sign *= (-1);
      }
    }
  }

  return status;
}

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  int status = OK;
  if (A == result || !s21_is_valid_matrix(A)) {
    status = ERROR_INCORRECT_MATRIX;
  }
  if (A->rows < 2 || A->columns < 2 || A->rows != A->columns) {
    status = CALCULATION_ERROR;
  }
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns && status == OK; j++) {
        matrix_t minor = {0};
        s21_get_minor(A, i, j, &minor);
        double minor_det = 0;
        status = s21_determinant(&minor, &minor_det);
        s21_remove_matrix(&minor);
        if (status == OK) {
          result->matrix[i][j] = pow(-1, i + j) * minor_det;
        }
      }
    }
  }
  return status;
}

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  int status = OK;
  if (A == result || !s21_is_valid_matrix(A)) {
    status = ERROR_INCORRECT_MATRIX;
  }
  if (A->rows < 2 || A->columns < 2 || A->rows != A->columns) {
    status = CALCULATION_ERROR;
  }
  double det = 0;
  if (status == OK) {
    status = s21_determinant(A, &det);
  }
  if (status == OK && det == 0) {
    status = CALCULATION_ERROR;
  }
  matrix_t complements = {0};
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, &complements);
  }
  if (status == OK) {
    status = s21_calc_complements(A, &complements);
  }
  matrix_t transposed = {0};
  if (status == OK) {
    status =
        s21_create_matrix(complements.columns, complements.rows, &transposed);
  }
  if (status == OK) {
    status = s21_transpose(&complements, &transposed);
  }
  s21_remove_matrix(&complements);
  if (status == OK) {
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    status = s21_mult_number(&transposed, 1.0 / det, result);
  }
  s21_remove_matrix(&transposed);
  return status;
}

void s21_print_matrix(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%f ", A->matrix[i][j]);
    }
    printf("\n");
  }
}

bool s21_is_valid_matrix(matrix_t* A) {
  return A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0;
}