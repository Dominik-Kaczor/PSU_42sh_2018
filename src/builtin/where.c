/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** Where command
*/

#include "mysh.h"

void get_multiple_path(char **path, char *binary)
{
    struct stat s;
    char *filepath = NULL;
    char *final_filepath = NULL;
    int my_stat = 0;

    if (path == NULL)
        return;
    for (int i = 0; path[i]; i++) {
        filepath = my_strcat(path[i], "/");
        final_filepath = my_strcat(filepath, binary);
        my_stat = stat(final_filepath, &s);
        if (my_stat != -1)
            my_printf("%s\n", final_filepath);
    }
}

int where_fun(general_t *general, function_t *tmp)
{
    if (my_strcompare((char *) "where", tmp->str[0])) {
        if (tmp->str[1] == NULL) {
            my_printf("where: Too few arguments\n");
            return (1);
        }
        for (int i = 1; tmp->str[i] != NULL; i++)
            get_multiple_path(general->path, tmp->str[i]);
        return (1);
    }
    return (0);
}