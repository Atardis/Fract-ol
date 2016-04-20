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

#include "fractol.h"

static void		ft_backfront_menu(t_a *a, int y_max, int x_max)
{
	int			x;
	int			y;

	y = 45;
	while (++y < y_max)
	{
		x = 45;
		while (++x < x_max)
			*(unsigned int*)(a->data + (x * (a->b)) + (y * a->l)) = 0x2C8CBC;
	}
}

static void		ft_print_info(t_a *a)
{
	if (a->main != 1 && a->mod_i != 1)
	{	
		a->mod_i *= -1;
		ft_print_menu(a);
	}
	else if (a->main != 1)
		ft_print_menu(a);
	if (a->mod_i != 1)
	{
		mlx_string_put(a->mlx, a->win, 60, 50, 0xFEA128, "Modificateur I : ");
		mlx_string_put(a->mlx, a->win, 225, 50, 0xFEA128, ft_itoa(a->i_max));
	}
	if (a->i_max == 0)
		ft_print_the_end(a);
}

void			fractal_print(t_a *a)
{
	int			i;

	fract_new_image(a);
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
	if (a->main != 1)
		ft_backfront_menu(a, 120, 325);
	if (a->mod_i != 1)
		ft_backfront_menu(a, 75, 325);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	ft_print_info(a);
	mlx_destroy_image(a->mlx, a->img);
}
