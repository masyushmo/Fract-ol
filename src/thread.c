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
	if (ft_strcmp("julia", str) == 0)
		JUL(core->name, core, core->args);
	if (ft_strcmp("mandelbrot", str) == 0)
		MAN(core->name, core, core->args);
	if (ft_strcmp("burnship", str) == 0)
		BRN(core->name, core, core->args);
	if (ft_strcmp("burnjul", str) == 0)
		BUJ(core->name, core, core->args);
	if (ft_strcmp("mandela_4", str) == 0)
		MA4(core->name, core, core->args);
	if (ft_strcmp("julia_3", str) == 0)
		JU3(core->name, core, core->args);
	if (ft_strcmp("tricorn", str) == 0)
		TRI(core->name, core, core->args);
	if (ft_strcmp("trijul", str) == 0)
		TRJ(core->name, core, core->args);
	thread_add(core);
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
		args[i].core = *core;
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
	put_it(core);
}

void	put_it(t_core *core)
{
	char		*its;
	char		*num;

	num = ft_itoa(core->iteration);
	its = ft_strjoin("ITERATIONS :", num);
	mlx_string_put(core->mlx_ptr, core->win_ptr, \
		10, 10, 0xCC0066, its);
	mlx_string_put(core->mlx_ptr, core->win_ptr, \
		11, 30, 0x00FF00, "Press 'H' to see hints");
	free(its);
	free(num);
}

void	*threads(void *data)
{
	t_tdata		*too;
	int			x;
	int			y;

	too = (t_tdata*)data;
	x = W_X / THREAD * too->num;
	while (x < (W_X / THREAD * (too->num + 1)))
	{
		y = 0;
		while (y < W_Y)
		{
			piexel_color(&too->core, x, y);
			y++;
		}
		x++;
	}
	return (NULL);
}
