/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:26:53 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/19 19:11:43 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"

# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define WINX 2000
# define WINY 1500
# define THREADS 8

typedef struct		s_rt
{
	char	ntm;
}					t_rt;

char				parse(t_rt *rt, int fd);
void				run(t_rt *rt);

#endif
