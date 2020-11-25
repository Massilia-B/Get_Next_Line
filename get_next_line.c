/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:40:30 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 11:59:42 by user42           ###   ########.fr       */
/*   Updated: 2020/11/24 18:22:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (ret == 0 && !str)
	{
		*line = ft_strdup("");
	}	
	else if (ft_strchr(str, '\n'))
	{
	//	printf("5) str = [%s], line = [%s] \n", str, *line);
		*line = ft_getline(str);
		ft_strdel(str);
		if (str[0] == '\0')
			return (0);
		return (1);
	}
	else if (!ft_strchr(str, '\n') && ret == 0)
	{	
	//	printf("6) str = [%s], line = [%s] \n", str, *line);
		*line = ft_getline(str);
		ft_strdel(str);
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
		//	printf("2) str = [%s], line = [%s] \n", str, *line);
			temp = ft_strjoin(str,buff);
			free(str);
			str = temp;
		}
		//	printf("1) str = [%s], line = [%s] \n", str, *line);
		if (ft_strchr(str, '\n'))
		{
			*line = ft_getline(str);
		//	printf("3.1) str = [%s], line = [%s] \n", str, *line);
			ft_strdel(str);
		//	printf("3) str = [%s], line = [%s] \n", str, *line);
			if (ret == 0 && str[0] == '\0')
				break ;
			return(1);
		}
	}
	free(buff);
	buff = NULL;
	return (ft_is_line(ret, line, str));

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
		printf("\n----result = [%d]", result);
		printf("Final line ==> [%s]\n", line);
	}
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
