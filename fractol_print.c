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

static void		ft_print_menu2(t_a *a, int i)
{
	char *str;
	
	if (i == 2)
	{
		str = "         Fractal Julia        ";
		mlx_string_put(a->mlx, a->win, 50, 50, BLACK, str);
		str = "------> Fractal Mandelbrot <--";
		mlx_string_put(a->mlx, a->win, 50, 65, BLACK, str);
		str = "        Fractal Mandelbar      ";
		mlx_string_put(a->mlx, a->win, 50, 80, BLACK, str);
	}
	else
	{
		str = "         Fractal Julia         ";
	mlx_string_put(a->mlx, a->win, 50, 50, BLACK, str);
	str = "        Fractal Mandelbrot     ";
	mlx_string_put(a->mlx, a->win, 50, 65, BLACK, str);
	str = "------> Fractal Mandelbar <----";
	mlx_string_put(a->mlx, a->win, 50, 80, BLACK, str);
	}
}

static void		ft_print_menu(t_a *a)
{
	char *str;

	if (a->main2 == 1)
	{
		str = "-------> Fractal Julia <-------";
		mlx_string_put(a->mlx, a->win, 50, 50, BLACK, str);
		str = "        Fractal Mandelbrot     ";
		mlx_string_put(a->mlx, a->win, 50, 65, BLACK, str);
		str = "        Fractal Mandelbar      ";
		mlx_string_put(a->mlx, a->win, 50, 80, BLACK, str);
	}
	if (a->main2 == 2)
		ft_print_menu2(a, 2);
	if (a->main2 == 3)
		ft_print_menu2(a, 3);
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
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	if (a->mod_i != 1)
		mlx_string_put(a->mlx, a->win, 50, 50, 0xFFFFFF, "Star Activated");
	if (a->main != 1)
		ft_print_menu(a);
	if (a->info_i == -1)
		mlx_string_put(a->mlx, a->win, 10, 10, 0xFFFFFF, ft_itoa(a->i_max));
	mlx_destroy_image(a->mlx, a->img);
}
