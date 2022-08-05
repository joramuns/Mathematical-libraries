#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"
#define BIT_SIZE 4294967295

START_TEST(s21_add_int_1) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 100;
    int tmp2 = 99999;
    int res_s21 = 0;
    int res = 100099;
    s21_decimal res1;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_add(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_int_2) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -100;
    int tmp2 = -99999;
    int res_s21 = 0;
    int res = -100099;
    s21_decimal res1;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_add(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_int_3) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 2147483647;
    int tmp2 = -2147483647;
    int res_s21 = 0;
    int res = 0;
    s21_decimal res1;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_add(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_int_4) {
    s21_decimal dec1;
    s21_decimal dec2;
    dec1.bits[3] = 0x300000;
    dec1.bits[2] = 0;
    dec1.bits[1] = 0xF;
    dec1.bits[0] = 0x67E4FEEF;
    dec2.bits[3] = 0x300000;
    dec2.bits[2] = 0;
    dec2.bits[1] = 0xFF;
    dec2.bits[0] = 0x67E4FFFF;
    s21_decimal res;
    res.bits[3] = 0x300000;
    res.bits[2] = 0;
    res.bits[1] = 0x10E;
    res.bits[0] = 0xCFC9FEEE;
    s21_decimal res1;
    s21_add(dec1, dec2, &res1);
    ck_assert_int_eq(res.bits[3], res1.bits[3]);
    ck_assert_int_eq(res.bits[2], res1.bits[2]);
    ck_assert_int_eq(res.bits[1], res1.bits[1]);
    ck_assert_int_eq(res.bits[0], res1.bits[0]);
}
END_TEST

START_TEST(s21_add_int_5) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -2147483647;
    int tmp2 = 2147483647;
    int res_s21 = 0;
    int res = 0;
    s21_decimal res1;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_add(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_add_inf) {
    s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}};
    s21_decimal dec2 = {{1, 0, 0, 0}};
    s21_decimal res1;
    int ret_s21 = s21_add(dec1, dec2, &res1);
    ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(s21_add_neg_inf) {
    s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, pow(2, 31)}};
    s21_decimal dec2 = {{1, 0, 0, pow(2, 31)}};
    s21_decimal res1;
    int ret_s21 = s21_add(dec1, dec2, &res1);
    ck_assert_int_eq(2, ret_s21);
}
END_TEST

START_TEST(s21_add_float_1) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // 1.01
    s21_set_scale(&dec1, 2);
    s21_decimal dec2 = {{1021, 0, 0, 0}};  // 10.21
    s21_set_scale(&dec2, 2);
    s21_decimal res1;
    s21_add(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, 11.22);
}
END_TEST

START_TEST(s21_add_float_2) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // -1.01
    s21_set_scale(&dec1, 2);
    s21_set_bit(&dec1 , 127);

    s21_decimal dec2 = {{1021, 0, 0, 0}};  // -10.21
    s21_set_scale(&dec2, 2);
    s21_set_bit(&dec2, 127);
    s21_decimal res1;
    s21_add(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, -11.22);
}
END_TEST

START_TEST(s21_add_float_3) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // -1.01
    s21_set_scale(&dec1, 2);
    s21_set_bit(&dec1 , 127);

    s21_decimal dec2 = {{1021, 0, 0, 0}};  // 10.21
    s21_set_scale(&dec2, 2);

    s21_decimal res1;
    s21_add(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, 9.2);
}
END_TEST

START_TEST(s21_add_float_4) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // 1.01
    s21_set_scale(&dec1, 2);

    s21_decimal dec2 = {{1021, 0, 0, 0}};  // -10.21
    s21_set_scale(&dec2, 2);
    s21_set_bit(&dec2, 127);

    s21_decimal res1;
    s21_add(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, -9.2);
}
END_TEST

START_TEST(s21_sub_int_1) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 100;
    int tmp2 = 99999;
    int res_s21 = 0;
    int res = -99899;
    s21_decimal res1;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_sub(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_2) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -100;
    int tmp2 = -99999;
    int res_s21 = 0;
    int res = 99899;
    s21_decimal res1;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_sub(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_3) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -2147483647;
    int tmp2 = -2147483647;
    int res_s21 = 0;
    int res = 0;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_sub(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_4) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -214748347;
    int tmp2 = 217483647;
    int res_s21 = 0;
    int res = -214748347 - 217483647;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_sub(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_5) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 214748347;
    int tmp2 = -217483647;
    int res_s21 = 0;
    int res =  214748347 - -217483647;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_sub(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_inf) {
    s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}};
    s21_decimal dec2 = {{1, 0, 0, pow(2, 31)}};
    s21_decimal res1;
    int ret_s21 = s21_sub(dec1, dec2, &res1);
    ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(s21_sub_neg_inf) {
    s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, pow(2, 31)}};
    s21_decimal dec2 = {{1, 0, 0, 0}};
    s21_decimal res1;
    int ret_s21 = s21_sub(dec1, dec2, &res1);
    ck_assert_int_eq(2, ret_s21);
}
END_TEST

START_TEST(s21_sub_float_1) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // 1.01
    s21_set_scale(&dec1, 2);
    s21_decimal dec2 = {{1021, 0, 0, 0}};  // 10.21
    s21_set_scale(&dec2, 2);
    s21_decimal res1;
    s21_sub(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, -9.2);
}
END_TEST

