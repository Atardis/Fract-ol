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
	ft_putendl("fractol: illegal option --");
	ft_putendl("usage: fractol:\n-j (julia)\n-m (mandelbrot)\n-a (autres)");
	exit(1);
}

static int		fract_key(int keycode, t_a *a)
{
	if (keycode == ESC)
		ft_error("ESC: Good Bye My Friend .. YOLO");
	return (0);
}

static void		verif_argv(char *s, t_a *a)
{

	if(ft_strcmp(s, "-j") && ft_strcmp(s, "-m") && ft_strcmp(s, "-a"))
		ft_print_help(a);
	if (!(ft_strcmp(s, "-j")))
		a->e.julia = 1;
	if (!(ft_strcmp(s, "-m")))
		a->e.mandelbrot = 1;
}

int				main(int argc, char **argv)
{
	t_a			a;

	a.e.julia = 0;
	a.e.mandelbrot = 0;
	if (argc != 2)
	{
		if (argc == 1)
			ft_error("No Argument\nInfo \"fractol --help\"");
		ft_print_help(&a);
	}
	verif_argv(argv[1], &a);
	fract_init(&a);
	fract_new_image(&a);
	mlx_string_put(a.e.mlx, a.e.win, 20, 20, 0x00FF00, a.e.name);
	mlx_hook(a.e.win, 2, (1L << 01), fract_key, &a);
	mlx_loop(a.e.mlx);
	return (0);
}
