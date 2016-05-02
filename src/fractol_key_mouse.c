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
		a->zoom *= 2;
	else if (c == '/')
		a->zoom /= 2;
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
	ft_putstr("X -> ");
	ft_putnbr_end(x);
	ft_putstr("Y -> ");
	ft_putnbr_end(y);
	ft_putchar('\n');
	if (a->mod_i == -1 && a->main == 1 && k == M_PLUS && a->mod_i != -1)
		a->i_max += 1;
	else if (a->mod_i == 1 && a->main == 1 && k == M_PLUS && a->mod_i != -1)
		ft_resize(a, x, y, '*');
	else if (a->mod_i == 1 && a->main == 1 && k == M_MINUS && a->mod_i != -1)
		ft_resize(a, x, y, '/');
	else if (k == M_LEFT)
		ft_resize(a, x, y, '*');
	else if (k == M_RIGHT)
		ft_resize(a, x, y, '/');
	else if (k == ELEVEN)
		a->mod_i *= -1;
	else if (a->mod_i == -1 && (k == M_PLUS || k == M_MINUS))
		a->i_max += (k == M_PLUS) ? 1 : -1;
	else if (a->mod_i == -1 && k == M_MINUS)
		a->i_max -= (a->i_max) ? 0 : 1;
	if (a->i_max < 0)
		a->i_max = 0;
	fractal_print(a);
	return (0);
}

int					mouse_position(int x, int y, t_a *a)
{
	if (a->slash == 1)
	{
		if (a->space == -1)
		{
			if (a->save_x >= x)
				a->cr -= 0.1;
			else
				a->cr += 0.1;
		}
		if (a->space == -2)
		{
			if (a->save_x >= x)
				a->ci -= 0.02;
			else
				a->ci += 0.02;
		}
	}
	if (a->slash == -1)
	{
		a->xx = -x;
		a->yy = -y;
	}
	a->save_x = x;
	fractal_print(a);
	return (0);
}
