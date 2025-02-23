/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:57:55 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/23 19:42:03 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_init(t_stack_node *a, t_stack_node *b, t_stack_node *clone)
{
	if (!stack_sort_check(a))
	{
		sort_stack(clone);
		assign_index_stack(a, clone);
		sort(a, b);
	}
}

// void	print_stack(t_stack_node *a)
// {
// 	t_stack_node	*tmp;

// 	tmp = a;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->nbr);
// 		tmp = tmp->next;
// 	}
// }

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
	// print_stack(a); // This is a test function to print the stack
	dupli_check_true(a);
	create_stack(&clone, av);
	sort_init(a, b, clone);
	free_stack(clone);
	free_stack(a);
	free_stack(b);
	return (0);
}
