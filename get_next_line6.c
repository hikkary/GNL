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
	if (!buf)
		return(1);
	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == '\0' || buf[i]  == EOF)
			return(i);
		i++;
	}
	return (0);
}


t_g *ft_stock(t_g *s, int fd)
{
	int ret;

	s->t = 0;
	s->total = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, s->buf, BUFF_SIZE)) )
	{
		s->buf[ret] = '\0';
		s->total = ft_strjoin(s->total, s->buf);
		if (fd == 0 && ret > 0)
			return (s);
	}
	if (ret == 0)
		s->t = 1;
	return (s);
}


char *ft_write(t_g *s,char **line)
{
	int i;
	
	i = 0;
	while (s->total[i] != '\n' && s->total[i] && s->total[i] != EOF)
	{
		line[0][i] = s->total[i];
		i++;
	}
	line[0][i] = '\0';
	return (line[0]);
}

int get_next_line(int const fd, char **line)
{
	static t_g *s;
	if (fd < 0)
		return (0);
	if (!s)
		s = malloc(sizeof(t_g));
	//ft_putnbr(s->t);
	if (s->t != 1)
		s = ft_stock(s,fd);
	//DEBUG
	line[0] = ft_strnew(len_buff(s->total) + 1);
	//DEBUG
	line[0] = ft_write(s, &line[0]);
	//DEBUG
	s->total = ft_strchr(s->total,'\n');
	//DEBUG
	s->total++;
	//ft_putstr(s->total);
	if((*s->total == '\0' || *s->total == EOF) && fd != 0)
		s->stop = 2;
	if(s->stop == 2)
		return(0);
	else
		return (1);
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	fd = open(argv[1], O_RDONLY);
	//fd = 0;
	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}
