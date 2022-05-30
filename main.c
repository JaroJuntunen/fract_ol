/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuntune <jjuntune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:03:57 by jjuntune          #+#    #+#             */
/*   Updated: 2022/05/17 16:29:38 by jjuntune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_usage(void)
{
	int		fd;
	int		i;
	int		ret;
	char	*str;

	ret = 1;
	i = 0;
	fd = open("usage.txt", O_RDONLY);
	while (ret == 1 && fd > -1)
	{
		ret = get_next_line(fd, &str);
		if (ret == 1)
		{
			ft_putendl(str);
			ft_strdel(&str);
		}
		i++;
	}
	if (fd > -1)
		close(fd);
	if (ret == -1)
		return (-1);
	exit(0);
}

static void	find_right_fractal(char *argument, t_mlx *mlx)
{
	if (ft_strcmp("Julia", argument) == 0
		|| ft_strcmp("julia", argument) == 0)
	{
		mlx->fractal_type = 1;
		mlx->iter = 300;
	}
	else if (ft_strcmp("Mandelbrot", argument) == 0
		|| ft_strcmp("mandelbrot", argument) == 0)
	{
		mlx->fractal_type = 2;
		mlx->iter = 300;
	}
	else if (ft_strcmp("Burningship", argument) == 0
		|| ft_strcmp("burningship", argument) == 0)
	{
		mlx->fractal_type = 3;
		mlx->iter = 100;
	}
	else
		mlx->fractal_type = 0;
}

static t_mlx	create_mlx_structure(char *argument)
{
	t_mlx	mlx;

	mlx.win_h = 500;
	mlx.win_w = 500;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_w, mlx.win_h, "Fractol");
	mlx.image = mlx_new_image(mlx.mlx, mlx.win_w, mlx.win_h);
	mlx.buffer = mlx_get_data_addr(mlx.image, &mlx.pixel_bits,
			&mlx.line_bytes, &mlx.endian);
	find_right_fractal(argument, &mlx);
	mlx.zoom = 10;
	mlx.movex = 0;
	mlx.movey = 0;
	mlx.julia_cre = -0.7;
	mlx.julia_cim = 0.27015;
	mlx.lock = 1;
	return (mlx);
}

void	calculate_image(t_mlx	*mlx)
{
	if (mlx->fractal_type == 0)
		print_usage();
	if (mlx->fractal_type == 1)
		calculate_julia(mlx);
	if (mlx->fractal_type == 2)
		calculate_mandelbrot(mlx);
	if (mlx->fractal_type == 3)
		calculate_burning_ship(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 1 || argc > 2)
		if (print_usage() == -1)
			return (1);
	mlx = create_mlx_structure(argv[1]);
	calculate_image(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 4, 0, mouse_events, &mlx);
	mlx_hook(mlx.win, 6, 0, mouse_movement, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
