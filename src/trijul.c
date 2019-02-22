/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trijul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:40:59 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/14 12:40:59 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		trijul(t_core *core, t_args *args, int x, int y)
{
	args->rx = x / args->zoom + args->xmove;
	args->iy = y / args->zoom + args->ymove;
	args->it = 0;
	while (args->rx * args->rx + args->iy * \
			args->iy < 4 && args->it < core->iteration)
	{
		args->xx = ft_expon(args->rx, 4) - 6 * ft_expon(args->rx, 2) * \
			ft_expon(args->iy, 2) + ft_expon(args->iy, 4) + args->cx;
		args->yy = -(4 * ft_expon(args->rx, 3) * args->iy - 4 * args->rx * \
			ft_expon(args->iy, 3) + args->cy);
		args->rx = args->xx;
		args->iy = args->yy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_trijul(t_core *core, t_args *args)
{
	args->cx = 0;
	args->cy = 0;
	args->zoom = 270;
	args->xmove = -2.35;
	args->ymove = -1.35;
	core->color->c = 6;
	core->iteration = 100;
	core->jmouse = 0;
	core->zoomit = 0;
}
