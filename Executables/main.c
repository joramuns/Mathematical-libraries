//
//  main.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    int ex_code = 0;
    s21_decimal res, val1, val2;
    s21_dec_zero(&res);
    val1.LOWBIT = UINT_MAX;
    val1.MEDBIT = UINT_MAX;
    val1.HIGHBIT = 2147483647;
    val1.bits[3] = 1638400;
//    s21_set_scale(&val1, 0);

    val2.LOWBIT = UINT_MAX;
    val2.MEDBIT = UINT_MAX;
    val2.HIGHBIT = 0;
    val2.bits[3] = 2148466688;
//    s21_set_scale(&val2, 15);

//    s21_set_sign(&val1);
//    s21_set_sign(&val2);
//    s21_zero_bit(&val2, 127);

    s21_print_decimal(val1);
    printf("+\n");
    s21_print_decimal(val2);

    ex_code = s21_add(val1, val2, &res);

    printf("=\n");
    s21_print_decimal(res);

    return ex_code;
}
//Value 1:
//Bit[0]: 11111111111111111111111111111111 -1
//Bit[1]: 11111111111111111111111111111111 -1
//Bit[2]: 1111111111111111111111111111111 2147483647
//Bit[3]: 110010000000000000000 1638400
//Decimal: 3961.4081257132168796771975167
//+
//Value 2:
//Bit[0]: 11111111111111111111111111111111 -1
//Bit[1]: 11111111111111111111111111111111 -1
//Bit[2]: 0 0
//Bit[3]: 10000000000011110000000000000000 2148466688
//Decimal: -18446.744073709551615
//=
//Bit[0]: 11110111100110000110100100110011 4153960755
//Bit[1]: 110011001100110011001100110010 858993458
//Bit[2]: 101110110011011111110100110011 785251635
//Bit[3]: 10000000000110000000000000000000 2149056512
//Decimal: -14485.335947996334735322802483
//=!=
//Bit[0]: 1010000100001001000101010010000 1350863504
//Bit[1]: 11001001000001100100000001001100 -922337204
//Bit[2]: 0 0
//Bit[3]: 10000000000011100000000000000000 2148401152
//Decimal: -144853.35947996334736
