/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 19:06:27 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/19 19:07:33 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char				parse(t_rt *rt, int fd)
{
	char	*data;
	char	**split;

	if ((data = ft_rfc(fd)) && (split = ft_strsplit(data, '\n')))
	{
		free(data);
		
		return (1);
	}
	return (0);
}
