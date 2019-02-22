/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:10:23 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/28 19:10:23 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom(int button, int x, int y, t_core *core)
{
	if (button == 4)
	{
		if (core->iteration > 0)
		{
			core->args.xmove = (x / core->args.zoom + \
				core->args.xmove) - (x / (core->args.zoom / 1.1));
			core->args.ymove = (y / core->args.zoom + \
				core->args.ymove) - (y / (core->args.zoom / 1.1));
			core->args.zoom /= 1.1;
			if (core->zoomit == 1)
				core->iteration -= 5;
		}
	}
	if (button == 5)
	{
		core->args.xmove = (x / core->args.zoom + \
			core->args.xmove) - (x / (core->args.zoom * 1.1));
		core->args.ymove = (y / core->args.zoom + \
			core->args.ymove) - (y / (core->args.zoom * 1.1));
		core->args.zoom *= 1.1;
		if (core->zoomit == 1)
			core->iteration += 5;
	}
}

void	numpad(int keycode, t_core *core)
{
	if (keycode == 83)
		JUL(core->name, core, core->args);
	if (keycode == 84)
		MAN(core->name, core, core->args);
	if (keycode == 85)
		BRN(core->name, core, core->args);
	if (keycode == 86)
		BUJ(core->name, core, core->args);
	if (keycode == 87)
		MA4(core->name, core, core->args);
	if (keycode == 88)
		JU3(core->name, core, core->args);
	if (keycode == 89)
		TRI(core->name, core, core->args);
	if (keycode == 91)
		TRJ(core->name, core, core->args);
}

void	sickomode(t_core *core)
{
	int	ro;

	srand(clock());
	ro = rand() % 111111110;
	core->args.cx = sin(core->angle * 1.1);
	core->args.cy = sin(core->angle);
	core->color->c = 6;
	core->color->set[6] = ro;
	core->angle += 0.2;
}

void	moves(int keycode, t_core *core)
{
	if (keycode == 13)
		core->args.ymove += 20 / core->args.zoom;
	if (keycode == 1)
		core->args.ymove -= 20 / core->args.zoom;
	if (keycode == 2)
		core->args.xmove -= 20 / core->args.zoom;
	if (keycode == 0)
		core->args.xmove += 20 / core->args.zoom;
}

void	help(int keycode, t_core *core)
{
	if (keycode == 4)
	{
		core->help_ptr = mlx_init();
		core->help_win_ptr = mlx_new_window(core->help_ptr, 650, 205, "HELP");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 10, 0xFF00FF, \
			"NUM1,NUM2,NUM3,NUM4,NUM5,NUM6,NUM7,NUM8 == change fractols");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 30, 0x00FFFF, \
			"1, 2, 3, 4, 5, 6 == change colors");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 50, \
			0xFF00FF, "Mouse wheel == zoom");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 70, \
			0x00FFFF, "Left mouse == juls transfomation");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 90, 0xFF00FF, \
			"W /A /S /D == move");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 110, 0x00FFFF, \
			"+/- == increase/decrease iteration");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 130, 0xFF00FF, \
			"CTRL == enable/disable auto zoom iteratiom");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 150, 0x00FFFF, \
			"SPACE == damn, my fractol goin’psycho![EXTREME SEIZURE WARNING]!");
		mlx_string_put(core->help_ptr, core->help_win_ptr, 10, 170, 0xFF00FF, \
			"R == default coloring");
		mlx_loop(core->help_ptr);
	}
}
