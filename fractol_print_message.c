/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_print_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:19:37 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/19 17:19:39 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_print_the_end(t_a *a)
{
	char *str;

	str = ",--------.,--.  ,--.,------.          ,------.,--.  ,--.,------.";
	mlx_string_put(a->mlx, a->win, 650, 500, WHITE, str);
	str = "'--.  .--'|  '--'  ||  .---'          |  .---'|  ,'.|  ||  .-.  \\";
	mlx_string_put(a->mlx, a->win, 650, 515, WHITE, str);
	str = "   |  |   |  .--.  ||  `--,           |  `--, |  |' '  ||  |  \\  :";
	mlx_string_put(a->mlx, a->win, 650, 530, WHITE, str);
	str = "   |  |   |  |  |  ||  `---.          |  `---.|  | `   ||  '--'  /";
	mlx_string_put(a->mlx, a->win, 650, 545, WHITE, str);
	str = "   `--'   `--'  `--'`------'          `------'`--'  `--'`-------'";
	mlx_string_put(a->mlx, a->win, 650, 560, WHITE, str);
}

void		ft_print_menu(t_a *a)
{
	char	*str;
	int		color;

	if (a->main2 == 1)
		str = "----->  Fractal Julia";
	else
		str = "        Fractal Julia";
	(a->main2 == 1) ? (color = 0xFEA128) : (color = WHITE);
	mlx_string_put(a->mlx, a->win, 50, 50, color, str);
	if (a->main2 == 2)
		str = "----->  Fractal Mandelbrot";
	else
		str = "        Fractal Mandelbrot";
	(a->main2 == 2) ? (color = 0xFEA128) : (color = WHITE);
	mlx_string_put(a->mlx, a->win, 50, 70, color, str);
	if (a->main2 == 3)
		str = "----->  Fractal Mandelbar";
	else
		str = "        Fractal Mandelbar";
	(a->main2 == 3) ? (color = 0xFEA128) : (color = WHITE);
	mlx_string_put(a->mlx, a->win, 50, 90, color, str);
}