/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** display
*/

#include "../include/my.h"
#include "time.h"

char *make_line(char *clock)
{
	int i = 0;
	int j = 14;
	char *line = malloc(sizeof(char) * 6);

        for(;i < 5; ++i, ++j) {
		line[i] = clock[j];
	}
	line[5] = '\0';
	return (line);
}

//put these 2 fts together, please (make_line and timer)
char *timer(time_t start)
{
    time_t timenow = time(NULL) - start;
    char *clock;
    clock = ctime(&timenow);
    return (make_line(clock));
        

}

int disp(opt_t options)
{
    int a = -12;
    (void)(options);
    char key;
    time_t start = time(NULL);
    char *clock;
    do {
	clock = timer(start);
        mvprintw(8, 10, "%s\n", clock);
        curs_set(0);
        noecho();
        //getmaxyx(stdscr, 20, 20);
        refresh();
        mvprintw(10,10,"THIS IS MY GAME\n");
    } while ((key = getch() != options.quit));
    free(clock);
    return (a);
}

