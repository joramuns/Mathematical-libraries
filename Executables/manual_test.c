//
//  manual_test.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int main() {
    int ex_code = OK;

    matrix_t val1;
    s21_create_matrix(9, 9, &val1);
    ex_code = s21_print_matrix(val1);
    if (ex_code == OK) s21_remove_matrix(&val1);

    return ex_code;
}
