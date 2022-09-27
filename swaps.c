/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:53:51 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/27 00:20:00 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	ft_sa fonksiyonu stackin en ustundeki iki elemani yer degistirir.
	1	2
	2	1
	3	3
*/
void	ft_sa(t_stack *a)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = temp;
		ft_printf("sa\n");
	}
}
/*
	ft_rra fonksiyonu her elemanı bir index aşağı kaydırır.
	1	3
	2	1
	3	2
*/
void	ft_rra(t_stack *a, int c)
{
	int	i;
	int	tmp;

	while (c--)
	{
		i = a->size;
		if (i >= 2)
		{
			tmp = a->array[a->size - 1];
			while (i > 1)
			{
				a->array[i - 1] = a->array[i - 2];
				i--;
			}
			a->array[0] = tmp;
			ft_printf("rra\n");
		}
	}
}
/*
	ft_pb fonksiyonu stack b nin en ustune stack a nin en ustundeki elemani ekler.
	b array pointeri bir sonraki veriyi tuttuğu için işlem öncesinde pointer 1 azaltılır. Bu sayede 0 index tutulur.
	a size azaltılır. b size arttırılır.
	a array pointeri bir sonraki veriyi tuttuğu için işlem sonrasında pointer 1 arttırılır.
*/
void	ft_pb(t_stack *a, t_stack *b, int c)
{
	while (c--)
	{
		if (a->size <= 0)
			return ;
		b->array--;
		b->array[0] = a->array[0];
		b->size++;
		a->size--;
		a->array++;
		ft_printf("pb\n");
	}
}
/*
	ft_pa fonksiyonu stack a nin en ustune stack b nin en ustundeki elemani ekler.
	a array pointeri bir sonraki veriyi tuttuğu için işlem öncesinde pointer 1 azaltılır. Bu sayede 0 index tutulur.
	b size azaltılır. a size arttırılır.
	b array pointeri bir sonraki veriyi tuttuğu için işlem sonrasında pointer 1 arttırılır.
*/
void	ft_pa(t_stack *a, t_stack *b, int c)
{
	while (c--)
	{
		if (b->size <= 0)
			return ;
		a->array--;
		a->array[0] = b->array[0];
		a->size++;
		b->size--;
		b->array++;
		ft_printf("pa\n");
	}
}
/*
	ft_ra fonksiyonu her elemanı bir index yukarı kaydırır.
	1	2
	2	3
	3	1
*/
void	ft_ra(t_stack *a, int c)
{
	int	i;
	int	count;
	int	temp;

	while (c--)
	{
		i = a->size;
		count = 0;
		temp = a->array[0];
		if (a->size > 1)
		{
			while (i-- > 1)
			{
				a->array[count] = a->array[count + 1];
				count++;
			}
			a->array[count] = temp;
			ft_printf("ra\n");
		}
	}
}
