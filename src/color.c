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

void	paint_pixel(t_core *core, int x, int y, int color)
{
	if (x < 0 || x >= W_X || y <= 0 || y >= W_Y)
		return ;
	*(int *)(core->image->addr + (x * 4 + 
		((y - 1) * W_X * 4))) = color;
}

int	sets(int i)
{
	int	set[2][5];


	set[0][0] = 0x000000;
	set[0][1] = 0xFFFFFF;
	set[0][3] = 0x000000;
	set[0][4] = 0xFFFFFF;
	return (set[0][i % 4]);
}