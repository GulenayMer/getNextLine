/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:13:36 by mgulenay          #+#    #+#             */
/*   Updated: 2022/01/05 19:18:28 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* size_t ft_str_length(const char *str) will be used to find the string lenght */
/* size_t ft_str_length(const char *str)
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
} */

/* char	*ft_strchr(const char *s, int c) will be used to check the charachter new line ('/n') */
/* char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (c == '\0')
	{
		return ((char *)(s + i));
	}
	return (0);
} */

/* char	*ft_strjoin(char *left_str, char *buff) will be used to join the the line stored in the buffer and the string left (it will used
every time to join the new buffer and the string left until the file ends) */
/* char	*ft_strjoin(char *str_left, char *temp)
{
	size_t	i;
	size_t	j;
	char	*merged_str;

// if there is no string left:
	if (!str_left)
	{
		str_left = malloc(sizeof(char));
		str_left[0] = '\0';
	}
	if (!str_left || !temp)
		return (0);
	merged_str = (char *)malloc(sizeof(char) * ((ft_str_length(str_left) + ft_str_length(temp)) + 1)); /* string in the buffer(which is already read) plus the left(the next) string */
/* 	if (!merged_str)
		return (0);
	i = 0;
	j = 0;
	// if there is still string in the file:
	if (str_left)
		while (str_left[i] != '\0')
		{
			merged_str[i] = str_left[i];
			i++;
		}
	while (temp[j] != '\0')
		merged_str[i++] = temp[j++];
	merged_str[ft_str_length(str_left) + ft_str_length(temp)] = '\0';
	//free(merged_str);
	return (merged_str);
} */

/* char	*ft_get_line(char *str) is used to read a line into str/temp
get_line will read a single line from stdin; lines are delimited by newline ('/n') chars, get_line will read up to
and including the newline.  */
 char	*ft_get_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
 	if (!str[i])
		return (0); 
	while (str[i] && str[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2)); /* i + 2 -- for newline character and null terminator*/
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')  /* if newline is encountered, it will add the newline to the end of the current string before 
								adding the null terminator. */
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int main(void)
{
	//char s1[20] = "Look Here!";
	 char s1[20] = "lorem ipsum\n";

	// char s1[20] = "";
	// char s2[20] = " Unimaginable";
	//char s1[20] = "";
	
	char *result = ft_get_line(s1);
	printf("%s\n", result);

	return (0);
}