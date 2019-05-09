/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:08:20 by lpan              #+#    #+#             */
/*   Updated: 2018/11/12 21:08:21 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char*)s;
	while (i < n)
	{
		if (*(temp + i) == (char)c)
			return (temp + i);
		i++;
	}
	return (0);
}
/*
** if ((char)c == '\0')
** return ((char*)s);
*/
