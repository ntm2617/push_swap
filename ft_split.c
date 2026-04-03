/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:49:19 by ming              #+#    #+#             */
/*   Updated: 2026/04/02 21:50:50 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

int	group(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

void	reserve_mem(int size_f, char const *s, char c, char **arr)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < size_f)
	{
		s = s + n;
		if (size(s, c) == 0)
		{
			s++;
			n = 0;
			continue ;
		}
		arr[i] = malloc(sizeof(char) * (size(s, c) + 1));
		if (arr[i] == NULL)
		{
			while (--i >= 0)
				free(arr[i]);
			free(arr);
			return ;
		}
		arr[i++][size(s, c)] = '\0';
		n = size(s, c);
	}
}

void	fill(int size_f, char const *a, char c, char **arr)
{
	int	i;
	int	n;

	i = 0;
	while (i < size_f)
	{
		n = 0;
		if (size(a, c) == 0)
		{
			a++;
			continue ;
		}
		while (n <= size(a, c))
		{
			if (a[n] != c)
				arr[i][n] = a[n];
			else if (a[n] == c)
				arr[i][n] = '\0';
			n++;
		}
		a = a + n;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	char const	*a;
	int			size_f;

	if (s == NULL)
		return (NULL);
	a = s;
	size_f = group(s, c);
	arr = malloc(sizeof(char *) * (size_f + 1));
	if (arr == NULL)
		return (NULL);
	reserve_mem(size_f, s, c, arr);
	fill(size_f, a, c, arr);
	arr[size_f] = NULL;
	return (arr);
}
