#include <check.h>
#include <stdio.h>  //delete

#include "s21_matrix.h"

#define OK 0
#define ERROR_INIT 1
#define ERROR_CALC 2
#define MAX_DOUBLE 1.79769e+308
#define MIN_DOUBLE 2.22507e-308

void s21_init_matrix(double val, matrix_t *A) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      A->matrix[i][j] = val++;
    }
  }
}

START_TEST(s21_create_matrix_01) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(result, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_02) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(result, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_03) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(result, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_04) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(9, 4, &A);
  ck_assert_int_eq(result, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_05) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(10, 15, &A);
  ck_assert_int_eq(result, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_06) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_create_matrix_07) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(1, 0, &A);
  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_create_matrix_08) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(0, 1, &A);
  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_create_matrix_09) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(-1, 1, &A);
  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_remove_matrix_01) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    result = ERROR_INIT;
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_remove_matrix_02) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    result = ERROR_INIT;
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_remove_matrix_03) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    result = ERROR_INIT;
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_remove_matrix_04) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    result = ERROR_INIT;
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_remove_matrix_05) {
  int result = 0;
  matrix_t A = {0};

  result = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    result = ERROR_INIT;
  }
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_eq_matrix_01) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(1.0, &B);

  result = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_eq_matrix_02) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(2.0, &B);

  result = s21_eq_matrix(&B, &A);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_03) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(3, 4, &B);
  s21_init_matrix(1.0, &B);

  result = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_04) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(10.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(-10.0, &B);

  result = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_05) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 3, &B);
  s21_init_matrix(1.0, &B);
  result = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(result, FAILURE);
}
END_TEST

