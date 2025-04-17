/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozemrani <ozemrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:00:00 by ozemrani          #+#    #+#             */
/*   Updated: 2025/04/10 22:24:30 by ozemrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_isdouble(char *str)
{
	int	has_dot;

	has_dot = 0;
	if (!str || !*str)
		return (1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (has_dot)
				return (1);
			has_dot = 1;
		}
		str++;
	}
	return (1);
}

static void	ft_skip_whitespace(const char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\r'
		|| **str == '\v' || **str == '\f')
		(*str)++;
}

static int	ft_parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

double	atod(const char *str)
{
	int	sign;

	double (result), (fraction), (divisor);
	result = 0.0;
	fraction = 0.0;
	divisor = 10.0;
	ft_skip_whitespace(&str);
	sign = ft_parse_sign(&str);
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			fraction += (*str - '0') / divisor;
			divisor *= 10.0;
			str++;
		}
	}
	return (sign * (result + fraction));
}
