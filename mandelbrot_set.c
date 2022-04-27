/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:34:19 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/26 21:29:02 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int i)
{
	return ((255 * i) + 255 + (255 * i));
}

static int	mandelbrot_iterator(t_fractal f, t_mlx *mlx, int x, int y)
{
	double	tempx;
	int		i;

	i = 0;
	f.cre = ((x - mlx->win_w / 2) / (0.05 * mlx->zoom * mlx->win_w))
		- mlx->movex;
	f.cim = ((y - mlx->win_h / 2) / (0.05 * mlx->zoom * mlx->win_h))
		- mlx->movey;
	f.zre = 0;
	f.zim = 0;
	while ((f.zre * f.zre + f.zim * f.zim < 4) && (i < f.maxiterations))
	{
		tempx = f.zre * f.zre - f.zim * f.zim + f.cre;
		f.zim = 2 * f.zre * f.zim + f.cim;
		f.zre = tempx;
		i++;
	}
	return (i);
}

void	calculate_mandelbrot(t_mlx	*mlx)
{
	t_fractal	f;
	int			x;
	int			y;
	int			i;

	f.maxiterations = 300;
	y = 0;
	while (y < mlx->win_h)
	{
		x = 0;
		while (x < mlx->win_w)
		{
			i = mandelbrot_iterator(f, mlx, x, y);
			if ( i >= f.maxiterations)
				f.color = 0x000000;
			else
				f.color = get_color(i);
			((int *)mlx->buffer)[(y * mlx->win_w) + x++] = f.color;
		}
		y++;
	}
}
