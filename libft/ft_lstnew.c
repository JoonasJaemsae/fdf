/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:48:27 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/23 12:50:48 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = NULL;
	link = (t_list *) malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
		link->next = NULL;
		return (link);
	}
	link->content = malloc(sizeof(content) * content_size);
	if (link->content == NULL)
		return (NULL);
	ft_memmove(link->content, content, content_size);
	link->content_size = content_size;
	link->next = NULL;
	return (link);
}
