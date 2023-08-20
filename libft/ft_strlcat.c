/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:00:57 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 17:26:21 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int				i;
	size_t			dst_length;
	size_t			src_length;

	i = 0;
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	if (dstsize < dst_length)
		return (src_length + dstsize);
	if (dstsize > dst_length + 1)
	{	
		while (src[i] != '\0')
		{
			dst[dst_length + i] = src[i];
			i++;
			if (dst_length + i >= dstsize - 1)
				break ;
		}
	}
	dst[dst_length + i] = '\0';
	return (dst_length + src_length);
}
