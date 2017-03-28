/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:10:17 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/29 00:31:38 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include "libft.h"

static char		get_id(char *line)
{
	if (!ft_strcmp(line, "camera"))
		return (CAM);
	else if (!ft_strcmp(line, "light"))
		return (LIGHT);
	else if (!ft_strcmp(line, "plan"))
		return (PLAN);
	else if (!ft_strcmp(line, "sphere"))
		return (SPHERE);
	else if (!ft_strcmp(line, "cone"))
		return (CONE);
	else if (!ft_strcmp(line, "cylinder"))
		return (CYLINDER);
	return (-1);
}

static char		parse_elem(t_rt *rt, char **lines)
{
	t_elem		*elem;

	elem = (t_elem*)ft_m(sizeof(t_elem));
	if ((elem->shape = get_id(*lines)) == -1 || (elem->shape == CAM
	&& rt->camera) || !*++lines)
		return (0);
	rt->camera = elem->shape == CAM ? elem : rt->camera;
	if (elem->shape == CAM)
		return (parse_camera(elem, lines));
	else if (elem->shape == LIGHT)
		return (parse_light(rt, elem, lines));
	return (parse_shape(rt, elem, lines));
}

char			parse(t_rt *rt, int fd)
{
	char	**lines;
	char	*line;

	rt->camera = 0;
	rt->lights = (t_elem**)ft_parrnew();
	rt->shapes = (t_elem**)ft_parrnew();
	lines = (char**)ft_parrnew();
	while ((line = ft_gnl(fd)))
	{
		if (*line)
			ft_parrpush((void***)&lines, line);
		else if (!parse_elem(rt, lines))
			return (0);
		else
		{
			ft_parrfree((void**)lines);
			lines = (char**)ft_parrnew();
		}
	}
	if (!parse_elem(rt, lines))
		return (0);
	ft_parrfree((void**)lines);
	return (rt->camera) ? 1 : 0;
}
