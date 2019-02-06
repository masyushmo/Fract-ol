/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 13:11:28 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/02 13:11:28 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		burnship(t_core *core, t_args *args, int x, int y)
{
	args->cx = x / args->zoom + args->xmove;
	args->cy = y / args->zoom + args->ymove;
	args->it = 0;
	args->rx = 0;
	args->iy = 0;
	while (args->rx * args->rx + args->iy * \
			args->iy < 4 && args->it < core->iteration)
	{
		args->xx = args->rx * args->rx - args->iy * args->iy - args->cx;
		args->yy = 2 * fabs(args->rx * args->iy) + args->cy;
		args->rx = args->xx;
		args->iy = args->yy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_burnship(t_core *core, t_args *args)
{
	args->zoom = 310;
	args->xmove = -1.8;
	args->ymove = -1.8;
	core->color->c = 6;
	core->iteration = 100;
	core->zoomit = 0;
}
