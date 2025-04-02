/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:46:36 by almatsch          #+#    #+#             */
/*   Updated: 2025/03/30 23:02:52 by almatsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_values(char **arv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arv[2][i])
	{
		if ((arv[2][i] >= '0' && arv[2][i] <= '9') || \
		arv[2][i] == '.' || arv[2][i] == '-')
			i++;
		else
			return (0);
	}
	while (arv[3][j])
	{
		if ((arv[3][j] >= '0' && arv[3][j] <= '9') || \
		arv[3][j] == '.' || arv[2][i] == '-')
			j++;
		else
			return (0);
	}
	return (1);
}

int	check_args(int arc, char **arv)
{
	if (ft_strncmp(arv[1], "mandelbrot", 10) && ft_strncmp(arv[1], "julia", 5))
		return (0);
	if (!ft_strncmp(arv[1], "julia", 5))
	{
		if (arc != 4)
			return (0);
		if (!check_values(arv))
			return (0);
		if (ft_atod(arv[2]) > 2.0 || ft_atod(arv[2]) < -2.0)
			return (0);
		if (ft_atod(arv[3]) > 2.0 || ft_atod(arv[3]) < -2.0)
			return (0);
	}
	return (1);
}

int	main(int arc, char **arv)
{
	t_fract	fract;

	if (arc > 4 || arc < 2)
		wrong_args();
	if (!check_args(arc, arv))
		wrong_args();
	if (!ft_strncmp(arv[1], "mandelbrot", 10))
		mandel_init(&fract);
	else if (!ft_strncmp(arv[1], "julia", 5))
		julia_init(&fract, ft_atod(arv[2]), ft_atod(arv[2]));
	return (0);
}
