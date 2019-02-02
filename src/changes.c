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
				core->args.xmove) - (x / (core->args.zoom / 1.3));
			core->args.ymove = (y / core->args.zoom + \
				core->args.ymove) - (y / (core->args.zoom / 1.3));
			core->args.zoom /= 1.3;
			if (core->zoomit == 1)
				core->iteration -= 10;
		}
	}
	if (button == 5)
	{
		core->args.xmove = (x / core->args.zoom + \
			core->args.xmove) - (x / (core->args.zoom * 1.3));
		core->args.ymove = (y / core->args.zoom + \
			core->args.ymove) - (y / (core->args.zoom * 1.3));
		core->args.zoom *= 1.3;
		if (core->zoomit == 1)
			core->iteration += 10;
	}
}
