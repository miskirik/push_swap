/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:04:49 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/24 16:44:20 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long long	numb;

	i = 0;
	sign = 1;
	numb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = (str[i] - '0') + (numb * 10);
		i++;
	}
	if ((numb * sign) > 2147483647 || (numb * sign) < -2147483648)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (numb * sign);
}
