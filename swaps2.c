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
void ft_push_b(t_stack *a,t_stack *b)
{
	int pivot;
	int i;
	int j;
	int min;

	i=a->size;
	j= i / 2;
	min = ft_pivot(a);
	pivot=j + min;
	if(i < 3)
		return ;
	while(i > i-j)
	{
		if(a->array[0] < pivot)
			ft_pb(a,b,1);
		else
			ft_ra(a,1);
	}
	ft_push_b(a,b);
}
void ft_push_a(t_stack *a,t_stack *b)
{
	int i;
	int j;
	int min;

	i=b->size;
	j= i / 2;
	min = ft_pivot(b);
	//burada kaldım buradan devam etmeliyim bb :)
}
