/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjacquie <vjacquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 22:39:03 by jmoiroux          #+#    #+#             */
/*   Updated: 2015/05/02 16:06:07 by vjacquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <projet.h>

static void	render_draw_2(t_data *d, int x, int y)
{
	if (d->map[y][x].type == OBSTACLE)
		render_draw_case(d, 15, x * BLOCK_WIDTH, y * BLOCK_HEIGHT);
	else if (d->map[y][x].type == SIMPLE)
		render_draw_case(d, 0, x * BLOCK_WIDTH, y * BLOCK_HEIGHT);
	else if (d->map[y][x].type == SPEC)
	{
		render_draw_case(d, d->map[y][x].state, x * BLOCK_WIDTH,
			y * BLOCK_HEIGHT);
	}
	else if (d->map[y][x].type == EMPTY)
		render_draw_case(d, 80, x * BLOCK_WIDTH, y * BLOCK_HEIGHT);
	else if (d->map[y][x].type == PLAYER)
		render_draw_player(d, x * BLOCK_WIDTH, y * BLOCK_HEIGHT);
}

void		render_draw(t_data *d)
{
	int x;
	int y;

	y = 0;
	while (y < MAP_Y)
	{
		x = 0;
		while (x < MAP_X)
		{
			render_draw_2(d, x, y);
			x++;
		}
		y++;
	}
	if (d->map[d->ball.posy][d->ball.posx].type == EMPTY)
	{
		render_draw_case(d, 99, d->ball.posx * BLOCK_WIDTH,
			d->ball.posy * BLOCK_HEIGHT);
	}
	render_score(d);
}
