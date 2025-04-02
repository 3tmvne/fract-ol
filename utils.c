/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:43:35 by almatsch          #+#    #+#             */
/*   Updated: 2025/03/31 00:56:51 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	wrong_args(void)
{
	ft_putstr_fd("Wrong Arguments !\n", 1);
	ft_putstr_fd("Enter one of the Options:\n", 1);
	ft_putstr_fd("mandelbrot\n", 1);
	ft_putstr_fd("julia <value 1> <value 2>\n", 1);
	ft_putstr_fd ("julia values needs to be doubles and <= 2 and >= -2 \n", 1);
	exit(EXIT_FAILURE);
}

unsigned int	get_color(int i, int color)
{
	unsigned int	colors[15];

	colors[0] = 0x000000FF;
	colors[1] = 0x111111FF;
	colors[2] = 0x222222FF;
	colors[3] = 0x333333FF;
	colors[4] = 0x444444FF;
	colors[5] = 0x555555FF;
	colors[6] = 0x666666FF;
	colors[7] = 0x777777FF;
	colors[8] = 0x888888FF;
	colors[9] = 0x999999FF;
	colors[10] = 0xAAAAAAAA;
	colors[11] = 0xBBBBBBFF;
	colors[12] = 0xCCCCCCFF;
	colors[13] = 0xDDDDDDFF;
	colors[14] = 0xFFFFFFFF;
	if (i == MAX_ITER)
		return (colors[14]);
	else
		return (colors[(i * 2 + color) % 15]);
}

void	error_msg(void)
{
	ft_putstr_fd("mlx failed", 1);
	exit(1);
}

double	get_double(char *str, int i)
{
	double	n;
	double	factor;

	n = 0;
	factor = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			factor /= 10;
			n += (str[i] - '0') * factor;
			i++;
		}
	}
	return (n);
}

double	ft_atod(char *str)
{
	int		i;
	double	count;
	double	nbr;

	i = 0;
	nbr = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count = count * -1;
		i++;
	}
	nbr = get_double(str, i);
	return (nbr * count);
}
