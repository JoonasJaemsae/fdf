/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_2d_char_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:13:58 by jjamsa            #+#    #+#             */
/*   Updated: 2022/03/22 17:26:26 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**rev_2d_char_array(char **array)
{
	char	**rev;
	int		nbr;
	int		i;

	nbr = 0;
	while (array[nbr] != 0)
		nbr++;
	rev = (char **) malloc(sizeof(char *) * (nbr + 1));
	if (rev == NULL)
		return (NULL);
	rev[nbr] = 0;
	nbr--;
	i = 0;
	while (nbr >= 0)
	{
		rev[i] = (char *) malloc(sizeof(char) * (ft_strlen(array[nbr]) + 1));
		if (rev[i] == NULL)
			return (NULL);
		rev[i] = ft_strcpy(rev[i], (const char *) array[nbr]);
		i++;
		nbr--;
	}
	rev[i] = 0;
	return (rev);
}
