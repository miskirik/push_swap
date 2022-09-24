/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:26:52 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/23 15:59:13 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It checks for invalid symbols in the input string
 *
 * @param str the string of numbers that we're checking
 * @param a pointer to the first stack
 * @param b the stack that will be used to store the numbers that are not in order
 */
void	ft_check_symbols(char *str, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && \
		(str[i + 1] == '-' || str[i + 1] == '+'))
			ft_error(a,b, 0);
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == '-' || \
		str[i + 1] == '+'))
			ft_error(a, b, 1);
		i++;
	}
	ft_split_stacks(str, a, b);
}

/**
 * It checks the input for errors
 *
 * @param str the string to be checked
 * @param a the first stack
 * @param b the stack b
 */
void	ft_check(char *str, t_stack *a, t_stack *b)
{
	int			i;
	i = 0;
	if (!str)
		ft_error(a,b,3);
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == ' ') || \
		str[i] == '-' || str[i] == '+'))
			ft_error(a, b, 1);
		i++;
	}
	ft_check_symbols(str, a, b);
}

/**
 * It checks if there are any repeated numbers in the stack
 *
 * @param a pointer to the first stack
 * @param b the stack that is not being sorted
 */
void	ft_check_repeat(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < a->size)
	{
		while (j < a->size)
		{
			if (a->array[j] == a->array[i])
				ft_error(a, b, 2);
			j++;
		}
		i++;
		j = 1 + i;
	}
}
/**
 * It checks if the stack is sorted, if it is, it sorts it
 *
 * @param a the first stack
 * @param b the number of elements to be sorted
 */
void	ft_check_sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		if (a->array[0] > a->array[1])
			ft_sa(a);
	if (a->size == 3)
		if (ft_check_sorted(a))
			ft_swap_trois(a);
	if (a->size == 4)
		if (ft_check_sorted(a))
			ft_swap_quatre(a,b);
	if (a->size == 5)
	{
		if (ft_check_sorted(a))
			ft_swap_cinq(a,b);
	}
	if (a->size > 5 )
		if (ft_check_sorted(a))
		{
			//printf("Baaaba şimdilik bu kdar değeri alamıyorum kb");
			ft_sort_plus(a,b);
		}
}
/**
 * It checks if the stack is sorted
 *
 * @param a the stack to check
 *
 * @return 1 if the array is not sorted, 0 if it is.
 */
int ft_check_sorted(t_stack *a)
{
	int i;

	i = 0;
	while (i < a->size)
	{
		if ((i+1 !=a->size) && a->array[i] > a->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}
