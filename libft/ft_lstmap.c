/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:13:38 by jjamsa            #+#    #+#             */
/*   Updated: 2022/02/16 15:08:45 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* If malloccing in ft_lstnew fails and returns NULL, we should exit in the
 * main. It is difficult to completely free the already mallocced parts in this
 * function, as we don't know what type of content goes into the t_list
 * variable (if the content is, for example 2D or 3D char arrays or something
 * else entirely, or if there's multiple different types of content like both
 * 2D and 3D arrays) and thus cannot thoroughly free it without extensive
 * checks. The possibilities are endless.
 * On the other hand, if return to main, we have lost the newly created list
 * and cannot access it anymore. Thus we must exit to free the memory.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = f(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (new == NULL)
		return (NULL);
	head = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (new->next == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
