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
	while (++y < 198)
	{
		x = -1;
		while (++x < MAX_X)
		{
			if (y < 4 || (x >= 520 && x < 523))
				c = 0xCC0000;
			else
				c = 0x002F2F;
			*(unsigned int*)(a->data_2 + (x * (a->b)) + (y * a->l)) = c;
		}
	}
}

static int		ft_zoom(t_a *a)
{
	int			i;
	double		tmp_z;

	i = 2;
	tmp_z = a->zoom;
	while(tmp_z > 100)
	{
		i++;
		tmp_z /= 10;
	}
	return (i);
}

static void		ft_print_info_2(t_a *a)
{
	if (a->i_max == 0)
		ft_print_the_end(a);
	a->str = "Nombre Zoom   : 2.10^";
	mlx_string_put(a->mlx, a->win, 10, 680, 0xFEA128, a->str);
	a->str = ft_itoa(ft_zoom(a));
	mlx_string_put(a->mlx, a->win, 220, 680, 0x16901A, a->str);
	free(a->str);
}

static void		ft_print_info(t_a *a)
{
	ft_print_info_2(a);
	a->str = "Iteration Max :";
	mlx_string_put(a->mlx, a->win, 10, 650, 0xFEA128, a->str);
	a->str = ft_itoa(a->i_max);
	mlx_string_put(a->mlx, a->win, 165, 650, 0x16901A, a->str);
	free(a->str);
	mlx_string_put(a->mlx, a->win, 10, 620, 0xFEA128, "Modifier I_MAX: ");
	if (a->mod_i != 1)
		mlx_string_put(a->mlx, a->win, 165, 622, 0x16901A, "Activated");
	else
		mlx_string_put(a->mlx, a->win, 165, 622, 0xFE3A4E, "Desactivate");
	if (a->main == -1)
	{

		ft_print_menu(a);
		if (a->main2 == 1 && a->main3 == -1)
			ft_print_sub_menu(a);
	}
	if (a->main == 1)
		ft_print_info_menu(a);
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
