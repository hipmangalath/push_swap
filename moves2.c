/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:49:02 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/23 18:31:43 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **a)
{
	t_stack_node	*tmp;

	if (ft_stacksize(*a) < 2 || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ra(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (ft_stacksize(*a) < 2 || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = last_node(*a);
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (ft_stacksize(*a) < 2 || !*a)
		return ;
	tmp = *a;
	last = last_node(*a);
	if (!last)
		return ;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
