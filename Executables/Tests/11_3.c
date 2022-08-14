//
//  10_3.c
//  check_main
//
//  Created by Joramun Sasin on 8/12/22.
//

#include "../check_main.h"

// 11 / 3 (0-0)
START_TEST(s21_div_box_11_3_0_0) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (0-1)
START_TEST(s21_div_box_11_3_0_1) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 1);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 1769472}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (1-0)
START_TEST(s21_div_box_11_3_1_0) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 1);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{1386916523, 1241284831, 198770398, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (1-1)
START_TEST(s21_div_box_11_3_1_1) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 1);
    s21_set_scale(&b, 1);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (10-10)
START_TEST(s21_div_box_11_3_10_10) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 10);
    s21_set_scale(&b, 10);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (28-28)
START_TEST(s21_div_box_11_3_28_28) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 28);
    s21_set_scale(&b, 28);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (28-0)
START_TEST(s21_div_box_11_3_28_0) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 28);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{4, 0, 0, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (0-28)
START_TEST(s21_div_box_11_3_0_28) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 28);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 0}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (5-15)
START_TEST(s21_div_box_11_3_5_15) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 5);
    s21_set_scale(&b, 15);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 1179648}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (15-5)
START_TEST(s21_div_box_11_3_15_5) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 15);
    s21_set_scale(&b, 5);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{275688107, 853712360, 0, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (5-0)
START_TEST(s21_div_box_11_3_5_0) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 5);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{3710560939, 171063826, 19877, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 11 / 3 (0-5)
START_TEST(s21_div_box_11_3_0_5) {
    s21_decimal a = {{11, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 5);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{984263339, 3822913721, 1987703982, 1507328}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

void div_11_3(TCase *tc) {
    tcase_add_test(tc, s21_div_box_11_3_0_0);
    tcase_add_test(tc, s21_div_box_11_3_0_1);
    tcase_add_test(tc, s21_div_box_11_3_1_0);
    tcase_add_test(tc, s21_div_box_11_3_1_1);
    tcase_add_test(tc, s21_div_box_11_3_10_10);
    tcase_add_test(tc, s21_div_box_11_3_28_28);
    tcase_add_test(tc, s21_div_box_11_3_28_0);
    tcase_add_test(tc, s21_div_box_11_3_0_28);
    tcase_add_test(tc, s21_div_box_11_3_5_15);
    tcase_add_test(tc, s21_div_box_11_3_15_5);
    tcase_add_test(tc, s21_div_box_11_3_5_0);
    tcase_add_test(tc, s21_div_box_11_3_0_5);
}

//  1 / 3
//  1 / 30
//  10 / 3
//  4 / 3
//  11 / 3
//  4 / 2
//  40/2
//  4/20
//  scales 0-0 0-1 1-0 1-1 10-10 28-28 28-0 0-28 0-0
