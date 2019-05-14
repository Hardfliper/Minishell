/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_strspecialcpy, test_cat_function, .init = redirect_all_std)
{
    char *ls = "ls";
    char *path = "PATH=/usr/local/sbin:/usr/local/bin:" \
        "/usr/sbin:/usr/bin:/home/Mwaaaa/my_scripts";
    int start = 0;

    my_printf("%s", strcpy_after(ls, path, &start));
    cr_assert_stdout_eq_str("/usr/local/sbin/ls");
}

Test(empty_arg, verify_cd, .init = redirect_all_std)
{
    my_put_nbr(check_empty_cd("cd          "));
    cr_assert_stdout_eq_str("0");
}

Test(arg_here, verify_cd, .init = redirect_all_std)
{
    my_put_nbr(check_empty_cd("cd delivery"));
    cr_assert_stdout_eq_str("1");
}

Test(go_to_root, test_cd_empty, .init = redirect_all_std)
{
    char *home = getenv("HOME");

    go_to_home(get);
    system("pwd");
    cr_assert_stdout_eq_str(home);
}
