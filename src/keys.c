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
	if (button == 5 || button == 4)
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
		stop("");
	mlx_clear_window(core->mlx_ptr, core->win_ptr);
	if (keycode == 83)
	{
		set_julia(core, &core->args);
		core->name = 1;
	}
	if (keycode == 84)
	{
		set_mandelbrot(core, &core->args);
		core->name = 2;
	}
	if (keycode == 85)
	{
		set_burnship(core, &core->args);
		core->name = 3;
	}
	if (keycode == 86)
	{
		set_burnjul(core, &core->args);
		core->name = 4;
	}
	if (keycode == 256)
	{
		if (core->zoomit == 1)
			core->zoomit--;
		else
			core->zoomit++;
	}
	if (keycode == 13)
		core->args.ymove += 0.05;
	if (keycode == 1)
		core->args.ymove -= 0.05;
	if (keycode == 2)
		core->args.xmove -= 0.05;
	if (keycode == 0)
		core->args.xmove += 0.05;
	if (keycode == 24)
		core->iteration += 10;
	if (keycode == 27 && core->iteration > 0)
		core->iteration -= 10;
	color(keycode, core);
	thread_add(core);
	return (0);
}

int	mouse_move(int x, int y, t_core *core)
{
	mlx_clear_window(core->mlx_ptr, core->win_ptr);
	if ((core->name == 1 || core->name == 4 ) && core->jmouse == 1)
	{
		core->args.cx = ((x / core->args.zoom + core->args.xmove) * 1.2);
		core->args.cy = ((y / core->args.zoom + core->args.ymove) * 1.2);
	}
	thread_add(core);
	return (0);
}
