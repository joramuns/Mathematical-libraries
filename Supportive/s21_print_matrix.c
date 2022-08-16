//
//  s21_print_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int    s21_print_matrix(matrix_t matrix) {
    int ex_code = OK;

    if (matrix.matrix) {
        for (int i_row = 0; i_row < matrix.rows; i_row++) {
            for (int i_column = 0; i_column < matrix.columns; i_column++) {
                printf("[%.0f]", matrix.matrix[i_row][i_column]);
            }
            printf("\n");
        }
    } else {
        ex_code = M_ERROR;
    }

    return ex_code;
}
