/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandela_vol4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:00:06 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/04 11:00:06 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mandela_vol4(t_core *core, t_args *args, int x, int y)
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
		args->xx = ft_expon(args->rx, 4) - 6 * ft_expon(args->rx, 2) * \
			ft_expon(args->iy, 2) + ft_expon(args->iy, 4) + args->cx;
		args->yy = 4 * ft_expon(args->rx, 3) * args->iy - 4 * args->rx * \
			ft_expon(args->iy, 3) + args->cy;
		args->rx = args->xx;
		args->iy = args->yy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_mandela_vol4(t_core *core, t_args *args)
{
	args->zoom = 330;
	args->xmove = -2.10;
	args->ymove = -1.16;
	core->color->c = 0;
	core->iteration = 100;
	core->zoomit = 1;
}