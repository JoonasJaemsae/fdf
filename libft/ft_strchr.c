/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:30:00 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/25 13:10:00 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned long	i;

	i = 0;
	str = NULL;
	if (c == '\0')
	{
		i = ft_strlen(s);
		str = (char *) &(s[i]);
		return (str);
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			str = (char *) &(s[i]);
			break ;
		}
		i++;
	}
	return (str);
}
