/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:10:16 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/13 13:00:35 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_file(char *str_read, int fd);
char	*ft_get_line(char *str_saved);
char	*ft_new_remain_str(char *str_saved);

char	*ft_strdup(const char *s);
char	*ft_strjoin(char *str_saved, char *temp);
char	*ft_strchr(const char *s, int c);
size_t 	ft_str_length(const char *str);
char	*ft_substr(char *str_saved, unsigned int start, size_t len);


#endif