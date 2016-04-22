/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_keyboard.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 01:27:43 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/22 01:27:45 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			ft_menu(int keycode, t_a *a, int c)
{
	if (c == 1)
	{
		if (a->main2 == 1 && keycode == UP)
			a->main2 = 4;
		else if (a->main2 == 4 && keycode == DOWN)
			a->main2 = 1;
		else if (keycode == UP)
			a->main2 -= 1;
		else
			a->main2 += 1;
	}
	else if (c == 2)
	{
		a->main *= -1;
		if (a->main2 == 1)
			a->ft = &julia;
		if (a->main2 == 2)
			a->ft = &mandelbrot;
		if (a->main2 == 3)
			a->ft = &mandelbar;
		if (a->main2 == 4)
			a->ft = &fire;
		fractol_init_var(a);
	}
	else if (c == 3)
	{
		if (a->main4 == 1 && keycode == UP)
			a->main4 = 4;
		else if (a->main4 == 4 && keycode == DOWN)
			a->main4 = 1;
		else if (keycode == UP)
			a->main4 -= 1;
		else
			a->main4 += 1;
	}
	else if (c == 4)
	{
		fractol_init_var(a);
		if (a->main4 == 1)
		{
			a->cr = -0.7269;
			a->ci = 0.1889;
		}
		if (a->main4 == 2)
		{
			a->cr = -0.70176;
			a->ci = -0.3842;
		}
		if (a->main4 == 3)
		{
			a->cr = -0.4;
			a->ci = 0.6;
		}
		if (a->main4 == 4)
		{
			a->cr = -0.8;
			a->ci = 0.156;
		}
		fractal_print(a);
	}
	else if (c == 5)
	{
		a->main *= -1;
		a->main3 *= -1;
		ft_menu(keycode, a, 4);
	}
}

int					fract_key(int k, t_a *a)
{
	if ((k == RIGHT || k == LEFT) && a->main == -1 && a->main2 == 1)
	{
		if (k == LEFT)
		{
			a->main *= -1;
			a->main3 = 1;
			ft_menu(k, a, 2);
		}
		if (k == RIGHT)
		{
			a->main3 = (k == RIGHT) ? -1 : 1;
			ft_menu(k, a, 4);
		}
	}
	if (k == O)
	{
		fractol_init_var(a);
		fractal_print(a);
	}
	if (k == SPACE && a->space == 1)
		a->space += -2;
	else if (k == SPACE && a->space == -1)
		a->space += -1;
	else if (k == SPACE && a->space == -2)
		a->space = 1;

	if (a->main == 1 && (k == LEFT || k == RIGHT))
		a->xx -= (k == LEFT) ? 30 : -30;
	if (a->main == 1 && (k == UP || k == DOWN))
		a->yy -= (k == UP) ? 30 : -30;
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
	else if (a->main == -1 && (k == UP || k == DOWN) && a->main3 == 1)
		ft_menu(k, a, 1);
	else if (a->main == -1 && (k == ENTER) && a->main3 == 1)
		ft_menu(k, a, 2);
	else if ((k == DOWN || k == UP) && a->main3 == -1)
	{
		ft_menu(k, a, 3);
		ft_menu(k, a, 4);
		fractal_print(a);
	}
	else if (a->main == -1 && a->main3 == -1 && (k == ENTER))
		ft_menu(k, a, 5);
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
