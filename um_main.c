#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int boot(char *buf, size_t size)
{
    write(1, buf, size);
    return (0);

}

int main(int ac, char **av)
{
    char *buf;
    struct stat st;
    size_t size;
    int fd;
    
    stat("./um.um", &st);
    size = st.st_size;
    buf = malloc(sizeof(char) * size + 1);
    fd = open("./um.um", O_RDONLY);
    read(fd, buf, size);
    close(fd);
    boot(buf, size);
    return (0);
}
