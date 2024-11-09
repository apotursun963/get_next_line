/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:02:14 by atursun           #+#    #+#             */
/*   Updated: 2024/11/09 15:36:28 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_lst	*create_node(char *content)
{
	t_lst	*new_unit;

	new_unit = malloc(sizeof(t_lst));
	if (!new_unit)
		return (NULL);
	new_unit->buff = str_dup(content);
	new_unit->next = NULL;
	return (new_unit);
}

char	*merge_nodes(t_lst **lst)
{
	t_lst	*current_unit;
	char	*merge;
	int		totla_len;
	int		i;
	int		j;

	totla_len = len_of_lst(lst);
	merge = malloc(totla_len +1);
	if (!merge)
		return (NULL);
	i = 0;
	current_unit = *lst;
	while (current_unit)
	{
		j = 0;
		while (current_unit->buff[j] != '\0')
			merge[i++] = current_unit->buff[j++];
		current_unit = current_unit->next;
	}
	merge[i] = '\0';
	return (merge);
}

char	*read_one_line(int fd, t_lst **lst)
{
	char	*buff;
	t_lst	*unit;
	int		bytes;

	buff = malloc(BUFFER_SIZE +1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff, 1);
		if (bytes <= 0 && !*lst)
			return (free(buff), NULL);
		buff[bytes] = '\0';
		unit = create_node(buff);
		append_lst(lst, unit);
		if (search_new_line(buff))
			break ;
	}
	free(buff);
	return (merge_nodes(lst));
}

char	*get_next_line(int fd)
{
	static t_lst	*lst[1000];
	char			*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	one_line = read_one_line(fd, &lst[fd]);
	if (!one_line)
		return (NULL);
	lst_free(&lst[fd]);
	return (one_line);
}
