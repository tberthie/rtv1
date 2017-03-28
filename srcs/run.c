/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 23:17:46 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/29 00:12:20 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#include "libft.h"

static void		event(SDL_Event event, t_rt *rt)
{
	if (event.type == SDL_WINDOWEVENT && event.window.event ==
	SDL_WINDOWEVENT_CLOSE)
		rt->run = 0;
}

static void		update(t_rt *rt)
{
	const Uint8		*status;

	status = SDL_GetKeyboardState(0);
	if (status[SDL_SCANCODE_ESCAPE])
		rt->run = 0;
}

void			run(t_rt *rt)
{
	SDL_Event	ev;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) || !(rt->win =
	SDL_CreateWindow("RTV1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	WINX, WINY, SDL_WINDOW_SHOWN)) || !(rt->ren = SDL_CreateRenderer(rt->win,
	-1, SDL_RENDERER_ACCELERATED)))
	{
		ft_printf(2, "rtv1: SDL failed to init\n");
		return ;
	}
	while (rt->run)
	{
		update(rt);
		while (SDL_PollEvent(&ev))
			event(ev, rt);
		render(rt);
	}
	SDL_Quit();
}
