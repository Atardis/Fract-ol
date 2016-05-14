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

#include "../includes/fractol.h"

void			ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void			ft_print_help(t_a *a)
{
	a->str = "fractol: illegal option -- -";
	ft_putendl(a->str);
	ft_putendl("usage: fractol:\n-j (julia)\n-m (mandelbrot)\n-M (mandelbar)");
	ft_putendl("-b (burning ship)\n-c (celtic)");
	exit(1);
}

static void		verif_argv(char *s, t_a *a)
{
	if (!(ft_strcmp(s, "-j")))
		a->main2 = 1;
	else if (!(ft_strcmp(s, "-m")))
		a->main2 = 2;
	else if (!(ft_strcmp(s, "-M")))
		a->main2 = 3;
	else if (!(ft_strcmp(s, "-b")))
		a->main2 = 4;
	else if (!(ft_strcmp(s, "-c")))
		a->main2 = 5;
	if (!(ft_strcmp(s, "-j")))
		a->ft = &julia;
	else if (!(ft_strcmp(s, "-m")))
		a->ft = &mandelbrot;
	else if (!(ft_strcmp(s, "-M")))
		a->ft = &mandelbar;
	else if (!(ft_strcmp(s, "-b")))
		a->ft = &burning_ship;
	else if (!(ft_strcmp(s, "-c")))
		a->ft = &celtic;
	else
		ft_print_help(a);
}

static int		windows_exit(t_a *a)
{
	(void)a;
	ft_putstr("Sylvain Durif, Le Grand Monarque, ");
	ft_error("le Christ Cosmique te dit au revoir ....Tchuss");
	return (0);
}

int				main(int argc, char **argv)
{
	t_a			a;

	if (argc == 1 || argc >= 4)
		ft_print_help(&a);
	if (argc == 3)
		if (ft_atoi(argv[2]) >= 0)
			a.i_max = ft_atoi(argv[2]);
	if (argc == 2)
		a.i_max = 75;
	verif_argv(argv[1], &a);
	fract_init(&a);
	fract_new_image(&a);
	fractal_print(&a);
	mlx_hook(a.win, 2, 1L << 1, fract_key, &a);
	mlx_hook(a.win, 6, 1L << 6, mouse_position, &a);
	mlx_hook(a.win, 17, 1L << 17, windows_exit, &a);
	mlx_mouse_hook(a.win, ft_key_mouse, &a);
	mlx_loop(a.mlx);
	return (0);
}
