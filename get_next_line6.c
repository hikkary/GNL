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
			return(i);
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
		if (fd == 0 && ret > 0)
			return (s);
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
	ft_putstr("1");
	s = stock(s,fd);
	ft_putstr("2");
	ft_putstr(s.total);
	return (1);
}
 
int main(int argc, char **argv)
{
	char *line;
	int fd;
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(0, &line))
	{
		ft_putendl(line);
		//free(line);
	}
	return (0);
}
