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
	
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return(1);
		i++;
	}
	return (0);
}

int len_line(int fd, char *buf, int bn)
{
	int i;
	int len;
	int ret;
	
	len = 0;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && check_buff(buf) != 1))
	{
		len += ret;	
	//	printf("%s",buf);
	}
	return(len);
}

char *ft_write(int fd, char *buf, char **line, int bn, int i)
{
	int ret;
	int j;

	j = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && check_buff(buf) != 1))
	{
		line[0][i] = buf[j];
		ft_putstr(buf);
		i++;
		j++;
	}
	line[0][i] = '\0';;
	read = 0;
	return (line[0]);
}
// integrer bn pour permettre la recursivite
int get_next_line(int const fd, char **line)
{
	int i;
	int ret;	
	char buf[BUFF_SIZE + 1];
	static int bn;
	int len;
	
	i =  0;	
	bn = 0;
	
	len = len_line(fd, buf, bn); 
	
	line[0] = (char *)malloc(sizeof(char) * len);
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && check_buff(buf) != 1))
		line[0] = ft_write(fd, buf, line, bn, i);

	//ft_putstr(line[0]);
	return (0);
}

int main(int argc, char **argv)
{
	int fd;
 	char **line;

	
	line = (char **)malloc(sizeof(char *) * 10);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);

	return (0);
}
