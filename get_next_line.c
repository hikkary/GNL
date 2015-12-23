/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:28:05 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/23 21:11:46 by zkerkeb          ###   ########.fr       */
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

int len_line(int fd, char *buf, char **line)
{
	int i;
	int len;
	int ret;
	
	len = 0;
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && check_buff(buf) != 1))
	{
		len += ret;	
		ft_putstr(buf);
	}
	return(len);
}

char *get_line(int const fd, char *buf, char **line)
{
	int i;
	
	i = 0;
/*	while (line[1][i] != '\n')
	{
 		
	}*/
	return("ta race");
}

int get_next_line(int const fd, char **line)
{
	int i;
	int fd2;	
	char buf[BUFF_SIZE];
	char *l;
	int len;

	fd2 = fd;
	i =  0;	
	fd2 = open(line[0], O_RDONLY);
	//printf("%d", fd2);
	//l = get_line(fd, buf, &argv[1]);
	while (read(fd,buf, BUFF_SIZE))
	{
		len = len_line(fd2, buf, line); 
		line[i] = (char *)malloc(sizeof(char) * len);
	}
	//printf(" %d", len);	
	return (0);
}

int main(int argc, char **argv)
{
	int fd;

		
	get_next_line(fd, &argv[1]);

	return (0);
}
