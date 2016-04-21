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
	else
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
}

int					fract_key(int k, t_a *a)
{
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
	else if (a->main == -1 && (k == UP || k == DOWN))
		ft_menu(k, a, 1);
	else if (a->main == -1 && (k == ENTER))
		ft_menu(k, a, 2);
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

static void			ft_resize(t_a *a, int x, int y)
{
	int tmp;

	tmp = a->zoom;
	x *= -1;
	y *= -1;
	tmp = tmp - (tmp * 1.1);
	if (x <= (MAX_X / 2))
		a->xx -= (MAX_X / 2) + x + tmp;
	else if (x > (MAX_X / 2))
		a->xx += x  + (MAX_X / 2) - tmp;
	else if (y <= (MAX_Y / 2))
		a->yy += (MAX_Y / 2) + y + tmp;
	else if (y > (MAX_Y / 2))
		a->yy += y + (MAX_X / 2) - tmp;
}

int					ft_key_mouse(int k, int x, int y, t_a *a)
{
	ft_putnbr_end(k);
	if (a->mod_i == -1 && a->main == 1 && k == M_PLUS)
		a->i_max += 1;
	else if (a->mod_i == -1 && a->main == 1 && k == M_MINUS)
		a->i_max -= (a->i_max == 0) ? 0 : 1;
	else if (k == M_LEFT)	
	{
		ft_resize(a, x, y);
		ft_putnbr_end(a->xx);
		ft_putnbr_end(a->yy);
		a->zoom *= 1.1;
	}
	else if (k == M_RIGHT)
	{
		ft_resize(a, x, y);
		a->zoom /= 1.1;
	}
	fractal_print(a);
	return (0);
}

int					mouse_position(int x, int y, t_a *a)
{
	ft_putendl("yolo");
	if (a->space == -1)
	{
		if (a->save_x >= x)
			a->cr -= 0.10;
		else 
			a->cr += 0.10;
	}
	a->save_x = x;
	if (a->space == -2)
	{
		if (a->save_y >= y)
			a->ci -= 0.02;
		else 
			a->ci += 0.02;
	}
	a->save_y = y;
	fractal_print(a);
	return (0);
}