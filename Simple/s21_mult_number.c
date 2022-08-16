//
//  s21_mult_number.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int     s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int ex_code = OK;

    ex_code = s21_create_matrix(A->rows, A->columns, result);
    if (ex_code == OK) {
        EVERY_ROW
            EVERY_COLUMN
                result->matrix[i_row][i_column] = A->matrix[i_row][i_column] * number;
            }
        }
    }

    return ex_code;
}
