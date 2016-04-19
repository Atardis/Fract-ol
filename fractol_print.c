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

static void		ft_backfront_menu(t_a *a)
{
	int x;
	int y;

	y = 45;
	while (++y < 125)
	{
		x = 45;
		while (++x < 325)
			*(unsigned int*)(a->data + (x * (a->b)) + (y * a->l)) = 0x2C8CBC;
	}
}

static void		ft_print_menu2(t_a *a, int i)
{
	char *str;
	
	if (i == 2)
	{
		str = "        Fractal Julia";
		mlx_string_put(a->mlx, a->win, 50, 50, WHITE, str);
		str = "----->  Fractal Mandelbrot";
		mlx_string_put(a->mlx, a->win, 50, 70, 0xFEA128, str);
		str = "        Fractal Mandelbar";
		mlx_string_put(a->mlx, a->win, 50, 90, WHITE, str);
	}
	else
	{
		str = "        Fractal Julia";
		mlx_string_put(a->mlx, a->win, 50, 50, WHITE, str);
		str = "        Fractal Mandelbrot";
		mlx_string_put(a->mlx, a->win, 50, 70, WHITE, str);
		str = "----->  Fractal Mandelbar";
		mlx_string_put(a->mlx, a->win, 50, 90, 0xFEA128, str);
	}
}

static void		ft_print_menu(t_a *a)
{
	char *str;

	ft_backfront_menu(a);
	if (a->main2 == 1)
	{
		str = "----->  Fractal Julia";
		mlx_string_put(a->mlx, a->win, 50, 50, 0xFEA128, str);
		str = "        Fractal Mandelbrot     ";
		mlx_string_put(a->mlx, a->win, 50, 70, WHITE, str);
		str = "        Fractal Mandelbar      ";
		mlx_string_put(a->mlx, a->win, 50, 90, WHITE, str);
	}
	if (a->main2 == 2)
		ft_print_menu2(a, 2);
	if (a->main2 == 3)
		ft_print_menu2(a, 3);
}

static void		ft_print_the_end(t_a *a)
{
	char *str;

	str = ",--------.,--.  ,--.,------.          ,------.,--.  ,--.,------.";
	mlx_string_put(a->mlx, a->win, 650, 500, WHITE, str);
	str = "'--.  .--'|  '--'  ||  .---'          |  .---'|  ,'.|  ||  .-.  \\";
	mlx_string_put(a->mlx, a->win, 650, 515, WHITE, str);
	str = "   |  |   |  .--.  ||  `--,           |  `--, |  |' '  ||  |  \\  :";
	mlx_string_put(a->mlx, a->win, 650, 530, WHITE, str);
	str = "   |  |   |  |  |  ||  `---.          |  `---.|  | `   ||  '--'  /";
	mlx_string_put(a->mlx, a->win, 650, 545, WHITE, str);
	str = "   `--'   `--'  `--'`------'          `------'`--'  `--'`-------'";
	mlx_string_put(a->mlx, a->win, 650, 560, WHITE, str);
}

static void			ft_print_info(t_a *a)
{
	if (a->main != 1 && a->mod_i != 1)
	{	
		a->mod_i *= -1;
		ft_print_menu(a);
	}
	else if (a->main != 1)
		ft_print_menu(a);
	if (a->mod_i != 1)
		mlx_string_put(a->mlx, a->win, 50, 50, 0xFF0000, "Modifier Activated");
	if (a->info_i == -1)
		mlx_string_put(a->mlx, a->win, 10, 10, 0xFFFFFF, ft_itoa(a->i_max));
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
		ft_backfront_menu(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	ft_print_info(a);
	mlx_destroy_image(a->mlx, a->img);
}
