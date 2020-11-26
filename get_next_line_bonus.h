/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:11:20 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 19:13:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_BONUS_H
# define _GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef FD_MAX
# define FD_MAX 256
#endif

int	get_next_line(int fd, char **line);
char	*ft_strdup(char *src);
int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	ft_strdel(char *str);

#endif

