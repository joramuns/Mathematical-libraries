//
//  s21_create_matrix.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int s21_matrix_allocation(matrix_t *result) {
    int ex_code = OK;
    for (int i_row = 0; i_row < result->rows && ex_code == OK; i_row++) {
        result->matrix[i_row] = calloc(result->columns, sizeof(double));
        if (result->matrix[i_row]) {
            for (int i_columns = 0; i_columns < result->columns; i_columns++) {
                result->matrix[i_row][i_columns] = 0;
            }
        } else {
            ex_code = M_ERROR;
        }
    }
    return ex_code;
}

int     s21_create_matrix(int rows, int columns, matrix_t *result) {
    int ex_code = OK;

    if (rows > 0 && columns > 0) {
        result->rows = rows;
        result->columns = columns;
        result->matrix = calloc(rows, sizeof(double*));
        if (result->matrix) {
            ex_code = s21_matrix_allocation(result);
        } else {
            ex_code = M_ERROR;
        }
    } else {
        ex_code = M_ERROR;
    }

    return ex_code;
}
