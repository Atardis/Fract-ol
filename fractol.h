/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:40:53 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/06 12:40:56 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define MAX_X 1920
# define MAX_Y 1080
# define TITLE "Fractol 42 by Gautier Hubault"

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define ESC 53
# define ENTER 36
# define I 34
# define J 38
# define M 46
# define N 45
# define FOIS 67

typedef struct		s_a
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;

	int				(*ft)(struct s_a*, int);
	
	int				julia;
	int				mandelbrot;
	int				info;
	int				info_i;
	int				mod_i;
	int				main;
	int				main2;

	int				lock;
	int				i_max;
	double			zoom;
	double			ox;
	double			oy;
	double			xx;
	double			yy;
	double			zi;
	double			zr;
	double			cr;
	double			ci;
	double			tmp_zi;
	int				x;
	int				y;
	
}					t_a;

/*
**		fract_image.c
*/
void				fract_new_image(t_a *a);
void				fract_init(t_a *a);
void				fractol_init_var(t_a *a);

/*
**		fractol_color.c
*/
void				play_color(t_a *a, int k, int i);

/*
**		fractol_equation.c
*/
int					mandelbrot(t_a *a, int i);
int					julia(t_a *a, int i);
int					mandelbar(t_a *a, int i);
/*
**		fractol_key.c
*/
void				fract_press(int keycode, t_a *a);

/*
**		fractol_print.c
*/
void				fractal_print(t_a *a);

/*
**		main.c
*/
void				ft_error(char *str);
void				ft_print_help(t_a *a);
int					main(int argc, char **argv);

#endif
