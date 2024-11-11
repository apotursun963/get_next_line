
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"


int main()
{
    int fd = open("oku.txt", O_RDONLY);

    printf("%s", get_next_line(fd));
}
