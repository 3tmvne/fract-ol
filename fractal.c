/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:34:20 by almatsch          #+#    #+#             */
/*   Updated: 2025/03/31 01:13:08 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_fract *julia, double val_1, double val_2)
{
	julia->mlx = mlx_init(WIDTH, HEIGHT, "Julia", true);
	if (julia->mlx == NULL)
		exit(1);
	julia->imag = mlx_new_image(julia->mlx, WIDTH, HEIGHT);
	if (julia->imag == NULL)
	{
		mlx_terminate(julia->mlx);
		error_msg();
	}
	julia->width = WIDTH;
	julia->height = HEIGHT;
	julia->type = "julia";
	julia->color = 0xFF0000;
	julia->zoom = 4.0;
	julia->c.real = val_1;
	julia->c.imag = val_2;
	key_init(julia);
	mlx_resize_hook(julia->mlx, resize_hook, julia);
	render_fract(julia);
	mlx_image_to_window(julia->mlx, julia->imag, 0, 0);
	mlx_loop(julia->mlx);
}

void	mandel_init(t_fract *mandel)
{
	mandel->mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true);
	if (mandel->mlx == NULL)
		exit(1);
	mandel->imag = mlx_new_image(mandel->mlx, WIDTH, HEIGHT);
	if (mandel->imag == NULL)
	{
		mlx_terminate(mandel->mlx);
		error_msg();
	}
	mandel->width = WIDTH;
	mandel->height = HEIGHT;
	mandel->type = "mandelbrot";
	mandel->color = 0xFF0000;
	mandel->zoom = 4.0;
	mandel->c.real = 0.0;
	mandel->c.imag = 0.0;
	key_init(mandel);
	mlx_resize_hook(mandel->mlx, resize_hook, mandel);
	render_fract(mandel);
	mlx_image_to_window(mandel->mlx, mandel->imag, 0, 0);
	mlx_loop(mandel->mlx);
}

int	iter_mandel(t_fract *mandel)
{
	int		i;
	double	tmp;
	t_cmp	c;
	t_cmp	z;

	c.real = mandel->z.real;
	c.imag = mandel->z.imag;
	z.real = mandel->z.real;
	z.imag = mandel->z.imag;
	i = 0;
	while (z.real * z.real + z.imag * z.imag < 4 && i < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		i++;
	}
	return (i);
}

int	iter_julia(t_fract *julia)
{
	int		i;
	double	tmp;
	t_cmp	c;
	t_cmp	z;

	c.real = julia->c.real;
	c.imag = julia->c.imag;
	z.real = julia->z.real;
	z.imag = julia->z.imag;
	i = 0;
	while (z.real * z.real + z.imag * z.imag < 4 && i < MAX_ITER)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		i++;
	}
	return (i);
}

void	render_fract(t_fract *fract)
{
	int		x;
	int		y;
	int		i;
	double	scale;

	y = 0;
	scale = fract->zoom / fract->width;
	while (y < fract->height)
	{
		x = 0;
		while (x < fract->width)
		{
			fract->z.real = (x - fract->width / 2.0) * scale;
			fract->z.imag = (y - fract->height / 2.0) * scale;
			if (!ft_strncmp(fract->type, "mandelbrot", 10))
				i = iter_mandel(fract);
			else if (!ft_strncmp(fract->type, "julia", 10))
				i = iter_julia(fract);
			mlx_put_pixel(fract->imag, x, y, get_color(i, fract->color));
			x++;
		}
		y++;
	}
}
