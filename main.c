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

static int				my_fonct_key(int keycode, t_a *a)
{
	if (keycode == ESC)
		ft_error("ESC: Good Bye My Friend .... YOLO");
	return (0);
}

static void		ft_print_conf(t_a *a)
{
	char *str;

	str = "Aucun Argument Donné en Paramètre n'est valide.";
	ft_putendl(str);
	str = "Argument Existant : ";
	ft_putstr(str);
	str = "\n - Julia \n - Mandelbrot\n - Autres";
	ft_putendl(str);
	exit(1);
}

static void			fct_verif(char *arg, t_a *a)
{
	char *str1;
	char *str2;

	str1 = "Julia";
	str2 = "Mandelbrot";

	if ((ft_strcmp(str1, arg)) && (ft_strcmp(str2, arg)))
		ft_print_conf(a);
}

int				main(int argc, char **argv)
{
	t_a		a;

	if (argc > 1)
		fct_verif(argv[1], &a);
	else
		ft_print_conf(&a);	
	fract_init(&a);
	fract_new_image(&a);
	mlx_hook(a.e.win, 2, (1L << 01), my_fonct_key, &a);
	mlx_loop(a.e.mlx);
	return (0);
}
