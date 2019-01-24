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

int stop(char *str)
{
	ft_putstr(str);
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	char *fract;
	t_core	*core;

	fract = argv[1];
	if (argc < 2)
		stop("ERROR: not enough args\n");
	if (argc > 2)
		stop("ERROR: too many args\n");
	if (chose(fract) == 0)
		stop("ERROR: wrong name\n");
	thread_add(core);
	//mlx_hook(core->win_ptr, 2, 0, key_press, 0);
	mlx_hook(core->win_ptr, 17, 0, stop, 0);
	mlx_loop(core->mlx_ptr);
	return (0);
}
