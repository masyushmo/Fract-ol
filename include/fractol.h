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
# define W_X 1200
# define W_Y 1200
# define THREAD 1
# define ITERATION 75

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
	int			*set;
	int			c;
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
	double		xx;
	double		yy;
	double		zoom;
	double		xmove;
	double		ymove;
	int			it;
	t_image		*image;
	t_color		*color;
}				t_core;

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
int						julia(t_core *core, int x, int y);
void					set_julia(t_core *core);
int						mandelbrot(t_core *core, int x, int y);
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
int						key_press(int keycode, t_core *core);
int						mouse_press(int button, int x, int y, t_core *core);
/*
**adds
*/
void					piexel_color(t_core *core, int x, int y);
void					color_set(t_core *core);
/*
**color
*/
void					zoom(int x, int y, t_core *core);
void					unzoom(int x, int y, t_core *core);

#endif