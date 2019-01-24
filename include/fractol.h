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
# define W_X 500
# define W_Y 500
# define THREAD 4
# define IT 100

typedef struct		s_core	t_core;

typedef struct		s_image
{
	void		*image_ptr;
	char		*addr;
	int			bpp;
	int			endian;
	int			size;
}					t_image;

typedef struct		s_args
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		x;
	double		y;
	int			color;
}					t_args;

typedef struct		s_complex
{
	double		rx;
	double		iy;
	int			i;
}					t_complex;

typedef struct		s_tdata
{
	int			num;
	t_core		*core;
}					t_tdata;

typedef struct		s_core
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_complex	*complex;
	t_image		*image;
	t_args		*args;
	pthread_t	thread[THREAD];
	t_tdata		tdata[THREAD];

}					t_core;

/*
**main
*/
int						main(int argc, char **argv);
int						stop(char *str);
/*
**fratals
*/

/*
**mlx
*/
t_core					*create_win(char *stt);
t_core					*destroy_win(t_core *core);
t_image					*create_image(t_core *core);
t_image					*destroy_image(t_core *core, t_image *image);
/*
**thread
*/
int						chose(char *str);
void					*threads(void *too);
void					thread_add(t_core *core);
/*
**keys
*/

/*
**adds
*/

#endif