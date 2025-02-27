/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:57:55 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/25 21:47:27 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*clone;

	a = NULL;
	b = NULL;
	clone = NULL;
	if (ac == 1)
		exit(0);
	if (!check_av(av))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	create_stack(&a, av);
	dupli_check_true(a);
	create_stack(&clone, av);
	sort_stack(clone);
	stack_sort_check(a, clone);
	assign_index_stack(a, clone);
	free_stack(clone);
	sort(a, b);
}
