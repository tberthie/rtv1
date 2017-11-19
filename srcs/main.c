/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:25:13 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/19 19:07:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				main(int ac, char **av)
{
	t_rt		*rt;
	int			fd;

	if (ac != 2)
		ft_print(2, "usage: ./rtv1 [file]\n");
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_print(2, "rtv1: %s\n", strerror(errno));
	else if (parse((rt = (t_rt*)ft_memalloc(sizeof(t_rt))), fd))
		run(rt);
	return (0);
}
