//
//  check_inverse_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/17/22.
//

#include "check_matrix.h"

START_TEST(inverse_1) {
    matrix_t val1 = {0}, result = {0}, expected = {0};
    int size = 3;
    s21_create_matrix(size, size, &val1);
    s21_create_matrix(size, size, &expected);

    val1.matrix[0][0] = 3;
    val1.matrix[0][1] = 27;
    val1.matrix[0][2] = 18;
    val1.matrix[1][0] = 0;
    val1.matrix[1][1] = 18;
    val1.matrix[1][2] = 15;
    val1.matrix[2][0] = 24;
    val1.matrix[2][1] = 9;
    val1.matrix[2][2] = 9;

    expected.matrix[0][0] = 0.01333333333;
    expected.matrix[0][1] = -0.04;
    expected.matrix[0][2] = 0.04;
    expected.matrix[1][0] = 0.1777777778;
    expected.matrix[1][1] = -0.2;
    expected.matrix[1][2] = -0.02222222222;
    expected.matrix[2][0] = -0.2133333333;
    expected.matrix[2][1] = 0.3066666667;
    expected.matrix[2][2] = 0.02666666667;

    ck_assert_int_eq(s21_inverse_matrix(&val1, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

//    s21_create_matrix(size, size, &A);
//    ONE_MATRIX;
//    s21_mult_matrix(&result, &val1, &one_checker);
//    ck_assert_int_eq(s21_eq_matrix(&A, &one_checker), SUCCESS);

//    s21_remove_matrix(&A);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
//    s21_remove_matrix(&one_checker);
}
END_TEST

START_TEST(inverse_2) {
    matrix_t val1 = {0}, result = {0}, expected = {0}, A = {0}, one_checker = {0};
    int size = 3;
    s21_create_matrix(size, size, &val1);
    s21_create_matrix(size, size, &expected);

    val1.matrix[0][0] = 4;
    val1.matrix[0][1] = 6;
    val1.matrix[0][2] = 8;
    val1.matrix[1][0] = 9;
    val1.matrix[1][1] = 2;
    val1.matrix[1][2] = 7;
    val1.matrix[2][0] = 9;
    val1.matrix[2][1] = 1;
    val1.matrix[2][2] = 0;

    expected.matrix[0][0] = -0.02517985612;
    expected.matrix[0][1] = 0.02877697842;
    expected.matrix[0][2] = 0.09352517986;
    expected.matrix[1][0] = 0.226618705;
    expected.matrix[1][1] = -0.2589928058;
    expected.matrix[1][2] = 0.1582733813;
    expected.matrix[2][0] = -0.03237410072;
    expected.matrix[2][1] = 0.1798561151;
    expected.matrix[2][2] = -0.1654676259;

    ck_assert_int_eq(s21_inverse_matrix(&val1, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    s21_create_matrix(size, size, &A);
    ONE_MATRIX;
    s21_mult_matrix(&result, &val1, &one_checker);
    ck_assert_int_eq(s21_eq_matrix(&A, &one_checker), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&one_checker);
}
END_TEST
/*
START_TEST(inverse_3) {
    matrix_t val1 = {0}, result = {0}, expected = {0};
    int size = 8;
    s21_create_matrix(size, size, &val1);
    s21_create_matrix(size, size, &expected);

    val1.matrix[0][0] = 2;
    val1.matrix[0][1] = 8;
    val1.matrix[0][2] = 7;
    val1.matrix[0][3] = 4;
    val1.matrix[0][4] = 1;
    val1.matrix[0][5] = 8;
    val1.matrix[0][6] = 3;
    val1.matrix[0][7] = 9;

    val1.matrix[1][0] = 4;
    val1.matrix[1][1] = 2;
    val1.matrix[1][2] = 6;
    val1.matrix[1][3] = 2;
    val1.matrix[1][4] = 2;
    val1.matrix[1][5] = 1;
    val1.matrix[1][6] = 5;
    val1.matrix[1][7] = 8;

    val1.matrix[2][0] = 8;
    val1.matrix[2][1] = 6;
    val1.matrix[2][2] = 7;
    val1.matrix[2][3] = 7;
    val1.matrix[2][4] = 3;
    val1.matrix[2][5] = 4;
    val1.matrix[2][6] = 4;
    val1.matrix[2][7] = 1;

    val1.matrix[3][0] = 1;
    val1.matrix[3][1] = 7;
    val1.matrix[3][2] = 0;
    val1.matrix[3][3] = 4;
    val1.matrix[3][4] = 4;
    val1.matrix[3][5] = 3;
    val1.matrix[3][6] = 0;
    val1.matrix[3][7] = 5;

    val1.matrix[4][0] = 5;
    val1.matrix[4][1] = 7;
    val1.matrix[4][2] = 5;
    val1.matrix[4][3] = 6;
    val1.matrix[4][4] = 8;
    val1.matrix[4][5] = 3;
    val1.matrix[4][6] = 1;
    val1.matrix[4][7] = 9;

    val1.matrix[5][0] = 3;
    val1.matrix[5][1] = 7;
    val1.matrix[5][2] = 8;
    val1.matrix[5][3] = 0;
    val1.matrix[5][4] = 5;
    val1.matrix[5][5] = 7;
    val1.matrix[5][6] = 0;
    val1.matrix[5][7] = 2;

    val1.matrix[6][0] = 5;
    val1.matrix[6][1] = 8;
    val1.matrix[6][2] = 3;
    val1.matrix[6][3] = 5;
    val1.matrix[6][4] = 9;
    val1.matrix[6][5] = 1;
    val1.matrix[6][6] = 2;
    val1.matrix[6][7] = 0;

    val1.matrix[7][0] = 7;
    val1.matrix[7][1] = 8;
    val1.matrix[7][2] = 7;
    val1.matrix[7][3] = 4;
    val1.matrix[7][4] = 7;
    val1.matrix[7][5] = 9;
    val1.matrix[7][6] = 1;
    val1.matrix[7][7] = 5;

    expected.matrix[0][0] = -0.5349902183;
    expected.matrix[0][1] = 0.2894503762;
    expected.matrix[0][2] = 0.2648128502;
    expected.matrix[0][3] = 0.6295578936;
    expected.matrix[0][4] = -0.1684575429;
    expected.matrix[0][5] = 0.2471263249;
    expected.matrix[0][6] = -0.3773947292;
    expected.matrix[0][7] = 0.0217143747;

    expected.matrix[1][0] = -0.3358379646;
    expected.matrix[1][1] = 0.2037511071;
    expected.matrix[1][2] = 0.2032547229;
    expected.matrix[1][3] = 0.6234293334;
    expected.matrix[1][4] = -0.1799149334;
    expected.matrix[1][5] = 0.3295114996;
    expected.matrix[1][6] = -0.2254070837;
    expected.matrix[1][7] = -0.1935314328;

    expected.matrix[2][0] = 0.09452225456;
    expected.matrix[2][1] = -0.09221066155;
    expected.matrix[2][2] = 0.03813722914;
    expected.matrix[2][3] = -0.2190871073;
    expected.matrix[2][4] = 0.1695573745;
    expected.matrix[2][5] = 0.1092580516;
    expected.matrix[2][6] = 0.007715043036;
    expected.matrix[2][7] = -0.1600498331;

    expected.matrix[3][0] = 0.3630563639;
    expected.matrix[3][1] = -0.3052665388;
    expected.matrix[3][2] = -0.04656927155;
    expected.matrix[3][3] = -0.4771776828;
    expected.matrix[3][4] = 0.2389343637;
    expected.matrix[3][5] = -0.2685487089;
    expected.matrix[3][6] = 0.1928760759;
    expected.matrix[3][7] = -0.001245826966;

    expected.matrix[4][0] = 0.2619837848;
    expected.matrix[4][1] = -0.133556544;
    expected.matrix[4][2] = -0.2495968906;
    expected.matrix[4][3] = -0.4562289726;
    expected.matrix[4][4] = 0.1044612934;
    expected.matrix[4][5] = -0.2245895097;
    expected.matrix[4][6] = 0.3128420752;
    expected.matrix[4][7] = 0.1500734843;

    expected.matrix[5][0] = 0.2992174649;
    expected.matrix[5][1] = -0.1560300945;
    expected.matrix[5][2] = -0.1850280149;
    expected.matrix[5][3] = -0.3646314915;
    expected.matrix[5][4] = -0.02339656554;
    expected.matrix[5][5] = -0.2701059926;
    expected.matrix[5][6] = 0.1915783395;
    expected.matrix[5][7] = 0.2628500238;

    expected.matrix[6][0] = 0.3028673486;
    expected.matrix[6][1] = 0.0418714657;
    expected.matrix[6][2] = -0.2001336669;
    expected.matrix[6][3] = -0.3106910771;
    expected.matrix[6][4] = -0.1692459178;
    expected.matrix[6][5] = -0.2826713255;
    expected.matrix[6][6] = 0.3477738954;
    expected.matrix[6][7] = 0.1562734201;

    expected.matrix[7][0] = -0.1023914038;
    expected.matrix[7][1] = 0.1015348978;
    expected.matrix[7][2] = 0.0104305565;
    expected.matrix[7][3] = 0.1667915738;
    expected.matrix[7][4] = 0.02489382894;
    expected.matrix[7][5] = 0.04583280613;
    expected.matrix[7][6] = -0.1284726616;
    expected.matrix[7][7] = -0.01017100922;

    ck_assert_int_eq(s21_inverse_matrix(&val1, &result), OK);
//    s21_inverse_matrix(&val1, &result);
//    s21_print_matrix(expected);
//    s21_print_matrix(result);
    ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);


    s21_remove_matrix(&val1);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
}
END_TEST
*/
START_TEST(inverse_4) {
    matrix_t val1 = {0}, result = {0}, expected = {0}, A = {0}, one_checker = {0};
    int size = 3;
    s21_create_matrix(size, size, &val1);
    s21_create_matrix(size, size, &expected);

    val1.matrix[0][0] = 4;
    val1.matrix[0][1] = 7;
    val1.matrix[0][2] = 3;
    val1.matrix[1][0] = 8;
    val1.matrix[1][1] = 8;
    val1.matrix[1][2] = 3;
    val1.matrix[2][0] = 9;
    val1.matrix[2][1] = 4;
    val1.matrix[2][2] = 7;

    expected.matrix[0][0] = -0.2993197279;
    expected.matrix[0][1] = 0.2517006803;
    expected.matrix[0][2] = 0.02040816327;
    expected.matrix[1][0] = 0.1972789116;
    expected.matrix[1][1] = -0.006802721088;
    expected.matrix[1][2] = -0.08163265306;
    expected.matrix[2][0] = 0.2721088435;
    expected.matrix[2][1] = -0.3197278912;
    expected.matrix[2][2] = 0.1632653061;

    ck_assert_int_eq(s21_inverse_matrix(&val1, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);

    s21_create_matrix(size, size, &A);
    ONE_MATRIX;
    s21_mult_matrix(&result, &val1, &one_checker);
    ck_assert_int_eq(s21_eq_matrix(&A, &one_checker), SUCCESS);

    s21_remove_matrix(&A);
    s21_remove_matrix(&val1);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
    s21_remove_matrix(&one_checker);
}
END_TEST

START_TEST(inverse_5) {
    matrix_t val1 = {0}, result = {0}, expected = {0};
    int size = 7;
    s21_create_matrix(size, size, &val1);
    s21_create_matrix(size, size, &expected);

    val1.matrix[0][0] = 2;
    val1.matrix[0][1] = 8;
    val1.matrix[0][2] = 7;
    val1.matrix[0][3] = 4;
    val1.matrix[0][4] = 1;
    val1.matrix[0][5] = 8;
    val1.matrix[0][6] = 3;

    val1.matrix[1][0] = 4;
    val1.matrix[1][1] = 2;
    val1.matrix[1][2] = 6;
    val1.matrix[1][3] = 2;
    val1.matrix[1][4] = 2;
    val1.matrix[1][5] = 1;
    val1.matrix[1][6] = 5;

    val1.matrix[2][0] = 8;
    val1.matrix[2][1] = 6;
    val1.matrix[2][2] = 7;
    val1.matrix[2][3] = 7;
    val1.matrix[2][4] = 3;
    val1.matrix[2][5] = 4;
    val1.matrix[2][6] = 4;

    val1.matrix[3][0] = 1;
    val1.matrix[3][1] = 7;
    val1.matrix[3][2] = 0;
    val1.matrix[3][3] = 4;
    val1.matrix[3][4] = 4;
    val1.matrix[3][5] = 3;
    val1.matrix[3][6] = 0;

    val1.matrix[4][0] = 5;
    val1.matrix[4][1] = 7;
    val1.matrix[4][2] = 5;
    val1.matrix[4][3] = 6;
    val1.matrix[4][4] = 8;
    val1.matrix[4][5] = 3;
    val1.matrix[4][6] = 1;

    val1.matrix[5][0] = 3;
    val1.matrix[5][1] = 7;
    val1.matrix[5][2] = 8;
    val1.matrix[5][3] = 0;
    val1.matrix[5][4] = 5;
    val1.matrix[5][5] = 7;
    val1.matrix[5][6] = 0;

    val1.matrix[6][0] = 5;
    val1.matrix[6][1] = 8;
    val1.matrix[6][2] = 3;
    val1.matrix[6][3] = 5;
    val1.matrix[6][4] = 9;
    val1.matrix[6][5] = 1;
    val1.matrix[6][6] = 2;

    expected.matrix[0][0] = -0.7535885167;
    expected.matrix[0][1] = 0.5062200957;
    expected.matrix[0][2] = 0.2870813397;
    expected.matrix[0][3] = 0.985645933;
    expected.matrix[0][4] = -0.1153110048;
    expected.matrix[0][5] = 0.3449760766;
    expected.matrix[0][6] = -0.6516746411;

    expected.matrix[1][0] = 1.612440191;
    expected.matrix[1][1] = -1.728229665;
    expected.matrix[1][2] = 0.004784688995;
    expected.matrix[1][3] = -2.550239234;
    expected.matrix[1][4] = -0.6535885167;
    expected.matrix[1][5] = -0.5425837321;
    expected.matrix[1][6] = 2.219138756;

    expected.matrix[2][0] = 1.705741627;
    expected.matrix[2][1] = -1.689952153;
    expected.matrix[2][2] = -0.1259968102;
    expected.matrix[2][3] = -2.843700159;
    expected.matrix[2][4] = -0.222169059;
    expected.matrix[2][5] = -0.6119617225;
    expected.matrix[2][6] = 2.029346093;

    expected.matrix[3][0] = 0.3755980861;
    expected.matrix[3][1] = -0.3177033493;
    expected.matrix[3][2] = -0.04784688995;
    expected.matrix[3][3] = -0.4976076555;
    expected.matrix[3][4] = 0.2358851675;
    expected.matrix[3][5] = -0.2741626794;
    expected.matrix[3][6] = 0.2086124402;

    expected.matrix[4][0] = -1.248803828;
    expected.matrix[4][1] = 1.364593301;
    expected.matrix[4][2] = -0.0956937799;
    expected.matrix[4][3] = 2.004784689;
    expected.matrix[4][4] = 0.4717703349;
    expected.matrix[4][5] = 0.4516746411;
    expected.matrix[4][6] = -1.58277512;

    expected.matrix[5][0] = -2.346889952;
    expected.matrix[5][1] = 2.467942584;
    expected.matrix[5][2] = 0.08452950558;
    expected.matrix[5][3] = 3.945773525;
    expected.matrix[5][4] = 0.6199362041;
    expected.matrix[5][5] = 0.914354067;
    expected.matrix[5][6] = -3.128548644;

    expected.matrix[6][0] = -1.270334928;
    expected.matrix[6][1] = 1.601913876;
    expected.matrix[6][2] = -0.03987240829;
    expected.matrix[6][3] = 2.25199362;
    expected.matrix[6][4] = 0.2132376396;
    expected.matrix[6][5] = 0.4215311005;
    expected.matrix[6][6] = -1.6261563;

    ck_assert_int_eq(s21_inverse_matrix(&val1, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&expected, &result), SUCCESS);


    s21_remove_matrix(&val1);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
}
END_TEST

Suite *inverse_matrix_suite(void) {
    Suite *s = suite_create("Inverse matrix");
    TCase *tc = tcase_create("Core");

    tcase_add_test(tc, inverse_1);
    tcase_add_test(tc, inverse_2);
//    tcase_add_test(tc, inverse_3);
    tcase_add_test(tc, inverse_4);
    tcase_add_test(tc, inverse_5);

    suite_add_tcase(s, tc);

    return s;
}
