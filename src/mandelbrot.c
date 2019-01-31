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

int		mandelbrot(t_core *core, t_args *args, int x, int y)
{
	args->cx = x / args->zoom + args->xmove;
	args->cy = y / args->zoom + args->ymove;
	args->it = 0;
	args->rx = 0;
	args->iy = 0;
	args->xx = 0;
	args->yy = 0;
	while (args->rx * args->rx + args->iy *
			args->iy < 4 && args->it < core->iteration)
	{
		args->xx = args->rx * args->rx - args->iy * args->iy + args->cx;
		args->yy = 2 * args->rx * args->iy + args->cy;
		args->rx = args->xx;
		args->iy = args->yy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_mandelbrot(t_core *core, t_args *args)
{
	args->zoom = 330;
	args->xmove = -2.6;
	args->ymove = -1.16;
	core->color->c = 0;
	core->iteration = 100;
	core->zoomit = 1;
}
