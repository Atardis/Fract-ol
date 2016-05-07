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

#include "../includes/fractol.h"

void		fract_new_image(t_a *a)
{
	int		e;

	mlx_clear_window(a->mlx, a->win);
	if (!(a->img = mlx_new_image(a->mlx, MAX_X, MAX_Y)))
		ft_error("Problem of Mlx New Image 1");
	a->data = mlx_get_data_addr(a->img, &a->b, &a->l, &e);
	if (a->data == NULL)
		ft_error("Problem of Get_Data Image 1");
	a->b /= 8;
	if (!(a->img_2 = mlx_new_image(a->mlx, MAX_X, 200)))
		ft_error("Problem of Mlx New Image 2");
	a->data_2 = mlx_get_data_addr(a->img_2, &a->b_2, &a->l_2, &e);
	if (a->data == NULL)
		ft_error("Problem of Get_Data Image 2");
}

void		fractol_init_var(t_a *a)
{
	a->lock = 1;
	a->zoom = 100;
	a->ox = -(MAX_X / 2);
	a->oy = -(MAX_Y / 2);
	a->xx = a->ox;
	a->yy = a->oy;
	a->zi = 0;
	a->cr = 0.285;
	a->ci = 0.01;
	a->nb_zoom = 0;
	a->save_x_m = (MAX_X / 2);
	a->save_y_m = (MAX_Y / 2);
}

void		ft_init_info(t_a *a)
{
	a->i = 1;
	a->mod_i = 1;
	a->main = 1;
	a->main2 = 1;
	a->main3 = 1;
	a->main4 = 1;
	a->info = -1;
	a->ten = 1;
	a->twelve = 1;
	a->nine = 1;
	a->eight = 1;
	a->save_x = -(MAX_X / 2);
	a->save_y = -(MAX_Y / 2);
	a->k = 0;
}

void		fract_init(t_a *a)
{
	ft_init_info(a);
	fractol_init_var(a);
	if (!(a->mlx = mlx_init()))
		ft_error("mlx_init error");
	if (!(a->win = mlx_new_window(a->mlx, MAX_X, MAX_Y + 200, TITLE)))
		ft_error("mlx_new_windows error");
}
