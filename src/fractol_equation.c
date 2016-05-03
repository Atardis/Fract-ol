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

#include "../includes/fractol.h"

int			julia(t_a *a, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	if (a->i_max == 0)
		return (0);
	a->zr = a->x / a->zoom + a->xx / a->zoom;
	a->zi = a->y / a->zoom + a->yy / a->zoom;
	zr = a->zr * a->zr;
	zi = a->zi * a->zi;
	while ((zr + zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = zr - zi + a->cr;
		a->zi = 2 * a->zi * tmp + a->ci;
		zr = a->zr * a->zr;
		zi = a->zi * a->zi;
	}
	return (i);
}

int			mandelbrot(t_a *a, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	if (a->i_max == 0)
		return (0);
	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	zr = a->zr * a->zr;
	zi = a->zi * a->zi;
	while ((zr + zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = zr - zi + a->cr;
		a->zi = 2 * a->zi * tmp + a->ci;
		zr = a->zr * a->zr;
		zi = a->zi * a->zi;
	}
	return (i);
}

int			mandelbar(t_a *a, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	if (a->i_max == 0)
		return (0);
	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	zr = a->zr * a->zr * 2;
	zi = a->zi * a->zi * 2;
	while ((zr + zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = zr - zi - a->cr;
		a->zi = -2 * a->zi * tmp + a->ci;
		zr = a->zr * a->zr;
		zi = a->zi * a->zi;
	}
	return (i);
}

int			celtic(t_a *a, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	zr = a->zr * a->zr * 2;
	zi = a->zi * a->zi * 2;
	while ((zr + zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = fabs(zr - zi) + a->cr;
		a->zi = 2 * a->zi * tmp + a->ci;
		zr = a->zr * a->zr;
		zi = a->zi * a->zi;
	}
	return (i);
}

int			burning_ship(t_a *a, int i)
{
	double	zr;
	double	zi;
	double	tmp;

	a->cr = a->x / a->zoom + a->xx / a->zoom;
	a->ci = a->y / a->zoom + a->yy / a->zoom;
	zr = a->zr * a->zr * 2;
	zi = a->zi * a->zi * 2;
	while ((zr + zi) < 4 && ++i < a->i_max)
	{
		tmp = a->zr;
		a->zr = zr - zi - a->cr;
		a->zi = 2 * fabs(a->zi) * fabs(tmp) + a->ci;
		zr = a->zr * a->zr;
		zi = a->zi * a->zi;
	}
	return (i);
}