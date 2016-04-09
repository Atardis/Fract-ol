/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:53:40 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/06 12:53:42 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fract_new_image(t_a *a)
{
	a->e.img = mlx_new_image(a->e.mlx, MAX_X, MAX_Y);
	a->e.data = mlx_get_data_addr(a->e.img, &a->e.bpp, &a->e.sl, &a->e.ed);
	if (a->e.data == NULL)
		ft_error("Problem of Get_Data");
	a->e.bpp /= 8;
}

void		fract_init(t_a *a)
{
	if (a->e.julia == 1)
		a->e.name = "Fractal Julia";
	else if (a->e.mandelbrot == 1)
		a->e.name = "Fractal Mandelbrot";
	if (!(a->e.mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(a->e.win = mlx_new_window(a->e.mlx, MAX_X, MAX_Y, a->e.name)))
		ft_error("mlx_new_windows error");
	fract_new_image(a);
}
