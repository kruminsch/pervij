/*
** EPITECH PROJECT, 2019
** CPool_Day09_2019
** File description:
** My_MY-H
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <getopt.h>

struct opt {
	int level;
	int left;
	int right;
	int turn;
	int drop;
	int quit;
	int pause;
	int x;
	int y;
	int hide_next;
	int debug;
};
typedef struct opt opt_t;
int disp(opt_t options);

#endif /* !MY_H */
