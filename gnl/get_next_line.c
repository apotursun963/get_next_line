
#include "get_next_line.h"
#include <stdio.h>

char    *pull_left(char *leftover)
{
    int     idx;
    int     jdx;
    char    *res;

    while (leftover[idx] != '\0' && leftover[idx] != '\n')
        idx++;
    if (leftover[idx] == '\0')
        return (free(leftover), NULL);
    res = (char *)malloc(len_of_str(&leftover[idx]) +1);
    if (!res)
        return (NULL);
    idx++;
    jdx = 0;
    while (leftover[idx])
        res[jdx++] = leftover[idx++];
    res[jdx] = '\0';
    free(leftover);
    return (res);
}

char    *pull_line(char *leftover)
{
    int     idx;
    char    *res;

    idx = 0;
    if (leftover[idx] == '\0')
        return (NULL);
    res = copy_str(leftover);
    return (res);
}

char    *read_file(int fd, char *leftover)
{
    char    *buffer;
    int     bytes;

    buffer = (char *)malloc(BUFFER_SIZE +1);
    if (!buffer)
        return (NULL);
    bytes = 1;
    while (!search_new_line(leftover) && bytes != 0)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        printf("apo%s", buffer);
        if (bytes <= 0)
            return (free(buffer), NULL);
        buffer[bytes] = '\0';
        leftover = merge_str(leftover, buffer);
    }
    if (!leftover)
        return (NULL);
    free(buffer);
    return (leftover);
}

char	*get_next_line(int fd)
{
    char           *one_line;
    static char    *leftover;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    leftover = read_file(fd, leftover);
    one_line = pull_line(leftover);
    leftover = pull_left(leftover);
    return (one_line);
}

