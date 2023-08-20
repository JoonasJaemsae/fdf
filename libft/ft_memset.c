/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:02:43 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 16:56:49 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	*ptr;

	i = 0;
	ptr = b;
	while (i < len)
	{
		*ptr = (unsigned char) c;
		ptr++;
		i++;
	}
	return (b);
}
