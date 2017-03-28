/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:54:49 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/29 00:05:04 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include "libft.h"

#include <fcntl.h>

int			main(int ac, char **av)
{
	int		fd;
	t_rt	*rt;

	rt = (t_rt*)ft_m(sizeof(t_rt));
	rt->run = 1;
	rt->win = 0;
	rt->ren = 0;
	if (ac != 2)
		ft_printf(2, "Usage: rtv1 [config file]\n");
	else if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_printf(2, "rtv1: couldn't open file: %s\n", av[1]);
	else if (!parse(rt, fd))
		ft_printf(2, "rtv1: invalid configuration file: %s\n", av[1]);
	else
		run(rt);
	return (0);
}
