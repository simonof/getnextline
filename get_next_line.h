/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoushi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:11:23 by ogoushi           #+#    #+#             */
/*   Updated: 2021/04/29 18:13:43 by ogoushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include	<unistd.h>
# include	<stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_return(int read_return_value, char *static_memory, char *buf);
char	*ft_line_remainder(char *static_memory, char *ptr);
char	*ft_line(char *static_memory);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
#endif
