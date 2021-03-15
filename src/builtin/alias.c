/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Alias command
*/

#include "mysh.h"

int alias_fun(function_t *tmp)
{
    if (my_strcompare((char *) ALIAS, tmp->str[0])) {
        if (tmp->str[1] == NULL && tmp->str[2] == NULL) {
            my_printf((char *) MISSING_ARGUMENTS);
            return (1);
        }
    }
    return (0);
}