START_TEST(s21_sub_float_2) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // -1.01
    s21_set_scale(&dec1, 2);
    s21_set_bit(&dec1 , 127);
    s21_decimal dec2 = {{1021, 0, 0, 0}};  // 10.21
    s21_set_scale(&dec2, 2);
    s21_decimal res1;
    s21_sub(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, -11.22);
}
END_TEST

START_TEST(s21_sub_float_3) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // 1.01
    s21_set_scale(&dec1, 2);
    s21_decimal dec2 = {{1021, 0, 0, 0}};  // -10.21
    s21_set_bit(&dec2, 127);
    s21_set_scale(&dec2, 2);
    s21_decimal res1;
    s21_sub(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, 11.22);
}
END_TEST

START_TEST(s21_sub_float_4) {
    s21_decimal dec1 = {{101, 0, 0, 0}};  // -1.01
    s21_set_scale(&dec1, 2);
    s21_set_bit(&dec1 , 127);
    s21_decimal dec2 = {{1021, 0, 0, 0}};  // -10.21
    s21_set_scale(&dec2, 2);
    s21_set_bit(&dec2, 127);
    s21_decimal res1;
    s21_sub(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, 9.2);
}
END_TEST

START_TEST(s21_mul_1) {
    s21_decimal dec1 = {{ 4, 0, 0, 0}};
    s21_decimal dec2 = {{10, 0, 0, 0}};

    s21_decimal d22;
    s21_mul(dec1, dec2, &d22);

    int qqqq = 0;
    s21_from_decimal_to_int(d22, &qqqq);
    ck_assert_int_eq(qqqq, 40);
}
END_TEST

START_TEST(s21_mul_2) {
    s21_decimal dec1 = {{100, 0, 0, 0}};  // 100
    s21_decimal dec2 = {{999999, 0, 0, 0}};  // 9999.99
    s21_set_scale(&dec2, 2);
    s21_decimal res1;
    s21_mul(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, 999999);
}
END_TEST

START_TEST(s21_mul_3) {
    s21_decimal dec1 = {{100, 0, 0, 0}};  // -100
    s21_set_bit(&dec1, 127);
    s21_decimal dec2 = {{999999, 0, 0, 0}};  // 9999.99
    s21_set_scale(&dec2, 2);
    s21_decimal res1;
    s21_mul(dec1, dec2, &res1);

    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq(g, -999999);
}
END_TEST

START_TEST(s21_mul_4) {
    s21_decimal dec1 = {{1002, 0, 0, 0}};  // -100.2
    s21_set_scale(&dec1, 1);
    s21_set_bit(&dec1, 127);

    s21_decimal dec2 = {{999999, 0, 0, 0}};  // -9999.99
    s21_set_scale(&dec2, 2);
    s21_set_bit(&dec2, 127);

    s21_decimal res1;
    s21_mul(dec1, dec2, &res1);
    float g;
    s21_from_decimal_to_float(res1, &g);
    ck_assert_float_eq_tol(g, 1001998.998, 1e-06);
}
END_TEST

START_TEST(s21_mul_5) {
    s21_decimal dec1 = {{0, 0, 0, 0}};  // -0.0
    s21_set_scale(&dec1, 1);
    s21_set_bit(&dec1, 127);

    s21_decimal dec2 = {{999999, 0, 0, 0}};  // -9999.99
    s21_set_scale(&dec2, 2);
    s21_set_bit(&dec2, 127);

    s21_decimal res1;
    s21_mul(dec1, dec2, &res1);
    int g;
    s21_from_decimal_to_int(res1, &g);
    float r = (float)g * pow(10, -s21_get_scale(res1));
    ck_assert_float_eq(r, 0.0);
}
END_TEST

START_TEST(s21_mul_too_big) {
    s21_decimal dec1 = {{BIT_SIZE - 1, BIT_SIZE - 1, BIT_SIZE - 1, 0}};
    s21_decimal dec2 = {{2, 0, 0, 0}};

    s21_decimal res;
    int ret = s21_mul(dec1, dec2, &res);

    ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_mul_rounding) {
    s21_decimal dec1 = {{123456789, 0, 0, 0}};
    s21_set_scale(&dec1, 10);
    s21_decimal dec2 = {{123456789, 0, 0, 0}};
    s21_set_scale(&dec2, 10);

    s21_decimal res;
    s21_mul(dec1, dec2, &res);
    float g;
    s21_from_decimal_to_float(res, &g);
    ck_assert_float_eq_tol(g, 0.00015241578512359410524368286132812, 1e-06);
}
END_TEST

START_TEST(s21_mul_too_big_neg) {
    s21_decimal dec1 = {{BIT_SIZE - 1, BIT_SIZE - 1, BIT_SIZE - 1, 0}};
    s21_set_bit(&dec1, 127);
    s21_decimal dec2 = {{2, 0, 0, 0}};

    s21_decimal res;
    int ret = s21_mul(dec1, dec2, &res);

    ck_assert_int_eq(ret, 2);
}
END_TEST

