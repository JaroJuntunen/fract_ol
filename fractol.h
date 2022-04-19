/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:37:11 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/19 19:42:05 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct s_mlx
{
	int		win_h;
	int		win_w;
	void	*mlx;
	void	*win;
	int		*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	double	zoom;
	double	moveX;
	double	moveY;
}			t_mlx;

typedef struct s_julia
{
	double	cRe;
	double	cIm;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	int		color;
}			t_julia;

int	key_hook(int keycode, t_mlx *mlx);
void	calculate_image(t_mlx	*mlx);
#endif