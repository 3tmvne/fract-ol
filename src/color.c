/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:00 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/09 21:58:21 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_get_color(int color, t_fractal *fractal)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	t = (double)color / fractal->max_iter;
	red = (int)(2 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color = (red << 16) | (green << 8) | blue;
	return (color);
}

int	ft_get_pixel_color(t_graphics *graphics, t_complex c)
{
	int	color;

	color = 0;
	if (graphics->fractal->name && ft_strcmp(graphics->fractal->name,
			"mandelbrot") == 0)
		color = ft_calculate_mandelbrot(c, graphics->fractal->max_iter);
	else if (graphics->fractal->name && ft_strcmp(graphics->fractal->name,
			"julia") == 0)
		color = ft_calculate_julia(c, graphics->fractal);
	if (color == graphics->fractal->max_iter)
		color = 0x000000;
	else
	{
		color = ft_get_color(color, graphics->fractal);
	}
	return (color);
}
