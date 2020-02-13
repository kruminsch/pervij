#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int my_strlen(char const *str)
{
    int n = 0;

    while (*(str + n))
        ++n;
    return (n);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}


int my_put_base(unsigned int nb, char *base)
{
    int deep = my_strlen(base);
    int modulo;

    if (nb <= deep && nb >= 0 )
        my_putchar(base[nb]);
    if (nb > deep) {
        modulo = nb % deep;
        my_put_base(nb / deep, base);
        my_putchar(base[modulo]);
    }
    return (0);
}

int boot(char *buf, size_t size)
{
    unsigned int a;
    memcpy(&a, buf, 4);
    printf("%d\n", a);
    my_put_base(a, "01");
    write(1, "\n", 1);
    my_put_base(a, "0123456789abcdef");
    write(1, "\n", 1);
    
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
