/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:06:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 18:36:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_strdel(char *str)
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

static char	*ft_getline(char *str)
{
	int i;
	char *dest;
	int	l;

	l = ft_strlen(str);
	if (!(dest = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_is_line(int ret, char **line, char **str, int fd)
{
	if ((ret == 0 && !*str) || !ft_strchr(str[fd], '\n'))
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_strchr(str[fd], '\n'))
	{
		*line = ft_getline(str[fd]);
		ft_strdel(str[fd]);
		if (str[fd][0] == '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	get_next_line_bonus(int fd, char **line)
{
	char *buff;
	static char *str[FD_MAX];
	int ret;
	char *temp;

	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE <= 0 || (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd],buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
		{
			*line = ft_getline(str[fd]);
			ft_strdel(str[fd]);
			if (ret == 0 && str[fd][0] == '\0')
				return (0);
			return(1);
		}
	}
	free(buff);
	buff = NULL;
	return (ft_is_line(ret, line, &str[fd], fd));

}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	int l;

	if (!str)
		return ;
	l = ft_strlen(str);
	write(1, str, l);
}

int main(int argc, char **argv)
{
	int fd;
	int result = 1;
	char *line;

	line = NULL;
	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY); 
	while(result)
	{
		result = get_next_line_bonus(fd, &line);
		printf("\n----result = [%d]\n", result);
		ft_putstr(line);
	}
	if (close(fd) == -1)
		return (-1);
	free(line);
	return (0);
}
