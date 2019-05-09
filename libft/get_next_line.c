/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:58:50 by lpan              #+#    #+#             */
/*   Updated: 2018/11/23 13:20:36 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_new_line(char **str, char **line)
{
	int				i;
	char			*temp;

	i = 0;
	temp = *str;
	while (temp[i] != '\n')
	{
		if (temp[i] == '\0')
			return (0);
		i++;
	}
	if (!(*line = ft_strndup(*str, i)))
		return (-1);
	if (!(*str = ft_strdup(&temp[i + 1])))
		return (-1);
	ft_strdel(&temp);
	return (1);
}

static int		read_file(const int fd, char *buff, char **str, char **line)
{
	int				ret;
	char			*temp;

	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!*str)
		{
			if (!(*str = ft_strdup(buff)))
				return (-1);
		}
		else
		{
			temp = *str;
			if (!(*str = ft_strjoin(temp, buff)))
				return (-1);
			ft_strdel(&temp);
		}
		if (check_new_line(str, line))
			return (1);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[1024];
	char			buff[BUFF_SIZE + 1];
	int				ret;

	ret = 0;
	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (str[fd])
	{
		if (check_new_line(&str[fd], line))
			return (1);
	}
	ret = read_file(fd, buff, &str[fd], line);
	if (ret != 0 || !str[fd] || str[fd][0] == '\0')
		return (ret);
	if (ret == 0 && str[fd])
	{
		*line = str[fd];
		str[fd] = NULL;
	}
	return (1);
}
