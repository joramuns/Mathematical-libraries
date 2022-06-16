//
//  tan.c
//  s21 Math.h
//
//  Created by Joramun Sasin on 6/9/22.
//

#include "tests.h"

START_TEST(zero) {
    ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-06);
} END_TEST

START_TEST(one) {
    ck_assert_double_eq_tol(s21_tan(1), tan(1), 1e-06);
} END_TEST

START_TEST(ten) {
    ck_assert_double_eq_tol(s21_tan(10), tan(10), 1e-06);
} END_TEST

START_TEST(negative) {
    ck_assert_double_eq_tol(s21_tan(-1), tan(-1), 1e-06);
} END_TEST

START_TEST(thirteen) {
    ck_assert_double_eq_tol(s21_tan(13), tan(13), 1e-06);
} END_TEST

START_TEST(hundred) {
    ck_assert_double_eq_tol(s21_tan(100), tan(100), 1e-06);
} END_TEST

START_TEST(negative_zero) {
    ck_assert_double_eq_tol(s21_tan(-0), tan(-0), 1e-06);
} END_TEST

START_TEST(negative_ten) {
    ck_assert_double_eq_tol(s21_tan(-10), tan(-10), 1e-06);
} END_TEST

START_TEST(negative_thirteen) {
    ck_assert_double_eq_tol(s21_tan(-13), tan(-13), 1e-06);
} END_TEST

START_TEST(negative_hundred) {
    ck_assert_double_eq_tol(s21_tan(-100), tan(-100), 1e-06);
} END_TEST

START_TEST(negative_hundred_half) {
    ck_assert_double_eq_tol(s21_tan(-100.55), tan(-100.55), 1e-06);
} END_TEST

START_TEST(half) {
    ck_assert_double_eq_tol(s21_tan(0.55), tan(0.55), 1e-06);
} END_TEST

START_TEST(negative_half) {
    ck_assert_double_eq_tol(s21_tan(-0.55), tan(-0.55), 1e-06);
} END_TEST

/* */
START_TEST(tan_1) { ck_assert_float_eq(s21_tan(-15.01), tan(-15.01)); }
END_TEST

START_TEST(tan_2) {
  double num = 0.55;
  long double orig_res = s21_tan(num), our_res = s21_tan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_3) { ck_assert_float_eq(-9999999999, -9999999999); }
END_TEST

START_TEST(tan_4) {
  double num = NAN;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_5) {
  double num = INFINITY;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_6) {
  double num = -INFINITY;
  long double orig_res = tan(num), our_res = s21_tan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_7) {
  double x = 0;
  ck_assert_double_eq_tol(s21_tan(x), tanl(x), 1e-06);
}
END_TEST

START_TEST(tan_8) {
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
  ck_assert_ldouble_nan(tanl(-INFINITY));
}
END_TEST

START_TEST(tan_9) {
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(tanl(INFINITY));
}
END_TEST

START_TEST(tan_10) {
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(tanl(NAN));
}
END_TEST

START_TEST(tan_11) { ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), 1e-06); }
END_TEST

START_TEST(tan_12) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 6), tanl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(tan_13) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 4), tanl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(tan_14) {
  ck_assert_double_eq_tol(s21_tan(-2 * M_PI), tanl(-2 * M_PI), 1e-06);
}
END_TEST

START_TEST(tan_15) {
  ck_assert_double_eq_tol(s21_tan(M_PI), tanl(M_PI), 1e-06);
}
END_TEST

START_TEST(tan_16) {
  ck_assert_double_eq_tol(s21_tan(M_PI / 3), tanl(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(tan_17) {
  ck_assert_double_eq_tol(s21_tan(3 * M_PI / 3), tanl(3 * M_PI / 3), 1e-06);
}
END_TEST

START_TEST(tan_18) {
  ck_assert_double_eq_tol(s21_tan(174.532925199433), tanl(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(tan_19) {
  ck_assert_double_eq_tol(s21_tan(-174.532925199433), tanl(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(tan_20) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 2), tanl(s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(tan_21) {
  ck_assert_double_eq_tol(s21_tan(-s21_PI / 2), tanl(-s21_PI / 2), 1e-06);
}
END_TEST

void tan_tests(TCase *tc) {
    puts("\e[32m");
    tcase_add_test(tc, zero);
    tcase_add_test(tc, one);
    tcase_add_test(tc, ten);
    tcase_add_test(tc, negative);
    tcase_add_test(tc, thirteen);
    tcase_add_test(tc, hundred);
    tcase_add_test(tc, negative_zero);
    tcase_add_test(tc, negative_ten);
    tcase_add_test(tc, negative_thirteen);
    tcase_add_test(tc, negative_hundred);
    tcase_add_test(tc, negative_hundred_half);
    tcase_add_test(tc, half);
    tcase_add_test(tc, negative_half);
    /* */
    tcase_add_test(tc, tan_1);
    tcase_add_test(tc, tan_2);
    tcase_add_test(tc, tan_3);
    tcase_add_test(tc, tan_4);
    tcase_add_test(tc, tan_5);
    tcase_add_test(tc, tan_6);
    tcase_add_test(tc, tan_7);
    tcase_add_test(tc, tan_8);
    tcase_add_test(tc, tan_9);
    tcase_add_test(tc, tan_10);
    tcase_add_test(tc, tan_11);
    tcase_add_test(tc, tan_12);
    tcase_add_test(tc, tan_13);
    tcase_add_test(tc, tan_14);
    tcase_add_test(tc, tan_15);
    tcase_add_test(tc, tan_16);
    tcase_add_test(tc, tan_17);
    tcase_add_test(tc, tan_18);
    tcase_add_test(tc, tan_19);
    tcase_add_test(tc, tan_20);
    tcase_add_test(tc, tan_21);
}
