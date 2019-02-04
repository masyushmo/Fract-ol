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

int		julia(t_core *core, t_args *args, int x, int y)
{
	double n;

	args->cx = x / args->zoom + args->xmove;
	args->iy = y / args->zoom + args->ymove;
	args->it = 0;
	args->rx = 0;
	args->iy = 0;
	args->xx = 0;
	args->yy = 0;
	n = args->rx * args->rx + args->iy * args->iy;
	while (n < 4 && args->it < core->iteration)
	{
		args->rx = args->xx - args->yy + args->cx;
		args->rx = 2 * fabs(args->rx * args->iy) + args->cy;
		args->xx = args->rx * args->rx;
		args->yy = args->iy * args->iy;
		n = args->xx * args->xx + args->yy * args->yy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_julia(t_core *core, t_args *args)
{
	args->zoom = 320;
	args->xmove = -2.13;
	args->ymove = -1.2;
	core->color->c = 0;
	core->iteration = 100;
	core->jmouse = 0;
	core->zoomit = 1;
}
