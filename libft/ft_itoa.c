/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:58:41 by jjamsa            #+#    #+#             */
/*   Updated: 2021/11/19 16:54:29 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_characters(int n);
static	char		*ft_create_string(char *str, int count, int i, int n);
static	char		*ft_handle_int_min(void);

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (n == -2147483648)
		return (ft_handle_int_min());
	if (n < 0)
		sign = -1;
	if (n < 0)
		n = n * -1;
	count = ft_count_characters(n);
	if (sign == -1)
		count++;
	str = (char *) malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	if (sign == -1)
		str[i] = '-';
	if (sign == -1)
		i++;
	str = ft_create_string(str, count, i, n);
	return (str);
}

static	int	ft_count_characters(int n)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	char	*ft_create_string(char *str, int count, int i, int n)
{
	int	temp_n;
	int	temp_count;

	temp_n = n;
	temp_count = count;
	while (temp_count > i)
	{
		temp_n = temp_n % 10;
		str[temp_count - 1] = temp_n + '0';
		n = n / 10;
		temp_n = n;
		temp_count--;
	}
	str[count] = '\0';
	return (str);
}

static	char	*ft_handle_int_min(void)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * 12);
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}
