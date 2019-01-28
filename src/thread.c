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

void	fract_ol(t_core *core, char *str)
{
	if (ft_strcmp("julia" , str) == 0)
	{
		core->name = 1;
		set_julia(core);
	}
	else if(ft_strcmp("mandelbrot", str) == 0)
	{
		core->name = 2;
		set_mandelbrot(core);
	}
	ft_putnbr(core->name);
	/*else if	(ft_strcmp("mo", str) == 0)
	{
		core->name = 3;
		set_mo(core);
	}*/
}

void	*threads(void *data)
{
	t_tdata		*too;
	int			x;
	int			y;

	too = (t_tdata*)data;
	y = W_X / THREAD * too->num;
	while (y < W_X / THREAD * (too->num + 1))
	{
		x = 0;
		while (x < W_Y)
		{
			if (too->core->name == 1)
				julia(too->core, x, y);
			if (too->core->name == 2)
				mandelbrot(too->core, x, y);
			/*else if (too->core->name == 3)
				mo(too->core, x, y);*/
			x++;
		}
		y++;
	}
	return (NULL);
}

void	thread_add(t_core *core)
{
	pthread_t	thread[THREAD];
	t_tdata		args[THREAD];
	int			i;

	i = 0;
	while (i < THREAD)
	{
		args[i].num = i;
		args[i].core = core;
		pthread_create(&thread[i], NULL, \
			threads, (void*)(&args[i]));
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(core->mlx_ptr, core->win_ptr, \
		core->image->image_ptr, 0, 0);
}
 