START_TEST(s21_eq_matrix_06) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(10, 10, &B);
  s21_init_matrix(1.0, &B);

  result = s21_eq_matrix(&A, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_01) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_sum_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 2.0;
  ORIGIN.matrix[0][1] = 4.0;
  ORIGIN.matrix[0][2] = 6.0;
  ORIGIN.matrix[0][3] = 8.0;
  ORIGIN.matrix[1][0] = 10.0;
  ORIGIN.matrix[1][1] = 12.0;
  ORIGIN.matrix[1][2] = 14.0;
  ORIGIN.matrix[1][3] = 16.0;
  ORIGIN.matrix[2][0] = 18.0;
  ORIGIN.matrix[2][1] = 20.0;
  ORIGIN.matrix[2][2] = 22.0;
  ORIGIN.matrix[2][3] = 24.0;
  ORIGIN.matrix[3][0] = 26.0;
  ORIGIN.matrix[3][1] = 28.0;
  ORIGIN.matrix[3][2] = 30.0;
  ORIGIN.matrix[3][3] = 32.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_02) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(0.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(2.0, &B);

  s21_sum_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 2.0;
  ORIGIN.matrix[0][1] = 4.0;
  ORIGIN.matrix[0][2] = 6.0;
  ORIGIN.matrix[0][3] = 8.0;
  ORIGIN.matrix[1][0] = 10.0;
  ORIGIN.matrix[1][1] = 12.0;
  ORIGIN.matrix[1][2] = 14.0;
  ORIGIN.matrix[1][3] = 16.0;
  ORIGIN.matrix[2][0] = 18.0;
  ORIGIN.matrix[2][1] = 20.0;
  ORIGIN.matrix[2][2] = 22.0;
  ORIGIN.matrix[2][3] = 24.0;
  ORIGIN.matrix[3][0] = 26.0;
  ORIGIN.matrix[3][1] = 28.0;
  ORIGIN.matrix[3][2] = 30.0;
  ORIGIN.matrix[3][3] = 32.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_03) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-3.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(5.0, &B);

  s21_sum_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 2.0;
  ORIGIN.matrix[0][1] = 4.0;
  ORIGIN.matrix[0][2] = 6.0;
  ORIGIN.matrix[0][3] = 8.0;
  ORIGIN.matrix[1][0] = 10.0;
  ORIGIN.matrix[1][1] = 12.0;
  ORIGIN.matrix[1][2] = 14.0;
  ORIGIN.matrix[1][3] = 16.0;
  ORIGIN.matrix[2][0] = 18.0;
  ORIGIN.matrix[2][1] = 20.0;
  ORIGIN.matrix[2][2] = 22.0;
  ORIGIN.matrix[2][3] = 24.0;
  ORIGIN.matrix[3][0] = 26.0;
  ORIGIN.matrix[3][1] = 28.0;
  ORIGIN.matrix[3][2] = 30.0;
  ORIGIN.matrix[3][3] = 32.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_04) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-3.0, &B);

  s21_sum_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 2.0;
  ORIGIN.matrix[0][1] = 4.0;
  ORIGIN.matrix[0][2] = 6.0;
  ORIGIN.matrix[0][3] = 8.0;
  ORIGIN.matrix[1][0] = 10.0;
  ORIGIN.matrix[1][1] = 12.0;
  ORIGIN.matrix[1][2] = 14.0;
  ORIGIN.matrix[1][3] = 16.0;
  ORIGIN.matrix[2][0] = 18.0;
  ORIGIN.matrix[2][1] = 20.0;
  ORIGIN.matrix[2][2] = 22.0;
  ORIGIN.matrix[2][3] = 24.0;
  ORIGIN.matrix[3][0] = 26.0;
  ORIGIN.matrix[3][1] = 28.0;
  ORIGIN.matrix[3][2] = 30.0;
  ORIGIN.matrix[3][3] = 32.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_05) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(1.0, &B);

  s21_sum_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = 2.0;
  ORIGIN.matrix[0][1] = 4.0;
  ORIGIN.matrix[1][0] = 6.0;
  ORIGIN.matrix[1][1] = 8.0;
  ORIGIN.matrix[2][0] = 10.0;
  ORIGIN.matrix[2][1] = 12.0;
  ORIGIN.matrix[3][0] = 14.0;
  ORIGIN.matrix[3][1] = 16.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_06) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(3.0, &B);

  s21_sum_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = 2.0;
  ORIGIN.matrix[0][1] = 4.0;
  ORIGIN.matrix[1][0] = 6.0;
  ORIGIN.matrix[1][1] = 8.0;
  ORIGIN.matrix[2][0] = 10.0;
  ORIGIN.matrix[2][1] = 12.0;
  ORIGIN.matrix[3][0] = 14.0;
  ORIGIN.matrix[3][1] = 16.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_07) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(4.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(-2.0, &B);

  s21_sum_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = 2.0;
  ORIGIN.matrix[0][1] = 4.0;
  ORIGIN.matrix[1][0] = 6.0;
  ORIGIN.matrix[1][1] = 8.0;
  ORIGIN.matrix[2][0] = 10.0;
  ORIGIN.matrix[2][1] = 12.0;
  ORIGIN.matrix[3][0] = 14.0;
  ORIGIN.matrix[3][1] = 16.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sum_matrix_08) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(4, 2, &A);

  s21_create_matrix(4, 3, &B);

  result = s21_sum_matrix(&A, &B, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, ERROR_CALC);
}
END_TEST

