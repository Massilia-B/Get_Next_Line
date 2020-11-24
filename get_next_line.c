/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:40:30 by user42            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/11/24 18:29:32 by user42           ###   ########.fr       */
=======
/*   Updated: 2020/11/24 18:22:37 by user42           ###   ########.fr       */
>>>>>>> c2de3b3df4b90dde57eaf5cb54117dc1061dd353
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static int	ft_is_line(int ret, char **line, char *str)
{
	if (ret < 0)
		return (-1);
	if ((ret == 0 && !str) || !ft_strchr(str, '\n'))
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_strchr(str, '\n'))
	{
		*line = ft_getline(str);
		ft_strdel(str);
		if (str[0] == '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char *buff;
	static char *str;
	int ret;
	char *temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str,buff);
			free(str);
			str = temp;
		}
		if (ft_strchr(str, '\n'))
		{
			*line = ft_getline(str);
			ft_strdel(str);
			if (ret == 0 && str[0] == '\0')
				break ;
			return(1);
		}
	}
	free(buff);
	buff = NULL;
	return (ft_is_line(ret, line, str));

}
<<<<<<< HEAD
=======

>>>>>>> c2de3b3df4b90dde57eaf5cb54117dc1061dd353
void	ft_putstr(char *str)
{
	int l;

	if (!str)
		return ;
	l = ft_strlen(str);
	write(1, str, l);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int fd;
	int result = 1;
	char *line;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	line = NULL;	
	while(result)
	{
		result = get_next_line(fd, &line);
		printf("\n----result = [%d]\n", result);
		ft_putstr(line);
	}
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
