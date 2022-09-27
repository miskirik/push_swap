/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:51:38 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/27 11:42:49 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_free(a, b);
	free(p);
	return (0);
}
