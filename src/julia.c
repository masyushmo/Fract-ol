/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:16:56 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/24 13:16:56 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		julia(t_core *core, int x, int y)
{
	core->rx = 1.5 * (x - W_X / 2) / (0.5 * core->zoom * W_X) + core->xmove;
	core->iy = (y - W_Y / 2) / (0.5 * core->zoom * W_Y) + core->ymove;
	core->it = 0;
	while (core->rx * core->rx + core->iy
			* core->iy < 4 && core->it < ITERATION)
	{
		core->xx = core->rx;
		core->yy = core->iy;
		core->rx = core->xx * core->xx - core->iy * core->iy + core->cx;
		core->iy = 2 * core->xx * core->yy + core->cy;
		core->it++;
	}
	if (core->it == ITERATION)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * core->it);
}

void	set_julia(t_core *core)
{
	core->cx = -0.70176;
	core->cy = -0.3842;
	core->zoom = 1;
	core->xmove = 0;
	core->ymove = 0;
	core->color->c = 0;
}
