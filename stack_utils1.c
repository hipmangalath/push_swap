/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:28:32 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/25 21:31:44 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*last_node(t_stack_node *a)
{
	t_stack_node	*ptr;

	if (!a)
		return (NULL);
	ptr = a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	swap(t_stack_node *a, t_stack_node *b)
{
	int	temp;

	temp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = temp;
}

void	stack_sort_check(t_stack_node *a, t_stack_node *clone)
{
	t_stack_node	*tmp;
	t_stack_node	*tmp1;

	tmp = a;
	tmp1 = clone;
	while (a != NULL)
	{
		if (clone->nbr == a->nbr)
		{
			a = a->next;
			clone = clone->next;
		}
		else
			return ;
	}
	free_stack(tmp);
	free_stack(tmp1);
	exit(0);
}

void	sort_stack(t_stack_node *clone)
{
	int		i;
	t_stack_node	*tmp;

	if (!clone)
		exit(1);
	tmp = clone;
	while (clone->next != NULL)
	{
		if (clone->nbr > clone->next->nbr)
		{
			swap(clone, clone->next);
			clone = tmp;
		}
		else
			clone = clone->next;
	}
	clone = tmp;
	i = 0;
	while (clone != NULL)
	{
		clone->index = i;
		i++;
		clone = clone->next;
	}
}

void	assign_index_stack(t_stack_node *a, t_stack_node *c)
{
	t_stack_node	*tmp;

	tmp = a;
	while (c)
	{
		while (a)
		{
			if (c->nbr == a->nbr)
			{
				a->index = c->index;
				break ;
			}
			a = a->next;
		}
		a = tmp;
		c = c->next;
	}
}
