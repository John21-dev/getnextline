/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:17:02 by jmacera-          #+#    #+#             */
/*   Updated: 2024/01/29 15:30:25 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	start_buffer(int fd, char **buff)
{
	int	bytes_read;

	*buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buff)
		return (-1);
	bytes_read = read(fd, *buff, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(*buff);
		*buff = NULL;
		return (-1);
	}
	(*buff)[bytes_read] = '\0';
	return (0);
}

int	ft_has_newline(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		m;
	int		n;

	m = 0;
	n = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new_str)
		return (NULL);
	if (str1)
	{
		while (str1[m])
			new_str[n++] = str1[m++];
	}
	m = 0;
	while (str2[m])
		new_str[n++] = str2[m++];
	new_str[n] = '\0';
	free(str1);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*new_line;
	char		*temp;
	int			bytes_read;

	new_line = NULL;
	if (buff == NULL && start_buffer(fd, &buff) == -1)
		return (NULL);
	if (!ft_has_newline(buff))
	{
		while (!ft_has_newline(buff))
		{
			new_line = ft_strjoin(new_line, buff);
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read <= 0 && new_line[0] == '\0')
				return (free(buff), free(new_line), buff = NULL);
			if (bytes_read <= 0)
				return (free(buff), buff = NULL, new_line);
			buff[bytes_read] = '\0';
		}
		temp = ft_ext_line_mbytes(buff);
		return (new_line = ft_strjoin(new_line, temp), free(temp), new_line);
	}
	return (new_line = ft_ext_line_mbytes(buff));
}
