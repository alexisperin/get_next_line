/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:11:27 by aperin            #+#    #+#             */
/*   Updated: 2022/10/11 11:35:03 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_fdlist
{
	int				fd;
	char			*rest;
	struct s_fdlist	*next;
}					t_fdlist;

char	*get_next_line(int fd);
char	*gnl_free(char **str1, char **str2);
int		found_nl(char *str);
char	*ft_strndup(char *str, int n);
char	*ft_strjoin_and_free(char **line, char *buf, int buf_len);

#endif