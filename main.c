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

// static void		ft_move(int keycode, t_a *a)
// {
// 	if (keycode == UP || keycode == DOWN)
// 	(keycode == UP) ? ()
// }

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
	mlx_hook(a.win, 2, 1L << 1, fract_key, &a);
	mlx_mouse_hook(a.win, ft_key_mouse, &a);
	mlx_loop(a.mlx);
	return (0);
}



// mlx_hook(a->win, 6, 1L << 6, pos_mouse, a);