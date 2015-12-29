/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:28:05 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/29 22:08:58 by zkerkeb          ###   ########.fr       */
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

char *len_line(int fd, char *buf, char *r, char **line)
{
	int i;
	int ret;
	int j;

	j = 0;

//	line[0] = ft_strnew(BUFF_SIZE + 100);
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE) != 0 && check_buff(line[0]) != 1))
	{
		line[0] = ft_strjoin(line[0], buf);
	}
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	while (line[0][i] != '\0')
	{
		i++;
		r[j] = line[0][i];
		j++;
	}
	line[0] = ft_strsub(line[0], 0, (i - j));
	return(line[0]);
}


int get_next_line(int const fd, char **line)
{
	int i;
	int ret;	
	char buf[BUFF_SIZE + 1];
	static char *r;	
	i =  0;	
	
	if (r)
	line[0] = ft_strnew(BUFF_SIZE + 1);
	r = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	line[0] = len_line(fd, buf, r, line); 	
	//if (line = 
	ft_putstr(line[0]);
	ft_putchar('\n');
//	ft_putstr(r);
	return (0);
}
//A FAIRE creer la fonction qui colle la static r a line , et qui si ya pas de buffer la renvoi a lautre fonction pour continuer a lire, Vive la republique, vive la France

int main(int argc, char **argv)
{
	int fd;
 	char *line;
	int fd2;

//	line = (char **)malloc(sizeof(char *) * 10);
	fd = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);
	//while(argv[1])
	
	get_next_line(fd, &line);
	free(line);
/*	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
*/	
	return (0);
}
