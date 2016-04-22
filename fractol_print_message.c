/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_print_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:19:37 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/19 17:19:39 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_print_the_end(t_a *a)
{
	char *str;

	str = " e88~~\\       e           e    e      888~~                      ,88~-_   Y88b      / 888~~  888~-_";
	mlx_string_put(a->mlx, a->win, 460, 500, WHITE, str);
	str = "d888         d8b         d8b  d8b     888___                    d888   \\   Y88b    /  888___ 888   \\";
	mlx_string_put(a->mlx, a->win, 460, 515, WHITE, str);
	str = "8888 __     /Y88b       d888bdY88b    888                      88888    |   Y88b  /   888    888    |";
	mlx_string_put(a->mlx, a->win, 460, 530, WHITE, str);
	str = "8888   |   /  Y88b     / Y88Y Y888b   888                      88888    |    Y888/    888    888   /";
	mlx_string_put(a->mlx, a->win, 460, 545, WHITE, str);
	str = "Y888   |  /____Y88b   /   YY   Y888b  888                       Y888   /      Y8/     888    888_-~";
	mlx_string_put(a->mlx, a->win, 460, 560, WHITE, str);
	str = " \"88__/  /      Y88b /          Y888b 888___                     `88_-~        Y      888___ 888 ~-_";
	mlx_string_put(a->mlx, a->win, 460, 575, WHITE, str);
}

static void		ft_print_sub_menu(t_a *a)
{
	char	*str;
	int		color;

	ft_putnbr_end(a->main2);
	if (a->main4 == 1)
		str = "     ----->  Style 1";
	else
		str = "             Style 1";
	color = (a->main4 == 1) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 227, 50, color, str);
	if (a->main4 == 2)
		str = "----->  Style 2";
	else
		str = "        Style 2";
	color = (a->main4 == 2) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 276, 70, color, str);
	if (a->main4 == 3)
		str = "----->  Style 3";
	else
		str = "        Style 3";
	color = (a->main4 == 3) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 276, 90, color, str);
	if (a->main4 == 4)
		str = "----->  Style 4";
	else
		str = "        Style 4";
	color = (a->main4 == 4) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 276, 110, color, str);
}

void			ft_print_menu(t_a *a)
{
	char	*str;
	int		color;

	ft_putnbr_end(a->main2);
	if (a->main2 == 1)
		str = "----->  Fractal Julia";
	else
		str = "        Fractal Julia";
	color = (a->main2 == 1) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 50, color, str);
	if (a->main2 == 2)
		str = "----->  Fractal Mandelbrot";
	else
		str = "        Fractal Mandelbrot";
	color = (a->main2 == 2) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 70, color, str);
	if (a->main2 == 3)
		str = "----->  Fractal Mandelbar";
	else
		str = "        Fractal Mandelbar";
	color = (a->main2 == 3) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 90, color, str);
	if (a->main2 == 4)
		str = "----->  Fractal Fire";
	else
		str = "        Fractal Fire";
	color = (a->main2 == 4) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 110, color, str);
	if (a->main3 == -1 && a->main2 == 1)
		ft_print_sub_menu(a);
}
