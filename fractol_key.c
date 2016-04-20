/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 01:06:50 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/13 01:06:51 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_menu(int keycode, t_a *a, char c)
{
	if (c == '1')
	{
		a->mod_i = 1;
		if (a->main2 == 1 && keycode == UP)
			a->main2 = 3;
		else if (a->main2 == 3 && keycode == DOWN)
			a->main2 = 1;
		else if (keycode == UP)
			a->main2 -= 1;
		else
			a->main2 += 1;
	}
	else
	{
		if (a->main2 == 1)
			a->ft = &julia;
		if (a->main2 == 2)
			a->ft = &mandelbrot;
		if (a->main2 == 3)
			a->ft = &mandelbar;
		fractol_init_var(a);
	}
}

int		fract_key(int k, t_a *a)
{
	if (k == Q || k == W)
		(k == Q) ? (a->k = Q) : (a->k = W);
	if (k == E)
		a->k = E;
	else if (k == ESC)
		ft_error("ESC: Good Bye My Friend .. YOLO");
	else if (k == M)
		a->main *= -1;
	else if (k == FOIS || k == I)
		(k == FOIS) ? (a->mod_i *= -1) : (a->info_i *= -1);
	else if (a->main == -1 && (k == UP || k == DOWN))
		ft_menu(k, a, '1');
	else if (a->main == -1 && (k == ENTER))
	{
		a->main *= -1;
		ft_menu(k, a, 'y');
	}
	else if (a->mod_i < 0 && k == PLUS && a->i_max < 0)
		a->i_max = 0;
	else if (a->mod_i == 1 && a->main == 1 && (k == PLUS || k == MINUS))
		(k == PLUS) ? (a->zoom *= 1.1) : (a->zoom *= 0.9);
	else if (a->mod_i == -1 && a->main == 1 && k == PLUS)
		a->i_max += 1;
	else if (a->mod_i == -1 && a->main == 1 && k == MINUS && a->i_max >= 1)
		(a->i_max == 0) ? (a->i_max = 0) : (a->i_max -= 1);
	fractal_print(a);
	return (0);
}


int		ft_key_mouse(int k, int x, int y, t_a *a)
{
	ft_putstr("X :  ");
	ft_putnbr_end(x);
	ft_putstr("Y :  ");
	ft_putnbr_end(y);
	ft_putchar('\n');
	if (a->mod_i == -1 && a->main == 1 && k == M_PLUS)
		a->i_max += 1;
	else if (a->mod_i == -1 && a->main == 1 && k == M_MINUS)
		(a->i_max == 0) ? (a->i_max = 0) : (a->i_max -= 1);
	else if (k == M_PLUS)	
		a->zoom *= 1.1;
	else if (k == M_MINUS)
		a->zoom /= 1.1;
	fractal_print(a);
	return (0);
}
