//
//  1_30.c
//  check_main
//
//  Created by Joramun Sasin on 8/12/22.
//

#include "../check_main.h"

// 1 / 30 (0-0)
START_TEST(s21_div_box_1_30_0_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{1297438037, 893747220, 18070036, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (0-1)
START_TEST(s21_div_box_1_30_0_1) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 1);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{89478485, 347537611, 180700362, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (1-0)
START_TEST(s21_div_box_1_30_1_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 1);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{2706724181, 2666355099, 1807003, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (1-1)
START_TEST(s21_div_box_1_30_1_1) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 1);
    s21_set_scale(&b, 1);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{1297438037, 893747220, 18070036, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (10-10)
START_TEST(s21_div_box_1_30_10_10) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 10);
    s21_set_scale(&b, 10);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{1297438037, 893747220, 18070036, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (28-28)
START_TEST(s21_div_box_1_30_28_28) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 28);
    s21_set_scale(&b, 28);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{1297438037, 893747220, 18070036, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (28-0)
START_TEST(s21_div_box_1_30_28_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 28);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{0, 0, 0, 0}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (0-28)
START_TEST(s21_div_box_1_30_0_28) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 28);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{894784853, 3475376110, 1807003620, 131072}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (5-15)
START_TEST(s21_div_box_1_30_5_15) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 5);
    s21_set_scale(&b, 15);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{894784853, 3475376110, 1807003620, 1310720}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (15-5)
START_TEST(s21_div_box_1_30_15_5) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 15);
    s21_set_scale(&b, 5);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{1954764117, 7761021, 0, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (5-0)
START_TEST(s21_div_box_1_30_5_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 5);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{3860157781, 3008032232, 180, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 30 (0-5)
START_TEST(s21_div_box_1_30_0_5) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{30, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 5);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{894784853, 3475376110, 1807003620, 1638400}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

void div_1_30(TCase *tc) {
    tcase_add_test(tc, s21_div_box_1_30_0_0);
    tcase_add_test(tc, s21_div_box_1_30_0_1);
    tcase_add_test(tc, s21_div_box_1_30_1_0);
    tcase_add_test(tc, s21_div_box_1_30_1_1);
    tcase_add_test(tc, s21_div_box_1_30_10_10);
    tcase_add_test(tc, s21_div_box_1_30_28_28);
    tcase_add_test(tc, s21_div_box_1_30_28_0);
    tcase_add_test(tc, s21_div_box_1_30_0_28);
    tcase_add_test(tc, s21_div_box_1_30_5_15);
    tcase_add_test(tc, s21_div_box_1_30_15_5);
    tcase_add_test(tc, s21_div_box_1_30_5_0);
    tcase_add_test(tc, s21_div_box_1_30_0_5);
}

//  1 / 3
//  1 / 30
//  10 / 3
//  4 / 3
//  11 / 3
//  4 / 2
//  40/2
//  4/20
//  ? / 0
//  0 / ?
//  + -
//  scales 0-0 0-1 1-0 1-1 10-10 28-28 28-0 0-28 0-0
