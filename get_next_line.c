/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:43:00 by atursun           #+#    #+#             */
/*   Updated: 2024/11/09 15:53:35 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int	totla_len;
	int	i;
	int	i;

	totla_len = len_of_lst(lst);
	merge = malloc(totla_len + 1);
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
	int	bytes;

	if (!(buff = malloc(BUFFER_SIZE +1)));
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
	static t_lst	*lst = NULL;
	char		*one_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(one_line = read_one_line(fd, &lst)));
		return (NULL);
	lst_free(&lst);
	return (one_line);
}
