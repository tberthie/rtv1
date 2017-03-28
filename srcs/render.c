/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 00:13:34 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/29 00:26:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include "libft.h"

static void		render_pixel(t_rt *rt, int x, int y)
{
	unsigned int	*pixel;
	unsigned char	rgb[3];

	pixel = rt->img->pixels + (y * rt->img->pitch + x * 4);
	raytrace(rt, x, y, rgb);
	*pixel = 255;
	*pixel |= rgb[2] << 8;
	*pixel |= rgb[1] << 16;
	*pixel |= rgb[0] << 24;
}

void			render(t_rt *rt)
{
	SDL_Texture		*tx;
	int				x;
	int				y;

	rt->img = SDL_CreateRGBSurface(0, WINX, WINY, 32, 0, 0, 0, 0);
	y = 0;
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
		{
			render_pixel(rt, x, y);
			x++;
		}
		y++;
	}
	tx = SDL_CreateTextureFromSurface(rt->ren, rt->img);
	SDL_RenderCopy(rt->ren, tx, 0, 0);
	SDL_DestroyTexture(tx);
	SDL_RenderPresent(rt->ren);
	SDL_FreeSurface(rt->img);
}
