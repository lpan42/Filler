/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:15:08 by lpan              #+#    #+#             */
/*   Updated: 2018/11/09 20:15:09 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int i;
	unsigned int n;

	i = 0;
	n = ft_strlen(src);
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > len)
		return (dest);
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
