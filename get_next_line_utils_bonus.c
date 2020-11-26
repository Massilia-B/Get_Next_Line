/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:54:36 by user42            #+#    #+#             */
/*   Updated: 2020/11/26 14:12:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	i;
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

void	ft_strdel(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	j = 0;
	i++;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
}
