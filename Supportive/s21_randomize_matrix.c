//
//  s21_randomize_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"
#include <time.h>

void s21_randomize_matrix (matrix_t *A, int range) {
    srand((unsigned)time(0));
    for (int i_row = 0; i_row < A->rows; i_row++) {
        for (int i_column = 0; i_column < A->columns; i_column++) {
            A->matrix[i_row][i_column] = rand() % range;
        }
    }
}
