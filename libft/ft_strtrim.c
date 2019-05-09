/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:11:33 by lpan              #+#    #+#             */
/*   Updated: 2018/11/15 19:11:35 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	result = NULL;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (ft_is_whitespace(s[i]))
		i++;
	while (ft_is_whitespace(s[len - 1]))
		len--;
	if (i > len)
		i = len;
	if (!(result = (char*)malloc(sizeof(char) * (len - i + 1))))
		return (NULL);
	while (i < len)
	{
		result[j++] = s[i++];
	}
	result[j] = '\0';
	return (result);
}
