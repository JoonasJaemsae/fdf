/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:19:50 by jjamsa            #+#    #+#             */
/*   Updated: 2022/02/11 14:21:42 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Counts the number of words in a string delimited by char c. */

#include "libft.h"

int	ft_word_count(const char *s, char c)
{
	int	i;
	int	count;
	int	in_word_check;

	i = 0;
	count = 0;
	in_word_check = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word_check = 0;
		else if (in_word_check == 0)
		{
			in_word_check = 1;
			count++;
		}
		i++;
	}
	return (count);
}
