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

void	mandelbrot(t_core *core, int x, int y)
{
	core->cx = 1.5 * (x - W_X / 2) / (0.5 * core->zoom * W_X) + core->xmove;
	core->cy = (y - W_Y / 2) / (0.5 * core->zoom * W_Y) + core->ymove;
	core->it = 0;
	while (core->rx * core->rx + core->iy *
			core->iy < 4 && core->it < ITERATION)
	{
		core->xx = core->rx;
		core->rx = core->rx * core->rx -
			core->iy * core->iy + core->cx;
		core->iy = 2 * core->iy * core->xx + core->cy;
		core->it++;
	}
	if (core->it == ITERATION)
		paint_pixel(core, x, y, 0x000000);
	else
		paint_pixel(core, x, y, 0x0000ff);
}

void	set_mandelbrot(t_core *core)
{
	core->xx = 0;
	core->rx = 0;
	core->yy = 0; 
	core->iy = 0;
	core->zoom = 1;
	core->xmove = 0;
	core->ymove = 0;
	core->color = 265;
}