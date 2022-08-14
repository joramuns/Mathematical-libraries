#ifndef SRC_EXECUTABLES_CHECK_MAIN_H_
#define SRC_EXECUTABLES_CHECK_MAIN_H_
//
//  Header.h
//  Decimal
//
//  Created by Joramun Sasin on 8/12/22.
//

#include "../s21_decimal.h"
#include <check.h>

#define ASSERT_DECIMAL_EQ for (size_t i = 0; i < 4; i++) { \
                              ck_assert_msg(result.bits[i] == expected.bits[i], \
                                            "[%zu] %u != %u", i, result.bits[i], expected.bits[i]); \
                          }

void div_1_3(TCase *tc);
void div_10_3(TCase *tc);
void div_1_30(TCase *tc);
void div_4_3(TCase *tc);
void div_11_3(TCase *tc);
void common_tests();

#endif  // SRC_EXECUTABLES_CHECK_MAIN_H_
