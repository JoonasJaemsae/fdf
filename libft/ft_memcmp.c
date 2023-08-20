/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:48:01 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 16:55:54 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned long	i;

	i = 0;
	if (n == 0)
		return (0);
	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	while (ptr1[i] == ptr2[i] && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}
