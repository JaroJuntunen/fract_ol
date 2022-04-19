/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   julia.Created: 2022/04/19 15:28:19 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/19 19:06:52 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb_to_int(int i)
{
	return (255 * i) + 255 + (255 * i);
}

void	calculate_image(t_mlx	*mlx)
{
	t_julia	julia;
	int		maxIterations;
	int		i;
	int		y;
	int		x;

	maxIterations = 300;
	julia.cRe = -0.7;
	julia.cIm = 0.27015;
	y = 0;
	while(y < mlx->win_h)
	{
		x = 0; 
		while(x < mlx->win_w)
		{
			julia.newRe = 1.5 * (x - mlx->win_w / 2) / (0.5 * mlx->zoom * mlx->win_w) +mlx->moveX;
			julia.newIm = (y - mlx->win_h / 2) / (0.5 * mlx->zoom * mlx->win_h) + mlx->moveY;
			i = 0;
			while(i++ < maxIterations)
			{
				julia.oldRe = julia.newRe;
				julia.oldIm = julia.newIm;
				julia.newRe = julia.oldRe * julia.oldRe - julia.oldIm * julia.oldIm + julia.cRe;
				julia.newIm = 2 * julia.oldRe * julia.oldIm + julia.cIm;
				if((julia.newRe * julia.newRe + julia.newIm * julia.newIm) > 4)
					break;
			}
			if (i < maxIterations)
				julia.color = rgb_to_int(i);
			else
				julia.color = rgb_to_int(maxIterations);
			((int *)mlx->buffer)[(y * mlx->win_w) + x++] = julia.color;
		}
		y++;
	}
}