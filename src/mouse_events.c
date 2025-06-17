/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:00 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/10 23:06:31 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_zoom(t_graphics *graphics, double zoom_factor)
{
	double	width;
	double	height;
	double	new_width;
	double	new_height;

	width = WIDTH / graphics->fractal->zoom;
	height = HEIGHT / graphics->fractal->zoom;
	new_width = width / zoom_factor;
	new_height = height / zoom_factor;
	graphics->fractal->zoom *= zoom_factor;
	graphics->fractal->shift_x += (width - new_width) / (2.0 * WIDTH);
	graphics->fractal->shift_y += (height - new_height) / (2.0 * HEIGHT);
}

int	ft_mouse_handler(int button, int x, int y, t_graphics *graphics)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		ft_zoom(graphics, ZOOM_FACTOR);
	else if (button == MOUSE_SCROLL_DOWN)
		ft_zoom(graphics, 1.0 / ZOOM_FACTOR);
	ft_render_fractal(graphics);
	return (0);
}
