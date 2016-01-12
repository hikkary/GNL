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

int len_buff(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == '\0' || buf[i]  == EOF)
			return(i);
		i++;
	}
	return (0);
}


t_g *stock(t_g *s, int fd)
{
	int ret;

	s->total = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, s->buf, BUFF_SIZE)))
	{
		s->buf[ret] = '\0';
		s->total = ft_strjoin(s->total, s->buf);
		if (fd == 0 && ret > 0)
			return (s);
	}
	return (s);
}


t_g *ft_write(t_g s,char **line)
{
	int i;
	
	i = 0;
	while (s->total[i] != '\n' && s->total[i] && s->total[i] != EOF)
	{
		line[0][i] = s->total[0][i];
		i++;
	}
	line[0][i] = '\0';
	return (line);
}

// Le stdin semble fonctionner, faire en sorte que la sortie standard sois stocker dans lime[0]
int get_next_line(int const fd, char **line)
{
	static t_g *s;

	if (!s)
		s = malloc(sizeof(t_g));
	s = stock(s,fd);
	line[0] = ft_strnew(len_buff(s->total));
	s = ft_write(s, line[0]);
//	ft_putstr(s->total);
	

	return (0);
}
 
int main(int argc, char **argv)
{
	char *line;
	int fd;
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
	{
		//ft_putendl(line);
		//free(line);
	}
	return (0);
}
