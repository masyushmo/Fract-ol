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

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include <pthread.h>
# define W_X 1366
# define W_Y 768
# define THREAD 1

typedef struct		s_image
{
	void			*image_ptr;
	char			*addr;
	int				bpp;
	int				endian;
	int				size;
}					t_image;

typedef struct		s_color
{
	int				*set;
	int				c;
}					t_color;

typedef	struct		s_args
{
	double			rx;
	double			iy;
	double			cx;
	double			cy;
	double			xx;
	double			yy;
	double			pr;
	double			pi;
	double			zoom;
	double			xmove;
	double			ymove;
	int				it;
}					t_args;

typedef struct		s_core
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				name;
	int				zoomit;
	int				iteration;
	int				jmouse;
	t_image			*image;
	t_color			*color;
	t_args			args;
}					t_core;

typedef struct		s_tdata
{
	int				num;
	t_core			*core;
}					t_tdata;

/*
**main.c
*/
int					main(int argc, char **argv);
int					stop(char *str);
int					chose(char *str);
/*
**fratals
*/
int					julia(t_core *core, t_args *args, int x, int y);
void				set_julia(t_core *core, t_args *args);
int					mandelbrot(t_core *core, t_args *args, int x, int y);
void				set_mandelbrot(t_core *core, t_args *args);
int					burnship(t_core *core, t_args *args, int x, int y);
void				set_burnship(t_core *core, t_args *args);
int					burnjul(t_core *core, t_args *args, int x, int y);
void				set_burnjul(t_core *core, t_args *args);
/*
**mlx.c
*/
t_core				*create_win(t_core *core, char *str);
t_core				*destroy_win(t_core *core);
t_image				*create_image(t_core *core);
t_image				*destroy_image(t_core *core, t_image *image);
/*
**thread.c
*/
void				fract_ol(t_core *core, char *str);
void				*threads(void *too);
void				thread_add(t_core *core);
/*
**keys.c
*/
int					key_press(int keycode, t_core *core);
int					mouse_press(int button, int x, int y, t_core *core);
int					mouse_move(int x, int y, t_core *core);
/*
**color.c
*/
void				piexel_color(t_core *core, int x, int y);
void				color_set(t_core *core);
void				color(int keycode, t_core *core);
/*
**changes.c
*/
void				zoom(int button, int x, int y, t_core *core);
#endif
