/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 21:15:45 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/25 19:59:58 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node *a)
{
	t_stack_node	*tmp;

	if (a == NULL)
		return ;
	tmp = a;
	while (a != NULL)
	{
		a = a->next;
		free(tmp);
		tmp = a;
	}
}

void	free_errors(t_stack_node *a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	dupli_check_true(t_stack_node *a)
{
	t_stack_node	*orig;
	t_stack_node	*temp;

	orig = a;
	while (a != NULL)
	{
		temp = a->next;
		while (temp != NULL)
		{
			if (a->nbr == temp->nbr)
				free_errors(orig);
			temp = temp->next;
		}
		a = a->next;
	}
}
