//
//  s21_eq_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int     s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int ex_code = SUCCESS;

    if (s21_compare_matrix_sizes(*A, *B) == OK) {
        EVERY_ROW
            EVERY_COLUMN
                double diff = A->matrix[i_row][i_column] - B->matrix[i_row][i_column];
                if (fabs(diff) > TOLERANCE) ex_code = FAILURE;
            }
        }
    } else {
        ex_code = FAILURE;
    }

    return ex_code;
}
