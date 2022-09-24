#include "push_swap.h"

void ft_swap_trois(t_stack *a)
{
	if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
	{
		if (a->array[1] < a->array[2])
		{
			ft_rra(a,2);
		}
		else
		{
			ft_sa(a);
			ft_rra(a,1);
		}
	}
	else if (a->array[1] > a->array[0] && a->array[1] > a->array[2])
	{
		if (a->array[0] > a->array[2])
			ft_rra(a,1);
		else
		{
			ft_rra(a,1);
			ft_sa(a);
		}
	}
	else if (a->array[2] > a->array[1] && a->array[2] > a->array[0])
		if (a->array[1] < a->array[0])
			ft_sa(a);
}
void	ft_swap_quatre(t_stack *a, t_stack *b)
{
	ft_pb(a, b,1);
	ft_swap_trois(a);
	ft_pa(a, b,1);
	ft_ra(a,1);
	if (a->array[3] > a->array[1])
	{
		if (a->array[3] < a->array[2])
		{
				ft_pb(a, b,2);
				ft_sa(a);
				ft_pa(a, b,2);
		}
	}
	else
	{
		if (a->array[3] < a->array[0])
			ft_rra(a,1);
		else
		{
			ft_rra(a,1);
			ft_sa(a);
		}
	}
}

void	ft_swap_cinq(t_stack *a, t_stack *b)
{
	int i;
	int index;
	int min;

	i=0;
	index=0;
	min=a->array[0];
	while(i<a->size)
	{
		if(a->array[i]< min)
		{
			index=i;
			min=a->array[i];
		}
		i++;
	}
	if(a->size / 2 <= index)
		while(a->array[0] != min)
			ft_rra(a,1);
	else
		while(a->array[0] != min)
			ft_ra(a,1);
	ft_pb(a, b,1);
	ft_swap_quatre(a,b);
	ft_pa(a, b,1);
}

void ft_sort_plus(t_stack *a,t_stack *b)
{
	int *tab;
	tab=ft_sort_index(a);
	ft_make_index(a,tab);
	ft_push_b(a,b);
	ft_push_a(a,b);
}
