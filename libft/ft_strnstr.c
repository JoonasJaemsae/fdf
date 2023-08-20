/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:50:48 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/24 19:03:22 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fuck_you_25_line_limit(int *i, int *j, unsigned long *m);
static void	ft_really_go_fuck_yourself_please(int *i, int *k, unsigned long *m);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				i;
	int				j;
	int				k;
	unsigned long	m;

	i = 0;
	j = 0;
	k = 0;
	m = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && m < len)
	{
		while (haystack[i] == needle[j] && m < len)
		{
			ft_fuck_you_25_line_limit(&i, &j, &m);
			if (needle[j] == '\0')
				return ((char *) &haystack[i - j]);
		}
		if (haystack[i] != needle[0])
			ft_really_go_fuck_yourself_please(&i, &k, &m);
		j = 0;
	}
	return (NULL);
}

static void	ft_fuck_you_25_line_limit(int *i, int *j, unsigned long *m)
{
	(*i)++;
	(*j)++;
	(*m)++;
}

static void	ft_really_go_fuck_yourself_please(int *i, int *k, unsigned long *m)
{
	(*k)++;
	*i = *k;
	*m = *k;
}
