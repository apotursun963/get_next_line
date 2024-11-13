/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:15:56 by atursun           #+#    #+#             */
/*   Updated: 2024/11/12 20:02:45 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*pull_left(char *leftover)
{
	int	idx;
	int	jdx;
	char	*res;

	idx = 0;
	while (leftover[idx] != '\0' && leftover[idx] != '\n')
		idx++;
	if (!leftover[idx])
		return (free(leftover), NULL);
	if (!(res = (char *)malloc(len_of_str(&leftover[idx]) + 1)))
		return (NULL);
	idx++;
	jdx = 0;
	while (leftover[idx])
		res[jdx++] = leftover[idx++];
	res[jdx] = '\0';
	free(leftover);
	return (res);
}

char	*pull_line(char *leftover)
{
	int	idx;
	char	*res;

	idx = 0;
	if (!leftover[idx])
		return (NULL);
	while (leftover[idx] != '\0' && leftover[idx] != '\n')
		idx++;
	if (!(res = (char *)malloc(idx + 2)))
		return (NULL);
	idx = 0;
	while (leftover[idx] != '\0' && leftover[idx] != '\n')
	{
		res[idx] = leftover[idx];
		idx++;
	}
	if (leftover[idx] == '\n')
		res[idx++] = '\n';
	res[idx] = '\0';
	return (res);
}

char	*read_file(int fd, char *leftover)
{
	char	*buffer;
	int	bytes;

	if (!(buffer = malloc(BUFFER_SIZE +1)))
		return (NULL);
	bytes = 1;
	while (!search_new_line(leftover) && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		leftover = merge_str(leftover, buffer);
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*one_line;
	static char	*leftover[1000];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(leftover[fd]), leftover[fd] = NULL, NULL);
	if (!(leftover[fd] = read_file(fd, leftover[fd])));
		return (NULL);
	one_line = pull_line(leftover[fd]);
	leftover[fd] = pull_left(leftover[fd]);
	return (one_line);
}
