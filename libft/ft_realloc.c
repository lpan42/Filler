/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:04:39 by lpan              #+#    #+#             */
/*   Updated: 2018/11/21 12:04:41 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (!ptr)
	{
		new_ptr = malloc(size);
		if (new_ptr == 0)
			return (0);
	}
	else
	{
		new_ptr = ft_memalloc(size);
		if (new_ptr == 0)
			return (0);
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}

/*
**#include <stdio.h>
**#include <string.h>
**#include <stdlib.h>
**int main ()
**{
**   char *str;
**
**   str = malloc(5);
**   ft_strcpy(str, "abcdefg");
**   printf("String = %s\n", str);
**   str = realloc(str, 0);
**   printf("String = %s\n", str);
**
**   free(str);
**
**   return(0);
**}
*/
