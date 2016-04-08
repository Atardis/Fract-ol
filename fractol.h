/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 12:40:53 by gahubaul          #+#    #+#             */
/*   Updated: 2016/04/06 12:40:56 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define MAX_X 1920
# define MAX_Y 1080

# define ESC 53

typedef struct		s_environ
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_e;

typedef struct		s_all
{
	t_e				e;
}					t_a;

/*
**		fract_image.c
*/
void				fract_init(t_a *a);
void				fract_new_image(t_a *a);

/*
**		main.c
*/
void				ft_error(char *str);
int					main(int argc, char **argv);
#endif