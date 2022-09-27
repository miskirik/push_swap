/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:44:57 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/27 01:00:25 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	Veri sayisi 3 ise bu fonksiyon calisir.
	birinci eleman eğer ikiden büyükse ve birinci eleman üçüncü elemandan büyükse
	ve ikinci eleman üçüncü elemandan küçükse rra komutu kullanilir.
	ilk    rra     rra
	9		8		7
	7		9		8
	8		7		9
	değil ise ilk sa komutu kullanilir. ardından rra komutu kullanilir.
	ilk    sa      rra
	9		8		7
	8		9		8
	7		7		9

	ikinci eleman eğer birinci elemandan büyükse ve ikinci eleman üçüncü elemandan büyükse
	ve birinci eleman üçüncü elemandan büyükse rra komutu kullanilir.
	ilk    rra
	7		6
	8		7
	6		8

	üçüncü eleman eğer ikinci elemandan büyükse ve 3üncü eleman birinci elemandan büyükse
	ve ikinci eleman birinci elemandan küçükse sa komutu kullanilir.
	ilk    sa
	8		7
	7		8
	9		9
*/
void	ft_swap_trois(t_stack *a)
{
	if (a->array[0] > a->array[1] && a->array[0] > a->array[2])
	{
		if (a->array[1] < a->array[2])
			ft_rra(a, 2);
		else
		{
			ft_sa(a);
			ft_rra(a, 1);
		}
	}
	else if (a->array[1] > a->array[0] && a->array[1] > a->array[2])
	{
		if (a->array[0] > a->array[2])
			ft_rra(a, 1);
		else
		{
			ft_rra(a, 1);
			ft_sa(a);
		}
	}
	else if (a->array[2] > a->array[1] && a->array[2] > a->array[0])
		if (a->array[1] < a->array[0])
			ft_sa(a);
}
/*
	Veri sayısı eğer 4 ise bu fonksiyon calisir.
	Verinin ilk elemanı pb fonksiyonu ile b stackine atılır.
	daha sonrasında ft_swap_trois fonksiyonu ile veriler siralanir.
	son olarak pa fonksiyonu ile b stackinden a stackine geri atılır.
	ra komutu ile verinin ilk elemanı sona atılır.
	eğer dördüncü eleman ikinci elemandan büyükse ve dördüncü eleman üçüncü elemandan küçükse
	pb yapılarak b stackine atılır. sa fonksiyonu ile ilk iki eleman yer degistirir. ardından veri a stackine geri atılır.
	ilk     pb      pb      sa      pa      pa
	5		6		8		7		6		5
	6		8		7		8		7		6
	8		7						8		7
	7										8
	eğer dördüncü eleman birinci elemandan küçükse rra komutu çalıştırılır.
	ilk     rra
	6		5
	7		6
	8		7
	5		8
	değil ise ilk rra komutu kullanılır daha sonrasında sa komutu kullanilir.
	ilk     rra     sa
	6		7		6
	8		6		7
	9		8		8
	7		9		9
*/
void	ft_swap_quatre(t_stack *a, t_stack *b)
{
	ft_pb(a, b, 1);
	ft_swap_trois(a);
	ft_pa(a, b, 1);
	ft_ra(a, 1);
	if (a->array[3] > a->array[1])
	{
		if (a->array[3] < a->array[2])
		{
			ft_pb(a, b, 2);
			ft_sa(a);
			ft_pa(a, b, 2);
		}
	}
	else
	{
		if (a->array[3] < a->array[0])
			ft_rra(a, 1);
		else
		{
			ft_rra(a, 1);
			ft_sa(a);
		}
	}
}
/*
	Veri sayısı eğer 5 ise bu fonksiyon çalışır.
	minimum değer olarak ilk elemanı seçilir.
	while döngüsü ile minimum değer ve değerin hangi indexte olduğu bulunur.
	eğer a size / 2 index verisine eşit veya küçük ise ilk eleman en küçük sayıya eşitlenene kadar rra atılır.
	değil ise ra atılarak ilk eleman en küçük sayıya eşitlenene kadar atılır.
	en küçük veri b stackine atılır.
	sonrasında ft_swap_quatre fonksiyonu ile veriler siralanır.
	sıralanmış verinin ilk elemanına önceden bulunup b stackine atılan en küçük sayı pa fonksiyonu ile geri atılır.
*/
void	ft_swap_cinq(t_stack *a, t_stack *b)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	index = 0;
	min = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] < min)
		{
			index = i;
			min = a->array[i];
		}
		i++;
	}
	if (a->size / 2 <= index)
		while (a->array[0] != min)
			ft_rra(a, 1);
	else
		while (a->array[0] != min)
			ft_ra(a, 1);
	ft_pb(a, b, 1);
	ft_swap_quatre(a, b);
	ft_pa(a, b, 1);
}
/*
	eğer veri 5 adetten fazla ise bu fonksiyon çalışır.
	ilk olarak tab pointeri içerisine verileri indexleyebilmek amacı ile ft_sort_index ile veriler sıralanır.
	sırlanan veriler ft_make_index fonksiyonu ile indexlenir.
	sonrasında sıralama algoritmasını içeren ft_push_b ve ft_push_a fonksiyonları çalıştırılır.
*/
void	ft_sort_plus(t_stack *a, t_stack *b)
{
	int	*tab;

	tab = ft_sort_index(a);
	ft_make_index(a, tab);
	ft_push_b(a, b);
	ft_push_a(a, b);
}
