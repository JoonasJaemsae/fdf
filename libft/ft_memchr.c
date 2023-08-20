/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:21:32 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 16:55:31 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned long	i;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return (&(ptr[i]));
		i++;
	}
	return (NULL);
}
