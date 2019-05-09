/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:25:57 by lpan              #+#    #+#             */
/*   Updated: 2018/11/19 12:25:58 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *temp;
	const char *result;

	result = NULL;
	temp = NULL;
	if ((char)c == '\0')
		return (ft_strchr(s, c));
	while ((temp = ft_strchr(s, c)))
	{
		result = temp;
		s = temp + 1;
	}
	return ((char*)result);
}
