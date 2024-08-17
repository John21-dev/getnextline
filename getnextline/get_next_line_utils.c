/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:49:55 by jmacera-          #+#    #+#             */
/*   Updated: 2024/01/26 12:08:53 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str++)
		i++;
	return (i);
}

int	ft_find_nline_location(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '\n')
			return (i);
		i++;
		str++;
	}
	return (-1);
}

void	*ft_movemem(void *to, const void *from, size_t size)
{
	unsigned char		*des;
	const unsigned char	*src;

	des = to;
	src = from;
	if (des < src)
	{
		while (size--)
			*(des++) = *(src++);
	}
	else if (des > src)
	{
		des += size;
		src += size;
		while (size--)
			*--des = *--src;
	}
	return (to);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_ext_line_mbytes(char *buff)
{
	char	*newline;
	int		nl_loc;

	nl_loc = ft_find_nline_location(buff);
	if (nl_loc >= 0)
	{
		newline = malloc(sizeof(char) * (nl_loc + 2));
		newline = ft_strncpy(newline, buff, nl_loc +1);
		newline[nl_loc + 1] = '\0';
		buff = ft_movemem(buff, buff + nl_loc + 1, ft_strlen(buff) - nl_loc);
		return (newline);
	}
	return (NULL);
}
