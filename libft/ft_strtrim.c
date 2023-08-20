/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:55:09 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 18:24:08 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlen_indexed(const char *str, size_t i);

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		len = 0;
	else
		len = ft_strlen_indexed(s, i);
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (j < len)
	{
		new[j++] = s[i++];
	}
	new[j] = '\0';
	return (new);
}

static	size_t	ft_strlen_indexed(const char *str, size_t i)
{
	unsigned int	len;

	len = 0;
	while (str[i] != '\0')
	{
		i++;
		len++;
	}
	i--;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		i--;
		len--;
	}
	return (len);
}
