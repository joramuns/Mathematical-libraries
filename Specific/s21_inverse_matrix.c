//
//  s21_inverse_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int     s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int ex_code = OK;
    double det = 0.0;

    if (A->matrix) {
        ex_code = s21_determinant(A, &det);
    } else {
        ex_code = M_ERROR;
    }
    if (det != 0 && ex_code == OK) {
        matrix_t calc_complement = {0};
        ex_code = s21_calc_complements(A, &calc_complement);
        if (ex_code == OK) {
            ex_code = s21_transpose(&calc_complement, result);
            s21_remove_matrix(&calc_complement);
            if (ex_code == OK) {
                EVERY_ROW
                    EVERY_COLUMN
                        result->matrix[i_row][i_column] /= det;
                    }
                }
            }
        }
    } else if (ex_code == OK) {
        ex_code = C_ERROR;
    }

    return ex_code;
}
