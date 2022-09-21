#include "push_swap.h"

void ft_sa(t_stack *a)
{
	int temp;
	if (a->size > 1)
	{
		temp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = temp;
		ft_printf("sa\n");
	}
}

void	ft_rra(t_stack *a,int c)
{
	while(c--)
	{
		int	i;
		int	tmp;
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
void	ft_pb(t_stack *a, t_stack *b,int c)
{
	while(c--)
	{
	if(a->size <=0)
		return;
	b->array--;
	b->array[0]=a->array[0];
	b->size++;
	a->size--;
	a->array++;
	ft_printf("pb\n");
	}
}
void	ft_pa(t_stack *a, t_stack *b,int c)
{
	while(c--)
	{
	if(b->size <=0)
		return;
	a->array--;
	a->array[0]=b->array[0];
	a->size++;
	b->size--;
	b->array++;
	ft_printf("pa\n");
	}
}
void	ft_ra(t_stack *a,int c)
{
	int i;
	int temp;
	while(c--)
	{
		i =0;
		while (i < a->size - 1)
		{
			temp = a->array[i + 1];
			a->array[i + 1] = a->array[i];
			a->array[i] = temp;
			++i;
		}
	}
	ft_printf("ra\n");
}
