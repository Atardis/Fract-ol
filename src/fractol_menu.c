/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 07:54:02 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/24 07:54:04 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			ft_menu2(int keycode, t_a *a, int c)
{
	if (c == 2)
	{
		if (c == 2 && keycode == ENTER)
			a->main *= -1;
		if (a->main2 == 1)
			a->ft = &julia;
		if (a->main2 == 2)
			a->ft = &mandelbrot;
		if (a->main2 == 3)
			a->ft = &mandelbar;
		if (a->main2 == 4)
			a->ft = &burning_ship;
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
}

static void			ft_menu3(int keycode, t_a *a)
{
	fractol_init_var(a);
	if (a->main4 == 1)
	{
		a->cr = -0.0986;
		a->ci = -0.65186;
		a->i_max = 115;
	}
	if (a->main4 == 2)
	{
		a->cr = -0.70176;
		a->ci = -0.3842;
	}
	if (a->main4 == 3)
	{
		a->cr = -0.772691322542185;
		a->ci = 0.124281466072787;
		a->i_max = 83;
	}
	if (a->main4 == 4)
	{
		a->cr = -0.8;
		a->ci = 0.156;
	}
	fractal_print(a);
}

void				ft_menu(int keycode, t_a *a, int c)
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
		ft_menu(keycode, a, 2);
	}
	else if (c == 2 || c == 3)
		ft_menu2(keycode, a, c);
	else if (c == 4)
		ft_menu3(keycode, a);
	else if (c == 5)
	{
		a->main *= -1;
		a->main3 *= -1;
		ft_menu(keycode, a, 4);
	}
}
