/*
** EPITECH PROJECT, 2019
** test_of_minishell1.c
** File description:
** tests for minishell1
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "mysh.h"

int main_test(int ac, char **av, char **env);
extern char **environ;

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
    cr_redirect_stdin();
}

Test(test_shell2, basic_exit, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/exit", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "exit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, cd_false, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/cd", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "cd Makefile\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, cd_hard, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/cd_hard", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "cd");
    fprintf(cr_get_redirected_stdin(), "%s", "\nls\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, ls, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/ls", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "ls\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, exec_directory, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/exec", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "./src\n/usr/bin\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, env, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/env", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "env\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, exit_test, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/exit_test", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "exit 3\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, set_env, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/set_env", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "setenv 3\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, unset_env, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/unsetenv", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "unsetenv toto\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, echo, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/echo", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "echo \"toto\"\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, pipe, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/pipe", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "ls | wc\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, history, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/history", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "ls\nhistory\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, loong_pipe, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/loong_pipe", "r");

    fprintf(cr_get_redirected_stdin(), "%s",
            "ls | ls | ls | ls | ls | ls | ls | ls | ls | ls | ls \nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, severals_commands, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/seperator", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "cd tests ; ls\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, cd_back, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/cd_back", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "cd -\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, setenv_null, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/env_bad", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "setenv\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, setenv_to_much, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/env_bad", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "setenv test test\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, unsetenv_null, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/env_bad", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "unsetenv\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, unsetenv_to_much, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/env_bad", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "unsetenv test test\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, help, .init = redirect_all_std)
{
    int ac = 2;
    char *av[3] = {"./mysh", "-h", NULL};
    FILE *solved = fopen("tests/sol/help", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "exit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}

Test(tests_shell2, test, .init = redirect_all_std)
{
    int ac = 1;
    char *av[3] = {"./mysh", NULL};
    FILE *solved = fopen("tests/sol/test", "r");

    fprintf(cr_get_redirected_stdin(), "%s", "ls\n!ls\nexit\n");
    main_test(ac, av, environ);
    cr_assert_stdout_eq(solved);
    fclose(solved);
}
