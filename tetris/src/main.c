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

void fatal_errors(int ac, char **av)
{
	(void)(ac);
	(void)(av);
	write(1, "i am reading options\n", 21);

}

void debug(int ac, char **av)
{

	fatal_errors(ac, av);
	write(1, "Press any key to start Tetris", 29);

}

int disp(char *str)
{
    int a = -12;
    //char key;
    time_t start = time(NULL);
    time_t timenow;    
    //while (key != 4) {
    while (1) {
	    refresh();
	    timenow = mytime - timstartL);
	    printw(ctime(&mytime));
	mvprintw(10,10,"%s\n", str);   
	    
        curs_set(0);
        noecho();
        //getmaxyx(stdscr, 20, 20);
        refresh();
         mvprintw(10,10,"%s\n", str);
	 //key = getch();

    }
    return (a);
}


int main(int ac, char **av)
{
	char *input = malloc(sizeof(char));
	char *check_string = "this is my check string\n";
	debug(ac, av);
	read(0, input, 1);
	initscr();
	start_color();
	init_pair(2, COLOR_CYAN, COLOR_BLUE);
	keypad(stdscr, TRUE);
	disp(check_string);
        endwin();
    (void)(ac);
    (void)(av);    
    return (84);
}
