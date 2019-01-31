/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:45:41 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/19 11:45:41 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_core	*create_win(t_core *core, char *str)
{	
	if (!(core = ft_memalloc(sizeof(t_core))))
		stop("ERROR: some problem with mlx ;(");
	core->mlx_ptr = mlx_init();
	core->win_ptr = mlx_new_window(core->mlx_ptr, W_X, W_Y, str);
	if (!(core->image = create_image(core)))
	{
		destroy_win(core);
		stop("ERROR: some problem with mlx ;(");
	}
	color_set(core);
	return (core);
}

t_core	*destroy_win(t_core *core)
{
	if (core->image != NULL)
		destroy_image(core, core->image);
	if (core->win_ptr != NULL)
		mlx_destroy_window(core->win_ptr, core->mlx_ptr);
	ft_memdel((void **)core);
	return (0);
}

t_image	*create_image(t_core *core)
{
	t_image		*image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (0);
	if (!(image->image_ptr = mlx_new_image(core->mlx_ptr, W_X, W_Y)))
		return (0);
	image->addr = mlx_get_data_addr(image->image_ptr, &image->bpp,
		&image->size, &image->endian);
	image->bpp /= 8;  
	return (image);
}

t_image	*destroy_image(t_core *core, t_image *image)
{
	if (!image)
		return (0);
	if (image->image_ptr)
		mlx_destroy_image(core->mlx_ptr, image->image_ptr);
	ft_memdel((void **)image);
	return (0);
}
