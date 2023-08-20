/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:21:56 by jjamsa            #+#    #+#             */
/*   Updated: 2022/02/10 17:32:07 by jjamsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	create_line(char **saved, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	temp = NULL;
	while ((*saved)[len] != '\n' && (*saved)[len] != '\0')
		len++;
	*line = ft_strsub(*saved, 0, len);
	if (*line == NULL)
		return (-1);
	if ((*saved)[len] == '\0')
	{
		ft_strdel(saved);
		return (1);
	}
	temp = ft_strdup(&((*saved)[len + 1]));
	if (temp == NULL)
		return (-1);
	free(*saved);
	*saved = temp;
	if ((*saved)[0] == '\0')
		ft_strdel(saved);
	return (1);
}

static	int	output(char **saved, char **line, int ret, const int fd)
{
	if (*line != NULL)
		ft_strdel(line);
	if (ret < 0)
	{
		return (-1);
	}
	else if (ret == 0 && saved[fd] == NULL)
	{
		return (0);
	}
	else
	{
		return (create_line(&(saved[fd]), line));
	}
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		*temp;
	char		buff[BUFF_SIZE + 1];
	static char	*saved[FD_MAX];

	if (fd < 0 || fd >= FD_MAX || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	while (1)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret > 0)
		{
			buff[ret] = '\0';
			temp = ft_strjoin((const char *) saved[fd], (const char *) buff);
			if (temp == NULL)
				return (-1);
			free(saved[fd]);
			saved[fd] = temp;
			if ((ft_strchr((const char *) saved[fd], '\n')) != NULL)
				break ;
		}
		else
			break ;
	}
	return (output(saved, line, ret, fd));
}
