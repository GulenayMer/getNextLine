/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:09:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/13 13:00:18 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_remain_str(char *str_saved)
{
	char	*new;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (str_saved[i] != '\n' && str_saved[i] != '\0')
		i++;
	if (!str_saved)
	{
		free(str_saved);
		return (0);
	}
	new = (char *)malloc(sizeof(char) * ((ft_str_length(str_saved) - i) + 1));
	if (!new)
		return (0);
	i++;
	while (str_saved[i] != '\0')
	{
		new[j] = str_saved[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(str_saved);
	return (new);
}

char	*ft_get_line(char *str_saved)
{
	int		i;
	char	*line;
	
	i = 0;
	if (!str_saved)
		return (0);
	while (str_saved[i]  && str_saved[i] != '\n')
		i++;
	while (str_saved[i])
	{
		/* if (str_saved[i] == '\n')
		{
			line = ft_substr(str_saved, 0, i);
		}
		i++; */
			line = ft_substr(str_saved, 0, i);
		i++;
	}
	line[i] = '\0';
	return (line);
}

/* char	*ft_get_line(char *str_saved)
{
	int		i;
	char	*line;

	i = 0;
	if (!str_saved)
		return (0);
	while (str_saved[i] && str_saved[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2)); 
	if (!line)
		return (NULL);
	i = 0;
	while (str_saved[i] && str_saved[i] != '\n')
	{
		line[i] = str_saved[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return (line);
} */

/* char ft_get_line(char *str_saved, char *line)
{
	char	*new;
	int		i;
	
	i = 0;
	while (str_saved[i] != '\n' && str_saved[i] != '\0')
		i++;
	if (str_saved[i] == '\n')
	{
		i++;
		line = ft_substr(str_saved, 0, i);
		new = ft_strdup(str_saved);
	}
	else
	{
		line = ft_strdup(str_saved);
	}
	free(str_saved);
	return (new);
} */

char	*ft_read_file(char *str_saved, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	bytes_read = 1;
	while(bytes_read != 0 && !ft_strchr(str_saved, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (0);
		}
		else if (!str_saved)
		str_saved = ft_strdup(buffer);
		else
		{
			buffer[bytes_read] = '\0';
			str_saved = ft_strjoin(str_saved, buffer);
		}
	}
	free(buffer);
	return (str_saved);
}


char	*get_next_line(int fd)
{
	static char *str_saved;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_saved = ft_read_file(str_saved, fd);
	line = ft_get_line(str_saved);
	str_saved = ft_new_remain_str(str_saved);
	return (line);
}
