//
//  main.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"
#include <limits.h>
#include <math.h>

long double DecimalToFloat(s21_decimal src);
char* IntToBinary(unsigned int n);


int main(int argc, const char * argv[]) {
    //
    s21_decimal res, val1, val2;
    s21_dec_zero(&res);
    //
    s21_set_scale(&val1, 0);
    val1.LOWBIT = 0;
    val1.MEDBIT = 0;
    val1.HIGHBIT = 0;
//    val1.bits[3] = 0;
//    s21_set_sign(&val1);
    
    float a = 9.2345678910;
    
//    s21_set_scale(&val2, 1);
//    val2.LOWBIT = 4;
//    val2.MEDBIT = 8;
//    val2.HIGHBIT = 0;
//    val2.bits[3] = 0;
//    s21_set_sign(&val2);
//    s21_print_dec_long(res);
//    printf("..\n");
//    s21_print_decimal(val1);
//    printf("*\n");
//    s21_print_decimal(val2);
    
    
//    printf("%Lf\n", DecimalToFloat(val1));
    
// 123 -> mul ten by 27 is overflow, 1 -> mul ten by 29 is overflow
//    int ex_code = s21_scale_equalize(&val1, &val2);
    int ex_code = s21_from_float_to_decimal(a, &val1);
    
    printf("=\n");
    s21_print_decimal(val1);
    printf("%d\n", s21_get_scale(val1));

//    printf("=\n");
//    s21_print_decimal(val2);
//    printf("%d\n", s21_get_scale(val2));
    
    printf("%Lf\n", DecimalToFloat(val1));
    
    return ex_code;
}



long double DecimalToFloat(s21_decimal src) {
    
    char *binary0 = IntToBinary(src.bits[0]);
    char *binary1 = IntToBinary(src.bits[1]);
    char *binary2 = IntToBinary(src.bits[2]);
    
    
    long double sumdec = 0;
    for (int i = 96, k = 0; i > 64; i--, k++) {
        sumdec += (binary2[k]-48) * pow(2, i-1);
    }
    for (int i = 64, k = 0; i > 32; i--, k++) {
        sumdec += (binary1[k]-48) * pow(2, i-1);
    }
    for (int i = 32, k = 0; i > 0; i--, k++) {
        sumdec += (binary0[k] - 48) * pow(2, i-1);
    }
    return sumdec;
}

char* IntToBinary(unsigned int n) {
    
    char* binary = (char*)malloc(sizeof(char) * (32 + 1));
    int k = 0;
    for (unsigned i = (1 << (32 - 1)); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}
