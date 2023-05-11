//
//  exp.c
//  S21 Math.h
//
//  Created by Joramun Sasin on 6/8/22.
//

#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq(s21_exp(0), exp(0));
} END_TEST

START_TEST(one) {
    ck_assert_double_eq_tol(s21_exp(1), exp(1), 1e-06);
} END_TEST

START_TEST(zero_fifty) {
    ck_assert_ldouble_eq_tol(s21_exp(0.05), exp(0.05), 1e-06);
} END_TEST

START_TEST(negative) {
    ck_assert_double_eq_tol(s21_exp(-1), exp(-1), 1e-06);
} END_TEST

START_TEST(thirteen) {
    ck_assert_double_eq_tol(s21_exp(13), exp(13), 1e-06);
} END_TEST


START_TEST(exp_2) {
  double x = 2;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_3) {
  double x = 3;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_4) {
  double x = 1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_5) {
  double x = -1.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_6) {
  double x = 0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_7) {
  double x = -0.5;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_8) {
  double x = 715;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_9) {
  double x = -715;
  ck_assert_double_eq_tol(s21_exp(x), exp(x), 1e-06);
}
END_TEST

START_TEST(exp_10) {
  double x = -0;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_11) {
  double x = 'A';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_12) {
  double x = -'N';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_13) {
  double x = -'V';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_14) {
  double x = +'B';
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_15) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_16) {
  double x = 0 / 1;
  ck_assert_int_eq(s21_exp(x), exp(x));
}
END_TEST

START_TEST(exp_17) { ck_assert_float_eq(s21_exp(2), exp(2)); }
END_TEST

START_TEST(exp_18) { ck_assert_float_eq(s21_exp(-750), exp(-750)); }
END_TEST

START_TEST(exp_19) { ck_assert_float_eq(s21_exp(-2), exp(-2)); }
END_TEST

START_TEST(exp_20) {
    ck_assert_double_nan(exp(NAN));
    ck_assert_double_nan(s21_exp(NAN));
}
END_TEST

START_TEST(exp_21) {
  double num = INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_22) {
  double num = -INFINITY;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(exp_23) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_24) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), expl(-INFINITY), 1e-06);
}
END_TEST

START_TEST(exp_25) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(expl(INFINITY));
}
END_TEST

START_TEST(exp_26) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(expl(NAN));
}
END_TEST

START_TEST(exp_27) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_28) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_29) {
  double x = -100;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_30) {
  double x = -1000000;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_31) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_32) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), expl(x), 1e-06);
}
END_TEST

START_TEST(exp_33) {
  double num = 1000000;
  long double orig_res = exp(num), our_res = s21_exp(num);
  int suc = 0;
  if (isinf(orig_res) && isinf(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

void exp_tests(TCase *tc) {
    tcase_add_test(tc, zero);
    tcase_add_test(tc, one);
    tcase_add_test(tc, zero_fifty);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, thirteen);
    /* */
    tcase_add_test(tc, exp_2);
    tcase_add_test(tc, exp_3);
    tcase_add_test(tc, exp_4);
    tcase_add_test(tc, exp_5);
    tcase_add_test(tc, exp_6);
    tcase_add_test(tc, exp_7);
    tcase_add_test(tc, exp_8);
    tcase_add_test(tc, exp_9);
    tcase_add_test(tc, exp_10);
    tcase_add_test(tc, exp_11);
    tcase_add_test(tc, exp_12);
    tcase_add_test(tc, exp_13);
    tcase_add_test(tc, exp_14);
    tcase_add_test(tc, exp_15);
    tcase_add_test(tc, exp_16);
    tcase_add_test(tc, exp_17);
    tcase_add_test(tc, exp_18);
    tcase_add_test(tc, exp_19);
    tcase_add_test(tc, exp_20);
    tcase_add_test(tc, exp_21);
    tcase_add_test(tc, exp_22);
    tcase_add_test(tc, exp_23);
    tcase_add_test(tc, exp_24);
    tcase_add_test(tc, exp_25);
    tcase_add_test(tc, exp_26);
    tcase_add_test(tc, exp_27);
    tcase_add_test(tc, exp_28);
    tcase_add_test(tc, exp_29);
    tcase_add_test(tc, exp_30);
    tcase_add_test(tc, exp_31);
    tcase_add_test(tc, exp_32);
    tcase_add_test(tc, exp_33);
}
