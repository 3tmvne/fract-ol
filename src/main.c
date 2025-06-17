/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:38:38 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/10 22:54:40 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_graphics	graphics;

	if ((argc != 2 && argc != 4)
		|| (ft_strcmp(argv[1], "mandelbrot") && ft_strcmp(argv[1], "julia")))
	{
		ft_putendl_fd("Available fractals: mandelbrot, julia", 2);
		exit(EXIT_FAILURE);
	}
	ft_input_handling(argc, argv, &fractal);
	ft_init_fractal(&fractal);
	ft_init_graphics(&graphics, &fractal);
	ft_render_fractal(&graphics);
	mlx_key_hook(graphics.win, ft_key_handler, &graphics);
	mlx_mouse_hook(graphics.win, ft_mouse_handler, &graphics);
	mlx_hook(graphics.win, 17, 0, ft_close_window, &graphics);
	mlx_loop(graphics.mlx);
	return (0);
}
