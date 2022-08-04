//
//  main.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"
#include <limits.h>

unsigned int bdiv(unsigned int dividend, unsigned int divisor);
int badd(int x,int y);
int bsub(int x, int y);


int main(int argc, const char * argv[]) {
    int ex_code = 0;
    unsigned int a = 4, b = 2, c = 0;
    s21_decimal res, val1, val2;
    s21_dec_zero(&res);

    val1.LOWBIT = a;
    val1.MEDBIT = 0;
    val1.HIGHBIT = 0;
    val1.bits[3] = 0;
    s21_set_scale(&val1, 0);
//    s21_set_sign(&val1);
//
    val2.LOWBIT = b;
    val2.MEDBIT = 0;
    val2.HIGHBIT = 0;
    val2.bits[3] = 0;
//    s21_set_scale(&val2, 0);
//    s21_set_sign(&val2);
//    s21_print_dec_long(res);
//    printf("..\n");
    s21_print_decimal(val1);
    printf("/\n");
    s21_print_decimal(val2);
// 123 -> mul ten by 27 is overflow, 1 -> mul ten by 29 is overflow
    ex_code = s21_div(val1, val2, &res);
//    int ex_code = s21_div_ten(&val1, 99999);
    printf("=\n");
//    s21_print_dec_long(res);
    s21_print_decimal(res);
//    s21_print_decimal(val1);

    c = bdiv(a, b);
    printf("C = %u\n", c);

    return ex_code;
}

unsigned int bdiv(unsigned int dividend, unsigned int divisor) {
    unsigned int quotient = 0, remainder = 0;

    if (divisor == 0) { printf("div by zero\n"); return 0; }

    for(int i = 31 ; i >= 0 ; i--) {
        quotient <<= 1;
        remainder <<= 1;
        remainder |= (dividend & (1 << i)) >> i;

        if (remainder >= divisor) {
            remainder = bsub(remainder, divisor);
            quotient |= 1;
        }
    }

    return quotient;
}

int badd(int x,int y) {
    int i;
    char sum;
    char car_in=0;
    char car_out;
    char a,b;
    unsigned int mask=0x00000001;
    int result=0;

    for(i=0;i<32;i++){
        a=(x&mask)!=0;
        b=(y&mask)!=0;
        car_out=car_in & (a|b) |a&b;
        sum=a^b^car_in;
        if(sum) {
            result|=mask;
        }
        if(i!=31) {
            car_in=car_out;
        } else {
            if(car_in!=car_out) {
                printf("Overflow occurred\n");
            }
        }
        mask<<=1;
    }

    return result;
}

// subracts two integers by finding the compliemnt
// of "y", adding 1, and using the badd() function
// to add "-y" and "x"
int bsub(int x, int y) {
    return badd(x, badd(~y, 1));
}
