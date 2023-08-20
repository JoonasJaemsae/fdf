/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:29:13 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/24 18:21:30 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i] == needle[j])
		{
			j++;
			i++;
			if (needle[j] == '\0')
				return ((char *) &haystack[i - j]);
		}
		if (haystack[i] != needle[0])
			k++;
		if (haystack[i] != needle[0])
			i = k;
		j = 0;
	}
	return (NULL);
}
