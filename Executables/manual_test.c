//
//  manual_test.c
//  s21_matrix
//
//  Created by Joramun Sasin on 8/16/22.
//

#include "../s21_matrix.h"

int main() {
    int ex_code = OK;

/*                                   CREATE                                     */
    matrix_t val1, val2, res;
    s21_create_matrix(3, 2, &val1);
    s21_create_matrix(2, 3, &val2);
    s21_create_matrix(3, 3, &res);
    res.matrix[0][0] = 1;
    res.matrix[0][1] = 2;
    res.matrix[0][2] = 3;
    res.matrix[1][0] = 4;
    res.matrix[1][1] = 5;
    res.matrix[1][2] = 6;
    res.matrix[2][0] = 7;
    res.matrix[2][1] = 8;
    res.matrix[2][2] = 3;


    s21_randomize_matrix(&val1, 9);
    s21_randomize_matrix(&val2, 9);

/*                                    ACTION                                    */
    ex_code = s21_mult_matrix(&val1, &val2, &res);

/*                                    PRINT                                     */
    s21_print_matrix(val1);
    printf("\n");
    s21_print_matrix(val2);
    printf("\n");
    s21_print_matrix(res);

    double det = 1;
    s21_determinant(&res, &det);
    printf("Determinant: %.2f\n", det);
/*                                    CLEAN                                     */
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
    s21_remove_matrix(&res);

    return ex_code;
}


