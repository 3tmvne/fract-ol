/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:59:28 by abdsalah          #+#    #+#             */
/*   Updated: 2025/04/06 03:38:41 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"


/*
** Function: ft_calculate_mandelbrot
** ---------------------------------
** Computes the number of iterations for a point in the Mandelbrot set.
**
** Mandelbrot equation:
**   z(n+1) = z(n)^2 + c
**   - z(n): Current complex number in the iteration.
**   - c: Initial complex number (constant).
**
** Parameters:
** - c: Complex number representing the initial point on the complex plane.
** - max_iterations: Maximum number of iterations to compute.
**
** Returns:
** - The number of iterations before the point diverges or reaches the maximum.
*/
int	ft_calculate_mandelbrot(t_complex c, int max_iterations)
{
	t_complex	z;
	int			iteration;
	double		temp;

	z.real = c.real;
	z.imag = c.imag;
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

/*
** Function: ft_calculate_julia
** ----------------------------
** Computes the number of iterations for a point in the Julia set.
**
** Julia equation:
**   z(n+1) = z(n)^2 + c
**   - z(n): Current complex number in the iteration.
**   - c: Constant complex number specific to the Julia set.
**
** Parameters:
** - z: Initial complex number (z0) to compute the iteration for.
** - fractal: Pointer to the fractal structure containing Julia parameters.
**
** Returns:
** - The number of iterations before the point diverges or reaches the maximum.
*/
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

/*
** Function: render_fractal
** ------------------------
** Renders the fractal image by iterating over each pixel and mapping it to
** the corresponding point on the complex plane.
**
** Parameters:
** - graphics: Pointer to the graphics structure containing fractal data and
**   rendering information.
**
** Notes:
** - This function calculates the color for each pixel based on the fractal
**   type and updates the image data.
*/
void	ft_render_fractal(t_graphics *graphics)
{
	t_complex	c;
	int			color;
	int			y;
	int			x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			// Map pixel coordinates to complex plane.
			c.real = (x - WIDTH / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
				+ graphics->fractal->shift_x;
			c.imag = (y - HEIGHT / 2.0) * 4.0 / WIDTH / graphics->fractal->zoom
				+ graphics->fractal->shift_y;
			color = ft_get_pixel_color(graphics, c);
			graphics->data[y * WIDTH + x] = color;
		}
	}
	mlx_put_image_to_window(graphics->mlx, graphics->win, graphics->img, 0, 0);
}