START_TEST(s21_div_1) {
    s21_decimal dec1 = {{100, 0, 0, 0}};
    s21_decimal dec2 = {{99999, 0, 0, 0}};

    float res_s21 = 0;
    float res = 100.0 / 99999.0;

    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_2) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 100;
    float tmp2 = 999.99;
    float res_s21 = 0.0;
    float res = 0.100001;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_float_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_3) {
    s21_decimal dec1 = {{1000, 0, 0, 0}};  // 100.0
    s21_set_scale(&dec1, 1);
    s21_decimal dec2 = {{5, 0, 0, 0}};  // 0.5
    s21_set_scale(&dec2, 1);

    float res_s21 = 0.0;
    float res = 200;

    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq(res_s21, res);
}
END_TEST

START_TEST(s21_div_4) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -100;
    int tmp2 = -99999;
    float res_s21 = 0;
    float res = 0.00100001;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_5) {
    s21_decimal dec1 = {{1005, 0, 0, 0}};  // -100.5
    s21_set_scale(&dec1, 1);
    s21_set_bit(&dec1, 127);
    s21_decimal dec2 = {{999995, 0, 0, 0}};  // -99999.5
    s21_set_scale(&dec2, 1);
    s21_set_bit(&dec2, 127);

    float res_s21 = 0;
    float res = 0.001005005;

    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_6) {
    s21_decimal dec1 = {{10.0e3, 0, 0, 0}};
    s21_decimal dec2 = {{2.00e2, 0, 0, 0}};

    int res_s21 = 0;
    int res = 50;

    s21_decimal res1;
    s21_div(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_div_null) {
    s21_decimal dec1 = {{1110, 0, 0, 0}};
    s21_decimal dec2 = {{0, 0, 0, 0}};

    s21_decimal res1;
    int res = s21_div(dec1, dec2, &res1);
    ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(s21_mod_1) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 99;
    int tmp2 = 2;
    int res_s21 = 0;
    int res = tmp1 % tmp2;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_mod(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_2) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 100;
    int tmp2 = 2;
    int res_s21 = 0;
    float res = tmp1 % tmp2;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_mod(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_3) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -100;
    int tmp2 = 2;
    float res_s21 = 0;
    float res = tmp1 % tmp2;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_mod(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_4) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = -99;
    int tmp2 = -2;
    int res_s21 = 0;
    int res = tmp1 % tmp2;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_mod(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_4_1) {
    s21_decimal dec1;
    s21_decimal dec2;
    int tmp1 = 99;
    int tmp2 = -2;
    int res_s21 = 0;
    float res = tmp1 % tmp2;
    s21_from_int_to_decimal(tmp1, &dec1);
    s21_from_int_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_mod(dec1, dec2, &res1);
    s21_from_decimal_to_int(res1, &res_s21);
    ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_mod_5) {
    s21_decimal dec1;
    s21_decimal dec2;
    float tmp1 = 1.2;
    float tmp2 = 0.2;
    float res_s21 = 0.0;
    float res = fmod(tmp1, tmp2);
    s21_from_float_to_decimal(tmp1, &dec1);
    s21_from_float_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_mod(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_mod_6) {
    s21_decimal dec1;
    s21_decimal dec2;
    float tmp1 = 1.2;
    float tmp2 = 0.25;
    float res_s21 = 0.0;
    float res = fmod(tmp1, tmp2);
    s21_from_float_to_decimal(tmp1, &dec1);
    s21_from_float_to_decimal(tmp2, &dec2);
    s21_decimal res1;
    s21_mod(dec1, dec2, &res1);
    s21_from_decimal_to_float(res1, &res_s21);
    ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(s21_mod_div_null) {
    s21_decimal dec1;
    s21_decimal dec2 = {{0, 0, 0, 0}};
    float tmp1 = 1.2;
    float tmp2 = 0.0;
    s21_from_float_to_decimal(tmp1, &dec1);
    s21_from_float_to_decimal(tmp2, &dec2);
    s21_decimal res_d;
    int res = s21_mod(dec1, dec2, &res_d);

    ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(s21_less) {
    s21_decimal dec5 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec6 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_less(dec5, dec6), 0);
    ck_assert_int_eq(s21_is_less(dec6, dec5), 1);

    s21_decimal dec7 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec8 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_less(dec7, dec8), 1);
    ck_assert_int_eq(s21_is_less(dec8, dec7), 0);

    s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec2 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_less(dec1, dec2), 0);
    ck_assert_int_eq(s21_is_less(dec2, dec1), 1);

    s21_decimal dec3 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec4 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_less(dec3, dec4), 1);
    ck_assert_int_eq(s21_is_less(dec4, dec3), 0);

    s21_decimal dec9 = {{12345, 0, 0, 0}};
    s21_decimal dec10 = {{12345, 0, 0, 0}};
    ck_assert_int_eq(s21_is_less(dec9, dec10), 0);
    ck_assert_int_eq(s21_is_less(dec10, dec9), 0);

    s21_decimal dec11 = {{0, 0, 0, 0}};
    s21_decimal dec12 = {{0, 0, 0, 0}};
    ck_assert_int_eq(s21_is_less(dec11, dec12), 0);
    ck_assert_int_eq(s21_is_less(dec12, dec11), 0);
}
END_TEST

START_TEST(s21_less_or_equal) {
    s21_decimal dec5 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec6 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_less_or_equal(dec5, dec6), 0);
    ck_assert_int_eq(s21_is_less_or_equal(dec6, dec5), 1);

    s21_decimal dec7 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec8 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_less_or_equal(dec7, dec8), 1);
    ck_assert_int_eq(s21_is_less_or_equal(dec8, dec7), 0);

    s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec2 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_less_or_equal(dec1, dec2), 0);
    ck_assert_int_eq(s21_is_less_or_equal(dec2, dec1), 1);

    s21_decimal dec3 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec4 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_less_or_equal(dec3, dec4), 1);
    ck_assert_int_eq(s21_is_less_or_equal(dec4, dec3), 0);

    s21_decimal dec9 = {{12345, 0, 0, 0}};
    s21_decimal dec10 = {{12345, 0, 0, 0}};
    ck_assert_int_eq(s21_is_less_or_equal(dec9, dec10), 1);
    ck_assert_int_eq(s21_is_less_or_equal(dec10, dec9), 1);

    s21_decimal dec11 = {{0, 0, 0, 0}};
    s21_decimal dec12 = {{0, 0, 0, 0}};
    ck_assert_int_eq(s21_is_less_or_equal(dec11, dec12), 1);
    ck_assert_int_eq(s21_is_less_or_equal(dec12, dec11), 1);
}
END_TEST

