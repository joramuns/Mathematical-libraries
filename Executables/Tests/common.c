//
//  check_main.c
//  Decimal
//

#include "check_main.h"

START_TEST(compare_01) {
    s21_decimal a = {{0, 0, 0, 0}};
    s21_decimal b = {{0, 0, 0, 0}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
    ck_assert_int_eq(s21_is_not_equal(a, b), 0);
}
END_TEST

START_TEST(compare_02) {
    s21_decimal a = {{123, 123, 123, 0}};
    s21_decimal b = {{123, 123, 123, 0}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
    ck_assert_int_eq(s21_is_not_equal(a, b), 0);
}
END_TEST

START_TEST(compare_03) {
    s21_decimal a = {{123, 0, 0, 0}};
    s21_decimal b = {{123, 0, 0, -2147483648}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_04) {
    s21_decimal a = {{4294967295, 4294967295, 0, 1835008}};
    s21_decimal b = {{4294967295, 4294967294, 0, 1835008}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_05) {
    s21_decimal a = {{4294967295, 4294967295, 4294967295, 65536}};
    s21_decimal b = {{4294967295, 4294967295, 4294967295, 196608}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_06) {
    s21_decimal a = {{4294967295, 4294967295, 4294967295, 65536}};
    s21_decimal b = {{4294967295, 4294967295, 4294967295, 196608}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_07) {
    s21_decimal a = {{2576980377, 4278124286, 4294967295, -2147483648}};
    s21_decimal b = {{2576980377, 4278124286, 4294967278, -2147483648}};
    ck_assert_int_eq(s21_is_less(a, b), 1);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_08) {
    s21_decimal a = {{12345600, 0, 0, 196608}};
    s21_decimal b = {{123456, 0, 0, 65536}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
    ck_assert_int_eq(s21_is_not_equal(a, b), 0);
}
END_TEST

START_TEST(compare_09) {
    s21_decimal a = {{12345678, 0, 0, 0}};
    s21_decimal b = {{123456781, 0, 0, 65536}};
    ck_assert_int_eq(s21_is_less(a, b), 1);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_10) {
    s21_decimal a = {{0, 0, 0, 0}};
    s21_decimal b = {{0, 0, 0, -2147483648}};
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
    ck_assert_int_eq(s21_is_not_equal(a, b), 0);
}
END_TEST

START_TEST(compare_11) {
    s21_decimal a = {{12345, 0, 0, 262144}};  //  1.2345
    s21_decimal b = {{12, 0, 0,    2147549184}};  // -1.2
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_12) {
    s21_decimal a = {{12345, 0, 0, 2147745792}};  // -1.2345
    s21_decimal b = {{12, 0, 0,    65536}};  //  1.2
    ck_assert_int_eq(s21_is_less(a, b), 1);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_13) {
    s21_decimal a = {{12345, 0, 0, 262144}};  //  1.2345
    s21_decimal b = {{12, 0, 0,    65536}};  //  1.2
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_14) {
    s21_decimal a = {{12345, 0, 0, 2147745792}};  // -1.2345
    s21_decimal b = {{12, 0, 0,    2147549184}};  // -1.2
    ck_assert_int_eq(s21_is_less(a, b), 1);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}
END_TEST

START_TEST(compare_15) {
    s21_decimal a = {{120000, 0, 0,  262144}};  //  12.0000
    s21_decimal b = {{12, 0, 0,      0}};  //  12
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater(a, b), 0);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 1);
    ck_assert_int_eq(s21_is_not_equal(a, b), 0);
}
END_TEST

START_TEST(compare_16) {
    s21_decimal a = {{120000, 0, 0,  262144}};  //  12.0000
    s21_decimal b = {{12, 0, 0, 2147483648}};  //  -12
    ck_assert_int_eq(s21_is_less(a, b), 0);
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 0);
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);
    ck_assert_int_eq(s21_is_equal(a, b), 0);
    ck_assert_int_eq(s21_is_not_equal(a, b), 1);
    ck_assert_int_eq(s21_is_greater_noscale(a, b), 1);
}
END_TEST

START_TEST(floor_test_zero) {
    s21_decimal input = {{0, 0, 0, 0}};
    s21_set_scale(&input, 15);
    s21_decimal expected = {{0, 0, 0, 0}};
    s21_decimal result;
    s21_floor(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_1) {
    s21_decimal input = {{362732873, 0, 0, 0}};
    s21_set_sign(&input);
    s21_decimal expected = {{362732873, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_floor(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_2) {
    s21_decimal input = {{572963473, 0, 0, 0}};
    s21_set_scale(&input, 4);
    s21_decimal expected = {{57296, 0, 0, 0}};
    s21_decimal result;
    s21_floor(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_3) {
    s21_decimal input = {{3041575557, 10215045, 0, 0}};
    s21_set_sign(&input);
    s21_set_scale(&input, 8);
    s21_decimal expected = {{438732873, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_floor(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_4) {
    s21_decimal input = {{1280801280, 202212445, 0, 0}};
    s21_set_scale(&input, 8);
    s21_decimal expected = {{95023802, 2, 0, 0}};
    s21_decimal result;
    s21_floor(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_5) {
    s21_decimal input = {{4294967295, 4294967295, 4294967295, 0}};
    s21_set_sign(&input);
    s21_set_scale(&input, 28);
    s21_decimal expected = {{8, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_floor(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_6) {
    s21_decimal dec1;
    dec1.bits[0] = 268435455;
    dec1.bits[1] = 1042612833;
    dec1.bits[2] = 542101086;
    dec1.bits[3] = 655360;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 2808348671;
    result.bits[1] = 232830643;
    result.bits[2] = 0;
    result.bits[3] = 0;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_7) {
    s21_decimal dec1;
    dec1.bits[0] = 268435455;
    dec1.bits[1] = 1042612833;
    dec1.bits[2] = 542101086;
    dec1.bits[3] = 2148139008;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 2808348672;
    result.bits[1] = 232830643;
    result.bits[2] = 0;
    result.bits[3] = 2147483648;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_8) {
    s21_decimal dec1;
    dec1.bits[0] = 3173483602;
    dec1.bits[1] = 28;
    dec1.bits[2] = 0;
    dec1.bits[3] = 2148073472;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 124;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 2147483648;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_9) {
    s21_decimal dec1;
    dec1.bits[0] = 2481986642;
    dec1.bits[1] = 288;
    dec1.bits[2] = 0;
    dec1.bits[3] = 655360;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 123;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 0;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_10) {
    s21_decimal dec1;
    dec1.bits[0] = 1429924785;
    dec1.bits[1] = 229956191;
    dec1.bits[2] = 0;
    dec1.bits[3] = 2148663296;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 1;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 2147483648;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_11) {
    s21_decimal dec1;
    dec1.bits[0] = 1429924785;
    dec1.bits[1] = 229956191;
    dec1.bits[2] = 0;
    dec1.bits[3] = 1179648;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 0;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 0;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(floor_test_12) {
    s21_decimal dec1;
    dec1.bits[0] = 2540937215;
    dec1.bits[1] = 1007169933;
    dec1.bits[2] = 1;
    dec1.bits[3] = 458752;
    s21_decimal res1;
    s21_floor(dec1, &res1);
    s21_decimal result;
    result.bits[3] = 0;
    result.bits[2] = 0;
    result.bits[1] = 530;
    result.bits[0] = 917933119;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(round_zero) {
    s21_decimal input = {{0, 0, 0, 0}};
    s21_set_scale(&input, 15);
    s21_decimal expected = {{0}};
    s21_decimal result;
    s21_round(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(round_1) {
    s21_decimal input = {{362732873, 0, 0, 0}};
    s21_set_sign(&input);
    s21_decimal expected = {{362732873, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_round(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(round_2) {
    s21_decimal input = {{45, 0, 0, 0}};
    s21_set_scale(&input, 1);
    s21_decimal expected = {{5, 0, 0, 0}};
    s21_decimal result;
    s21_round(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(round_3) {
    s21_decimal input = {{3041575557, 10215045, 0, 0}};
    s21_set_sign(&input);
    s21_set_scale(&input, 8);
    s21_decimal expected = {{438732872, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_round(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(round_4) {
    s21_decimal input = {{1280801280, 202212445, 0, 0}};
    s21_set_scale(&input, 8);
    s21_decimal expected = {{95023802, 2, 0, 0}};
    s21_decimal result;
    s21_round(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(round_5) {
    s21_decimal input = {{4294967295, 4294967295, 4294967295, 0}};
    s21_set_sign(&input);
    s21_set_scale(&input, 28);
    s21_decimal expected = {{8, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_round(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(round_6) {
    s21_decimal dec1;

    dec1.bits[0] = 1661992959;
    dec1.bits[1] = 1808227885;
    dec1.bits[2] = 5;
    dec1.bits[3] = 2148139008;
    s21_decimal result;
    result.bits[0] = 1410065408;
    result.bits[1] = 2;
    result.bits[2] = 0;
    result.bits[3] = 2147483648;
    s21_decimal res1;
    s21_round(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(round_7) {
    s21_decimal dec1;

    dec1.bits[0] = 1429924785;
    dec1.bits[1] = 229956191;
    dec1.bits[2] = 0;
    dec1.bits[3] = 2148663296;
    s21_decimal result;
    result.bits[0] = 1;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 2147483648;
    s21_decimal res1;
    s21_round(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(round_8) {
    s21_decimal dec1;

    dec1.bits[0] = 2481986642;
    dec1.bits[1] = 288;
    dec1.bits[2] = 0;
    dec1.bits[3] = 655360;
    s21_decimal result;
    result.bits[0] = 124;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 0;
    s21_decimal res1;
    s21_round(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(round_9) {
    s21_decimal dec1;

    dec1.bits[0] = 3452402752;
    dec1.bits[1] = 1042612832;
    dec1.bits[2] = 542101086;
    dec1.bits[3] = 2147745792;
    s21_decimal result;
    result.bits[0] = 2701020676;
    result.bits[1] = 466537709;
    result.bits[2] = 54210;
    result.bits[3] = 2147483648;
    s21_decimal res1;
    s21_round(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(round_10) {
    s21_decimal dec1;

    dec1.bits[0] = 2701020676;
    dec1.bits[1] = 466537709;
    dec1.bits[2] = 54210;
    dec1.bits[3] = 0;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[0] = 2701020676;
    result.bits[1] = 466537709;
    result.bits[2] = 54210;
    result.bits[3] = 0;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(round_11) {
    s21_decimal dec1;

    dec1.bits[0] = 2540937215;
    dec1.bits[1] = 1007169933;
    dec1.bits[2] = 1;
    dec1.bits[3] = 458752;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[3] = 0;
    result.bits[2] = 0;
    result.bits[1] = 530;
    result.bits[0] = 917933120;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(round_12) {
    s21_decimal dec1;

    dec1.bits[0] = 2540937215;
    dec1.bits[1] = 1007169933;
    dec1.bits[2] = 1;
    dec1.bits[3] = 2147942400;
    s21_decimal res1;
    s21_round(dec1, &res1);
    s21_decimal result;
    result.bits[3] = 2147483648;
    result.bits[2] = 0;
    result.bits[1] = 530;
    result.bits[0] = 917933120;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_zero) {
    s21_decimal input = {{0, 0, 0, 0}};
    s21_set_scale(&input, 15);
    s21_decimal expected = {{0}};
    s21_decimal result;
    s21_truncate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(truncate_1) {
    s21_decimal input = {{362732873, 0, 0, 0}};
    s21_set_sign(&input);
    s21_decimal expected = {{362732873, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_truncate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(truncate_2) {
    s21_decimal input = {{572963473, 0, 0, 0}};
    s21_set_scale(&input, 4);
    s21_decimal expected = {{57296, 0, 0, 0}};
    s21_decimal result;
    s21_truncate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(truncate_3) {
    s21_decimal input = {{3041575557, 10215045, 0, 0}};
    s21_set_sign(&input);
    s21_set_scale(&input, 8);
    s21_decimal expected = {{438732872, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_truncate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(truncate_4) {
    s21_decimal input = {{1280801280, 202212445, 0, 0}};
    s21_set_scale(&input, 8);
    s21_decimal expected = {{95023802, 2, 0, 0}};
    s21_decimal result;
    s21_truncate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(truncate_5) {
    s21_decimal input = {{4294967295, 4294967295, 4294967295, 0}};
    s21_set_sign(&input);
    s21_set_scale(&input, 28);
    s21_decimal expected = {{7, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    s21_truncate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
}
END_TEST

START_TEST(truncate_6) {
    s21_decimal dec1;
    dec1.bits[3] = 655360;
    dec1.bits[2] = 0;
    dec1.bits[1] = 4294967295;
    dec1.bits[0] = 4294967295;
    s21_decimal result;
    result.bits[3] = 0;
    result.bits[2] = 0;
    result.bits[1] = 0;
    result.bits[0] = 1844674407;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_7) {
    s21_decimal dec1;
    dec1.bits[3] = 2148270080;
    dec1.bits[2] = 0;
    dec1.bits[1] = 4294967295;
    dec1.bits[0] = 4294967295;
    s21_decimal result;
    result.bits[3] = 2147483648;
    result.bits[2] = 0;
    result.bits[1] = 0;
    result.bits[0] = 18446744;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_8) {
    s21_decimal dec1;
    dec1.bits[3] = 2147483648;
    dec1.bits[2] = 0;
    dec1.bits[1] = 4294967295;
    dec1.bits[0] = 4294967295;
    s21_decimal result;
    result.bits[3] = 2147483648;
    result.bits[2] = 0;
    result.bits[1] = 4294967295;
    result.bits[0] = 4294967295;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_9) {
    s21_decimal dec1;
    dec1.bits[0] = 109;
    dec1.bits[1] = 812379;
    dec1.bits[2] = 12345;
    dec1.bits[3] = 917504;
    s21_decimal result;
    result.bits[0] = 2277250590;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 0;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_10) {
    s21_decimal dec1;
    dec1.bits[0] = 3735322806;
    dec1.bits[1] = 1604706208;
    dec1.bits[2] = 535408480;
    dec1.bits[3] = 589824;
    s21_decimal result;
    result.bits[0] = 883802430;
    result.bits[1] = 2299561913;
    result.bits[2] = 0;
    result.bits[3] = 0;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_11) {
    s21_decimal dec1;
    dec1.bits[3] = 2148073472;
    dec1.bits[2] = 0;
    dec1.bits[1] = 4294961716;
    dec1.bits[0] = 4286807631;
    s21_decimal result;
    s21_truncate(dec1, &result);
    s21_decimal res1;
    res1.bits[3] = 2147483648;
    res1.bits[2] = 0;
    res1.bits[1] = 4;
    res1.bits[0] = 1266850928;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_12) {
    s21_decimal dec1;
    dec1.bits[0] = 3500355693;
    dec1.bits[1] = 530213720;
    dec1.bits[2] = 0;
    dec1.bits[3] = 589824;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    s21_decimal result;
    result.bits[3] = 0;
    result.bits[2] = 0;
    result.bits[1] = 0;
    result.bits[0] = 2277250590;
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(truncate_13) {
    s21_decimal dec1;
    dec1.bits[0] = 2024258758;
    dec1.bits[1] = 2684156548;
    dec1.bits[2] = 535408493;
    dec1.bits[3] = 1835008;
    s21_decimal result;
    result.bits[0] = 0;
    result.bits[1] = 0;
    result.bits[2] = 0;
    result.bits[3] = 0;
    s21_decimal res1;
    s21_truncate(dec1, &res1);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], res1.bits[i]);
    }
}
END_TEST

START_TEST(negate_1) {
    s21_decimal input = {{1}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{1, 0, 0, 0}};
    s21_set_sign(&expected);
    int status = s21_negate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(negate_2) {
    s21_decimal input = {{1, 0, 0, 0}};
    s21_set_sign(&input);
    s21_decimal result = {{0}};
    s21_decimal expected = {{1}};
    int status = s21_negate(input, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(negate_3) {
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

START_TEST(negate_4) {
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

START_TEST(negate_5) {
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

START_TEST(negate_6) {
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

START_TEST(int_to_dec_1) {
    int src = INT_MIN;
    s21_decimal expected = {{INT_MIN, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    int status = s21_from_int_to_decimal(src, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(int_to_dec_2) {
    int src = INT_MAX;
    s21_decimal expected = {{INT_MAX, 0, 0, 0}};
    s21_decimal result;
    int status = s21_from_int_to_decimal(src, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(int_to_dec_3) {
    int src = 0;
    s21_decimal expected = {{0}};
    s21_decimal result;
    int status = s21_from_int_to_decimal(src, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(int_to_dec_4) {
    int src = 1234567;
    s21_decimal expected = {{1234567, 0, 0, 0}};
    s21_decimal result;
    int status = s21_from_int_to_decimal(src, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(int_to_dec_5) {
    int src = -98765;
    s21_decimal expected = {{98765, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_decimal result;
    int status = s21_from_int_to_decimal(src, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(dec_to_int_1) {
    int expected = INT_MAX, result;
    s21_decimal src = {{INT_MAX, 0, 0, 0}};
    int status = s21_from_decimal_to_int(src, &result);
    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(status, 0);
}

START_TEST(dec_to_int_2) {
    int expected = INT_MIN, result;
    s21_decimal src = {{INT_MIN, 0, 0, 0}};
    s21_set_sign(&src);
    int status = s21_from_decimal_to_int(src, &result);
    ck_assert_int_eq(result, expected);
    ck_assert_int_eq(status, 0);
}

START_TEST(dec_to_int_3) {
    int result = 0;
    s21_decimal src = {{INT_MIN, 0, 0, 0}};
    int status = s21_from_decimal_to_int(src, &result);
    ck_assert_int_eq(status, 1);
}

START_TEST(dec_to_int_4) {
    s21_decimal dec;
    int result = 0;
    int number = 0;
    dec.bits[0] = 2147483647;
    dec.bits[1] = 0;
    dec.bits[2] = 0;
    dec.bits[3] = 0;
    result = s21_from_decimal_to_int(dec, &number);
    ck_assert_int_eq(number, 2147483647);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(dec_to_int_5) {
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

START_TEST(dec_to_int_6) {
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

START_TEST(dec_to_int_7) {
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

START_TEST(dec_to_int_8) {
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

START_TEST(dec_to_int_9) {
    s21_decimal dec;
    int result = 0, number = 0;
    dec.bits[0] = 1714336475;
    dec.bits[1] = 602887423;
    dec.bits[2] = 48737584;
    dec.bits[3] = 2148401152;
    result = s21_from_decimal_to_int(dec, &number);
    ck_assert_int_eq(result, 1);
}
END_TEST


START_TEST(float_1) {
    s21_decimal dec;
    s21_from_float_to_decimal(-0.478965218, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -0.478965218, 1e-06);
}
END_TEST

START_TEST(float_2) {
    s21_decimal dec;
    s21_from_float_to_decimal(0.8541465951, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 0.8541465951, 1e-06);
}
END_TEST

START_TEST(float_3) {
    s21_decimal dec;
    s21_from_float_to_decimal(1.4896752254, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 1.4896752254, 1e-05);
}
END_TEST

START_TEST(float_4) {
    s21_decimal dec;
    s21_from_float_to_decimal(-1.89651472, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -1.89651472, 1e-05);
}
END_TEST

START_TEST(float_5) {
    s21_decimal dec;
    s21_from_float_to_decimal(-10.000584145, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -10.000584145, 1e-04);
}
END_TEST

START_TEST(float_6) {
    s21_decimal dec;
    s21_from_float_to_decimal(87.185547514, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 87.185547514, 1e-04);
}
END_TEST

START_TEST(float_7) {
    s21_decimal dec;
    s21_from_float_to_decimal(954.6547892, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 954.6547892, 1e-03);
}
END_TEST

START_TEST(float_8) {
    s21_decimal dec;
    s21_from_float_to_decimal(-547.6587123, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -547.6587123, 1e-03);
}
END_TEST

START_TEST(float_9) {
    s21_decimal dec;
    s21_from_float_to_decimal(-1547.6587123, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -1547.6587123, 1e-02);
}
END_TEST

START_TEST(float_10) {
    s21_decimal dec;
    s21_from_float_to_decimal(6874.98541, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 6874.98541, 1e-02);
}
END_TEST

START_TEST(float_11) {
    s21_decimal dec;
    s21_from_float_to_decimal(-86874.98541, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -86874.98541, 1e-01);
}
END_TEST

START_TEST(float_12) {
    s21_decimal dec;
    s21_from_float_to_decimal(-686874.98541, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -686874.98541, 1);
}
END_TEST

START_TEST(float_13) {
    s21_decimal dec;
    s21_from_float_to_decimal(-686874.98541, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, -686874.98541, 1);
}
END_TEST

START_TEST(float_14) {
    s21_decimal dec;
    s21_from_float_to_decimal(4.189654154e18, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 4.189654154e18, 1e+12);
}
END_TEST

START_TEST(float_15) {
    s21_decimal dec;
    int a = s21_from_float_to_decimal(4e30, &dec);
    ck_assert_int_eq(a, 1);
}
END_TEST


START_TEST(float_16) {
    s21_decimal dec;
    s21_from_float_to_decimal(5.6584159654e25, &dec);
    float tmp = 0;
    s21_from_decimal_to_float(dec, &tmp);
    ck_assert_float_eq_tol(tmp, 5.6584159654e25, 1e+19);
}
END_TEST

START_TEST(float_17) {
    s21_decimal dec;
    int a = s21_from_float_to_decimal(4e-30, &dec);
    ck_assert_int_eq(a, 1);
}
END_TEST


START_TEST(add_1) {
    s21_decimal value_1 = {{55555, 0, 0, 0}};
    s21_decimal value_2 = {{66666, 0, 0, 262144}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{555616666, 0, 0, 262144}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);

}
END_TEST

START_TEST(add_2) {
    s21_decimal value_1 = {{5555, 0, 0, 2147483648}};
    s21_decimal value_2 = {{333333333, 0, 0, 327680}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{222166667, 0, 0, 2147811328}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(add_3) {
    s21_decimal value_1 = {{UINT_MAX, 0, 0, 327680}};
    s21_decimal value_2 = {{UINT_MAX, 100, 0, 2148139008}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{4294867297, 99898, 0, 655360}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(add_4) {
    s21_decimal value_1 = {{UINT_MAX, 613566756, 0, 2147811328}};
    s21_decimal value_2 = {{UINT_MAX, 214748364, 0, 2147745792}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{4294967285, 2761050406, 0, 2147811328}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(add_5) {
    s21_decimal value_1 = {{346456, 53345, 0, 2147942400}};
    s21_decimal value_2 = {{567567, 3456567, 0, 262144}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{567220544, 3456513655, 0, 458752}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(add_6) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, 2147483647, 1638400}};
    s21_decimal value_2 = {{UINT_MAX, UINT_MAX, 0, 2148466688}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{4153960755, 858993458, 785251635, 2149056512}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(add_7) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 1638400}};
    s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 2148466688}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{2701727008, 2450292888, UINT_MAX, 2148466688}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(add_8) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX}};
    s21_decimal value_2 = {{54, 0, 0, 0}};
    s21_set_sign(&value_2);
    s21_set_scale(&value_2, 2);
    s21_decimal result = {{0}};
    s21_decimal expected = {{4294967294, UINT_MAX, UINT_MAX}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(add_9) {
    s21_decimal value_1 = {{4294967294, UINT_MAX, UINT_MAX, 0}};
    s21_decimal value_2 = {{15, 0, 0, 65536}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{0, 0, 0, 0}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(add_10) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 2147483648}};
    s21_decimal value_2 = {{1, 0, 0, 2147483648}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{0, 0, 0, 0}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(add_11) {
    s21_decimal value_1 = {{98564, 1247856, 98541, 2147483648}};
    s21_decimal value_2 = {{875, 651214965, 831764, 131072}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{9855525, 3768537931, 9022335, 2147614720}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(add_12) {
    s21_decimal value_1 = {{124, 0, 2014589674, 458752}};
    s21_decimal value_2 = {{875, 651214965, 831764, 131072}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{172673693, 1558211807, 851910048, 327680}};
    int status = s21_add(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_1) {
    s21_decimal value_1 = {{55555, 0, 0, 0}};
    s21_decimal value_2 = {{66666, 0, 0, 262144}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{555483334, 0, 0, 262144}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_2) {
    s21_decimal value_1 = {{UINT_MAX, 0, 0, 2147614720}};
    s21_decimal value_2 = {{23465246, 0, 0, 2147549184}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{4060314835, 0, 0, 2147614720}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_3) {
    s21_decimal value_1 = {{UINT_MAX, 0, 0, 0}};
    s21_decimal value_2 = {{UINT_MAX, 100, 0, 0}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{0, 100, 0, 2147483648}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_4) {
    s21_decimal value_1 = {{UINT_MAX, 4563654, 0, 2148139008}};
    s21_decimal value_2 = {{23465246, 364563, 0, 2148270080}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{4271501950, 456000936, 0, 2148270080}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_5) {
    s21_decimal value_1 = {{UINT_MAX, 345634, 0, 2147876864}};
    s21_decimal value_2 = {{23465246, 45634, 0, 327680}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{234652459, 801975, 0, 2147876864}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_6) {
    s21_decimal value_1 = {{UINT_MAX, 345634, 0, 393216}};
    s21_decimal value_2 = {{23465246, 45634, 0, 2147811328}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{234652459, 801975, 0, 393216}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_7) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, 2147483647, 1638400}};
    s21_decimal value_2 = {{UINT_MAX, UINT_MAX, 0, 983040}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{4153960755, 858993458, 785251635, 2149056512}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(sub_8) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal value_2 = {{4294967294, UINT_MAX, UINT_MAX, 0}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{1, 0, 0, 0}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(sub_9) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 1835008}};
    s21_decimal value_2 = {{4294967294, UINT_MAX, UINT_MAX, 0}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{4294967286, UINT_MAX, UINT_MAX, 2147483648}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(sub_10) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX}};
    s21_decimal value_2 = {{54, 0, 0, 0}};
    s21_set_scale(&value_2, 2);
    s21_decimal result = {{0}};
    s21_decimal expected = {{4294967294, UINT_MAX, UINT_MAX}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(sub_11) {
    s21_decimal value_1 = {{2294791350, 10215304, 0, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 2);
    s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_set_sign(&value_2);
    s21_decimal result = {{0}};
    s21_decimal expected = {{4100220690, 4294865142, 4294967295}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}

START_TEST(sub_12) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 2147483648}};
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_decimal result = {{0}};
    s21_decimal expected = {{0, 0, 0, 0}};
    int status = s21_sub(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(mul_1) {
    s21_decimal value_1 = {{644382323, 0, 0, 0}};
    s21_set_scale(&value_1, 4);
    s21_decimal value_2 = {{211, 0, 0, 0}};
    s21_set_scale(&value_2, 1);
    s21_decimal expected = {{2820683977, 31, 0, 0}};
    s21_set_scale(&expected, 5);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_2) {
    s21_decimal value_1 = {{1024, 0, 0, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 2);
    s21_decimal value_2 = {{1024, 0, 0, 0}};
    s21_set_sign(&value_2);
    s21_set_scale(&value_2, 2);
    s21_decimal expected = {{1048576, 0, 0, 0}};
    s21_set_scale(&expected, 4);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_3) {
    s21_decimal value_1 = {{1, 0, 0, 0}};
    s21_set_scale(&value_1, 28);
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_set_scale(&value_2, 28);
    s21_decimal expected = {{0, 0, 0, 0}};
    s21_set_scale(&expected, 28);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_4) {
    s21_decimal value_1 = {{1, 0, 0, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 14);
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_set_sign(&value_2);
    s21_set_scale(&value_2, 14);
    s21_decimal expected = {{1, 0, 0, 0}};
    s21_set_scale(&expected, 28);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_5) {
    s21_decimal value_1 = {{6, 0, 0, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 15);
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_set_sign(&value_2);
    s21_set_scale(&value_2, 14);
    s21_decimal expected = {{1, 0, 0, 0}};
    s21_set_scale(&expected, 28);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_6) {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{UINT_MAX, 0, 0, 0}};
    s21_set_sign(&value_2);
    s21_set_scale(&value_2, 2);
    s21_decimal expected = {{0, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_set_scale(&expected, 2);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_7) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, 0, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 6);
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_decimal expected = {{UINT_MAX, UINT_MAX, 0, 0}};
    s21_set_sign(&expected);
    s21_set_scale(&expected, 6);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_8) {
    s21_decimal value_1 = {{83730275, 15003338, 0, 0}};
    s21_set_scale(&value_1, 8);
    s21_decimal value_2 = {{100, 0, 0, 0}};
    s21_decimal expected = {{4078060204, 1500333801, 0, 0}};
    s21_set_scale(&expected, 8);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_9) {
    s21_decimal value_1 = {{4001320886, 4287581145, 40, 0}};
    s21_set_scale(&value_1, 16);
    s21_decimal value_2 = {{391535930, 1760863, 0, 0}};
    s21_set_scale(&value_2, 9);
    s21_decimal expected = {{3958225213, 2625355668, 3100638189, 0}};
    s21_set_scale(&expected, 17);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_10) {
    s21_decimal value_1 = {{2547709347, 428758114, 4, 0}};
    s21_set_scale(&value_1, 15);
    s21_decimal value_2 = {{391819107, 1760863, 0, 0}};
    s21_set_scale(&value_2, 9);
    s21_decimal expected = {{2941190343, 3124007977, 3100638189, 0}};
    s21_set_scale(&expected, 17);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_11) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 28);
    s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_set_scale(&value_2, 28);
    s21_decimal expected = {{158262358, 899300158, 3402823669, 0}};
    s21_set_sign(&expected);
    s21_set_scale(&expected, 27);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_12) {
    s21_decimal value_1 = {{1224992642, 3599754252, 150, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 11);
    s21_decimal value_2 = {{3459039107, 108296, 0, 0}};
    s21_set_scale(&value_2, 10);
    s21_decimal expected = {{4288873668, 3635651073, 701595274, 0}};
    s21_set_sign(&expected);
    s21_set_scale(&expected, 13);
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mul_13) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal value_2 = {{2, 0, 0, 0}};
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(mul_14) {
    s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_set_sign(&value_1);
    s21_decimal value_2 = {{2, 0, 0, 0}};
    s21_decimal result;
    int status = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(div_1) {
    s21_decimal value_1 = {{895412, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(status, 3);
}
END_TEST

START_TEST(div_2) {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{75, 0, 0, 0}};
    s21_decimal result;
    s21_decimal expected = {{0, 0, 0, 0}};
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_3) {
    s21_decimal value_1 = {{225, 0, 0, 0}};
    s21_set_scale(&value_1, 2);
    s21_decimal value_2 = {{15, 0, 0, 0}};
    s21_set_sign(&value_2);
    s21_set_scale(&value_2, 1);
    s21_decimal expected = {{15, 0, 0, 0}};
    s21_set_sign(&expected);
    s21_set_scale(&expected, 1);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_4) {
    s21_decimal value_1 =  {{2, 0, 0, 0}};
    s21_decimal value_2 = {{3, 0, 0, 0}};
    s21_decimal expected = {{178956971, 695075222, 361400724, 0}};
    s21_set_scale(&expected, 28);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_5) {
    s21_decimal value_1 =  {{1, 0, 0, 0}};
    s21_set_scale(&value_1, 28);
    s21_decimal value_2 = {{5, 0, 0, 0}};
    s21_decimal expected = {{0, 0, 0, 0}};
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_6) {
    s21_decimal value_1 =  {{20, 0, 0, 0}};
    s21_decimal value_2 = {{5, 0, 0, 0}};
    s21_set_scale(&value_2, 5);
    s21_decimal expected = {{400000, 0, 0, 0}};
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_7) {
    s21_decimal value_1 =  {{592211859, 1035921593, 0, 0}};
    s21_set_scale(&value_1, 6);
    s21_decimal value_2 = {{43764, 0, 0, 0}};
    s21_decimal expected = {{926677031, 1324446808, 551124877, 0}};
    s21_set_scale(&expected, 20);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_8) {
    s21_decimal value_1 =  {{279772309, 218, 0, 0}};
    s21_set_sign(&value_1);
    s21_decimal value_2 = {{2984756849, 242550, 0, 0}};
    s21_set_scale(&value_2, 16);
    s21_decimal expected = {{1714336475, 602887423, 48737584, 0}};
    s21_set_sign(&expected);
    s21_set_scale(&expected, 14);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_9) {
    s21_decimal value_1 =  {{2243774991, 741267166, 0, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 19);
    s21_decimal value_2 = {{2243774991, 741267166, 0, 0}};
    s21_set_sign(&value_2);
    s21_set_scale(&value_2, 19);
    s21_decimal expected = {{1, 0, 0, 0}};
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_10) {
    s21_decimal value_1 =  {{1392783818, 22080446, 0, 0}};
    s21_set_sign(&value_1);
    s21_set_scale(&value_1, 8);
    s21_decimal value_2 = {{2313682944, 2328306436, 0, 0}};
    s21_decimal expected = {{1392783818, 22080446, 0, 0}};
    s21_set_sign(&expected);
    s21_set_scale(&expected, 27);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_11) {
    s21_decimal value_1 =  {{2397809911, 86451412, 10, 0}};
    s21_set_sign(&value_1);
    s21_decimal value_2 = {{193289, 0, 0, 0}};
    s21_set_scale(&value_2, 14);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(div_12) {
    s21_decimal value_1 =  {{2833012231, 1194835434, 39, 0}};
    s21_decimal value_2 = {{193289, 0, 0, 0}};
    s21_set_scale(&value_2, 17);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(div_13) {
    s21_decimal value_1 =  {{3815433103, 2843293561, 408, 0}};
    s21_set_scale(&value_1, 14);
    s21_decimal value_2 = {{134934984, 0, 0, 0}};
    s21_set_scale(&value_2, 5);
    s21_decimal expected = {{2535589114, 2456994201, 302858453, 0}};
    s21_set_scale(&expected, 23);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_14) {
    s21_decimal value_1 =  {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_set_scale(&value_1, 28);
    s21_decimal value_2 = {{5, 0, 0, 0}};
    s21_set_scale(&value_2, 1);
    s21_decimal expected = {{858993459, 858993459, 858993459, 0}};
    s21_set_scale(&expected, 27);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(div_15) {
    s21_decimal value_1 =  {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_set_scale(&value_1, 1);
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_set_scale(&value_2, 2);
    s21_decimal result;
    int status = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(status, 1);
}
END_TEST


START_TEST(mod_1) {
    s21_decimal value_1 = {{55555, 0, 0, 0}};
    s21_decimal value_2 = {{66666, 0, 0, 262144}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{22222, 0, 0, 262144}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mod_2) {
    s21_decimal value_1 = {{5555, 345635, 0, 327680}};
    s21_decimal value_2 = {{333333333, 56765, 0, 458752}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{3492319244, 50332, 0, 458752}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mod_3) {
    s21_decimal value_1 = {{5555, 345635, 3456, 786432}};
    s21_decimal value_2 = {{333333333, 56765, 4567, 1114112}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{565121299, 203145210, 1416, 1114112}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mod_4) {
    s21_decimal value_1 = {{5555, 345635, 0, 327680}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{0, 0, 0, 0}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 3);
}
END_TEST

START_TEST(mod_5) {
    s21_decimal value_1 = {{0, 0, 0, 786432}};
    s21_decimal value_2 = {{2452, 45646, 4564, 1114112}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{0, 0, 0, 0}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mod_6) {
    s21_decimal value_1 = {{1224992642, 95213044, 96, 2148204544}};
    s21_decimal value_2 = {{835928189, 108296, 0, 655360}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{1549492382, 670995, 0, 2148204544}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST


START_TEST(mod_7) {
    s21_decimal value_1 = {{1224992642, 95213044, 96, 2148204544}};
    s21_decimal value_2 = {{835928189, 108296, 0, 655360}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{1549492382, 670995, 0, 2148204544}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mod_8) {
    s21_decimal value_1 = {{1528, 0, 0, 0}};
    s21_decimal value_2 = {{835928189, 108296, 87456, 655360}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{2801328128, 3557, 0, 655360}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mod_9) {
    s21_decimal value_1 = {{1528, 98754, 0, 327680}};
    s21_decimal value_2 = {{2598741, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{604379640, 7, 0, 327680}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(mod_10) {
    s21_decimal value_1 = {{1528, 98754, 98745621, 720896}};
    s21_decimal value_2 = {{2598741, 87456321, 0, 786432}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal expected = {{4044925088, 36789656, 0, 786432}};
    int status = s21_mod(value_1, value_2, &result);
    for(int i = 0; i < 4; i++) {
        ck_assert_uint_eq(result.bits[i], expected.bits[i]);
    }
    ck_assert_int_eq(status, 0);
}
END_TEST

START_TEST(scale_equalize_extra) {
    s21_decimal_extra value_1_extra = {{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, \
        UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    s21_decimal_extra value_2_extra = {{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, \
        UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, 262144}};
    int status = s21_scale_equalize_extra(&value_1_extra, &value_2_extra, 0, 4);
    ck_assert_int_eq(status, 99);
}
END_TEST

START_TEST(div_ten_extra) {
    s21_decimal_extra value_1_extra = {{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, \
        UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, 0}};
    int status = s21_div_ten_extra(&value_1_extra, 4);
    ck_assert_int_eq(status, 0);
}
END_TEST


void common_tests() {
    Suite *s1 = suite_create("Decimal");

    TCase *compare_fn = tcase_create("Comparative");
    suite_add_tcase(s1, compare_fn);
    tcase_add_test(compare_fn, compare_01);
    tcase_add_test(compare_fn, compare_02);
    tcase_add_test(compare_fn, compare_03);
    tcase_add_test(compare_fn, compare_04);
    tcase_add_test(compare_fn, compare_05);
    tcase_add_test(compare_fn, compare_06);
    tcase_add_test(compare_fn, compare_07);
    tcase_add_test(compare_fn, compare_08);
    tcase_add_test(compare_fn, compare_09);
    tcase_add_test(compare_fn, compare_10);
    tcase_add_test(compare_fn, compare_11);
    tcase_add_test(compare_fn, compare_12);
    tcase_add_test(compare_fn, compare_13);
    tcase_add_test(compare_fn, compare_14);
    tcase_add_test(compare_fn, compare_15);
    tcase_add_test(compare_fn, compare_16);

    TCase *floor_fn = tcase_create("Other_floor");
    suite_add_tcase(s1, floor_fn);
    tcase_add_test(floor_fn, floor_test_zero);
    tcase_add_test(floor_fn, floor_test_1);
    tcase_add_test(floor_fn, floor_test_2);
    tcase_add_test(floor_fn, floor_test_3);
    tcase_add_test(floor_fn, floor_test_4);
    tcase_add_test(floor_fn, floor_test_5);
    tcase_add_test(floor_fn, floor_test_6);
    tcase_add_test(floor_fn, floor_test_7);
    tcase_add_test(floor_fn, floor_test_8);
    tcase_add_test(floor_fn, floor_test_9);
    tcase_add_test(floor_fn, floor_test_10);
    tcase_add_test(floor_fn, floor_test_11);
    tcase_add_test(floor_fn, floor_test_12);

    TCase *round_fn = tcase_create("Other_round");
    suite_add_tcase(s1, round_fn);
    tcase_add_test(round_fn, round_zero);
    tcase_add_test(round_fn, round_1);
    tcase_add_test(round_fn, round_2);
    tcase_add_test(round_fn, round_3);
    tcase_add_test(round_fn, round_4);
    tcase_add_test(round_fn, round_5);
    tcase_add_test(round_fn, round_6);
    tcase_add_test(round_fn, round_7);
    tcase_add_test(round_fn, round_8);
    tcase_add_test(round_fn, round_9);
    tcase_add_test(round_fn, round_10);
    tcase_add_test(round_fn, round_11);
    tcase_add_test(round_fn, round_12);

    TCase *truncate_fn = tcase_create("Other_truncate");
    suite_add_tcase(s1, truncate_fn);
    tcase_add_test(truncate_fn, truncate_zero);
    tcase_add_test(truncate_fn, truncate_1);
    tcase_add_test(truncate_fn, truncate_2);
    tcase_add_test(truncate_fn, truncate_3);
    tcase_add_test(truncate_fn, truncate_4);
    tcase_add_test(truncate_fn, truncate_5);
    tcase_add_test(truncate_fn, truncate_6);
    tcase_add_test(truncate_fn, truncate_7);
    tcase_add_test(truncate_fn, truncate_8);
    tcase_add_test(truncate_fn, truncate_9);
    tcase_add_test(truncate_fn, truncate_10);
    tcase_add_test(truncate_fn, truncate_11);
    tcase_add_test(truncate_fn, truncate_12);
    tcase_add_test(truncate_fn, truncate_13);

    TCase *negate_fn = tcase_create("Other_negate");
    suite_add_tcase(s1, negate_fn);
    tcase_add_test(negate_fn, negate_1);
    tcase_add_test(negate_fn, negate_2);
    tcase_add_test(negate_fn, negate_3);
    tcase_add_test(negate_fn, negate_4);
    tcase_add_test(negate_fn, negate_5);
    tcase_add_test(negate_fn, negate_6);

    TCase *int_to_dec_fn = tcase_create("Convertational_int_to_dec");
    suite_add_tcase(s1, int_to_dec_fn);
    tcase_add_test(int_to_dec_fn, int_to_dec_1);
    tcase_add_test(int_to_dec_fn, int_to_dec_2);
    tcase_add_test(int_to_dec_fn, int_to_dec_3);
    tcase_add_test(int_to_dec_fn, int_to_dec_4);
    tcase_add_test(int_to_dec_fn, int_to_dec_5);

    TCase *dec_to_int_fn = tcase_create("Convertational_dec_to_int");
    suite_add_tcase(s1, dec_to_int_fn);
    tcase_add_test(dec_to_int_fn, dec_to_int_1);
    tcase_add_test(dec_to_int_fn, dec_to_int_2);
    tcase_add_test(dec_to_int_fn, dec_to_int_3);
    tcase_add_test(dec_to_int_fn, dec_to_int_4);
    tcase_add_test(dec_to_int_fn, dec_to_int_5);
    tcase_add_test(dec_to_int_fn, dec_to_int_6);
    tcase_add_test(dec_to_int_fn, dec_to_int_7);
    tcase_add_test(dec_to_int_fn, dec_to_int_8);
    tcase_add_test(dec_to_int_fn, dec_to_int_9);

    TCase *dec_float_fn = tcase_create("Convertational_dec_float");
    suite_add_tcase(s1, dec_float_fn);
    tcase_add_test(dec_float_fn, float_1);
    tcase_add_test(dec_float_fn, float_2);
    tcase_add_test(dec_float_fn, float_3);
    tcase_add_test(dec_float_fn, float_4);
    tcase_add_test(dec_float_fn, float_5);
    tcase_add_test(dec_float_fn, float_6);
    tcase_add_test(dec_float_fn, float_7);
    tcase_add_test(dec_float_fn, float_8);
    tcase_add_test(dec_float_fn, float_9);
    tcase_add_test(dec_float_fn, float_10);
    tcase_add_test(dec_float_fn, float_11);
    tcase_add_test(dec_float_fn, float_12);
    tcase_add_test(dec_float_fn, float_13);
    tcase_add_test(dec_float_fn, float_14);
    tcase_add_test(dec_float_fn, float_15);
    tcase_add_test(dec_float_fn, float_16);
    tcase_add_test(dec_float_fn, float_17);
    tcase_add_test(dec_float_fn, scale_equalize_extra);
    tcase_add_test(dec_float_fn, div_ten_extra);

    TCase *add_fn = tcase_create("Arithmetic_add");
    suite_add_tcase(s1, add_fn);
    tcase_add_test(add_fn, add_1);
    tcase_add_test(add_fn, add_2);
    tcase_add_test(add_fn, add_3);
    tcase_add_test(add_fn, add_4);
    tcase_add_test(add_fn, add_5);
    tcase_add_test(add_fn, add_6);
    tcase_add_test(add_fn, add_7);
    tcase_add_test(add_fn, add_8);
    tcase_add_test(add_fn, add_9);
    tcase_add_test(add_fn, add_10);
    tcase_add_test(add_fn, add_11);
    tcase_add_test(add_fn, add_12);

    TCase *sub_fn = tcase_create("Arithmetic_sub");
    suite_add_tcase(s1, sub_fn);
    tcase_add_test(sub_fn, sub_1);
    tcase_add_test(sub_fn, sub_2);
    tcase_add_test(sub_fn, sub_3);
    tcase_add_test(sub_fn, sub_4);
    tcase_add_test(sub_fn, sub_5);
    tcase_add_test(sub_fn, sub_6);
    tcase_add_test(sub_fn, sub_7);
    tcase_add_test(sub_fn, sub_8);
    tcase_add_test(sub_fn, sub_9);
    tcase_add_test(sub_fn, sub_10);
    tcase_add_test(sub_fn, sub_11);
    tcase_add_test(sub_fn, sub_12);

    TCase *mul_fn = tcase_create("Arithmetic_mul");
    suite_add_tcase(s1, mul_fn);
    tcase_add_test(mul_fn, mul_1);
    tcase_add_test(mul_fn, mul_2);
    tcase_add_test(mul_fn, mul_3);
    tcase_add_test(mul_fn, mul_4);
    tcase_add_test(mul_fn, mul_5);
    tcase_add_test(mul_fn, mul_6);
    tcase_add_test(mul_fn, mul_7);
    tcase_add_test(mul_fn, mul_8);
    tcase_add_test(mul_fn, mul_9);
    tcase_add_test(mul_fn, mul_10);
    tcase_add_test(mul_fn, mul_11);
    tcase_add_test(mul_fn, mul_12);
    tcase_add_test(mul_fn, mul_13);
    tcase_add_test(mul_fn, mul_14);

    TCase *div_fn = tcase_create("Arithmetic_div");
    suite_add_tcase(s1, div_fn);
    tcase_add_test(div_fn, div_1);
    tcase_add_test(div_fn, div_2);
    tcase_add_test(div_fn, div_3);
    tcase_add_test(div_fn, div_4);
    tcase_add_test(div_fn, div_5);
    tcase_add_test(div_fn, div_6);
    tcase_add_test(div_fn, div_7);
    tcase_add_test(div_fn, div_8);
    tcase_add_test(div_fn, div_9);
    tcase_add_test(div_fn, div_10);
    tcase_add_test(div_fn, div_11);
    tcase_add_test(div_fn, div_12);
    tcase_add_test(div_fn, div_13);
    tcase_add_test(div_fn, div_14);
    tcase_add_test(div_fn, div_15);

    TCase *mod_fn = tcase_create("Arithmetic_mod");
    suite_add_tcase(s1, mod_fn);
    tcase_add_test(mod_fn, mod_1);
    tcase_add_test(mod_fn, mod_2);
    tcase_add_test(mod_fn, mod_3);
    tcase_add_test(mod_fn, mod_4);
    tcase_add_test(mod_fn, mod_5);
    tcase_add_test(mod_fn, mod_6);
    tcase_add_test(mod_fn, mod_7);
    tcase_add_test(mod_fn, mod_8);
    tcase_add_test(mod_fn, mod_9);
    tcase_add_test(mod_fn, mod_10);

    SRunner *sr = srunner_create(s1);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
}
