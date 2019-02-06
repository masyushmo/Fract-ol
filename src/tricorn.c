/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:15:59 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/05 13:15:59 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		tricorn(t_core *core, t_args *args, int x, int y)
{
	args->cx = x / args->zoom + args->xmove;
	args->cy = -(y / args->zoom + args->ymove);
	args->it = 0;
	args->rx = 0;
	args->iy = 0;
	while (args->rx * args->rx + args->iy * \
			args->iy < 4 && args->it < core->iteration)
	{
		args->xx = args->rx * args->rx - args->iy * args->iy + args->cx;
		args->yy = -2 * args->rx * args->iy + args->cy;
		args->rx = args->xx;
		args->iy = args->yy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_tricorn(t_core *core, t_args *args)
{
	args->zoom = 210;
	args->xmove = -3.0;
	args->ymove = -1.70;
	core->color->c = 6;
	core->iteration = 100;
	core->zoomit = 1;
}
