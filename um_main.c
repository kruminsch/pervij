#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <arpa/inet.h>

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

int convert(u_int32_t num)
{
    u_int32_t b0;
    u_int32_t b1;
    u_int32_t b2;
    u_int32_t b3;
    u_int32_t res;

    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;
    res = b0 | b1 | b2 | b3;
    printf("%u\n", res);
    my_put_base(res, "0123456789abcdef");
    write(1, "\n", 1);
    return (0);
    

}
//print numbers big endian
int boot(char *buf, size_t size)
{
    //256 is size/4;
    u_int32_t a[256];
    u_int32_t b[256];    

    for (int i = 0; i < 256; ++i) {
        memcpy(&a[i], buf, 4);
        buf += 4;
    }
    for (int i = 0; i < 256; ++i) {
        printf("%u\n", htonl(a[i]));
    }    
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