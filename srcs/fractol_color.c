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
