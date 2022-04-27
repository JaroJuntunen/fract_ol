/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:54:29 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/27 19:07:46 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	x = y;
	if (button == 4)
		mlx->zoom += 1;
	else if (button == 5 && mlx->zoom > 1)
		mlx->zoom -= 1;
	if (button == 1)
		mlx->lock *= -1;
	calculate_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (0);
}

int	mouse_movement(int x, int y, t_mlx *mlx)
{
	if (mlx->lock == 1)
	{
		x = (x - mlx->win_w / 2);
		y = (y - mlx->win_h / 2);
		if (x < 0)
			mlx->julia_cre -= 0.0001;
		if (x >= 0)
			mlx->julia_cre += 0.0001;
		else if (y < 0)
			mlx->julia_cim -= 0.0005;
		else if (y >= 0)
			mlx->julia_cim += 0.0005;
		calculate_image(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	}
	return (0);
}