START_TEST(s21_sub_matrix_01) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_sub_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 0.0;
  ORIGIN.matrix[0][1] = 0.0;
  ORIGIN.matrix[0][2] = 0.0;
  ORIGIN.matrix[0][3] = 0.0;
  ORIGIN.matrix[1][0] = 0.0;
  ORIGIN.matrix[1][1] = 0.0;
  ORIGIN.matrix[1][2] = 0.0;
  ORIGIN.matrix[1][3] = 0.0;
  ORIGIN.matrix[2][0] = 0.0;
  ORIGIN.matrix[2][1] = 0.0;
  ORIGIN.matrix[2][2] = 0.0;
  ORIGIN.matrix[2][3] = 0.0;
  ORIGIN.matrix[3][0] = 0.0;
  ORIGIN.matrix[3][1] = 0.0;
  ORIGIN.matrix[3][2] = 0.0;
  ORIGIN.matrix[3][3] = 0.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_02) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(0.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(2.0, &B);

  s21_sub_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = -2.0;
  ORIGIN.matrix[0][1] = -2.0;
  ORIGIN.matrix[0][2] = -2.0;
  ORIGIN.matrix[0][3] = -2.0;
  ORIGIN.matrix[1][0] = -2.0;
  ORIGIN.matrix[1][1] = -2.0;
  ORIGIN.matrix[1][2] = -2.0;
  ORIGIN.matrix[1][3] = -2.0;
  ORIGIN.matrix[2][0] = -2.0;
  ORIGIN.matrix[2][1] = -2.0;
  ORIGIN.matrix[2][2] = -2.0;
  ORIGIN.matrix[2][3] = -2.0;
  ORIGIN.matrix[3][0] = -2.0;
  ORIGIN.matrix[3][1] = -2.0;
  ORIGIN.matrix[3][2] = -2.0;
  ORIGIN.matrix[3][3] = -2.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_03) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-3.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(5.0, &B);

  s21_sub_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = -8.0;
  ORIGIN.matrix[0][1] = -8.0;
  ORIGIN.matrix[0][2] = -8.0;
  ORIGIN.matrix[0][3] = -8.0;
  ORIGIN.matrix[1][0] = -8.0;
  ORIGIN.matrix[1][1] = -8.0;
  ORIGIN.matrix[1][2] = -8.0;
  ORIGIN.matrix[1][3] = -8.0;
  ORIGIN.matrix[2][0] = -8.0;
  ORIGIN.matrix[2][1] = -8.0;
  ORIGIN.matrix[2][2] = -8.0;
  ORIGIN.matrix[2][3] = -8.0;
  ORIGIN.matrix[3][0] = -8.0;
  ORIGIN.matrix[3][1] = -8.0;
  ORIGIN.matrix[3][2] = -8.0;
  ORIGIN.matrix[3][3] = -8.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_04) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-3.0, &B);

  s21_sub_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 8.0;
  ORIGIN.matrix[0][1] = 8.0;
  ORIGIN.matrix[0][2] = 8.0;
  ORIGIN.matrix[0][3] = 8.0;
  ORIGIN.matrix[1][0] = 8.0;
  ORIGIN.matrix[1][1] = 8.0;
  ORIGIN.matrix[1][2] = 8.0;
  ORIGIN.matrix[1][3] = 8.0;
  ORIGIN.matrix[2][0] = 8.0;
  ORIGIN.matrix[2][1] = 8.0;
  ORIGIN.matrix[2][2] = 8.0;
  ORIGIN.matrix[2][3] = 8.0;
  ORIGIN.matrix[3][0] = 8.0;
  ORIGIN.matrix[3][1] = 8.0;
  ORIGIN.matrix[3][2] = 8.0;
  ORIGIN.matrix[3][3] = 8.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_05) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(1.0, &B);

  s21_sub_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = 0.0;
  ORIGIN.matrix[0][1] = 0.0;
  ORIGIN.matrix[1][0] = 0.0;
  ORIGIN.matrix[1][1] = 0.0;
  ORIGIN.matrix[2][0] = 0.0;
  ORIGIN.matrix[2][1] = 0.0;
  ORIGIN.matrix[3][0] = 0.0;
  ORIGIN.matrix[3][1] = 0.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_06) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(3.0, &B);

  s21_sub_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = -4.0;
  ORIGIN.matrix[0][1] = -4.0;
  ORIGIN.matrix[1][0] = -4.0;
  ORIGIN.matrix[1][1] = -4.0;
  ORIGIN.matrix[2][0] = -4.0;
  ORIGIN.matrix[2][1] = -4.0;
  ORIGIN.matrix[3][0] = -4.0;
  ORIGIN.matrix[3][1] = -4.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_07) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(4.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(-2.0, &B);

  s21_sub_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = 6.0;
  ORIGIN.matrix[0][1] = 6.0;
  ORIGIN.matrix[1][0] = 6.0;
  ORIGIN.matrix[1][1] = 6.0;
  ORIGIN.matrix[2][0] = 6.0;
  ORIGIN.matrix[2][1] = 6.0;
  ORIGIN.matrix[3][0] = 6.0;
  ORIGIN.matrix[3][1] = 6.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_sub_matrix_08) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(4, 2, &A);

  s21_create_matrix(4, 3, &B);

  result = s21_sub_matrix(&A, &B, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, ERROR_CALC);
}
END_TEST

