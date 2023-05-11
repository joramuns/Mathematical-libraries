//
//  s21_calc_complements.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int     s21_complements_go(matrix_t *A, matrix_t *result) {
    int ex_code = OK;
    int sign = -1;

    EVERY_ROW
        EVERY_COLUMN
            matrix_t temp_matrix = {0};
            s21_create_matrix(A->rows - 1, A->columns - 1, &temp_matrix);
            s21_determinant_cofactor(A, &temp_matrix, i_row, i_column, A->rows);
            double det = 0.0;
            s21_determinant(&temp_matrix, &det);
            result->matrix[i_row][i_column] = powf(sign, (i_row + i_column)) * det;
//            sign = -sign;
            s21_remove_matrix(&temp_matrix);
        }
    }

    return ex_code;
}

int     s21_calc_complements(matrix_t *A, matrix_t *result) {
    int ex_code = s21_check_matrix(*A);

    if (ex_code == OK) {
        if (A->rows == A->columns) {
            ex_code = s21_create_matrix(A->rows, A->columns, result);
            if (ex_code == OK) {
                if (A->rows == 1) {
                    result->matrix[0][0] = 1;
                } else {
                    ex_code = s21_complements_go(A, result);
                }
            }
        } else {
            ex_code = C_ERROR;
        }
    }

    return ex_code;
}
