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
	if (button == 4)
		zoom(x, y, core);
	if (button == 5)
		unzoom(x, y, core);
	thread_add(core);
	return (0);
}

int key_press(int keycode, t_core *core)
{
	if (keycode == 53)
		stop("");
	if (keycode == 49)
	{
		core->color->c += 1;
		if (core->color->c + 1 == 7)
			core->color->c = 0;
	}
	if (keycode == 126)
		core->ymove += 0.05;
	if (keycode == 125)
		core->ymove -= 0.05;
	if (keycode == 124)
		core->xmove -= 0.05;
	if (keycode == 123)
		core->xmove += 0.05;
	thread_add(core);
	return (0);
}