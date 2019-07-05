/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clonger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:39 by clonger           #+#    #+#             */
/*   Updated: 2017/11/09 18:05:39 by clonger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(char *str, char c)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				len++;
		}
		i++;
	}
	len++;
	return (len);
}

static int		get_next_len(char *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			len++;
		else
			return (len);
		i++;
	}
	return (len);
}

static int		check_char(char *str, int i, char c)
{
	int space;

	space = 0;
	while (str[i])
	{
		if (str[i] == c)
			space++;
		else if (str[i] != c)
			return (space);
		i++;
	}
	return (space);
}

static char		**split(char **table, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		if (str[k] != c)
		{
			table[i][j] = str[k];
			j++;
			if (str[k + 1] == c || str[k + 1] == '\0')
			{
				table[i][j] = '\0';
				i++;
				j = 0;
			}
		}
		k++;
	}
	table[i] = 0;
	return (table);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i;
	int			start;
	int			len;
	int			len_2;
	char		**table;

	i = 0;
	start = 0;
	if (!s || !c)
		return (NULL);
	len = get_len((char *)s, c);
	table = (char **)malloc(sizeof(char *) * (len));
	if (!table)
		return (NULL);
	while (i < len - 1)
	{
		start = start + check_char((char *)s, start, c);
		len_2 = get_next_len((char *)s, start, c);
		start = (start + len_2);
		table[i] = (char *)malloc(sizeof(char) * (len_2 + 1));
		i++;
	}
	table = split(table, (char *)s, c);
	return (table);
}
