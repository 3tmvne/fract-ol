/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:00 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/10 23:00:11 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void	ft_handle_movement(int keycode, t_graphics *graphics, double step)
{
	if (keycode == LEFT_KEY)
		graphics->fractal->shift_x -= step;
	else if (keycode == RIGHT_KEY)
		graphics->fractal->shift_x += step;
	else if (keycode == UP_KEY)
		graphics->fractal->shift_y -= step;
	else if (keycode == DOWN_KEY)
		graphics->fractal->shift_y += step;
}

static void	ft_handle_iterations(int keycode, t_graphics *graphics)
{
	if (keycode == PLUS_KEY)
		graphics->fractal->max_iter += 20;
	else if (keycode == MINUS_KEY && graphics->fractal->max_iter > 20)
		graphics->fractal->max_iter -= 20;
}

static void	ft_handle_exit(t_graphics *graphics)
{
	mlx_destroy_image(graphics->mlx, graphics->img);
	mlx_destroy_window(graphics->mlx, graphics->win);
	mlx_destroy_display(graphics->mlx);
	free(graphics->mlx);
	exit(0);
}

int	ft_key_handler(int keycode, t_graphics *graphics)
{
	double	move_step;

	move_step = 0.5 / graphics->fractal->zoom;
	if (keycode == ESC_KEY)
		ft_handle_exit(graphics);
	else
		ft_handle_iterations(keycode, graphics);
	ft_handle_movement(keycode, graphics, move_step);
	ft_render_fractal(graphics);
	return (0);
}
