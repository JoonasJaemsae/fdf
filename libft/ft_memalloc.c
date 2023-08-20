/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:58:14 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 16:55:05 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*area;
	unsigned long	i;

	i = 0;
	area = (unsigned char *) malloc(sizeof(unsigned char) * size);
	if (area == NULL)
		return (NULL);
	while (i < size)
	{
		area[i] = '\0';
		i++;
	}
	return (area);
}
