/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 22:55:54 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/29 00:33:16 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WINX	1500
# define WINY	1000

# include <SDL.h>

enum				e_shapes
{
	CAM, LIGHT, PLAN, SPHERE, CONE, CYLINDER
};

typedef struct		s_elem
{
	char	shape;

	int		pos[3];
	int		rot[3];
	int		size[3];
}					t_elem;

typedef struct		s_rt
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*img;
	unsigned int	color;

	char			run;

	t_elem			*camera;
	t_elem			**lights;
	t_elem			**shapes;
}					t_rt;

char				parse(t_rt *rt, int fd);
void				run(t_rt *rt);
void				render(t_rt *rt);

void				raytrace(t_rt *rt, int x, int y, unsigned char *rgb);

char				parse_camera(t_elem *elem, char **lines);
char				parse_light(t_rt *rt, t_elem *elem, char **lines);
char				parse_shape(t_rt *rt, t_elem *elem, char **lines);

void				set_pixel(t_rt *rt, int x, int y);

#endif
