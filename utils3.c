/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:21:50 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/27 11:47:52 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_helper(t_stack *a, t_stack *b)
{
	int	*temp;

	temp = ft_calc(a, b);
	ft_pre_b(b, temp);
	free(temp);
	ft_pre_a(a, b);
	ft_pa(a, b, 1);
}

void	ft_free(t_stack *a, t_stack *b)
{
	b->array = b->start;
	free(b->array);
	free(b);
	free(a->array);
	free(a);
	exit (0);
}
