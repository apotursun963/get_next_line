/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:44:55 by atursun           #+#    #+#             */
/*   Updated: 2024/11/09 15:53:42 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	char			*buff;
	struct s_lst	*next;
}	t_lst;

char	*read_one_line(int fd, t_lst **lst);
char	*get_next_line(int fd);
void	lst_free(t_lst **lst);
int		len_of_lst(t_lst **lst);
int		len_of_node(char *node);
char	*merge_nodes(t_lst **lst);
char	*str_dup(char *src);
t_lst	*create_node(char *content);
char	*search_new_line(char *str);
void	append_lst(t_lst **lst, t_lst *unit);

#endif