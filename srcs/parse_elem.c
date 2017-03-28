/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:45:12 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/29 00:31:56 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include "libft.h"

static char		parse_vec3(int *vec, char **split)
{
	if (ft_intlen(ft_atoi(split[1])) != (int)ft_strlen(split[1])
	|| ft_intlen(ft_atoi(split[2])) != (int)ft_strlen(split[2])
	|| ft_intlen(ft_atoi(split[3])) != (int)ft_strlen(split[3]))
		return (0);
	vec[0] = ft_atoi(split[1]);
	vec[1] = ft_atoi(split[2]);
	vec[2] = ft_atoi(split[3]);
	return (1);
}

char			parse_camera(t_elem *elem, char **lines)
{
	char		**split;

	split = ft_strsplit(*lines++, ' ');
	if (!parse_vec3(elem->pos, split))
		return (0);
	ft_parrfree((void**)split);
	split = ft_strsplit(*lines++, ' ');
	if (!parse_vec3(elem->rot, split))
		return (0);
	ft_parrfree((void**)split);
	return (*lines) ? 0 : 1;
}

char			parse_light(t_rt *rt, t_elem *elem, char **lines)
{
	char		**split;

	split = ft_strsplit(*lines++, ' ');
	if (!parse_vec3(elem->pos, split))
		return (0);
	ft_parrfree((void**)split);
	if (*lines)
		return (0);
	ft_parrpush((void***)&rt->lights, elem);
	return (1);
}

char			parse_shape(t_rt *rt, t_elem *elem, char **lines)
{
	char		**split;

	split = ft_strsplit(*lines++, ' ');
	if (!parse_vec3(elem->pos, split))
		return (0);
	ft_parrfree((void**)split);
	split = ft_strsplit(*lines++, ' ');
	if (!parse_vec3(elem->rot, split))
		return (0);
	ft_parrfree((void**)split);
	split = ft_strsplit(*lines++, ' ');
	if (!parse_vec3(elem->size, split))
		return (0);
	ft_parrfree((void**)split);
	if (*lines)
		return (0);
	ft_parrpush((void***)&rt->shapes, elem);
	return (1);
}
