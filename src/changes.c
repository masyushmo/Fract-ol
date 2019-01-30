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

void zoom(int x, int y, t_core *core)
{
	//core->xmove = (x / core->zoom + core->xmove)  - (x / (core->zoom + 1.3));
	//core->ymove = (y / core->zoom + core->ymove) - (y / (core->zoom + 1.3));
	core->zoom += 1.3;
}

void unzoom(int x, int y, t_core *core)
{
	//core->x1 = (x / core->zoom + core->x1)  - (x / (core->zoom * 1.3));
	//core->y1 = (y / core->zoom + core->y1) - (y / (core->zoom * 1.3));
	core->zoom -= 1;
}
