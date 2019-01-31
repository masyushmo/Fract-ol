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
	/*else if	(ft_strcmp("mo", str) == 0)
	{
		core->name = 3;
		set_mo(core);
	}*/
}

void	thread_add(t_core *core)
{
	pthread_t	thread[THREAD];
	t_tdata		args[THREAD];
	int			i;
	char		*its;

	i = 0;
	while (i < THREAD)
	{
		args[i].num = i;
		args[i].core = core;
		pthread_create(thread + i, NULL, \
			threads, args + i);
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
	its = ft_strjoin("ITERATIONS :", ft_itoa(core->iteration));
	mlx_string_put(core->mlx_ptr, core->win_ptr, \
		10, 10, 0xFFCCE5, its);
}

void	*threads(void *data)
{
	t_tdata		*too;
	int			x;
	int			y;

	too = (t_tdata*)data;
	x = W_X / THREAD * too->num;
	while (x < W_X / THREAD * (too->num + 1))
	{
		y = 0;
		while (y < W_Y)
		{
			piexel_color(too->core, x, y);
			y++;
		}
		x++;
	}
	return (NULL);
}
