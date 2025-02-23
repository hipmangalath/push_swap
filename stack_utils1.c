/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:28:32 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/22 21:04:04 by haiqbal          ###   ########.fr       */
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

void	ft_index(t_stack_node *clone)
{
	int	i;

	i = 0;
	while (clone)
	{
		clone->index = i;
		clone = clone->next;
		i++;
	}
}

int	stack_sort_check(t_stack_node *a)
{
	t_stack_node	*n1;
	t_stack_node	*n2;

	n1 = a;
	while (n1->next)
	{
		n2 = n1->next;
		while (n2)
		{
			if (n1->nbr > n2->nbr)
				return (0);
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	return (1);
}

void	sort_stack(t_stack_node *clone)
{
	t_stack_node	*n1;
	t_stack_node	*n2;
	int				tmp;

	n1 = clone;
	while (n1)
	{
		n2 = n1->next;
		while (n2)
		{
			if (n1->nbr > n2->nbr)
			{
				tmp = n1->nbr;
				n1->nbr = n2->nbr;
				n2->nbr = tmp;
			}
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	ft_index(clone);
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
