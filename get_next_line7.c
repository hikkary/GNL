/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:44:02 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/13 22:14:38 by zkerkeb          ###   ########.fr       */
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
		if (buf[i] == '\n' || buf[i]  == EOF)
			return(i);
		i++;
	}
	return (0);
}

t_g *ft_stock(t_g *s, int fd)
{
	int ret;

	s->total = malloc(sizeof(char) * BUFF_SIZE + 1);
	s->total[ft_strlen(s->total)] = '\0';
		DEBUG
		while((ret = read(fd, s->buf, BUFF_SIZE)) && len_buff(s->total) != 0)
		{
			s->buf[ret] = '\0';
			ft_strjoin(s->total, s->buf);
			printf("%s", s->total);
			if (len_buff(s->total))
				s->t = 1;
		}
	return (s);
}

char *ft_write(t_g *s,char **line)
{
	int i;

	i = 0;
	while ((s->total[i] != '\n' && s->total[i] != EOF) && s->total[i])
	{
		line[0][i] = s->total[i];
		i++;
		DEBUG
	}
	line[0][i] = '\0';
	return (line[0]);
}

// regler le pb de boucle infini]
int get_next_line(int const fd, char **line)
{
	static t_g *s;
	DEBUG
	if (fd < 0)
		return (0);
	if (!s)
		s = malloc(sizeof(t_g));
	DEBUG
	s = ft_stock(s, fd); 
	DEBUG
	line[0] = ft_strnew(100);
	line[0] = ft_write(s, &line[0]);
	DEBUG
	printf(" ace %s", s->total);
	s->total = ft_strchr(s->total,'\n');
	s->total++;
	
	return(0);
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
