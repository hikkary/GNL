/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:15:07 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/01/13 23:21:38 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int bn(char *buf)
{
	int i;

	i = 0;

	while (buf[i])
	{
		if(buf[i] == '\n')
			return(i);
		i++;
	}
	return (0);
}

// faire fonction qui va gerer after \n
int get_next_line(int const fd, char **line)
{
	static t_g *s;
	int ret;

	if(!s)
		s = malloc(sizeof(t_g));
	line[0] = ft_strnew(BUFF_SIZE + 1);
	if(!s->an) 
	{
		s->an = ft_strnew(BUFF_SIZE + 1);
		s->an = NULL;
	}
	if ((ret = read(fd, s->buf,BUFF_SIZE)) && !s->an) // is si il y a quelque chose a lire
	{
		s->buf[ret] = '\0';
		line[0] = ft_strjoin(line[0], s->buf);
	}

	if ((s->an = ft_strchr(line[0],'\n'))) //stock le pointeur sur \n dans s->an
	{
		s->an++;
		line[0] = ft_strsub(line[0], 0, bn(line[0]));	
	}	
	
	if(line[0])	
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	char *line;
	int fd;

	fd = open(argv[1], O_RDONLY);
	
	while(get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
}
