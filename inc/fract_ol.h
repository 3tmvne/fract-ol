/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:00 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/10 22:56:29 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 700
# define HEIGHT 700
# define MAX_ITER 50
# define ESC_KEY 65307
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define LEFT_CLICK 1
# define ZOOM_FACTOR 1.1
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364
# define PLUS_KEY 65451
# define MINUS_KEY 65453

typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_fractal
{
	char		*name;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_re;
	double		julia_im;
	int			max_iter;
}				t_fractal;

typedef struct s_graphics
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			line_len;
	int			endian;
	t_fractal	*fractal;
}				t_graphics;

void			ft_input_handling(int argc, char **argv, t_fractal *fractal);
int				ft_close_window(t_graphics *graphics);
void			ft_init_fractal(t_fractal *fractal);
void			ft_init_graphics(t_graphics *graphics, t_fractal *fractal);
void			ft_render_fractal(t_graphics *graphics);
int				ft_key_handler(int keycode, t_graphics *graphics);
int				ft_mouse_handler(int button, int x, int y,
					t_graphics *graphics);
void			ft_error_exit(char *message);
void			ft_free_graphics(t_graphics *graphics);
int				ft_get_pixel_color(t_graphics *graphics, t_complex c);
int				ft_calculate_julia(t_complex z, t_fractal *fractal);
int				ft_calculate_mandelbrot(t_complex c, int max_iterations);
int				ft_get_color(int color, t_fractal *fractal);
size_t			ft_strcmp(const char *s1, const char *s2);
void			ft_putendl_fd(char *s, int fd);
double			atod(const char *str);
int				ft_isdouble(char *str);
int				ft_isdigit(int c);

#endif