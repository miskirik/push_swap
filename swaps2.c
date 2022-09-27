/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:09:53 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/27 03:25:16 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	ft_rrb fonksiyonu her elemanı bir index aşağı kaydırır.
	1	3
	2	1
	3	2
*/
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
/*
	ft_rb fonksiyonu her elemanı bir index yukarı kaydırır.
	1	2
	2	3
	3	1
*/
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
/*
	bu fonksiyonda a size 3 ten küçük olana kadar recursive olarak veri işlenir.
	min  ft_pivottan gelen veriyi tutar.
	pivot ise a sizeın yarısı ile pivotun toplamını tutar.
	if kontrolü ile a sizeının 3 ten küçük olması durumunda fonksiyon durdurulur.
	while döngüsü ile a size  a size - a size /2 den büyük olduğu sürece çalışır
	a stackin en üstündeki veri pivotdan küçükse ft_pb fonksiyonu ile b ye gönderilir.
	değil ise ft_ra fonksiyonu ile a stackin en üstündeki veri a stackin en altına gönderilir.
*/
void	ft_push_b(t_stack *a, t_stack *b)
{
	int	pivot;
	int	i;
	int	j;
	int	min;

	i = 0;
	j = a->size / 2;
	min = ft_pivot(a);
	pivot = a->size / 2 + ft_pivot(a);
	i = a->size;
	if (i < 3)
		return ;
	while (a->size > i - j)
	{
		if (a->array[0] < pivot)
			ft_pb(a, b, 1);
		else
			ft_ra(a, 1);
	}
	ft_push_b(a, b);
}
/*
	Bu fonksiyonda b size bitene kadar helper içerisindeki fonksiyonları çağırır.
	daha sonrasında küçük verinin indexini bulana kadar while döngüm çalışır.
	eğer index size /2 den büyük ise minumumu a size - dan çıkarıp yeni min bulunur.
	daha sonrasında mine gelene kadar while döngüsü çalışır.
	eğer min a size /2 den büyük ise ft_rra fonksiyonu ile a stackin en altındaki veri a stackin en üstüne gönderilir.
	değil ise ft_ra fonksiyonu ile a stackin en üstündeki veri a stackin en altına gönderilir.
*/
void	ft_push_a(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	min;

	min = 0;
	while (b->size)
		ft_helper(a, b);
	i = ft_pivot(a);
	j = 1;
	while (i != a->array[min])
		min++;
	if (min > a->size / 2)
	{
		min = a->size - min;
		j = 0;
	}
	while (min--)
	{
		if (j == 0)
			ft_rra(a, 1);
		else
			ft_ra(a, 1);
	}
}
