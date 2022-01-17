/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:10:22 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/17 10:15:44 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_update_static(char *chars_read)
{
	char	*new_static;
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_strlen(chars_read);
	while (chars_read[i] != '\n' && chars_read[i] != '\0')
		i++;
	if (!chars_read[i])
	{
		free(chars_read);
		return (0);
	}
	new_static = (char *)malloc(sizeof(char) * (size - i) + 1);
	if (!new_static)
		return (0);
	i++;
	j = 0;
	while (chars_read[i] != '\0')
		new_static[j++] = chars_read[i++];
	new_static[j] = '\0';
	free(chars_read);
	return (new_static);
}

char	*ft_extract_line(char *chars_read)
{
	int		i;
	char	*line;

	i = 0;
	if (!chars_read[i])
		return (0);
	while (chars_read[i] != '\n' && chars_read[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (chars_read[i] != '\n' && chars_read[i] != '\0')
	{
		line[i] = chars_read[i];
		i++;
	}
	if (chars_read[i] == '\n')
	{
		line[i] = chars_read[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_file(int fd, char *chars_read)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	bytes_read = 1;
	while (!ft_strchr(chars_read, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (0);
		}
		else
		{
			buffer[bytes_read] = '\0';
			chars_read = ft_strjoin(chars_read, buffer);
		}
	}
	free(buffer);
	return (chars_read);
}

char	*get_next_line(int fd)
{
	static char	*chars_read[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	chars_read[fd] = ft_read_file(fd, chars_read[fd]);
	if (!chars_read[fd])
		return (0);
	line = ft_extract_line(chars_read[fd]);
	chars_read[fd] = ft_update_static(chars_read[fd]);
	return (line);
}