START_TEST(s21_greater) {
    s21_decimal dec5 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec6 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_greater(dec5, dec6), 1);
    ck_assert_int_eq(s21_is_greater(dec6, dec5), 0);

    s21_decimal dec7 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec8 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_greater(dec7, dec8), 0);
    ck_assert_int_eq(s21_is_greater(dec8, dec7), 1);

    s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec2 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_greater(dec1, dec2), 1);
    ck_assert_int_eq(s21_is_greater(dec2, dec1), 0);

    s21_decimal dec3 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec4 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_greater(dec3, dec4), 0);
    ck_assert_int_eq(s21_is_greater(dec4, dec3), 1);
}
END_TEST

START_TEST(s21_greater_or_equal) {
    s21_decimal dec5 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec6 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_greater_or_equal(dec5, dec6), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(dec6, dec5), 0);

    s21_decimal dec7 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec8 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_greater_or_equal(dec7, dec8), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(dec8, dec7), 1);

    s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec2 = {{12, 0, 0,    0b00000000000000010000000000000000}};  //  1.2;
    ck_assert_int_eq(s21_is_greater_or_equal(dec1, dec2), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(dec2, dec1), 0);

    s21_decimal dec3 = {{12345, 0, 0, 0b10000000000001000000000000000000}};  // -1.2345
    s21_decimal dec4 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_greater_or_equal(dec3, dec4), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(dec4, dec3), 1);

    s21_decimal dec9 = {{12345, 0, 0, 0}};
    s21_decimal dec10 = {{12345, 0, 0, 0}};
    ck_assert_int_eq(s21_is_greater_or_equal(dec9, dec10), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(dec10, dec9), 1);

    s21_decimal dec11 = {{0, 0, 0, 0}};
    s21_decimal dec12 = {{0, 0, 0, 0}};
    ck_assert_int_eq(s21_is_greater_or_equal(dec11, dec12), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(dec12, dec11), 1);
}
END_TEST

START_TEST(s21_equal) {
    s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec2 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 0);

    s21_decimal dec3 = {{120000, 0, 0,  0b00000000000001000000000000000000}};  //  12.0000
    s21_decimal dec4 = {{12, 0, 0,      0b00000000000000000000000000000000}};  //  12;
    ck_assert_int_eq(s21_is_equal(dec3, dec4), 1);

    s21_decimal dec5 = {{0, 0, 0,  0b00000000000000000000000000000000}};  //  0
    s21_decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //  0.0;
    ck_assert_int_eq(s21_is_equal(dec5, dec6), 1);

    s21_decimal dec7 = {{0, 0, 0, 0b00000000000000000000000000000000}};  //   0
    s21_decimal dec8 = {{0, 0, 0, 0b10000000000000000000000000000000}};  //  -0;
    ck_assert_int_eq(s21_is_equal(dec7, dec8), 0);
}
END_TEST

START_TEST(s21_equal_null) {
    s21_decimal dec1, dec2;
    s21_from_int_to_decimal(0, &dec1);
    s21_from_int_to_decimal(0, &dec2);
    dec1.bits[3] = 0;
    ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}
END_TEST

START_TEST(s21_not_equal) {
    s21_decimal dec1 = {{12345, 0, 0, 0b00000000000001000000000000000000}};  //  1.2345
    s21_decimal dec2 = {{12, 0, 0,    0b10000000000000010000000000000000}};  // -1.2;
    ck_assert_int_eq(s21_is_not_equal(dec1, dec2), 1);

    s21_decimal dec3 = {{120000, 0, 0,  0b00000000000001000000000000000000}};  //  12.0000
    s21_decimal dec4 = {{12, 0, 0,      0b00000000000000000000000000000000}};  //  12;
    ck_assert_int_eq(s21_is_not_equal(dec3, dec4), 0);

    s21_decimal dec5 = {{0, 0, 0,  0b00000000000000000000000000000000}};  //  0
    s21_decimal dec6 = {{00, 0, 0, 0b00000000000000010000000000000000}};  //  0.0;
    ck_assert_int_eq(s21_is_not_equal(dec5, dec6), 0);

    s21_decimal dec7 = {{0, 0, 0, 0b00000000000000000000000000000000}};  //   0
    s21_decimal dec8 = {{0, 0, 0, 0b10000000000000000000000000000000}};  //  -0;
    ck_assert_int_eq(s21_is_not_equal(dec7, dec8), 1);
}
END_TEST

