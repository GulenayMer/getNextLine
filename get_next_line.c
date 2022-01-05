/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:09:05 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/05 17:44:10 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* */
char	ft_line_next(char *line, int fd)
{
	char	*buffer;
	int		nbytes;
	char 	*line_end;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));  /* allocate memory for the temporary storage */
	if (!buffer)
		return (0);
	line_end = ft_strchr(line, '\n'); /* how I know it is the next line: by checking the ft_strchr function */
	while(!line_end && nbytes != 0)
	{
		/* read (): reads in data in bytes, the number of which is specified by the caller, from the file; and stores in a buffer supplied 
		by the calling process  --- ssize_t read(int fd, void *buf, size_t count) */
		nbytes = read(fd, buffer, BUFFER_SIZE + 1);  /* nbytes: the number of bytes to be read from the file */
		buffer[nbytes] = '\0';  /* buffer stops at nbytes */
		line = ft_strjoin(buffer, line);  /* line is the result of concanating from src to dest--buffer */
	}
	free(buffer);
	return (line);
}	

/* return: the line that has just been read;
 		if there is nothing else to read/erorr occurs/integer is 
		 negative,
	return: NULL */
 /*static variable which does not need to 
	be initialized/ persists its value*/
char	*get_next_line(int fd)
{
	static char *str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);





	return (line);
	}