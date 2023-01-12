/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:39:37 by isaridas          #+#    #+#             */
/*   Updated: 2023/01/10 15:41:17 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_part(int fd, char *dynamic_buffer)
{
	char	*buffer;
	int		read_byte;
	int		control;

	control = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (control)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		if (ft_strchr(buffer, '\n') != 0 || read_byte == 0)
			control = 0;
		dynamic_buffer = ft_strjoin(dynamic_buffer, buffer);
	}
	free(buffer);
	return (dynamic_buffer);
}

char	*ft_get_line(char *dynamic_buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (dynamic_buffer[i] && dynamic_buffer[i] != '\n')
	{
		i++;
	}
	if (dynamic_buffer[i] == '\n')
		i++;
	line = ft_substr(dynamic_buffer, 0, i);
	return (line);
}

char	*ft_new_buffer(char *dynamic_buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	while (dynamic_buffer[i] && dynamic_buffer[i] != '\n')
	{
		i++;
	}
	if (!dynamic_buffer[i])
	{
		free(dynamic_buffer);
		return (NULL);
	}
	i++;
	line = ft_substr(dynamic_buffer, i, ft_strlen(dynamic_buffer) - i + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*dynamic_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dynamic_buffer = ft_read_part(fd, dynamic_buffer);
	if (dynamic_buffer == NULL)
		return (NULL);
	line = ft_get_line(dynamic_buffer);
	dynamic_buffer = ft_new_buffer(dynamic_buffer);
	return (line);
}
