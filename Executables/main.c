//
//  main.c
//  Decimal
//

#include <stdio.h>
#include "../s21_decimal.h"
#include <limits.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    s21_decimal test;
    test.LOWBIT = 17;
    test.MEDBIT = 128;
    test.HIGHBIT = UINT_MAX;
    s21_print_decimal(test);
    printf("uintmax = %u\n", (UINT_MAX));
    return 0;
}
