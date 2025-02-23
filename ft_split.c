/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haiqbal <haiqbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 05:38:30 by haiqbal           #+#    #+#             */
/*   Updated: 2025/02/22 16:33:21 by haiqbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_memdlt(char *s, int i)
{
	while (i >= 0)
	{
		free(&s[i]);
		i--;
	}
	free (s);
}

static char	*ft_strcpy(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s, i);
	return (str);
}

static int	ft_count(char const	*s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**str;

	i = 0;
	count = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		str[i] = ft_strcpy(s, c);
		if (!str)
			ft_memdlt(*str, i);
		s += ft_strlen(str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

// char    **ft_split(char const *s, char c);

// int main(void)
// {
//     char **result;
//     int i;
//     char *str = "1";
//     char delimiter = ' ';
//     result = ft_split(str, delimiter);
//     if (!result)
//     {
//         printf("Memory allocation failed\n");
//         return (1);
//     }
//     i = 0;
//     while (result[i])
//     {
//         printf("Segment %d: %s\n", i, result[i]);
//         free(result[i]);
//         i++;
//     }
//     free(result);
//     return (0);
// }
