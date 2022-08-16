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
    s21_create_matrix(5, 5, &val1);
    s21_create_matrix(5, 5, &val2);


    s21_randomize_matrix(&val1, 99);
    s21_randomize_matrix(&val2, 99);

/*                                    ACTION                                    */
    ex_code = s21_sum_matrix(&val1, &val2, &res);

/*                                    PRINT                                     */
    s21_print_matrix(val1);
    printf("\n");
    s21_print_matrix(val2);
    printf("\n");
    s21_print_matrix(res);

/*                                    CLEAN                                     */
    s21_remove_matrix(&val1);
    s21_remove_matrix(&val2);
    s21_remove_matrix(&res);

    return ex_code;
}


