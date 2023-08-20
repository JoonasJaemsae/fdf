/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:18:10 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 17:30:28 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	size_t			length;
	unsigned long	i;
	char			*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	new = (char *) malloc(sizeof(char) * (length + 1));
	if (new == NULL)
		return (NULL);
	while (i < length)
	{
		new[i] = f((char) s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
