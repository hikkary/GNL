/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:28:05 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/23 22:04:24 by zkerkeb          ###   ########.fr       */
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

// fonction a modifier pour ecrire sur la ligne bn
char *ft_write(int fd, char *buf, char **line , int bn)
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

int len_line(int fd, char *buf, char **line , int bn)
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


// integrer bn pour permettre la recursivite
int get_next_line(int const fd, char **line)
{
	int i;
	int fd2;	
	char buf[BUFF_SIZE];
	static int bn;
	int len;

	fd2 = fd;
	i =  0;	
	fd2 = open(line[0], O_RDONLY);
	//printf("%d", fd2);
	//l = get_line(fd, buf, &argv[1]);
	
	len = len_line(fd2, buf, line, bn); 
	line[i] = (char *)malloc(sizeof(char) * len);
	line[i] = ft_write(fd2, buf, line, bn);
	//printf(" %d", len);
	return (0);
}

int main(int argc, char **argv)
{
	int fd;

		
	get_next_line(fd, &argv[1]);

	return (0);
}