START_TEST(s21_transpose_01) {
  int result = 0;
  matrix_t A = {0};

  result = s21_transpose(&A, &A);
  ck_assert_int_eq(result, ERROR_INIT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_02) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 4, &B);
  s21_init_matrix(1.0, &B);
  result = s21_transpose(&A, &B);
  result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_03) {
  int result = 0;
  matrix_t A = {0};
  matrix_t T = {0};
  matrix_t B = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;

  result = s21_transpose(&A, &T);
  result = s21_eq_matrix(&T, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&T);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_number_01) {
  int result = 0;
  double number = 3.0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);

  s21_init_matrix(1.0, &A);

  s21_mult_number(&A, number, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 3.0;
  ORIGIN.matrix[0][1] = 6.0;
  ORIGIN.matrix[0][2] = 9.0;
  ORIGIN.matrix[0][3] = 12.0;
  ORIGIN.matrix[1][0] = 15.0;
  ORIGIN.matrix[1][1] = 18.0;
  ORIGIN.matrix[1][2] = 21.0;
  ORIGIN.matrix[1][3] = 24.0;
  ORIGIN.matrix[2][0] = 27.0;
  ORIGIN.matrix[2][1] = 30.0;
  ORIGIN.matrix[2][2] = 33.0;
  ORIGIN.matrix[2][3] = 36.0;
  ORIGIN.matrix[3][0] = 39.0;
  ORIGIN.matrix[3][1] = 42.0;
  ORIGIN.matrix[3][2] = 45.0;
  ORIGIN.matrix[3][3] = 48.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_02) {
  int result = 0;
  double number = 5.0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_mult_number(&A, number, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 5.0;
  ORIGIN.matrix[0][1] = 10.0;
  ORIGIN.matrix[0][2] = 15.0;
  ORIGIN.matrix[0][3] = 20.0;
  ORIGIN.matrix[1][0] = 25.0;
  ORIGIN.matrix[1][1] = 30.0;
  ORIGIN.matrix[1][2] = 35.0;
  ORIGIN.matrix[1][3] = 40.0;
  ORIGIN.matrix[2][0] = 45.0;
  ORIGIN.matrix[2][1] = 50.0;
  ORIGIN.matrix[2][2] = 55.0;
  ORIGIN.matrix[2][3] = 60.0;
  ORIGIN.matrix[3][0] = 65.0;
  ORIGIN.matrix[3][1] = 70.0;
  ORIGIN.matrix[3][2] = 75.0;
  ORIGIN.matrix[3][3] = 80.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_03) {
  int result = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = 4.0;
  ORIGIN.matrix[0][1] = 6.0;
  ORIGIN.matrix[1][0] = 8.0;
  ORIGIN.matrix[1][1] = 10.0;
  ORIGIN.matrix[2][0] = 12.0;
  ORIGIN.matrix[2][1] = 14.0;
  ORIGIN.matrix[3][0] = 16.0;
  ORIGIN.matrix[3][1] = 18.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_04) {
  int result = 0;
  double number = -2.0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &RESULT);

  s21_create_matrix(4, 2, &ORIGIN);

  ORIGIN.matrix[0][0] = -4.0;
  ORIGIN.matrix[0][1] = -6.0;
  ORIGIN.matrix[1][0] = -8.0;
  ORIGIN.matrix[1][1] = -10.0;
  ORIGIN.matrix[2][0] = -12.0;
  ORIGIN.matrix[2][1] = -14.0;
  ORIGIN.matrix[3][0] = -16.0;
  ORIGIN.matrix[3][1] = -18.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_05) {
  int result = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &RESULT);

  s21_create_matrix(1, 1, &ORIGIN);

  ORIGIN.matrix[0][0] = 4.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_number_06) {
  int result = 0;
  double number = 2.0;
  matrix_t A = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(0, 0, &A);

  result = s21_mult_number(&A, number, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_mult_matrix_01) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 90.0;
  ORIGIN.matrix[0][1] = 100.0;
  ORIGIN.matrix[0][2] = 110.0;
  ORIGIN.matrix[0][3] = 120.0;
  ORIGIN.matrix[1][0] = 202.0;
  ORIGIN.matrix[1][1] = 228.0;
  ORIGIN.matrix[1][2] = 254.0;
  ORIGIN.matrix[1][3] = 280.0;
  ORIGIN.matrix[2][0] = 314.0;
  ORIGIN.matrix[2][1] = 356.0;
  ORIGIN.matrix[2][2] = 398.0;
  ORIGIN.matrix[2][3] = 440.0;
  ORIGIN.matrix[3][0] = 426.0;
  ORIGIN.matrix[3][1] = 484.0;
  ORIGIN.matrix[3][2] = 542.0;
  ORIGIN.matrix[3][3] = 600.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_02) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-5.0, &B);

  s21_mult_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 30.0;
  ORIGIN.matrix[0][1] = 40.0;
  ORIGIN.matrix[0][2] = 50.0;
  ORIGIN.matrix[0][3] = 60.0;
  ORIGIN.matrix[1][0] = 46.0;
  ORIGIN.matrix[1][1] = 72.0;
  ORIGIN.matrix[1][2] = 98.0;
  ORIGIN.matrix[1][3] = 124.0;
  ORIGIN.matrix[2][0] = 62.0;
  ORIGIN.matrix[2][1] = 104.0;
  ORIGIN.matrix[2][2] = 146.0;
  ORIGIN.matrix[2][3] = 188.0;
  ORIGIN.matrix[3][0] = 78.0;
  ORIGIN.matrix[3][1] = 136.0;
  ORIGIN.matrix[3][2] = 194.0;
  ORIGIN.matrix[3][3] = 252.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_03) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = -78.0;
  ORIGIN.matrix[0][1] = -92.0;
  ORIGIN.matrix[0][2] = -106.0;
  ORIGIN.matrix[0][3] = -120.0;
  ORIGIN.matrix[1][0] = 34.0;
  ORIGIN.matrix[1][1] = 36.0;
  ORIGIN.matrix[1][2] = 38.0;
  ORIGIN.matrix[1][3] = 40.0;
  ORIGIN.matrix[2][0] = 146.0;
  ORIGIN.matrix[2][1] = 164.0;
  ORIGIN.matrix[2][2] = 182.0;
  ORIGIN.matrix[2][3] = 200.0;
  ORIGIN.matrix[3][0] = 258.0;
  ORIGIN.matrix[3][1] = 292.0;
  ORIGIN.matrix[3][2] = 326.0;
  ORIGIN.matrix[3][3] = 360.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_04) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = -25.0;
  ORIGIN.matrix[0][1] = -34.0;
  ORIGIN.matrix[0][2] = -43.0;
  ORIGIN.matrix[0][3] = -52.0;
  ORIGIN.matrix[1][0] = -13.0;
  ORIGIN.matrix[1][1] = -18.0;
  ORIGIN.matrix[1][2] = -23.0;
  ORIGIN.matrix[1][3] = -28.0;
  ORIGIN.matrix[2][0] = -1.0;
  ORIGIN.matrix[2][1] = -2.0;
  ORIGIN.matrix[2][2] = -3.0;
  ORIGIN.matrix[2][3] = -4.0;
  ORIGIN.matrix[3][0] = 11.0;
  ORIGIN.matrix[3][1] = 14.0;
  ORIGIN.matrix[3][2] = 17.0;
  ORIGIN.matrix[3][3] = 20.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_05) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(1, 1, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &RESULT);

  s21_create_matrix(1, 1, &ORIGIN);

  ORIGIN.matrix[0][0] = -5.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_06) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};

  result = s21_mult_matrix(&A, &B, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_mult_matrix_07) {
  int result = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 2, &B);
  s21_init_matrix(1.0, &B);

  result = s21_mult_matrix(&A, &B, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, ERROR_CALC);
}
END_TEST

