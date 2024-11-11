
#include "get_next_line.h"

int     len_of_str(char *str)
{
    int     len;

    len = 0;
    while (*str++)
        len++;
    return (len);
}

char    *copy_str(char *leftover)
{
    char    *res;
    int     idx;

    idx = 0;
    res = (char *)malloc(len_of_str(leftover) + 2);
    if (!res)
        return (NULL);
    while (leftover[idx] != '\0' && leftover[idx] != '\n')
    {
        res[idx] = leftover[idx];
        idx++;
    }
    if (leftover[idx] == '\n')
    {
        res[idx] = '\n';
        idx++;
    }
    res[idx] = '\0';
    return (res);
} 

char	*search_new_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

char	*merge_str(char *leftover, char *buffer)
{
	char	*assemble;
	int	index;

    if (!leftover)
	{
		leftover = malloc(1);
		leftover[0] = '\0';
	}
	if (!leftover || !buffer)
		return (NULL);
	assemble = (char *)malloc((len_of_str(leftover) + len_of_str(buffer)) + 1);
    if (!assemble)
		return (NULL);
	index = -1;
	while (++index < (len_of_str(leftover) + len_of_str(buffer)))
	{
		if (index < len_of_str(leftover))
			assemble[index] = leftover[index];
		else
			assemble[index] = buffer[index - len_of_str(leftover)];
	}
	assemble[index] = '\0';
    free(leftover);
	return (assemble);
}