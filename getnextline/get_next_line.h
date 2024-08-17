/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmacera- <jmacera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:43:45 by jmacera-          #+#    #+#             */
/*   Updated: 2024/01/26 12:12:27 by jmacera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strlen(char *str);
int		ft_has_newline(char *str);
int		start_buffer(int fd, char **buff);

char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, int n);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_ext_line_mbytes(char *buff);
#endif
