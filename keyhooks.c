/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:10:14 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/27 12:42:01 by jjuntune         ###   ########.fr       */
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
	calculate_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (0);
}
