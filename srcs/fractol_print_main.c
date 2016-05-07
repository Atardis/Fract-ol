/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_print_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 05:18:06 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/07 05:18:08 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		ft_print_info_3(t_a *a)
{
	if (a->main == -1)
	{
		ft_print_menu(a);
		if (a->main2 == 1 && a->main3 == -1)
			ft_print_sub_menu(a);
	}
	if (a->main == 1)
		ft_print_info_menu(a);
	if (a->i_max == 0)
		ft_print_the_end(a);
}

static void		ft_print_info_2(t_a *a)
{
	mlx_string_put(a->mlx, a->win, 10, 670, 0xFEA128, "Iteration Max :");
	a->str = ft_itoa(a->i_max);
	mlx_string_put(a->mlx, a->win, 165, 670, 0x16901A, a->str);
	free(a->str);
	a->str = "Nomber Zoom 10*";
	mlx_string_put(a->mlx, a->win, 10, 690, 0xFEA128, a->str);
	a->str = ft_itoa(ft_zoom(a));
	mlx_string_put(a->mlx, a->win, 163, 690, 0xFE3A4E, a->str);
	free(a->str);
	a->str = "Horizontal's Deplacement";
	mlx_string_put(a->mlx, a->win, 10, 710, 0xFEA128, a->str);
	a->str = (a->nine == -1) ? "ON" : "OFF";
	a->color = (a->nine == -1) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 255, 710, a->color, a->str);
	a->str = "Vertical's Deplacement ";
	mlx_string_put(a->mlx, a->win, 10, 730, 0xFEA128, a->str);
	a->str = (a->eight == -1) ? "ON" : "OFF";
	a->color = (a->eight == -1) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 255, 730, a->color, a->str);
}

void			ft_print_info(t_a *a)
{
	mlx_string_put(a->mlx, a->win, 10, 610, 0xFEA128, "Modifier I_MAX");
	a->str = (a->mod_i != 1) ? "ON" : "OFF";
	a->color = (a->mod_i != 1) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 255, 610, a->color, a->str);
	mlx_string_put(a->mlx, a->win, 10, 630, 0xFEA128, "Modifier Julia");
	if (a->ten < 1)
		a->str = (a->ten == -1) ? "Cr" : "Ci";
	else
		a->str = "OFF";
	a->color = (a->ten != 1) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 255, 630, a->color, a->str);
	a->str = "Modifier Centre Fractal";
	mlx_string_put(a->mlx, a->win, 10, 650, 0xFEA128, a->str);
	a->str = (a->twelve == -1) ? "ON" : "OFF";
	a->color = (a->twelve == -1) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 255, 650, a->color, a->str);
	ft_print_color_info(a);
	ft_print_info_2(a);
	ft_print_info_3(a);
}

void			ft_print_color_info(t_a *a)
{
	a->str = "Color Choice :";
	mlx_string_put(a->mlx, a->win, 320, 610, 0xFEA128, a->str);
	a->color = (a->k == Q) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 320, 660, a->color, "Color 1 -> Q ");
	a->color = (a->k == W) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 320, 690, a->color, "Color 2 -> W ");
	a->color = (a->k == E) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 320, 720, a->color, "Color 3 -> E ");
	a->color = (a->k == 0 || a->k == R) ? 0x16901A : 0xFE3A4E;
	mlx_string_put(a->mlx, a->win, 320, 750, a->color, "Origin  -> R ");
}
