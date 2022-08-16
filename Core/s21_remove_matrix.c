//
//  s21_remove_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

void    s21_remove_matrix(matrix_t *A) {
    if (A->matrix) {
        for (int i_row = 0; i_row < A->rows; i_row++) {
            free(A->matrix[i_row]);
        }
        free(A->matrix);
    }
}
