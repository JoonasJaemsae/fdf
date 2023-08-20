/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:05:49 by jjamsa            #+#    #+#             */
/*   Updated: 2022/02/11 13:02:15 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of chars in a word in a string starting from index i
 * and delimited by char c.
 */

static	size_t	ft_word_length(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static	char	**filler(char const *s, char c, char **arr, int word_count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < word_count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		arr[j] = (char *) malloc(sizeof(char) * (ft_word_length(s, c, i) + 1));
		if (arr[j] == NULL)
		{
			ft_free_2d_char_array(arr, j);
			return (NULL);
		}
		while (s[i] != '\0' && s[i] != c)
			arr[j][k++] = s[i++];
		arr[j][k] = '\0';
		j++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_strsplit(char const *s, char c)
{
	int		word_count;
	char	**arr;

	word_count = ft_word_count(s, c);
	if (s == NULL)
		return (NULL);
	arr = (char **) malloc(sizeof(char *) * (word_count + 1));
	if (arr == NULL)
		return (NULL);
	arr = filler(s, c, arr, word_count);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
