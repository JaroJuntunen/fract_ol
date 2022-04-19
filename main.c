/* ************************************************************************** */
/*																			*/
/*														:::		::::::::	 */
/*	 main.c											 :+:		:+:	:+:	 */
/*													+:+ +:+		 +:+	 */
/*	 By: jjuntune <jjuntune@student.42.fr>			+#+	+:+		 +#+		*/
/*												+#+#+#+#+#+	 +#+			 */
/*	 Created: 2022/04/04 15:44:50 by jjuntune			#+#	#+#			 */
/*	 Updated: 2022/04/12 14:37:08 by jjuntune		 ###	 ########.fr		 */
/*																			*/
/* ************************************************************************** */

#include "fractol.h"

static t_mlx	create_mlx_structure(void)
{
	t_mlx	mlx;

	mlx.win_h = 1000;
	mlx.win_w = 1000;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_w,mlx.win_h, "Fractol");
	mlx.image = mlx_new_image(mlx.mlx, mlx.win_w, mlx.win_h);
	mlx.buffer = mlx_get_data_addr(mlx.image, &mlx.pixel_bits,
			&mlx.line_bytes, &mlx.endian);
	mlx.zoom = 1;
	mlx.moveX = 0;
	mlx.moveY = 0;
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	
	if (argc == 1)
		ft_putendl(argv[0]);
	mlx = create_mlx_structure();
	calculate_image(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	return 0;
}
