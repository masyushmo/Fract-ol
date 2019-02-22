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
	if (str != NULL)
	{
		ft_putendl("\033[22;36mUsage: ./fractol [fractal name]");
		ft_putstr("\033[23;32m[julia] [mandelbrot] [burnship] [burnjul] ");
		ft_putendl("\033[23;32m[julia_3] [mandela_4] [tricorn] [trijul]");
	}
	ft_putstr(str);
	exit(1);
	return (0);
}

int	chose(char *str)
{
	if ((!(ft_strcmp("julia", str))) || (!(ft_strcmp("mandelbrot", str))) || \
		(!(ft_strcmp("burnship", str))) || (!(ft_strcmp("burnjul", str))) || \
		(!(ft_strcmp("julia_3", str))) || (!(ft_strcmp("mandela_4", str))) || \
		(!(ft_strcmp("tricorn", str))) || (!(ft_strcmp("trijul", str))))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_core	*core;

	if (argc < 2)
		stop("\033[22;31mERROR: not enough args\n");
	if (argc > 2)
		stop("\033[22;31mERROR: too many args\n");
	if (!(chose(argv[1])))
		stop("\033[22;31mERROR: wrong name\n");
	core = create_win(core);
	fract_ol(core, argv[1]);
	mlx_hook(core->win_ptr, 2, 0, key_press, core);
	mlx_hook(core->win_ptr, 4, 0, mouse_press, core);
	mlx_hook(core->win_ptr, 6, 0, mouse_move, core);
	mlx_hook(core->win_ptr, 17, 0, stop, 0);
	mlx_loop(core->mlx_ptr);
	return (0);
}
