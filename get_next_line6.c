/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:44:02 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/11 20:37:54 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*
int check_buff(char *buf, int cara)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == cara)
			return(1);
		i++;
	}
	return (0);
}
*/

t_g stock(t_g s, int fd)
{
	int ret;

	s.total = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, s.buf, BUFF_SIZE)))
	{
		s.buf[ret] = '\0';
		s.total = ft_strjoin(s.total, s.buf);
		printf("ace\n");
	}
	return (s);
}

/*
char **ft_write(char **line, char **b)
{
	int i;
	
	i = 0;
	while (b[0][i] != '\n' && b[0][i] && b[0][i] != EOF)
	{
		line[0][i] = b[0][i];
		i++;
	}
	line[0][i] = '\0';
	return (line);
}
*/
int get_next_line(int const fd, char **line)
{
	static t_g s;
	
	s = stock(s,fd);
	ft_putstr(s.total);
	return (0);
}
// mettre le fd 
int main(int argc, char **argv)
{
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(0, &line);
	return (0);
}
