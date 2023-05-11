#ifndef SRC_S21_DECIMAL_TYPES_H_
#define SRC_S21_DECIMAL_TYPES_H_
//
//  s21_decimal_types.h
//  Decimal
//
//  Created by Joramun Sasin on 7/14/22.
//
#define EXTRASIZE 10
#define EXTRALASTBIT 319
#define DECIMSIZE 4
#define LASTBIT 95
#define INITDEC {{0, 0, 0, 0}}
#define INITDECONE {{1, 0, 0, 0}}
#define INITDECEXTRA {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}
#define INITDECONEEXTRA {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}}

typedef struct {
    unsigned int bits[DECIMSIZE];
} s21_decimal;

typedef struct {
    unsigned int bits[EXTRASIZE];
} s21_decimal_extra;

#endif  // SRC_S21_DECIMAL_TYPES_H_
