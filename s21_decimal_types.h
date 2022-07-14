//
//  s21_decimal_types.h
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//

#ifndef s21_decimal_types_h
#define s21_decimal_types_h

typedef struct {
    unsigned int bits[4];
} s21_decimal;

typedef struct {
    unsigned int bits[6];
} s21_decimal_extra;

#endif /* s21_decimal_types_h */
