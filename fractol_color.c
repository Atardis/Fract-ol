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
	return (0x00FF00CC);
}

void			play_color(t_a *a, int k, int i)
{
	int			color_back;
	int			color_front;

	color_back = 0x0;
	color_front = choose_color(a);
	if (i == 0)
		i = 1;
	if (a->i_max == 0)
		a->i_max = 2;
	if (i == a->i_max)
	{
		a->data[k] = color_back >> 0;							// Blue
		a->data[++k] = color_back >> 4;							// Green
		a->data[++k] = color_back >> 10;						// Red
	}
	else
	{
		a->data[k] = ((color_front / a->i_max) * i);			// Blue
		a->data[++k] = ((color_front / a->i_max) * i) >> 16;	// Red
		a->data[++k] = ((color_front / a->i_max) * i) >> 8;		// Green
	}
}
