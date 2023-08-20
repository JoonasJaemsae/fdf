/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:59:55 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 17:22:32 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned long	i;
	size_t			length;
	char			*duplicate;

	i = 0;
	length = ft_strlen(src);
	duplicate = ((char *)malloc(sizeof(char) * (length + 1)));
	if (duplicate == NULL)
		return (NULL);
	while (i < length)
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
