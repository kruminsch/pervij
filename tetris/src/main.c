/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "../include/my.h"
#include "time.h"

/*
 * ALLOWED FUNCTIONS:
 * malloc
free
write
(f)write
(f)read
(f)close
(f)open
exit
getline
ioctl
usleep
sigaction
signal
stat
lstat
fstat
opendir
readdir
closedir
getpwuid
getgrgid
time
ctime
readlink
perror
strerror
getcwd
chdir
fork
execve
access
isatty
wait
waitpid
wait3
wait4
kill
getpid
strsignal
strerror
lseek
sigemptyset
setcontext
getcontext
nanosleep
pause
lseek
sigemptyset
setcontext
getcontext
nanosleep
pause
rand
srand
getopt
getopt-long
clock*/

//checKing for fatal errors like cannot open dir or no passing files found
//or malloc...???
void fatal_errors(int ac, char **av)
{
	(void)(ac);
	(void)(av);
	write(1, "i am reading options\n", 21);

}

void debug(int ac, char **av)
{

	fatal_errors(ac, av);
	//ONLY if u r in debug mode:
	write(1, "Press any key to start Tetris", 29);

}

void fill_opt_default(opt_t *options)
{
	options->level = 1;
	options->debug = 0;
	options->hide_next = 0;
	options->x = 10;
	options->y = 20;
	options->left = 4;
	options->right = 5;
	options->drop = 2;
	options->turn = 3;
	options->pause = ' ';
	options->quit = 'q';


}

//we have to use getopt and getopt_long functions
void fill_options(opt_t *options, int ac, char **av)
{
    (void)(ac);
    (void)(av);    
    options->level = 2;
    options->quit = 97;


}

int main(int ac, char **av)
{
    char *input = malloc(sizeof(char));
    opt_t options;
    fill_opt_default(&options);
    fill_options(&options, ac, av);
    debug(ac, av);
    //ONLY ifu r in debug mode:
    read(0, input, 1);
    initscr();
    start_color();
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    disp(options);
    endwin();
    free(input);
    return (0);
}
