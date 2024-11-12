/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:50:41 by atursun           #+#    #+#             */
/*   Updated: 2024/11/12 20:05:24 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len_of_str(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*search_new_line(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*merge_str(char *leftover, char *buffer)
{
	int		index;
	int		jndex;
	char	*assemble;

	if (!leftover)
	{
		leftover = malloc(1);
		leftover[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	assemble = malloc(len_of_str(leftover) + len_of_str(buffer) + 1);
	if (!assemble)
		return (NULL);
	index = -1;
	jndex = 0;
	while (leftover[++index])
		assemble[index] = leftover[index];
	while (buffer[jndex])
		assemble[index++] = buffer[jndex++];
	assemble[len_of_str(leftover) + len_of_str(buffer)] = '\0';
	free(leftover);
	return (assemble);
}
