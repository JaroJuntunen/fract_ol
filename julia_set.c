/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:23:23 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/17 16:20:37 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_color(int i)
{
	return ((255 * i) + 255 + (255 * i));
}

static int	julia_iterator(t_fractal f, t_mlx *mlx, int x, int y)
{
	int	i;

	i = 0;
	f.zre = 1.5 * (x - mlx->win_w / 2) / (0.5 * mlx->zoom * mlx->win_w)
		+ mlx->movex;
	f.zim = (y - mlx->win_h / 2) / (0.5 * mlx->zoom * mlx->win_h)
		+ mlx->movey;
	while (i++ < f.maxiterations && (f.zre * f.zre + f.zim * f.zim) < 4)
	{
		f.tempre = f.zre;
		f.tempim = f.zim;
		f.zre = f.tempre * f.tempre - f.tempim * f.tempim + f.cre;
		f.zim = 2 * f.tempre * f.tempim + f.cim;
	}
	return (i);
}

void	calculate_julia(t_mlx	*mlx)
{
	t_fractal	f;
	int			i;
	int			y;
	int			x;

	f.maxiterations = mlx->iter;
	f.cre = mlx->julia_cre;
	f.cim = mlx->julia_cim;
	y = 0;
	while (y < mlx->win_h)
	{
		x = 0;
		while (x < mlx->win_w)
		{
			i = julia_iterator(f, mlx, x, y);
			if (i >= f.maxiterations)
				f.color = 0x000000;
			else
				f.color = get_color(i);
			((int *)mlx->buffer)[(y * mlx->win_w) + x++] = f.color;
		}
		y++;
	}
}
