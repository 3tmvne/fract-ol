/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:00 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/10 22:33:00 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_calculate_mandelbrot(t_complex c, int max_iterations)
{
	t_complex	z;
	int			iteration;
	double		temp;

	z.real = 0;
	z.imag = 0;
	iteration = 0;
	while (z.real * z.real + z.imag * z.imag <= 4 && iteration < max_iterations)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		iteration++;
	}
	return (iteration);
}

int	ft_calculate_julia(t_complex z, t_fractal *fractal)
{
	int		iteration;
	double	temp;

	iteration = 0;
	while (z.real * z.real + z.imag * z.imag <= 4
		&& iteration < fractal->max_iter)
	{
		temp = z.real * z.real - z.imag * z.imag + fractal->julia_re;
		z.imag = 2 * z.real * z.imag + fractal->julia_im;
		z.real = temp;
		iteration++;
	}
	return (iteration);
}

void	ft_render_fractal(t_graphics *graphics)
{
	t_complex	c;
	int			color;
	int			y;
	int			x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
				+ graphics->fractal->shift_x;
			c.imag = (y - HEIGHT / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
				+ graphics->fractal->shift_y;
			color = ft_get_pixel_color(graphics, c);
			graphics->data[y * WIDTH + x] = color;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(graphics->mlx, graphics->win, graphics->img, 0, 0);
}
