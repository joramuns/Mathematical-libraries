#include "check_matrix.h"



START_TEST(complements_1) {
    matrix_t A, B, R;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    A.matrix[0][0] = 5; A.matrix[0][1] = -1; A.matrix[0][2] = 1;
    A.matrix[1][0] = 2; A.matrix[1][1] = 3; A.matrix[1][2] = 4;
    A.matrix[2][0] = 1; A.matrix[2][1] = 0; A.matrix[2][2] = 3;

    s21_calc_complements(&A, &R);

    B.matrix[0][0] = 9;  B.matrix[0][1] = -2;  B.matrix[0][2] = -3;
    B.matrix[1][0] = 3;  B.matrix[1][1] = 14;  B.matrix[1][2] = -1;
    B.matrix[2][0] = -7; B.matrix[2][1] = -18; B.matrix[2][2] = 17;

    ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
} END_TEST

START_TEST(complements_2) {
    matrix_t A, B, R;
    s21_create_matrix(2, 2, &A);
    s21_create_matrix(2, 2, &B);

    A.matrix[0][0] = 5; A.matrix[0][1] = -1;
    A.matrix[1][0] = 2; A.matrix[1][1] = 3;

    s21_calc_complements(&A, &R);

    B.matrix[0][0] = 3;  B.matrix[0][1] = -2;
    B.matrix[1][0] = 1;  B.matrix[1][1] = 5;

    ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
} END_TEST

START_TEST(complements_3) {
    matrix_t A, B, R;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);

    A.matrix[0][0] = 5;
    s21_calc_complements(&A, &R);

    B.matrix[0][0] = 1;

    ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
} END_TEST

START_TEST(determinant_test_1) {
    matrix_t A;
    double B, R = 1.25;
    s21_create_matrix(1, 1, &A);

    A.matrix[0][0] = 1.25;
    s21_determinant(&A, &B);

    ck_assert_double_eq_tol(B, R, 1e-7);
    s21_remove_matrix(&A);
} END_TEST

START_TEST(determinant_test_2) {
    matrix_t A;
    double B, R = -69;
    s21_create_matrix(3, 3, &A);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 10;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    s21_determinant(&A, &B);
    ck_assert_double_eq_tol(B, R, 1e-7);
    s21_remove_matrix(&A);
} END_TEST


START_TEST(eq_test_1) {
    matrix_t A, B;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);

    A.matrix[0][0] = 1.25;
    B.matrix[0][0] = 2.25;

    ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
} END_TEST

START_TEST(eq_test_2) {
    matrix_t A, B;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    B.matrix[0][0] = 0.25;
    B.matrix[0][1] = 1.25;
    B.matrix[0][2] = 2.25;
    B.matrix[1][0] = 3.25;
    B.matrix[1][1] = 4.25;
    B.matrix[1][2] = 5.25;
    B.matrix[2][0] = 6.25;
    B.matrix[2][1] = 7.25;
    B.matrix[2][2] = 8.25;

    ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
} END_TEST


START_TEST(eq_test_3) {
    matrix_t A, B;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);

    A.matrix[0][0] = 1.25;
    B.matrix[0][0] = 2.25;

    ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
} END_TEST

START_TEST(inverse_test_1) {
    matrix_t A, B, R;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);

    A.matrix[0][0] = 1.25;
    B.matrix[0][0] = 0.8;

    s21_inverse_matrix(&A, &R);
    ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
} END_TEST

START_TEST(inverse_test_2) {
    matrix_t A, B, R;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    A.matrix[0][0] = -1;   A.matrix[0][1] = -10;  A.matrix[0][2] = 1;
    A.matrix[1][0] = 1;    A.matrix[1][1] = 10;   A.matrix[1][2] = 1;
    A.matrix[2][0] = 1;    A.matrix[2][1] = 1;    A.matrix[2][2] = 1;

    s21_inverse_matrix(&A, &R);

    B.matrix[0][0] = -0.5;  B.matrix[0][1] = -11.0/18.0;    B.matrix[0][2] = 10.0/9.0;
    B.matrix[1][0] = 0;     B.matrix[1][1] = 1.0/9.0;       B.matrix[1][2] = -1.0/9.0;
    B.matrix[2][0] = 0.5;   B.matrix[2][1] = 0.5;           B.matrix[2][2] = 0;

    ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
} END_TEST

