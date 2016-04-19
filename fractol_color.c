/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 00:42:03 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/13 00:42:06 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		choose_color(t_a *a)
{
	if (a->k == Q)
		return (0x0000CC00);
	else if (a->k == W)
		return (0x00CC0000);
	else if (a->k == E)
		return (0x00FF00CC);
	return (0x00FF00CC);
}

void			play_color(t_a *a, int k, int i)
{
	int			color_back;
	int			color_front;

	color_back = choose_color(a);
	color_front = choose_color(a);
	if (i == 0 && a->main2 == 1)
	{
		a->data[k] = ((color_front / a->i_max) * 20);
		a->data[++k] = ((color_front / a->i_max) * 20) >> 16;
		a->data[++k] = ((color_front / a->i_max) * 20) >> 8;
	}
	// else if (i == 0 && a->main2 == 2)
	// 	i = 20;
	// else if (i == 0 && a->main2 == 3)
	// 	i = 20;
	if (i == a->i_max)
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
