/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:29:53 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 14:22:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 255
#endif

int	get_next_line(int fd, char **line);
char	*ft_strdup(char *src);
int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

#endif
