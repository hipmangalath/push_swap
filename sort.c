/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:02:44 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/25 20:03:51 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack_node **a)
{
	int	max;

	max = find_max_node(*a);
	if ((*a)->nbr == max)
		ra(a);
	else if ((*a)->next->nbr == max)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	four_sort(t_stack_node **a, t_stack_node **b)
{
	int	min;

	min = find_min_node(*a);
	while (*a)
	{
		if ((*a)->nbr == min)
		{
			pb(a, b);
			break ;
		}
		else
			ra(a);
	}
	three_sort(a);
	pa(a, b);
}

void	five_sort(t_stack_node **a, t_stack_node **b)
{
	int	min;
	int	max;
	int	i;

	min = find_min_node(*a);
	max = find_max_node(*a);
	i = 5;
	while (i--)
	{
		if ((*a)->nbr == min || (*a)->nbr == max)
			pb(a, b);
		else
			ra(a);
	}
	three_sort(a);
	pa(a, b);
	pa(a, b);
	if ((*a)->nbr == min)
	{
		sa(a);
		ra(a);
	}
	else
		ra(a);
}

void	radix_sort(t_stack_node **a, t_stack_node **b, int size)
{
	int	bit_len;
	int	i;
	int	j;

	i = 0;
	bit_len = 0;
	while (((size - 1) >> bit_len) != 0)
		bit_len++;
	while (i < bit_len)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

void	sort(t_stack_node *a, t_stack_node *b)
{
	int	size;

	size = ft_stacksize(a);
	if (size == 2)
		sa(&a);
	else if (size == 3)
		three_sort(&a);
	else if (size == 4)
		four_sort(&a, &b);
	else if (size == 5)
		five_sort(&a, &b);
	else
		radix_sort(&a, &b, size);
}
