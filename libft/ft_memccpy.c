/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:57:56 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/24 16:46:47 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned long	i;

	ptr1 = dst;
	ptr2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*ptr1 = ptr2[i];
		if (ptr2[i] == (unsigned char) c)
			return (ptr1 + 1);
		ptr1++;
		i++;
	}
	return (NULL);
}
