/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:26:00 by jjamsa            #+#    #+#             */
/*   Updated: 2022/02/11 16:54:17 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* We'll put new to the beginning by making it next to the
 * to the current head, which is the first node in alst i.e. *alst.
 * Finally, we'll make "new" the new head by copying its value to
 * *alst, which points to the first node in the list.
 * */

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
