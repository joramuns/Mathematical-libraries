//
//  check_main.c
//  Decimal
//

#include "check_main.h"

int main() {
    Suite *div = suite_create("DIV");
    TCase *t_1_3 = tcase_create("1/3");
    suite_add_tcase(div, t_1_3);
    div_1_3(t_1_3);
    TCase *t_10_3 = tcase_create("10/3");
    suite_add_tcase(div, t_10_3);
    div_10_3(t_10_3);
    TCase *t_1_30 = tcase_create("1/30");
    suite_add_tcase(div, t_1_30);
    div_1_30(t_1_30);
    TCase *t_4_3 = tcase_create("4/3");
    suite_add_tcase(div, t_4_3);
    div_4_3(t_4_3);
    TCase *t_11_3 = tcase_create("11/3");
    suite_add_tcase(div, t_11_3);
    div_11_3(t_11_3);
    SRunner *sr = srunner_create(div);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);

    common_tests();

    return 0;
}

