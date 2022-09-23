#include "push_swap.h"

void	ft_rrb(t_stack *b)
{
	int	i;
	int	sup;

	i = b->size;
	if (i > 2)
	{
		sup = b->array[b->size - 1];
		while (i > 1)
		{
			b->array[i - 1] = b->array[i - 2];
			i--;
		}
		b->array[0] = sup;
		ft_printf("rrb\n");
	}
}

void	ft_rb(t_stack *b)
{
	int	i;
	int	k;
	int	sup;

	i = b->size;
	k = 0;
	sup = b->array[0];
	if (b->size > 1)
	{
		while (i-- > 1)
		{
			b->array[k] = b->array[k + 1];
			k++;
		}
		b->array[k] = sup;
		ft_printf("rb\n");
	}
}
/**
 * It takes the first half of the stack and pushes it to the second stack
 *
 * @param a The stack that we're sorting.
 * @param b the stack to push to
 */
void ft_push_b(t_stack *a,t_stack *b)
{
	int pivot;
	int i;
	int j;
	int min;

	i=a->size;
	j= i / 2;
	min = ft_pivot(a);
	pivot=j + ft_pivot(a);
	if(i < 3)
		return ;
	//while(i > i - j)
	while(a->size > i-j)
	{
		if(a->array[0] < pivot)
			ft_pb(a,b,1);
		else
			ft_ra(a,1);
	}
	printf("girdi\n");
	ft_push_b(a,b);
}
void ft_push_a(t_stack *a,t_stack *b)
{
	int i;
	int j;
	int min;
	int *temp;

	temp=ft_calloc(sizeof(int),b->size);
	while (b->size)
	{
		ft_calc(a,b, &temp);
	}
}
