/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:17:40 by mmasyush          #+#    #+#             */
/*   Updated: 2019/01/17 12:17:40 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <pthread.h>
# define W_X 2000
# define W_Y 1300
# define THREAD 1
# define ITERATION 1000

typedef struct		s_image
{
	void		*image_ptr;
	char		*addr;
	int			bpp;
	int			endian;
	int			size;
}					t_image;

typedef struct		s_color
{

}					t_color;

typedef struct		s_core
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			name;
	double		rx;
	double		iy;
	double		cx;
	double		cy;
	double		cxx;
	double		cxy;
	double		xx;
	double		yy;
	double		zoom;
	double		xmove;
	double		ymove;
	int			color;
	int			it;
	t_image		*image;
}					t_core;

typedef struct		s_tdata
{
	int			num;
	t_core		*core;
}					t_tdata;

/*
**main
*/
int						main(int argc, char **argv);
int						stop(char *str);
int						chose(char *str);
/*
**fratals
*/
void					julia(t_core *core, int x, int y);
void					set_julia(t_core *core);
void					mandelbrot(t_core *core, int x, int y);
void					set_mandelbrot(t_core *core);
/*
**mlx
*/
t_core					*create_win(t_core *core, char *str);
t_core					*destroy_win(t_core *core);
t_image					*create_image(t_core *core);
t_image					*destroy_image(t_core *core, t_image *image);
/*
**thread
*/
void					fract_ol(t_core *core, char *str);
void					*threads(void *too);
void					thread_add(t_core *core);
/*
**keys
*/

/*
**adds
*/
void					color(t_core *core, int x, int y);
void					paint_pixel(t_core *core, int x, int y, int color);
int						sets(int i);

#endif