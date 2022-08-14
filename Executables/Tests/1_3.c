//
//  1_3.c
//  check_main
//
//  Created by Joramun Sasin on 8/12/22.
//

#include "../check_main.h"

// 1 / 3 (0-0)
START_TEST(s21_div_box_1_3_0_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{89478485, 347537611, 180700362, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (0-1)
START_TEST(s21_div_box_1_3_0_1) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 1);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{894784853, 3475376110, 1807003620, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (1-0)
START_TEST(s21_div_box_1_3_1_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 1);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{1297438037, 893747220, 18070036, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (1-1)
START_TEST(s21_div_box_1_3_1_1) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 1);
    s21_set_scale(&b, 1);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{89478485, 347537611, 180700362, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (10-10)
START_TEST(s21_div_box_1_3_10_10) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 10);
    s21_set_scale(&b, 10);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{89478485, 347537611, 180700362, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (28-28)
START_TEST(s21_div_box_1_3_28_28) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 28);
    s21_set_scale(&b, 28);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{89478485, 347537611, 180700362, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (28-0)
START_TEST(s21_div_box_1_3_28_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 28);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{0, 0, 0, 0}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (0-28)
START_TEST(s21_div_box_1_3_0_28) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 28);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{894784853, 3475376110, 1807003620, 65536}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (5-15)
START_TEST(s21_div_box_1_3_5_15) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 5);
    s21_set_scale(&b, 15);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{894784853, 3475376110, 1807003620, 1245184}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (15-5)
START_TEST(s21_div_box_1_3_15_5) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 15);
    s21_set_scale(&b, 5);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{2367771989, 77610214, 0, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (5-0)
START_TEST(s21_div_box_1_3_5_0) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 5);
    s21_set_scale(&b, 0);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{4241839445, 15551256, 1807, 1835008}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

// 1 / 3 (0-5)
START_TEST(s21_div_box_1_3_0_5) {
    s21_decimal a = {{1, 0, 0, 0}};
    s21_decimal b = {{3, 0, 0, 0}};
    s21_set_scale(&a, 0);
    s21_set_scale(&b, 5);
    s21_decimal result = INITDEC;
    int ex_code = s21_div(a, b, &result);
    s21_decimal expected = {{894784853, 3475376110, 1807003620, 1572864}};

    ASSERT_DECIMAL_EQ
    ck_assert_int_eq(0, ex_code);
}
END_TEST

void div_1_3(TCase *tc) {
    tcase_add_test(tc, s21_div_box_1_3_0_0);
    tcase_add_test(tc, s21_div_box_1_3_0_1);
    tcase_add_test(tc, s21_div_box_1_3_1_0);
    tcase_add_test(tc, s21_div_box_1_3_1_1);
    tcase_add_test(tc, s21_div_box_1_3_10_10);
    tcase_add_test(tc, s21_div_box_1_3_28_28);
    tcase_add_test(tc, s21_div_box_1_3_28_0);
    tcase_add_test(tc, s21_div_box_1_3_0_28);
    tcase_add_test(tc, s21_div_box_1_3_5_15);
    tcase_add_test(tc, s21_div_box_1_3_15_5);
    tcase_add_test(tc, s21_div_box_1_3_5_0);
    tcase_add_test(tc, s21_div_box_1_3_0_5);
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
