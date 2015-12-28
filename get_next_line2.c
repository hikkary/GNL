/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:28:05 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/27 19:58:53 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

int check_buff(char *buf)
{
	int i;
	static char *rest;


	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}

char *len_line(int fd, char *buf, int bn, char **line)
{
	int i;
	int len;
	int ret;
	char *ace;
	
	line[1] = ft_strnew(BUFF_SIZE + 1);
	len = 0;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && check_buff(buf) != 1))
	{
	//	len += ret;
	//	ft_putchar('a');
		printf("%d", ret);
		line[1] = ft_strjoin(line[1], buf);	
	}
		//ft_putstr(line[1]);
	return(line[1]);
}


// integrer bn pour permettre la recursivite
int get_next_line(int const fd, char **line)
{
	int i;
	int ret;	
	char buf[BUFF_SIZE + 1];
	static int bn;
	char *len;
	
	i =  0;	
	bn = 0;
	
	line[0] = len_line(fd, buf, bn, line); 	
	
	ft_putstr(line[0]);
	ft_putchar('\n');
	return (0);
}

int main(int argc, char **argv)
{
	int fd;
 	char **line;
	int fd2;

	line = (char **)malloc(sizeof(char *) * 10);
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	get_next_line(fd, line);
	get_next_line(fd2, line);
	get_next_line(fd, line);
	get_next_line(fd2, line);

	return (0);
}
