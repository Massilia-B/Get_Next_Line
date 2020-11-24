/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:54:36 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 15:28:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int	l;

	l = ft_strlen(src);	
	if (!(dest = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(const char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = 0;
	return (dest);
}
char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (c && *s == c)
			return ((char *)(s));
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}
