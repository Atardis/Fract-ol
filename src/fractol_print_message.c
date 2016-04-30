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

#include "../includes/fractol.h"

static void		ft_print_the_end2(t_a *a)
{
	a->str = "      ,88~-_   Y88b      / 888~~  888~-_";
	mlx_string_put(a->mlx, a->win, 800, 350, WHITE, a->str);
	a->str = "   d888     \\   Y88b    /  888___ 888   \\";
	mlx_string_put(a->mlx, a->win, 800, 365, WHITE, a->str);
	a->str = "  88888      |   Y88b  /   888    888    |";
	mlx_string_put(a->mlx, a->win, 800, 380, WHITE, a->str);
	a->str = "  88888      |    Y888/    888    888   /";
	mlx_string_put(a->mlx, a->win, 800, 395, WHITE, a->str);
	a->str = "   Y888     /      Y8/     888    888_-~";
	mlx_string_put(a->mlx, a->win, 800, 410, WHITE, a->str);
	a->str = "     `88_ -~        Y      888___ 888 ~-_";
	mlx_string_put(a->mlx, a->win, 800, 425, WHITE, a->str);
}

void			ft_print_the_end(t_a *a)
{
	a->str = " e88~~\\       e           e    e      888~~";
	mlx_string_put(a->mlx, a->win, 250, 350, WHITE, a->str);
	a->str = "d888         d8b         d8b  d8b     888___";
	mlx_string_put(a->mlx, a->win, 250, 365, WHITE, a->str);
	a->str = "8888 __     /Y88b       d888bdY88b    888";
	mlx_string_put(a->mlx, a->win, 250, 380, WHITE, a->str);
	a->str = "8888   |   /  Y88b     / Y88Y Y888b   888";
	mlx_string_put(a->mlx, a->win, 250, 395, WHITE, a->str);
	a->str = "Y888   |  /____Y88b   /   YY   Y888b  888";
	mlx_string_put(a->mlx, a->win, 250, 410, WHITE, a->str);
	a->str = " \"88__/  /      Y88b /          Y888b 888___";
	mlx_string_put(a->mlx, a->win, 250, 425, WHITE, a->str);
	a->str = "     `88_ -~        Y      888___ 888 ~-_";
	mlx_string_put(a->mlx, a->win, 800, 425, WHITE, a->str);
	ft_print_the_end2(a);
}

void			ft_print_sub_menu(t_a *a)
{
	if (a->main4 == 1)
		a->str = "| ---->  Style 1";
	else
		a->str = "|       Style 1";
	a->color = (a->main4 == 1) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 276, 50, a->color, a->str);
	if (a->main4 == 2)
		a->str = "| --->   Style 2";
	else
		a->str = "|       Style 2";
	a->color = (a->main4 == 2) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 276, 70, a->color, a->str);
	if (a->main4 == 3)
		a->str = "| --->   Style 3";
	else
		a->str = "|       Style 3";
	a->color = (a->main4 == 3) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 276, 90, a->color, a->str);
	if (a->main4 == 4)
		a->str = "| --->   Style 4";
	else
		a->str = "|       Style 4";
	a->color = (a->main4 == 4) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 276, 110, a->color, a->str);
}

void			ft_print_menu(t_a *a)
{
	if (a->main2 == 1)
		a->str = "----->   Fractal Julia";
	else
		a->str = "        Fractal Julia";
	a->color = (a->main2 == 1) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 50, a->color, a->str);
	if (a->main2 == 2)
		a->str = "----->   Fractal Mandelbrot";
	else
		a->str = "        Fractal Mandelbrot";
	a->color = (a->main2 == 2) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 70, a->color, a->str);
	if (a->main2 == 3)
		a->str = "----->   Fractal Mandelbar";
	else
		a->str = "        Fractal Mandelbar";
	a->color = (a->main2 == 3) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 90, a->color, a->str);
	if (a->main2 == 4)
		a->str = "----->   Fractal Fire";
	else
		a->str = "        Fractal BurningShip";
	a->color = (a->main2 == 4) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 5, 110, a->color, a->str);
}

void			ft_back_menu2(t_a *a)
{
	int			y;
	int			x;
	int			z;

	if (a->i == -1)
	{
		y = (MAX_Y - 25);
		while (++y < MAX_Y)
		{
			x = (MAX_X - 65);
			while (++x < MAX_X)
			{
				z = (x * (a->b)) + (y * a->l);
				*(unsigned int*)(a->data + z) = 0x000000;
			}
		}
	}
}