START_TEST(mult_number_test_1) {
    matrix_t A, R, R2;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &R2);

    A.matrix[0][0] = 1.25;
    R2.matrix[0][0] = -5;

    s21_mult_number(&A, -4, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST

START_TEST(mult_number_test_2) {
    matrix_t A, R, R2;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &R2);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    R2.matrix[0][0] = 1;
    R2.matrix[0][1] = 5;
    R2.matrix[0][2] = 9;
    R2.matrix[1][0] = 13;
    R2.matrix[1][1] = 17;
    R2.matrix[1][2] = 21;
    R2.matrix[2][0] = 25;
    R2.matrix[2][1] = 29;
    R2.matrix[2][2] = 33;

    s21_mult_number(&A, 4, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][1], R2.matrix[0][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][2], R2.matrix[0][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][0], R2.matrix[1][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][1], R2.matrix[1][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][2], R2.matrix[1][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][0], R2.matrix[2][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][1], R2.matrix[2][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][2], R2.matrix[2][2], 1e-7);
    s21_remove_matrix(&A);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST


START_TEST(mult_matrix_test_1) {
    matrix_t A, B, R, R2;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);
    s21_create_matrix(1, 1, &R2);

    A.matrix[0][0] = -1;
    B.matrix[0][0] = 2;
    R2.matrix[0][0] = -2;

    s21_mult_matrix(&A, &B, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST

START_TEST(mult_matrix_test_2) {
    matrix_t A, B, R, R2;
    s21_create_matrix(3, 2, &A);
    s21_create_matrix(2, 3, &B);
    s21_create_matrix(3, 3, &R2);

    A.matrix[0][0] = 0;
    A.matrix[0][1] = 1;
    A.matrix[1][0] = 3;
    A.matrix[1][1] = 4;
    A.matrix[2][0] = 6;
    A.matrix[2][1] = 7;

    B.matrix[0][0] = 9;
    B.matrix[0][1] = 8;
    B.matrix[0][2] = 7;
    B.matrix[1][0] = 6;
    B.matrix[1][1] = 5;
    B.matrix[1][2] = 4;

    R2.matrix[0][0] = 6;
    R2.matrix[0][1] = 5;
    R2.matrix[0][2] = 4;
    R2.matrix[1][0] = 51;
    R2.matrix[1][1] = 44;
    R2.matrix[1][2] = 37;
    R2.matrix[2][0] = 96;
    R2.matrix[2][1] = 83;
    R2.matrix[2][2] = 70;

    s21_mult_matrix(&A, &B, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][1], R2.matrix[0][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][2], R2.matrix[0][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][0], R2.matrix[1][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][1], R2.matrix[1][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][2], R2.matrix[1][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][0], R2.matrix[2][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][1], R2.matrix[2][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][2], R2.matrix[2][2], 1e-7);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST

START_TEST(sub_test_1) {
    matrix_t A, B, R, R2;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);
    s21_create_matrix(1, 1, &R2);

    A.matrix[0][0] = 1.25;
    B.matrix[0][0] = 2.25;

    R2.matrix[0][0] = -1;
    s21_sub_matrix(&A, &B, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST

START_TEST(sub_test_2) {
    matrix_t A, B, R, R2;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);
    s21_create_matrix(3, 3, &R2);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    B.matrix[0][0] = 9.25;
    B.matrix[0][1] = 8.25;
    B.matrix[0][2] = 7.25;
    B.matrix[1][0] = 6.25;
    B.matrix[1][1] = 5.25;
    B.matrix[1][2] = 4.25;
    B.matrix[2][0] = 3.25;
    B.matrix[2][1] = 2.25;
    B.matrix[2][2] = 1.25;

    R2.matrix[0][0] = -9.0;
    R2.matrix[0][1] = -7.0;
    R2.matrix[0][2] = -5.0;
    R2.matrix[1][0] = -3.0;
    R2.matrix[1][1] = -1.0;
    R2.matrix[1][2] = 1.0;
    R2.matrix[2][0] = 3.0;
    R2.matrix[2][1] = 5.0;
    R2.matrix[2][2] = 7.0;

    s21_sub_matrix(&A, &B, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][1], R2.matrix[0][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][2], R2.matrix[0][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][0], R2.matrix[1][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][1], R2.matrix[1][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][2], R2.matrix[1][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][0], R2.matrix[2][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][1], R2.matrix[2][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][2], R2.matrix[2][2], 1e-7);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST

START_TEST(sum_test_1) {
    matrix_t A, B, R, R2;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);
    s21_create_matrix(1, 1, &R2);

    A.matrix[0][0] = 1.25;
    B.matrix[0][0] = 2.25;
    R2.matrix[0][0] = 3.5;

    s21_sum_matrix(&A, &B, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST

START_TEST(sum_test_2) {
    matrix_t A, B, R, R2;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);
    s21_create_matrix(3, 3, &R2);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    B.matrix[0][0] = 9.65;
    B.matrix[0][1] = 8.65;
    B.matrix[0][2] = 7.65;
    B.matrix[1][0] = 6.65;
    B.matrix[1][1] = 5.65;
    B.matrix[1][2] = 4.65;
    B.matrix[2][0] = 3.65;
    B.matrix[2][1] = 2.65;
    B.matrix[2][2] = 1.65;

    R2.matrix[0][0] = 9.9;
    R2.matrix[0][1] = 9.9;
    R2.matrix[0][2] = 9.9;
    R2.matrix[1][0] = 9.9;
    R2.matrix[1][1] = 9.9;
    R2.matrix[1][2] = 9.9;
    R2.matrix[2][0] = 9.9;
    R2.matrix[2][1] = 9.9;
    R2.matrix[2][2] = 9.9;

    s21_sum_matrix(&A, &B, &R);

    ck_assert_double_eq_tol(R.matrix[0][0], R2.matrix[0][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][1], R2.matrix[0][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[0][2], R2.matrix[0][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][0], R2.matrix[1][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][1], R2.matrix[1][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[1][2], R2.matrix[1][2], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][0], R2.matrix[2][0], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][1], R2.matrix[2][1], 1e-7);
    ck_assert_double_eq_tol(R.matrix[2][2], R2.matrix[2][2], 1e-7);

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
    s21_remove_matrix(&R2);
} END_TEST


START_TEST(transpose_test_11) {
    matrix_t A, B, R;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &B);

    A.matrix[0][0] = 1.25;
    B.matrix[0][0] = 1.25;

    s21_transpose(&A, &R);
    ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
} END_TEST


