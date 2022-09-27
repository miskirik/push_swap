/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:51:38 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/26 23:38:23 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	A ve B olarak iki stack olusturulur.
	init fonksiyonunda ilk veriler olusturulur.
	ft_check fonksiyonunda verilerin dogrulugu kontrol edilir.
	ft_check_sort fonksiyonunda veriler siralanir.
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*p;

	if (argc < 1)
		exit (0);
	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	p = malloc(sizeof(char));
	init(a, b, &p, argv);
	ft_check(p, a, b);
	ft_check_sort(a, b);
}
