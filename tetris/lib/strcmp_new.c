/*
** EPITECH PROJECT, 2020
** Str_compar
** File description:
** For minishell
*/

#include "../include/my.h"
#include "../include/mysh.h"
#include <stdio.h>

int strcmp_mysh(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] == s2[i])
            i = i + 1;
        else
            return (0);
    }
    if ((s1[i] == '\n' || s1[i] == '\0')  && s2[i] == '\0')
        return (1);
    else
        return (0);
}

int strcmp_n(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i])
    {
        if (s1[i] == s2[i])
            ++i;
        else
            return (0);
    }
    if (s1[i] == '\0' && s2[i] == '=')
        return (1);
    else
        return (0);
}

char **make_path(env_t *env_list)
{
    char **path;
    env_t *tmp;

    tmp = env_list;
    while ((strcmp_mysh(tmp->name, "PATH")) == 0 && tmp != NULL) {
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return (NULL);
    path = my_path_2(tmp->var_it);
    return (path);
}
