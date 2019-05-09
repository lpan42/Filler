/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:29:54 by lpan              #+#    #+#             */
/*   Updated: 2018/11/17 13:29:55 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ptr_new;
	t_list	*begin_list;

	if (lst == NULL)
		return (0);
	ptr_new = NULL;
	begin_list = NULL;
	if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (0);
	begin_list = new;
	ptr_new = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst)->content, f(lst)->content_size)))
			return (0);
		ptr_new->next = new;
		ptr_new = new;
		lst = lst->next;
	}
	return (begin_list);
}
