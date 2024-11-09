/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:43:36 by atursun           #+#    #+#             */
/*   Updated: 2024/11/09 17:09:54 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	lst_free(t_lst **lst)
{
	t_lst	*current_unit;
	t_lst	*next_unit;

	current_unit = *lst;
	while (current_unit)
	{
		next_unit = current_unit->next;
		free(current_unit->buff);
		free(current_unit);
		current_unit = next_unit;
	}
	*lst = NULL;
}

int	len_of_node(char *node)
{
	int	len;

	len = 0;
	while (*node++)
		len++;
	return (len);
}

int	len_of_lst(t_lst **lst)
{
	int		len;
	t_lst	*current_unit;

	len = 0;
	current_unit = *lst;
	while (current_unit)
	{
		len += len_of_node(current_unit->buff);
		current_unit = current_unit->next;
	}
	return (len);
}

char	*str_dup(char *src)
{
	char	*str;
	int		size;
	int		index;

	size = len_of_node(src);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	index = -1;
	while (++index < size)
		str[index] = src[index];
	str[index] = '\0';
	return (str);
}

void	append_lst(t_lst **lst, t_lst *unit)
{
	t_lst	*current_unit;

	if (!*lst)
	{
		*lst = unit;
		return ;
	}
	current_unit = *lst;
	while (current_unit->next)
		current_unit = current_unit->next;
	current_unit->next = unit;
}