START_TEST(s21_determinant_01) {
  int result = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};

  result = s21_determinant(&A, &determ);
  ck_assert_int_eq(result, ERROR_INIT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_02) {
  int result = 0;
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);

  result = s21_determinant(&A, &determ);
  ck_assert_int_eq(result, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_03) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_04) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 4000.87;
  A.matrix[0][1] = 454.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 1.897;
  A.matrix[1][2] = 3.0;
  A.matrix[2][0] = 0.000087;
  A.matrix[2][1] = 2.5668;
  A.matrix[2][2] = 1.0;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -24105.996724156);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_05) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -677700.0;
  A.matrix[0][1] = 654.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -0.00001;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -1301.223);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_06) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(8, 8, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_07) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(6, 6, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = -9;
  A.matrix[0][5] = 6;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 1;
  A.matrix[1][4] = 0;
  A.matrix[1][5] = -3;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 0;
  A.matrix[2][4] = 2;
  A.matrix[2][5] = 0;
  A.matrix[3][0] = 3;
  A.matrix[3][1] = 1;
  A.matrix[3][2] = 4;
  A.matrix[3][3] = 2;
  A.matrix[3][4] = 17;
  A.matrix[3][5] = 89;
  A.matrix[4][0] = -4;
  A.matrix[4][1] = 87;
  A.matrix[4][2] = 7;
  A.matrix[4][3] = 0;
  A.matrix[4][4] = -3;
  A.matrix[4][5] = 5;
  A.matrix[5][0] = 5;
  A.matrix[5][1] = 45;
  A.matrix[5][2] = 7;
  A.matrix[5][3] = 9;
  A.matrix[5][4] = 7;
  A.matrix[5][5] = 0;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -6926978);
  s21_remove_matrix(&A);
}
END_TEST
START_TEST(s21_calc_complements_01) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;

  s21_calc_complements(&A, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = -2879514.0;
  ORIGIN.matrix[0][1] = -1236631.0;
  ORIGIN.matrix[0][2] = -1685096.0;
  ORIGIN.matrix[0][3] = 880697.0;
  ORIGIN.matrix[1][0] = 1162090.0;
  ORIGIN.matrix[1][1] = -714015.0;
  ORIGIN.matrix[1][2] = 4046255.0;
  ORIGIN.matrix[1][3] = -3901600.0;
  ORIGIN.matrix[2][0] = 4362897.0;
  ORIGIN.matrix[2][1] = -2049432.0;
  ORIGIN.matrix[2][2] = -532912.0;
  ORIGIN.matrix[2][3] = -1370781.0;
  ORIGIN.matrix[3][0] = 3412773.0;
  ORIGIN.matrix[3][1] = -1569493.0;
  ORIGIN.matrix[3][2] = 3144517.0;
  ORIGIN.matrix[3][3] = 1284666.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_02) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_calc_complements(&A, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 0.0;
  ORIGIN.matrix[0][1] = -30.0;
  ORIGIN.matrix[0][2] = -108.0;
  ORIGIN.matrix[0][3] = 106.0;
  ORIGIN.matrix[1][0] = 138.0;
  ORIGIN.matrix[1][1] = -726.0;
  ORIGIN.matrix[1][2] = -1137.0;
  ORIGIN.matrix[1][3] = 1061.0;
  ORIGIN.matrix[2][0] = 0.0;
  ORIGIN.matrix[2][1] = 12.0;
  ORIGIN.matrix[2][2] = 57.0;
  ORIGIN.matrix[2][3] = -47.0;
  ORIGIN.matrix[3][0] = 0.0;
  ORIGIN.matrix[3][1] = 6.0;
  ORIGIN.matrix[3][2] = -75.0;
  ORIGIN.matrix[3][3] = 57.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_03) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(4, 3, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;

  result = s21_calc_complements(&A, &RESULT);

  s21_remove_matrix(&A);

  ck_assert_int_eq(result, ERROR_CALC);
}
END_TEST

