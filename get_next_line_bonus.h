/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:31:53 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/17 10:13:38 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *chars_read);
char	*ft_extract_line(char *chars_read);
char	*ft_update_static(char *char_read);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memmove(void *dest, void *src, size_t len);
char	*ft_strjoin(char *chars_saved, char *temp);

#endif
