/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:05:58 by lpan              #+#    #+#             */
/*   Updated: 2018/11/20 11:05:59 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_cat_str(size_t size, char *d, const char *s)
{
	while (size > 0 && *d)
	{
		d++;
		size--;
	}
	while (*s)
	{
		if (size != 1)
		{
			*d = *s;
			d++;
			size--;
		}
		s++;
	}
	*d = '\0';
}

size_t			ft_strlcat(char *restrict dst, const char *restrict src,
	size_t size)
{
	char		*d;
	const char	*s;
	size_t		len_d;

	d = dst;
	s = src;
	len_d = ft_strlen(dst);
	if (len_d >= size)
		return (size + ft_strlen(src));
	else
		ft_cat_str(size, d, s);
	return (len_d + ft_strlen(src));
}
