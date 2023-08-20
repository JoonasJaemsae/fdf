/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:14:16 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 17:39:32 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	i = ft_strlen(s);
	if (c == '\0')
	{
		str = (char *) &(s[i]);
		return (str);
	}
	while (i >= 0)
	{
		if (s[i] == c)
		{
			str = (char *) &(s[i]);
			break ;
		}
		i--;
	}
	return (str);
}
