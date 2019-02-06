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

	if (core->name == 1)
		color = julia(core, &core->args, x, y);
	else if (core->name == 2)
		color = mandelbrot(core, &core->args, x, y);
	else if (core->name == 3)
		color = burnship(core, &core->args, x, y);
	else if (core->name == 4)
		color = burnjul(core, &core->args, x, y);
	else if (core->name == 5)
		color = mandela_vol4(core, &core->args, x, y);
	else if (core->name == 6)
		color = julia_vol3(core, &core->args, x, y);
	else if (core->name == 7)
		color = tricorn(core, &core->args, x, y);
	if (x >= 0 && x <= W_X && y >= 0 && y <= W_Y)
		ft_memcpy(core->image->addr + ((x * 4) + ((y - 1) * 4 * W_X)), \
		&color, sizeof(int));
}

void	color(int keycode, t_core *core)
{
	if (keycode == 18)
		core->color->c = 0;
	else if (keycode == 19)
		core->color->c = 1;
	else if (keycode == 20)
		core->color->c = 2;
	else if (keycode == 21)
		core->color->c = 3;
	else if (keycode == 23)
		core->color->c = 4;
	else if (keycode == 22)
		core->color->c = 5;
}

void	color_set(t_core *core)
{
	core->color = ft_memalloc(sizeof(t_color));
	core->color->set = ft_memalloc(sizeof(int) * 7);
	core->color->set[0] = 001002004;
	core->color->set[1] = 001001202;
	core->color->set[2] = 001001000;
	core->color->set[3] = 022013013;
	core->color->set[4] = 000600000;
	core->color->set[5] = 002020000;
	core->color->set[6] = 001002004;
}
