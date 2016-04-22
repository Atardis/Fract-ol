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
	if (a->mod_i == -1 && a->main == 1 && k == M_PLUS)
		a->i_max += 1;
	else if (a->mod_i == -1 && a->main == 1 && k == M_MINUS)
		a->i_max -= (a->i_max == 0) ? 0 : 1;
	else if (k == M_LEFT)	
	{
		ft_resize(a, x, y);
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
	a->save_x = x;
	fractal_print(a);
	return (0);
}
