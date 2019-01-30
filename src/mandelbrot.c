/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:39:16 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/28 15:39:17 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mandelbrot(t_core *core, int x, int y)
{
	core->rx = (1.5 * (x - W_X / 2) / (0.5 * core->zoom * W_X) + core->xmove);
	core->iy = ((y - W_Y / 2) / (0.5 * core->zoom * W_Y) + core->ymove);
	core->it = 0;
	while (core->rx * core->rx + core->iy *
			core->iy < 4 && core->it < ITERATION)
	{
		core->xx = core->rx * core->rx - core->iy * core->iy + core->rx;
		core->yy = 2 * core->rx * core->iy + core->iy;
		core->rx = core->xx;
		core->iy = core->yy;
		core->it++;
	}
	if (core->it == ITERATION)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * core->it);
}

void	set_mandelbrot(t_core *core)
{
	core->xx = 0;
	core->yy = 0;
	core->zoom = 1;
	core->xmove = -0.5;
	core->ymove = 0;
	core->color->c = 0;
}