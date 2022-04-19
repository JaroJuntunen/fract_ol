/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:10:14 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/19 20:07:42 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53 && mlx)
		exit(0);
	else if (keycode == 125)
		mlx->zoom -= 10;
	else if (keycode == 126)
		mlx->zoom += 10;
	if (keycode == 0)
		mlx->moveX -= 0.05 / mlx->zoom;
	else if (keycode == 2)
		mlx->moveX += 0.05 / mlx->zoom;
	else if (keycode == 13)
		mlx->moveY -= 0.05 / mlx->zoom;
	else if (keycode == 1)
		mlx->moveY += 0.05 / mlx->zoom;
	calculate_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (0);
}