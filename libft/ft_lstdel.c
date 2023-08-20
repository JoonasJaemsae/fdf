/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:21:33 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/23 16:55:30 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp_next;

	while (*alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		temp_next = (*alst)->next;
		free(*alst);
		*alst = temp_next;
	}
}
