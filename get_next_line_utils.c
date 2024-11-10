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

int	len_of_lst(t_lst **lst)
{
	int	len;
	t_lst	*current_unit;

	len = 0;
	current_unit = *lst;
	while (current_unit)
	{
		len++;
		current_unit = current_unit->next;
	}
	return (len);
}

char	*str_dup(char *content)
{
	char	*str;

	str = (char *)malloc(2);
	if (!str)
		return (NULL);
	str[0] = content[0];
	str[1] = '\0';
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
