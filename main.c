/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:40:11 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/06 12:40:15 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void			ft_print_help(t_a *a)
{
	ft_putendl("fractol: illegal option -- -");
	ft_putendl("usage: fractol:\n-j (julia)\n-m (mandelbrot)\n-M (mandelbar)");
	exit(1);
}

static void		fractal_choose(int keycode, t_a *a)
{
	if (keycode == J)
		a->ft = &julia;
	if (keycode == M)
		a->ft = &mandelbrot;
	if (keycode == N)
		a->ft = &mandelbar;
	fractol_init_var(a);
}

static void		ft_menu(int keycode, t_a *a, char c)
{
	if (c == '1')
	{
		a->mod_i = 1;
		if (a->main2 == 1 && keycode == UP)
			a->main2 = 3;
		else if (a->main2 == 3 && keycode == DOWN)
			a->main2 = 1;
		else if (keycode == UP)
			a->main2 -= 1;
		else
			a->main2 += 1;
	}
	else
	{
		if (a->main2 == 1)
			a->ft = &julia;
		if (a->main2 == 2)
			a->ft = &mandelbrot;
		if (a->main2 == 3)
			a->ft = &mandelbar;
		fractol_init_var(a);
	}
}

static int		fract_key(int k, t_a *a)
{
	if (k == ESC)
		ft_error("ESC: Good Bye My Friend .. YOLO");
	if (k == M)
		a->main *= -1;
	if (k == FOIS)
		a->mod_i *= -1;
	if (k == I)
		a->info_i *= -1;
	if (a->main == -1 && (k == UP || k == DOWN))
		ft_menu(k, a, '1');
	if (a->main == -1 && (k == ENTER))
		ft_menu(k, a, 'y');
	if (a->mod_i == 1 && a->main == 1 && (k == PLUS || k == MINUS))	
		(k == PLUS) ? (a->zoom *= 1.25) : (a->zoom /= 1.25);
	if (a->mod_i == -1 && a->main == 1 && (k == PLUS || k == MINUS))
		(k == PLUS) ? (a->i_max += 1) : (a->i_max -= 1);
	fractal_print(a);
	return (0);
}

static void		verif_argv(char *s, t_a *a)
{
	if (ft_strcmp(s, "-j") && ft_strcmp(s, "-m") && ft_strcmp(s, "-M"))
		ft_print_help(a);
	if (!(ft_strcmp(s, "-j")))
	{
		a->ft = &julia;
		a->main2 = 1;
	}
	else if (!(ft_strcmp(s, "-m")))
	{
		a->ft = &mandelbrot;
		a->main2 = 2;
	}
	else if (!(ft_strcmp(s, "-M")))
	{
		a->ft = &mandelbar;
		a->main2 = 3;
	}
}

int				main(int argc, char **argv)
{
	t_a			a;

	a.mod_i = 1;
	a.main = 1;
	a.main2 = 1;
	a.info_i = 1;
	// a.julia = 0;
	// a.mandelbrot = 0;
	a.info = -1;
	if (argc != 2)
		ft_print_help(&a);
	verif_argv(argv[1], &a);
	fract_init(&a);
	fractal_print(&a);
	// mlx_mouse_hook(a->win, ft_mouse, a);
	// mlx_hook(a->win, 6, 1L << 6, pos_mouse, a);
	mlx_hook(a.win, 2, 1L << 1, fract_key, &a);
	mlx_loop(a.mlx);
	return (0);
}
