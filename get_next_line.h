/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:10:16 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/04 18:28:17 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	ft_read_line(char *line, int fd);
char	*ft_get_line(char *left_str);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *s);


#endif