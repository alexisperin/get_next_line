/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:36:14 by aperin            #+#    #+#             */
/*   Updated: 2022/10/10 18:36:18 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*split_nl(char **str);

int	main(void)
{
	char *str = ft_strndup("Hello", 0);
	char *str2 = ft_strndup("aaaa\n", 0);
	printf("%s", ft_strjoin_and_free(&str, str2, 5));
}
