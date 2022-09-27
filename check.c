/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:26:52 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/27 03:22:24 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	Verilerin sembolleri kontrol edilir.
	--9 ++9 -+9 9* +*9 gibi hatalı sembol kullanımı durumunda error verilir.
	Verinin sorunsuz olması durumunda ft_split_stacks fonksiyonuna gonderilir.
*/
void	ft_check_symbols(char *str, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && \
		(str[i + 1] == '-' || str[i + 1] == '+'))
			ft_error(a, b, 0);
		if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] == '-' || \
		str[i + 1] == '+'))
			ft_error(a, b, 1);
		i++;
	}
	ft_split_stacks(str, a, b);
}
/*
	Verilerin doğru bir biçimde girildiğini kontrol eder.
	Hata olması durumunda error döndürür.
	Hata olmaması durumunda ft_check_symbols fonksiyonuna yollar.
*/
void	ft_check(char *str, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (!str)
		ft_error(a, b, 3);
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] == ' ') || \
		str[i] == '-' || str[i] == '+'))
			ft_error(a, b, 1);
		i++;
	}
	ft_check_symbols(str, a, b);
}
/*
	stack içerisinde a size kadar çalışarak verinin içerisinde tekrar eden veri olup olmadığı kontrol edilir.
	tekrar eden veri varsa error döndürür.
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
/*
	Sorunsuz olduğu bilinen verilerin sıralanması için gerekli fonksiyonlara yollar.
	Veri eğer 2 elemanlı ise sıralama yapılır.
	Veri eğer 2> elemanlı ise ilk olarak girilen verinin sıralı olup olmadığı kontrol edilir.
	Veri sıralı değil ise sıralama fonksiyonuna yollanır.
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
			ft_swap_quatre(a, b);
	if (a->size == 5)
	{
		if (ft_check_sorted(a))
			ft_swap_cinq(a, b);
	}
	if (a->size > 5)
		if (ft_check_sorted(a))
			ft_sort_plus(a, b);
}
/*
	Verinin sıralı olup olmadığını kontrol eder.
	Veri sıralı ise 1 döndürür.
	Veri sıralı değil ise 0 döndürür.
*/
int	ft_check_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if ((i + 1 != a->size) && a->array[i] > a->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}
