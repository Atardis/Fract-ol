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
		return (0x0CCC00);
	else if (a->k == W)
		return (0xCC00FF);
	else if (a->k == E)
		return (0xF0F0F0);
	else if (a->k == R)
		return (0x0863C0);
	return (0x0863C0);
}

void			play_color(t_a *a, int k, int i)
{
	int			color_back;
	int			color_front;

	color_back = choose_color(a);
	color_front = choose_color(a);
	if (i == a->i_max || i == 0)
	{
		a->data[k] = color_back >> 4;
		a->data[++k] = color_back >> 6;
		a->data[++k] = color_back >> 2;
	}
	else
	{
		a->data[k] = ((color_front / a->i_max) * i) >> 4;
		a->data[++k] = ((color_front / a->i_max) * i) >> 6;
		a->data[++k] = ((color_front / a->i_max) * i) >> 2;
	}
}

void			ft_print_info_menu(t_a *a)
{
	a->str = "Info (Clique ici pour ouvrir le menu)";
	mlx_string_put(a->mlx, a->win, 535, 605, 0xC03000, a->str);
	a->str = "Touche O               - Origin";
	mlx_string_put(a->mlx, a->win, 535, 630, 0xFEA128, a->str);
	a->str = "Clique <- / ->         - Zoom/Dezoom";
	mlx_string_put(a->mlx, a->win, 535, 650, 0xFEA128, a->str);
	a->str = "Molette Haut/Bas       - Zoom/Dezoom";
	mlx_string_put(a->mlx, a->win, 535, 670, 0xFEA128, a->str);
	a->str = "08 ou 8/*              - Deplacement Vertical";
	mlx_string_put(a->mlx, a->win, 535, 690, 0xFEA128, a->str);
	a->str = "09 ou 9/(              - Deplacement Horiz";
	mlx_string_put(a->mlx, a->win, 535, 710, 0xFEA128, a->str);
	a->str = "10 ou 0/)              - Change Julia";
	mlx_string_put(a->mlx, a->win, 535, 730, 0xFEA128, a->str);
	a->str = "11 ou -/_ et Molette   - Changer Iteration";
	mlx_string_put(a->mlx, a->win, 535, 750, 0xFEA128, a->str);
	a->str = "12 ou =/+              - Centre Fractal";
	mlx_string_put(a->mlx, a->win, 535, 770, 0xFEA128, a->str);
}
