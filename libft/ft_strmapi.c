/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:13:00 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 17:30:55 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			length;
	unsigned int	i;
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
		new[i] = f(i, (char) s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