START_TEST(s21_from_int_to_decimal_1) {
    s21_decimal dec;
    s21_from_int_to_decimal(0, &dec);
    ck_assert_int_eq(dec.bits[0], 0);
    ck_assert_int_eq(dec.bits[1], 0);
    ck_assert_int_eq(dec.bits[2], 0);
    ck_assert_int_eq(dec.bits[3], 0);

    s21_from_int_to_decimal(-128, &dec);
    ck_assert_int_eq(dec.bits[0], 128);
    ck_assert_int_eq(dec.bits[1], 0);
    ck_assert_int_eq(dec.bits[2], 0);
    ck_assert_int_eq(!!s21_get_bit_long(dec, 127), 1);

    s21_from_int_to_decimal(-2147483648, &dec);
    ck_assert_int_eq(dec.bits[0], 2147483648);
    ck_assert_int_eq(dec.bits[1], 0);
    ck_assert_int_eq(dec.bits[2], 0);
    ck_assert_int_eq(!!s21_get_bit_long(dec, 127), 1);

    s21_from_int_to_decimal(2147483647, &dec);
    ck_assert_int_eq(dec.bits[0], 2147483647);
    ck_assert_int_eq(dec.bits[1], 0);
    ck_assert_int_eq(dec.bits[2], 0);
    ck_assert_int_eq(dec.bits[3], 0);

    // s21_from_int_to_decimal(__builtin_nanf("0x7fc00000"), &dec);
    // ck_assert_int_eq(dec.bits[0], 0);
    // ck_assert_int_eq(dec.bits[1], 0);
    // ck_assert_int_eq(dec.bits[2], 0);
    // ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_1) {
    s21_decimal dec;
    float tmp = 0;
    float tmp1 = 0.03;
    s21_from_float_to_decimal(tmp1, &dec);
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
    s21_decimal dec;
    s21_from_float_to_decimal(-128.023, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
    s21_decimal dec;
    s21_from_float_to_decimal(-2.1474836E+09, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -2.1474836E+09, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
    s21_decimal dec;
    s21_from_float_to_decimal(22.14836E+03, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
    s21_decimal dec;
    s21_from_float_to_decimal(1.02E+08, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 1.02E+08, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
    s21_decimal dec;
    s21_from_float_to_decimal(-333.2222, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(s21_from_float_to_decimal_7) {
    s21_decimal dec;
    float a = 1.0 / 0.0;
    int ret = s21_from_float_to_decimal(a, &dec);
    ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(s21_from_float_to_decimal_8) {
    s21_decimal dec;
    float a = -1.0 / 0.0;
    s21_from_float_to_decimal(a, &dec);
    ck_assert_int_eq(dec.bits[0], 0);
    ck_assert_int_eq(dec.bits[1], 0);
    ck_assert_int_eq(dec.bits[2], 0);
    ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_9) {
    s21_decimal dec;
    float a = 0.0 / 0.0;
    s21_from_float_to_decimal(a, &dec);
    ck_assert_int_eq(dec.bits[0], 0);
    ck_assert_int_eq(dec.bits[1], 0);
    ck_assert_int_eq(dec.bits[2], 0);
    ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_big) {
    s21_decimal dec;
    float i = 29228162514264337593543950330.;
    s21_from_float_to_decimal(i, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, i, 1e-06);
}
END_TEST

START_TEST(s21_from_decimal_to_int_1) {
    s21_decimal dec;
    int result = 0;
    int number = 0;
    dec.bits[0] = 2147483647;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 0;
    result = s21_from_decimal_to_int(dec, &number);
    ck_assert_float_eq(number, 2147483647);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
    s21_decimal dec;
    int result = 0;
    int number = 0;
    dec.bits[0] = 133141;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 0;
    result = s21_from_decimal_to_int(dec, &number);
    ck_assert_int_eq(number, 133141);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
    s21_decimal dec;
    int result = 0;
    int number = 0;
    dec.bits[0] = 2147483648;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 0;
    s21_set_bit(&dec, 127);
    result = s21_from_decimal_to_int(dec, &number);
    ck_assert_int_eq(number, -2147483648);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_4) {
    s21_decimal dec;
    int result = 0, number = 0;
    dec.bits[0] = 123451234;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 2147483648;
    result = s21_from_decimal_to_int(dec, &number);
    ck_assert_int_eq(number, -123451234);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_5) {
    s21_decimal dec;
    int result = 0, number = 0;
    dec.bits[0] = 18;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 2147483648;
    result = s21_from_decimal_to_int(dec, &number);
    ck_assert_int_eq(number, -18);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_1) {
    s21_decimal dec;
    int result = 0;
    float number = 0.0;
    dec.bits[0] = 18122;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 2147680256;
    result = s21_from_decimal_to_float(dec, &number);
    ck_assert_float_eq(number, -18.122);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
    s21_decimal dec;
    int result = 0;
    float number = 0.0;
    dec.bits[0] = 1812;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 2147483648;
    result = s21_from_decimal_to_float(dec, &number);
    ck_assert_float_eq(number, -1812);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
    s21_decimal dec;
    int result = 0;
    float number = 0.0;

    dec.bits[0] = 0XFFFFFF;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 0;
    result = s21_from_decimal_to_float(dec, &number);
    ck_assert_float_eq(number, 16777215);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
    s21_decimal dec;
    int result = 0;
    float number = 0.0;

    dec.bits[0] = 23450987;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 2147745792;
    result = s21_from_decimal_to_float(dec, &number);
    ck_assert_float_eq(number, -2345.0987);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
    s21_decimal dec;
    int result = 0;
    float number = 0.0;

    dec.bits[0] = 4294967295;
    dec.bits[1] = 4294967295;
    dec.bits[2] = 0;
    dec.bits[3] = 0;
    result = s21_from_decimal_to_float(dec, &number);
    ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_truncate_1) {
    s21_decimal dec1;

    dec1.bits[3] = 0x000A0000;
    dec1.bits[2] = 0x0;
    dec1.bits[1] = 0xFFFFFFFF;
    dec1.bits[0] = 0xFFFFFFFF;
    s21_decimal result;
    result.bits[3] = 0x0;
    result.bits[2] = 0x0;
    result.bits[1] = 0x0;
    result.bits[0] = 0x6DF37F67;
s21_decimal res1;
s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_2) {
    s21_decimal dec1;

    dec1.bits[3] = 0x800C0000;
    dec1.bits[2] = 0x0;
    dec1.bits[1] = 0xFFFFFFFF;
    dec1.bits[0] = 0xFFFFFFFF;
    s21_decimal result;
    result.bits[3] = 0x80000000;
    result.bits[2] = 0x0;
    result.bits[1] = 0x0;
    result.bits[0] = 0x1197998;
s21_decimal res1;
s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_3) {
    s21_decimal dec1;

    dec1.bits[3] = 0x80000000;
    dec1.bits[2] = 0x0;
    dec1.bits[1] = 0xFFFFFFFF;
    dec1.bits[0] = 0xFFFFFFFF;
    s21_decimal result;
    result.bits[3] = 0x80000000;
    result.bits[2] = 0x0;
    result.bits[1] = 0xFFFFFFFF;
    result.bits[0] = 0xFFFFFFFF;
s21_decimal res1;
s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_4) {
    s21_decimal dec1;

    dec1.bits[0] = 0b00000000000000000000000001101101;
    dec1.bits[1] = 0b00000000000011000110010101011011;
    dec1.bits[2] = 0b00000000000000000011000000111001;
    dec1.bits[3] = 0b00000000000011100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10000111101111000001011000011110;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
s21_decimal res1;
s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_5) {
    s21_decimal dec1;

    dec1.bits[0] = 0b11011110101001001000000010110110;
    dec1.bits[1] = 0b01011111101001011101111110100000;
    dec1.bits[2] = 0b00011111111010011010111101100000;
    dec1.bits[3] = 0b00000000000010010000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00110100101011011100000100111110;
    result.bits[1] = 0b10001001000100001000011110111001;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
s21_decimal res1;
s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_6) {
    s21_decimal dec1;

    dec1.bits[3] = 0x80090000;
    dec1.bits[2] = 0;
    dec1.bits[1] = 0xFFFFEA34;
    dec1.bits[0] = 0xFF837E4F;
    s21_decimal result;
    s21_truncate(dec1, &result);
    s21_decimal res1;

    res1.bits[3] = 0x80000000;
    res1.bits[2] = 0;
    res1.bits[1] = 0x4;
    res1.bits[0] = 0x4B829C70;
    ck_assert_int_eq(res1.bits[3], result.bits[3]);
    ck_assert_int_eq(res1.bits[2], result.bits[2]);
    ck_assert_int_eq(res1.bits[1], result.bits[1]);
    ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_7) {
    s21_decimal dec1;

    dec1.bits[0] = 0b11010000101000110011000001101101;
    dec1.bits[1] = 0b00011111100110100110101101011000;
    dec1.bits[2] = 0;
    dec1.bits[3] = 0b00000000000010010000000000000000;
    s21_decimal result;
    s21_truncate(dec1, &result);
    s21_decimal result_origin;
    result_origin.bits[3] = 0;
    result_origin.bits[2] = 0;
    result_origin.bits[1] = 0;
    result_origin.bits[0] = 0b10000111101111000001011000011110;
    ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
    ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
    ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
    ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_8) {
    s21_decimal dec1;

    dec1.bits[0] = 0b01111000101001111011110011000110;
    dec1.bits[1] = 0b10011111111111001111101010000100;
    dec1.bits[2] = 0b00011111111010011010111101101101;
    dec1.bits[3] = 0b00000000000111000000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
s21_decimal res1;
s21_truncate(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_1) {
    s21_decimal dec1;

    dec1.bits[0] = 0b01100011000011111111111111111111;
    dec1.bits[1] = 0b01101011110001110101111000101101;
    dec1.bits[2] = 0b00000000000000000000000000000101;
    dec1.bits[3] = 0b10000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b01010100000010111110010000000000;
    result.bits[1] = 0b00000000000000000000000000000010;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_2) {
    s21_decimal dec1;

    dec1.bits[0] = 0b01010101001110101110101110110001;
    dec1.bits[1] = 0b00001101101101001101101001011111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000100100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000001;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_3) {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010011111100000001110001010010;
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111100;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_4) {
    s21_decimal dec1;

    dec1.bits[0] = 0b11001101110001110111110001000000;
    dec1.bits[1] = 0b00111110001001010000001001100000;
    dec1.bits[2] = 0b00100000010011111100111001011110;
    dec1.bits[3] = 0b10000000000001000000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10100000111111100100111000000100;
    result.bits[1] = 0b00011011110011101100110011101101;
    result.bits[2] = 0b00000000000000001101001111000010;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_5) {
    s21_decimal dec1;

    dec1.bits[0] = 0b10100000111111100100111000000100;
    dec1.bits[1] = 0b00011011110011101100110011101101;
    dec1.bits[2] = 0b00000000000000001101001111000010;
    dec1.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b10100000111111100100111000000100;
    result.bits[1] = 0b00011011110011101100110011101101;
    result.bits[2] = 0b00000000000000001101001111000010;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_6) {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b00000000000001110000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[3] = 0;
    result.bits[2] = 0;
    result.bits[1] = 0b00000000000000000000001000010010;
    result.bits[0] = 0b00110110101101101000110001000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_7) {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b10000000000001110000000000000000;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[3] = 0b10000000000000000000000000000000;
    result.bits[2] = 0;
    result.bits[1] = 0b00000000000000000000001000010010;
    result.bits[0] = 0b00110110101101101000110001000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_1) {
    s21_decimal dec1;

    dec1.bits[0] = 0b00001111111111111111111111111111;
    dec1.bits[1] = 0b00111110001001010000001001100001;
    dec1.bits[2] = 0b00100000010011111100111001011110;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b10100111011000111111111111111111;
    result.bits[1] = 0b00001101111000001011011010110011;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_2) {
    s21_decimal dec1;

    dec1.bits[0] = 0b00001111111111111111111111111111;
    dec1.bits[1] = 0b00111110001001010000001001100001;
    dec1.bits[2] = 0b00100000010011111100111001011110;
    dec1.bits[3] = 0b10000000000010100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b10100111011001000000000000000000;
    result.bits[1] = 0b00001101111000001011011010110011;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_3) {
    s21_decimal dec1;

    dec1.bits[0] = 0b10111101001001111000010001010010;
    dec1.bits[1] = 0b00000000000000000000000000011100;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000010010000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111100;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_4) {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010011111100000001110001010010;
    dec1.bits[1] = 0b00000000000000000000000100100000;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000010100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000001111011;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_5) {
    s21_decimal dec1;

    dec1.bits[0] = 0b01010101001110101110101110110001;
    dec1.bits[1] = 0b00001101101101001101101001011111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b10000000000100100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000001;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_6) {
    s21_decimal dec1;

    dec1.bits[0] = 0b01010101001110101110101110110001;
    dec1.bits[1] = 0b00001101101101001101101001011111;
    dec1.bits[2] = 0b00000000000000000000000000000000;
    dec1.bits[3] = 0b00000000000100100000000000000000;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000000;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_float_eq(res1.bits[0], result.bits[0]);
    ck_assert_float_eq(res1.bits[1], result.bits[1]);
    ck_assert_float_eq(res1.bits[2], result.bits[2]);
    ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_7) {
    s21_decimal dec1;

    dec1.bits[0] = 0b10010111011100111001111111111111;
    dec1.bits[1] = 0b00111100000010000011000110001101;
    dec1.bits[2] = 0b00000000000000000000000000000001;
    dec1.bits[3] = 0b00000000000001110000000000000000;
    s21_decimal result;
    s21_floor(dec1, &result);
    s21_decimal result_origin;
    result_origin.bits[3] = 0;
    result_origin.bits[2] = 0;
    result_origin.bits[1] = 0b00000000000000000000001000010010;
    result_origin.bits[0] = 0b00110110101101101000110000111111;
    ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
    ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
    ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
    ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_negate_1) {
    int a = 10;
    int res_a = 0;
    s21_decimal dec;
    s21_from_int_to_decimal(a, &dec);
    s21_decimal res;
s21_negate(dec, &res);
    s21_from_decimal_to_int(res, &res_a);
    ck_assert_int_eq(-10, res_a);
}
END_TEST

START_TEST(s21_negate_2) {
    float a = 10.12345;
    float res_a = 0;
    s21_decimal dec;
    s21_from_float_to_decimal(a, &dec);
    s21_decimal res;
s21_negate(dec, &res);
    s21_from_decimal_to_float(res, &res_a);
    ck_assert_float_eq(-10.12345, res_a);
}
END_TEST

START_TEST(s21_negate_3) {
    float a = 10.1234e5;
    float res_a = 0;
    s21_decimal src;
    s21_from_float_to_decimal(a, &src);
    s21_decimal res;
    s21_negate(src, &res);
    s21_from_decimal_to_float(res, &res_a);
    ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(s21_negate_4) {
    float a = -10;
    float res_a = 0;
    s21_decimal dec;
    s21_from_float_to_decimal(a, &dec);
    s21_decimal res;
s21_negate(dec, &res);
    s21_from_decimal_to_float(res, &res_a);
    ck_assert_float_eq(10, res_a);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, s21_add_int_1);
    tcase_add_test(tc1_1, s21_add_int_2);
    tcase_add_test(tc1_1, s21_add_int_3);
    tcase_add_test(tc1_1, s21_add_int_4);
    tcase_add_test(tc1_1, s21_add_int_5);
    tcase_add_test(tc1_1, s21_add_inf);
    tcase_add_test(tc1_1, s21_add_neg_inf);
    tcase_add_test(tc1_1, s21_add_float_1);
    tcase_add_test(tc1_1, s21_add_float_2);
    tcase_add_test(tc1_1, s21_add_float_3);
    tcase_add_test(tc1_1, s21_add_float_4);

    tcase_add_test(tc1_1, s21_sub_int_1);
    tcase_add_test(tc1_1, s21_sub_int_2);
    tcase_add_test(tc1_1, s21_sub_int_3);
    tcase_add_test(tc1_1, s21_sub_int_4);
    tcase_add_test(tc1_1, s21_sub_int_5);
    tcase_add_test(tc1_1, s21_sub_inf);
    tcase_add_test(tc1_1, s21_sub_neg_inf);
    tcase_add_test(tc1_1, s21_sub_float_1);
    tcase_add_test(tc1_1, s21_sub_float_2);
    tcase_add_test(tc1_1, s21_sub_float_3);
    tcase_add_test(tc1_1, s21_sub_float_4);

    tcase_add_test(tc1_1, s21_mul_1);
    tcase_add_test(tc1_1, s21_mul_2);
    tcase_add_test(tc1_1, s21_mul_3);
    tcase_add_test(tc1_1, s21_mul_4);
    tcase_add_test(tc1_1, s21_mul_5);
    tcase_add_test(tc1_1, s21_mul_too_big);
    tcase_add_test(tc1_1, s21_mul_too_big_neg);
    tcase_add_test(tc1_1, s21_mul_rounding);

    tcase_add_test(tc1_1, s21_div_1);
    tcase_add_test(tc1_1, s21_div_2);
    tcase_add_test(tc1_1, s21_div_3);
    tcase_add_test(tc1_1, s21_div_4);
    tcase_add_test(tc1_1, s21_div_5);
    tcase_add_test(tc1_1, s21_div_6);
    tcase_add_test(tc1_1, s21_div_null);

    tcase_add_test(tc1_1, s21_mod_1);
    tcase_add_test(tc1_1, s21_mod_2);
    tcase_add_test(tc1_1, s21_mod_3);
    tcase_add_test(tc1_1, s21_mod_4);
    tcase_add_test(tc1_1, s21_mod_4_1);
    tcase_add_test(tc1_1, s21_mod_5);
    tcase_add_test(tc1_1, s21_mod_div_null);
    tcase_add_test(tc1_1, s21_mod_6);

    tcase_add_test(tc1_1, s21_less);

    tcase_add_test(tc1_1, s21_less_or_equal);

    tcase_add_test(tc1_1, s21_greater);

    tcase_add_test(tc1_1, s21_greater_or_equal);

    tcase_add_test(tc1_1, s21_equal);

    tcase_add_test(tc1_1, s21_equal_null);

    tcase_add_test(tc1_1, s21_not_equal);

    tcase_add_test(tc1_1, s21_from_int_to_decimal_1);

    tcase_add_test(tc1_1, s21_from_decimal_to_int_1);
    tcase_add_test(tc1_1, s21_from_decimal_to_int_2);
    tcase_add_test(tc1_1, s21_from_decimal_to_int_3);
    tcase_add_test(tc1_1, s21_from_decimal_to_int_4);
    tcase_add_test(tc1_1, s21_from_decimal_to_int_5);

    tcase_add_test(tc1_1, s21_from_float_to_decimal_1);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_2);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_3);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_4);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_5);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_6);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_7);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_8);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_9);
    tcase_add_test(tc1_1, s21_from_float_to_decimal_big);
    
    tcase_add_test(tc1_1, s21_from_decimal_to_float_1);
    tcase_add_test(tc1_1, s21_from_decimal_to_float_2);
    tcase_add_test(tc1_1, s21_from_decimal_to_float_3);
    tcase_add_test(tc1_1, s21_from_decimal_to_float_4);
    tcase_add_test(tc1_1, s21_from_decimal_to_float_5);

    tcase_add_test(tc1_1, s21_truncate_1);
    tcase_add_test(tc1_1, s21_truncate_2);
    tcase_add_test(tc1_1, s21_truncate_3);
    tcase_add_test(tc1_1, s21_truncate_4);
    tcase_add_test(tc1_1, s21_truncate_5);
    tcase_add_test(tc1_1, s21_truncate_6);
    tcase_add_test(tc1_1, s21_truncate_7);
    tcase_add_test(tc1_1, s21_truncate_8);

    tcase_add_test(tc1_1, s21_round_1);
    tcase_add_test(tc1_1, s21_round_2);
    tcase_add_test(tc1_1, s21_round_3);
    tcase_add_test(tc1_1, s21_round_4);
    tcase_add_test(tc1_1, s21_round_5);
    tcase_add_test(tc1_1, s21_round_6);
    tcase_add_test(tc1_1, s21_round_7);

    tcase_add_test(tc1_1, s21_floor_1);
    tcase_add_test(tc1_1, s21_floor_2);
    tcase_add_test(tc1_1, s21_floor_3);
    tcase_add_test(tc1_1, s21_floor_4);
    tcase_add_test(tc1_1, s21_floor_5);
    tcase_add_test(tc1_1, s21_floor_6);
    tcase_add_test(tc1_1, s21_floor_7);

    tcase_add_test(tc1_1, s21_negate_1);
    tcase_add_test(tc1_1, s21_negate_2);
    tcase_add_test(tc1_1, s21_negate_3);
    tcase_add_test(tc1_1, s21_negate_4);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
