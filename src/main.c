/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:06:45 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/17 15:06:45 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	stop(char *str)
{
	ft_putstr(str);
	exit(1);
	return (0);
}

int	chose(char *str)
{
	if ((ft_strcmp("julia" , str) == 0) || \
		(ft_strcmp("mandelbrot", str) == 0) || \
		(ft_strcmp("mo", str) == 0))
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_core	*core;
	
	if (argc < 2)
		stop("ERROR: not enough args\n");
	if (argc > 2)
		stop("ERROR: too many args\n");
	if (!(chose(argv[1])))
		stop("ERROR: wrong name");
	core = create_win(core, argv[1]);
	fract_ol(core, argv[1]);
	thread_add(core);
	mlx_hook(core->win_ptr, 2, 0, key_press, core);
	mlx_hook(core->win_ptr, 4, 0, mouse_press, core);
	mlx_hook(core->win_ptr, 17, 0, stop, 0);
	mlx_loop(core->mlx_ptr);
	return (0);
}
