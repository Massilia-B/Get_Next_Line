/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:06:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 12:48:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (ret < 0)
		return (-1);
	if (ret == 0 && !str[fd])
	{
		*line = ft_strdup("");
		free(str[fd]);
	}
	else if (ft_strchr(str[fd], '\n'))
	{
		*line = ft_getline(str[fd]);
		ft_strdel(str[fd]);
		if (str[fd][0] == '\0')
		{
			free(str[fd]);
			return (0);
		}
		return (1);
	}
	else if (!ft_strchr(str[fd], '\n') && ret == 0)
	{	
		*line = ft_getline(str[fd]);
		ft_strdel(str[fd]);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
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
				break ;
			return(1);
		}
	}
	free(buff);
	buff = NULL;
	return (ft_is_line(ret, line, str, fd));

}
/*int main(int ac, char **av)
{ 
	int fd1; 
	int fd2;
	int fd3; 
	char *line; 
	char *file1; 
	char *file2; 
	char *file3;
	int result = 1;
	
		
	file1 = av[1]; 
	file2 = av[2]; 
	file3 = av[3]; 
	
	if (ac == 1)
	{
		fd1 = 0;
		fd2 = 0;
		fd3 = 0;
	}
	else
	{
		fd1 = open(file1, O_RDONLY); 
		fd2 = open(file2, O_RDONLY); 
		fd3 = open(file3, O_RDONLY); 
	}
	while (result)
	{	
		result = get_next_line(fd1, &line); 
		printf("1) ---- lign [%s] \t et result = [%d]\n", line, result); 
	}
	free(line);
	result = 1;
	while (result)
	{
		result = get_next_line(fd2, &line); 
		printf("2) ---- lign [%s] \t et result = [%d]\n", line, result); 
	}
	free(line);
result = 1;
	while (result)
	{
		result = get_next_line(fd3, &line); 
		printf("3) ---- lign [%s] \t et result = [%d]\n", line, result); 
	}
	free(line);
	close(fd1); 
	close(fd2); 
	close(fd3); 
		printf("3) str = [%s], line = [%s] \n", str[fd], *line);
		printf("2) str = [%s], line = [%s] \n", str[fd], *line);
		printf("1) str = [%s], line = [%s] \n", str[fd], *line);
		printf("6) str = [%s], line = [%s] \n", str[fd], *line);
		printf("5) str = [%s], line = [%s] \n", str[fd], *line);
		printf("4) str = [%s], line = [%s] \n", str[fd], *line);
	printf("4.000) str = [%s], line = [%s] \n", str[fd], *line);
	return 0;
}*/
