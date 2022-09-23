/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:49:05 by miskirik          #+#    #+#             */
/*   Updated: 2022/09/23 14:15:50 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_ps(char *s1, char *s2)
{
	char	*return_str;
	size_t	i;
	size_t	j;

	return_str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	i = -1;
	j = -1;
	while (s1[++i])
		return_str[i] = s1[i];
	return_str[i] = ' ';
	i++;
	while (s2[++j])
		return_str[i++] = s2[j];
	return_str[i] = '\0';
	free (s1);
	return (return_str);
}

void	init(t_stack *a, t_stack *b, char **p, char **argv)
{
	int	i;

	i = 0;
	a->size = 0;
	b->size = 0;
	*p[0] = '\0';
	while (argv[++i])
	{
		*p = ft_strjoin_ps(*p, argv[i]);
	}
}

void	ft_split_stacks(char *str, t_stack *a, t_stack *b)
{
	int		i;
	int		c;
	char	**splitted;

	i = 0;
	c = 0;
	splitted = ft_split(str, ' ');
	while (splitted[i++])
		a->size++;
	a->array = malloc(sizeof(int) * a->size);
	b->array = malloc(sizeof(int) * a->size);
	i = 0;
	while (splitted[i])
	{
		a->array[i] = ft_atoi(splitted[i]);
		i++;
		c++;
	}
	b->array += c;
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	ft_check_repeat(a, b);
}
int *ft_create_temp(t_stack *a)
{
	int	*temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		temp[i] = a->array[i];
		i++;
	}
	return (temp);
}

int *ft_sort_index(t_stack *a)
{
	int	i;
	int	j;
	int	*temp;
	int max;

	temp = ft_create_temp(a);
	i=0;
	while(i < a->size)
	{
		j = i;
		while (j < a->size)
		{
			if (temp[i] > temp[j])
			{
				max = temp[i];
				temp[i] = temp[j];
				temp[j] = max;
			}
			j++;
		}
		i++;
	}
	return (temp);
}
