/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:07:22 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/28 19:07:23 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_press(int button, int x, int y, t_core *core)
{
	mlx_clear_window(core->mlx_ptr, core->win_ptr);
	if (button == 5 || button == 4 || button == 2)
		zoom(button, x, y, core);
	if (button == 1)
	{
		if (core->jmouse == 1)
			core->jmouse = 0;
		else
			core->jmouse = 1;
	}
	thread_add(core);
	return (0);
}

int	key_press(int keycode, t_core *core)
{
	if (keycode == 53)
		stop(NULL);
	mlx_clear_window(core->mlx_ptr, core->win_ptr);
	if (keycode == 256)
	{
		if (core->zoomit == 0)
			core->zoomit = 1;
		else
			core->zoomit = 0;
	}
	if (keycode == 24)
		core->iteration += 10;
	if (keycode == 27 && core->iteration > 0)
		core->iteration -= 10;
	if (keycode == 15)
		core->color->set[6] = 001002004;
	if (keycode == 49)
		sickomode(core);
	help(keycode, core);
	moves(keycode, core);
	numpad(keycode, core);
	color(keycode, core);
	thread_add(core);
	return (0);
}

int	mouse_move(int x, int y, t_core *core)
{
	mlx_clear_window(core->mlx_ptr, core->win_ptr);
	if ((core->name == 1 || core->name == 4 || \
		core->name == 6 || core->name == 8) && core->jmouse == 1)
	{
		core->args.cx = ((x / core->args.zoom + core->args.xmove) * 1.2);
		core->args.cy = ((y / core->args.zoom + core->args.ymove) * 1.2);
	}
	thread_add(core);
	return (0);
}
