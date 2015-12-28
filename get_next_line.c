/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:28:05 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/27 17:36:28 by zkerkeb          ###   ########.fr       */
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
	int j;
	int ret;

	j = 0;
	i = 0;
//	printf("%s", buf);
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && check_buff(buf) != 1))
	{
		while(buf[j])
		{
			line[0][i] = buf[j];
			j++;
			i++;
			ft_putchar(line[0][i]); 
		}
	}
	return(line[0]);
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
//		printf("%s", buf);
	}
	ret++;
	return(len);
}

// integrer bn pour permettre la recursivite
int get_next_line(int const fd, char **line)
{
	int i;
	int ret;	
	char buf[BUFF_SIZE];
	static int bn;
	int len;

//	fd2 = fd;
	i =  0;	
	bn = 0;
	//fd2 = open(line[0], O_RDONLY);
	//printf("%d", fd2);
	//l = get_line(fd, buf, &argv[1]);
	
	len = len_line(fd, buf, line, bn); 
//	printf("%d\n", len);
	line[0] = (char *)malloc(sizeof(char) * len);
//	close(fd2);
//	fd2 = open(line[0], O_RDONLY);
	while (check_buff(buf) != 1)
		line[0] = ft_write(fd, buf, line, bn);

	ft_putstr(line[0]);
	//printf(" %d", len);
	return (0);
}
//	fd2 = open(line[0], O_RDONLY);

int main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &argv[1]);

	return (0);
}