/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:53:19 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/23 19:42:25 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atol(char *str)
{
	int					s;
	unsigned long long	n;
	int					i;

	s = 1;
	n = 0;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 10)
		return (2147483649);
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
	}
	return (s * n);
}

int	check_av(char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) || (av[i][j] == '-' && (av[i][j - 1] == ' '
						|| j == 0)) || (av[i][j] == '+' && (av[i][j - 1] == ' '
						|| j == 0)) || av[i][j] == ' ')
				flag = 1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (flag);
}

int	stack_init(t_stack_node **a, char *av)
{
	long			n;
	int				j;
	char			**temp;

	j = 0;
	temp = ft_split(av, ' ');
	if (!temp || !(temp[0]))
		return (free_split(temp), 0);
	while (temp[j])
	{
		if ((temp[j][0] == '-' || temp[j][0] == '+') && temp[j][1] == '\0')
			return (free_split(temp), 0);
		n = ft_atol(temp[j]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_split(temp), 0);
		append_node(a, new_node(n, 0));
		j++;
	}
	free_split(temp);
	return (1);
}

void	create_stack(t_stack_node **a, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!stack_init(a, av[i]))
			free_errors(*a);
		i++;
	}
}
