/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:56:00 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/25 21:31:23 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

//functions
void			free_stack(t_stack_node *a);
void			free_errors(t_stack_node *a);
void			dupli_check_true(t_stack_node *a);
int				ft_isdigit(int i);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
void			push(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			ra(t_stack_node **a);
void			rra(t_stack_node **a);
void			three_sort(t_stack_node **a);
void			four_sort(t_stack_node **a, t_stack_node **b);
void			five_sort(t_stack_node **a, t_stack_node **b);
void			sort(t_stack_node *a, t_stack_node *b);
long long		ft_atol(char *str);
int				check_av(char **av);
int				stack_init(t_stack_node **a, char *av);
void			create_stack(t_stack_node **a, char **av);
void			append_node(t_stack_node **a, t_stack_node *new);
t_stack_node	*last_node(t_stack_node *a);
void			swap(t_stack_node *a, t_stack_node *b);
void			stack_sort_check(t_stack_node *a, t_stack_node *clone);
void			sort_stack(t_stack_node *clone);
void			assign_index_stack(t_stack_node *a, t_stack_node *c);
t_stack_node	*new_node(int nbr, int index);
int				ft_stacksize(t_stack_node *lst);
void			free_split(char **str_arr);
int				find_max_node(t_stack_node *a);
int				find_min_node(t_stack_node *a);

#endif