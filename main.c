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
	ft_putendl("-b (burning ship)");
	exit(1);
}

static void		verif_argv(char *s, t_a *a)
{
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
	else if (!(ft_strcmp(s, "-b")))
	{
		a->ft = &burning_ship;
		a->main2 = 4;
	}
	else
		ft_print_help(a);
}

int				main(int argc, char **argv)
{
	t_a			a;

	if (argc == 1 || argc >= 4)
		ft_print_help(&a);
	a.argv3 = -1;
	if (argc == 3)
		a.argv3 = (ft_atoi(argv[2]) == 0) ? 75 : ft_atoi(argv[2]);
	verif_argv(argv[1], &a);
	fract_init(&a);
	fractal_print(&a);
	mlx_hook(a.win, 2, 1L << 1, fract_key, &a);
	mlx_hook(a.win, 6, 1L << 6, mouse_position, &a);
	mlx_mouse_hook(a.win, ft_key_mouse, &a);
	mlx_loop(a.mlx);
	return (0);
}
