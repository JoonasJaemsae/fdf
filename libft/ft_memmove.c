/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:37:00 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/24 17:12:31 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;

	i = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			((unsigned char *) dst)[len - 1] = ((unsigned char *) src)[len - 1];
			len--;
		}
	}
	else if (dst <= src)
	{
		while (i < len)
		{
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
			i++;
		}
	}
	return (dst);
}
