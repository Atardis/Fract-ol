/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 23:26:19 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/12 23:26:23 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		ft_back_menu(t_a *a)
{
	int			x;
	int			y;
	int			c;

	y = -1;
	while (++y < 200)
	{
		x = -1;
		while (++x < MAX_X)
		{
			if (y < 4 || (x >= 470 && x < 473))
				c = 0xCC0000;
			else if (x >= 300 && x <= 302 && y < 200)
				c = 0xCC0000;
			else
				c = 0x002F2F;
			*(unsigned int*)(a->data_2 + (x * (a->b)) + (y * a->l)) = c;
		}
	}
}

void			fractal_print(t_a *a)
{
	int			i;

	mlx_clear_window(a->mlx, a->win);
	ft_bzero(a->data, (MAX_X * MAX_Y));
	a->y = -1;
	a->tmp_zi = a->zi;
	while (++a->y < MAX_Y)
	{
		a->x = -1;
		while (++a->x < MAX_X)
		{
			i = -1;
			a->zr = 0;
			a->zi = a->tmp_zi;
			i = a->ft(a, i);
			play_color(a, (a->x * 4 + a->y * MAX_X * 4), i);
		}
	}
	a->zi = a->tmp_zi;
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	ft_back_menu(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img_2, 0, MAX_Y);
	ft_print_info(a);
}
