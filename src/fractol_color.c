/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 00:42:04 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/13 00:42:06 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		choose_color(t_a *a)
{
	if (a->k == Q)
		return (0x000CCC00);
	else if (a->k == W)
		return (0x00CC00FF);
	else if (a->k == E)
		return (0x00F0F0F0);
	else if (a->k == R)
		return (0x004BB5C1);
	return (0x004BB5C1);
}

void			play_color(t_a *a, int k, int i)
{
	int			color_back;
	int			color_front;

	color_back = choose_color(a);
	color_front = choose_color(a);
	if (i == a->i_max || i == 0)
	{
		a->data[k] = color_back >> 0;
		a->data[++k] = color_back >> 4;
		a->data[++k] = color_back >> 10;
	}
	else
	{
		a->data[k] = ((color_front / a->i_max) * i);
		a->data[++k] = ((color_front / a->i_max) * i) >> 16;
		a->data[++k] = ((color_front / a->i_max) * i) >> 8;
	}
}

void			ft_print_info_menu(t_a *a)
{
	a->str = "Info (Clique ici pour ouvrir le menu)";
	mlx_string_put(a->mlx, a->win, 540, 605, 0xC03000, a->str);
	a->str = "Touche O             -> Origin";
	mlx_string_put(a->mlx, a->win, 540, 630, 0xFEA128, a->str);
	a->str = "Clique Gauche/Froite -> Zoom/Dezoom";
	mlx_string_put(a->mlx, a->win, 540, 650, 0xFEA128, a->str);
	a->str = "Molette Haut/Bas     -> Zoom/Dezoom";
	mlx_string_put(a->mlx, a->win, 540, 670, 0xFEA128, a->str);
	a->str = "08 (souris)          -> Deplacement Vertical";
	mlx_string_put(a->mlx, a->win, 540, 690, 0xFEA128, a->str);
	a->str = "09 (souris)          -> Deplacement Horiz";
	mlx_string_put(a->mlx, a->win, 540, 710, 0xFEA128, a->str);
	a->str = "10 (souris)          -> Change Julia";
	mlx_string_put(a->mlx, a->win, 540, 730, 0xFEA128, a->str);
	a->str = "11 (souris)          -> Changer Iteration";
	mlx_string_put(a->mlx, a->win, 540, 750, 0xFEA128, a->str);
	a->str = "12 (souris)          -> Centre Fractal";
	mlx_string_put(a->mlx, a->win, 540, 770, 0xFEA128, a->str);
}