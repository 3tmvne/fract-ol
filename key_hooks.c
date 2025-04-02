/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:09:30 by almatsch          #+#    #+#             */
/*   Updated: 2025/03/31 01:04:51 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_init(t_fract *fract)
{
	mlx_key_hook(fract->mlx, key_hooks, fract);
	mlx_scroll_hook(fract->mlx, scroll_hook, fract);
}

void	close_window(t_fract *fract)
{
	mlx_terminate(fract->mlx);
	exit(EXIT_SUCCESS);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fract	*fract;

	(void)xdelta;
	fract = (t_fract *)param;
	if (ydelta > 0)
		fract->zoom *= 1.1;
	else if (ydelta < 0)
		fract->zoom /= 1.1;
	render_fract(fract);
}

void	resize_hook(int width, int height, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	mlx_delete_image(fract->mlx, fract->imag);
	fract->imag = mlx_new_image(fract->mlx, width, height);
	if (!fract->imag)
		error_msg();
	fract->height = height;
	fract->width = width;
	render_fract(fract);
	mlx_image_to_window(fract->mlx, fract->imag, 0, 0);
}

void	key_hooks(struct mlx_key_data key_data, void *param)
{
	t_fract	*fract;

	fract = (t_fract *)param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_PRESS)
		close_window(fract);
	render_fract(fract);
}
