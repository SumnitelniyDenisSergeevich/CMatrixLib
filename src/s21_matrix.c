#include "s21_matrix.h"

#include <math.h>
#include <stdlib.h>

int alloc_matr(matrix_t* result) {
  int err = 0;
  if ((result->matrix = (double**)malloc(sizeof(double*) * result->rows))) {
    for (int i = 0; i < result->rows && !err; ++i) {
      if (!(result->matrix[i] =
                (double*)malloc(sizeof(double) * result->columns))) {
        for (int j = 0; j < i; ++j) {
          free(result->matrix[j]);
        }
        free(result->matrix);
        err = 1;
      }
    }
  } else {
    err = 1;
  }
  return err;
}

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int err = 1;
  if (rows > 0 && columns > 0) {
    result->columns = columns;
    result->rows = rows;
    err = alloc_matr(result);
  }
  if (!err) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        result->matrix[i][j] = 0;
      }
    }
  } else {
    result->matrix = NULL;
    result->columns = 0;
    result->rows = 0;
  }
  return err;
}

void s21_remove_matrix(matrix_t* A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; ++i) {
        free(A->matrix[i]);
      }
      free(A->matrix);
      A->matrix = NULL;
    }
    A->columns = 0;
    A->rows = 0;
  }
}

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  if ((A->columns != B->columns) || (A->rows != B->rows)) {
    result = FAILURE;
  } else {
    for (int i = 0; i < A->rows && result; ++i) {
      for (int j = 0; j < A->columns && result; ++j) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}

int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0 ||
      B == NULL || B->matrix == NULL || B->rows <= 0 || B->columns <= 0) {
    err = 1;
  } else if (A->rows == B->rows && A->columns == B->columns) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  } else {
    err = 2;
  }
  return err;
}

int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0 ||
      B == NULL || B->matrix == NULL || B->rows <= 0 || B->columns <= 0) {
    err = 1;
  } else if (A->rows == B->rows && A->columns == B->columns) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  } else {
    err = 2;
  }
  return err;
}

int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    err = 1;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }
  return err;
}

void s21_mult_matr(matrix_t* A, matrix_t* B, matrix_t* result) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < B->columns; ++j) {
      for (int z = 0; z < A->columns; ++z) {
        result->matrix[i][j] += A->matrix[i][z] * B->matrix[z][j];
      }
    }
  }
}

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0 ||
      B == NULL || B->matrix == NULL || B->rows <= 0 || B->columns <= 0) {
    err = 1;
  } else if (A->columns != B->rows) {
    err = 2;
  } else {
    if (!(err = s21_create_matrix(A->rows, B->columns, result))) {
      s21_mult_matr(A, B, result);
    }
  }
  return err;
}

int s21_transpose(matrix_t* A, matrix_t* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    err = 1;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int row = 0; row < A->rows; ++row) {
      for (int col = 0; col < A->columns; ++col) {
        result->matrix[col][row] = A->matrix[row][col];
      }
    }
  }
  return err;
}

int s21_determinant(matrix_t* A, double* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    err = 1;
  } else if (A->rows != A->columns) {
    err = 2;
  } else {
    if (A->rows == 1)
      *result = A->matrix[0][0];
    else if (A->rows == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    else {
      *result = 0;
      matrix_t temp;
      temp.rows = A->rows - 1;
      temp.columns = A->columns - 1;
      temp.matrix = (double**)malloc(sizeof(double*) * temp.rows);
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < temp.rows; ++j) {
          temp.matrix[j] = j < i ? A->matrix[j] : A->matrix[j + 1];
        }
        double k = ((i + A->columns - 1) % 2 ? -1. : 1.);
        double val = 0.;
        s21_determinant(&temp, &val);
        *result += k * A->matrix[i][A->columns - 1] * val;
      }
      free(temp.matrix);
    }
  }
  return err;
}

void s21_get_matrix_without_row_col(int row, int col, matrix_t* A,
                                    matrix_t* result) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      int t_row = i >= row ? 1 : 0;
      int t_col = j >= col ? 1 : 0;
      result->matrix[i][j] = A->matrix[i + t_row][j + t_col];
    }
  }
}

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    err = 1;
  } else if (A->rows != A->columns) {
    err = 2;
  } else if (A->rows == 1) {
    err = 1;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        matrix_t matr_without_row_col = {0};
        s21_get_matrix_without_row_col(i, j, A, &matr_without_row_col);
        double det;
        s21_determinant(&matr_without_row_col, &det);
        int k = (i + j) % 2 ? -1 : 1;
        result->matrix[i][j] = det * k;
        s21_remove_matrix(&matr_without_row_col);
      }
    }
  }
  return err;
}

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  int err = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0) {
    err = 1;
  } else if (A->rows != A->columns) {
    err = 2;
  } else if (A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1. / A->matrix[0][0];
  } else {
    double det;
    s21_determinant(A, &det);
    if (fabs(det) > 1e-6) {
      matrix_t minors_matr;  // = {0};
      s21_calc_complements(A, &minors_matr);
      matrix_t transpoir_minors_matr = {0};
      s21_transpose(&minors_matr, &transpoir_minors_matr);
      det = 1. / det;
      s21_mult_number(&transpoir_minors_matr, det, result);
      s21_remove_matrix(&minors_matr);
      s21_remove_matrix(&transpoir_minors_matr);
    } else {
      err = 2;
    }
  }
  return err;
}
