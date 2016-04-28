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

#include "../includes/fractol.h"

static void				fract_key_menu(int k, t_a *a)
{
	if ((k == RIGHT || k == LEFT) && a->main == -1 && a->main2 == 1)
	{
		if (k == LEFT)
		{
			a->main3 = 1;
			ft_menu(k, a, 2);
		}
		else if (k == RIGHT)
		{
			a->main3 = -1;
			ft_menu(k, a, 4);
		}
	}
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
}

static void				fract_key_move(int k, t_a *a)
{
	if (a->main == 1 && (k == LEFT || k == RIGHT))
		a->xx -= (k == LEFT) ? 30 : -30;
	else if (a->main == 1 && (k == UP || k == DOWN))
		a->yy -= (k == UP) ? 30 : -30;
	else if (a->mod_i == -1 && k == PLUS && a->i_max < 0)
		a->i_max = 0;
	else if (a->mod_i == 1 && a->main == 1 && (k == PLUS || k == MINUS))
		(k == PLUS) ? (a->zoom *= 2) : (a->zoom *= 0.5);
	else if (a->mod_i == -1 && a->main == 1 && k == PLUS)
		a->i_max += 1;
	if (k == O)
	{
		fractol_init_var(a);
		fractal_print(a);
	}
}

int						fract_key(int k, t_a *a)
{
	ft_putnbr_end(k);
	fract_key_menu(k, a);
	fract_key_move(k, a);
	if (k == SLASH)
		a->slash *= -1;
	if (k == SPACE && a->space == 1)
		a->space += -2;
	else if (k == SPACE && a->space == -1)
		a->space += -1;
	else if (k == SPACE && a->space == -2)
		a->space = 1;
	else if (k == Q || k == W)
		a->k = (k == Q) ? Q : W;
	else if (k == E || k == R)
		a->k = (k == E) ? E : R;
	else if (k == ESC)
		ft_error("ESC: Good Bye My Friend .. YOLO");
	else if (k == M)
		a->main *= -1;
	else if (k == FOIS || k == I || k == ELEVEN)
		(k == FOIS || k == ELEVEN) ? (a->mod_i *= -1) : (a->info_i *= -1);
	else if (a->mod_i == -1 && a->main == 1 && k == MINUS && a->i_max >= 1)
		(a->i_max == 0) ? (a->i_max = 0) : (a->i_max -= 1);
	fractal_print(a);
	return (0);
}
