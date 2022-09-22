/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:29:19 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/22 04:09:51 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_make_index(t_stack *a, int *tab)
{
	int i;
	int j;

	i=0;
	while (i < a->size)
	{
		j = 0;
		while (j < a->size)
		{
			if (a->array[i] == tab[j])
				a->array[i] = j;
			j++;
		}
		i++;
	}
}
int ft_pivot(t_stack *a)
{
	int i;
	int min;

	i=0;
	min=INT_MIN;
	while (i < a->size)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	return(min);
}
