/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:18:05 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/22 11:18:06 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		chose(char *str)
{
	int		i;
	char	*stt[2] = {"julia", "mandelbrot"};

	i = -1;
	while (++i < 3)
	{
		if (ft_strcmp(stt[i], str) == 0)
		{
			create_win(str);
			return (1);
		}
	}
	return (0);
}

void	thread_add(t_core *core)
{
	int		i;

	i = -1;
	while (++i < THREAD)
	{
		core->tdata[i].num = i;
    	core->tdata[i].core = core;
		pthread_create(core->thread + i, NULL, \
			threads, (void*)(&core->tdata[i])); 
	}
	while(i--)
		pthread_join(core->thread[i], NULL);
	mlx_put_image_to_window(core->mlx_ptr, core->win_ptr, \
		core->image->image_ptr, 0, 0);
}

void	*threads(void *data)
{
	t_tdata		*too;
	int			x;
	int			y;

	too = (t_tdata*)data;
	y = W_Y / THREAD * too->num;
	while (y < W_Y / THREAD * (too->num + 1))
	{
		x = -1;
		while (++x < W_X)
		{
			if (x < 0 || x >= W_X || y <= 0 || y >= W_Y)
				return ;
			*(int *)(too->core->image->addr + ((x * 4) + ((y - 1) * W_X * 4))) = color();
		}
		y++;
	}
	return (NULL);
}
 