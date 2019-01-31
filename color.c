/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:26:15 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/23 16:26:15 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	piexel_color(t_core *core, int x, int y)
{
	int color;
	if (x >= 0 || x <= W_X || y >= 0 || y <= W_Y)
	{
		if (core->name == 1)
			color = julia(core, x, y);
		if (core->name == 2)
			color = mandelbrot(core, x, y);
		*(int *)(core->image->addr + 4 * W_X * y + x * 4) = color;
	}
}

void color_set(t_core *core)
{
	core->color = ft_memalloc(sizeof(t_color));
	core->color->set =  ft_memalloc(sizeof(int) * 6);
	core->color->set[0] = 001002004;
	core->color->set[1] = 001001202;
	core->color->set[2] = 001001000;
	core->color->set[3] = 022013013;
	core->color->set[4] = 000600000;
	core->color->set[5] = 002020000;
}