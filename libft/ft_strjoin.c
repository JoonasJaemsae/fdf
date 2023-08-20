/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:53:43 by jjamsa            #+#    #+#             */
/*   Updated: 2021/12/02 12:38:14 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_handle_one_null(const char *s1, const char *s2)
{
	char	*new;

	if (s1 == NULL)
	{
		new = ft_strdup(s2);
		if (new == NULL)
			return (NULL);
	}
	else
	{
		new = ft_strdup(s1);
		if (new == NULL)
			return (NULL);
	}
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL || s2 == NULL)
	{
		new = ft_handle_one_null(s1, s2);
		if (new == NULL)
			return (NULL);
	}
	else
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char *) malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		ft_strcpy(new, s1);
		ft_strcat(new, s2);
	}
	return (new);
}
