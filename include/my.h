/*
** EPITECH PROJECT, 2020
** Solo stumper
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *src);
int my_putstr(char const *str);
void my_putchar(char c);
int make_word(char *word, char const *src, int pos, int w_len);

struct um_array{
	struct um_array *prev;
	u_int32_t num;
	u_int32_t *plates;
	u_int32_t len;
	struct um_array *next;
};
typedef struct um_array um_t;



#endif /* !MY_H */
