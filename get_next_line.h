/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:07:16 by aperin            #+#    #+#             */
/*   Updated: 2022/10/10 14:42:37 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdio.h> // A VIRER !!!

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		found_nl(char *str);
char	*ft_strndup(char *str, int n);
char	*ft_strjoin_and_free(char *line, char *buf, int buf_len);

#endif