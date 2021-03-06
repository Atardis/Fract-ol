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
	mlx_string_put(a->mlx, a->win, 280, 340, WHITE, a->str);
	a->str = "   d888     \\   Y88b    /  888___ 888   \\";
	mlx_string_put(a->mlx, a->win, 280, 355, WHITE, a->str);
	a->str = "  88888      |   Y88b  /   888    888    |";
	mlx_string_put(a->mlx, a->win, 280, 370, WHITE, a->str);
	a->str = "  88888      |    Y888/    888    888   /";
	mlx_string_put(a->mlx, a->win, 280, 385, WHITE, a->str);
	a->str = "   Y888     /      Y8/     888    888_-~";
	mlx_string_put(a->mlx, a->win, 280, 400, WHITE, a->str);
	a->str = "     `88_ -~        Y      888___ 888 ~-_";
	mlx_string_put(a->mlx, a->win, 280, 415, WHITE, a->str);
}

void			ft_print_the_end(t_a *a)
{
	a->str = " e88~~\\       e           e    e      888~~";
	mlx_string_put(a->mlx, a->win, 280, 140, WHITE, a->str);
	a->str = "d888         d8b         d8b  d8b     888___";
	mlx_string_put(a->mlx, a->win, 280, 155, WHITE, a->str);
	a->str = "8888 __     /Y88b       d888bdY88b    888";
	mlx_string_put(a->mlx, a->win, 280, 170, WHITE, a->str);
	a->str = "8888   |   /  Y88b     / Y88Y Y888b   888";
	mlx_string_put(a->mlx, a->win, 280, 185, WHITE, a->str);
	a->str = "Y888   |  /____Y88b   /   YY   Y888b  888";
	mlx_string_put(a->mlx, a->win, 280, 200, WHITE, a->str);
	a->str = " \"88__/  /      Y88b /          Y888b 888___";
	mlx_string_put(a->mlx, a->win, 280, 215, WHITE, a->str);
	ft_print_the_end2(a);
}

void			ft_print_sub_menu(t_a *a)
{
	a->str = " *   Style 1";
	a->color = (a->main4 == 1) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 810, 620, a->color, a->str);
	a->str = " *   Style 2";
	a->color = (a->main4 == 2) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 810, 650, a->color, a->str);
	a->str = " *   Style 3";
	a->color = (a->main4 == 3) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 810, 680, a->color, a->str);
	a->str = " *   Style 4";
	a->color = (a->main4 == 4) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 810, 710, a->color, a->str);
}

void			ft_print_menu(t_a *a)
{
	a->str = "* Fractal Julia";
	a->color = (a->main2 == 1) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 550, 620, a->color, a->str);
	a->str = "* Fractal Mandelbrot";
	a->color = (a->main2 == 2) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 550, 650, a->color, a->str);
	a->str = "* Fractal Mandelbar";
	a->color = (a->main2 == 3) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 550, 680, a->color, a->str);
	a->str = "* Fractal Burning Ship";
	a->color = (a->main2 == 4) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 550, 710, a->color, a->str);
	a->str = "* Fractal Celtic";
	a->color = (a->main2 == 5) ? 0xFEA128 : WHITE;
	mlx_string_put(a->mlx, a->win, 550, 740, a->color, a->str);
}

void			ft_print_info_menu(t_a *a)
{
	a->str = "Info (Clique ici pour ouvrir le menu)";
	mlx_string_put(a->mlx, a->win, 480, 605, 0xC03000, a->str);
	a->str = "Touche O                    - Origin";
	mlx_string_put(a->mlx, a->win, 480, 630, 0xFEA128, a->str);
	a->str = "Clique <- / ->              - Zoom/Dezoom";
	mlx_string_put(a->mlx, a->win, 480, 650, 0xFEA128, a->str);
	a->str = "Molette Haut/Bas            - Zoom/Dezoom";
	mlx_string_put(a->mlx, a->win, 480, 670, 0xFEA128, a->str);
	a->str = "08(s) ou 8/*                - Deplacement Vertical";
	mlx_string_put(a->mlx, a->win, 480, 690, 0xFEA128, a->str);
	a->str = "09(s) ou 9/(                - Deplacement Horizontal";
	mlx_string_put(a->mlx, a->win, 480, 710, 0xFEA128, a->str);
	a->str = "10(s) ou 0/) (2 click)      - Change Julia";
	mlx_string_put(a->mlx, a->win, 480, 730, 0xFEA128, a->str);
	a->str = "11(s) ou -/_ et Molette +/- - Changer Iteration";
	mlx_string_put(a->mlx, a->win, 480, 750, 0xFEA128, a->str);
	a->str = "12(s) ou =/+                - Centre Fractal";
	mlx_string_put(a->mlx, a->win, 480, 770, 0xFEA128, a->str);
}
