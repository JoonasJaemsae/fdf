/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:24:00 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 16:53:07 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{	
	unsigned char	*ptr;
	unsigned long	i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		*ptr = (unsigned char) '\0';
		ptr++;
		i++;
	}
	return ;
}
