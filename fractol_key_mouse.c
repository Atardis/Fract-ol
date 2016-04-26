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

#include "fractol.h"

void				ft_resize(t_a *a, int x, int y, char c)
{
	int				tmp_x;
	int				tmp_y;
	int				tmp_z;
	int				tmp_xx;
	int				tmp_yy;

	a->xx *= -1;
	a->yy *= -1;
	tmp_z = a->zoom;
	if (c == '*')
		a->zoom *= 1.1;
	else if (c == '/')
		a->zoom /= 1.1;
	if (x <= a->xx)
		tmp_x = -(a->xx - x);
	else if (x > -a->xx)
		tmp_x = x - a->xx;
	if (y <= a->yy)
		tmp_y = a->yy - y;
	else if (y > a->yy)
		tmp_y = -(y - a->yy);
	if (c == '*')
		a->zoom *= 1.1;
	else if (c == '/')
		a->zoom /= 1.1;
	tmp_xx = ((a->zoom * tmp_x) / tmp_z);
	tmp_yy = ((a->zoom * tmp_y) / tmp_z);
	a->xx -= tmp_xx - tmp_x;
	a->yy += tmp_yy - tmp_y;
	a->xx *= -1;
	a->yy *= -1;
}

int					ft_key_mouse(int k, int x, int y, t_a *a)
{
	if (a->mod_i == -1 && a->main == 1 && k == M_PLUS)
		a->i_max += 5;
	else if (a->mod_i == -1 && a->main == 1 && k == M_MINUS)
		a->i_max -= (a->i_max == 0) ? 0 : 5;
	else if (a->mod_i == 1 && a->main == 1 && k == M_PLUS)
		ft_resize(a, x, y, '*');
	else if (a->mod_i == 1 && a->main == 1 && k == M_MINUS)
		ft_resize(a, x, y, '/');
	else if (k == M_LEFT)
		ft_resize(a, x, y, '*');
	else if (k == M_RIGHT)
		ft_resize(a, x, y, '/');
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
				a->cr -= 0.10;
			else
				a->cr += 0.10;
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
