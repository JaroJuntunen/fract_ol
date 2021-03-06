/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:10:14 by jjuntune          #+#    #+#             */
/*   Updated: 2022/06/06 20:03:54 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		mlx->movex -= 0.5 / mlx->zoom;
	else if (keycode == 124)
		mlx->movex += 0.5 / mlx->zoom;
	else if (keycode == 126)
		mlx->movey -= 0.5 / mlx->zoom;
	else if (keycode == 125)
		mlx->movey += 0.5 / mlx->zoom;
	else if (keycode == 78 && mlx->iter > 5)
		mlx->iter -= 5;
	else if (keycode == 69)
		mlx->iter += 5;
	calculate_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (0);
}

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
		if (( y > 0 && y < mlx->win_h) && ( x > 0 && x < mlx->win_w))
		{
			mlx->julia_cre = ((((2.0 / (double)mlx->win_w)) * x) - 1);
			mlx->julia_cim = ((((2.0 / (double)mlx->win_h)) * y) - 1);
			calculate_image(mlx);
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
		}
	}
	return (0);
}
