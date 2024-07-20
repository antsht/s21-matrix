#include "s21_matrix.h"

#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (result == NULL) return ERROR_INCORRECT_MATRIX;
  if (rows < 1 || columns < 1) return ERROR_INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = NULL;

  Matrix_operation_result status = OK;
  result->matrix = (double**)calloc(rows, sizeof(double*));
  if (result->matrix == NULL) status |= ERROR_INCORRECT_MATRIX;

  for (int i = 0; i < rows && status == OK; i++) {
    result->matrix[i] = (double*)calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) status |= ERROR_INCORRECT_MATRIX;
  }
  if (status != OK) s21_remove_matrix(result);
  return status;
}

void s21_remove_matrix(matrix_t* A) {
  if (A == NULL) return;

  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
        A->matrix[i] = NULL;
      }
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) ||
      A->rows != B->rows || A->columns != B->columns || A == NULL ||
      B == NULL) {
    return FAILURE;
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
      !s21_is_valid_matrix(B))
    return ERROR_INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return CALCULATION_ERROR;

  status = s21_create_matrix(A->rows, A->columns, result);

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
    s21_remove_matrix(result);
    status = s21_create_matrix(A->rows, A->columns, result);
  }
  if (status == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] =
            ((long double)A->matrix[i][j]) * ((long double)number);
      }
    }
  }

  return status;
}
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int status = OK;
  if (A == result || B == result || !s21_is_valid_matrix(A) ||
      !s21_is_valid_matrix(B))
    return ERROR_INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALCULATION_ERROR;

  status = s21_create_matrix(A->rows, B->columns, result);

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
  if (A == result || !s21_is_valid_matrix(A)) return ERROR_INCORRECT_MATRIX;

  status = s21_create_matrix(A->columns, A->rows, result);

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
  if (A == NULL || !s21_is_valid_matrix(A)) return ERROR_INCORRECT_MATRIX;

  if (A == result || result == NULL || row < 0 || row > (A->rows - 1) ||
      column < 0 || column > (A->columns - 1))
    return CALCULATION_ERROR;

  status = s21_create_matrix(A->rows - 1, A->columns - 1, result);

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

  if (status != OK) s21_remove_matrix(result);

  return status;
}

void s21_swap_rows(matrix_t* A, int i, int j) {
  if (!A) return;
  for (int k = 0; k < A->columns; ++k) {
    double temp = A->matrix[i][k];
    A->matrix[i][k] = A->matrix[j][k];
    A->matrix[j][k] = temp;
  }
}

int s21_determinant(matrix_t* A, double* result) {
  int status = OK;
  if (A == NULL || result == NULL || A->rows != A->columns)
    return CALCULATION_ERROR;
  if (!s21_is_valid_matrix(A)) return ERROR_INCORRECT_MATRIX;

  long double l_result = 1.0;
  matrix_t temp = {0};
  s21_create_matrix(A->rows, A->columns, &temp);

  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) temp.matrix[i][j] = A->matrix[i][j];

  int n = temp.rows;
  for (int i = 0; i < n && status == OK; ++i) {
    if (fabs(temp.matrix[i][i]) < EPSILON) {
      int j = i + 1;
      while (j < n && fabs(temp.matrix[j][i]) < EPSILON) ++j;
      if (j < n) {
        s21_swap_rows(&temp, i, j);
        l_result *= -1;
      } else {
        l_result = 0;
        break;
      }
    }
    double diag_elem = temp.matrix[i][i];
    if (fabs(diag_elem) > EPSILON) {
      l_result *= diag_elem;
      for (int k = 0; k < n; ++k) temp.matrix[i][k] /= diag_elem;
      for (int j = 0; j < n; ++j)
        if (j != i) {
          long double multiplier = temp.matrix[j][i];
          for (int k = 0; k < n; ++k)
            temp.matrix[j][k] -= (double)(multiplier * temp.matrix[i][k]);
        }
    }
  }

  if (fabsl(l_result) > DBL_MAX)
    status = CALCULATION_ERROR;
  else
    *result = (double)l_result;
  s21_remove_matrix(&temp);

  return status;
}

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  int status = OK;
  if (A == result || !s21_is_valid_matrix(A)) return ERROR_INCORRECT_MATRIX;

  if (A->rows < 2 || A->columns < 2 || A->rows != A->columns)
    return CALCULATION_ERROR;

  status = s21_create_matrix(A->rows, A->columns, result);

  if (status == OK) {
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns && status == OK; j++) {
        matrix_t minor = {0};
        status |= s21_get_minor(A, i, j, &minor);
        double minor_det = 0;
        if (status == OK) status |= s21_determinant(&minor, &minor_det);
        s21_remove_matrix(&minor);
        if (status == OK) result->matrix[i][j] = pow(-1, i + j) * minor_det;
      }
    }
  }

  if (status != OK) s21_remove_matrix(result);

  return status;
}

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  int status = OK;
  if (A == result || !s21_is_valid_matrix(A)) return ERROR_INCORRECT_MATRIX;

  if (A->rows != A->columns) return CALCULATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1) {
    result->matrix[0][0] = 1 / A->matrix[0][0];
  } else {
    double det = 0;
    if (status == OK) {
      status = s21_determinant(A, &det);
    }
    if (status == OK && det == 0) {
      status = CALCULATION_ERROR;
    }
    matrix_t complements = {0};

    if (status == OK) {
      status = s21_calc_complements(A, &complements);
    }
    matrix_t transposed = {0};

    if (status == OK) {
      status |= s21_transpose(&complements, &transposed);
    }
    s21_remove_matrix(&complements);

    if (status == OK) {
      status |= s21_mult_number(&transposed, 1.0 / det, result);
    }
    s21_remove_matrix(&transposed);
  }

  if (status != OK) s21_remove_matrix(result);

  return status;
}

void s21_print_matrix(matrix_t* A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      printf("%.8f ", A->matrix[i][j]);
    }
    printf("\n");
  }
}

bool s21_is_valid_matrix(const matrix_t* A) {
  return A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0;
}