START_TEST(transpose_test_22) {
    matrix_t A, B, R;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    s21_transpose(&A, &R);

    B.matrix[0][0] = 0.25;
    B.matrix[1][0] = 1.25;
    B.matrix[2][0] = 2.25;
    B.matrix[0][1] = 3.25;
    B.matrix[1][1] = 4.25;
    B.matrix[2][1] = 5.25;
    B.matrix[0][2] = 6.25;
    B.matrix[1][2] = 7.25;
    B.matrix[2][2] = 8.25;

    ck_assert_int_eq(s21_eq_matrix(&R, &B), 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&R);
} END_TEST



START_TEST(transpose_test_23) {
    matrix_t A, R;
    s21_create_matrix(3, 3, &A);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    A.rows = 0;

    int res = s21_transpose(&A, &R);
    ck_assert_int_eq(res, 1);

    A.rows = 3;
    s21_remove_matrix(&A);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST

START_TEST(sum_test_23) {
    matrix_t A, B, R;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    A.rows = 0;

    B.matrix[0][0] = 0.25;
    B.matrix[0][1] = 1.25;
    B.matrix[0][2] = 2.25;
    B.matrix[1][0] = 3.25;
    B.matrix[1][1] = 4.25;
    B.matrix[1][2] = 5.25;
    B.matrix[2][0] = 6.25;
    B.matrix[2][1] = 7.25;
    B.matrix[2][2] = 8.25;

    int res = s21_sum_matrix(&A, &B, &R);
    ck_assert_int_eq(res, 1);

    A.rows = 3;
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST

START_TEST(sub_test_23) {
    matrix_t A, B, R;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    A.rows = 0;

    B.matrix[0][0] = 0.25;
    B.matrix[0][1] = 1.25;
    B.matrix[0][2] = 2.25;
    B.matrix[1][0] = 3.25;
    B.matrix[1][1] = 4.25;
    B.matrix[1][2] = 5.25;
    B.matrix[2][0] = 6.25;
    B.matrix[2][1] = 7.25;
    B.matrix[2][2] = 8.25;

    int res = s21_sub_matrix(&A, &B, &R);
    ck_assert_int_eq(res, 1);

    A.rows = 3;
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST



START_TEST(complement_test_23) {
    matrix_t A, R;
    s21_create_matrix(3, 3, &A);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    A.rows = 0;

    int res = s21_calc_complements(&A, &R);
    ck_assert_int_eq(res, 1);

    A.rows = 3;
    s21_remove_matrix(&A);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST
START_TEST(determinant_test_23) {
    matrix_t A;
    s21_create_matrix(3, 3, &A);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    A.rows = 0;
    double number = 10;

    int res = s21_determinant(&A, &number);
    ck_assert_int_eq(res, 1);

    A.rows = 3;
    s21_remove_matrix(&A);
} END_TEST
START_TEST(inverse_test_23) {
    matrix_t A, R;
    s21_create_matrix(3, 3, &A);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    A.rows = 0;

    int res = s21_inverse_matrix(&A, &R);
    ck_assert_int_eq(res, 1);

    A.rows = 3;
    s21_remove_matrix(&A);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST


START_TEST(mult_matrix_test_23) {
    matrix_t A, B, R;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &B);

    A.matrix[0][0] = 0.25;
    A.matrix[0][1] = 1.25;
    A.matrix[0][2] = 2.25;
    A.matrix[1][0] = 3.25;
    A.matrix[1][1] = 4.25;
    A.matrix[1][2] = 5.25;
    A.matrix[2][0] = 6.25;
    A.matrix[2][1] = 7.25;
    A.matrix[2][2] = 8.25;

    A.rows = 0;

    B.matrix[0][0] = 0.25;
    B.matrix[0][1] = 1.25;
    B.matrix[0][2] = 2.25;
    B.matrix[1][0] = 3.25;
    B.matrix[1][1] = 4.25;
    B.matrix[1][2] = 5.25;
    B.matrix[2][0] = 6.25;
    B.matrix[2][1] = 7.25;
    B.matrix[2][2] = 8.25;

    int res = s21_mult_matrix(&A, &B, &R);
    ck_assert_int_eq(res, 1);

    A.rows = 3;

    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST

START_TEST(create_22) {
    matrix_t A;
    int res = s21_create_matrix(0, 0, &A);
    ck_assert_int_eq(res, 1);
} END_TEST

START_TEST(mult_number_test_22) {
    matrix_t A, R, R2;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &R2);

    A.matrix[0][0] = 1.25;
    R2.matrix[0][0] = -5;

    int res = s21_mult_number(&A, NAN, &R);

    ck_assert_int_eq(res, 2);

    s21_remove_matrix(&A);
    s21_remove_matrix(&R2);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST

START_TEST(mult_number_test_222) {
    matrix_t A, R, R2;
    s21_create_matrix(1, 1, &A);
    s21_create_matrix(1, 1, &R2);

    A.matrix[0][0] = 1.25;
    A.rows = 0;
    R2.matrix[0][0] = -5;

    int res = s21_mult_number(&A, -4, &R);

    ck_assert_int_eq(res, 1);

    A.rows = 1;
    s21_remove_matrix(&A);
    s21_remove_matrix(&R2);
    if (!res) {
        s21_remove_matrix(&R);
    }
} END_TEST


Suite *extrapack_suite(void) {
    Suite *s1 = suite_create("Ch");
    TCase *tc1_1 = tcase_create("Core");

    tcase_add_test(tc1_1, complements_1);
    tcase_add_test(tc1_1, complements_2);
    tcase_add_test(tc1_1, complements_3);
    tcase_add_test(tc1_1, determinant_test_1);
    tcase_add_test(tc1_1, determinant_test_2);
    tcase_add_test(tc1_1, eq_test_1);
    tcase_add_test(tc1_1, eq_test_2);
    tcase_add_test(tc1_1, eq_test_3);

    tcase_add_test(tc1_1, inverse_test_1);
    tcase_add_test(tc1_1, inverse_test_2);
    tcase_add_test(tc1_1, mult_number_test_1);
    tcase_add_test(tc1_1, mult_number_test_2);

    tcase_add_test(tc1_1, mult_matrix_test_1);
    tcase_add_test(tc1_1, mult_matrix_test_2);
    tcase_add_test(tc1_1, sub_test_1);
    tcase_add_test(tc1_1, sub_test_2);
    tcase_add_test(tc1_1, sum_test_1);
    tcase_add_test(tc1_1, sum_test_2);
    tcase_add_test(tc1_1, transpose_test_11);

    tcase_add_test(tc1_1, mult_number_test_222);
    tcase_add_test(tc1_1, create_22);
    tcase_add_test(tc1_1, mult_number_test_22);
    tcase_add_test(tc1_1, transpose_test_22);
    tcase_add_test(tc1_1, transpose_test_23);
    tcase_add_test(tc1_1, sum_test_23);
    tcase_add_test(tc1_1, sub_test_23);

    tcase_add_test(tc1_1, inverse_test_23);
    tcase_add_test(tc1_1, determinant_test_23);
    tcase_add_test(tc1_1, complement_test_23);
    tcase_add_test(tc1_1, mult_matrix_test_23);

    suite_add_tcase(s1, tc1_1);
    return s1;
}
