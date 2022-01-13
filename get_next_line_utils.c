/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:13:36 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/13 12:59:15 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_str_length(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return(0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(*s) * (ft_str_length(s) + 1));
	if (p == 0)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *str_saved, char *temp)
{
	size_t	i;
	size_t	j;
	char	*merged_str;

	if (!str_saved || !temp)
		return (0);
	merged_str = malloc(sizeof(char) * ((ft_str_length(str_saved) + ft_str_length(temp)) + 1));
	if (!merged_str)
		return (0);
	i = 0;
	while (str_saved[i] != '\0')
	{	merged_str[i] = str_saved[i];
		i++;
	}
	j = 0;
	while (temp[j] != '\0')
	{	merged_str[i] = temp[j];
		i++;
		j++;
	}
	merged_str[i] = '\0';
	free(str_saved);
	return (merged_str);
}

char	*ft_substr(char *str_saved, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!str_saved)
		return (0);
	subs = (char *)malloc(len + 2);
	if (!subs)
		return (0);
	i = 0;
	while (start < ft_str_length(str_saved) && i < len)
	{
		subs[i] = str_saved[start];
		start++;
		i++;
	}
	subs[i++] = '\n';
 	if (str_saved[i] == '\n')
	{
		subs[i] = str_saved[i];
		i++;
	} 
	subs[i] = '\0';
	return (subs);
}