START_TEST(s21_calc_complements_04) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);

  result = s21_calc_complements(&A, &RESULT);

  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_inverse_matrix_01) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_inverse_matrix(&A, &RESULT);

  s21_create_matrix(4, 4, &ORIGIN);

  ORIGIN.matrix[0][0] = 0.0;
  ORIGIN.matrix[0][1] = 1.0;
  ORIGIN.matrix[0][2] = 0.0;
  ORIGIN.matrix[0][3] = 0.0;
  ORIGIN.matrix[1][0] = -5.0 / 23.0;
  ORIGIN.matrix[1][1] = -121.0 / 23.0;
  ORIGIN.matrix[1][2] = 2.0 / 23.0;
  ORIGIN.matrix[1][3] = 1.0 / 23.0;
  ORIGIN.matrix[2][0] = -18.0 / 23.0;
  ORIGIN.matrix[2][1] = -379.0 / 46.0;
  ORIGIN.matrix[2][2] = 19.0 / 46.0;
  ORIGIN.matrix[2][3] = -25.0 / 46.0;
  ORIGIN.matrix[3][0] = 53.0 / 69.0;
  ORIGIN.matrix[3][1] = 1061.0 / 138.0;
  ORIGIN.matrix[3][2] = -47.0 / 138.0;
  ORIGIN.matrix[3][3] = 19.0 / 46.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

