/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:21:50 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/27 03:24:21 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	en küçük elemanı bulur ve en küçük elemanı bulunduğu yere getirir.
*/
void	ft_pre_a(t_stack*a, t_stack *b)
{
	int	len;
	int	sup;

	len = ft_floor(a, b->array[0], b->size + a->size);
	sup = 1;
	if (len > a->size / 2)
	{
		len = a->size - len;
		sup = 0;
	}
	while (len--)
	{
		if (!sup)
			ft_rra(a, 1);
		else
			ft_ra(a, 1);
	}
}

/*
	en küçük elemanı bulur ve en küçük elemanı bulunduğu yere getirir.
*/
int	ft_pre_b(t_stack *b, int *p)
{
	int	len;
	int	sup;
	int	end;

	sup = 1;
	len = ft_min(p, b->size);
	end = len;
	if (len > b->size / 2)
	{
		len = b->size - len;
		sup = 0;
	}
	while (len--)
	{
		if (!sup)
			ft_rrb(b);
		else
			ft_rb(b);
	}
	return (end);
}
/*
	5 > elemanlı verilerin sıralanması esnasında gereken fonksiyonları içeren bir fonksiyondur.
*/
void	ft_helper(t_stack *a, t_stack *b)
{
	int	*temp;

	temp = ft_calc(a, b);
	ft_pre_b(b, temp);
	ft_pre_a(a, b);
	ft_pa(a, b, 1);
}
