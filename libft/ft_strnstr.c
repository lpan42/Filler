/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:59:47 by lpan              #+#    #+#             */
/*   Updated: 2018/11/12 14:59:48 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;
	size_t a;

	i = 0;
	if (!(*to_find))
		return ((char *)str);
	while ((str[i] != '\0') && (i < len))
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			a = i;
			while ((str[i] == to_find[j]) && (i < len))
			{
				if (to_find[j + 1] == '\0')
					return ((char *)(str + a));
				j++;
				i++;
			}
			i = a;
		}
		i++;
	}
	return (NULL);
}
