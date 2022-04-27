/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:37:11 by jjuntune          #+#    #+#             */
/*   Updated: 2022/04/27 12:29:04 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_mlx
{
	int		win_h;
	int		win_w;
	void	*mlx;
	void	*win;
	int		fractal_type;
	int		*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	double	zoom;
	double	movex;
	double	movey;
	double	julia_cre;
	double	julia_cim;
	int		lock;
}			t_mlx;

typedef struct s_fractal
{
	double	cre;
	double	cim;
	double	zre;
	double	zim;
	double	tempre;
	double	tempim;
	int		color;
	int		maxiterations;
}			t_fractal;

int		key_hook(int keycode, t_mlx *mlx);
int		mouse_events(int button, int x, int y, t_mlx *mlx);
int		mouse_movement(int x, int y, t_mlx *mlx);
void	calculate_image(t_mlx	*mlx);
void	calculate_mandelbrot(t_mlx	*mlx);
void	calculate_julia(t_mlx	*mlx);
void	calculate_burning_ship(t_mlx	*mlx);
int		print_usage(void);

#endif