/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperin <aperin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:00:13 by aperin            #+#    #+#             */
/*   Updated: 2022/10/06 16:16:35 by aperin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void Func() {
  static int x = 0;
  x++;
  printf("%d\n", x);
}

int main() {
  Func();
  Func();
  Func();
  Func();
  Func();
  get_next_line(0);

  return 0;
}
