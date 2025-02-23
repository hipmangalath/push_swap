/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:55:32 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/22 21:50:27 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **a, t_stack_node *new)
{
	if (!new)
		return ;
	if (!*a)
		*a = new;
	else
		last_node(*a)->next = new;
}
