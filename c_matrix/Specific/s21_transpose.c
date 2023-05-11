//
//  s21_transpose.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int     s21_transpose(matrix_t *A, matrix_t *result) {
    int ex_code = s21_create_matrix(A->columns, A->rows, result);

    if (ex_code == OK) {
        EVERY_ROW
            EVERY_COLUMN
                result->matrix[i_column][i_row] = A->matrix[i_row][i_column];
            }
        }
    }

    return ex_code;
}
