/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:44:14 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/25 20:44:46 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *a, t_stack *b, int err)
{
	(void)a;
	(void)b;
	if (err == 0)
		write(2, "Error\n", 6);
	if (err == 1)
		write(2, "Error\n", 6);
	if (err == 2)
		write(2, "Error\n", 6);
	if (err == 3)
		write(2, "Error\n", 6);
	exit(0);
}
