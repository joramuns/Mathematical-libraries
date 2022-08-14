//
//  main.c
//  Decimal
//

#include "../s21_decimal.h"

int main(int argc, const char * argv[]) {
    int ex_code = 0;
    s21_decimal res, val1, val2;
    s21_dec_zero(&res);

    val1.LOWBIT = 0x10ACFC95;
    val1.MEDBIT = 0xDA;
    val1.HIGHBIT = 0;
    val1.bits[3] = 262144;
//    s21_set_scale(&val1, 25);

    val2.LOWBIT = 0xB1E7C671;
    val2.MEDBIT = 0x3B376;
    val2.HIGHBIT = 0;
    val2.bits[3] = 2147483648;
//    s21_set_scale(&val2, 16);

//    s21_set_sign(&val1);
//    s21_set_sign(&val2);
//    s21_zero_bit(&val2, 127);

    s21_print_decimal(val1);
    printf("+\n");
    s21_print_decimal(val2);

    ex_code = s21_div(val1, val2, &res);
//    s21_truncate(val1, &res);
    printf("=\n");
    s21_print_decimal(res);
    printf("Scale res: %d\n", s21_get_scale(val1));
    printf("Scale res: %d\n", s21_get_scale(val2));

    return ex_code;
}
