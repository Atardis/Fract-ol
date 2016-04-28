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

#include "../includes/fractol.h"

static int		choose_color(t_a *a)
{
	if (a->k == Q)
		return (0x0000CC00);
	else if (a->k == W)
		return (0x00CC00FF);
	else if (a->k == E)
		return (0x00F0F0F0);
	else if (a->k == R)
		return (0x004BB5C1);
	return (0x004BB5C1);
}

static void		color_backgroud(t_a *a, int i, int k)
{
	int			color_back;

	color_back = choose_color(a);
	a->data[k] = color_back >> 0;
	a->data[++k] = color_back >> 4;
	a->data[++k] = color_back >> 10;
}

void			play_color(t_a *a, int k, int i)
{
	int			color_back;
	int			color_front;

	color_back = choose_color(a);
	color_front = choose_color(a);
	if (i == 0)
		color_backgroud(a, i, k);
	else if (i == a->i_max)
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
