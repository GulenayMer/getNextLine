/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:14:17 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/17 10:14:21 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}

void	*ft_memmove(void *dest, void *src, size_t len)
{
	unsigned char		*p_dst;
	unsigned char		*p_src;
	size_t				i;

	p_dst = dest;
	p_src = src;
	i = 0;
	if (!dest && !src)
		return (0);
	if (p_dst > p_src)
		while (len-- > 0)
			p_dst[len] = p_src[len];
	else
	{
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char *chars_saved, char *temp)
{
	size_t	len;
	char	*new;

	if (!chars_saved && !temp)
		return (0);
	len = ft_strlen((char *)chars_saved) + ft_strlen((char *)temp);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	ft_memmove(new, chars_saved, ft_strlen(chars_saved));
	ft_memmove(new + ft_strlen(chars_saved), temp, ft_strlen(temp));
	new[len] = '\0';
	free(chars_saved);
	return (new);
}
