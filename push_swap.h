/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:26:57 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/21 23:34:32 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}				t_stack;

void	init(t_stack *a, t_stack *b, char **p, char **argv);
char	*ft_strjoin_ps(char *s1, char *s2);
void	ft_split_stacks(char *str, t_stack *a, t_stack *b);
void	ft_check_repeat(t_stack *a, t_stack *b);
void	ft_check_sort(t_stack *a, t_stack *b);
void	ft_check_symbols(char *str, t_stack *a, t_stack *b);
int		ft_check(char *str, t_stack *a, t_stack *b);
void	ft_error(t_stack *a, t_stack *b, int err);
void	ft_check_sort(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_swap_trois(t_stack *a);
void	ft_rra(t_stack *a,int c);
int		ft_check_sorted(t_stack *a);
void	ft_swap_quatre(t_stack *a,t_stack *b);
void	ft_pb(t_stack *a, t_stack *b,int c);
void	ft_pa(t_stack *a, t_stack *b,int c);
void	ft_ra(t_stack *a,int c);
void	ft_swap_cinq(t_stack *a, t_stack *b);
int *ft_sort_index(t_stack *a);
int ft_pivot(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rb(t_stack *b);
void ft_index(t_stack *a);
int ft_floor(t_stack *a, int x,int len);
int	ft_min(int *p, int len);
int *ft_calc(t_stack *a, t_stack *b);
void	ft_prep_a(t_stack *a, t_stack *b, int index);
int	ft_prep_b(t_stack *a, t_stack *b, int *p);
void ft_send_to_sup(t_stack *a, t_stack *b, int *p);
void ft_sort_plus(t_stack *a,t_stack *b);
void ft_make_index(t_stack *a, int *tab);
#endif
