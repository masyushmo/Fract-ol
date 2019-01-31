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
	if (button == 5 || button == 4)
		zoom(button, x, y, core);
	if (button == 1)
	{
		if (core->jmouse == 1)
			core->jmouse--;
		else
			core->jmouse++;
	}
	thread_add(core);
	return (0);
}

int	key_press(int keycode, t_core *core)
{
	if (keycode == 53)
		stop("");
	if (keycode == 49)
	{
		core->color->c += 1;
		if (core->color->c + 1 == 7)
			core->color->c = 0;
	}
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
	if (keycode == 256)
	{
		if (core->zoomit == 1)
			core->zoomit--;
		else
			core->zoomit++;
	}
	if (keycode == 126)
		core->args.ymove += 0.05;
	if (keycode == 125)
		core->args.ymove -= 0.05;
	if (keycode == 124)
		core->args.xmove -= 0.05;
	if (keycode == 123)
		core->args.xmove += 0.05;
	if (keycode == 24)
		core->iteration += 10;
	if (keycode == 27 && core->iteration > 0)
		core->iteration -= 10;
	thread_add(core);
	return (0);
}

int	mouse_move(int x, int y, t_core *core)
{
	if (core->name == 1 && core->jmouse == 1)
	{
		core->args.cx = ((x / core->args.zoom + core->args.xmove) * 1.2);
		core->args.cy = ((y / core->args.zoom + core->args.ymove) * 1.2);
	}
	thread_add(core);
	return (0);
}
