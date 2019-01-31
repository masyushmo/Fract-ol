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
	args->rx = x / args->zoom + args->xmove;
	args->iy = y / args->zoom + args->ymove;
	args->it = 0;
	while (args->rx * args->rx + args->iy
			* args->iy < 4 && args->it < core->iteration)
	{
		args->xx = args->rx;
		args->yy = args->iy;
		args->rx = args->xx * args->xx - args->iy * args->iy + args->cx;
		args->iy = 2 * args->xx * args->yy + args->cy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_julia(t_core *core, t_args *args)
{
	args->cx = 0;
	args->cy = 0;
	args->zoom = 320;
	args->xmove = -2.13;
	args->ymove = -1.2;
	core->color->c = 0;
	core->iteration = 100;
	core->jmouse = 0;
	core->zoomit = 1;
}
