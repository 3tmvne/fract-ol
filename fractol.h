/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:47:09 by almatsch          #+#    #+#             */
/*   Updated: 2025/03/31 01:02:31 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITER 42

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_cmp;

typedef struct s_fractal
{
	char		*type;
	mlx_t		*mlx;
	mlx_image_t	*imag;
	t_cmp		z;
	t_cmp		c;
	int			color;
	double		zoom;
	int			width;
	int			height;
}				t_fract;

double			ft_atod(char *str);
void			error_msg(void);
void			wrong_args(void);
void			julia_init(t_fract *julia, double val_1, double val_2);
int				iter_julia(t_fract *julia);
unsigned int	get_color(int i, int color);
void			mandel_init(t_fract *mandel);
void			key_hooks(struct mlx_key_data key_data, void *param);
void			key_init(t_fract *fract);
void			scroll_hook(double xdelta, double ydelta, void *param);
void			render_fract(t_fract *fract);
void			resize_hook(int width, int height, void *param);

#endif