START_TEST(s21_inverse_matrix_02) {
  int result;
  matrix_t A = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  result = s21_inverse_matrix(&A, &RESULT);

  ck_assert_int_eq(RESULT.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);
  ck_assert_int_eq(result, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RESULT);
}
END_TEST

START_TEST(s21_inverse_matrix_03) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);

  result = s21_inverse_matrix(&A, &RESULT);
  ck_assert_int_eq(result, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_04) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  result = s21_inverse_matrix(&A, &RESULT);
  ck_assert_int_eq(result, ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_05) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};

  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_remove_matrix(&A);

  result = s21_inverse_matrix(&A, &RESULT);

  ck_assert_int_eq(result, ERROR_INIT);
}
END_TEST

START_TEST(s21_inverse_matrix_06) {
  int result = 0;
  matrix_t A = {0};
  matrix_t RESULT = {0};
  matrix_t ORIGIN = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;

  s21_inverse_matrix(&A, &RESULT);

  s21_create_matrix(3, 3, &ORIGIN);

  ORIGIN.matrix[0][0] = -3.0 / 5.0;
  ORIGIN.matrix[0][1] = 0.0;
  ORIGIN.matrix[0][2] = 1.0 / 5.0;
  ORIGIN.matrix[1][0] = -4.0 / 5.0;
  ORIGIN.matrix[1][1] = 1.0;
  ORIGIN.matrix[1][2] = -2.0 / 5.0;
  ORIGIN.matrix[2][0] = 16.0 / 15.0;
  ORIGIN.matrix[2][1] = -2.0 / 3.0;
  ORIGIN.matrix[2][2] = 1.0 / 5.0;

  result = s21_eq_matrix(&ORIGIN, &RESULT);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN);
  s21_remove_matrix(&RESULT);

  ck_assert_int_eq(result, SUCCESS);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc_core = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc_core);

  tcase_add_test(tc_core, s21_create_matrix_01);
  tcase_add_test(tc_core, s21_create_matrix_02);
  tcase_add_test(tc_core, s21_create_matrix_03);
  tcase_add_test(tc_core, s21_create_matrix_04);
  tcase_add_test(tc_core, s21_create_matrix_05);
  tcase_add_test(tc_core, s21_create_matrix_06);
  tcase_add_test(tc_core, s21_create_matrix_07);
  tcase_add_test(tc_core, s21_create_matrix_08);
  tcase_add_test(tc_core, s21_create_matrix_09);

  tcase_add_test(tc_core, s21_remove_matrix_01);
  tcase_add_test(tc_core, s21_remove_matrix_02);
  tcase_add_test(tc_core, s21_remove_matrix_03);
  tcase_add_test(tc_core, s21_remove_matrix_04);
  tcase_add_test(tc_core, s21_remove_matrix_05);

  tcase_add_test(tc_core, s21_eq_matrix_01);
  tcase_add_test(tc_core, s21_eq_matrix_02);
  tcase_add_test(tc_core, s21_eq_matrix_03);
  tcase_add_test(tc_core, s21_eq_matrix_04);
  tcase_add_test(tc_core, s21_eq_matrix_05);
  tcase_add_test(tc_core, s21_eq_matrix_06);

  tcase_add_test(tc_core, s21_sum_matrix_01);
  tcase_add_test(tc_core, s21_sum_matrix_02);
  tcase_add_test(tc_core, s21_sum_matrix_03);
  tcase_add_test(tc_core, s21_sum_matrix_04);
  tcase_add_test(tc_core, s21_sum_matrix_05);
  tcase_add_test(tc_core, s21_sum_matrix_06);
  tcase_add_test(tc_core, s21_sum_matrix_07);
  tcase_add_test(tc_core, s21_sum_matrix_08);

  tcase_add_test(tc_core, s21_sub_matrix_01);
  tcase_add_test(tc_core, s21_sub_matrix_02);
  tcase_add_test(tc_core, s21_sub_matrix_03);
  tcase_add_test(tc_core, s21_sub_matrix_04);
  tcase_add_test(tc_core, s21_sub_matrix_05);
  tcase_add_test(tc_core, s21_sub_matrix_06);
  tcase_add_test(tc_core, s21_sub_matrix_07);
  tcase_add_test(tc_core, s21_sub_matrix_08);

  tcase_add_test(tc_core, s21_mult_number_01);
  tcase_add_test(tc_core, s21_mult_number_02);
  tcase_add_test(tc_core, s21_mult_number_03);
  tcase_add_test(tc_core, s21_mult_number_04);
  tcase_add_test(tc_core, s21_mult_number_05);
  tcase_add_test(tc_core, s21_mult_number_06);

  tcase_add_test(tc_core, s21_mult_matrix_01);
  tcase_add_test(tc_core, s21_mult_matrix_02);
  tcase_add_test(tc_core, s21_mult_matrix_03);
  tcase_add_test(tc_core, s21_mult_matrix_04);
  tcase_add_test(tc_core, s21_mult_matrix_05);
  tcase_add_test(tc_core, s21_mult_matrix_06);
  tcase_add_test(tc_core, s21_mult_matrix_07);

  tcase_add_test(tc_core, s21_transpose_01);
  tcase_add_test(tc_core, s21_transpose_02);
  tcase_add_test(tc_core, s21_transpose_03);

  tcase_add_test(tc_core, s21_determinant_01);
  tcase_add_test(tc_core, s21_determinant_02);
  tcase_add_test(tc_core, s21_determinant_03);
  tcase_add_test(tc_core, s21_determinant_04);
  tcase_add_test(tc_core, s21_determinant_05);
  tcase_add_test(tc_core, s21_determinant_06);
  tcase_add_test(tc_core, s21_determinant_07);

  tcase_add_test(tc_core, s21_calc_complements_01);
  tcase_add_test(tc_core, s21_calc_complements_02);
  tcase_add_test(tc_core, s21_calc_complements_03);
  tcase_add_test(tc_core, s21_calc_complements_04);

  tcase_add_test(tc_core, s21_inverse_matrix_01);
  tcase_add_test(tc_core, s21_inverse_matrix_02);
  tcase_add_test(tc_core, s21_inverse_matrix_03);
  tcase_add_test(tc_core, s21_inverse_matrix_04);
  tcase_add_test(tc_core, s21_inverse_matrix_05);
  tcase_add_test(tc_core, s21_inverse_matrix_06);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf ? 1 : 0;
}