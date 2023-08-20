/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:10:41 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/24 15:30:58 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL && s2 != NULL)
		return (0);
	else if (s1 != NULL && s2 == NULL)
		return (0);
	else if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
