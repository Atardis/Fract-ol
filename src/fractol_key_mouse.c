/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 01:28:26 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/22 01:28:28 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void				ft_resize(t_a *a, int x, int y, char c)
{
	a->xx *= -1;
	a->yy *= -1;
	a->tmp_z = a->zoom;
	if (c == '*')
	{
		a->zoom *= 2;
		a->nb_zoom += 2;
	}
	else if (c == '/')
	{
		a->zoom /= 2;
		a->nb_zoom -= 2;
	}
	if (x <= a->xx)
		a->tmp_x = -(a->xx - x);
	if (x > a->xx)
		a->tmp_x = x - a->xx;
	if (y <= a->yy)
		a->tmp_y = a->yy - y;
	if (y > a->yy)
		a->tmp_y = -(y - a->yy);
	a->tmp_xx = ((a->zoom * a->tmp_x) / a->tmp_z);
	a->tmp_yy = ((a->zoom * a->tmp_y) / a->tmp_z);
	a->xx -= a->tmp_xx - a->tmp_x;
	a->yy += a->tmp_yy - a->tmp_y;
	a->xx *= -1;
	a->yy *= -1;
	
}

int					ft_key_mouse(int k, int x, int y, t_a *a)
{
	if(k == M_LEFT && (x >= 520 && y > MAX_Y))
		a->main *= -1;
	if (a->mod_i == -1 && k == M_PLUS && a->mod_i != -1)
		a->i_max += 1;
	if ((x >= 0 && x <= MAX_X) && (y >= 0 && y <= MAX_Y))
	{
		if (a->mod_i == 1 && k == M_PLUS && a->mod_i != -1)
			ft_resize(a, x, y, '*');
		if (a->mod_i == 1 && k == M_MINUS && a->mod_i != -1)
			ft_resize(a, x, y, '/');
		if (k == M_LEFT)
			ft_resize(a, x, y, '*');
		if (k == M_RIGHT)
			ft_resize(a, x, y, '/');
		if (k == ELEVEN)
			a->mod_i *= -1;
		if (a->mod_i == -1 && (k == M_PLUS || k == M_MINUS))
			a->i_max += (k == M_PLUS) ? 1 : -1;
		if (a->mod_i == -1 && k == M_MINUS)
			a->i_max -= (a->i_max) ? 0 : 1;
	}
	if (a->i_max < 0)
		a->i_max = 0;
	if ((k == M_PLUS || k == M_MINUS) && a->main == -1)
	{
		if (a->main2 == 1 && k == M_PLUS)
			a->main2 = 5;
		else if (a->main2 == 5 && k == M_MINUS)
			a->main2 = 1;
		else if (k == M_PLUS)
			a->main2 -= 1;
		else
			a->main2 += 1;
		ft_menu(k, a, 2);
	}
	fractal_print(a);
	return (0);
}

static void			move_to_mouse(t_a *a, int x, int y, int c)
{
	ft_putstr("X -> ");
	ft_putnbr_end(x);
	ft_putstr("Y -> ");
	ft_putnbr_end(y);
	ft_putchar ('\n');
	if ((x >= 0 && x <= MAX_X) && (y >= 0 && y <= MAX_Y))
	{
		if (c == 1)
		{
			if (x <= a->save_x_m)
				a->xx += 30;
			else if (x > a->save_x_m)
				a->xx -= 30;
			a->save_x_m = x;
		}
		else if (c == 2)
		{
			if (y <= a->save_y_m)
				a->yy += 30;
			else if (y >= a->save_y_m)
				a->yy -= 30;
			a->save_y_m = y;
		}
	}
}

int					mouse_position(int x, int y, t_a *a)
{
	if (a->nine == 1)
		a->save_x_m = x;
	if (a->eight == 1)
		a->save_y_m = y;
	if (a->slash == 1)
	{
		if (a->space == -1)
			a->cr += (a->save_x >= x) ? (-0.1) : 0.1;
		if (a->space == -2)
			a->ci += (a->save_x >= x) ? (-0.02) : 0.02;
	}
	if (a->slash == -1)
	{
		a->xx = -x;
		a->yy = -y;
	}
	if (a->nine == -1)
		move_to_mouse(a, x, y, 1);
	if (a->eight == -1)
		move_to_mouse(a, x, y, 2);
	a->save_x = x;
	fractal_print(a);
	return (0);
}
