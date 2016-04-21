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

static void		ft_backfront_menu(t_a *a, int i)
{
	int			x;
	int			y;

	y = -1;
	while (++y < (40 + i))
	{
		x = -1;
		while (++x < 275)
			*(unsigned int*)(a->data + (x * (a->b)) + (y * a->l)) = 0x000000;
	}
	y = 4;
	while (++y < 31)
	{
		x = 1835;
		while (++x < 1890)
			*(unsigned int*)(a->data + (x * (a->b)) + (y * a->l)) = 0x000000;
	}
}

static void		ft_print_info(t_a *a)
{
	char *str;

	ft_backfront_menu(a, 0);
	mlx_string_put(a->mlx, a->win, 1850, 5, 0xFEA128, ft_itoa(a->i_max));
	mlx_string_put(a->mlx, a->win, 10, 5, 0xFEA128, "Modifier I_MAX");
	if (a->main != 1)
	{
		str = "--------------------------";
		mlx_string_put(a->mlx, a->win, 5, 25, 0x2C8CBC, str);
		ft_print_menu(a);
	}
	if (a->mod_i != 1)
		mlx_string_put(a->mlx, a->win, 160, 5, 0xB5E655, "Activated");
	else
		mlx_string_put(a->mlx, a->win, 160, 5, 0xF33353, "Deactivate");
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
		ft_backfront_menu(a, 115);
	ft_backfront_menu(a, 0);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	ft_print_info(a);
	mlx_destroy_image(a->mlx, a->img);
}
