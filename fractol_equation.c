/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 01:19:52 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/13 01:19:53 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia(t_a *a, int i)
{
	double	fa_zr;
	double	fa_zi;
	double	tmp;

	if (a->i_max == 0)
		return (0);
	a->zr = a->x / a->zoom + a->xx / a->zoom;
	a->zi = a->y / a->zoom + a->yy / a->zoom;
	fa_zr = a->zr * a->zr;
	fa_zi = a->zi * a->zi;
	while ((fa_zr + fa_zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fa_zr - fa_zi + a->cr;
		a->zi = 2 * a->zi * tmp + a->ci;
		fa_zr = a->zr * a->zr;
		fa_zi = a->zi * a->zi;
	}
	return (i);
}

int			mandelbrot(t_a *a, int i)
{
	double	fa_zr;
	double	fa_zi;
	double	tmp;

	if (a->i_max == 0)
		return (0);
	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	fa_zr = a->zr * a->zr;
	fa_zi = a->zi * a->zi;
	while ((fa_zr + fa_zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fa_zr - fa_zi + a->cr;
		a->zi = 2 * a->zi * tmp + a->ci;
		fa_zr = a->zr * a->zr;
		fa_zi = a->zi * a->zi;
	}
	return (i);
}

int			mandelbar(t_a *a, int i)
{
	double	fa_zr;
	double	fa_zi;
	double	tmp;

	if (a->i_max == 0)
		return (0);
	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	fa_zr = a->zr * a->zr * 2;
	fa_zi = a->zi * a->zi * 2;
	while ((fa_zr + fa_zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fa_zr - fa_zi - a->cr;
		a->zi = -2 * a->zi * tmp + a->ci;
		fa_zr = a->zr * a->zr;
		fa_zi = a->zi * a->zi;
	}
	return (i);
}

int			burning_ship(t_a *a, int i)
{
	double	fa_zr;
	double	fa_zi;
	double	tmp;

	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	fa_zr = a->zr * a->zr * 2;
	fa_zi = a->zi * a->zi * 2;
	while ((fa_zr + fa_zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fa_zr - fa_zi - a->cr;
		a->zi = 2 * fabs(a->zi) * fabs(tmp) + a->ci;
		fa_zr = a->zr * a->zr;
		fa_zi = a->zi * a->zi;
	}
	return (i);
}
