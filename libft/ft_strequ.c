/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:06:01 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/24 15:26:14 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL && s2 != NULL)
		return (0);
	else if (s1 != NULL && s2 == NULL)
		return (0);
	else if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
