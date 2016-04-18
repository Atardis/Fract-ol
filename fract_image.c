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
	int		b;
	int		c;
	int		e;

	if (!(a->img = mlx_new_image(a->mlx, MAX_X, MAX_Y)))
		ft_error("Problem of Mlx New Image");
	a->data = mlx_get_data_addr(a->img, &b, &c, &e);
	if (a->data == NULL)
		ft_error("Problem of Get_Data");
}

void		fractol_init_var(t_a *a)
{
	a->lock = 1;
	a->i_max = 282;
	a->zoom = 100;
	a->ox = -(MAX_X / 2);
	a->oy = -(MAX_Y / 2);
	a->xx = a->ox;
	a->yy = a->oy;
	a->zi = 0;
	a->cr = 0.285;
	a->ci = 0.01;
}

void		fract_init(t_a *a)
{
	fractol_init_var(a);
	if (!(a->mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(a->win = mlx_new_window(a->mlx, MAX_X, MAX_Y, TITLE)))
		ft_error("mlx_new_windows error");
}
