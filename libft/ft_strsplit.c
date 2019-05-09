/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:05:08 by lpan              #+#    #+#             */
/*   Updated: 2018/11/16 11:05:09 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_delimiter(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

static int		ft_word_count(const char *s, char c)
{
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (ft_check_delimiter(s[i], c))
		i++;
	if (i == 0)
		wc++;
	while (s[i] != '\0')
	{
		if ((!(ft_check_delimiter(s[i], c))) &&
		(ft_check_delimiter(s[i - 1], c)))
			wc++;
		i++;
	}
	if (i == 0)
		return (0);
	return (wc);
}

static int		ft_word_len(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (ft_check_delimiter(s[i], c))
		i++;
	while (!(ft_check_delimiter(s[i], c)) && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static void		ft_create_array(char **array, char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < ft_word_count(s, c))
	{
		k = 0;
		array[i] = ft_strnew(ft_word_len(&s[j], c) + 1);
		if (array[i] == NULL)
			return ;
		while (ft_check_delimiter(s[j], c))
			j++;
		while (!(ft_check_delimiter(s[j], c)) && s[j])
		{
			array[i][k] = s[j];
			k++;
			j++;
		}
		array[i][k] = '\0';
		i++;
	}
	array[i] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (s == NULL)
		return (NULL);
	array = (char **)malloc(sizeof(*array) * (ft_word_count(s, c) + 1));
	if (array == NULL)
		return (NULL);
	ft_create_array(array, s, c);
	return (array);
}
