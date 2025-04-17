/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 21:38:58 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/10 23:33:56 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_init_fractal(t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->max_iter = MAX_ITER;
}

static void	ft_init_graphics_struct(t_graphics *graphics)
{
	graphics->mlx = NULL;
	graphics->win = NULL;
	graphics->img = NULL;
	graphics->data = NULL;
	graphics->bpp = 0;
	graphics->line_len = 0;
	graphics->endian = 0;
	graphics->fractal = NULL;
}

void	ft_init_graphics(t_graphics *graphics, t_fractal *fractal)
{
	ft_init_graphics_struct(graphics);
	graphics->mlx = mlx_init();
	if (!graphics->mlx)
		ft_error_exit("Failed to initialize MLX");
	graphics->win = mlx_new_window(graphics->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!graphics->win)
	{
		ft_free_graphics(graphics);
		ft_error_exit("Failed to create MLX window");
	}
	graphics->img = mlx_new_image(graphics->mlx, WIDTH, HEIGHT);
	if (!graphics->img)
	{
		ft_free_graphics(graphics);
		ft_error_exit("Failed to create MLX image");
	}
	graphics->data = (int *)mlx_get_data_addr(graphics->img, &graphics->bpp,
			&graphics->line_len, &graphics->endian);
	if (!graphics->data)
	{
		ft_free_graphics(graphics);
		ft_error_exit("Failed to get image data address");
	}
	graphics->fractal = fractal;
}

void	ft_input_handling(int argc, char **argv, t_fractal *fractal)
{
	fractal->name = argv[1];
	if (!(ft_strcmp(fractal->name, "julia")))
	{
		if (!(ft_isdouble(argv[2])) || !(ft_isdouble(argv[3])) || argc != 4)
		{
			ft_putendl_fd("Usage: ./fractol julia -0.8 0.156", 2);
			exit(EXIT_FAILURE);
		}
		fractal->julia_re = atod(argv[2]);
		fractal->julia_im = atod(argv[3]);
	}
	else if (!ft_strcmp(fractal->name, "mandelbrot") && argc != 2)
	{
		ft_putendl_fd("Usage: ./fractol mandelbrot", 2);
		exit(EXIT_FAILURE);
	}
}
